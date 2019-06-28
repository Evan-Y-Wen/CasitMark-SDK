#pragma once

#include <QObject>
#include <QFile>   
#include <QtXml>
#include <QDomDocument> 
#include <QString>

class AppConfig : public QObject
{
	//Q_OBJECT

public:
	AppConfig(QObject *parent);
	AppConfig();
	~AppConfig();

//��Ա����
//��Ա����
//��Ա����
public:
	int SimplecodeLen = 5;// ��������
	bool SimplecodeWriteText = false;// �����Ƿ�д���ı�
	int QRcodePixelSize = 300;
	int SimpleCodePixelSizeLength = 240;
	int SimpleCodePixelSizeWidth = 40;
	int CodePixelMargin = 10;


//��Ա����
//��Ա����
//��Ա����
public:
	void readXMLElement(const QString &path);
	void ChangeXMLElement(const QString &path, const QString &ElementName, const QString &ElementValue);
	void insertXMLElement(const QString &path, const QString &ElementName, const QString &ElementValue);

};
