#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_formimageanalyzer.h"
#include "pixitem.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsView>
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
public slots:
	void OnButtonOpenPatten();
	void OnButtonZoomIn();
	void OnButtonZoomOut();
	void OnButtonRecover();
	void OnButtonClockwiseRotate();
	void OnButtonNegativeRotate();
	
//成员函数
public:
	void loadImageOperate();

//成员变量
private:
	//QString *appExeFolder = nullptr;//程序运行目录
	//AppConfig *appConfig = nullptr;//XML文件配置读取
	//static unsigned s_buildCount;//统计页码
	QPixmap *mPixmap = nullptr;//原图
	PixItem *mPixItem = nullptr;
	QGraphicsScene *mGraphicsScene = nullptr;

};