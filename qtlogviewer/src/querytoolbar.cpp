#include "querytoolbar.h"

#include <QToolButton>

QueryToolBar::QueryToolBar(QWidget *parent)
	: QToolBar(parent)
{
	m_levels = QLogger::All;

	m_offButton = new QToolButton(this);
	this->addWidget(m_offButton);
    m_offButton->setIcon(QIcon(":/level_off.png"));
	connect(m_offButton, SIGNAL(clicked()), this, SLOT(setLevelOff()));

	this->addSeparator();

	m_fatalButton = new QToolButton(this);
	m_fatalButton->setCheckable(true);
	m_fatalButton->setChecked(true);
	this->addWidget(m_fatalButton);
    m_fatalButton->setIcon(QIcon(":/level_fatal.png"));
	connect(m_fatalButton, SIGNAL(clicked()), this, SLOT(checkTest()));

	m_errorButton = new QToolButton(this);
	m_errorButton->setCheckable(true);
	m_errorButton->setChecked(true);
	this->addWidget(m_errorButton);
    m_errorButton->setIcon(QIcon(":/level_error.png"));
	connect(m_errorButton, SIGNAL(clicked()), this, SLOT(checkTest()));

	m_warnButton = new QToolButton(this);
	m_warnButton->setCheckable(true);
	m_warnButton->setChecked(true);
	this->addWidget(m_warnButton);
    m_warnButton->setIcon(QIcon(":/level_warn.png"));
	connect(m_warnButton, SIGNAL(clicked()), this, SLOT(checkTest()));

	m_infoButton = new QToolButton(this);
	m_infoButton->setCheckable(true);
	m_infoButton->setChecked(true);
	this->addWidget(m_infoButton);
    m_infoButton->setIcon(QIcon(":/level_info.png"));
	connect(m_infoButton, SIGNAL(clicked()), this, SLOT(checkTest()));

	m_debugButton = new QToolButton(this);
	m_debugButton->setCheckable(true);
	m_debugButton->setChecked(true);
	this->addWidget(m_debugButton);
    m_debugButton->setIcon(QIcon(":/level_debug.png"));
	connect(m_debugButton, SIGNAL(clicked()), this, SLOT(checkTest()));

	m_traceButton = new QToolButton(this);
	m_traceButton->setCheckable(true);
	m_traceButton->setChecked(true);
	this->addWidget(m_traceButton);
    m_traceButton->setIcon(QIcon(":/level_trace.png"));
	connect(m_traceButton, SIGNAL(clicked()), this, SLOT(checkTest()));

	this->addSeparator();

	m_allButton = new QToolButton(this);
	this->addWidget(m_allButton);
    m_allButton->setIcon(QIcon(":/level_all.png"));
	connect(m_allButton, SIGNAL(clicked()), this, SLOT(setLevelAll()));

	this->addSeparator();

	m_executeButton = new QToolButton(this);
	this->addWidget(m_executeButton);
    m_executeButton->setIcon(QIcon(":/execute.png"));
    connect(m_executeButton, SIGNAL(clicked()), this, SLOT(execute()));
}

QueryToolBar::~QueryToolBar()
{
}

void QueryToolBar::setLevelOff()
{
	m_fatalButton->setChecked(false);
	m_errorButton->setChecked(false);
	m_warnButton->setChecked(false);
	m_infoButton->setChecked(false);
	m_debugButton->setChecked(false);
	m_traceButton->setChecked(false);

	m_levels = QLogger::Off;
	m_executeButton->setEnabled(false);
}

void QueryToolBar::setLevelAll()
{
	m_fatalButton->setChecked(true);
	m_errorButton->setChecked(true);
	m_warnButton->setChecked(true);
	m_infoButton->setChecked(true);
	m_debugButton->setChecked(true);
	m_traceButton->setChecked(true);

	m_levels = QLogger::All;
	m_executeButton->setEnabled(true);
}

void QueryToolBar::checkTest()
{
	m_levels = QLogger::Off;

	if (m_fatalButton->isChecked())
		m_levels |= QLogger::Fatal;

	if (m_errorButton->isChecked())
		m_levels |= QLogger::Error;

	if (m_warnButton->isChecked())
		m_levels |= QLogger::Warn;

	if (m_infoButton->isChecked())
		m_levels |= QLogger::Info;

	if (m_debugButton->isChecked())
		m_levels |= QLogger::Debug;

	if (m_traceButton->isChecked())
		m_levels |= QLogger::Trace;

	m_executeButton->setEnabled(m_levels ? true: false);
}

void QueryToolBar::execute()
{
    emit requestChanged(m_levels);
}
