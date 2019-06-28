#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_formimageanalyzer.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QImage>
#include <QPixmap>
#include <QDebug>


class FormImageAnalyzer : public QMainWindow
{
	Q_OBJECT

public:
	FormImageAnalyzer(QWidget *parent = Q_NULLPTR);
	~FormImageAnalyzer();

private:
	Ui::FormImageAnalyzerClass ui;


//槽函数
//槽函数
//槽函数
public slots:
	void openImage();
	void MyLabelWheelSlot(int delta);

//成员变量
//成员变量
//成员变量
private:
	//QString *appExeFolder = nullptr;//程序运行目录
	//AppConfig *appConfig = nullptr;//XML文件配置读取
	//static unsigned s_buildCount;//统计页码
	double mScale;
	QImage *image;//原图


//成员函数
//成员函数
//成员函数
public:
	void loadImageOperate();



};
