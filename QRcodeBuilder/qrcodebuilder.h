#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qrcodebuilder.h"
#include <QImage>
#include <QFile>
#include <QBuffer>
#include <QDebug>
#include <QDir>
#include <QMessageBox>
#include <QClipboard>
#include "appconfig.h"
#include "mylabel.h"
#include "QrCode.hpp"//二维码

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class QRcodeBuilder : public QMainWindow
{
	Q_OBJECT

public:
	QRcodeBuilder(QWidget *parent = Q_NULLPTR);
	~QRcodeBuilder();

private:
	Ui::QRcodeBuilderClass ui;

	
//槽函数
//槽函数
//槽函数
public slots:
	void RadioButton_SimpleCode_Checked();//定位方式一
	void RadioButton_QRCode_Checked();//定位方式二
	void button_Copy_Click();//复制选中图像
	void button_Build_Click();//重新生成

	//MyLabel自定义控件的槽函数
	void on_MyLabel_clicked();

//成员变量
//成员变量
//成员变量
private:
	int simpleCodeOrQRCode;//判断生成简单码还是二维码，0--简单码，1--二维码，默认简单码
	QImage *oldSelectedImage = nullptr;//以前选择的图片
	QImage *cursorNowOn = nullptr;//新选择的图片
	QString *oldSelectLabelName = nullptr;//上一次选择的LabelName
	QString *newSelectLabelName = nullptr;//当前选择的LabelName
	QString *voteID = nullptr;//选票ID
	QString *appExeFolder = nullptr;//程序运行目录
	AppConfig *appConfig = nullptr;//XML文件配置读取
	static unsigned s_buildCount;//统计页码

//成员函数
//成员函数
//成员函数
public:
	QImage GenerateSimpleCodeImage();//产生一张简单码图片
	QImage GenerateQRCodeImage(const QString &data);//产生一张二维码图片
	void ShowCodeImage(const QImage &image, QLabel *imageLabel, bool writeText, const QString &text, QLabel *textLabel);
	void SaveCodeImageToFile(QImage &image, const QString &filePath, const QString & imageFormat);
	void CreateDirectory(const QString &filePath);
	bool DeleteDirectory(const QString &filePath);
	string QStringToStdstringWithLength(QString num, int length);
	

};
