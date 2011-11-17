#include "qabstractlogger_p.h"

QAbstractLoggerPrivate::QAbstractLoggerPrivate()
    : QObjectPrivate()
    , m_target(0)
    , m_loggerId(0)
    , m_levels(QtLog::All)
{
}

QAbstractLoggerPrivate::~QAbstractLoggerPrivate()
{
}
