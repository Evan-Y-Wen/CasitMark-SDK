#include "recognizeform.h"

RecognizeForm::RecognizeForm(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	setWindowTitle(u8"ʶ�����");

	// ���ӵ�tabwidget
	//tabWidget->addTab(tableViewArr[index], name);

	 //8�����õ�ǰ���tab
	//tabWidget->setCurrentIndex(0);

	//��ȡ��ǰtab����tab��
	//int curTabCount = tabWidget->count();

	// 1����ȡ��ǰѡ�������һ��tab
	//int curTabIndex = tabWidget->currentIndex();
	//// ��û��tabҳ
	//if (-1 == curTabIndex)
	//{
	//	return;
	//}

	//��Ա�������ó�ʼ��
	_mAppExeFolder = nullptr;
	_mAppConfig = nullptr;
}


RecognizeForm::~RecognizeForm()
{
	// �ͷ��豸
	_dev.Release();	
}


/***************************************
*�������ܣ���ʶ��ͼ����ת90��ѡ��CheckBox�ۺ����������ǰ��ѡ���������ļ��в�һ�£����޸������ļ���
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-24-V1.0
***************************************/
void RecognizeForm::CheckBox_Rotate90_Click()
{
	_mAppConfig->ImageRotate90 = ui.CheckBox_Rotate90->isChecked();
	QVariant tempValue = _mAppConfig->ImageRotate90;
	_mAppConfig->ChangeXMLElement((*_mAppExeFolder) + "/AppConfig.xml", "ImageRotate90", tempValue.toString());
}


/***************************************
*�������ܣ��Զ����˰�ͼ��ѡ��CheckBox�ۺ����������ǰ��ѡ���������ļ��в�һ�£����޸������ļ���
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-24-V1.0
***************************************/
void RecognizeForm::CheckBox_AutoFilterWhitePage_Click()
{
	//todo:_ImageMgrͼ����������洦��ImagesManager
	//_ImageMgr._AutoFilterWhite = CheckBox_AutoFilterWhitePage.IsChecked.Value;
	_mAppConfig->IsAutoFilterWhite = ui.CheckBox_AutoFilterWhitePage->isChecked();
	QVariant tempValue = _mAppConfig->ImageRotate90;
	_mAppConfig->ChangeXMLElement((*_mAppExeFolder) + "/AppConfig.xml", "IsAutoFilterWhite", tempValue.toString());
}


/***************************************
*�������ܣ�����ʶ��ť�ۺ�����
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-24-V1.0
***************************************/
void RecognizeForm::Button_RecognizeControl_Click()
{
	//todo�������ť�Ƿ���Ҫ���ڣ�
	/*
	if (_recognizeRunning)
	{
		_recognizeRunning = false;
		Button_RecognizeControl.Content = "����ʶ��";
		ProcessRing_Running.IsActive = false;
		if (_recognizeThread != null)
			_recognizeThread.Join();
	}
	else
	{
		_recognizeRunning = true;
		Button_RecognizeControl.Content = "ֹͣʶ��";
		ProcessRing_Running.IsActive = true;
		_recognizeThread = new Thread(new ThreadStart(ImageRecognizeThreadFun));
		_recognizeThread.Priority = ThreadPriority.Highest;
		_recognizeThread.Name = "����ͼ��ʶ���߳�";
		_recognizeThread.Start();
	}
	*/
}



/***************************************
*�������ܣ����豸��ť�ۺ���
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-26-V1.0
***************************************/
void RecognizeForm::OpenDevice()
{
	// �����豸
	if (_dev.OpenDevice())
	{
		ui.pushButton_Open->setEnabled(false);
		ui.pushButton_Close->setEnabled(true);
		ui.pushButton_StartScan->setEnabled(true);
		ui.pushButton_StopScan->setEnabled(false);
	}
	else
	{
		QMessageBox::critical(this, QStringLiteral("Error"), QStringLiteral("OCR�Ķ�����ʧ�ܣ�"));
	}
}


/***************************************
*�������ܣ������Ķ���ť�ۺ���
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-26-V1.0
***************************************/
void RecognizeForm::StartScan()
{
	// ����ɨ��
	if (_dev.StartScan(0))
	{
		ui.pushButton_StartScan->setEnabled(false);
	}
	else
	{
		QMessageBox::critical(this, QStringLiteral("Error"), QStringLiteral("OCR�Ķ�������ɨ��ʧ�ܣ�"));
	}
}


/***************************************
*�������ܣ��ж��Ķ���ť�ۺ���
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-26-V1.0
***************************************/
void RecognizeForm::StopScan()
{
	// �ж�ɨ��
	_dev.AbortScan();
	ui.pushButton_StopScan->setEnabled(false);
}


/***************************************
*�������ܣ��Ͽ��豸��ť�ۺ���
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-26-V1.0
***************************************/
void RecognizeForm::CloseDeivce()
{
	// �Ͽ��豸����
	_dev.CloseDevice();
	ui.pushButton_Open->setEnabled(true);
	ui.pushButton_StartScan->setEnabled(false);
	ui.pushButton_StopScan->setEnabled(false);
	ui.pushButton_Close->setEnabled(false);

}


/***************************************
*�������ܣ������豸��ť�ۺ���
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-26-V1.0
***************************************/
void RecognizeForm::Setting()
{
	ScanSetting ss(_dev.GetDevCfg(), this);
	if (ss.exec() == QDialog::Accepted)
	{
		_dev.GetDevCfg()->SaveToFile(_cfgFilePath);
		ui.label_ImageDPI->setText(ss._mDPI);
		if (ss._mImageType == u8"��ɫ")
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
*�������ܣ����ļ�����ѡ��ͼƬ�ļ���ť�ۺ���
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-25-V1.0
***************************************/
void RecognizeForm::Button_OpenDirs_Click()
{
	QString dirPath = QFileDialog::getExistingDirectory(this, QString(u8"ѡ��ͼ�������ļ���"), QString());
	if (dirPath.isEmpty())
	{
		QMessageBox::information(this, QStringLiteral("ȡ��ѡ��"), QStringLiteral("ȡ��ͼ���ļ���ѡ��"));
		return;
	}

	try
	{
		QDir dir(dirPath);
		QStringList ImageFormat;
		QStringList FileNameList;//�����ļ�������ļ���
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
		if (QMessageBox::question(this, (u8"��ʾ��"), (u8"��ѡ��" + QString::number(FileNameList.size()) + u8"��ͼ��ȷ�����ӣ�")) == QMessageBox::Ok)
		{
			//_ImageMgr.AddImageFiles(imgFileNames.ToArray());
			//todo:������Ĳ���
		}
	}
	catch (const std::exception & ex)
	{
		QMessageBox::warning(this, QStringLiteral("����ʧ��"), QString(ex.what()));
	}
}


/***************************************
*�������ܣ��Ӽ������ѡ��ͼƬ�ļ���ť�ۺ���
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-25-V1.0
***************************************/
void RecognizeForm::Button_OpenFiles_Click()
{
	QStringList fileNames = QFileDialog::getOpenFileNames(this, QString(u8"ͼ���ļ�"), QString(), u8"ͼ���ļ�|(*.bmp;*.jpg;*jpeg;*.png;*.tif;*.tiff)");
	if (fileNames.isEmpty())
	{
		QMessageBox::information(this, QStringLiteral("ȡ��ѡ��"), QStringLiteral("ȡ��ͼ���ļ�ѡ��"));
		return;
	}

	try
	{
		if (QMessageBox::question(this, (u8"��ʾ��"), (u8"��ѡ��" + QString::number(fileNames.size()) + u8"��ͼ��ȷ�����ӣ�")) == QMessageBox::Ok)
		{
			//_ImageMgr.AddImageFiles(fileNames);
			//todo:������Ĳ���
		}
	}
	catch (const std::exception & ex)
	{
		QMessageBox::warning(this, QStringLiteral("����ʧ��"), QString(ex.what()));
	}
}


/***************************************
*�������ܣ��Ķ��豸�ź���Ӧ�ۣ���Ӧ�źţ�SIGNAL(InfoChanged(eDeviceInfo info))��
*���룺
*	info����ǰ���豸��Ϣ
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-26-V1.0
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
		QMessageBox::critical(this, u8"����", u8"�ϸǿ�����", QMessageBox::Ok, QMessageBox::Ok);
	}
	break;
	case cs200::eError_PaperIn:
	{
		ui.pushButton_StartScan->setEnabled(false);
		ui.pushButton_StopScan->setEnabled(false);
		QMessageBox::critical(this, u8"����", u8"��ֽ����", QMessageBox::Ok, QMessageBox::Ok);
	}
	break;
	case cs200::eError_Lift:
	{
		ui.pushButton_StartScan->setEnabled(false);
		ui.pushButton_StopScan->setEnabled(false);
		QMessageBox::critical(this, u8"����", u8"����̨����", QMessageBox::Ok, QMessageBox::Ok);
	}
	break;
	case cs200::eError_Jam:
	{
		ui.pushButton_StartScan->setEnabled(false);
		ui.pushButton_StopScan->setEnabled(false);
		QMessageBox::critical(this, u8"����", u8"��ֽ��", QMessageBox::Ok, QMessageBox::Ok);
	}
	break;
	case cs200::eError_Double:
	{
		ui.pushButton_StartScan->setEnabled(false);
		ui.pushButton_StopScan->setEnabled(false);
		QMessageBox::critical(this, u8"����", u8"���ţ�", QMessageBox::Ok, QMessageBox::Ok);
	}
	break;
	default:
		break;
	}
}


/***************************************
*�������ܣ�ͼ�����ݲɼ�����Ӧ�ۣ����ڲ�ʹʱ�����ͷ��ڴ�ռ��Ķ��豸�ź���Ӧ��
*����Ӧ�źţ�SIGNAL(ImageGenerated(uchar *fImgBuf, int fBufLen, uchar *bImgBuf, int bBufLen))��
*���룺
*	info����ǰ���豸��Ϣ
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-26-V1.0
***************************************/
void RecognizeForm::OnDeviceImageGenerated(uchar * fImgBuf, int fBufLen, uchar * bImgBuf, int bBufLen)
{
	//todo��������Ҫ��д����ԭ���Ĵ��벻һ�£��ҵĳ�����ֻ��һ��ͼƬ����ѯ��һ����ʦ�֡�
	/*
	QString imgPrefix = u8"ͼ��" + QString::number(_imageIndex);
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
*�������ܣ�����ϵͳ���ã�����ʼ�����Ӵ���
*���룺
*	appConfig������ϵͳ����
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-24-V1.0
***************************************/
void RecognizeForm::setupRecognizeChildWindow(AppConfig * appConfig, QString *appExeFolder)
{
	_mAppConfig = appConfig;
	_mAppExeFolder = appExeFolder;
	_imageSaveFolder = "images";
	_cfgFilePath.isNull();

	//�ؼ����ó�ʼ��
	ui.Label_ImageNum->setText("0");
	ui.Label_TotalCount->setText("0");
	ui.Label_ReadCount->setText("0");
	ui.label_ImageDPI->setText("0");
	ui.label_ImageType->setText(u8"������");
	ui.label_OtherFun->setText(u8"������");

	ui.pushButton_Open->setEnabled(true);
	ui.pushButton_Close->setEnabled(false);
	ui.pushButton_StartScan->setEnabled(false);
	ui.pushButton_StopScan->setEnabled(false);
	ui.pushButton_Setting->setEnabled(true);
	ui.Button_RecognizeControl->setEnabled(false);//todo:�Ƿ���Ҫ�����ť��

	ui.CheckBox_Rotate90->setChecked(_mAppConfig->ImageRotate90);
	ui.CheckBox_AutoFilterWhitePage->setChecked(_mAppConfig->IsAutoFilterWhite);
	if (_mAppConfig->BinarizeThreshold == 0)
	{
		ui.TextBox_BinarizeThreshold->setText(u8"�Զ�");
	}
	else
	{
		ui.TextBox_BinarizeThreshold->setText(QString::number(_mAppConfig->BinarizeThreshold));
	}

	_imageSaveFolder = *_mAppExeFolder + "/" + _imageSaveFolder;//G:\Qt\Qt5.12.1\User\Cocer200Utility\x64\Debug\images
	_cfgFilePath = *_mAppExeFolder + "/utility.cfg";//G:\Qt\Qt5.12.1\User\Cocer200Utility\x64\Debug\utility.cfg
	QDir dir(_imageSaveFolder);
	if (dir.exists())//_imageSaveFolder����ļ��д��ڣ���ɾ����������������ݣ������������½�һ���ļ��С�
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

	// ��״̬֪ͨ��ͼ������źŲ�
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
	// ��ʼ��
	if (!_dev.Initialize())
	{
		ui.frame->setEnabled(false);
		QMessageBox::critical(this, QStringLiteral("Error"), QStringLiteral("OCR�Ķ�����ʼ��ʧ�ܣ�"));
		return;
	}
}
