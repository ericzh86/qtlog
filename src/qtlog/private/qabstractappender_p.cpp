#include "qabstractappender_p.h"

QAbstractAppenderPrivate::QAbstractAppenderPrivate()
    : QObjectPrivate()
    , m_levels(QtLog::All)
    , m_formatter(0)
{
}

QAbstractAppenderPrivate::~QAbstractAppenderPrivate()
{
}
