#include "qobjectloggerfactory.h"

#include "qobjectlogger.h"
#include <QCoreApplication>

QObjectLoggerFactory::QObjectLoggerFactory(QObject *parent)
    : QObject(parent)
{
}

QObjectLoggerFactory *QObjectLoggerFactory::instance()
{
    static QMutex s_instanceLock;
    static QObjectLoggerFactory *s_instance = 0;

    if (s_instance == 0) {
        QMutexLocker locker(&s_instanceLock);

        if (s_instance == 0) {
            if (qApp == 0)
                qFatal("QObjectLoggerFactory::instance: Please instantiate the QApplication object first.");
            s_instance = new QObjectLoggerFactory(qApp);
        }

        Q_UNUSED(locker);
    }
    return s_instance;
}

QObjectLogger *QObjectLoggerFactory::logger(QObject *target)
{
    QObjectLogger *theLogger = m_loggers.value(target);
    if (theLogger == 0) {

        QMutexLocker locker(&m_loggersLock);
        theLogger = m_loggers.value(target);
        if (theLogger == 0) {
            theLogger = new QObjectLogger(target, this);
            connect(target, SIGNAL(destroyed(QObject*)), this, SLOT(_q_removeLogger(QObject*)));
            m_loggers.insert(target, theLogger);
        }

        Q_UNUSED(locker);
    }
    return theLogger;
}

void QObjectLoggerFactory::_q_removeLogger(QObject *target)
{
    QMutexLocker locker(&m_loggersLock);

    QObjectLogger *theLogger = m_loggers.value(target);
    m_loggers.remove(target);
    delete theLogger;

    Q_UNUSED(locker);
}
