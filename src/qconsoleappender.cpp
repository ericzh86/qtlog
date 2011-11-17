/*!
  \class QConsoleAppender
  \brief The QConsoleAppender class.
*/

#include "qconsoleappender.h"

////////////////////////////////////////////////////////////////////////////////
// QConsoleAppenderPrivate

#include "private/qabstractappender_p.h"

#include <QtCore/QTextStream>

class QConsoleAppenderPrivate : public QAbstractAppenderPrivate
{
	Q_DECLARE_PUBLIC(QConsoleAppender)

public:
	QConsoleAppenderPrivate();
	~QConsoleAppenderPrivate();
};

QConsoleAppenderPrivate::QConsoleAppenderPrivate()
    : QAbstractAppenderPrivate()
{
}

QConsoleAppenderPrivate::~QConsoleAppenderPrivate()
{
}

////////////////////////////////////////////////////////////////////////////////
// QConsoleAppender

#include "qsimpleformatter.h"

/*!
  \fn QConsoleAppender::QConsoleAppender(QObject *parent)
  \brief Constructs an object with parent object \a parent.
*/
QConsoleAppender::QConsoleAppender(QObject *parent)
    : QAbstractAppender(*new QConsoleAppenderPrivate(), parent)
{
    setFormatter(new QSimpleFormatter(false, this));
}

#include <QtDebug>

/*!
  \fn void QConsoleAppender::write(QAbstractLogger *logger, QLogLevel level, const QString &text)
  \brief \a logger, \a level and \a text.
*/
void QConsoleAppender::write(QAbstractLogger *logger, QLogLevel level, const QString &text)
{
    qDebug() << formatter()->format(logger, level, text);
}
