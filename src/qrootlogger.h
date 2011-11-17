#ifndef QROOTLOGGER_H
#define QROOTLOGGER_H

#include "qabstractlogger.h"

class QRootLoggerPrivate;
class QTLOGSHARED_EXPORT QRootLogger : public QAbstractLogger
{
    Q_OBJECT

private:
    QRootLogger(QObject *target, QObject *parent);
public:
    static QRootLogger *logger();

private:
    friend class QRootLoggerFactory;

private:
    Q_DISABLE_COPY(QRootLogger)
    Q_DECLARE_PRIVATE(QRootLogger)    
};

namespace QtLog
{
    inline QRootLogger *rootLogger()
    {
        return QRootLogger::logger();
    }
}

#endif//QROOTLOGGER_H
