#ifndef QABSTRACTFORMATTER_P_H
#define QABSTRACTFORMATTER_P_H

#include "qobject_p.h"
#include "../qabstractformatter.h"
class QAbstractFormatterPrivate : public QObjectPrivate
{
    Q_DECLARE_PUBLIC(QAbstractFormatter)

public:
    QAbstractFormatterPrivate();
    ~QAbstractFormatterPrivate();

public:
    QLogFormats m_formats;
};

#endif//QABSTRACTFORMATTER_P_H
