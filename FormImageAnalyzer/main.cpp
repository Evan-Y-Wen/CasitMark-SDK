#include "formimageanalyzer.h"
#include <QtWidgets/QApplication>

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