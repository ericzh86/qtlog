#ifndef QCONSOLEAPPENDER_H
#define QCONSOLEAPPENDER_H

#include "qtlogglobal.h"
#include "qabstractappender.h"

#include <QObject>
class QConsoleAppenderPrivate;
class QTLOGSHARED_EXPORT QConsoleAppender : public QObject, public QAbstractAppender
{
	Q_OBJECT
	Q_INTERFACES(QAbstractAppender)

public:
	QConsoleAppender(QObject *parent = 0);

private:
    void _write(QLogger *logger, QLogger::Level level, const QString &text);

private:
	Q_DISABLE_COPY(QConsoleAppender)
	Q_DECLARE_PRIVATE(QConsoleAppender)
};

#endif//QCONSOLEAPPENDER_H
