#ifndef QABSTRACTLOGGER_P_H
#define QABSTRACTLOGGER_P_H

#include "qobject_p.h"
#include "../qabstractlogger.h"
class QAbstractLoggerPrivate : public QObjectPrivate
{
    Q_DECLARE_PUBLIC(QAbstractLogger)

public:
    QAbstractLoggerPrivate();
    ~QAbstractLoggerPrivate();

public:
    QObject *m_target;
public:
    quint32 m_loggerId;
public:
    QLogLevels m_levels;

    // Appenders
public:
    QList<QAbstractAppender *> m_appenders;
};

#endif//QABSTRACTLOGGER_P_H
