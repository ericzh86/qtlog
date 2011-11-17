#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QtLog/QtLog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // RootLogger的级别设置成为Fatal和Debug.
    QtLog::rootLogger()->setLevels(QLogLevels() | QtLog::Fatal | QtLog::Debug);

    // 定义一个控制台输出Appender.
    QConsoleAppender consoleAppender;

    // 如果每个Appender不指定记录的级别, 默认使用RootLogger的级别.
    // consoleAppender.setLevels(QLogger::All);

    // 将ConsoleAppender添加到记录队列中.
    QtLog::rootLogger()->addAppender(&consoleAppender);

    // 这条消息将被忽略, 因为RootLogger现在只记录Fatal和Debug的.
    QtLog::rootLogger()->debug("This message will be ignored.");
    // 这条日记将被输出到控制台.
    QtLog::rootLogger()->fatal("This message will be recorded.");

    // 将记录级别修改为全部记录.
    QtLog::rootLogger()->setLevels(QtLog::All);
    // SQLITE数据库文件.
    QSQLiteAppender dbfileAppender(QString("test.any"));
    // 添加进去.
    QtLog::rootLogger()->addAppender(&dbfileAppender);

    // 如果编译时候定义了QTLOG_LOCALE_SUPPORT, 写入中文也是可以的.
    QtLog::rootLogger()->error("这个消息是中文的, 不会被忽略.");


    MainWindow w;
    w.show();

    return a.exec();
}
