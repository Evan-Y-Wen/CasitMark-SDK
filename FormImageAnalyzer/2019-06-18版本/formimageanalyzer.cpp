#include "formimageanalyzer.h"

FormImageAnalyzer::FormImageAnalyzer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//����title
	setWindowTitle(QString::fromLocal8Bit("ͼ�����"));


	//��Ա�������ó�ʼ��
	mPixItem = nullptr;
	mGraphicsScene = nullptr;
	mGraphicsScene = nullptr;

	//�ؼ����ó�ʼ��

	//��һ�����н���ʱ�ĳ�ʼ��
	loadImageOperate();//����ͼƬmPixmap������ʼ��mPixItem
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
*�������ܣ��Ŵ�ť�ۺ���
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-13-V1.0
***************************************/
void FormImageAnalyzer::OnButtonZoomIn()
{
	mPixItem->setScaleValue(mPixItem->getScaleValue() + 1);
}


/***************************************
*�������ܣ���С��ť�ۺ���
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-13-V1.0
***************************************/
void FormImageAnalyzer::OnButtonZoomOut()
{
	mPixItem->setScaleValue(mPixItem->getScaleValue() - 1);
}


/***************************************
*�������ܣ���ԭ��ť�ۺ���
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-13-V1.0
***************************************/
void FormImageAnalyzer::OnButtonRecover()
{
	mPixItem->setZoomState(Enum_ZoomState::RESET);
}


/***************************************
*�������ܣ�˳ʱ����ת��ť�ۺ���
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-17-V1.0
***************************************/
void FormImageAnalyzer::OnButtonClockwiseRotate()
{
	mPixItem->setRotationValue((mPixItem->getRotationValue() + 90));
}


/***************************************
*�������ܣ���ʱ����ת��ť�ۺ���
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-17-V1.0
***************************************/
void FormImageAnalyzer::OnButtonNegativeRotate()
{
	mPixItem->setRotationValue((mPixItem->getRotationValue() - 90));
}


/***************************************
*�������ܣ�����ͼƬ
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-13-V1.0
***************************************/
void FormImageAnalyzer::loadImageOperate()
{
	if (mPixmap != nullptr)
	{
		delete mPixmap;
		mPixmap = nullptr;
	}
	mPixmap = new QPixmap;
	//����ͼƬ�ļ�
	QString fileName = QFileDialog::getOpenFileName(this, QString(), QString(), "Images(*.png *.bmp *.jpg *.tif *.GIF)");
	if (fileName.isEmpty())
	{
		QMessageBox::information(this, QStringLiteral("ȡ��ѡ��"), QStringLiteral("ȡ��ͼƬѡ��"));
		return;
	}

	if (!(mPixmap->load(fileName))) //����ͼ��
	{
		QMessageBox::information(this, QStringLiteral("ʧ��"), QStringLiteral("��ͼ��ʧ��!"));
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
*�������ܣ��л�ģʽ��ť�ۺ��������¼���ͼƬ
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-13-V1.0
***************************************/
void FormImageAnalyzer::OnButtonOpenPatten()
{
	loadImageOperate();
}