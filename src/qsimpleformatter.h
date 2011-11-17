#ifndef QSIMPLEFORMATTER_H
#define QSIMPLEFORMATTER_H

#include "qtlogglobal.h"

#include "qabstractformatter.h"

class QSimpleFormatterPrivate;
class QTLOGSHARED_EXPORT QSimpleFormatter : public QAbstractFormatter
{
    Q_OBJECT

public:
    QSimpleFormatter(bool wrapEnabled, QObject *parent = 0);

public:
    QString format(QAbstractLogger *logger, QLogLevel level, const QString &text);

private:
    Q_DISABLE_COPY(QSimpleFormatter)
    Q_DECLARE_PRIVATE(QSimpleFormatter)
};

#endif//QSIMPLEFORMATTER_H
