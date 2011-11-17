#ifndef QCONSOLEAPPENDER_H
#define QCONSOLEAPPENDER_H

#include "qtlogglobal.h"

#include "qabstractappender.h"

class QConsoleAppenderPrivate;
class QTLOGSHARED_EXPORT QConsoleAppender : public QAbstractAppender
{
    Q_OBJECT

public:
    QConsoleAppender(QObject *parent = 0);

private:
    void write(QAbstractLogger *logger, QLogLevel level, const QString &text);

private:
    Q_DISABLE_COPY(QConsoleAppender)
    Q_DECLARE_PRIVATE(QConsoleAppender)
};

#endif//QCONSOLEAPPENDER_H
