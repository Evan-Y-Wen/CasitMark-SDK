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

//成员变量
//成员变量
//成员变量
public:
	int SimplecodeLen = 5;// 简单码列数
	bool SimplecodeWriteText = false;// 简单码是否写入文本
	int QRcodePixelSize = 300;
	int SimpleCodePixelSizeLength = 240;
	int SimpleCodePixelSizeWidth = 40;
	int CodePixelMargin = 10;


//成员函数
//成员函数
//成员函数
public:
	void readXMLElement(const QString &path);
	void ChangeXMLElement(const QString &path, const QString &ElementName, const QString &ElementValue);
	void insertXMLElement(const QString &path, const QString &ElementName, const QString &ElementValue);

};
