#include "formimagegetter.h"

FormImageGetter::FormImageGetter(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//设置title
	setWindowTitle(QString::fromLocal8Bit("图像获取"));


	//控件配置初始化
	//左上角：调整ComboBox下拉项目的间隔
	ui.ComboBox_ImageType->setView(new QListView());
	ui.ComboBox_DeviceCount->setView(new QListView());
	ui.ComboBox_Position->setView(new QListView());
	ui.ComboBox_Light->setView(new QListView());
	ui.Label_Pages1->setText(QStringLiteral("0张"));
	//左下角：图像属性控件
	ui.Label_FileName->setText("");
	ui.Label_ImageType->setText("");
	ui.Label_ImageSize->setText("");
	ui.Label_ImageFolder->setText("");
	ui.Label_FileSize->setText("");
	//右上角：图像列表控件
	ui.groupBox_ListTitle->setTitle(QStringLiteral("图像列表 总数：0张"));
	ui.groupBox_image1->setVisible(false);
	ui.groupBox_image2->setVisible(false);
	ui.groupBox_image3->setVisible(false);
	ui.groupBox_image4->setVisible(false);

	//成员变量配置初始化
	appExeFolder = new QString(QCoreApplication::applicationDirPath());//"G:\Qt\Qt5.12.1\User\CasitMark SDK\x64\Debug"
	appConfig = new AppConfig;//XML文件配置读取
	appConfig->readXMLElement((*appExeFolder) + "/AppConfig.xml");//已验证，能读出，且存在appConfig的公有成员变量里。
	switch (appConfig->LastSelectedDevice)
	{
	case 0:
		ui.GroupBox_TWAIN->setVisible(false);
		ui.CheckBox_IsRectify->setVisible(false);
		break;
	case 1:
		ui.GroupBox_TWAIN->setVisible(false);
		ui.GroupBox_Scanner->setTitle("OCR阅读机");
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

	// 初始化设备对象
	_highSpeedScanner1 = new HighSpeedScanner;
	_isUIInitial = false;
}


/***************************************
*函数功能：游览按钮槽函数
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-05-29-V1.0
***************************************/
void FormImageGetter::Button_SelectFolder_Click()
{
	QString FileFormat = "." + ui.ComboBox_ImageType->currentText();//控件上选取的格式
	QString FileName = appConfig->ImageFilePrefix + FileFormat;//文件名：图像.jpg
	QString FilePathAndName = QFileDialog::getSaveFileName(this, QStringLiteral("选择文件夹"), FileName);//文件名+路径：C:/Users/ww/Desktop/V20壁纸/图像1.jpg
	QString ImageSaveFolder = "";//绝对路径
	QFileInfo fileInfo(FilePathAndName);//
	if (fileInfo.exists())//exists() 函数判断一个文件是否存在
	{
		QFile::remove(FilePathAndName);//存在了，就先删除。
	}
	ImageSaveFolder = fileInfo.absolutePath();//只有路径
	qDebug() << "FileName: " << FileName;//"图像.jpg"
	qDebug() << "FilePathAndName: " << FilePathAndName;//"C:/Users/ww/Desktop/V20壁纸/图像.jpg"
	qDebug() << "ImageSaveFolder: " << ImageSaveFolder;//"C:/Users/ww/Desktop/V20壁纸"

	appConfig->ImageSaveFolder = ImageSaveFolder;
	//AppConfig.CurrentConfig.Save();//这里未实现******************************这里未实现**********************************这里未实现*******************这里未实现
	ui.TextBox_ImageFileNamePrefix->setText(appConfig->ImageFilePrefix);
	ui.TextBox_ImageSaveFolder->setPlainText(ImageSaveFolder.mid(ImageSaveFolder.lastIndexOf('/') + 1));
	ui.TextBox_ImageSaveFolder->setToolTip(ImageSaveFolder);
}


/***************************************
*函数功能：开始阅读按钮
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-05-28-V1.0
***************************************/
void FormImageGetter::Button_ScannerStart1_Click()
{
	/*
	if (appConfig->LastSelectedDevice == 0)//0-高速扫描仪
	{
		if (!_highSpeedScanner1.Initial(0))
			MetroStyleMessageBox.ShowMessageBox_Ok(this, "高速阅读仪初始化失败！", "Error");
		else
		{
			if (_highSpeedScanner1.StartSanner())
			{
				// 启动阅读仪
				Label_Pages1.Content = "0张";
				Button_ScannerStart1.IsEnabled = false;
				Button_ScannerContinue1.IsEnabled = false;
				_highSpeedScanner1.CurrentSannedImagesCount = 0;
				SetIsEnableProperty(false);
			}
			else
				MetroStyleMessageBox.ShowMessageBox_Ok(this, "启动失败！", "Error");
		}
	}
	else if (appConfig->LastSelectedDevice == 1)//1 - OCR阅读机
	{
	}
	else if (appConfig->LastSelectedDevice == 2)//2-TWAIN	
	{
	}
	else//3-KVSL扫描仪	
	{
	}*/
}


/***************************************
*函数功能：继续阅读按钮
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-05-28-V1.0
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
