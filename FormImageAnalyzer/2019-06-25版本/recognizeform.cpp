#include "recognizeform.h"

RecognizeForm::RecognizeForm(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	setWindowTitle(u8"识别表格");

	// 添加到tabwidget
	//tabWidget->addTab(tableViewArr[index], name);

	 //8、设置当前活动的tab
	//tabWidget->setCurrentIndex(0);

	//获取当前tab的总tab数
	//int curTabCount = tabWidget->count();

	// 1、获取当前选择的是哪一个tab
	//int curTabIndex = tabWidget->currentIndex();
	//// 若没有tab页
	//if (-1 == curTabIndex)
	//{
	//	return;
	//}

	//成员变量配置初始化
	_mAppExeFolder = nullptr;
	_mAppConfig = nullptr;


}

RecognizeForm::~RecognizeForm()
{
}

/***************************************
*函数功能：启用裁剪选择CheckBox槽函数，如果当前的选择与配置文件中不一致，则修改配置文件。
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-24-V1.0
***************************************/
void RecognizeForm::CheckBox_IsRectify_Click()
{
	if (ui.CheckBox_IsRectify->isChecked() != _mAppConfig->IsRectify)
	{
		_mAppConfig->IsRectify = ui.CheckBox_IsRectify->isChecked();
		QVariant tempValue = _mAppConfig->IsRectify;
		_mAppConfig->ChangeXMLElement((*_mAppExeFolder) + "/AppConfig.xml", "IsRectify", tempValue.toString());
	}
}


/***************************************
*函数功能：被识别图像旋转90度选择CheckBox槽函数，如果当前的选择与配置文件中不一致，则修改配置文件。
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-24-V1.0
***************************************/
void RecognizeForm::CheckBox_Rotate90_Click()
{
	_mAppConfig->ImageRotate90 = ui.CheckBox_Rotate90->isChecked();
	QVariant tempValue = _mAppConfig->ImageRotate90;
	_mAppConfig->ChangeXMLElement((*_mAppExeFolder) + "/AppConfig.xml", "ImageRotate90", tempValue.toString());
}


/***************************************
*函数功能：自动过滤白图像选择CheckBox槽函数，如果当前的选择与配置文件中不一致，则修改配置文件。
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-24-V1.0
***************************************/
void RecognizeForm::CheckBox_AutoFilterWhitePage_Click()
{
	//todo:_ImageMgr图像管理类里面处理ImagesManager
	//_ImageMgr._AutoFilterWhite = CheckBox_AutoFilterWhitePage.IsChecked.Value;
	_mAppConfig->IsAutoFilterWhite = ui.CheckBox_AutoFilterWhitePage->isChecked();
	QVariant tempValue = _mAppConfig->ImageRotate90;
	_mAppConfig->ChangeXMLElement((*_mAppExeFolder) + "/AppConfig.xml", "IsAutoFilterWhite", tempValue.toString());
}





/***************************************
*函数功能：光源选择ComboBox槽函数，如果当前的选择与配置文件中不一致，则修改配置文件。
*输入：
*	currentIndex：当前选择项目的索引
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-24-V1.0
***************************************/
void RecognizeForm::ComboBox_Light_SelectionChanged(int currentIndex)
{
	if (currentIndex != (int)_mAppConfig->OCRLightColor)
	{
		_mAppConfig->OCRLightColor = (LightColor)currentIndex;
		switch (_mAppConfig->OCRLightColor)
		{
		case LightColor::Red:
			_mAppConfig->ChangeXMLElement((*_mAppExeFolder) + "/AppConfig.xml", "OCRLightColor", "Red");
			break;
		case LightColor::Green:
			_mAppConfig->ChangeXMLElement((*_mAppExeFolder) + "/AppConfig.xml", "OCRLightColor", "Green");
			break;
		case LightColor::Blue:
			_mAppConfig->ChangeXMLElement((*_mAppExeFolder) + "/AppConfig.xml", "OCRLightColor", "Blue");
			break;
		case LightColor::White:
			_mAppConfig->ChangeXMLElement((*_mAppExeFolder) + "/AppConfig.xml", "OCRLightColor", "White");
			break;
		default:
			break;
		}
	}
}


/***************************************
*函数功能：启动识别按钮槽函数。
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-24-V1.0
***************************************/
void RecognizeForm::Button_RecognizeControl_Click()
{
	/*
	if (_recognizeRunning)
	{
		_recognizeRunning = false;
		Button_RecognizeControl.Content = "启动识别";
		ProcessRing_Running.IsActive = false;
		if (_recognizeThread != null)
			_recognizeThread.Join();
	}
	else
	{
		_recognizeRunning = true;
		Button_RecognizeControl.Content = "停止识别";
		ProcessRing_Running.IsActive = true;
		_recognizeThread = new Thread(new ThreadStart(ImageRecognizeThreadFun));
		_recognizeThread.Priority = ThreadPriority.Highest;
		_recognizeThread.Name = "表格图像识别线程";
		_recognizeThread.Start();
	}
	*/
}


/***************************************
*函数功能：
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-25-V1.0
***************************************/
void RecognizeForm::Button_ScannerControl1_Click()
{
	/*
	if (_mAppConfig->LastSelectedDevice == 1)
	{
		if (ui.Button_ScannerControl1->text() == "启动阅读")
		{
			_ocrReader.Close();
			if (!_ocrReader.Open())
				QMessageBox::critical(this, QStringLiteral("Error"), QStringLiteral("OCR阅读机初始化失败！"));
			else
			{
				bool isLackPaper = false;
				_ocrReader.StartScan(0, out isLackPaper);

				// 启动OCR阅读机
				if (isLackPaper)
				{
					QMessageBox::critical(this, QStringLiteral("Error"), QStringLiteral("未检测到纸张！"));
				}
				else
				{
					if (_ocrReader._ImageCount.Count > 0)
						_ocrReader._ImageCount[0] = 0;
					ui.Button_ScannerControl1->setText(u8"停止阅读");
					SetIsEnableProperty(false);
				}
			}
		}
		else
		{
			// 停止阅读
			ui.Button_ScannerControl1->setEnabled(false);
			_ocrReader.StopScan(0);
		}
	}
	*/
}


void RecognizeForm::Button_ScannerControl2_Click()
{
}


/***************************************
*函数功能：从文件夹中选择图片文件按钮槽函数
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-25-V1.0
***************************************/
void RecognizeForm::Button_OpenDirs_Click()
{
	QString dirPath = QFileDialog::getExistingDirectory(this, QString(u8"选择图像所在文件夹"), QString());
	if (dirPath.isEmpty())
	{
		QMessageBox::information(this, QStringLiteral("取消选择"), QStringLiteral("取消图像文件夹选择"));
		return;
	}

	try
	{
		QDir dir(dirPath);
		QStringList ImageFormat;
		QStringList FileNameList;//保存文件夹里的文件名
		ImageFormat
			<< "*.bmp" << "*.BMP"
			<< "*.jpg" << "*.JPG"
			<< "*.jpeg" << "*.JPEG"
			<< "*.png" << "*.PNG"
			<< "*.tif" << "*.TIF"
			<< "*.tiff" << "*.TIFF";

		QFileInfoList FileList = dir.entryInfoList(ImageFormat, QDir::Files, QDir::Unsorted);
		foreach(QFileInfo file, FileList)
		{
			FileNameList.push_back(file.fileName());
		}
		if (QMessageBox::question(this, (u8"提示？"), (u8"共选择" + QString::number(FileNameList.size()) + u8"张图像，确认添加？")) == QMessageBox::Ok)
		{
			//_ImageMgr.AddImageFiles(imgFileNames.ToArray());
			//todo:做上面的操作
		}
	}
	catch (const std::exception & ex)
	{
		QMessageBox::warning(this, QStringLiteral("添加失败"), QString(ex.what()));
	}
}


/***************************************
*函数功能：从计算机中选择图片文件按钮槽函数
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-25-V1.0
***************************************/
void RecognizeForm::Button_OpenFiles_Click()
{
	QStringList fileNames = QFileDialog::getOpenFileNames(this, QString(u8"图像文件"), QString(), u8"图像文件|(*.bmp;*.jpg;*jpeg;*.png;*.tif;*.tiff)");
	if (fileNames.isEmpty())
	{
		QMessageBox::information(this, QStringLiteral("取消选择"), QStringLiteral("取消图像文件选择"));
		return;
	}

	try
	{
		if (QMessageBox::question(this, (u8"提示？"), (u8"共选择" + QString::number(fileNames.size()) + u8"张图像，确认添加？")) == QMessageBox::Ok)
		{
			//_ImageMgr.AddImageFiles(fileNames);
			//todo:做上面的操作
		}
	}
	catch (const std::exception & ex)
	{
		QMessageBox::warning(this, QStringLiteral("添加失败"), QString(ex.what()));
	}
}

void RecognizeForm::OpenDevice()
{
	// 连接设备
	if (_dev.OpenDevice())
	{
		ui.pushButton_Open->setEnabled(false);
		ui.pushButton_Close->setEnabled(true);
		ui.pushButton_StartScan->setEnabled(true);
		ui.pushButton_StopScan->setEnabled(false);
	}
	else
	{
		QMessageBox::critical(this, QStringLiteral("Error"), QStringLiteral("OCR阅读机打开失败！"));
	}
}

void RecognizeForm::StartScan()
{
	// 启动扫描
	if (_dev.StartScan(0))
	{
		ui.pushButton_StartScan->setEnabled(false);
	}
	else
	{
		QMessageBox::critical(this, QStringLiteral("Error"), QStringLiteral("OCR阅读机启动扫描失败！"));
	}
}

void RecognizeForm::StopScan()
{
	// 中断扫描
	if (_dev.AbortScan)
	{
		ui.pushButton_StopScan->setEnabled(false);
	}
	else
	{
		QMessageBox::critical(this, QStringLiteral("Error"), QStringLiteral("OCR阅读机中断扫描失败！"));
	}	
}

void RecognizeForm::CloseDeivce()
{
	// 断开设备连接
	if (_dev.CloseDevice())
	{
		ui.pushButton_Open->setEnabled(true);
		ui.pushButton_StartScan->setEnabled(false);
		ui.pushButton_StopScan->setEnabled(false);
		ui.pushButton_Close->setEnabled(false);
	}
	else
	{
	QMessageBox::critical(this, QStringLiteral("Error"), QStringLiteral("OCR阅读机关闭失败！"));
	}
}



void RecognizeForm::OnDeviceInfoChanged(cs200::eDeviceInfo info)
{
}

void RecognizeForm::OnDeviceImageGenerated(uchar * fImgBuf, int fBufLen, uchar * bImgBuf, int bBufLen)
{
}


/***************************************
*函数功能：设置系统配置，并初始化该子窗口
*输入：
*	appConfig：传入系统配置
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-24-V1.0
***************************************/
void RecognizeForm::setupRecognizeChildWindow(AppConfig * appConfig, QString *appExeFolder)
{
	_mAppConfig = appConfig;
	_mAppExeFolder = appExeFolder;
	_imageSaveFolder = "images";
	_cfgFilePath.isNull();

	//控件配置初始化
//调整ComboBox下拉项目的间隔
	ui.ComboBox_DeviceCount->setView(new QListView());
	ui.ComboBox_Position->setView(new QListView());
	ui.ComboBox_Light->setView(new QListView());
	ui.Label_Pages1->setText(u8"0");
	ui.Label_Pages2->setText(u8"0");
	ui.Label_TotalCount->setText(u8"0");
	ui.Label_ReadCount->setText(u8"0");
	ui.RadioButton_HighSpeedScanner->setChecked(true);
	ui.CheckBox_IsRectify->setEnabled(_mAppConfig->IsRectify);
	ui.ComboBox_DeviceCount->setCurrentIndex(0);
	ui.ComboBox_Position->setCurrentIndex(_mAppConfig->ScanPosition);
	ui.ComboBox_Light->setCurrentIndex(_mAppConfig->OCRLightColor);
	ui.CheckBox_Rotate90->setChecked(_mAppConfig->ImageRotate90);
	ui.CheckBox_AutoFilterWhitePage->setChecked(_mAppConfig->IsAutoFilterWhite);
	if (_mAppConfig->BinarizeThreshold == 0)
		ui.TextBox_BinarizeThreshold->setText(u8"自动");
	else
		ui.TextBox_BinarizeThreshold->setText(QString::number(_mAppConfig->BinarizeThreshold));
	//TextBox_BinarizeThreshold.LostFocus += new RoutedEventHandler(TextBox_BinarizeThreshold_LostFocus);

	connect(ui.CheckBox_IsRectify, SIGNAL(clicked()), this, SLOT(CheckBox_IsRectify_Click()));
	connect(ui.CheckBox_Rotate90, SIGNAL(clicked()), this, SLOT(CheckBox_Rotate90_Click()));
	connect(ui.CheckBox_AutoFilterWhitePage, SIGNAL(clicked()), this, SLOT(CheckBox_AutoFilterWhitePage_Click()));
	connect(ui.ComboBox_DeviceCount, SIGNAL(currentIndexChanged(int)), this, SLOT(ComboBox_DeviceCount_SelectionChanged(int)));
	connect(ui.ComboBox_Position, SIGNAL(currentIndexChanged(int)), this, SLOT(ComboBox_Position_SelectionChanged(int)));
	connect(ui.ComboBox_Light, SIGNAL(currentIndexChanged(int)), this, SLOT(ComboBox_Light_SelectionChanged(int)));
	connect(ui.Button_RecognizeControl, SIGNAL(clicked()), this, SLOT(Button_RecognizeControl_Click()));
	connect(ui.Button_OpenDirs, SIGNAL(clicked()), this, SLOT(Button_OpenDirs_Click()));
	connect(ui.Button_OpenFiles, SIGNAL(clicked()), this, SLOT(Button_OpenFiles_Click()));


	_imageSaveFolder = *_mAppExeFolder + "/" + _imageSaveFolder;//G:\Qt\Qt5.12.1\User\Cocer200Utility\x64\Debug\images
	_cfgFilePath = *_mAppExeFolder + "/utility.cfg";//G:\Qt\Qt5.12.1\User\Cocer200Utility\x64\Debug\utility.cfg
	QDir dir(_imageSaveFolder);
	if (dir.exists())//_imageSaveFolder这个文件夹存在，这删除它里面的所有内容，若不存在则新建一个文件夹。
	{
		dir.setFilter(QDir::Files);
		QStringList filters;
		filters.push_back("*.bmp");
		dir.setNameFilters(filters);
		QFileInfoList files = dir.entryInfoList();
		for (int i = 0; i < files.size(); ++i)
			QFile::remove(files[i].filePath());
	}
	else
	{
		dir.mkdir(_imageSaveFolder);
	}

	// 绑定状态通知和图像产生信号槽
	connect(&_dev, &cs200::Cocer200Scan::InfoChanged, this, &RecognizeForm::OnDeviceInfoChanged);
	connect(&_dev, &cs200::Cocer200Scan::ImageGenerated, this, &RecognizeForm::OnDeviceImageGenerated);

	QFile cfgFile(_cfgFilePath);
	if (cfgFile.exists())
		_dev.GetDevCfg()->ReadFromFile(cfgFile.fileName());
	else
		_dev.GetDevCfg()->SaveToFile(cfgFile.fileName());
	// 初始化
	if (!_dev.Initialize())
	{
		QMessageBox::critical(this, QStringLiteral("Error"), QStringLiteral("OCR阅读机初始化失败！"));
		return;
	}
}



/***************************************
*函数功能：设备数量选择ComboBox槽函数。
*输入：
*	currentIndex：当前选择项目的索引
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-24-V1.0
***************************************/
//void RecognizeForm::ComboBox_DeviceCount_SelectionChanged(int currentIndex)
//{
//	if (ui.Label_Pages2Title == nullptr || ui.Label_Pages2 == nullptr || ui.Button_ScannerControl2 == nullptr)
//		return;
//	if (currentIndex == 0)
//	{
//		ui.Label_Pages2Title->setVisible(false);
//		ui.Label_Pages2->setVisible(false);
//		ui.Button_ScannerControl2->setVisible(false);
//	}
//	else
//	{
//		ui.Label_Pages2Title->setVisible(true);
//		ui.Label_Pages2->setVisible(true);
//		ui.Button_ScannerControl2->setVisible(true);
//	}
//}


/***************************************
*函数功能：阅读纸张位置选择ComboBox槽函数，如果当前的选择与配置文件中不一致，则修改配置文件。
*输入：
*	currentIndex：当前选择项目的索引
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-24-V1.0
***************************************/
//void RecognizeForm::ComboBox_Position_SelectionChanged(int currentIndex)
//{
//	if (currentIndex != (int)_mAppConfig->ScanPosition)
//	{
//		_mAppConfig->ScanPosition = (ScanPostion)currentIndex;
//		switch (_mAppConfig->ScanPosition)
//		{
//		case ScanPostion::Upside:
//			_mAppConfig->ChangeXMLElement((*_mAppExeFolder) + "/AppConfig.xml", "ScanPosition", "Upside");
//			break;
//		case ScanPostion::Downside:
//			_mAppConfig->ChangeXMLElement((*_mAppExeFolder) + "/AppConfig.xml", "ScanPosition", "Downside");
//			break;
//		case ScanPostion::Bothside:
//			_mAppConfig->ChangeXMLElement((*_mAppExeFolder) + "/AppConfig.xml", "ScanPosition", "Bothside");
//			break;
//		default:
//			break;
//		}
//	}
//}