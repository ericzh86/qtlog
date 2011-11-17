#include "qabstractformatter.h"
#include "private/qabstractformatter_p.h"

QAbstractFormatter::QAbstractFormatter(QObject *parent)
    : QObject(*new QAbstractFormatterPrivate(), parent)
{
}

QAbstractFormatter::QAbstractFormatter(QAbstractFormatterPrivate &dd, QObject *parent)
    : QObject(dd, parent)
{
}

void QAbstractFormatter::setFormats(QLogFormats newFormats)
{
    Q_D(QAbstractFormatter);

    d->m_formats = newFormats;
}

QLogFormats QAbstractFormatter::formats() const
{
    Q_D(const QAbstractFormatter);

    return d->m_formats;
}
