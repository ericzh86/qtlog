#ifndef QTEXTFILEAPPENDER_H
#define QTEXTFILEAPPENDER_H

#include "qtlogglobal.h"

#include "qabstractappender.h"

class QTextFileAppenderPrivate;
class QTLOGSHARED_EXPORT QTextFileAppender : public QAbstractAppender
{
	Q_OBJECT

public:
    QTextFileAppender(const QString &fileName, QObject *parent = 0);

private:
    void write(QAbstractLogger *logger, QLogLevel level, const QString &text);

private:
    Q_DISABLE_COPY(QTextFileAppender)
    Q_DECLARE_PRIVATE(QTextFileAppender)
};

#endif//QTEXTFILEAPPENDER_H
