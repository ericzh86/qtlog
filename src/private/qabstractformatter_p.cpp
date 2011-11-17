#include "qabstractformatter_p.h"

QAbstractFormatterPrivate::QAbstractFormatterPrivate()
    : QObjectPrivate()
    , m_formats(QtLog::AllFormats)
{
}

QAbstractFormatterPrivate::~QAbstractFormatterPrivate()
{
}
