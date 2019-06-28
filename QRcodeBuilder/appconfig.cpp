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
*ʱ��汾��2019-06-11-V2.0
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
		// QDomNodeList list=e.childNodes();//��������ֱ���ӽڵ���б�,����Ҫ�ɱ����б�
		if (!fileElem.isNull())
		{
			//qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()���ش�Ԫ���а������ı���
			if (fileElem.nodeName() == "SimplecodeLen")//ƥ��ĳһ��Ԫ��
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()���ش�Ԫ���а������ı���
				SimplecodeLen = fileElem.text().toInt();//תΪint
			}
			if (fileElem.nodeName() == "SimplecodeWriteText")//ƥ��ĳһ��Ԫ��
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()���ش�Ԫ���а������ı���
				QVariant tempValue = fileElem.text();
				SimplecodeWriteText = tempValue.toBool();//תΪbooL
			}
			if (fileElem.nodeName() == "QRcodePixelSize")//ƥ��ĳһ��Ԫ��
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()���ش�Ԫ���а������ı���
				QRcodePixelSize = fileElem.text().toInt();//תΪint
			}
			if (fileElem.nodeName() == "SimpleCodePixelSizeLength")//ƥ��ĳһ��Ԫ��
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()���ش�Ԫ���а������ı���
				SimpleCodePixelSizeLength = fileElem.text().toInt();//תΪint
			}
			if (fileElem.nodeName() == "SimpleCodePixelSizeWidth")//ƥ��ĳһ��Ԫ��
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()���ش�Ԫ���а������ı���
				SimpleCodePixelSizeWidth = fileElem.text().toInt();//תΪint
			}
			if (fileElem.nodeName() == "CodePixelMargin")//ƥ��ĳһ��Ԫ��
			{
				qDebug() << fileElem.nodeName() << ":" << fileElem.text();//text()���ش�Ԫ���а������ı���
				CodePixelMargin = fileElem.text().toInt();//תΪint
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
*ʱ��汾��2019-05-28-V1.0
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


/***************************************
*�������ܣ���AppConfig.XML�ļ�������һ��������Ϣ
*���룺
*	path:AppConfig.XML�ļ�����·��
*	ElementName:����Ԫ�ص�����
*	ElementValue:����Ԫ�ص�ֵ
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-10-V1.0
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

	//����һ��һ���ӽڵ��Լ�Ԫ��
	QDomElement root = doc.documentElement();
	QDomElement book = doc.createElement(ElementName);
	QDomText text = doc.createTextNode(ElementValue);
	book.appendChild(text);
	root.appendChild(book);

	if (!file.open(QFile::WriteOnly | QFile::Truncate)) //�ȶ�����������д���������truncate�����ں���׷�����ݣ�����Ч��
		return;
	//������ļ�
	QTextStream out_stream(&file);
	doc.save(out_stream, 2); //����2��
}
