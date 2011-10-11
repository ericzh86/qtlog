#include "qdbfileappender.h"

#include <QtCore/QFile>
#include <QtCore/QSet>
#include <QtCore/QTime>

#include "private/qobject_p.h"
class QDBFileAppenderPrivate : public QObjectPrivate
{
	Q_DECLARE_PUBLIC(QDBFileAppender)
public:
	QDBFileAppenderPrivate();
	~QDBFileAppenderPrivate();

public:
	QFile m_file;
public:
	QDataStream m_writer;
public:
	QSet<quint32> m_loggers;
};

QDBFileAppenderPrivate::QDBFileAppenderPrivate()
	: QObjectPrivate()
{
}

QDBFileAppenderPrivate::~QDBFileAppenderPrivate()
{
	if (m_file.isOpen()) {
		m_file.close();
	}
}

//////////////////////////////////////////////////////////////////////////

QDBFileAppender::QDBFileAppender(QObject *parent)
	: QObject(*new QDBFileAppenderPrivate(), parent)
{
}

QDBFileAppender::QDBFileAppender(QString &fileName, QObject *parent)
	: QObject(*new QDBFileAppenderPrivate(), parent)
{
	setFileName(fileName);
	if (!open()) {
		qDebug(qPrintable(QString("DatabaseAppender::DatabaseAppender: The file(%1) open failed.").arg(fileName)));
	}
}

QString QDBFileAppender::fileName() const
{
	Q_D(const QDBFileAppender);

	return d->m_file.fileName();
}

void QDBFileAppender::setFileName(const QString &fileName)
{
	Q_D(QDBFileAppender);

	if (!d->m_file.isOpen())
		d->m_file.setFileName(fileName);
}

bool QDBFileAppender::open()
{
	Q_D(QDBFileAppender);

	if (d->m_file.isOpen())
		return true;

    if (d->m_file.open(QFile::WriteOnly | QFile::Unbuffered)) {
		d->m_writer.setDevice(&d->m_file);
        char fileFlag[] = {"QtLog format v1"};
        d->m_writer.writeRawData(fileFlag, 16);
		return true;
	}

	return false;
}

void QDBFileAppender::close()
{
    Q_D(QDBFileAppender);

    d->m_file.close();
}

bool QDBFileAppender::isOpen() const
{
	Q_D(const QDBFileAppender);

	return d->m_file.isOpen();
}

void QDBFileAppender::_write(QLogger *logger, QLogger::Level level, const QString &text)
{
    // Level check.
	if (!(levels() & level)) {
		return;
	}

	Q_D(QDBFileAppender);

	if (!d->m_loggers.contains(logger->loggerId())) {
        // Write object info.
        QString className = QString::fromLatin1(logger->target()->metaObject()->className());
		d->m_writer << quint8(0) << logger->loggerId() << className << logger->target()->objectName();
        // Cache index.
		d->m_loggers.insert(logger->loggerId());
	}

    // Write content.
	QDateTime now = QDateTime::currentDateTime();
	d->m_writer << quint8(1) << quint8(level) << now << logger->loggerId() << text.toUtf8();
}
