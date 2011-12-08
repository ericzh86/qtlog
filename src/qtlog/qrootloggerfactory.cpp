#include "qrootloggerfactory.h"

#include "qrootlogger.h"
#include <QCoreApplication>

QRootLoggerFactory::QRootLoggerFactory(QObject *parent)
    : QObject(parent)
    , m_logger(0)
{
}

QRootLoggerFactory *QRootLoggerFactory::instance()
{
    static QMutex s_instanceLock;
    static QRootLoggerFactory *s_instance = 0;

    if (s_instance == 0) {
        QMutexLocker locker(&s_instanceLock);

        if (s_instance == 0) {
            if (qApp == 0)
                qFatal("QRootLoggerFactory::instance: Please instantiate the QApplication object first.");
            s_instance = new QRootLoggerFactory(qApp);
        }

        Q_UNUSED(locker);
    }
    return s_instance;
}

QRootLogger *QRootLoggerFactory::logger()
{
    if (m_logger == 0) {
        QMutexLocker locker(&m_loggerLock);

        if (m_logger == 0)
            m_logger = new QRootLogger(qApp, this);

        Q_UNUSED(locker);
    }
    return m_logger;
}
