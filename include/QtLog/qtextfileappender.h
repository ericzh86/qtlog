#ifndef QTEXTFILEAPPENDER_H
#define QTEXTFILEAPPENDER_H

#include "qtlogglobal.h"
#include "qabstractappender.h"

#include <QObject>
class QTextFileAppenderPrivate;
class QTLOGSHARED_EXPORT QTextFileAppender : public QObject, public QAbstractAppender
{
	Q_OBJECT
	Q_INTERFACES(QAbstractAppender)

public:
	QTextFileAppender(QObject *parent = 0);
	QTextFileAppender(QString &fileName, QObject *parent = 0);

public:
	QString fileName() const;
public:
	void setFileName(const QString &fileName);

public:
	bool open();
public:
    void close();
public:
	bool isOpen() const;
private:
    void _write(QLogger *logger, QLogger::Level level, const QString &text);

private:
	Q_DISABLE_COPY(QTextFileAppender)
	Q_DECLARE_PRIVATE(QTextFileAppender)
};

#endif//QTEXTFILEAPPENDER_H
