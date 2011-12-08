#ifndef QABSTRACTAPPENDER_H
#define QABSTRACTAPPENDER_H

#include "qtlogglobal.h"

#include <QObject>
class QAbstractAppenderPrivate;
class QTLOGSHARED_EXPORT QAbstractAppender : public QObject
{
    Q_OBJECT

    // Constructors
protected:
    explicit QAbstractAppender(QObject *parent = 0);
protected:
    explicit QAbstractAppender(QAbstractAppenderPrivate &dd, QObject *parent = 0);

    // Levels
public:
    void setLevels(QLogLevels newLevels);
public:
    QLogLevels levels() const;

public:
    bool isEnabledFor(QLogLevel level) const;

    // Formatter
public:
    void setFormatter(QAbstractFormatter *formatter);
public:
    QAbstractFormatter *formatter() const;

    //
protected:
    virtual void write(QAbstractLogger *logger, QLogLevel level, const QString &text) = 0;

private:
    friend class QAbstractLogger;

private:
    Q_DISABLE_COPY(QAbstractAppender)
    Q_DECLARE_PRIVATE(QAbstractAppender)
};

//////////////////////////////////////////////////////////////////////////
// QAbstractLogger Inline Functions

inline bool QAbstractAppender::isEnabledFor(QLogLevel level) const
{
    return (levels() & level);
}

#endif//QABSTRACTAPPENDER_H
