#include "recognizeform.h"

RecognizeForm::RecognizeForm(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	setWindowTitle(u8"ʶ����");

	// ��ӵ�tabwidget
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
}

/***************************************
*�������ܣ����òü�ѡ��CheckBox�ۺ����������ǰ��ѡ���������ļ��в�һ�£����޸������ļ���
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-24-V1.0
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
*�������ܣ���Դѡ��ComboBox�ۺ����������ǰ��ѡ���������ļ��в�һ�£����޸������ļ���
*���룺
*	currentIndex����ǰѡ����Ŀ������
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-24-V1.0
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
		_recognizeThread.Name = "���ͼ��ʶ���߳�";
		_recognizeThread.Start();
	}
	*/
}


/***************************************
*�������ܣ�
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-25-V1.0
***************************************/
void RecognizeForm::Button_ScannerControl1_Click()
{
	/*
	if (_mAppConfig->LastSelectedDevice == 1)
	{
		if (ui.Button_ScannerControl1->text() == "�����Ķ�")
		{
			_ocrReader.Close();
			if (!_ocrReader.Open())
				QMessageBox::critical(this, QStringLiteral("Error"), QStringLiteral("OCR�Ķ�����ʼ��ʧ�ܣ�"));
			else
			{
				bool isLackPaper = false;
				_ocrReader.StartScan(0, out isLackPaper);

				// ����OCR�Ķ���
				if (isLackPaper)
				{
					QMessageBox::critical(this, QStringLiteral("Error"), QStringLiteral("δ��⵽ֽ�ţ�"));
				}
				else
				{
					if (_ocrReader._ImageCount.Count > 0)
						_ocrReader._ImageCount[0] = 0;
					ui.Button_ScannerControl1->setText(u8"ֹͣ�Ķ�");
					SetIsEnableProperty(false);
				}
			}
		}
		else
		{
			// ֹͣ�Ķ�
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
		if (QMessageBox::question(this, (u8"��ʾ��"), (u8"��ѡ��" + QString::number(FileNameList.size()) + u8"��ͼ��ȷ����ӣ�")) == QMessageBox::Ok)
		{
			//_ImageMgr.AddImageFiles(imgFileNames.ToArray());
			//todo:������Ĳ���
		}
	}
	catch (const std::exception & ex)
	{
		QMessageBox::warning(this, QStringLiteral("���ʧ��"), QString(ex.what()));
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
		if (QMessageBox::question(this, (u8"��ʾ��"), (u8"��ѡ��" + QString::number(fileNames.size()) + u8"��ͼ��ȷ����ӣ�")) == QMessageBox::Ok)
		{
			//_ImageMgr.AddImageFiles(fileNames);
			//todo:������Ĳ���
		}
	}
	catch (const std::exception & ex)
	{
		QMessageBox::warning(this, QStringLiteral("���ʧ��"), QString(ex.what()));
	}
}

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

void RecognizeForm::StopScan()
{
	// �ж�ɨ��
	if (_dev.AbortScan)
	{
		ui.pushButton_StopScan->setEnabled(false);
	}
	else
	{
		QMessageBox::critical(this, QStringLiteral("Error"), QStringLiteral("OCR�Ķ����ж�ɨ��ʧ�ܣ�"));
	}	
}

void RecognizeForm::CloseDeivce()
{
	// �Ͽ��豸����
	if (_dev.CloseDevice())
	{
		ui.pushButton_Open->setEnabled(true);
		ui.pushButton_StartScan->setEnabled(false);
		ui.pushButton_StopScan->setEnabled(false);
		ui.pushButton_Close->setEnabled(false);
	}
	else
	{
	QMessageBox::critical(this, QStringLiteral("Error"), QStringLiteral("OCR�Ķ����ر�ʧ�ܣ�"));
	}
}



void RecognizeForm::OnDeviceInfoChanged(cs200::eDeviceInfo info)
{
}

void RecognizeForm::OnDeviceImageGenerated(uchar * fImgBuf, int fBufLen, uchar * bImgBuf, int bBufLen)
{
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
//����ComboBox������Ŀ�ļ��
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
		ui.TextBox_BinarizeThreshold->setText(u8"�Զ�");
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
		_dev.GetDevCfg()->ReadFromFile(cfgFile.fileName());
	else
		_dev.GetDevCfg()->SaveToFile(cfgFile.fileName());
	// ��ʼ��
	if (!_dev.Initialize())
	{
		QMessageBox::critical(this, QStringLiteral("Error"), QStringLiteral("OCR�Ķ�����ʼ��ʧ�ܣ�"));
		return;
	}
}



/***************************************
*�������ܣ��豸����ѡ��ComboBox�ۺ�����
*���룺
*	currentIndex����ǰѡ����Ŀ������
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-24-V1.0
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
*�������ܣ��Ķ�ֽ��λ��ѡ��ComboBox�ۺ����������ǰ��ѡ���������ļ��в�һ�£����޸������ļ���
*���룺
*	currentIndex����ǰѡ����Ŀ������
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-24-V1.0
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