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

//�ۺ���
public slots:
	void OnButtonOpenPatten();
	void OnButtonZoomIn();
	void OnButtonZoomOut();
	void OnButtonRecover();
	void OnButtonClockwiseRotate();
	void OnButtonNegativeRotate();
	
//��Ա����
public:
	void loadImageOperate();

//��Ա����
private:
	//QString *appExeFolder = nullptr;//��������Ŀ¼
	//AppConfig *appConfig = nullptr;//XML�ļ����ö�ȡ
	//static unsigned s_buildCount;//ͳ��ҳ��
	QPixmap *mPixmap = nullptr;//ԭͼ
	PixItem *mPixItem = nullptr;
	QGraphicsScene *mGraphicsScene = nullptr;

};