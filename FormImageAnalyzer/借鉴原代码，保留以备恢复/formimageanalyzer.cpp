#include "formimageanalyzer.h"

FormImageAnalyzer::FormImageAnalyzer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//����title
	setWindowTitle(QString::fromLocal8Bit("ͼ�����"));


	//�ؼ����ó�ʼ��

	//��Ա�������ó�ʼ��
	mScale = 1.0;
	image = new QImage;

	//�Զ����ź���ۺ������ӳ�ʼ��
	connect(ui.label_image, SIGNAL(MyLabelWheelSignal(int)), this, SLOT(MyLabelWheelSlot(int)));

	//��һ�����н���ʱ�ĳ�ʼ��
	loadImageOperate();
}

FormImageAnalyzer::~FormImageAnalyzer()
{
	if (image != nullptr)
	{
		delete image;
	}
	image = nullptr;
}

void FormImageAnalyzer::MyLabelWheelSlot(int delta)
{
	//MyLabel *senderLabel = dynamic_cast<MyLabel*>(QObject::sender());//�����źŵ�MyLabel
	const double diff = 0.1;
	const double rate = image->rect().height() / image->rect().width();
	QSize size = ui.label_image->size();
	int width = size.width();
	int height = size.height();
	if (delta > 0)
	{
		width = int(ui.label_image->width() + ui.label_image->width()*diff);
		height = int(ui.label_image->height() + ui.label_image->width()*diff*rate);
	}
	else
	{
		width = int(ui.label_image->width() - ui.label_image->width()*diff);
		height = int(ui.label_image->height() - ui.label_image->width()*diff*rate);
	}
	
	QImage imgScaled;
	imgScaled = image->scaled(width, height, Qt::KeepAspectRatio);
	//ui.label_image->resize(imgScaled.size());
	ui.label_image->setPixmap(QPixmap::fromImage(imgScaled));
	
	qDebug() << QStringLiteral("�������ųɹ���");
}

void FormImageAnalyzer::loadImageOperate()
{
	if (image == nullptr)
	{
		image = new QImage;
	}
	//����ͼƬ�ļ�
	QString fileName = QFileDialog::getOpenFileName(this, QString(), QString(), "Images(*.png *.bmp *.jpg *.tif *.GIF)");
	if (fileName.isEmpty())
	{
		QMessageBox::information(this, QStringLiteral("ȡ��ѡ��"), QStringLiteral("ȡ��ͼƬѡ��"));
		return;
	}

	if (!(image->load(fileName))) //����ͼ��
	{
		QMessageBox::information(this, QStringLiteral("ʧ��"), QStringLiteral("��ͼ��ʧ��!"));
		return;
	}

	//��ʾͼƬ
	
	ui.label_image->resize(image->size());
	ui.label_image->setPixmap(QPixmap::fromImage(*image));
}

void FormImageAnalyzer::openImage()
{
	loadImageOperate();
}