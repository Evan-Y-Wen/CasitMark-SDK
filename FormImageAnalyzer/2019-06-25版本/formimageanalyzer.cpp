#include "formimageanalyzer.h"

FormImageAnalyzer::FormImageAnalyzer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//设置title
	setWindowTitle(QString::fromLocal8Bit("图像分析"));
	//设置窗口初始化状态
	setWindowState(Qt::WindowMaximized);


	//成员变量配置初始化
	appExeFolder = new QString(QCoreApplication::applicationDirPath());//"G:\Qt\Qt5.12.1\User\CasitMark SDK\x64\Debug"
	appConfig = new AppConfig;//XML文件配置读取
	appConfig->readXMLElement((*appExeFolder) + "/AppConfig.xml");//已验证，能读出，且存在appConfig的公有成员变量里。
	_mPixmap = nullptr;
	_mPixItem = nullptr;
	_mGraphicsScene = nullptr;
	_mModel = nullptr;
	_mModelRow = 0;
	_mModelColumn = 0;
	_mSelectionModel = nullptr;

	//控件配置初始化


	//第一次运行界面时的初始化
	OnButtonOpenPatten();//载入图片_mPixmap，并初始化_mPixItem

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
	ui.graphicsView->stateRecover();
	ui.graphicsView->centerOn(_mPixItem);
	_mPixItem->setScale(1);
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
	//加载图片文件  todo:修改选择的文件格式
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
*函数功能：识别表格按钮槽函数
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-24-V1.0
***************************************/
void FormImageAnalyzer::OnButtonRecognize()
{
	RecognizeForm RecognizeChildWindow;
	RecognizeChildWindow.setupRecognizeChildWindow(appConfig, appExeFolder);//获得XML文件配置读取
	RecognizeChildWindow.exec();
}


/***************************************
*函数功能：添加数据按钮槽函数
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-13-V1.0
***************************************/
void FormImageAnalyzer::OnButtonAddData()
{//todo:修改选择的文件格式
	QString fileName = QFileDialog::getOpenFileName(this, QString(), QString(), "Data Files(*.txt *.crst)");
	if (fileName.isEmpty())
	{
		QMessageBox::information(this, QStringLiteral("取消选择"), QStringLiteral("取消数据文件选择"));
		return;
	}

	QVector<QStringList> FileContent;//保存文件里的内容
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
				FileContent.push_back(line.split(",", QString::SkipEmptyParts)); //QVector的大小即为有多少列
				column = (FileContent[row]).size();
				if (_mModelColumn < column)
				{
					_mModelColumn = column;//取得最大的列数
				}
				row++;
				_mModelRow = row;//取得行数
			}
		} while (!line.isEmpty());
		file.close();
	}

	setupModel();//新建模式
	setupView();//新建视图

	if (FileContent.isEmpty())
	{
		QMessageBox::information(this, QStringLiteral("文件"), QStringLiteral("文件为空！"));
		return;
	}
	//给模式中填充数据
	_mModel->removeRows(0, _mModel->rowCount(QModelIndex()), QModelIndex());//删除所有的行（防止空白的行）
	for (unsigned iRow = 0; iRow < _mModelRow; ++iRow)
	{
		_mModel->insertRows(iRow, 1, QModelIndex());
		for (unsigned iColumn = 0; iColumn < _mModelColumn; ++iColumn)
		{
			_mModel->setData(_mModel->index(iRow, iColumn, QModelIndex()), FileContent[iRow].value(iColumn));
		}
	}

	ui.groupBox_ListTitle->setTitle(QStringLiteral("总识别表格数：") + QString::number(_mModelRow) + QStringLiteral("张"));
}


/***************************************
*函数功能：视图上选择项改变槽函数（重载函数，名称固定）
*输入：
*	selected：新选择项
*	deselected：旧选择项
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-21-V1.0
***************************************/
void FormImageAnalyzer::selectionChanged(const QItemSelection & selected, const QItemSelection & deselected)
{
	if (selected.isEmpty())
	{
		return;
	}

	qreal ScaleValue = 1.5;//todo:修改坐标
	int MoveValue = 0;
	int Steep = 200;//移动的单元步长

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
*函数功能：建立一个模式
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-21-V1.0
***************************************/
void FormImageAnalyzer::setupModel()
{
	_mModel = new QStandardItemModel(_mModelRow, _mModelColumn, this);
	for (unsigned iColumn = 0; iColumn < _mModelColumn; ++iColumn)
	{
		_mModel->setHeaderData(iColumn, Qt::Horizontal, QStringLiteral("分组-") + QString::number(iColumn + 1));
	}
}


/***************************************
*函数功能：给界面的表格视图添加数据模式和选择模式
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-21-V1.0
***************************************/
void FormImageAnalyzer::setupView()
{
	ui.tableView->setModel(_mModel);
	//QItemSelectionModel *selectionModel = new QItemSelectionModel(_mModel);
	//_mSelectionModel = selectionModel;
	//ui.tableView->setSelectionModel(_mSelectionModel);
	_mSelectionModel = ui.tableView->selectionModel();//获得视图上的选择项
	_mPixItem->setSelectionModel(_mSelectionModel);//在图元中获得视图上的选择项
	connect(_mSelectionModel, SIGNAL(selectionChanged(QItemSelection, QItemSelection)), this, SLOT(selectionChanged(QItemSelection, QItemSelection)));
}