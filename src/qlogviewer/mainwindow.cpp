#include "mainwindow.h"

#include "querytoolbar.h"
#include "logitemdelegate.h"

#include <QGridLayout>
#include <QComboBox>
#include <QTableView>
#include <QSqlTableModel>
#include <QHeaderView>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QApplication>
#include <QSettings>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QTextStream>
#include <QtDebug>

#include "qdbfileconvertor.h"

#define Unspecified QObject::tr("Unspecified")

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createMenus();

    m_sqlite = QSqlDatabase::addDatabase("QSQLITE");

    QWidget *centralWindow = new QWidget(this);
    this->setCentralWidget(centralWindow);

    QGridLayout *mainLayout = new QGridLayout(centralWindow);
    mainLayout->setSpacing(2);
    mainLayout->setMargin(2);

    m_classNames = new QComboBox(this);
    mainLayout->addWidget(m_classNames, 0, 0);
    connect(m_classNames, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(setClassName(const QString &)));

    m_objectNames = new QComboBox(this);
    mainLayout->addWidget(m_objectNames, 0, 1);
    connect(m_objectNames, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(setObjectName(const QString &)));

    m_logTableView = new QTableView(this);
    mainLayout->addWidget(m_logTableView, 1, 0, 1, 2);
    m_logTableView->setItemDelegate(new LogItemDelegate(m_logTableView));
    m_logTableView->horizontalHeader()->setStretchLastSection(true);
    m_logTableView->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    m_logTableView->setSelectionMode(QTableView::SingleSelection);
    m_logTableView->setSelectionBehavior(QTableView::SelectRows);

    m_queryModel = new QSqlQueryModel(this);
    m_logTableView->setModel(m_queryModel);

    QueryToolBar *queryToolBar = new QueryToolBar(this);
    this->addToolBar(Qt::LeftToolBarArea, queryToolBar);
    queryToolBar->setFloatable(false);
    queryToolBar->setMovable(false);
    connect(queryToolBar, SIGNAL(requestChanged(QLogLevels)), this, SLOT(queryLogs(QLogLevels)));
}

MainWindow::~MainWindow()
{
}

void MainWindow::createMenus()
{
    QMenuBar *menuBar = this->menuBar();

    ///
    QMenu *fileMenu = menuBar->addMenu(QObject::tr("&File"));

    QAction *openFileAction = fileMenu->addAction(QObject::tr("&Open"), this, SLOT(openFile()));
    openFileAction->setShortcuts(QKeySequence::Open);

    fileMenu->addSeparator();

    fileMenu->addAction(QObject::tr("E&xit"), qApp, SLOT(quit()));

    ///
    QMenu *helpMenu = menuBar->addMenu(QObject::tr("&Help"));

//    helpMenu->addAction(QObject::tr("File &association"), this, SLOT(associateFile()));

//    helpMenu->addSeparator();

    helpMenu->addAction(QObject::tr("About..."));
}

void MainWindow::openFile()
{
    QSettings settings("qlogviewer.ini", QSettings::IniFormat);
    QString filePath = settings.value("Config/FilePath").toString();
    if (filePath.isEmpty())
        filePath = QCoreApplication::applicationDirPath();
    QString fileName = QFileDialog::getOpenFileName(this, QObject::tr("Open file"), filePath);
    if (!fileName.isEmpty()) {
        loadFile(fileName);
        settings.setValue("Config/FilePath", QFileInfo(fileName).absolutePath());
    }
}

void MainWindow::associateFile()
{
    QMessageBox::StandardButton button = QMessageBox::information(this, QObject::tr("File association"), QObject::tr("Would you like to associate the qvl file with this application?"), QMessageBox::Yes | QMessageBox::No);
    if (button == QMessageBox::Yes) {
        QString appFileName = QDir::toNativeSeparators(QApplication::applicationFilePath());

#if defined(Q_OS_WIN)
        QSettings regedit("HKEY_CLASSES_ROOT", QSettings::NativeFormat);
        //
        regedit.beginGroup("Qt3rd.qvlfile");
            regedit.beginGroup("DefaultIcon");
                regedit.setValue(".", QString("\"%1\",-102").arg(appFileName));
            regedit.endGroup();
            regedit.beginGroup("shell");
                regedit.beginGroup("open");
                    regedit.beginGroup("command");
                        regedit.setValue(".", QString("\"%1\" \"%2\"").arg(appFileName).arg("%1"));
                    regedit.endGroup();
                regedit.endGroup();
            regedit.endGroup();
        regedit.endGroup();
        //
        regedit.beginGroup(".qvl");
        regedit.setValue(".", "Qt3rd.qvlfile");
        regedit.endGroup();
#endif
    }
}

void MainWindow::loadFile(const QString &fileName)
{
    if (m_sqlite.isOpen())
        m_sqlite.close();

    m_className = Unspecified;
    m_objectName = Unspecified;

    QByteArray fileFlag;

    QFile file(fileName);
    if (file.open(QFile::ReadOnly)) {
        fileFlag = file.read(15);
        file.close();
    }

    if (fileFlag == "SQLite format 3") {
        m_sqlite.setDatabaseName(fileName);
        if (m_sqlite.open()) {
            queryClassNames();
            queryObjectNames();
            queryLogs(QtLog::All);
        }
    } else if (fileFlag == "QtLog format v1") {
        QString tmpFileName = fileName + ".tmp";
        if (!QFile::rename(fileName, tmpFileName)) {
            return;
        }
        QFile sourceFile(tmpFileName);
        if (!sourceFile.open(QFile::ReadOnly)) {
            return;
        }
        m_sqlite.setDatabaseName(fileName);
        if (!m_sqlite.open()) {
            return;
        }

        QDataStream reader(&sourceFile);
        if (!QDBFileConvertor::convert(m_sqlite, reader)) {
            return;
        }
        //
        sourceFile.close();
        //
        QFile::remove(tmpFileName);
        //
        queryClassNames();
        queryObjectNames();
        queryLogs(QtLog::All);

        // it doesn't work.
        // setWindowTitle(QString("qlogviewer - %1").arg(fileName));
    }
}

void MainWindow::queryClassNames()
{
    m_classNames->clear();
    m_classNames->addItem(Unspecified);

    QString sql = QString("SELECT [class_name] FROM [contexts];");

    QStringList items;
    QSqlQuery query(sql, m_sqlite);
    while (query.next())
        items << query.value(0).toString();
    items.sort();
    m_classNames->addItems(items);
}

void MainWindow::queryObjectNames()
{
    m_objectNames->clear();
    m_objectNames->addItem(Unspecified);

    QString sql = QString("SELECT [object_name] FROM [contexts];");
    if (m_className != Unspecified)
        sql = QString("SELECT [object_name] FROM [contexts] WHERE [contexts].[class_name] = '%1';").arg(m_className);

    QStringList items;
    QSqlQuery query(sql, m_sqlite);
    while (query.next())
        items << query.value(0).toString();
    items.removeDuplicates();
    items.sort();
    m_objectNames->addItems(items);
}

void MainWindow::setClassName(const QString &name)
{
    if (m_className != name) {
        m_className = name;
        //
        queryObjectNames();
    }
}

void MainWindow::setObjectName(const QString &name)
{
    if (m_objectName != name) {
        m_objectName = name;
    }
}

void MainWindow::queryLogs(QLogLevels levels)
{
    if (!m_sqlite.isOpen())
        return;

    QStringList items;
    items << QString("[texts].[level] AS '%1'").arg(QObject::tr("Level"));
    items << QString("[texts].[time] AS '%1'").arg(QObject::tr("Time"));
    items << QString("[contexts].[class_name] AS '%1'").arg(QObject::tr("ClassName"));
    items << QString("[contexts].[object_name] AS '%1'").arg(QObject::tr("ObjectName"));
    items << QString("[texts].[text] AS '%1'").arg(QObject::tr("Content"));

    QStringList arguments;
    arguments << QString("[texts].[level] & %1").arg(levels);
    if (m_className != Unspecified)
        arguments << QString("[contexts].[class_name] = '%1'").arg(m_className);
    if (m_objectName != Unspecified)
        arguments << QString("[contexts].[object_name] = '%1'").arg(m_objectName);

    QString sql;
    QTextStream s(&sql);

    s << "SELECT ";

    bool itemEntered = false;
    foreach (const QString &item, items) {
        if (itemEntered) {
            s << ", ";
        } else {
            itemEntered = true;
        }
        s << item;
    }
    s << " FROM [texts] LEFT JOIN [contexts] ON [texts].[index] = [contexts].[index]";

    if (!arguments.isEmpty())
        s << " WHERE ";

    bool argumentEntered = false;
    foreach (const QString &argument, arguments) {
        if (argumentEntered) {
            s << " AND ";
        } else {
            argumentEntered = true;
        }
        s << argument;
    }

    s << ";";

    s.flush();

    m_queryModel->setQuery(sql, m_sqlite);
}
