#ifndef QSQLITEAPPENDER_H
#define QSQLITEAPPENDER_H

#include "qtlogglobal.h"

#include "qabstractappender.h"

class QSQLiteAppenderPrivate;
class QTLOGSHARED_EXPORT QSQLiteAppender : public QAbstractAppender
{
	Q_OBJECT

public:
    QSQLiteAppender(const QString &fileName, QObject *parent = 0);

private:
    void write(QAbstractLogger *logger, QLogLevel level, const QString &text);

private:
    Q_DISABLE_COPY(QSQLiteAppender)
    Q_DECLARE_PRIVATE(QSQLiteAppender)
};

#endif//QSQLITEAPPENDER_H
