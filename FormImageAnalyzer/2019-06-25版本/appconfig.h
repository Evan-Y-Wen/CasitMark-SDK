#pragma once

#include <QObject>
#include <QFile>   
#include <QtXml>
#include <QDomDocument> 
#include <QString>
#include <QVector>

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

/***************************************
*定义：成员变量
*属性：公有
***************************************/
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

	// 最近使用的模式文件
	//QVector<QString> RecentUsedPatternFiles;
	QString RecentUsedPatternFiles;
	
	// 表格图像识别线程时间间隔
	int RecognizeElapse = 200;
	
	// 是否启用编辑结果限制
	bool IsEnableEditLimit = false;
	
	// 启用编辑的密码
	QString Password = "123456";
	
	// 识别图像时二值化阈值
	int BinarizeThreshold = 0;
	
	// 被识别图像旋转90度
	bool ImageRotate90 = false;
	
	// 自动抛弃扫描的白色图像
	bool IsAutoFilterWhite = true;
	
	// 白色图像判定阈值
	int BlackDotsCountInWhitePaper = 200;
	
	//// 使用同步道定位时，填涂块缩放，正值放大，负值缩小
	//int MarkSizeBySyncW = -4;
	//int MarkSizeBySyncH = -4;
	//
	//// 使用矩形框定位时，填涂块缩放，正值放大，负值缩小
	//int MarkSizeByLocalW = -4;
	//int MarkSizeByLocalH = -4;
	//
	//// 填涂块是否全填充
	//bool IsMarkBlockFullFill = true;
	 
/***************************************
*定义：成员函数
*属性：公有
***************************************/
public:
	void readXMLElement(const QString &path);
	void ChangeXMLElement(const QString &path, const QString &ElementName, const QString &ElementValue);


};
