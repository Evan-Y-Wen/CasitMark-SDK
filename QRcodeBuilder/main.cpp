#include "qrcodebuilder.h"
#include <QtWidgets/QApplication>
#include <QDebug>

//普通函数声明
//普通函数声明
//普通函数声明
void ChangeStyle();//加载系统样式表单

int main(int argc, char *argv[])
{
	QApplication App(argc, argv);
	QRcodeBuilder TheMainWindow;

	//加载系统样式表单
	ChangeStyle();

	//开始执行应用程序
	TheMainWindow.show();
	return App.exec();
}

//加载系统样式表单
void ChangeStyle()
{
	/*
QFile styleFile(":/QssFile/Resources/style/blue.qss");
styleFile.open(QFile::ReadOnly);
QString setStyleSheet(styleFile.readAll());;
App.setStyleSheet(setStyleSheet);
styleFile.close();
*/
}