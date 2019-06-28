#include "formimageanalyzer.h"

FormImageAnalyzer::FormImageAnalyzer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//设置title
	setWindowTitle(QString::fromLocal8Bit("图像分析"));


	//控件配置初始化

	//成员变量配置初始化
	mScale = 1.0;
	image = new QImage;

	//自定义信号与槽函数链接初始化
	connect(ui.label_image, SIGNAL(MyLabelWheelSignal(int)), this, SLOT(MyLabelWheelSlot(int)));

	//第一次运行界面时的初始化
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
	//MyLabel *senderLabel = dynamic_cast<MyLabel*>(QObject::sender());//发送信号的MyLabel
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
	
	qDebug() << QStringLiteral("滚动缩放成功！");
}

void FormImageAnalyzer::loadImageOperate()
{
	if (image == nullptr)
	{
		image = new QImage;
	}
	//加载图片文件
	QString fileName = QFileDialog::getOpenFileName(this, QString(), QString(), "Images(*.png *.bmp *.jpg *.tif *.GIF)");
	if (fileName.isEmpty())
	{
		QMessageBox::information(this, QStringLiteral("取消选择"), QStringLiteral("取消图片选择"));
		return;
	}

	if (!(image->load(fileName))) //加载图像
	{
		QMessageBox::information(this, QStringLiteral("失败"), QStringLiteral("打开图像失败!"));
		return;
	}

	//显示图片
	
	ui.label_image->resize(image->size());
	ui.label_image->setPixmap(QPixmap::fromImage(*image));
}

void FormImageAnalyzer::openImage()
{
	loadImageOperate();
}