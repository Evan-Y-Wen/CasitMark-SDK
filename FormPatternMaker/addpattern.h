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

//�ۺ���
public slots:
	void BTN_AddPatternFromFile_Click();//ѡ��ͼ��
	void BTN_AddPatternFromDevice_Click();//��ȡͼ��
	void BTN_AddPatternFromWord_Click();//ѡ��word
	void BTN_AddPatternFromPDF_Click();//ѡ��pdf
	void BTN_Comfirm_Click();//��ɰ�ť
	void BTN_Left_Click();//������ת��ť
	void BTN_Right_Click();//������ת��ť

//��������
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
