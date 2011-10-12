#ifndef QLOGGER_P_H
#define QLOGGER_P_H

#include "qlogger.h"

//////////////////////////////////////////////////////////////////////////
// QLoggerPrivate
//////////////////////////////////////////////////////////////////////////

#include "private/qobject_p.h"
class QLoggerPrivate : public QObjectPrivate
{
    Q_DECLARE_PUBLIC(QLogger)

public:
    QLoggerPrivate(bool isRoot);
    ~QLoggerPrivate();

public:
    quint32 loggerId() const { return _m_loggerId; }
private:
    static quint32 _s_loggerIdCounter;
private:
    quint32 _m_loggerId;

public:
    static QLogger *logger(QObject *target);
public:
    static QHash<QObject *, QLogger *> s_loggers;

public:
    static QLogger::Levels s_rootLoggerLevels;
public:
    static QHash<quint32, QLogger::Levels> s_loggerLevels;

public:
    QList<QAbstractAppender *> m_appenders;

public:
    static void write(QLogger *logger, QLogger::Level level, const QString &text);
};

#endif//QLOGGER_P_H
