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
*时间版本：2019-06-11-V2.0
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
		// QDomNodeList list=e.childNodes();//返回所有直接子节点的列表,如需要可遍历列表
		if (!fileElem.isNull())
		{
			//qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()返回此元素中包含的文本。
			if (fileElem.nodeName() == "SimplecodeLen")//匹配某一个元素
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()返回此元素中包含的文本。
				SimplecodeLen = fileElem.text().toInt();//转为int
			}
			if (fileElem.nodeName() == "SimplecodeWriteText")//匹配某一个元素
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()返回此元素中包含的文本。
				QVariant tempValue = fileElem.text();
				SimplecodeWriteText = tempValue.toBool();//转为booL
			}
			if (fileElem.nodeName() == "QRcodePixelSize")//匹配某一个元素
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()返回此元素中包含的文本。
				QRcodePixelSize = fileElem.text().toInt();//转为int
			}
			if (fileElem.nodeName() == "SimpleCodePixelSizeLength")//匹配某一个元素
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()返回此元素中包含的文本。
				SimpleCodePixelSizeLength = fileElem.text().toInt();//转为int
			}
			if (fileElem.nodeName() == "SimpleCodePixelSizeWidth")//匹配某一个元素
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()返回此元素中包含的文本。
				SimpleCodePixelSizeWidth = fileElem.text().toInt();//转为int
			}
			if (fileElem.nodeName() == "CodePixelMargin")//匹配某一个元素
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()返回此元素中包含的文本。
				CodePixelMargin = fileElem.text().toInt();//转为int
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
*时间版本：2019-05-28-V1.0
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


/***************************************
*函数功能：向AppConfig.XML文件中新增一条配置信息
*输入：
*	path:AppConfig.XML文件所在路径
*	ElementName:新增元素的名字
*	ElementValue:新增元素的值
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-10-V1.0
***************************************/
void AppConfig::insertXMLElement(const QString & path, const QString &ElementName, const QString &ElementValue)
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

	//增加一个一级子节点以及元素
	QDomElement root = doc.documentElement();
	QDomElement book = doc.createElement(ElementName);
	QDomText text = doc.createTextNode(ElementValue);
	book.appendChild(text);
	root.appendChild(book);

	if (!file.open(QFile::WriteOnly | QFile::Truncate)) //先读进来，再重写，如果不用truncate就是在后面追加内容，就无效了
		return;
	//输出到文件
	QTextStream out_stream(&file);
	doc.save(out_stream, 2); //缩进2格
}
