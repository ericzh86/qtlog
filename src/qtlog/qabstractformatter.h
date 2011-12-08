#ifndef QABSTRACTFORMATTER_H
#define QABSTRACTFORMATTER_H

#include "qtlogglobal.h"

#include <QtCore/QObject>
class QAbstractFormatterPrivate;
class QTLOGSHARED_EXPORT QAbstractFormatter : public QObject
{
    Q_OBJECT

protected:
    explicit QAbstractFormatter(QObject *parent = 0);
protected:
    explicit QAbstractFormatter(QAbstractFormatterPrivate &dd, QObject *parent = 0);

public:
    void setFormats(QLogFormats newFormats);
public:
    QLogFormats formats() const;

public:
    virtual QString format(QAbstractLogger *logger, QLogLevel level, const QString &text) = 0;

private:
    Q_DISABLE_COPY(QAbstractFormatter)
    Q_DECLARE_PRIVATE(QAbstractFormatter)
};

#endif//QABSTRACTFORMATTER_H
