#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QSqlDatabase>

class QComboBox;
class QTableView;
class QSqlQueryModel;

#include "./../QtLog/qlogger.h"

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    QSqlDatabase m_sqlite;

private:
    QComboBox *m_classNames;
    QComboBox *m_objectNames;
private:
    QTableView *m_logTableView;
private:
    QSqlQueryModel *m_queryModel;

private:
    void createMenus();

private slots:
    void openFile();
private slots:
    void associateFile();

public:
    void loadFile(const QString &fileName);

private slots:
    void setClassName(const QString &name);
    void setObjectName(const QString &name);
private:
    QString m_className;
    QString m_objectName;
private:
    void queryClassNames();
    void queryObjectNames();

private slots:
    void queryLogs(QLogger::Levels levels);
};

#endif//MAINWINDOW_H
