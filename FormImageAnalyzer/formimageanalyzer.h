#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_formimageanalyzer.h"
#include "appconfig.h"
#include "excelreader.h"
#include "pixitem.h"
#include "mygraphicsview.h"
#include "recognizeform.h"
#include "MPattern.h"
#include "Cm3FormResult.h"

#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QDebug>

#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QTableView>
#include <QTextStream>
#include <QStringList>
#include <QVector>


class FormImageAnalyzer : public QMainWindow
{
	Q_OBJECT

public:
	FormImageAnalyzer(QWidget *parent = Q_NULLPTR);
	~FormImageAnalyzer();

private:
	Ui::FormImageAnalyzerClass ui;

/***************************************
*定义：槽函数
*属性：公有
***************************************/
public slots:
	//图像操作
	void OnButtonZoomIn();
	void OnButtonZoomOut();
	void OnButtonRecover();
	void OnButtonClockwiseRotate();
	void OnButtonNegativeRotate();

	//工具栏按钮
	void OnButtonOpenPatten();
	void OnButtonRecognize();
	void OnButtonReRecognize();
	void OnButtonAddData();
	void OnButtonSaveData();
	void OnButtonExcelResult();

	//其他
	void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

/***************************************
*定义：成员函数
*属性：公有
***************************************/
public:
	void setupModel();
	void setupView();

/***************************************
*定义：成员变量
*属性：私有
***************************************/
private:
	QString *appExeFolder = nullptr;//程序运行目录
	AppConfig *appConfig = nullptr;//XML文件配置读取
	ExcelReader *_mExcelReader = nullptr;//excel操作

	QPixmap *_mPixmap = nullptr;//原图
	PixItem *_mPixItem = nullptr;
	QGraphicsScene *_mGraphicsScene = nullptr;
	QStandardItemModel *_mModel = nullptr;
	int _mModelRow;
	int _mModelColumn;
	QItemSelectionModel *_mSelectionModel = nullptr;
	//Cm3::FormPattern::MPattern *_mCurrentPattern;

};