#pragma once

#include <QDialog>
#include "ui_recognizeform.h"
#include "appconfig.h"
#include "cocer200scan.h"//获取阅读设备状态信息
#include "scansetting.h"//设置、获取阅读设备配置信息

#include <QFileDialog>
#include <QMessageBox>
#include <QStringList>
#include <QFileInfoList>
#include <QFileInfo>
#include <QFile>
#include <QDir>
#include <QDebug>

class RecognizeForm : public QDialog
{
	Q_OBJECT

public:
	RecognizeForm(QWidget *parent = Q_NULLPTR);
	~RecognizeForm();

private:
	Ui::RecognizeForm ui;


/***************************************
*定义：槽函数
*属性：公有
***************************************/
public slots:
	//第一页：专用设备
	void CheckBox_Rotate90_Click();
	void CheckBox_AutoFilterWhitePage_Click();
	void Button_RecognizeControl_Click();
	void OpenDevice();	// 阅读设备操作
	void StartScan();
	void StopScan();
	void CloseDeivce();
	void Setting();

	//第二页：图像文件
	void Button_OpenDirs_Click();
	void Button_OpenFiles_Click();

	// 阅读设备信号响应槽
	void OnDeviceInfoChanged(cs200::eDeviceInfo info);

	// 图像数据采集到响应槽，需在不使时主动释放内存空间
	void OnDeviceImageGenerated(uchar *fImgBuf, int fBufLen, uchar *bImgBuf, int bBufLen);

/***************************************
*定义：成员函数
*属性：公有
***************************************/
public:
	void setupRecognizeChildWindow(AppConfig *appConfig, QString *appExeFolder);

/***************************************
*定义：成员变量
*属性：私有
***************************************/
private:
	//下面的两个指针，并未在在该子窗口分配内存，是在主窗口分配的内存，在主窗口的析构函数中去释放。
	QString *_mAppExeFolder = nullptr;//程序运行目录
	AppConfig *_mAppConfig = nullptr;//XML文件配置读取
	QString _imageSaveFolder;//todo:我的程序中应该在formiamgeanalyzer里面保存图片
	QString _cfgFilePath;
	cs200::Cocer200Scan _dev;//Cocer200Scan里面定义了两个信号，所以它可以用作信号发送者。
};
