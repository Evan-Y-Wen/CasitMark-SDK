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
	_mExcelReader = new ExcelReader;
	_mPixmap = nullptr;
	_mPixItem = nullptr;
	_mGraphicsScene = nullptr;
	_mModel = nullptr;
	_mModelRow = 0;
	_mModelColumn = 0;
	_mSelectionModel = nullptr;
	_mCurrentPattern = new Cm3::FormPattern::MPattern; // 当前使用的模式
	_mCurrentResult = new Cm3::FormResult::MResult; // 当前识别的结果

	//控件配置初始化
	ui.splitter->setStretchFactor(0, 5);//设置两个分割窗口的比例为5:2
	ui.splitter->setStretchFactor(1, 2);

	//第一次运行界面时的初始化
	OnButtonOpenPatten();//载入图片_mPixmap，并初始化_mPixItem
	addPatternStructure();
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
	if (_mExcelReader != nullptr)
	{
		delete _mExcelReader;
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
	if (_mCurrentPattern != nullptr)
	{
		delete _mCurrentPattern;
	}
	if (_mCurrentResult != nullptr)
	{
		delete _mCurrentResult;
	}
	appExeFolder = nullptr;
	appConfig = nullptr;
	_mExcelReader = nullptr;
	_mPixmap = nullptr;
	_mPixItem = nullptr;
	_mGraphicsScene = nullptr;
	_mModel = nullptr;
	_mModelRow = 0;
	_mModelColumn = 0;
	_mSelectionModel = nullptr;
	_mCurrentPattern = nullptr;
	_mCurrentResult = nullptr;
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

	QImage imageToDecode("QRCode1-8.jpg");
	//QString path = QFileDialog::getOpenFileName();
	QZXing decoder;
	//decoder.setDecoder(QZXing::DecoderFormat_QR_CODE | QZXing::DecoderFormat_EAN_13);
	//QString result = decoder.decodeImageFromFile(path);
	QString result = decoder.decodeImage(imageToDecode);
	qDebug() << result;
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
	//加载图片文件  todo:修改选择的文件格式
	QString fileName = QFileDialog::getOpenFileName(this, QString(), QString(), "Images(*.png *.bmp *.jpg *.tif *.GIF)");
	if (fileName.isEmpty())
	{
		QMessageBox::information(this, QStringLiteral("取消选择"), QStringLiteral("取消图片选择"));
		return;
	}

	if (_mPixmap != nullptr)
	{
		delete _mPixmap;
		_mPixmap = nullptr;
	}
	_mPixmap = new QPixmap;

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
	RecognizeForm RecognizeChildWindow(appConfig, appExeFolder, this);
	RecognizeChildWindow.exec();
}


/***************************************
*函数功能：重新识别表格按钮槽函数
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-07-01-V1.0
***************************************/
void FormImageAnalyzer::OnButtonReRecognize()
{
	OnButtonRecognize();
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

	ui.tabWidget->setTabText(0, (QStringLiteral("总识别表格数：%1张").arg(_mModelRow)));
}


/***************************************
*函数功能：导出数据按钮槽函数
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-26-V1.0
***************************************/
void FormImageAnalyzer::OnButtonSaveData()
{
	QStringList FileContent;//保存视图里的内容，以便存到文档中去
	for (unsigned iRow = 0; iRow < _mModelRow; ++iRow)
	{
		QString dataLine = QString();
		for (unsigned iColumn = 0; iColumn < _mModelColumn; ++iColumn)
		{
			if (_mModel->item(iRow, iColumn)->text() == "")
			{
				continue;
			}
			dataLine = dataLine + _mModel->item(iRow, iColumn)->text() + ",";
		}
		dataLine.chop(1);
		//qDebug() << dataLine;
		FileContent << dataLine;
	}

	//todo:修改选择的文件格式
	QString fileName = QFileDialog::getSaveFileName(this, QString(), QString("*.txt"), "Data Files(*.txt *.crst)");
	if (fileName.isEmpty())
	{
		QMessageBox::information(this, u8"取消保存", u8"取消数据文件保存");
		return;
	}

	QFile file(fileName);
	//if (file.open(QFile::WriteOnly | QIODevice::Text  | QFile::Truncate))
	if (file.open(QFile::WriteOnly | QFile::Truncate))
	{
		QTextStream writeStream(&file);
		foreach(QString Line, FileContent)
		{
			writeStream << Line << "\r\n";
		}
		file.close();
		QMessageBox::information(this, u8"保存成功", u8"数据文件保存成功！");
	}
	else
	{
		QMessageBox::critical(this, u8"保存失败", u8"数据文件保存失败！");
	}
}


/***************************************
*函数功能：结果转换按钮槽函数，将model结果转换成Excel表格
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-07-03-V1.0
***************************************/
void FormImageAnalyzer::OnButtonExcelResult()
{
	try
	{
		//新建一个Excel
		if (!_mExcelReader->newExcel())
		{
			throw "-1";
		}
		//表头设置
		for (unsigned iColumn = 0; iColumn < _mModelColumn; ++iColumn)
		{
			_mExcelReader->writeExcel(1, iColumn + 1, QStringLiteral("分组-%1").arg(iColumn + 1));
		}
		//内容设置
		for (unsigned iRow = 0; iRow < _mModelRow; ++iRow)
		{
			for (unsigned iColumn = 0; iColumn < _mModelColumn; ++iColumn)
			{
				if (_mModel->item(iRow, iColumn)->text() == "")
				{
					continue;
				}
				_mExcelReader->writeExcel(iRow + 2, iColumn + 1, _mModel->item(iRow, iColumn)->text());
			}
		}
		QMessageBox::information(this, QStringLiteral("成功"), QStringLiteral("Excel保存成功！"));
	}
	catch (...)
	{
		QMessageBox::critical(this, QStringLiteral("失败"), QStringLiteral("Excel保存失败！"));
	}
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
*函数功能：建立一个模型
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
		_mModel->setHeaderData(iColumn, Qt::Horizontal, QStringLiteral("分组-%1").arg(iColumn + 1));
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


/***************************************
*函数功能：加载模式结构，显示到界面
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-07-09-V1.0
***************************************/
void FormImageAnalyzer::addPatternStructure()
{
	// todo:后期修改，应该是，加载了模式，该结构就确定了。
	ui.treeWidget->setHeaderLabel(u8"模式名称："); 
	QTreeWidgetItem *identifierItem = new QTreeWidgetItem(ui.treeWidget, QStringList(u8"标志码"));
	QTreeWidgetItem *identifierTypeItem = new QTreeWidgetItem(identifierItem, QStringList(u8"标志码类型"));
	
	QTreeWidgetItem *markGroupItem = new QTreeWidgetItem(ui.treeWidget, QStringList(u8"填涂区"));
	QTreeWidgetItem *groupItem1 = new QTreeWidgetItem(markGroupItem, QStringList(u8"分组-1"));
	QTreeWidgetItem *groupItem2 = new QTreeWidgetItem(markGroupItem, QStringList(u8"分组-2"));
	QTreeWidgetItem *groupItem3 = new QTreeWidgetItem(markGroupItem, QStringList(u8"分组-3"));
	QTreeWidgetItem *groupItem4 = new QTreeWidgetItem(markGroupItem, QStringList(u8"分组-4"));
	QTreeWidgetItem *groupItem5 = new QTreeWidgetItem(markGroupItem, QStringList(u8"分组-5"));
	QTreeWidgetItem *groupItem6 = new QTreeWidgetItem(markGroupItem, QStringList(u8"分组-6"));

	QTreeWidgetItem *cellItem01 = new QTreeWidgetItem(groupItem1, QStringList(u8"cell(0-1)"));
	QTreeWidgetItem *cellItem02 = new QTreeWidgetItem(groupItem1, QStringList(u8"cell(0-2)"));
	QTreeWidgetItem *cellItem03 = new QTreeWidgetItem(groupItem1, QStringList(u8"cell(0-3)"));
	QTreeWidgetItem *cellItem04 = new QTreeWidgetItem(groupItem1, QStringList(u8"cell(0-4)"));
	QTreeWidgetItem *cellItem05 = new QTreeWidgetItem(groupItem1, QStringList(u8"cell(0-5)"));

	QTreeWidgetItem *cellItem11 = new QTreeWidgetItem(groupItem2, QStringList(u8"cell(1-1)"));
	QTreeWidgetItem *cellItem12 = new QTreeWidgetItem(groupItem2, QStringList(u8"cell(1-2)"));
	QTreeWidgetItem *cellItem13 = new QTreeWidgetItem(groupItem2, QStringList(u8"cell(1-3)"));
	QTreeWidgetItem *cellItem14 = new QTreeWidgetItem(groupItem2, QStringList(u8"cell(1-4)"));
	QTreeWidgetItem *cellItem15 = new QTreeWidgetItem(groupItem2, QStringList(u8"cell(1-5)"));
	
}
