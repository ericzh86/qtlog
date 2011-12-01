#include "qsimpleformatter.h"
#include "private/qabstractformatter_p.h"

class QSimpleFormatterPrivate : public QAbstractFormatterPrivate
{
public:
    QSimpleFormatterPrivate();
    ~QSimpleFormatterPrivate();

public:
    bool m_wrapEnabled;
};

QSimpleFormatterPrivate::QSimpleFormatterPrivate()
    : QAbstractFormatterPrivate()
    , m_wrapEnabled(false)
{
}

QSimpleFormatterPrivate::~QSimpleFormatterPrivate()
{
}

QSimpleFormatter::QSimpleFormatter(bool wrapEnabled, QObject *parent)
    : QAbstractFormatter(*new QSimpleFormatterPrivate(), parent)
{
    Q_D(QSimpleFormatter);

    d->m_wrapEnabled = wrapEnabled;
}

#include "qabstractlogger.h"

#include <QDateTime>

#if defined(Q_OS_WIN)
QString wordWrap = QString::fromLatin1("\r\n");
#endif
#if defined(Q_OS_MAC)
QString wordWrap = QString::fromLatin1("\r");
#endif
#if defined(Q_OS_LINUX)
QString wordWrap = QString::fromLatin1("\n");
#endif

#include <QStringBuilder>

QString QSimpleFormatter::format(QAbstractLogger *logger, QLogLevel level, const QString &text)
{
    Q_D(QSimpleFormatter);

    const QObject *target = logger->target();
    const QMetaObject *metaObject = target->metaObject();

    QString levelName;
    switch (level) {
        case QtLog::Off:
            // Nothing.
            break;
        case QtLog::Fatal:
            levelName = QString::fromLatin1("Fatal");
            break;
        case QtLog::Error:
            levelName = QString::fromLatin1("Error");
            break;
        case QtLog::Warn:
            levelName = QString::fromLatin1("Warn");
            break;
        case QtLog::Info:
            levelName = QString::fromLatin1("Info");
            break;
        case QtLog::Debug:
            levelName = QString::fromLatin1("Debug");
            break;
        case QtLog::Trace:
            levelName = QString::fromLatin1("Trace");
            break;
        case QtLog::All:
            // Nothing.
            break;
    }

    QString className;
    if (formats() & QtLog::ClassName) {
        QString mClassName = QString::fromLatin1(metaObject->className());
        QString objectName = target->objectName();
        if (objectName.isEmpty()) {
            className = mClassName;
        } else {
            className = mClassName % "#" % objectName;
        }
    }

    QString now;
    if (formats() & QtLog::Date) {
        if (formats() & QtLog::Time) {
            // DateTime
            now = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        } else {
            // Date
            now = QDate::currentDate().toString("yyyy-MM-dd");
        }
    } else if (formats() & QtLog::Time) {
        // Time
        now = QTime::currentTime().toString("hh:mm:ss.zzz");
    }
    
    if (formats() & QtLog::ClassName) {
        if (formats() & (QtLog::Date | QtLog::Time)) {
            if (d->m_wrapEnabled) {
                return QString("%1 %2(%3): %4%5").arg(levelName, className, now, text, wordWrap);
            } else {
                return QString("%1 %2(%3): %4").arg(levelName, className, now, text);
            }
        } else {
            if (d->m_wrapEnabled) {
                return QString("%1 %2: %3%4").arg(levelName, className, text, wordWrap);
            } else {
                return QString("%1 %2: %3").arg(levelName, className, text);
            }
        }
    } else {
        if (formats() & (QtLog::Date | QtLog::Time)) {
            if (d->m_wrapEnabled) {
                return QString("%1(%2): %3%4").arg(levelName, now, text, wordWrap);
            } else {
                return QString("%1(%2): %3").arg(levelName, now, text);
            }
        } else {
            if (d->m_wrapEnabled) {
                return QString("%1: %2%3").arg(levelName, text, wordWrap);
            } else {
                return QString("%1: %2").arg(levelName, text);
            }
        }
    }
}
