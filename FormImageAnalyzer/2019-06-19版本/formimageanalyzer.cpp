#include "formimageanalyzer.h"

FormImageAnalyzer::FormImageAnalyzer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//设置title
	setWindowTitle(QString::fromLocal8Bit("图像分析"));


	//成员变量配置初始化
	_mPixmap = nullptr;
	_mPixItem = nullptr;
	_mGraphicsScene = nullptr;

	//控件配置初始化

	//第一次运行界面时的初始化
	OnButtonOpenPatten();//载入图片_mPixmap，并初始化_mPixItem
}

FormImageAnalyzer::~FormImageAnalyzer()
{
	if (_mPixmap != nullptr)
	{
		delete _mPixmap;
	}
	if (_mPixItem != nullptr)
	{
		delete _mPixItem;
	}
	if (_mGraphicsScene != nullptr)
	{
		delete _mGraphicsScene;
	}
	_mPixmap = nullptr;
	_mPixItem = nullptr;
	_mGraphicsScene = nullptr;
}


/***************************************
*函数功能：放大按钮槽函数
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-13-V1.0
***************************************/
void FormImageAnalyzer::OnButtonZoomIn()
{
	ui.graphicsView->setScale(ui.graphicsView->getScale() + 1);
	ui.graphicsView->centerOn(_mPixItem);
}


/***************************************
*函数功能：缩小按钮槽函数
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-13-V1.0
***************************************/
void FormImageAnalyzer::OnButtonZoomOut()
{
	ui.graphicsView->setScale(ui.graphicsView->getScale() - 1);
	ui.graphicsView->centerOn(_mPixItem);
}


/***************************************
*函数功能：复原按钮槽函数
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-13-V1.0
***************************************/
void FormImageAnalyzer::OnButtonRecover()
{
	ui.graphicsView->setRotate(0);
	ui.graphicsView->setScale(0);
	ui.graphicsView->centerOn(_mPixItem);
}


/***************************************
*函数功能：顺时针旋转按钮槽函数
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-17-V1.0
***************************************/
void FormImageAnalyzer::OnButtonClockwiseRotate()
{
	
	ui.graphicsView->setRotate(ui.graphicsView->getRotate() + 90);
	ui.graphicsView->centerOn(_mPixItem);
}


/***************************************
*函数功能：逆时针旋转按钮槽函数
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-17-V1.0
***************************************/
void FormImageAnalyzer::OnButtonNegativeRotate()
{
	ui.graphicsView->setRotate(ui.graphicsView->getRotate() - 90);
	ui.graphicsView->centerOn(_mPixItem);
}


/***************************************
*函数功能：切换模式按钮槽函数，重新加载图片
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-13-V1.0
***************************************/
void FormImageAnalyzer::OnButtonOpenPatten()
{
	if (_mPixmap != nullptr)
	{
		delete _mPixmap;
		_mPixmap = nullptr;
	}
	_mPixmap = new QPixmap;
	//加载图片文件
	QString fileName = QFileDialog::getOpenFileName(this, QString(), QString(), "Images(*.png *.bmp *.jpg *.tif *.GIF)");
	if (fileName.isEmpty())
	{
		QMessageBox::information(this, QStringLiteral("取消选择"), QStringLiteral("取消图片选择"));
		return;
	}

	if (!(_mPixmap->load(fileName))) //加载图像
	{
		QMessageBox::information(this, QStringLiteral("失败"), QStringLiteral("打开图像失败!"));
		return;
	}

	if (_mPixItem != nullptr)
	{
		delete _mPixItem;
		_mPixItem = nullptr;
	}
	_mPixItem = new PixItem(_mPixmap);

	if (_mGraphicsScene != nullptr)
	{
		delete _mGraphicsScene;
		_mGraphicsScene = nullptr;
	}
	_mGraphicsScene = new QGraphicsScene;
	//_mGraphicsScene->setSceneRect(-200, -200, 400, 400);
	_mGraphicsScene->addItem(_mPixItem);
	ui.graphicsView->setScene(_mGraphicsScene);
}