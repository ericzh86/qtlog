/*!
  \class QAbstractAppender
  \brief The QAbstractAppender class is the base class of all appenders.
*/

/*!
  \enum QAbstractAppender::Type

  This enum type specifies a type in a appender:

  \value TextFile
         The appender is a plain text file.
  \value Console
         The appender is a console.
  \value DBFile
         The appender is a sqlite database file.
*/

#include "qabstractappender.h"
#include "private/qabstractappender_p.h"

#include "qsimpleformatter.h"

/*!
  \fn QAbstractAppender::QAbstractAppender(QAbstractAppenderPrivate &dd, QObject *parent)
  \brief \a dd and \a parent
*/
QAbstractAppender::QAbstractAppender(QObject *parent)
    : QObject(*new QAbstractAppenderPrivate(), parent)
{
}

/*!
  \fn QAbstractAppender::QAbstractAppender(QAbstractAppenderPrivate &dd, QObject *parent)
  \brief \a dd and \a parent
*/
QAbstractAppender::QAbstractAppender(QAbstractAppenderPrivate &dd, QObject *parent)
    : QObject(dd, parent)
{
}

/*!
  \fn void QAbstractAppender::setLevels(QLogLevels newLevels)
  \brief Set the log levels by \a newLevels.
*/
void QAbstractAppender::setLevels(QLogLevels newLevels)
{
    Q_D(QAbstractAppender);

    d->m_levels = newLevels;
}

/*!
  \fn QLogLevels QAbstractAppender::levels() const
  \brief Return the log levels of this appender.
*/
QLogLevels QAbstractAppender::levels() const
{
    Q_D(const QAbstractAppender);

    return d->m_levels;
}

void QAbstractAppender::setFormatter(QAbstractFormatter *formatter)
{
    Q_D(QAbstractAppender);

    d->m_formatter = formatter;
}

QAbstractFormatter *QAbstractAppender::formatter() const
{
    Q_D(const QAbstractAppender);

    return d->m_formatter;
}

/*!
  \fn virtual void QAbstractAppender::write(QAbstractLogger *logger, QLogLevel level, const QString &text) = 0
  \brief \a logger, \a level and \a text.
*/
