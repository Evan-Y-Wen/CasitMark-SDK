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
*函数功能：读取AppConfig.XML文件中的信息
*输入：
*	path:AppConfig.XML文件所在路径
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-24-V1.0
***************************************/
void AppConfig::readXMLElement(const QString &path)
{
	QDomDocument doc;
	QFile file(path);//打开或创建文件
	if (!file.open(QIODevice::ReadOnly))
		return;
	if (!doc.setContent(&file))
	{
		file.close();
		return;
	}
	file.close();

	QDomElement rootElem = doc.documentElement();//返回根节点元素
	QDomNode rootNode = rootElem.firstChild();//获得第一个子节点
	while (!rootNode.isNull())
	{
		QDomElement fileElem = rootNode.toElement(); //将QDomNode转换为QDomElement。如果节点不是元素，则返回的对象将为null。
		if (!fileElem.isNull())
		{
			// 图像文件名前缀
			if (fileElem.nodeName() == "ImageFilePrefix")//匹配某一个元素
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()返回此元素中包含的文本。
				ImageFilePrefix = fileElem.text();
			}
			// 图像文件类型0-jpg,1-bmp,2-png,3-tiff
			if (fileElem.nodeName() == "ImageFileType")//匹配某一个元素
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()返回此元素中包含的文本。
				ImageFileType = fileElem.text().toInt();
			}
			// 图像文件保存位置	
			if (fileElem.nodeName() == "ImageSaveFolder")//匹配某一个元素
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()返回此元素中包含的文本。
				ImageSaveFolder = fileElem.text();
			}
			// 可选择设备类型	
			if (fileElem.nodeName() == "CanSelectDevice")//匹配某一个元素
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()返回此元素中包含的文本。
				QVariant tempValue = fileElem.text();
				CanSelectDevice = tempValue.toBool();//转为booL
			}
			// 设备类型0-高速扫描仪；1-OCR阅读机；2-TWAIN；3-KVSL扫描仪	
			if (fileElem.nodeName() == "LastSelectedDevice")//匹配某一个元素
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()返回此元素中包含的文本。
				LastSelectedDevice = fileElem.text().toInt();
			}
			// 专用扫描仪扫描位置	
			if (fileElem.nodeName() == "ScanPosition")//匹配某一个元素
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()返回此元素中包含的文本。
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
			// 启用裁剪	
			if (fileElem.nodeName() == "IsRectify")//匹配某一个元素
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()返回此元素中包含的文本。
				QVariant tempValue = fileElem.text();
				IsRectify = tempValue.toBool();//转为booL
			}
			// 光源颜色	
			if (fileElem.nodeName() == "OCRLightColor")//匹配某一个元素
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()返回此元素中包含的文本。
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


			// 最近使用的模式文件
			if (fileElem.nodeName() == "RecentUsedPatternFiles")//匹配某一个元素
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()返回此元素中包含的文本。
				RecentUsedPatternFiles = fileElem.text();
			}
			// 表格图像识别线程时间间隔
			if (fileElem.nodeName() == "RecognizeElapse")//匹配某一个元素
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()返回此元素中包含的文本。
				RecognizeElapse = fileElem.text().toInt();
			}
			// 是否启用编辑结果限制
			if (fileElem.nodeName() == "IsEnableEditLimit")//匹配某一个元素
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()返回此元素中包含的文本。
				QVariant tempValue = fileElem.text();
				IsEnableEditLimit = tempValue.toBool();//转为booL
			}
			// 启用编辑的密码
			if (fileElem.nodeName() == "Password")//匹配某一个元素
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()返回此元素中包含的文本。
				Password = fileElem.text();
			}
			// 识别图像时二值化阈值
			if (fileElem.nodeName() == "BinarizeThreshold")//匹配某一个元素
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()返回此元素中包含的文本。
				BinarizeThreshold = fileElem.text().toInt();
			}
			// 被识别图像旋转90度
			if (fileElem.nodeName() == "ImageRotate90")//匹配某一个元素
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()返回此元素中包含的文本。
				QVariant tempValue = fileElem.text();
				ImageRotate90 = tempValue.toBool();//转为booL
			}
			// 自动抛弃扫描的白色图像
			if (fileElem.nodeName() == "IsAutoFilterWhite")//匹配某一个元素
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()返回此元素中包含的文本。
				QVariant tempValue = fileElem.text();
				IsAutoFilterWhite = tempValue.toBool();//转为booL
			}
			// 白色图像判定阈值
			if (fileElem.nodeName() == "BlackDotsCountInWhitePaper")//匹配某一个元素
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()返回此元素中包含的文本。
				BlackDotsCountInWhitePaper = fileElem.text().toInt();
			}
		}
		rootNode = rootNode.nextSibling();//下一个兄弟节点
	}
	return;
}


/***************************************
*函数功能：修改AppConfig.XML文件中的信息
*输入：
*	path:AppConfig.XML文件所在路径
*	ElementName:要修改的元素的名字
*	ElementValue:修改为该值
*输出：
*	void
*作者：JZQ
*时间版本：2019-05-29-V1.0
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

	QDomElement rootElem = doc.documentElement();//返回根节点元素
	QDomNode rootNode = rootElem.firstChild();//获得第一个子节点
	while (!rootNode.isNull())
	{
		QDomElement fileElem = rootNode.toElement();//将QDomNode转换为QDomElement。如果节点不是元素，则返回的对象将为null。
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
	if (!file.open(QFile::WriteOnly | QFile::Truncate))//Truncate:打开文件后,之前的内容将会消失(默认Truncate是打开的)
	{
		return;
	}
	QTextStream out(&file);
	out.setCodec("UTF-8");//这里，XML是UTF-8的格式。
	out << xml;
	file.close();
}
