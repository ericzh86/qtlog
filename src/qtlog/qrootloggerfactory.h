#ifndef QROOTLOGGERFACTORY_H
#define QROOTLOGGERFACTORY_H

#include "qtlogglobal.h"

#include <QMutex>

#include <QObject>

class QRootLoggerFactory : public QObject
{
    Q_OBJECT

private:
    QRootLoggerFactory(QObject *parent);
public:
    static QRootLoggerFactory *instance();

public:
    QRootLogger *logger();

private:
    QRootLogger *m_logger;
private:
    QMutex       m_loggerLock;
};

#endif//QROOTLOGGERFACTORY_H
