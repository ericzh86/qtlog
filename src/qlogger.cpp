#include "qlogger.h"

#include "qloggerkernel.h"
#include "qabstractappender.h"

QLoggerKernel theKernel;

//////////////////////////////////////////////////////////////////////////
// QLoggerPrivate
//

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
    bool m_usePrivateLevels;
public:
    QLogger::Levels m_levels;

public:
    QList<QAbstractAppender *> m_appenders;
};

QLoggerPrivate::QLoggerPrivate(bool isRoot)
	: QObjectPrivate()
        , m_levels(QLogger::All)
{
    if (isRoot) {
        _m_loggerId = 0;
        m_usePrivateLevels = true;
    } else {
        _m_loggerId = _s_loggerIdCounter++;
        m_usePrivateLevels = false;
    }
}

QLoggerPrivate::~QLoggerPrivate()
{
}

// The root logger id is 0, so the object logger's id have to count from 1.
quint32 QLoggerPrivate::_s_loggerIdCounter = 1;

//////////////////////////////////////////////////////////////////////////
// QLogger

QLogger::QLogger(QObject *parent, bool isRoot)
    : QObject(*new QLoggerPrivate(isRoot), parent)
{
}

QObject *QLogger::target() const
{
    return parent();
}

quint32 QLogger::loggerId() const
{
    Q_D(const QLogger);

    return d->loggerId();
}

Q_DECLARE_METATYPE(QLogger::Level)

void QLogger::clearLevels()
{
    Q_D(QLogger);

    // The object logger only.
    if (d->loggerId() != 0)
        d->m_usePrivateLevels = false;
}

QLogger::Levels QLogger::levels() const
{
    Q_D(const QLogger);

    if (d->m_usePrivateLevels)
        return d->m_levels;
    return rootLogger()->levels();
}

void QLogger::setLevels(Levels levels)
{
    Q_D(QLogger);

    d->m_levels = levels;
    d->m_usePrivateLevels = true;
}

void QLogger::addAppender(QObject *appender)
{
    Q_D(QLogger);

    QAbstractAppender *appender2 = qobject_cast<QAbstractAppender *>(appender);
    if (appender2) {
        if (!d->m_appenders.contains(appender2)) {
            connect(appender, SIGNAL(destroyed(QObject *)), this, SLOT(removeAppender(QObject *)));
            d->m_appenders.append(appender2);
        }
    }
}

void QLogger::removeAppender(QObject *appender)
{
    Q_D(QLogger);

    QAbstractAppender *appender2 = qobject_cast<QAbstractAppender *>(appender);
    if (appender2) {
        if (d->m_appenders.contains(appender2)) {
            disconnect(appender, SIGNAL(destroyed(QObject *)), this, SLOT(removeAppender(QObject *)));
            d->m_appenders.removeOne(appender2);
        }
    }
}

QLogger *QLogger::rootLogger()
{
    return QLoggerKernel::instance()->rootLogger();
}

QLogger *QLogger::logger(QObject *target)
{
    return QLoggerKernel::instance()->logger(target);
}

QList<QAbstractAppender *> QLogger::_appenders() const
{
    Q_D(const QLogger);

    return d->m_appenders;
}

void QLogger::_write(Level level, const QString &text)
{
    QLoggerKernel::instance()->log(this, level, text);
}
