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
	// 释放设备
	_dev.Release();	
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
	//todo：这个按钮是否还需要存在？
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
*函数功能：打开设备按钮槽函数
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-26-V1.0
***************************************/
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


/***************************************
*函数功能：启动阅读按钮槽函数
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-26-V1.0
***************************************/
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


/***************************************
*函数功能：中断阅读按钮槽函数
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-26-V1.0
***************************************/
void RecognizeForm::StopScan()
{
	// 中断扫描
	_dev.AbortScan();
	ui.pushButton_StopScan->setEnabled(false);
}


/***************************************
*函数功能：断开设备按钮槽函数
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-26-V1.0
***************************************/
void RecognizeForm::CloseDeivce()
{
	// 断开设备连接
	_dev.CloseDevice();
	ui.pushButton_Open->setEnabled(true);
	ui.pushButton_StartScan->setEnabled(false);
	ui.pushButton_StopScan->setEnabled(false);
	ui.pushButton_Close->setEnabled(false);

}


/***************************************
*函数功能：设置设备按钮槽函数
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-26-V1.0
***************************************/
void RecognizeForm::Setting()
{
	ScanSetting ss(_dev.GetDevCfg(), this);
	if (ss.exec() == QDialog::Accepted)
	{
		_dev.GetDevCfg()->SaveToFile(_cfgFilePath);
		ui.label_ImageDPI->setText(ss._mDPI);
		if (ss._mImageType == u8"灰色")
		{
			ui.label_ImageType->setText(ss._mImageType + ":" + ss._mLightColor);
		}
		else
		{
			ui.label_ImageType->setText(ss._mImageType);
		}
		ui.label_OtherFun->setText(ss._mCheckBox_DoubleCheck);
	}
		
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


/***************************************
*函数功能：阅读设备信号响应槽（响应信号：SIGNAL(InfoChanged(eDeviceInfo info))）
*输入：
*	info：当前的设备信息
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-26-V1.0
***************************************/
void RecognizeForm::OnDeviceInfoChanged(cs200::eDeviceInfo info)
{
	switch (info)
	{
	case cs200::eStandby:
	{
		ui.pushButton_StartScan->setEnabled(false);
		ui.pushButton_StopScan->setEnabled(false);
		ui.pushButton_Close->setEnabled(true);
	}
	break;
	case cs200::ePaperOn:
	{
		ui.pushButton_StartScan->setEnabled(true);
		ui.pushButton_StopScan->setEnabled(false);
	}
	break;
	case cs200::eScanning:
	{
		ui.pushButton_StartScan->setEnabled(false);
		ui.pushButton_StopScan->setEnabled(true);
		ui.pushButton_Close->setEnabled(false);
	}
	break;
	case cs200::eError_UpcoverOpen:
	{
		ui.pushButton_StartScan->setEnabled(false);
		ui.pushButton_StopScan->setEnabled(false);
		QMessageBox::critical(this, u8"错误", u8"上盖开启！", QMessageBox::Ok, QMessageBox::Ok);
	}
	break;
	case cs200::eError_PaperIn:
	{
		ui.pushButton_StartScan->setEnabled(false);
		ui.pushButton_StopScan->setEnabled(false);
		QMessageBox::critical(this, u8"错误", u8"进纸错误！", QMessageBox::Ok, QMessageBox::Ok);
	}
	break;
	case cs200::eError_Lift:
	{
		ui.pushButton_StartScan->setEnabled(false);
		ui.pushButton_StopScan->setEnabled(false);
		QMessageBox::critical(this, u8"错误", u8"升降台错误！", QMessageBox::Ok, QMessageBox::Ok);
	}
	break;
	case cs200::eError_Jam:
	{
		ui.pushButton_StartScan->setEnabled(false);
		ui.pushButton_StopScan->setEnabled(false);
		QMessageBox::critical(this, u8"错误", u8"卡纸！", QMessageBox::Ok, QMessageBox::Ok);
	}
	break;
	case cs200::eError_Double:
	{
		ui.pushButton_StartScan->setEnabled(false);
		ui.pushButton_StopScan->setEnabled(false);
		QMessageBox::critical(this, u8"错误", u8"重张！", QMessageBox::Ok, QMessageBox::Ok);
	}
	break;
	default:
		break;
	}
}


/***************************************
*函数功能：图像数据采集到响应槽，需在不使时主动释放内存空间阅读设备信号响应槽
*（响应信号：SIGNAL(ImageGenerated(uchar *fImgBuf, int fBufLen, uchar *bImgBuf, int bBufLen))）
*输入：
*	info：当前的设备信息
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-26-V1.0
***************************************/
void RecognizeForm::OnDeviceImageGenerated(uchar * fImgBuf, int fBufLen, uchar * bImgBuf, int bBufLen)
{
	//todo：这里需要重写，和原来的代码不一致，我的程序里只有一张图片。先询问一下温师兄。
	/*
	QString imgPrefix = u8"图像" + QString::number(_imageIndex);
	QListWidgetItem *item = new QListWidgetItem();
	item->setText(imgPrefix);
	QFont font = item->font();
	font.setPointSize(16);
	item->setFont(font);
	ui.listWidget_ImageList->addItem(item);
	ui.listWidget_ImageList->scrollToBottom();
	item->setSelected(true);

	if (fImgBuf != NULL)
	{
		QString frontImgPath = _imageSaveFolder + "/" + imgPrefix + "_F.bmp";
		QFile fFile(frontImgPath);
		fFile.open(QIODevice::Truncate | QIODevice::WriteOnly);
		fFile.write((char*)fImgBuf, fBufLen);
		fFile.close();
		delete[] fImgBuf;
		ui.frame_Left->setImage(frontImgPath);
	}

	if (bImgBuf != NULL)
	{
		QString backImgPath = _imageSaveFolder + "/" + imgPrefix + "_B.bmp";
		QFile bFile(backImgPath);
		bFile.open(QIODevice::Truncate | QIODevice::WriteOnly);
		bFile.write((char*)bImgBuf, bBufLen);
		bFile.close();
		delete[] bImgBuf;
		ui.frame_Right->setImage(backImgPath);
	}

	_imageIndex++;

	if (!ui.pushButton_Save->isEnabled())
		ui.pushButton_Save->setEnabled(true);
	*/
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
	ui.Label_ImageNum->setText("0");
	ui.Label_TotalCount->setText("0");
	ui.Label_ReadCount->setText("0");
	ui.label_ImageDPI->setText("0");
	ui.label_ImageType->setText(u8"请设置");
	ui.label_OtherFun->setText(u8"请设置");

	ui.pushButton_Open->setEnabled(true);
	ui.pushButton_Close->setEnabled(false);
	ui.pushButton_StartScan->setEnabled(false);
	ui.pushButton_StopScan->setEnabled(false);
	ui.pushButton_Setting->setEnabled(true);
	ui.Button_RecognizeControl->setEnabled(false);//todo:是否还需要这个按钮？

	ui.CheckBox_Rotate90->setChecked(_mAppConfig->ImageRotate90);
	ui.CheckBox_AutoFilterWhitePage->setChecked(_mAppConfig->IsAutoFilterWhite);
	if (_mAppConfig->BinarizeThreshold == 0)
	{
		ui.TextBox_BinarizeThreshold->setText(u8"自动");
	}
	else
	{
		ui.TextBox_BinarizeThreshold->setText(QString::number(_mAppConfig->BinarizeThreshold));
	}

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
	{
		_dev.GetDevCfg()->ReadFromFile(cfgFile.fileName());
	}
	else
	{
		_dev.GetDevCfg()->SaveToFile(cfgFile.fileName());
	}
	// 初始化
	if (!_dev.Initialize())
	{
		ui.frame->setEnabled(false);
		QMessageBox::critical(this, QStringLiteral("Error"), QStringLiteral("OCR阅读机初始化失败！"));
		return;
	}
}

