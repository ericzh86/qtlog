#ifndef QDBFILECONVERTOR_H
#define QDBFILECONVERTOR_H

#include <QSqlDatabase>

class QDBFileConvertor
{
public:
    static bool convert(QSqlDatabase &sqlite, QDataStream &reader);
};

#endif//QDBFILECONVERTOR_H
