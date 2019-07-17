#include "formimageanalyzer.h"
#include <QtWidgets/QApplication>
#include <QZXing.h>
#include <QImage>
#include <QString>
#include <QDebug>

//��ͨ��������
//��ͨ��������
//��ͨ��������
void ChangeStyle();//����ϵͳ��ʽ��

int main(int argc, char *argv[])
{
	QApplication App(argc, argv);
	FormImageAnalyzer TheMainWindow;

	//����ϵͳ��ʽ��
	ChangeStyle();

	QImage imageToDecode("QRCode1-8.jpg");
	QZXing decoder;
	decoder.setDecoder(QZXing::DecoderFormat_QR_CODE | QZXing::DecoderFormat_EAN_13);
	QString result = decoder.decodeImage(imageToDecode);
	qDebug() << result;

	//��ʼִ��Ӧ�ó���
	TheMainWindow.show();

	return App.exec();
}

//����ϵͳ��ʽ��
void ChangeStyle()
{
	//todo:todo
/*
QFile styleFile(":/QssFile/Resources/style/blue.qss");
styleFile.open(QFile::ReadOnly);
QString setStyleSheet(styleFile.readAll());;
App.setStyleSheet(setStyleSheet);
styleFile.close();
*/
}