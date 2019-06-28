#pragma once

#include <QDialog>
#include "ui_addpattern.h"

#include "formpatternmaker.h"
#include <QString>

#include <iostream>
#include <vector>
using namespace std;

class AddPattern : public QDialog
{
	Q_OBJECT

public:
	AddPattern(QWidget *parent = Q_NULLPTR);
	~AddPattern();

//槽函数
public slots:
	void BTN_AddPatternFromFile_Click();//选择图像
	void BTN_AddPatternFromDevice_Click();//获取图像
	void BTN_AddPatternFromWord_Click();//选择word
	void BTN_AddPatternFromPDF_Click();//选择pdf
	void BTN_Comfirm_Click();//完成按钮
	void BTN_Left_Click();//向左旋转按钮
	void BTN_Right_Click();//向右旋转按钮

//变量定义
public:
	list<Cm2::FormPattern::MFormPattern> *_HasCreatedFromPattern = new list<Cm2::FormPattern::MFormPattern>;
	bool m_AddFormPatternSuccessed = false;
	bool m_AddImage = false;
private:
	//private MemoryStream _imageMemoryStream = null;
	//private BitmapImage _showedBitmap = null;
	 int32_t m_insertFromPosition = -1;
	 int _threshold = -1;
	 list<QString> *_fileName = new list<QString>;
	 int readStatus = 0;
	
private:
	Ui::AddPattern ui;
};
