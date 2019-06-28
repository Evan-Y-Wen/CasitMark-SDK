#include "formimageanalyzer.h"

FormImageAnalyzer::FormImageAnalyzer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//����title
	setWindowTitle(QString::fromLocal8Bit("ͼ�����"));


	//��Ա�������ó�ʼ��
	_mPixmap = nullptr;
	_mPixItem = nullptr;
	_mGraphicsScene = nullptr;

	//�ؼ����ó�ʼ��

	//��һ�����н���ʱ�ĳ�ʼ��
	OnButtonOpenPatten();//����ͼƬ_mPixmap������ʼ��_mPixItem
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
	ui.graphicsView->setScale(ui.graphicsView->getScale() + 1);
	ui.graphicsView->centerOn(_mPixItem);
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
	ui.graphicsView->setScale(ui.graphicsView->getScale() - 1);
	ui.graphicsView->centerOn(_mPixItem);
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
	ui.graphicsView->setRotate(0);
	ui.graphicsView->setScale(0);
	ui.graphicsView->centerOn(_mPixItem);
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
	
	ui.graphicsView->setRotate(ui.graphicsView->getRotate() + 90);
	ui.graphicsView->centerOn(_mPixItem);
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
	ui.graphicsView->setRotate(ui.graphicsView->getRotate() - 90);
	ui.graphicsView->centerOn(_mPixItem);
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
	if (_mPixmap != nullptr)
	{
		delete _mPixmap;
		_mPixmap = nullptr;
	}
	_mPixmap = new QPixmap;
	//����ͼƬ�ļ�
	QString fileName = QFileDialog::getOpenFileName(this, QString(), QString(), "Images(*.png *.bmp *.jpg *.tif *.GIF)");
	if (fileName.isEmpty())
	{
		QMessageBox::information(this, QStringLiteral("ȡ��ѡ��"), QStringLiteral("ȡ��ͼƬѡ��"));
		return;
	}

	if (!(_mPixmap->load(fileName))) //����ͼ��
	{
		QMessageBox::information(this, QStringLiteral("ʧ��"), QStringLiteral("��ͼ��ʧ��!"));
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