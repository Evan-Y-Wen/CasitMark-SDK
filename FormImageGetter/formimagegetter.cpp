#include "formimagegetter.h"

FormImageGetter::FormImageGetter(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//����title
	setWindowTitle(QString::fromLocal8Bit("ͼ���ȡ"));


	//�ؼ����ó�ʼ��
	//���Ͻǣ�����ComboBox������Ŀ�ļ��
	ui.ComboBox_ImageType->setView(new QListView());
	ui.ComboBox_DeviceCount->setView(new QListView());
	ui.ComboBox_Position->setView(new QListView());
	ui.ComboBox_Light->setView(new QListView());
	ui.Label_Pages1->setText(QStringLiteral("0��"));
	//���½ǣ�ͼ�����Կؼ�
	ui.Label_FileName->setText("");
	ui.Label_ImageType->setText("");
	ui.Label_ImageSize->setText("");
	ui.Label_ImageFolder->setText("");
	ui.Label_FileSize->setText("");
	//���Ͻǣ�ͼ���б�ؼ�
	ui.groupBox_ListTitle->setTitle(QStringLiteral("ͼ���б� ������0��"));
	ui.groupBox_image1->setVisible(false);
	ui.groupBox_image2->setVisible(false);
	ui.groupBox_image3->setVisible(false);
	ui.groupBox_image4->setVisible(false);

	//��Ա�������ó�ʼ��
	appExeFolder = new QString(QCoreApplication::applicationDirPath());//"G:\Qt\Qt5.12.1\User\CasitMark SDK\x64\Debug"
	appConfig = new AppConfig;//XML�ļ����ö�ȡ
	appConfig->readXMLElement((*appExeFolder) + "/AppConfig.xml");//����֤���ܶ������Ҵ���appConfig�Ĺ��г�Ա�����
	switch (appConfig->LastSelectedDevice)
	{
	case 0:
		ui.GroupBox_TWAIN->setVisible(false);
		ui.CheckBox_IsRectify->setVisible(false);
		break;
	case 1:
		ui.GroupBox_TWAIN->setVisible(false);
		ui.GroupBox_Scanner->setTitle("OCR�Ķ���");
		break;
	case 2:
		ui.GroupBox_Scanner->setVisible(false);
		break;
	default:
		ui.GroupBox_TWAIN->setVisible(false);
		ui.CheckBox_IsRectify->setVisible(false);
		break;
	}
	ui.TextBox_ImageFileNamePrefix->setText(appConfig->ImageFilePrefix);
	ui.TextBox_ImageSaveFolder->setPlainText(appConfig->ImageSaveFolder.mid(appConfig->ImageSaveFolder.lastIndexOf('/') + 1));
	ui.TextBox_ImageSaveFolder->setToolTip(appConfig->ImageSaveFolder);
	ui.CheckBox_IsRectify->setChecked(appConfig->IsRectify);
	ui.ComboBox_Position->setCurrentIndex((int)appConfig->ScanPosition);
	ui.ComboBox_Light->setCurrentIndex((int)appConfig->OCRLightColor);
	ui.ComboBox_ImageType->setCurrentIndex((int)appConfig->ImageFileType);
	switch (appConfig->ImageFileType)
	{
	case 0:
		ImageType = ".jpg";
		break;
	case 1:
		ImageType = ".bmp";
		break;
	case 2:
		ImageType = ".png";
		break;
	case 3:
		ImageType = ".tiff";
		break;
	}
	connect(ui.ComboBox_Position, SIGNAL(currentIndexChanged(int)), this, SLOT(ComboBox_Position_SelectionChanged()));
	connect(ui.ComboBox_Light, SIGNAL(currentIndexChanged(int)), this, SLOT(ComboBox_Light_SelectionChanged()));
	connect(ui.ComboBox_ImageType, SIGNAL(currentIndexChanged(int)), this, SLOT(ComboBox_ImageType_SelectionChanged()));

	// ��ʼ���豸����
	_highSpeedScanner1 = new HighSpeedScanner;
	_isUIInitial = false;
}


/***************************************
*�������ܣ�������ť�ۺ���
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-05-29-V1.0
***************************************/
void FormImageGetter::Button_SelectFolder_Click()
{
	QString FileFormat = "." + ui.ComboBox_ImageType->currentText();//�ؼ���ѡȡ�ĸ�ʽ
	QString FileName = appConfig->ImageFilePrefix + FileFormat;//�ļ�����ͼ��.jpg
	QString FilePathAndName = QFileDialog::getSaveFileName(this, QStringLiteral("ѡ���ļ���"), FileName);//�ļ���+·����C:/Users/ww/Desktop/V20��ֽ/ͼ��1.jpg
	QString ImageSaveFolder = "";//����·��
	QFileInfo fileInfo(FilePathAndName);//
	if (fileInfo.exists())//exists() �����ж�һ���ļ��Ƿ����
	{
		QFile::remove(FilePathAndName);//�����ˣ�����ɾ����
	}
	ImageSaveFolder = fileInfo.absolutePath();//ֻ��·��
	qDebug() << "FileName: " << FileName;//"ͼ��.jpg"
	qDebug() << "FilePathAndName: " << FilePathAndName;//"C:/Users/ww/Desktop/V20��ֽ/ͼ��.jpg"
	qDebug() << "ImageSaveFolder: " << ImageSaveFolder;//"C:/Users/ww/Desktop/V20��ֽ"

	appConfig->ImageSaveFolder = ImageSaveFolder;
	//AppConfig.CurrentConfig.Save();//����δʵ��******************************����δʵ��**********************************����δʵ��*******************����δʵ��
	ui.TextBox_ImageFileNamePrefix->setText(appConfig->ImageFilePrefix);
	ui.TextBox_ImageSaveFolder->setPlainText(ImageSaveFolder.mid(ImageSaveFolder.lastIndexOf('/') + 1));
	ui.TextBox_ImageSaveFolder->setToolTip(ImageSaveFolder);
}


/***************************************
*�������ܣ���ʼ�Ķ���ť
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-05-28-V1.0
***************************************/
void FormImageGetter::Button_ScannerStart1_Click()
{
	/*
	if (appConfig->LastSelectedDevice == 0)//0-����ɨ����
	{
		if (!_highSpeedScanner1.Initial(0))
			MetroStyleMessageBox.ShowMessageBox_Ok(this, "�����Ķ��ǳ�ʼ��ʧ�ܣ�", "Error");
		else
		{
			if (_highSpeedScanner1.StartSanner())
			{
				// �����Ķ���
				Label_Pages1.Content = "0��";
				Button_ScannerStart1.IsEnabled = false;
				Button_ScannerContinue1.IsEnabled = false;
				_highSpeedScanner1.CurrentSannedImagesCount = 0;
				SetIsEnableProperty(false);
			}
			else
				MetroStyleMessageBox.ShowMessageBox_Ok(this, "����ʧ�ܣ�", "Error");
		}
	}
	else if (appConfig->LastSelectedDevice == 1)//1 - OCR�Ķ���
	{
	}
	else if (appConfig->LastSelectedDevice == 2)//2-TWAIN	
	{
	}
	else//3-KVSLɨ����	
	{
	}*/
}


/***************************************
*�������ܣ������Ķ���ť
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-05-28-V1.0
***************************************/
void FormImageGetter::Button_ScannerContinue1_Click()
{
}

void FormImageGetter::ComboBox_Position_SelectionChanged()
{
	qDebug() << "ScanPosition: " << ui.ComboBox_Position->currentIndex();
	qDebug() << "ScanPosition: " << ui.ComboBox_Position->currentText();
}

void FormImageGetter::ComboBox_Light_SelectionChanged()
{
	qDebug() << "LightColor: " << ui.ComboBox_Light->currentIndex();
	qDebug() << "LightColor: " << ui.ComboBox_Light->currentText();
}

void FormImageGetter::ComboBox_ImageType_SelectionChanged()
{
	qDebug() << "ImageType: " << ui.ComboBox_ImageType->currentIndex();
	qDebug() << "ImageType: " << ui.ComboBox_ImageType->currentText();
}
