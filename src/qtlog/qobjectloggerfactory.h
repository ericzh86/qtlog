#ifndef QOBJECTLOGGERFACTORY_H
#define QOBJECTLOGGERFACTORY_H

#include "qtlogglobal.h"

#include <QHash>
#include <QMutex>

#include <QObject>

class QObjectLoggerFactory : public QObject
{
    Q_OBJECT

private:
    QObjectLoggerFactory(QObject *parent);
public:
    static QObjectLoggerFactory *instance();

public:
    QObjectLogger *logger(QObject *target);
private slots:
    void _q_removeLogger(QObject *target);

private:
    QHash<QObject *, QObjectLogger *> m_loggers;
private:
    QMutex                            m_loggersLock;
};

#endif//QOBJECTLOGGERFACTORY_H
