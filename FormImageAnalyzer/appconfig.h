#pragma once

#include <QObject>
#include <QFile>   
#include <QtXml>
#include <QDomDocument> 
#include <QString>
#include <QVector>

// �豸����
enum ScannerType
{
	BSC3230,
	OCR
};
// ר��ɨ����ɨ��λ��	
enum ScanPostion
{
	Upside = 0,
	Downside,
	Bothside
};
// ��Դ��ɫ
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
*���壺��Ա����
*���ԣ�����
***************************************/
public:
	// ͼ���ļ���ǰ׺
	QString ImageFilePrefix = "ͼ��";

	// ͼ���ļ�����0-jpg,1-bmp,2-png,3-tiff
	int ImageFileType = 0;

	// ͼ���ļ�����λ��	
	QString ImageSaveFolder = "";

	// ��ѡ���豸����	
	bool CanSelectDevice = true;

	// �豸����: 0-����ɨ���ǣ�1-OCR�Ķ�����2-TWAIN��3-KVSLɨ����	
	int LastSelectedDevice = 0;

	// ר��ɨ����ɨ��λ��	
	ScanPostion ScanPosition = ScanPostion::Upside;

	// ���òü�	
	bool IsRectify = true;

	// ��Դ��ɫ	
	LightColor OCRLightColor = LightColor::White;

	// ���ʹ�õ�ģʽ�ļ�
	//QVector<QString> RecentUsedPatternFiles;
	QString RecentUsedPatternFiles;
	
	// ���ͼ��ʶ���߳�ʱ����
	int RecognizeElapse = 200;
	
	// �Ƿ����ñ༭�������
	bool IsEnableEditLimit = false;
	
	// ���ñ༭������
	QString Password = "123456";
	
	// ʶ��ͼ��ʱ��ֵ����ֵ
	int BinarizeThreshold = 0;
	
	// ��ʶ��ͼ����ת90��
	bool ImageRotate90 = false;
	
	// �Զ�����ɨ��İ�ɫͼ��
	bool IsAutoFilterWhite = true;
	
	// ��ɫͼ���ж���ֵ
	int BlackDotsCountInWhitePaper = 200;
	
	//// ʹ��ͬ������λʱ����Ϳ�����ţ���ֵ�Ŵ󣬸�ֵ��С
	//int MarkSizeBySyncW = -4;
	//int MarkSizeBySyncH = -4;
	//
	//// ʹ�þ��ο�λʱ����Ϳ�����ţ���ֵ�Ŵ󣬸�ֵ��С
	//int MarkSizeByLocalW = -4;
	//int MarkSizeByLocalH = -4;
	//
	//// ��Ϳ���Ƿ�ȫ���
	//bool IsMarkBlockFullFill = true;
	 
/***************************************
*���壺��Ա����
*���ԣ�����
***************************************/
public:
	void readXMLElement(const QString &path);
	void ChangeXMLElement(const QString &path, const QString &ElementName, const QString &ElementValue);


};
