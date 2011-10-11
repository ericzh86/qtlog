#ifndef QLOGGERKERNEL_H
#define QLOGGERKERNEL_H

#include "qlogger.h"

#include <QObject>
class QLoggerKernelPrivate;
class QLoggerKernel : public QObject
{
	Q_OBJECT

public:
	QLogger *rootLogger();
public:
	QLogger *logger(QObject *target);
public:
	void log(QLogger *logger, QLogger::Level level, const QString &text);

public:
	QLoggerKernel(QObject *parent = 0);

public:
    static QLoggerKernel *instance();

private:
	Q_DISABLE_COPY(QLoggerKernel)
	Q_DECLARE_PRIVATE(QLoggerKernel)
};

#endif//QLOGGERKERNEL_H
