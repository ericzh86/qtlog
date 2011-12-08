/*!
  \class QSQLiteAppender
  \brief The QSQLiteAppender class.
*/

#include "qsqliteappender.h"

////////////////////////////////////////////////////////////////////////////////
// QSQLiteAppenderPrivate

#include "private/qabstractappender_p.h"

#include <QtCore/QFile>
#include <QtCore/QSet>

class QSQLiteAppenderPrivate : public QAbstractAppenderPrivate
{
    Q_DECLARE_PUBLIC(QSQLiteAppender)

public:
    QSQLiteAppenderPrivate();
    ~QSQLiteAppenderPrivate();

public:
	QFile m_file;
public:
	QDataStream m_writer;
public:
    QSet<quint32> m_loggerIds;
};

QSQLiteAppenderPrivate::QSQLiteAppenderPrivate()
    : QAbstractAppenderPrivate()
{
}

QSQLiteAppenderPrivate::~QSQLiteAppenderPrivate()
{
    m_file.close();
}

////////////////////////////////////////////////////////////////////////////////
// QSQLiteAppender

/*!
  \fn QSQLiteAppender::QSQLiteAppender(QString &fileName, QObject *parent)
*/
QSQLiteAppender::QSQLiteAppender(const QString &fileName, QObject *parent)
    : QAbstractAppender(*new QSQLiteAppenderPrivate(), parent)
{
    Q_D(QSQLiteAppender);

    d->m_file.setFileName(fileName);

    if (d->m_file.open(QFile::WriteOnly | QFile::Unbuffered)) {
        d->m_writer.setDevice(&d->m_file);
        // Write the file flag.
        char fileFlag[] = {"QtLog format v1"};
        d->m_writer.writeRawData(fileFlag, 16);
    } else {
        //
    }
}

#include "qabstractlogger.h"

#include <QtCore/QTime>

/*!
  \fn void void QSQLiteAppender::write(QAbstractLogger *logger, QLogLevel level, const QString &text)
*/
void QSQLiteAppender::write(QAbstractLogger *logger, QLogLevel level, const QString &text)
{
    Q_D(QSQLiteAppender);

    if (!d->m_loggerIds.contains(logger->loggerId())) {
        const QObject *target = logger->target();
        const QMetaObject *metaObject = target->metaObject();
        // Write object info.
        QString className = QString::fromLatin1(metaObject->className());
        d->m_writer << quint8(0) << logger->loggerId() << className << target->objectName();
        // Cache logger id.
        d->m_loggerIds.insert(logger->loggerId());
	}

    // Write content.
	QDateTime now = QDateTime::currentDateTime();
	d->m_writer << quint8(1) << quint8(level) << now << logger->loggerId() << text.toUtf8();
}
