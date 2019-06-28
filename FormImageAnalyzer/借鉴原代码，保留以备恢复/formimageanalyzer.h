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


//�ۺ���
//�ۺ���
//�ۺ���
public slots:
	void openImage();
	void MyLabelWheelSlot(int delta);

//��Ա����
//��Ա����
//��Ա����
private:
	//QString *appExeFolder = nullptr;//��������Ŀ¼
	//AppConfig *appConfig = nullptr;//XML�ļ����ö�ȡ
	//static unsigned s_buildCount;//ͳ��ҳ��
	double mScale;
	QImage *image;//ԭͼ


//��Ա����
//��Ա����
//��Ա����
public:
	void loadImageOperate();



};
