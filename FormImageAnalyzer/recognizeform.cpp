#include "recognizeform.h"

RecognizeForm::RecognizeForm(AppConfig * appConfig, QString *appExeFolder, QWidget *parent) : QDialog(parent)
{
	ui.setupUi(this);

	setWindowTitle(u8"识别表格");

	//成员变量配置初始化
	_mAppConfig = appConfig;
	_mAppExeFolder = appExeFolder;
	_imageSaveFolder = "images";
	_imageIndex = 0;
	_imageCount = 0;
	_cfgFilePath.isNull();

	//控件配置初始化
	ui.label_ImageNum->setText("0");
	ui.label_TotalCount->setText("0");
	ui.label_ReadCount->setText("0");
	ui.label_ImageDPI->setText("0");
	ui.label_ImageType->setText(u8"请设置");
	ui.label_OtherFun->setText(u8"请设置");

	ui.pushButton_Open->setEnabled(true);
	ui.pushButton_Close->setEnabled(false);
	ui.pushButton_StartScan->setEnabled(false);
	ui.pushButton_StopScan->setEnabled(false);
	ui.pushButton_Setting->setEnabled(true);
	ui.pushButton_Save->setEnabled(false);//todo:是否还需要这个按钮？SaveImage()这个槽函数没做任何事。

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
*函数功能：保存图片按钮槽函数，保存识别出的图片到文件夹
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-26-V1.0
***************************************/
void RecognizeForm::SaveImage()
{//todo:图像在图像数据采集到响应槽中已经保存了
	/*
	QString dir = QFileDialog::getExistingDirectory(this, u8"保存到...");
	if (!dir.isEmpty())
	{
		QList< QListWidgetItem *> items = ui.listWidget_ImageList->selectedItems();
		for (int i = 0; i < items.count(); ++i)
		{
			QListWidgetItem *item = items[i];
			QString imgPrefix = item->text();
			QString frontImgPath = _imageSaveFolder + "/" + imgPrefix + "_F.bmp";
			QFile::copy(frontImgPath, dir + "/" + imgPrefix + "_F.bmp");
		}
	}
	*/
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
	_imageCount++;
	ui.label_ImageNum->setText(QString::number(_imageCount));
	ui.label_TotalCount->setText(QString::number(_imageCount));

	if (fImgBuf == nullptr || bImgBuf == nullptr || fBufLen == 0 || bBufLen == 0)
	{
		return;
	}

	_imageIndex++;
	//todo：这里需要重写，和原来的代码不一致，该程序里只有一张图片。
	QString imgPrefix = u8"图像" + QString::number(_imageIndex);
	ui.label_ReadCount->setText(QString::number(_imageIndex));

	////todo:这里查看一下fImgBuf、bImgBuf的值
	////判断正反面,若是正面，则为0的像素点会比反面少、todo:白色像素点是否是0？
	//int fImgBufCount = 0;
	//int bImgBufCount = 0;
	//uchar * ImageData = nullptr;
	//int ImageDataLen = 0;
	//for (int i = 0; i < fBufLen || i < bBufLen; ++i)
	//{
	//	if (fImgBuf[i] == '0')
	//	{
	//		fImgBufCount++;
	//	}
	//	if (bImgBuf[i] == '0')
	//	{
	//		bImgBufCount++;
	//	}
	//}
	//if (fImgBufCount <= bImgBufCount)
	//{
	//	ImageData = fImgBuf;// fImgBuf为正面
	//	ImageDataLen = fBufLen;
	//}
	//else
	//{
	//	ImageData = bImgBuf;// bImgBuf为正面
	//	ImageDataLen = bBufLen;
	//}
	//QString frontImgPath = _imageSaveFolder + "/" + imgPrefix + ".bmp";
	//QFile fFile(frontImgPath);
	//fFile.open(QIODevice::Truncate | QIODevice::WriteOnly);
	//fFile.write((char*)ImageData, ImageDataLen);
	//fFile.close();
	//delete[] ImageData;

	//保存正面图片
	QString frontImgPath = _imageSaveFolder + "/" + imgPrefix + "_F.bmp";
	QFile fFile(frontImgPath);
	fFile.open(QIODevice::Truncate | QIODevice::WriteOnly);
	fFile.write((char*)fImgBuf, fBufLen);
	fFile.close();
	delete[] fImgBuf;
	//保存反面图片
	QString backImgPath = _imageSaveFolder + "/" + imgPrefix + "_B.bmp";
	QFile bFile(backImgPath);
	bFile.open(QIODevice::Truncate | QIODevice::WriteOnly);
	bFile.write((char*)bImgBuf, bBufLen);
	bFile.close();
	delete[] bImgBuf;
	//放置图片到主界面，todo:由主界面显示，到主界面去处理。
	//ui.frame_Right->setImage(backImgPath);

	if (!ui.pushButton_Save->isEnabled())
		ui.pushButton_Save->setEnabled(true);
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