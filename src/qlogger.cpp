#include "qlogger.h"

#include "qlogger_p.h"
#include "qabstractappender.h"

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

// Q_DECLARE_METATYPE(QLogger::Level)

void QLogger::clearLevels()
{
    Q_D(QLogger);

    quint32 id = d->loggerId();

    if (id == 0) {
        // do nothing.
    } else {
        QLoggerPrivate::s_loggerLevels.remove(id);
    }
}

QLogger::Levels QLogger::levels() const
{
    Q_D(const QLogger);

    quint32 id = d->loggerId();

    QLogger::Levels levels = QLoggerPrivate::s_rootLoggerLevels;
    if (id == 0) {
        // do nothing.
    } else {
        levels = QLoggerPrivate::s_loggerLevels.value(id, levels);
    }

    return levels;
}

void QLogger::setLevels(Levels ls)
{
    Q_D(QLogger);

    quint32 id = d->loggerId();

    if (id == 0) {
        QLoggerPrivate::s_rootLoggerLevels = ls;
    } else {
        QLoggerPrivate::s_loggerLevels.insert(id, ls);
    }
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
    return QLoggerPrivate::logger(0);
}

QLogger *QLogger::logger(QObject *target)
{
    return QLoggerPrivate::logger(target);
}

void QLogger::_write(Level level, const QString &text)
{
    QLoggerPrivate::write(this, level, text);
}
