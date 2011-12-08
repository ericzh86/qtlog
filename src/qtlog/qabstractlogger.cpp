/*!
  \class QAbstractLogger
  \brief The QAbstractLogger class is the base class of all loggers.
*/

/*!
  \enum QAbstractLogger::Type

  This enum type specifies a type in a logger:

  \value Object
         It is a Qt object logger.
  \value Class
         It is a c++ class object logger.
  \value Root
         It is a root logger in global.
*/

#include "qabstractlogger.h"
#include "private/qabstractlogger_p.h"

#include "qabstractappender.h"

/*!
  \fn QAbstractLogger::QAbstractLogger(QObject *parent)
  \brief Constructs an object with \a dd and parent object \a parent.
*/
QAbstractLogger::QAbstractLogger(QObject *target, QObject *parent)
    : QObject(*new QAbstractLoggerPrivate(), parent)
{
    Q_D(QAbstractLogger);

    d->m_target = target;
}

/*!
  \fn QAbstractLogger::QAbstractLogger(QAbstractLoggerPrivate &dd, QObject *parent)
  \brief Constructs an object with \a dd and parent object \a parent.
*/
QAbstractLogger::QAbstractLogger(QAbstractLoggerPrivate &dd, QObject *target, QObject *parent)
    : QObject(dd, parent)
{
    dd.m_target = target;
}

/*!
  \fn QObject *QAbstractLogger::target() const
  \brief Returns the target pointer of this logger.
*/
QObject *QAbstractLogger::target() const
{
    Q_D(const QAbstractLogger);

    return d->m_target;
}

/*!
  \fn quint32 QAbstractLogger::loggerId() const
  \brief Returns the identifier of this logger.
*/
quint32 QAbstractLogger::loggerId() const
{
    Q_D(const QAbstractLogger);

    return d->m_loggerId;
}

/*!
  \fn void QAbstractLogger::setLevels(QLogLevels newLevels)
  \brief Set the log levels by \a newLevels.
*/
void QAbstractLogger::setLevels(QLogLevels newLevels)
{
    Q_D(QAbstractLogger);

    d->m_levels = newLevels;
}

/*!
  \fn QLogLevels QAbstractLogger::levels() const
  \brief Return the log levels of this appender.
*/
QLogLevels QAbstractLogger::levels() const
{
    Q_D(const QAbstractLogger);

    return d->m_levels;
}

/*!
  \fn void QAbstractLogger::addAppender(QAbstractAppender *appender)
  \brief \a appender.
*/
void QAbstractLogger::addAppender(QAbstractAppender *appender)
{
    Q_D(QAbstractLogger);

    Q_CHECK_PTR(appender);

    if (appender != 0) {
        if (!d->m_appenders.contains(appender)) {
            d->m_appenders.append(appender);
            //
            connect(appender, SIGNAL(destroyed(QObject *)), this, SLOT(_q_removeAppender(QObject *)));
        }
    }
}

/*!
  \fn void QAbstractLogger::removeAppender(QAbstractAppender *appender)
*/
void QAbstractLogger::removeAppender(QAbstractAppender *appender)
{
    Q_D(QAbstractLogger);

    Q_CHECK_PTR(appender);

    if (appender != 0) {
        if (d->m_appenders.contains(appender)) {
            d->m_appenders.removeOne(appender);
            //
            appender->disconnect(this);
        }
    }
}

/*!
  \fn const QList<QAbstractAppender *> &QAbstractLogger::appenders() const
*/
const QList<QAbstractAppender *> &QAbstractLogger::appenders() const
{
    Q_D(const QAbstractLogger);

    return d->m_appenders;
}

/*!
  \fn void QAbstractLogger::removeAppender(QObject *appender)
*/
void QAbstractLogger::_q_removeAppender(QObject *appender)
{
    removeAppender(static_cast<QAbstractAppender *>(appender));
}

/*!
  \fn void QAbstractLogger::write(QAbstractLogger *logger, QLogLevel level, const QString &text)
*/
void QAbstractLogger::write(QAbstractLogger *logger, QLogLevel level, const QString &text)
{
    Q_D(QAbstractLogger);

    Q_FOREACH (QAbstractAppender *appender, d->m_appenders) {
        if (appender->isEnabledFor(level)) {
            appender->write(logger, level, text);
        }
    }
}
