#ifndef LOGITEMDELEGATE_H
#define LOGITEMDELEGATE_H

#include <QStyledItemDelegate>

class LogItemDelegate : public QStyledItemDelegate
{
public:
	LogItemDelegate(QObject *parent);
	~LogItemDelegate();

private:
	void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif//LOGITEMDELEGATE_H
