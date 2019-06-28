#pragma once

#include <QObject>
#include <QFile>   
#include <QtXml>
#include <QDomDocument> 
#include <QString>

// 设备类型
enum ScannerType
{
	BSC3230,
	OCR
};
// 专用扫描仪扫描位置	
enum ScanPostion
{
	Upside = 0,
	Downside,
	Bothside
};
// 光源颜色
enum LightColor
{
	Red = 0,
	Green,
	Blue,
	White
};

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
	// 图像文件名前缀
	 QString ImageFilePrefix = "图像";

	// 图像文件类型0-jpg,1-bmp,2-png,3-tiff
	 int ImageFileType = 0;
	
	// 图像文件保存位置	
	 QString ImageSaveFolder = "";
	
	// 可选择设备类型	
	 bool CanSelectDevice = true;
	
	// 设备类型: 0-高速扫描仪；1-OCR阅读机；2-TWAIN；3-KVSL扫描仪	
	 int LastSelectedDevice = 0;
	
	// 专用扫描仪扫描位置	
	 ScanPostion ScanPosition = ScanPostion::Upside;
	
	// 启用裁剪	
	 bool IsRectify = true;
	
	// 光源颜色	
	 LightColor OCRLightColor = LightColor::White;
	 
//成员函数
//成员函数
//成员函数
public:
	void readXMLElement(const QString &path);
	void ChangeXMLElement(const QString &path, const QString &ElementName, const QString &ElementValue);


};
