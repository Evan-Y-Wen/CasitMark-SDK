#include "appconfig.h"

AppConfig::AppConfig(QObject *parent)
	: QObject(parent)
{
}

AppConfig::AppConfig()
{
}

AppConfig::~AppConfig()
{
}

/***************************************
*�������ܣ���ȡAppConfig.XML�ļ��е���Ϣ
*���룺
*	path:AppConfig.XML�ļ�����·��
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-24-V1.0
***************************************/
void AppConfig::readXMLElement(const QString &path)
{
	QDomDocument doc;
	QFile file(path);//�򿪻򴴽��ļ�
	if (!file.open(QIODevice::ReadOnly))
		return;
	if (!doc.setContent(&file))
	{
		file.close();
		return;
	}
	file.close();

	QDomElement rootElem = doc.documentElement();//���ظ��ڵ�Ԫ��
	QDomNode rootNode = rootElem.firstChild();//��õ�һ���ӽڵ�
	while (!rootNode.isNull())
	{
		QDomElement fileElem = rootNode.toElement(); //��QDomNodeת��ΪQDomElement������ڵ㲻��Ԫ�أ��򷵻صĶ���Ϊnull��
		if (!fileElem.isNull())
		{
			// ͼ���ļ���ǰ׺
			if (fileElem.nodeName() == "ImageFilePrefix")//ƥ��ĳһ��Ԫ��
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()���ش�Ԫ���а������ı���
				ImageFilePrefix = fileElem.text();
			}
			// ͼ���ļ�����0-jpg,1-bmp,2-png,3-tiff
			if (fileElem.nodeName() == "ImageFileType")//ƥ��ĳһ��Ԫ��
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()���ش�Ԫ���а������ı���
				ImageFileType = fileElem.text().toInt();
			}
			// ͼ���ļ�����λ��	
			if (fileElem.nodeName() == "ImageSaveFolder")//ƥ��ĳһ��Ԫ��
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()���ش�Ԫ���а������ı���
				ImageSaveFolder = fileElem.text();
			}
			// ��ѡ���豸����	
			if (fileElem.nodeName() == "CanSelectDevice")//ƥ��ĳһ��Ԫ��
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()���ش�Ԫ���а������ı���
				QVariant tempValue = fileElem.text();
				CanSelectDevice = tempValue.toBool();//תΪbooL
			}
			// �豸����0-����ɨ���ǣ�1-OCR�Ķ�����2-TWAIN��3-KVSLɨ����	
			if (fileElem.nodeName() == "LastSelectedDevice")//ƥ��ĳһ��Ԫ��
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()���ش�Ԫ���а������ı���
				LastSelectedDevice = fileElem.text().toInt();
			}
			// ר��ɨ����ɨ��λ��	
			if (fileElem.nodeName() == "ScanPosition")//ƥ��ĳһ��Ԫ��
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()���ش�Ԫ���а������ı���
				if ("Upside" == fileElem.text())
				{
					ScanPosition = ScanPostion::Upside;
				}
				else if ("Downside" == fileElem.text())
				{
					ScanPosition = ScanPostion::Downside;
				}
				else
				{
					ScanPosition = ScanPostion::Bothside;
				}
			}
			// ���òü�	
			if (fileElem.nodeName() == "IsRectify")//ƥ��ĳһ��Ԫ��
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()���ش�Ԫ���а������ı���
				QVariant tempValue = fileElem.text();
				IsRectify = tempValue.toBool();//תΪbooL
			}
			// ��Դ��ɫ	
			if (fileElem.nodeName() == "OCRLightColor")//ƥ��ĳһ��Ԫ��
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()���ش�Ԫ���а������ı���
				if ("Red" == fileElem.text())
				{
					OCRLightColor = LightColor::Red;
				}
				else if ("Green" == fileElem.text())
				{
					OCRLightColor = LightColor::Green;
				}
				else if ("Blue" == fileElem.text())
				{
					OCRLightColor = LightColor::Blue;
				}
				else
				{
					OCRLightColor = LightColor::White;

				}
			}


			// ���ʹ�õ�ģʽ�ļ�
			if (fileElem.nodeName() == "RecentUsedPatternFiles")//ƥ��ĳһ��Ԫ��
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()���ش�Ԫ���а������ı���
				RecentUsedPatternFiles = fileElem.text();
			}
			// ���ͼ��ʶ���߳�ʱ����
			if (fileElem.nodeName() == "RecognizeElapse")//ƥ��ĳһ��Ԫ��
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()���ش�Ԫ���а������ı���
				RecognizeElapse = fileElem.text().toInt();
			}
			// �Ƿ����ñ༭�������
			if (fileElem.nodeName() == "IsEnableEditLimit")//ƥ��ĳһ��Ԫ��
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()���ش�Ԫ���а������ı���
				QVariant tempValue = fileElem.text();
				IsEnableEditLimit = tempValue.toBool();//תΪbooL
			}
			// ���ñ༭������
			if (fileElem.nodeName() == "Password")//ƥ��ĳһ��Ԫ��
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()���ش�Ԫ���а������ı���
				Password = fileElem.text();
			}
			// ʶ��ͼ��ʱ��ֵ����ֵ
			if (fileElem.nodeName() == "BinarizeThreshold")//ƥ��ĳһ��Ԫ��
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()���ش�Ԫ���а������ı���
				BinarizeThreshold = fileElem.text().toInt();
			}
			// ��ʶ��ͼ����ת90��
			if (fileElem.nodeName() == "ImageRotate90")//ƥ��ĳһ��Ԫ��
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()���ش�Ԫ���а������ı���
				QVariant tempValue = fileElem.text();
				ImageRotate90 = tempValue.toBool();//תΪbooL
			}
			// �Զ�����ɨ��İ�ɫͼ��
			if (fileElem.nodeName() == "IsAutoFilterWhite")//ƥ��ĳһ��Ԫ��
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()���ش�Ԫ���а������ı���
				QVariant tempValue = fileElem.text();
				IsAutoFilterWhite = tempValue.toBool();//תΪbooL
			}
			// ��ɫͼ���ж���ֵ
			if (fileElem.nodeName() == "BlackDotsCountInWhitePaper")//ƥ��ĳһ��Ԫ��
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()���ش�Ԫ���а������ı���
				BlackDotsCountInWhitePaper = fileElem.text().toInt();
			}
		}
		rootNode = rootNode.nextSibling();//��һ���ֵܽڵ�
	}
	return;
}


/***************************************
*�������ܣ��޸�AppConfig.XML�ļ��е���Ϣ
*���룺
*	path:AppConfig.XML�ļ�����·��
*	ElementName:Ҫ�޸ĵ�Ԫ�ص�����
*	ElementValue:�޸�Ϊ��ֵ
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-05-29-V1.0
***************************************/
void AppConfig::ChangeXMLElement(const QString &path, const QString &ElementName, const QString &ElementValue)
{
	QString name;
	QDomDocument doc;
	QFile file(path);
	if (!file.open(QIODevice::ReadOnly))
	{
		return;
	}
	if (!doc.setContent(&file))
	{
		file.close();
		return;
	}

	file.close();

	QDomElement rootElem = doc.documentElement();//���ظ��ڵ�Ԫ��
	QDomNode rootNode = rootElem.firstChild();//��õ�һ���ӽڵ�
	while (!rootNode.isNull())
	{
		QDomElement fileElem = rootNode.toElement();//��QDomNodeת��ΪQDomElement������ڵ㲻��Ԫ�أ��򷵻صĶ���Ϊnull��
		if (!fileElem.isNull())
		{
			name = fileElem.tagName();
			if (name == ElementName)
			{
				QDomElement newNode = doc.createElement(ElementName);
				QDomText text = doc.createTextNode(ElementValue);
				newNode.appendChild(text);
				rootElem.replaceChild(newNode, rootNode);
			}
		}
		rootNode = rootNode.nextSibling();
	}

	QString xml = doc.toString();
	if (!file.open(QFile::WriteOnly | QFile::Truncate))//Truncate:���ļ���,֮ǰ�����ݽ�����ʧ(Ĭ��Truncate�Ǵ򿪵�)
	{
		return;
	}
	QTextStream out(&file);
	out.setCodec("UTF-8");//���XML��UTF-8�ĸ�ʽ��
	out << xml;
	file.close();
}
