#include "qobjectlogger.h"

//////////////////////////////////////////////////////////////////////////
// QObjectLoggerPrivate

#include "private/qabstractlogger_p.h"

class QObjectLoggerPrivate : public QAbstractLoggerPrivate
{
    Q_DECLARE_PUBLIC(QObjectLogger)

public:
    QObjectLoggerPrivate();
    ~QObjectLoggerPrivate();

public:
    static quint32 s_loggerIdCounter;

public:
    bool m_isRootLoggerEnabled;
public:
    bool m_isRootLevelsEnabled;
};

QObjectLoggerPrivate::QObjectLoggerPrivate()
    : QAbstractLoggerPrivate()
    , m_isRootLoggerEnabled(true)
    , m_isRootLevelsEnabled(true)
{
    m_loggerId = ++s_loggerIdCounter;
}

QObjectLoggerPrivate::~QObjectLoggerPrivate()
{
}

quint32 QObjectLoggerPrivate::s_loggerIdCounter;

//////////////////////////////////////////////////////////////////////////
// QObjectLogger

#include "qrootlogger.h"
#include "qobjectloggerfactory.h"

QObjectLogger::QObjectLogger(QObject *target, QObject *parent)
    : QAbstractLogger(*new QObjectLoggerPrivate(), target, parent)
{
}

QObjectLogger *QObjectLogger::logger(QObject *target)
{
    return QObjectLoggerFactory::instance()->logger(target);
}

void QObjectLogger::setRootLoggerEnabled(bool enable)
{
    Q_D(QObjectLogger);

    d->m_isRootLoggerEnabled = enable;
}

bool QObjectLogger::isRootLoggerEnabled() const
{
    Q_D(const QObjectLogger);

    return d->m_isRootLoggerEnabled;
}

void QObjectLogger::setRootLevelsEnabled(bool enable)
{
    Q_D(QObjectLogger);

    d->m_isRootLevelsEnabled = enable;
}

bool QObjectLogger::isRootLevelsEnabled() const
{
    Q_D(const QObjectLogger);

    return d->m_isRootLevelsEnabled;
}

QLogLevels QObjectLogger::levels() const
{
    Q_D(const QObjectLogger);

    if (d->m_isRootLevelsEnabled)
        return QRootLogger::logger()->levels();
    return QAbstractLogger::levels();
}

void QObjectLogger::write(QAbstractLogger *logger, QLogLevel level, const QString &text)
{
    Q_D(QObjectLogger);

    if (d->m_isRootLoggerEnabled)
        QRootLogger::logger()->write(logger, level, text);
    QAbstractLogger::write(logger, level, text);
}
