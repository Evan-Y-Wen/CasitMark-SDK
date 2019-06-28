#include "formimageanalyzer.h"

FormImageAnalyzer::FormImageAnalyzer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//设置title
	setWindowTitle(QString::fromLocal8Bit("图像分析"));


	//成员变量配置初始化
	mPixItem = nullptr;
	mGraphicsScene = nullptr;
	mGraphicsScene = nullptr;

	//控件配置初始化

	//第一次运行界面时的初始化
	loadImageOperate();//载入图片mPixmap，并初始化mPixItem
}

FormImageAnalyzer::~FormImageAnalyzer()
{
	if (mPixmap != nullptr)
	{
		delete mPixmap;
	}
	if (mPixItem != nullptr)
	{
		delete mPixItem;
	}
	if (mGraphicsScene != nullptr)
	{
		delete mGraphicsScene;
	}
	mPixmap = nullptr;
	mPixItem = nullptr;
	mGraphicsScene = nullptr;
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
	mPixItem->setScaleValue(mPixItem->getScaleValue() + 1);
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
	mPixItem->setScaleValue(mPixItem->getScaleValue() - 1);
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
	mPixItem->setZoomState(Enum_ZoomState::RESET);
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
	mPixItem->setRotationValue((mPixItem->getRotationValue() + 90));
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
	mPixItem->setRotationValue((mPixItem->getRotationValue() - 90));
}


/***************************************
*函数功能：加载图片
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-13-V1.0
***************************************/
void FormImageAnalyzer::loadImageOperate()
{
	if (mPixmap != nullptr)
	{
		delete mPixmap;
		mPixmap = nullptr;
	}
	mPixmap = new QPixmap;
	//加载图片文件
	QString fileName = QFileDialog::getOpenFileName(this, QString(), QString(), "Images(*.png *.bmp *.jpg *.tif *.GIF)");
	if (fileName.isEmpty())
	{
		QMessageBox::information(this, QStringLiteral("取消选择"), QStringLiteral("取消图片选择"));
		return;
	}

	if (!(mPixmap->load(fileName))) //加载图像
	{
		QMessageBox::information(this, QStringLiteral("失败"), QStringLiteral("打开图像失败!"));
		return;
	}

	if (mPixItem != nullptr)
	{
		delete mPixItem;
		mPixItem = nullptr;
	}
	mPixItem = new PixItem(mPixmap);

	if (mGraphicsScene != nullptr)
	{
		delete mGraphicsScene;
		mGraphicsScene = nullptr;
	}
	mGraphicsScene = new QGraphicsScene;
	//mGraphicsScene->setSceneRect(-200, -200, 400, 400);
	mGraphicsScene->addItem(mPixItem);
	ui.graphicsView->setScene(mGraphicsScene);
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
	loadImageOperate();
}