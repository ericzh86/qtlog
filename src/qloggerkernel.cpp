#include "qloggerkernel.h"

#include <QtCore/QCoreApplication>
#include "qabstractappender.h"

//////////////////////////////////////////////////////////////////////////
// QLoggerKernelPrivate
//

#include "private/qobject_p.h"
class QLoggerKernelPrivate : public QObjectPrivate
{
	Q_DECLARE_PUBLIC(QLoggerKernel)
public:
	QLoggerKernelPrivate();
	~QLoggerKernelPrivate();

public:
	QLogger *m_rootLogger;
};

QLoggerKernelPrivate::QLoggerKernelPrivate()
	: QObjectPrivate()
	, m_rootLogger(0)
{
}

QLoggerKernelPrivate::~QLoggerKernelPrivate()
{
}

//////////////////////////////////////////////////////////////////////////
// QLoggerKernel
// 

Q_DECLARE_METATYPE(QLogger *)

QLoggerKernel::QLoggerKernel(QObject *parent)
	: QObject(*new QLoggerKernelPrivate(), parent)
{
    Q_D(QLoggerKernel);

    d->m_rootLogger = new QLogger(qApp, true);
}

QLogger *QLoggerKernel::rootLogger()
{
	Q_D(QLoggerKernel);

	return d->m_rootLogger;
}

QLogger *QLoggerKernel::logger(QObject *target)
{
	QVariant theLogger = target->property("_q_logger");
    // If the target's logger is valid, return it.
	if (theLogger.isValid())
		return theLogger.value<QLogger *>();
    // Else create a new logger for the target.
	QLogger *newLogger = new QLogger(target, false);
	target->setProperty("_q_logger", QVariant::fromValue(newLogger));
	return newLogger;
}

void QLoggerKernel::log(QLogger *logger, QLogger::Level level, const QString &text)
{
	Q_D(QLoggerKernel);

    if (d->m_rootLogger != 0) {
        QList<QAbstractAppender *> rootAppenders = d->m_rootLogger->_appenders();
		if (!rootAppenders.isEmpty()) {
			foreach (QAbstractAppender *appender, rootAppenders) {
				if (appender->isOpen()) {
                    appender->_write(logger, level, text);
				}
			}
		}
	}

    // If the logger is not root logger.
	if (logger->loggerId() != 0) {
        QList<QAbstractAppender *> targetAppenders = logger->_appenders();
        if (!targetAppenders.isEmpty()) {
            foreach (QAbstractAppender *appender, targetAppenders) {
				if (appender->isOpen()) {
                    appender->_write(logger, level, text);
				}
			}
		}
	}
}

QLoggerKernel *QLoggerKernel::instance()
{
    static QLoggerKernel *s_instance = 0;
    if (s_instance == 0)
        s_instance = new QLoggerKernel(qApp);
    return s_instance;
}
