#include <QtCore/QCoreApplication>

#include "qrootlogger.h"
#include "qobjectlogger.h"

#include "qsqliteappender.h"
#include "qconsoleappender.h"
#include "qtextfileappender.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QtLog::rootLogger()->addAppender(new QConsoleAppender(&a));
    QtLog::rootLogger()->debug("´òÓ¡ÖĞÎÄ");

    return a.exec();
}
