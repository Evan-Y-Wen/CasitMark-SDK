#include "formimageanalyzer.h"
#include <QtWidgets/QApplication>
#include <QZXing.h>
#include <QImage>
#include <QString>
#include <QDebug>

//普通函数声明
//普通函数声明
//普通函数声明
void ChangeStyle();//加载系统样式表单

int main(int argc, char *argv[])
{
	QApplication App(argc, argv);
	FormImageAnalyzer TheMainWindow;

	//加载系统样式表单
	ChangeStyle();

	QImage imageToDecode("QRCode1-8.jpg");
	QZXing decoder;
	decoder.setDecoder(QZXing::DecoderFormat_QR_CODE | QZXing::DecoderFormat_EAN_13);
	QString result = decoder.decodeImage(imageToDecode);
	qDebug() << result;

	//开始执行应用程序
	TheMainWindow.show();

	return App.exec();
}

//加载系统样式表单
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