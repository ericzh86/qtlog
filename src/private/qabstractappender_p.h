#ifndef QABSTRACTAPPENDER_P_H
#define QABSTRACTAPPENDER_P_H

#include "qobject_p.h"
#include "../qabstractappender.h"
class QAbstractAppenderPrivate : public QObjectPrivate
{
    Q_DECLARE_PUBLIC(QAbstractAppender)

public:
    QAbstractAppenderPrivate();
    ~QAbstractAppenderPrivate();

public:
    QLogLevels               m_levels;
public:
    QAbstractFormatter      *m_formatter;
};

#endif//QABSTRACTAPPENDER_P_H
