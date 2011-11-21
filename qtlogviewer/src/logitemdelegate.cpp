#include "logitemdelegate.h"

#include "./../QtLog/qlogger.h"

#include <QPainter>

LogItemDelegate::LogItemDelegate(QObject *parent)
	: QStyledItemDelegate(parent)
{
}

LogItemDelegate::~LogItemDelegate()
{
}

void LogItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	if (index.column() != 0) {
		QStyledItemDelegate::paint(painter, option, index);
		return;
	}

	QString text = index.model()->data(index).toString();

	QColor textColor = Qt::black;
	QColor backgroundColor = Qt::white;

	int level = index.model()->data(index).toInt();

	switch (level) {
		case QLogger::Fatal:
			{
                text = QObject::tr("Fatal");

				textColor = Qt::white;
				backgroundColor = QColor(105, 105, 105);
			}
			break;
		case QLogger::Error:
			{
                text = QObject::tr("Error");

				textColor = Qt::black;
				backgroundColor = QColor(255, 48, 48);
			}
			break;
		case QLogger::Warn:
			{
                text = QObject::tr("Warn");

				textColor = Qt::black;
				backgroundColor = QColor(255, 255, 0);
			}
			break;
		case QLogger::Info:
			{
                text = QObject::tr("Info");

				textColor = Qt::black;
				backgroundColor = QColor(151, 255, 255);
			}
			break;
		case QLogger::Debug:
			{
                text = QObject::tr("Debug");

				textColor = Qt::black;
				backgroundColor = QColor(245, 255, 250);
			}
			break;
		case QLogger::Trace:
			{
                text = QObject::tr("Trace");

				textColor = Qt::black;
				backgroundColor = QColor(245, 255, 250);
			}
			break;
	}

	painter->save();

	painter->fillRect(option.rect, backgroundColor);

    int borderWidth = 1;
    painter->setPen(textColor);
    painter->setFont(option.font);
    QRect textRect = option.rect.adjusted(borderWidth, borderWidth, -borderWidth, -borderWidth);

    painter->drawText(textRect, Qt::AlignCenter, text);

	painter->restore();
}
