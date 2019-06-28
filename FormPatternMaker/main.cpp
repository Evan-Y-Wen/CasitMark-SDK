#include "formpatternmaker.h"
//#include "GlobalDefinitions.h"
#include <QtWidgets/QApplication>
#include <QString>
#include <QDebug>

//普通函数声明区：
//普通函数声明区：
//普通函数声明区：
void ChangeStyle();//加载系统样式表单

int main(int argc, char *argv[])
{
	QApplication App(argc, argv);

	//获取当前运行应用程序的所在目录
	QString AppExeFolder = QCoreApplication::applicationDirPath();
	qDebug() << AppExeFolder;  //到Debug就对了："G:/Qt/Qt5.12.1/User/FormPatternMaker/x64/Debug"

	//加载系统样式表单
	ChangeStyle();

	//开始执行应用程序
	FormPatternMaker TheMainWindow;
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
