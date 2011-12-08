#ifndef QOBJECTLOGGER_H
#define QOBJECTLOGGER_H

#include "qabstractlogger.h"

class QObjectLoggerPrivate;
class QTLOGSHARED_EXPORT QObjectLogger : public QAbstractLogger
{
    Q_OBJECT

private:
    QObjectLogger(QObject *target, QObject *parent);
public:
    static QObjectLogger *logger(QObject *target);

public:
    void setRootLoggerEnabled(bool enable);
public:
    bool isRootLoggerEnabled() const;

public:
    void setRootLevelsEnabled(bool enable);
public:
    bool isRootLevelsEnabled() const;

public:
    QLogLevels levels() const;

private:
    void write(QAbstractLogger *logger, QLogLevel level, const QString &text);

private:
    friend class QObjectLoggerFactory;

private:
    Q_DISABLE_COPY(QObjectLogger)
    Q_DECLARE_PRIVATE(QObjectLogger)    
};

#define Q_LOGGER                                \
    private:                                    \
        QObjectLogger *logger()                 \
        {                                       \
            return QObjectLogger::logger(this); \
        }                                       \
    private:

#endif//QOBJECTLOGGER_H
