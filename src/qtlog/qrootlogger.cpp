#include "qrootlogger.h"

//////////////////////////////////////////////////////////////////////////
// QRootLoggerPrivate

#include "private/qabstractlogger_p.h"

class QRootLoggerPrivate : public QAbstractLoggerPrivate
{
    Q_DECLARE_PUBLIC(QRootLogger)

public:
    QRootLoggerPrivate();
    ~QRootLoggerPrivate();
};

QRootLoggerPrivate::QRootLoggerPrivate()
    : QAbstractLoggerPrivate()
{
}

QRootLoggerPrivate::~QRootLoggerPrivate()
{
}

//////////////////////////////////////////////////////////////////////////
// QRootLogger

#include "qrootloggerfactory.h"

QRootLogger::QRootLogger(QObject *target, QObject *parent)
    : QAbstractLogger(*new QRootLoggerPrivate(), target, parent)
{
}

QRootLogger *QRootLogger::logger()
{
    return QRootLoggerFactory::instance()->logger();
}