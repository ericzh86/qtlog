#ifndef QUERYTOOLBAR_H
#define QUERYTOOLBAR_H

class QToolButton;

#include "../../include/QtLog/QtLog"

#include <QToolBar>

class QueryToolBar : public QToolBar
{
	Q_OBJECT

public:
	QueryToolBar(QWidget *parent);
	~QueryToolBar();

private:
	QToolButton *m_offButton;

	QToolButton *m_fatalButton;
	QToolButton *m_errorButton;
	QToolButton *m_warnButton;
	QToolButton *m_infoButton;
	QToolButton *m_debugButton;
	QToolButton *m_traceButton;

	QToolButton *m_allButton;

private:
	QToolButton *m_executeButton;

private slots:
	void setLevelOff();
	void setLevelAll();

private slots:
	void checkTest();

signals:
    void requestChanged(QLogLevels);
private:
    QLogLevels m_levels;
private slots:
	void execute();
};

#endif//QUERYTOOLBAR_H
