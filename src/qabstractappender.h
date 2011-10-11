#ifndef QABSTRACTAPPENDER_H
#define QABSTRACTAPPENDER_H

#include "qtlogglobal.h"
#include "qlogger.h"

class QLoggerKernel;

class QTLOGSHARED_EXPORT QAbstractAppender
{
    friend class QLoggerKernel;

public:
    QAbstractAppender();

public:
    virtual bool isOpen() const { return false; }
private:
    virtual void _write(QLogger *logger, QLogger::Level level, const QString &text) = 0;

public:
    QLogger::Levels levels() const;
public:
    void setLevels(QLogger::Levels levels);

private:
    QLogger::Levels _m_levels;
};

Q_DECLARE_INTERFACE(QAbstractAppender, "com.zhouj.QtLog.QAbstractAppender/1.0")

#endif//QABSTRACTAPPENDER_H
