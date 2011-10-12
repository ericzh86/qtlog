#ifndef QABSTRACTAPPENDER_H
#define QABSTRACTAPPENDER_H

#include "qtlogglobal.h"
#include "qlogger.h"

class QLoggerPrivate;

class QTLOGSHARED_EXPORT QAbstractAppender
{
    friend class QLoggerPrivate;

public:
    QAbstractAppender();

private:
    virtual void _write(QLogger *logger, QLogger::Level level, const QString &text) = 0;

public:
    void setLevels(QLogger::Levels levels);
public:
    QLogger::Levels levels() const;
private:
    QLogger::Levels _m_levels;
};

Q_DECLARE_INTERFACE(QAbstractAppender, "com.zhouj.QtLog.QAbstractAppender/1.0")

#endif//QABSTRACTAPPENDER_H
