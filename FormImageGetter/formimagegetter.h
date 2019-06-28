#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_formimagegetter.h"
#include <QListView>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

#include "appconfig.h"
#include "HighSpeedScanner.h"

class FormImageGetter : public QMainWindow
{
	Q_OBJECT

public:
	FormImageGetter(QWidget *parent = Q_NULLPTR);

private:
	Ui::FormImageGetterClass ui;

//�ۺ���
//�ۺ���
//�ۺ���
public slots:
	void Button_SelectFolder_Click();//�����ť
	void Button_ScannerStart1_Click();//��ʼ�Ķ���ť
	void Button_ScannerContinue1_Click();//�����Ķ���ť
	void ComboBox_Position_SelectionChanged();
	void ComboBox_Light_SelectionChanged();
	void ComboBox_ImageType_SelectionChanged();

//��Ա����
//��Ա����
//��Ա����
public:
	QString ImageType = ".jpg";// ͼ���ļ�����׺
private:
	QString *appExeFolder = nullptr;//��������Ŀ¼
	AppConfig *appConfig = nullptr;//XML�ļ����ö�ȡ
	
	int _imageCount = 0;// ��ɨ��ͼ����
	HighSpeedScanner *_highSpeedScanner1 = nullptr;// ����ɨ����1
	int *_currentWindowHandle = nullptr;// �˴�����
	//HwndSourceHook _hwndSourceHook = nullptr;// windows�¼�����

	bool _isUIInitial = true;
};
