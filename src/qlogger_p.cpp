#include "qlogger_p.h"
#include "qabstractappender.h"
#include <QtCore/QCoreApplication>

quint32 QLoggerPrivate::_s_loggerIdCounter = 1;

QHash<QObject *, QLogger *> QLoggerPrivate::s_loggers;

QLogger::Levels QLoggerPrivate::s_rootLoggerLevels = QLogger::All;

QHash<quint32, QLogger::Levels> QLoggerPrivate::s_loggerLevels;

QLoggerPrivate::QLoggerPrivate(bool isRoot)
    : QObjectPrivate()
{
    if (isRoot) {
        _m_loggerId = 0;
    } else {
        _m_loggerId = _s_loggerIdCounter++;
    }
}

QLoggerPrivate::~QLoggerPrivate()
{
    Q_Q(QLogger);

    if (_m_loggerId == 0) {
        s_loggers.remove(0);
    } else {
        s_loggers.remove(q->parent());
    }

    s_loggerLevels.remove(_m_loggerId);
}

QLogger *QLoggerPrivate::logger(QObject *target)
{
    QLogger *logger = s_loggers.value(target);

    if (logger == 0) {
        if (target == 0) {
            logger = new QLogger(qApp, true);
        } else {
            logger = new QLogger(target, false);
        }
        s_loggers.insert(target, logger);
    }

    return logger;
}

void QLoggerPrivate::write(QLogger *logger, QLogger::Level level, const QString &text)
{
    if (s_loggers.contains(0)) {
        QLogger *rootLogger = s_loggers.value(0);
        QList<QAbstractAppender *> appenders = rootLogger->d_func()->m_appenders;
        if (!appenders.isEmpty()) {
            foreach (QAbstractAppender *appender, appenders) {
                appender->_write(logger, level, text);
            }
        }
    }

    // If the logger is not root logger.
    if (logger->loggerId() != 0) {
        QList<QAbstractAppender *> appenders = logger->d_func()->m_appenders;
        if (!appenders.isEmpty()) {
            foreach (QAbstractAppender *appender, appenders) {
                appender->_write(logger, level, text);
            }
        }
    }
}

