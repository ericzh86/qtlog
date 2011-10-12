#include "qtextfileappender.h"

#include <QtCore/QFile>
#include <QtCore/QTime>

#include "private/qobject_p.h"
class QTextFileAppenderPrivate : public QObjectPrivate
{
	Q_DECLARE_PUBLIC(QTextFileAppender)
public:
	QTextFileAppenderPrivate();
	~QTextFileAppenderPrivate();

public:
	QFile m_file;
};

QTextFileAppenderPrivate::QTextFileAppenderPrivate()
    : QObjectPrivate()
{
}

QTextFileAppenderPrivate::~QTextFileAppenderPrivate()
{
	if (m_file.isOpen()) {
		m_file.close();
	}
}

//////////////////////////////////////////////////////////////////////////

QTextFileAppender::QTextFileAppender(QObject *parent)
    : QObject(*new QTextFileAppenderPrivate(), parent)
{
}

QTextFileAppender::QTextFileAppender(QString &fileName, QObject *parent)
    : QObject(*new QTextFileAppenderPrivate(), parent)
{
	setFileName(fileName);
	if (!open()) {
		qDebug(qPrintable(QString("TextFileAppender::TextFileAppender: The file(%1) open failed.").arg(fileName)));
	}
}

QString QTextFileAppender::fileName() const
{
	Q_D(const QTextFileAppender);

	return d->m_file.fileName();
}

void QTextFileAppender::setFileName(const QString &fileName)
{
	Q_D(QTextFileAppender);

	if (!d->m_file.isOpen())
		d->m_file.setFileName(fileName);
}

bool QTextFileAppender::open()
{
	Q_D(QTextFileAppender);

	if (d->m_file.isOpen())
		return true;

	return d->m_file.open(QFile::WriteOnly | QFile::Unbuffered);
}

void QTextFileAppender::close()
{
    Q_D(QTextFileAppender);

    d->m_file.close();
}

bool QTextFileAppender::isOpen() const
{
	Q_D(const QTextFileAppender);

	return d->m_file.isOpen();
}

void QTextFileAppender::_write(QLogger *logger, QLogger::Level level, const QString &text)
{
    // Level check.
	if (!(levels() & level)) {
		return;
	}

	Q_D(QTextFileAppender);

	QObject *target = logger->target();

	QString targetName = QLatin1String(target->metaObject()->className());
	if (!target->objectName().isEmpty())
		targetName += "#" + target->objectName();

	QString now = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");

	QString content;
	switch (level) {
        case QLogger::Off:
            // Nothing.
            break;
		case QLogger::Fatal:
			content = QString("Fatal %1(%2): %3\n").arg(targetName).arg(now).arg(text);
			break;
		case QLogger::Error:
			content = QString("Error %1(%2): %3\n").arg(targetName).arg(now).arg(text);
			break;
		case QLogger::Warn:
			content = QString("Warn %1(%2): %3\n").arg(targetName).arg(now).arg(text);
			break;
		case QLogger::Info:
			content = QString("Info %1(%2): %3\n").arg(targetName).arg(now).arg(text);
			break;
		case QLogger::Debug:
			content = QString("Debug %1(%2): %3\n").arg(targetName).arg(now).arg(text);
			break;
		case QLogger::Trace:
			content = QString("Trace %1(%2): %3\n").arg(targetName).arg(now).arg(text);
			break;
        case QLogger::All:
            // Nothing.
            break;
	}

	d->m_file.write(content.toLocal8Bit());
}
