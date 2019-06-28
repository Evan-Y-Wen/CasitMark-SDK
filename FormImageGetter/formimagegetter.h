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

//槽函数
//槽函数
//槽函数
public slots:
	void Button_SelectFolder_Click();//浏览按钮
	void Button_ScannerStart1_Click();//开始阅读按钮
	void Button_ScannerContinue1_Click();//继续阅读按钮
	void ComboBox_Position_SelectionChanged();
	void ComboBox_Light_SelectionChanged();
	void ComboBox_ImageType_SelectionChanged();

//成员变量
//成员变量
//成员变量
public:
	QString ImageType = ".jpg";// 图像文件名后缀
private:
	QString *appExeFolder = nullptr;//程序运行目录
	AppConfig *appConfig = nullptr;//XML文件配置读取
	
	int _imageCount = 0;// 已扫描图像数
	HighSpeedScanner *_highSpeedScanner1 = nullptr;// 高速扫描仪1
	int *_currentWindowHandle = nullptr;// 此窗体句柄
	//HwndSourceHook _hwndSourceHook = nullptr;// windows事件钩子

	bool _isUIInitial = true;
};
