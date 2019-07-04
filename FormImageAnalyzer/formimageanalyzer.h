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
*���壺�ۺ���
*���ԣ�����
***************************************/
public slots:
	//ͼ�����
	void OnButtonZoomIn();
	void OnButtonZoomOut();
	void OnButtonRecover();
	void OnButtonClockwiseRotate();
	void OnButtonNegativeRotate();

	//��������ť
	void OnButtonOpenPatten();
	void OnButtonRecognize();
	void OnButtonReRecognize();
	void OnButtonAddData();
	void OnButtonSaveData();
	void OnButtonExcelResult();

	//����
	void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

/***************************************
*���壺��Ա����
*���ԣ�����
***************************************/
public:
	void setupModel();
	void setupView();

/***************************************
*���壺��Ա����
*���ԣ�˽��
***************************************/
private:
	QString *appExeFolder = nullptr;//��������Ŀ¼
	AppConfig *appConfig = nullptr;//XML�ļ����ö�ȡ
	ExcelReader *_mExcelReader = nullptr;//excel����

	QPixmap *_mPixmap = nullptr;//ԭͼ
	PixItem *_mPixItem = nullptr;
	QGraphicsScene *_mGraphicsScene = nullptr;
	QStandardItemModel *_mModel = nullptr;
	int _mModelRow;
	int _mModelColumn;
	QItemSelectionModel *_mSelectionModel = nullptr;
	//Cm3::FormPattern::MPattern *_mCurrentPattern;

};