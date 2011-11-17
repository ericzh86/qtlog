/*!
    \class QTextFileAppender
    \brief The QTextFileAppender class.
*/

#include "qtextfileappender.h"

////////////////////////////////////////////////////////////////////////////////
// QTextFileAppenderPrivate

#include "private/qabstractappender_p.h"

#include <QtCore/QFile>

class QTextFileAppenderPrivate : public QAbstractAppenderPrivate
{
	Q_DECLARE_PUBLIC(QTextFileAppender)

public:
	QTextFileAppenderPrivate();
	~QTextFileAppenderPrivate();

public:
	QFile m_file;
};

QTextFileAppenderPrivate::QTextFileAppenderPrivate()
    : QAbstractAppenderPrivate()
{
}

QTextFileAppenderPrivate::~QTextFileAppenderPrivate()
{
    m_file.close();
}

////////////////////////////////////////////////////////////////////////////////
// QTextFileAppender

#include "qsimpleformatter.h"

/*!
  \fn QTextFileAppender::QTextFileAppender(QString &fileName, QObject *parent)
  \brief Construct a QTextFileAppender class. \a fileName and \a parent.
*/
QTextFileAppender::QTextFileAppender(const QString &fileName, QObject *parent)
    : QAbstractAppender(*new QTextFileAppenderPrivate(), parent)
{
    setFormatter(new QSimpleFormatter(true, this));

    Q_D(QTextFileAppender);

    d->m_file.setFileName(fileName);

    if (d->m_file.open(QFile::WriteOnly | QFile::Unbuffered)) {
        // do nothing.
    } else {
        //
    }
}

/*!
  \fn void QTextFileAppender::write(QAbstractLogger *logger, QLogLevel level, const QString &text)
*/
void QTextFileAppender::write(QAbstractLogger *logger, QLogLevel level, const QString &text)
{
    Q_D(QTextFileAppender);

    d->m_file.write(formatter()->format(logger, level, text).toLocal8Bit());
}
