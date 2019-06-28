#include "formimageanalyzer.h"

FormImageAnalyzer::FormImageAnalyzer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//����title
	setWindowTitle(QString::fromLocal8Bit("ͼ�����"));
	//���ô��ڳ�ʼ��״̬
	setWindowState(Qt::WindowMaximized);


	//��Ա�������ó�ʼ��
	appExeFolder = new QString(QCoreApplication::applicationDirPath());//"G:\Qt\Qt5.12.1\User\CasitMark SDK\x64\Debug"
	appConfig = new AppConfig;//XML�ļ����ö�ȡ
	appConfig->readXMLElement((*appExeFolder) + "/AppConfig.xml");//����֤���ܶ������Ҵ���appConfig�Ĺ��г�Ա�����
	_mPixmap = nullptr;
	_mPixItem = nullptr;
	_mGraphicsScene = nullptr;
	_mModel = nullptr;
	_mModelRow = 0;
	_mModelColumn = 0;
	_mSelectionModel = nullptr;

	//�ؼ����ó�ʼ��


	//��һ�����н���ʱ�ĳ�ʼ��
	OnButtonOpenPatten();//����ͼƬ_mPixmap������ʼ��_mPixItem

}

FormImageAnalyzer::~FormImageAnalyzer()
{
	if (appExeFolder != nullptr)
	{
		delete appExeFolder;
	}
	if (appConfig != nullptr)
	{
		delete appConfig;
	}
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
	if (_mModel != nullptr)
	{
		delete _mModel;
	}
	if (_mSelectionModel != nullptr)
	{
		delete _mSelectionModel;
	}
	appExeFolder = nullptr;
	appConfig = nullptr;
	_mPixmap = nullptr;
	_mPixItem = nullptr;
	_mGraphicsScene = nullptr;
	_mModel = nullptr;
	_mModelRow = 0;
	_mModelColumn = 0;
	_mSelectionModel = nullptr;
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
	ui.graphicsView->stateRecover();
	ui.graphicsView->centerOn(_mPixItem);
	_mPixItem->setScale(1);
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
	//����ͼƬ�ļ�  todo:�޸�ѡ����ļ���ʽ
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

	if (_mModel != nullptr)
	{
		delete _mModel;
	}
	_mModel = nullptr;
	_mModelRow = 0;
	_mModelColumn = 0;

	if (_mSelectionModel != nullptr)
	{
		delete _mSelectionModel;
	}
	_mSelectionModel = nullptr;

	OnButtonRecover();
}


/***************************************
*�������ܣ�ʶ����ť�ۺ���
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-24-V1.0
***************************************/
void FormImageAnalyzer::OnButtonRecognize()
{
	RecognizeForm RecognizeChildWindow;
	RecognizeChildWindow.setupRecognizeChildWindow(appConfig, appExeFolder);//���XML�ļ����ö�ȡ
	RecognizeChildWindow.exec();
}


/***************************************
*�������ܣ�������ݰ�ť�ۺ���
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-13-V1.0
***************************************/
void FormImageAnalyzer::OnButtonAddData()
{//todo:�޸�ѡ����ļ���ʽ
	QString fileName = QFileDialog::getOpenFileName(this, QString(), QString(), "Data Files(*.txt *.crst)");
	if (fileName.isEmpty())
	{
		QMessageBox::information(this, QStringLiteral("ȡ��ѡ��"), QStringLiteral("ȡ�������ļ�ѡ��"));
		return;
	}

	QVector<QStringList> FileContent;//�����ļ��������
	QFile file(fileName);
	if (file.open(QFile::ReadOnly))
	{
		QTextStream stream(&file);
		QString line;

		int row = 0;
		int column = 0;
		do
		{
			line = stream.readLine();
			if (!line.isEmpty())
			{
				FileContent.push_back(line.split(",", QString::SkipEmptyParts)); //QVector�Ĵ�С��Ϊ�ж�����
				column = (FileContent[row]).size();
				if (_mModelColumn < column)
				{
					_mModelColumn = column;//ȡ����������
				}
				row++;
				_mModelRow = row;//ȡ������
			}
		} while (!line.isEmpty());
		file.close();
	}

	setupModel();//�½�ģʽ
	setupView();//�½���ͼ

	if (FileContent.isEmpty())
	{
		QMessageBox::information(this, QStringLiteral("�ļ�"), QStringLiteral("�ļ�Ϊ�գ�"));
		return;
	}
	//��ģʽ���������
	_mModel->removeRows(0, _mModel->rowCount(QModelIndex()), QModelIndex());//ɾ�����е��У���ֹ�հ׵��У�
	for (unsigned iRow = 0; iRow < _mModelRow; ++iRow)
	{
		_mModel->insertRows(iRow, 1, QModelIndex());
		for (unsigned iColumn = 0; iColumn < _mModelColumn; ++iColumn)
		{
			_mModel->setData(_mModel->index(iRow, iColumn, QModelIndex()), FileContent[iRow].value(iColumn));
		}
	}

	ui.groupBox_ListTitle->setTitle(QStringLiteral("��ʶ��������") + QString::number(_mModelRow) + QStringLiteral("��"));
}


/***************************************
*�������ܣ���ͼ��ѡ����ı�ۺ��������غ��������ƹ̶���
*���룺
*	selected����ѡ����
*	deselected����ѡ����
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-21-V1.0
***************************************/
void FormImageAnalyzer::selectionChanged(const QItemSelection & selected, const QItemSelection & deselected)
{
	if (selected.isEmpty())
	{
		return;
	}

	qreal ScaleValue = 1.5;//todo:�޸�����
	int MoveValue = 0;
	int Steep = 200;//�ƶ��ĵ�Ԫ����

	if (deselected.isEmpty())
	{
		//qDebug() << "first selected.indexes()[0].column() = " << selected.indexes()[0].column();
		//ui.graphicsView->setScale(ui.graphicsView->getScale() + 5);
		MoveValue = (-Steep) * selected.indexes()[0].column();
	}
	else
	{
		//qDebug() << "selected.indexes()[0].column() = " << selected.indexes()[0].column();
		//qDebug() << "deselected.indexes()[0].column() = " << deselected.indexes()[0].column();
		if (selected.indexes()[0].column() > deselected.indexes()[0].column())
		{
			MoveValue = (-Steep) * (selected.indexes()[0].column() - deselected.indexes()[0].column());
		}
		else if (selected.indexes()[0].column() < deselected.indexes()[0].column())
		{
			MoveValue = (-Steep) * (selected.indexes()[0].column() - deselected.indexes()[0].column());
		}
		else
		{
			MoveValue = 0;
		}
	}
	_mPixItem->setScale(ScaleValue);
	_mPixItem->moveBy(0, MoveValue);
	//_mPixItem->setPos(0, 0);
}


/***************************************
*�������ܣ�����һ��ģʽ
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-21-V1.0
***************************************/
void FormImageAnalyzer::setupModel()
{
	_mModel = new QStandardItemModel(_mModelRow, _mModelColumn, this);
	for (unsigned iColumn = 0; iColumn < _mModelColumn; ++iColumn)
	{
		_mModel->setHeaderData(iColumn, Qt::Horizontal, QStringLiteral("����-") + QString::number(iColumn + 1));
	}
}


/***************************************
*�������ܣ�������ı����ͼ�������ģʽ��ѡ��ģʽ
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-21-V1.0
***************************************/
void FormImageAnalyzer::setupView()
{
	ui.tableView->setModel(_mModel);
	//QItemSelectionModel *selectionModel = new QItemSelectionModel(_mModel);
	//_mSelectionModel = selectionModel;
	//ui.tableView->setSelectionModel(_mSelectionModel);
	_mSelectionModel = ui.tableView->selectionModel();//�����ͼ�ϵ�ѡ����
	_mPixItem->setSelectionModel(_mSelectionModel);//��ͼԪ�л����ͼ�ϵ�ѡ����
	connect(_mSelectionModel, SIGNAL(selectionChanged(QItemSelection, QItemSelection)), this, SLOT(selectionChanged(QItemSelection, QItemSelection)));
}