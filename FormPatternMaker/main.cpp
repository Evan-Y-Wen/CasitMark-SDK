#include "formpatternmaker.h"
//#include "GlobalDefinitions.h"
#include <QtWidgets/QApplication>
#include <QString>
#include <QDebug>

//��ͨ������������
//��ͨ������������
//��ͨ������������
void ChangeStyle();//����ϵͳ��ʽ��

int main(int argc, char *argv[])
{
	QApplication App(argc, argv);

	//��ȡ��ǰ����Ӧ�ó��������Ŀ¼
	QString AppExeFolder = QCoreApplication::applicationDirPath();
	qDebug() << AppExeFolder;  //��Debug�Ͷ��ˣ�"G:/Qt/Qt5.12.1/User/FormPatternMaker/x64/Debug"

	//����ϵͳ��ʽ��
	ChangeStyle();

	//��ʼִ��Ӧ�ó���
	FormPatternMaker TheMainWindow;
	TheMainWindow.show();
	return App.exec();
}

//����ϵͳ��ʽ��
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
