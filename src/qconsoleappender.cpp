#include "qconsoleappender.h"

#include <QtCore/QTime>
#include <QtCore/QtDebug>

#include "private/qobject_p.h"
class QConsoleAppenderPrivate : public QObjectPrivate
{
	Q_DECLARE_PUBLIC(QConsoleAppender)
public:
	QConsoleAppenderPrivate();
	~QConsoleAppenderPrivate();
};

QConsoleAppenderPrivate::QConsoleAppenderPrivate()
	: QObjectPrivate()
{
}

QConsoleAppenderPrivate::~QConsoleAppenderPrivate()
{
}

QConsoleAppender::QConsoleAppender(QObject *parent)
	: QObject(*new QConsoleAppenderPrivate(), parent)
{
}

void QConsoleAppender::_write(QLogger *logger, QLogger::Level level, const QString &text)
{
    // Level check.
	if (!(levels() & level)) {
		return;
	}

	QObject *target = logger->target();
	
	QString targetName = QLatin1String(target->metaObject()->className());
	if (!target->objectName().isEmpty())
		targetName += "#" + target->objectName();

	QString now = QTime::currentTime().toString("hh:mm:ss.zzz");

	QString targetAddress = QString("%1").arg((qulonglong)target, 8, 10, QLatin1Char('0'));

	switch (level) {
        case QLogger::Off:
            // Nothing.
            break;
		case QLogger::Fatal:
            qDebug() << QString("Fatal %1(%2,0x%3): %4").arg(targetName).arg(now).arg(targetAddress).arg(text);
			break;
		case QLogger::Error:
            qDebug() << QString("Error %1(%2,0x%3): %4").arg(targetName).arg(now).arg(targetAddress).arg(text);
			break;
		case QLogger::Warn:
            qDebug() << QString("Warn %1(%2,0x%3): %4").arg(targetName).arg(now).arg(targetAddress).arg(text);
			break;
		case QLogger::Info:
			qDebug() << QString("Info %1(%2,0x%3): %4").arg(targetName).arg(now).arg(targetAddress).arg(text);
			break;
		case QLogger::Debug:
			qDebug() << QString("Debug %1(%2,0x%3): %4").arg(targetName).arg(now).arg(targetAddress).arg(text);
			break;
		case QLogger::Trace:
			qDebug() << QString("Trace %1(%2,0x%3): %4").arg(targetName).arg(now).arg(targetAddress).arg(text);
			break;
        case QLogger::All:
            // Nothing.
            break;
	}
}
