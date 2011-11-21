#include "qdbfileconvertor.h"

#include <QFile>
#include <QDataStream>
#include <QSqlError>
#include <QSqlQuery>
#include <QTime>

bool QDBFileConvertor::convert(QSqlDatabase &sqlite, QDataStream &reader)
{
    char fileFlag[16] = {0};
    reader.readRawData(fileFlag, 16);

    // File flag check.
    if (qstrcmp(fileFlag, "QtLog format v1") != 0) {
        qDebug("DBFileAppender::convert: The source file has a bad format.");
        return false;
    }

    sqlite.exec("DROP TABLE IF EXISTS [contexts];");
    // Create table 'contexts'.
    QString sqlContexts = "CREATE TABLE IF NOT EXISTS [contexts] ("
        "[index] INTEGER NOT NULL,"
        "[class_name] VARCHAR(255) NOT NULL,"
        "[object_name] VARCHAR(255));";
    QSqlQuery createContexts(sqlite);
    if (!createContexts.exec(sqlContexts)) {
        qDebug("DBFileAppender::convert: Create table 'contexts' failed(%s).", qPrintable(createContexts.lastError().text()));
    }

    sqlite.exec("DROP TABLE IF EXISTS [texts];");
    // Create table 'texts'.
    QString sqlTexts = "CREATE TABLE IF NOT EXISTS [texts] ("
        "[time] DATETIME NOT NULL,"
        "[index] INTEGER NOT NULL,"
        "[level] INTEGER NOT NULL,"
        "[text] TEXT NOT NULL);";
    QSqlQuery createTexts(sqlite);
    if (!createTexts.exec(sqlTexts)) {
        qDebug("DBFileAppender::convert: Create table 'texts' failed(%s).", qPrintable(createTexts.lastError().text()));
    }

    if (!sqlite.transaction()) {
        qDebug("DBFileAppender::convert: transaction failed(%s).", qPrintable(createTexts.lastError().text()));
    }

    quint8 type;
    while (!reader.atEnd()) {
        reader >> type;
        if (type == 1) {
            // Context.
            quint8     level;
            QDateTime  logTime;
            quint32    loggerId;
            QByteArray logText;
            // Read datas.
            reader >> level >> logTime >> loggerId >> logText;
            //
            QString sqlCommand("INSERT INTO [texts] VALUES('%1','%2','%3','%4');");
            QString sql = sqlCommand.arg(logTime.toString("yyyy-MM-dd hh:mm:ss.zzz")).arg(loggerId).arg(level).arg(QString::fromUtf8(logText));
            // Insert datas.
            QSqlQuery query(sqlite);
            if (!query.exec(sql)) {
                qDebug("DBFileAppender::convert: Insert datas to 'texts' failed(%s).", qPrintable(query.lastError().text()));

                if (!sqlite.rollback()) {
                    qDebug("DBFileAppender::convert: rollback failed(%s).", qPrintable(createTexts.lastError().text()));
                }

                return false;
            }
        } else if (type == 0) {
            // Context.
            quint32 loggerId;
            QString className;
            QString objectName;
            // Read datas.
            reader >> loggerId >> className >> objectName;
            //
            QString sqlCommand("INSERT INTO [contexts] VALUES('%1','%2','%3');");
            QString sql = sqlCommand.arg(loggerId).arg(className).arg(objectName);
            // Insert datas.
            QSqlQuery query(sqlite);
            if (!query.exec(sql)) {
                qDebug("DBFileAppender::convert: Insert datas to 'contexts' failed(%s).", qPrintable(query.lastError().text()));

                if (!sqlite.rollback()) {
                    qDebug("DBFileAppender::convert: rollback failed(%s).", qPrintable(createTexts.lastError().text()));
                }

                return false;
            }
        }
    }

    if (!sqlite.commit()) {
        qDebug("DBFileAppender::convert: commit failed(%s).", qPrintable(createTexts.lastError().text()));
    }

    return true;
}
