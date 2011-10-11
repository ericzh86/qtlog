#ifndef QDBFILEAPPENDER_H
#define QDBFILEAPPENDER_H

#include "qtlogglobal.h"
#include "qabstractappender.h"

#include <QObject>
class QDBFileAppenderPrivate;
class QTLOGSHARED_EXPORT QDBFileAppender : public QObject, public QAbstractAppender
{
	Q_OBJECT
	Q_INTERFACES(QAbstractAppender)

public:
	QDBFileAppender(QObject *parent = 0);
	QDBFileAppender(QString &fileName, QObject *parent = 0);

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
	Q_DISABLE_COPY(QDBFileAppender)
	Q_DECLARE_PRIVATE(QDBFileAppender)
};

#endif//QDBFILEAPPENDER_H
