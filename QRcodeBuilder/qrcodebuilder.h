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
#include "QrCode.hpp"//��ά��

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

	
//�ۺ���
//�ۺ���
//�ۺ���
public slots:
	void RadioButton_SimpleCode_Checked();//��λ��ʽһ
	void RadioButton_QRCode_Checked();//��λ��ʽ��
	void button_Copy_Click();//����ѡ��ͼ��
	void button_Build_Click();//��������

	//MyLabel�Զ���ؼ��Ĳۺ���
	void on_MyLabel_clicked();

//��Ա����
//��Ա����
//��Ա����
private:
	int simpleCodeOrQRCode;//�ж����ɼ��뻹�Ƕ�ά�룬0--���룬1--��ά�룬Ĭ�ϼ���
	QImage *oldSelectedImage = nullptr;//��ǰѡ���ͼƬ
	QImage *cursorNowOn = nullptr;//��ѡ���ͼƬ
	QString *oldSelectLabelName = nullptr;//��һ��ѡ���LabelName
	QString *newSelectLabelName = nullptr;//��ǰѡ���LabelName
	QString *voteID = nullptr;//ѡƱID
	QString *appExeFolder = nullptr;//��������Ŀ¼
	AppConfig *appConfig = nullptr;//XML�ļ����ö�ȡ
	static unsigned s_buildCount;//ͳ��ҳ��

//��Ա����
//��Ա����
//��Ա����
public:
	QImage GenerateSimpleCodeImage();//����һ�ż���ͼƬ
	QImage GenerateQRCodeImage(const QString &data);//����һ�Ŷ�ά��ͼƬ
	void ShowCodeImage(const QImage &image, QLabel *imageLabel, bool writeText, const QString &text, QLabel *textLabel);
	void SaveCodeImageToFile(QImage &image, const QString &filePath, const QString & imageFormat);
	void CreateDirectory(const QString &filePath);
	bool DeleteDirectory(const QString &filePath);
	string QStringToStdstringWithLength(QString num, int length);
	

};
