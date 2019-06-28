#include "qrcodebuilder.h"

//静态成员变量初始化
unsigned QRcodeBuilder::s_buildCount = 0;
//构造函数
QRcodeBuilder::QRcodeBuilder(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//设置title
	setWindowTitle(QString::fromLocal8Bit("图像工具"));


	//成员变量配置初始化
	simpleCodeOrQRCode = 0;//判断生成简单码还是二维码，0--简单码，1--二维码，默认简单码
	oldSelectedImage = new QImage;//以前选择的图片
	cursorNowOn = new QImage;//新选择的图片
	oldSelectLabelName = new QString("");//上一次选择的LabelName
	newSelectLabelName = new QString("");//当前选择的LabelName
	voteID = new QString("0");//选票ID
	appExeFolder = new QString(QCoreApplication::applicationDirPath());//"G:\Qt\Qt5.12.1\User\CasitMark SDK\x64\Debug"
	appConfig = new AppConfig;//XML文件配置读取
	//appConfig->insertXMLElement((*appExeFolder) + "/AppConfig.xml");
	appConfig->readXMLElement((*appExeFolder) + "/AppConfig.xml");//已验证，能读出，且存在appConfig的公有成员变量里。

	//控件配置初始化
	ui.button_Copy->setEnabled(false);
	ui.RadioButton_QRCode->setChecked(false);
	ui.RadioButton_SimpleCode->setChecked(true);
	ui.text0->setEnabled(false);
	ui.text1->setEnabled(false);
	ui.text2->setEnabled(false);
	ui.text3->setEnabled(false);
	ui.text4->setEnabled(false);
	ui.text5->setEnabled(false);
	ui.frame_image0->setContentsMargins(appConfig->CodePixelMargin, appConfig->CodePixelMargin, appConfig->CodePixelMargin, appConfig->CodePixelMargin);
	ui.frame_image1->setContentsMargins(appConfig->CodePixelMargin, appConfig->CodePixelMargin, appConfig->CodePixelMargin, appConfig->CodePixelMargin);
	ui.frame_image2->setContentsMargins(appConfig->CodePixelMargin, appConfig->CodePixelMargin, appConfig->CodePixelMargin, appConfig->CodePixelMargin);
	ui.frame_image3->setContentsMargins(appConfig->CodePixelMargin, appConfig->CodePixelMargin, appConfig->CodePixelMargin, appConfig->CodePixelMargin);
	ui.frame_image4->setContentsMargins(appConfig->CodePixelMargin, appConfig->CodePixelMargin, appConfig->CodePixelMargin, appConfig->CodePixelMargin);
	ui.frame_image5->setContentsMargins(appConfig->CodePixelMargin, appConfig->CodePixelMargin, appConfig->CodePixelMargin, appConfig->CodePixelMargin);
	//ui.frame_image0->setContentsMargins(5, 5, 5, 5);
	//ui.frame_image1->setContentsMargins(5, 5, 5, 5);
	//ui.frame_image2->setContentsMargins(5, 5, 5, 5);
	//ui.frame_image3->setContentsMargins(5, 5, 5, 5);
	//ui.frame_image4->setContentsMargins(5, 5, 5, 5);
	//ui.frame_image5->setContentsMargins(5, 5, 5, 5);

	//自定义信号与槽函数链接初始化
	connect(ui.image0, SIGNAL(clicked()), this, SLOT(on_MyLabel_clicked()));
	connect(ui.image1, SIGNAL(clicked()), this, SLOT(on_MyLabel_clicked()));
	connect(ui.image2, SIGNAL(clicked()), this, SLOT(on_MyLabel_clicked()));
	connect(ui.image3, SIGNAL(clicked()), this, SLOT(on_MyLabel_clicked()));
	connect(ui.image4, SIGNAL(clicked()), this, SLOT(on_MyLabel_clicked()));
	connect(ui.image5, SIGNAL(clicked()), this, SLOT(on_MyLabel_clicked()));

	//第一次运行界面时的初始化
	if (ui.RadioButton_QRCode->isChecked())
	{
		this->resize(952, 720);//二维码
		CreateDirectory((*appExeFolder) + "/QRCodes");//创建一个存放二维码图片的文件夹
		s_buildCount = 0;
		simpleCodeOrQRCode = 1;
	}
	else
	{
		this->resize(952, 307);//简单码
		CreateDirectory((*appExeFolder) + "/SimpleCodes");//创建一个存放SimpleCodes图片的文件夹
		s_buildCount = 0;
		simpleCodeOrQRCode = 0;
	}

	//第一次运行界面时的要直接显示
	button_Build_Click();
}

//程序析构函数，释放内存
QRcodeBuilder::~QRcodeBuilder()
{
	if (oldSelectedImage != nullptr)
	{
		delete oldSelectedImage;
	}
	if (cursorNowOn != nullptr)
	{
		delete cursorNowOn;
	}
	if (oldSelectLabelName != nullptr)
	{
		delete oldSelectLabelName;
	}
	if (newSelectLabelName != nullptr)
	{
		delete newSelectLabelName;
	}
	if (voteID != nullptr)
	{
		delete voteID;
	}
	if (appExeFolder != nullptr)
	{
		delete appExeFolder;
	}
	if (appConfig != nullptr)
	{
		delete appConfig;
	}
	oldSelectedImage = nullptr;
	cursorNowOn = nullptr;
	oldSelectLabelName = nullptr;
	newSelectLabelName = nullptr;
	voteID = nullptr;
	appExeFolder = nullptr;
	appConfig = nullptr;
}


/**************************************
*函数功能：定位方式二：简单码，按钮检测
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-11-V2.0
***************************************/
void QRcodeBuilder::RadioButton_SimpleCode_Checked()//定位方式一
{
	this->resize(952, 307);//简单码
	CreateDirectory((*appExeFolder) + "/SimpleCodes");//创建一个存放SimpleCodes图片的文件夹
	s_buildCount = 0;
	simpleCodeOrQRCode = 0;
	button_Build_Click();
}


/**************************************
*函数功能：定位方式一：二维码，按钮检测
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-11-V2.0
***************************************/
void QRcodeBuilder::RadioButton_QRCode_Checked()//定位方式二
{
	this->resize(952, 720);//二维码
	//this->resize(1011, 800);
	CreateDirectory((*appExeFolder) + "/QRCodes");//创建一个存放二维码图片的文件夹
	s_buildCount = 0;
	simpleCodeOrQRCode = 1;
	button_Build_Click();
}


/***************************************
*函数功能：复制选中图像按钮
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-11-V2.0
***************************************/
void QRcodeBuilder::button_Copy_Click()
{
	if (*oldSelectLabelName == "")
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("没有选择的图片！"));
		return;
	}
	int n = atoi((&((*oldSelectLabelName).toStdString())[((*oldSelectLabelName).size() - 1)]));
	//qDebug() << "n = " << n;

	int PixelSizeLength = 0;
	int PixelSizeWidth = 0;
	if (simpleCodeOrQRCode == 0)
	{//简单码
		PixelSizeLength = appConfig->SimpleCodePixelSizeLength;
		PixelSizeWidth = appConfig->SimpleCodePixelSizeWidth;
	}
	else
	{//二维码
		PixelSizeLength = appConfig->QRcodePixelSize;
		PixelSizeWidth = appConfig->QRcodePixelSize;
	}

	QPixmap pix;
	QImage image;
	switch (n)
	{
	case 0:
		//控件截图并存放到clipboard
		//pix = QWidget::grab(ui.frame_image0->rect());
		pix = QPixmap::grabWidget(ui.frame_image0);
		image = pix.toImage().scaled(PixelSizeLength, PixelSizeWidth);
		qDebug() << image.size();
		QApplication::clipboard()->setImage(image);
		//QApplication::clipboard()->setPixmap(pix);
		break;
	case 1:
		//控件截图并存放到clipboard
		//pix = QWidget::grab(ui.frame_image1->rect());
		pix = QPixmap::grabWidget(ui.frame_image1);
		image = pix.toImage().scaled(PixelSizeLength, PixelSizeWidth);
		//qDebug() << image.size();
		QApplication::clipboard()->setImage(image);
		break;
	case 2:
		//控件截图并存放到clipboard
		//pix = QWidget::grab(ui.frame_image2->rect());
		pix = QPixmap::grabWidget(ui.frame_image2);
		image = pix.toImage().scaled(PixelSizeLength, PixelSizeWidth);
		//qDebug() << image.size();
		QApplication::clipboard()->setImage(image);
		break;
	case 3:
		//控件截图并存放到clipboard
		//pix = QWidget::grab(ui.frame_image3->rect());
		pix = QPixmap::grabWidget(ui.frame_image3);
		image = pix.toImage().scaled(PixelSizeLength, PixelSizeWidth);
		//qDebug() << image.size();
		QApplication::clipboard()->setImage(image);
		break;
	case 4:
		//控件截图并存放到clipboard
		//pix = QWidget::grab(ui.frame_image4->rect());
		pix = QPixmap::grabWidget(ui.frame_image4);
		image = pix.toImage().scaled(PixelSizeLength, PixelSizeWidth);
		//qDebug() << image.size();
		QApplication::clipboard()->setImage(image);
		break;
	case 5:
		//控件截图并存放到clipboard
		//pix = QWidget::grab(ui.frame_image5->rect());
		pix = QPixmap::grabWidget(ui.frame_image5);
		image = pix.toImage().scaled(PixelSizeLength, PixelSizeWidth);
		//qDebug() << image.size();
		QApplication::clipboard()->setImage(image);
		break;
	default:
		return;
		break;
	}
}


/***************************************
*函数功能：重新生成图片按钮
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-11-V2.0
***************************************/
void QRcodeBuilder::button_Build_Click()
{
	if (ui.voteID->text().toInt() >= pow(2, appConfig->SimplecodeLen - 1))
	{//输入选票ID过大，请输入[0,pow(2,appConfig->SimplecodeLen-1))之间的数
		QString maxvoteIDMessage = (QStringLiteral("输入选票ID过大，请输入区间[0,") + QString::number(pow(2, appConfig->SimplecodeLen - 1)) + QStringLiteral(")之内的数！"));
		QMessageBox::warning(this, QString::fromLocal8Bit("错误"), maxvoteIDMessage);
		return;
	}

	//将用户输入的ID值赋给变量
	*voteID = ui.voteID->text();

	//生成图片
	QImage image0;
	QImage image1;
	QImage image2;
	QImage image3;
	QImage image4;
	QImage image5;
	int PixelSizeLength = 0;//图片像素大小
	int PixelSizeWidth = 0;//图片像素大小
	if (simpleCodeOrQRCode == 0)
	{//生成简单码
		//qDebug() << (ui.voteID->text() + "-" + QString::number((s_buildCount), 10));
		image0 = GenerateSimpleCodeImage();//Qt已经重载过等号操作符
		image1 = GenerateSimpleCodeImage();
		image2 = GenerateSimpleCodeImage();
		image3 = GenerateSimpleCodeImage();
		image4 = GenerateSimpleCodeImage();
		image5 = GenerateSimpleCodeImage();
		PixelSizeLength = appConfig->SimpleCodePixelSizeLength;
		PixelSizeWidth = appConfig->SimpleCodePixelSizeWidth;
	}
	else
	{//生成二维码
		//qDebug() << (ui.voteID->text() + "-" + QString::number((s_buildCount) , 10));
		image0 = GenerateQRCodeImage((ui.voteID->text() + "-" + QString::number((s_buildCount), 10)));
		image1 = GenerateQRCodeImage((ui.voteID->text() + "-" + QString::number((s_buildCount), 10)));
		image2 = GenerateQRCodeImage((ui.voteID->text() + "-" + QString::number((s_buildCount), 10)));
		image3 = GenerateQRCodeImage((ui.voteID->text() + "-" + QString::number((s_buildCount), 10)));
		image4 = GenerateQRCodeImage((ui.voteID->text() + "-" + QString::number((s_buildCount), 10)));
		image5 = GenerateQRCodeImage((ui.voteID->text() + "-" + QString::number((s_buildCount), 10)));
		PixelSizeLength = appConfig->QRcodePixelSize;
		PixelSizeWidth = appConfig->QRcodePixelSize;
	}

	//显示图片
	ShowCodeImage(image0, ui.image0, appConfig->SimplecodeWriteText, (ui.voteID->text() + "-" + QString::number((s_buildCount + 6) % 12, 10)), ui.text0);
	ShowCodeImage(image1, ui.image1, appConfig->SimplecodeWriteText, (ui.voteID->text() + "-" + QString::number((s_buildCount + 7) % 12, 10)), ui.text1);
	ShowCodeImage(image2, ui.image2, appConfig->SimplecodeWriteText, (ui.voteID->text() + "-" + QString::number((s_buildCount + 8) % 12, 10)), ui.text2);
	ShowCodeImage(image3, ui.image3, appConfig->SimplecodeWriteText, (ui.voteID->text() + "-" + QString::number((s_buildCount + 9) % 12, 10)), ui.text3);
	ShowCodeImage(image4, ui.image4, appConfig->SimplecodeWriteText, (ui.voteID->text() + "-" + QString::number((s_buildCount + 10) % 12, 10)), ui.text4);
	ShowCodeImage(image5, ui.image5, appConfig->SimplecodeWriteText, (ui.voteID->text() + "-" + QString::number((s_buildCount + 11) % 12, 10)), ui.text5);

	//保存图片
	QPixmap pix0;
	QPixmap pix1;
	QPixmap pix2;
	QPixmap pix3;
	QPixmap pix4;
	QPixmap pix5;
	//pix0 = QWidget::grab(ui.frame_image0->rect());
	//pix1 = QWidget::grab(ui.frame_image1->rect());
	//pix2 = QWidget::grab(ui.frame_image2->rect());
	//pix3 = QWidget::grab(ui.frame_image3->rect());
	//pix4 = QWidget::grab(ui.frame_image4->rect());
	//pix5 = QWidget::grab(ui.frame_image5->rect());
	pix0 = QPixmap::grabWidget(ui.frame_image0);
	pix1 = QPixmap::grabWidget(ui.frame_image1);
	pix2 = QPixmap::grabWidget(ui.frame_image2);
	pix3 = QPixmap::grabWidget(ui.frame_image3);
	pix4 = QPixmap::grabWidget(ui.frame_image4);
	pix5 = QPixmap::grabWidget(ui.frame_image5);
	image0 = pix0.toImage().scaled(PixelSizeLength, PixelSizeWidth);//调整图片像素大小
	image1 = pix1.toImage().scaled(PixelSizeLength, PixelSizeWidth);
	image2 = pix2.toImage().scaled(PixelSizeLength, PixelSizeWidth);
	image3 = pix3.toImage().scaled(PixelSizeLength, PixelSizeWidth);
	image4 = pix4.toImage().scaled(PixelSizeLength, PixelSizeWidth);
	image5 = pix5.toImage().scaled(PixelSizeLength, PixelSizeWidth);

	QString imageFormat = ".jpg";//保存图片的格式
	if (simpleCodeOrQRCode == 0)//保存简单码图片
	{
		//qDebug() << image5.size();
		SaveCodeImageToFile(image0, ((*appExeFolder) + "/SimpleCodes" + "/SimpleCode" + ui.voteID->text() + "-" + QString::number((s_buildCount + 6) % 12, 10)), imageFormat);
		SaveCodeImageToFile(image1, ((*appExeFolder) + "/SimpleCodes" + "/SimpleCode" + ui.voteID->text() + "-" + QString::number((s_buildCount + 7) % 12, 10)), imageFormat);
		SaveCodeImageToFile(image2, ((*appExeFolder) + "/SimpleCodes" + "/SimpleCode" + ui.voteID->text() + "-" + QString::number((s_buildCount + 8) % 12, 10)), imageFormat);
		SaveCodeImageToFile(image3, ((*appExeFolder) + "/SimpleCodes" + "/SimpleCode" + ui.voteID->text() + "-" + QString::number((s_buildCount + 9) % 12, 10)), imageFormat);
		SaveCodeImageToFile(image4, ((*appExeFolder) + "/SimpleCodes" + "/SimpleCode" + ui.voteID->text() + "-" + QString::number((s_buildCount + 10) % 12, 10)), imageFormat);
		SaveCodeImageToFile(image5, ((*appExeFolder) + "/SimpleCodes" + "/SimpleCode" + ui.voteID->text() + "-" + QString::number((s_buildCount + 11) % 12, 10)), imageFormat);
	}
	else//保存二维码图片
	{
		//qDebug() << image5.size();
		SaveCodeImageToFile(image0, ((*appExeFolder) + "/QRCodes" + "/QRCode" + ui.voteID->text() + "-" + QString::number((s_buildCount + 6) % 12, 10)), imageFormat);
		SaveCodeImageToFile(image1, ((*appExeFolder) + "/QRCodes" + "/QRCode" + ui.voteID->text() + "-" + QString::number((s_buildCount + 7) % 12, 10)), imageFormat);
		SaveCodeImageToFile(image2, ((*appExeFolder) + "/QRCodes" + "/QRCode" + ui.voteID->text() + "-" + QString::number((s_buildCount + 8) % 12, 10)), imageFormat);
		SaveCodeImageToFile(image3, ((*appExeFolder) + "/QRCodes" + "/QRCode" + ui.voteID->text() + "-" + QString::number((s_buildCount + 9) % 12, 10)), imageFormat);
		SaveCodeImageToFile(image4, ((*appExeFolder) + "/QRCodes" + "/QRCode" + ui.voteID->text() + "-" + QString::number((s_buildCount + 10) % 12, 10)), imageFormat);
		SaveCodeImageToFile(image5, ((*appExeFolder) + "/QRCodes" + "/QRCode" + ui.voteID->text() + "-" + QString::number((s_buildCount + 11) % 12, 10)), imageFormat);
	}
}


/***************************************
*函数功能：MyLabel自定义控件的槽函数
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-11-V2.0
***************************************/
void QRcodeBuilder::on_MyLabel_clicked()
{
	MyLabel *senderLabel = dynamic_cast<MyLabel*>(QObject::sender());//当前点击的Label
	QGroupBox *senderGroupBox = dynamic_cast<QGroupBox*>(senderLabel->parent()->parent());//当前点击的Label的基类，即当前点击的QGroupBox
	*newSelectLabelName = senderLabel->objectName();//更新
	if (*oldSelectLabelName == "")//第一次选择
	{
		senderGroupBox->setStyleSheet("QGroupBox{border:1px solid red;}");
		//senderGroupBox->setStyleSheet("border:none");
		senderLabel->setFrameShadow(QFrame::Sunken);//Sunken  下降
		*oldSelectLabelName = senderLabel->objectName();//更新
		senderLabel = nullptr;
		ui.button_Copy->setEnabled(true);
		return;
	}
	else//不是第一次选择
	{
		if (*oldSelectLabelName == *newSelectLabelName)//再次点击同一个控件，即取消选择
		{
			*oldSelectLabelName = "";
			*newSelectLabelName = "";
			//当前控件Label还原样式
			senderGroupBox->setStyleSheet("QGroupBox{}");
			senderLabel->setFrameShadow(QFrame::Raised);//Raised  上浮
			senderLabel = nullptr;
			ui.button_Copy->setEnabled(false);
			return;
		}
		else//点击一个新的控件
		{
			//旧的控件
			MyLabel *oldSelectLabel = ui.centralWidget->findChild<MyLabel *>(*oldSelectLabelName);
			QGroupBox *oldGroupBox = dynamic_cast<QGroupBox*>(oldSelectLabel->parent()->parent());//上一次的QGroupBox
			oldGroupBox->setStyleSheet("QGroupBox{}");
			oldSelectLabel->setFrameShadow(QFrame::Raised);//Raised  上浮
			oldSelectLabel = nullptr;
			oldGroupBox = nullptr;
			//新的控件--信号发送者
			senderGroupBox->setStyleSheet("QGroupBox{border:1px solid red;}");
			senderLabel->setFrameShadow(QFrame::Sunken);//Sunken  下降
			*oldSelectLabelName = senderLabel->objectName();//更新
			senderLabel = nullptr;
			ui.button_Copy->setEnabled(true);
			return;
		}
	}
}


/***************************************
*函数功能：产生一张简单码的图片
*输入：
*	void
*输出：
*	QImage:返回一张简单码的图片，返回局部变量对象，而非地址
*作者：JZQ
*时间版本：2019-06-11-V2.0
***************************************/
QImage QRcodeBuilder::GenerateSimpleCodeImage()
{
	//图片有（appConfig->SimplecodeLen-1）+ 2(起始结束两列)列，只有2行
	QImage image(240, 40, QImage::Format_RGB888);//局部变量，匿名对象扶正，用匿名对象去初始化，而不是赋值（=）。
	image.fill(QColor(Qt::white).rgb());

	//先处理起始结束两列的像素。
	for (int i = 0; i < image.height(); i++)
	{
		for (int j = 0; j < image.width() / ((appConfig->SimplecodeLen - 1 + 2) * 2); j++)
		{
			//图片左侧改变，不存在对齐问题，但效率降低
			image.setPixelColor(j, i, QColor(Qt::black));
		}
		for (int j = image.width() * ((appConfig->SimplecodeLen - 1 + 2) * 2 - 1) / ((appConfig->SimplecodeLen - 1 + 2) * 2); j < image.width(); j++)
		{
			//图片右侧改变，不存在对齐问题，但效率降低
			image.setPixelColor(j, i, QColor(Qt::black));
		}
	}

	//再处理剩余列（appConfig->SimplecodeLen-1），第一行，根据选票ID来处理。
	int begin_N = 0;
	int end_N = 0;
	string theFirstLine = QStringToStdstringWithLength(QString::number(ui.voteID->text().toInt(), 2), appConfig->SimplecodeLen - 1);
	for (int x = 0; theFirstLine[x] != '\0'; x++)
	{//画块
		if (theFirstLine[x] == '1')
		{
			begin_N = (image.width() / (appConfig->SimplecodeLen - 1 + 2)) * (x + 1);
			end_N = begin_N + (image.width() / (appConfig->SimplecodeLen - 1 + 2));
			for (int i = 0; i < image.height() / 2; i++)//第一行
			{
				for (int j = begin_N; j < end_N; j++)
				{//每次只处理一列。
					image.setPixelColor(j, i, QColor(Qt::black));
				}
			}
		}
	}

	//再处理剩余列（appConfig->SimplecodeLen-1），第二行，页码，安序生成6张[0,5]或[6,11]
	string theSecondLine = QStringToStdstringWithLength(QString::number(s_buildCount, 2), appConfig->SimplecodeLen - 1);//产生随机数，来随机生成图片
	for (int x = 0; theSecondLine[x] != '\0'; x++)
	{//画块
		if (theSecondLine[x] == '1')
		{
			begin_N = (image.width() / (appConfig->SimplecodeLen - 1 + 2)) * (x + 1);
			end_N = begin_N + (image.width() / (appConfig->SimplecodeLen - 1 + 2));
			for (int i = image.height() / 2; i < image.height(); i++)//第二行
			{
				for (int j = begin_N; j < end_N; j++)
				{//每次只处理一列。
					image.setPixelColor(j, i, QColor(Qt::black));
				}
			}
		}
	}
	s_buildCount += 1;//每一次递增1
	if (s_buildCount >= 12)
	{
		s_buildCount = 0;//从0再开始
	}
	return image;
}


/***************************************
*函数功能：产生一张二维码的图片
*输入：
*	data:扫二维码显示的信息
*输出：
*	QImage:返回一张简单码的图片，返回局部变量对象，而非地址
*作者：JZQ
*时间版本：2019-06-11-V2.0
***************************************/
QImage QRcodeBuilder::GenerateQRCodeImage(const QString &data)
{
	qrcodegen::QrCode qrCode = qrcodegen::QrCode::encodeText(data.toUtf8().constData(), qrcodegen::QrCode::Ecc::LOW);
	const int qrCodeSize = qrCode.getSize() > 0 ? qrCode.getSize() : 1;//大小由data而定
	float scale = appConfig->QRcodePixelSize / qrCodeSize;//用户设置图片像素与qrCodeSize的缩放比例。

	QImage image(qrCodeSize, qrCodeSize, QImage::Format_RGB888);
	image.fill(QColor(Qt::white).rgb());

	for (int y = 0; y < qrCodeSize; y++) {
		for (int x = 0; x < qrCodeSize; x++) {
			/*
			bool getModule(int x, int y)
			返回给定坐标下模块(像素)的颜色，白色为false，黑色为true。左上角有坐标(x=0, y=0)。如果给定的坐标超出界限，则返回false(白色)。
			*/
			const int color = qrCode.getModule(x, y); // 0 for white, 1 for black
			if (0 != color)
			{
				image.setPixelColor(x, y, QColor(Qt::black));
			}
		}
	}
	s_buildCount += 1;//每一次递增1
	if (s_buildCount >= 12)
	{
		s_buildCount = 0;//从0再开始
	}

	image = image.scaled(240, 240);
	//qDebug() << "image_r.rect().height() = " << image_r.rect().height();
	return image;
}


/***************************************
*函数功能：将一张图片显示到控件imageLabel上
*输入：
*	image:需要显示的图片
*	imageLabel:显示图片的控件
*	writeText:是否需要在图片下方写文字
*	text:需要显示的文字，文字格式:X-X；第一个X代表选票ID，第二个X代表页码
*	textLabel:显示文字的控件
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-11-V2.0
***************************************/
void QRcodeBuilder::ShowCodeImage(const QImage &image, QLabel *imageLabel, bool writeText, const QString &text, QLabel *textLabel)
{
	//显示图片
	imageLabel->setScaledContents(true);
	QSize resize = imageLabel->rect().size();
	imageLabel->setPixmap(QPixmap::fromImage(image).scaled(resize));

	//显示文字
	if (writeText)
	{
		textLabel->setEnabled(true);
		textLabel->setText(text);
	}
	else
	{
		textLabel->setEnabled(false);
		textLabel->setText("");
	}
}


/***************************************
*函数功能：保存生成的图片到文件夹下，并取不同的名字
*输入：
*	image:需要保存的图片
*	filePath:保存图片的路径
*	imageFormat:图片保存的格式
*输出：
*	void
*作者：JZQ
*时间版本：2019-05-29-V1.0
***************************************/
void QRcodeBuilder::SaveCodeImageToFile(QImage & image, const QString & filePath, const QString & imageFormat)
{
	//将图片保存到路径：filePath，
	//qDebug() << "savefilePath:" << (filePath + imageFormat);
	QFile file(filePath + imageFormat);
	if (!file.open(QIODevice::ReadWrite))
	{
		//qDebug() << QString::fromLocal8Bit("打开文件失败！");
		QMessageBox::warning(this, QStringLiteral("错误"), QStringLiteral("图片保存失败！"));
		return;
	}
	QByteArray data;
	QBuffer buffer(&data);
	buffer.open(QIODevice::WriteOnly);
	image.save(&buffer, "jpg");//需要保存的格式imageFormat.toStdString().c_str()
	file.write(data);
	file.close();
	buffer.close();
}


/***************************************
*函数功能：QString型二进制转变成string型二进制，并且固定位宽为：length，高位补零
*输入：
*	num:需要转换的QString型二进制
*	length:固定位宽的长度
*输出：
*	string:转换后的具有length位宽的string型二进制
*作者：JZQ
*时间版本：2019-05-28-V1.0
***************************************/
string QRcodeBuilder::QStringToStdstringWithLength(QString num, int length)
{
	int renderSize = 0;
	renderSize = length - num.size();
	char* ch = new char[length + 1];//使用完要释放
	memset(ch, '0', length + 1);
	for (int j = 0; j < num.size(); j++)
	{
		ch[j + renderSize] = num.toStdString()[j];
	}
	ch[length] = '\0';//填补末尾

	string ret(ch);
	delete[] ch;
	return ret;
}


/***************************************
*函数功能：创建新的文件夹，若文件夹存在，则删除后再新建；若不存在，直接新建
*输入：
*	filePath:文件夹地址
*输出：
*	void
*作者：JZQ
*时间版本：2019-05-28-V1.0
***************************************/
void QRcodeBuilder::CreateDirectory(const QString & filePath)
{
	QString dir_str = filePath;
	QDir dir;
	if (dir.exists(dir_str))// 检查目录是否存在，若存在则删除后再新建
	{
		if (!DeleteDirectory(dir_str))
		{
			//文件夹未删除成功
			QMessageBox::warning(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("文件夹未删除成功！"));
			return;
		}
		if (!dir.mkpath(dir_str))
		{
			//文件夹未创建成功
			QMessageBox::warning(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("文件夹未创建成功！"));
			return;
		}
	}
	else// 若不存在则直接新建
	{
		if (!dir.mkpath(dir_str))
		{
			//文件夹未创建成功
			QMessageBox::warning(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("文件夹未创建成功！"));
			return;
		}
	}
}


/***************************************
*函数功能：删除文件夹，及其下面的所有内容
*输入：
*	filePath:文件夹地址
*输出：
*	void
*作者：JZQ
*时间版本：2019-05-28-V1.0
***************************************/
bool QRcodeBuilder::DeleteDirectory(const QString & filePath)
{
	if (filePath.isEmpty()) {
		return false;
	}
	QDir dir(filePath);
	if (!dir.exists()) {
		return true;
	}
	dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot); //设置过滤
	QFileInfoList fileList = dir.entryInfoList(); // 获取所有的文件信息
	foreach(QFileInfo file, fileList) { //遍历文件信息
		if (file.isFile()) { // 是文件，删除
			file.dir().remove(file.fileName());
		}
		else { // 递归删除
			DeleteDirectory(file.absoluteFilePath());
		}
	}
	return dir.rmpath(dir.absolutePath()); // 删除文件夹
}


