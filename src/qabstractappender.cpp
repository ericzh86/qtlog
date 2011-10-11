#include "qabstractappender.h"

QAbstractAppender::QAbstractAppender()
    : _m_levels(QLogger::All)
{
}

QLogger::Levels QAbstractAppender::levels() const
{
    return _m_levels;
}

void QAbstractAppender::setLevels(QLogger::Levels levels)
{
    _m_levels = levels;
}
