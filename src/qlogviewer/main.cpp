#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator *translator = new QTranslator(&a);
    if (translator->load(QLatin1String(":/res/qlogviewer_zh.qm"))) {
        a.installTranslator(translator);
    }

    MainWindow w;
    w.show();
    if (argc == 2) {
        w.loadFile(a.arguments()[1]);
    }
    return a.exec();
}
