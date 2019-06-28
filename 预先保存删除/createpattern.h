#pragma once

#include <QWidget>
#include "ui_createpattern.h"

class CreatePattern : public QWidget
{
	Q_OBJECT

public:
	CreatePattern(QWidget *parent = Q_NULLPTR);
	~CreatePattern();


public slots:
	void BTN_Submit_Click();
	void CB_Bihe_Click();
	void CB_QR_Click();

private:
	Ui::CreatePattern ui;

public:
	bool m_CreatePatternSuccessed = false;

};
