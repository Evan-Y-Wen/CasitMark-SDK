#include "qrcodebuilder.h"

//��̬��Ա������ʼ��
unsigned QRcodeBuilder::s_buildCount = 0;
//���캯��
QRcodeBuilder::QRcodeBuilder(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//����title
	setWindowTitle(QString::fromLocal8Bit("ͼ�񹤾�"));


	//��Ա�������ó�ʼ��
	simpleCodeOrQRCode = 0;//�ж����ɼ��뻹�Ƕ�ά�룬0--���룬1--��ά�룬Ĭ�ϼ���
	oldSelectedImage = new QImage;//��ǰѡ���ͼƬ
	cursorNowOn = new QImage;//��ѡ���ͼƬ
	oldSelectLabelName = new QString("");//��һ��ѡ���LabelName
	newSelectLabelName = new QString("");//��ǰѡ���LabelName
	voteID = new QString("0");//ѡƱID
	appExeFolder = new QString(QCoreApplication::applicationDirPath());//"G:\Qt\Qt5.12.1\User\CasitMark SDK\x64\Debug"
	appConfig = new AppConfig;//XML�ļ����ö�ȡ
	//appConfig->insertXMLElement((*appExeFolder) + "/AppConfig.xml");
	appConfig->readXMLElement((*appExeFolder) + "/AppConfig.xml");//����֤���ܶ������Ҵ���appConfig�Ĺ��г�Ա�����

	//�ؼ����ó�ʼ��
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

	//�Զ����ź���ۺ������ӳ�ʼ��
	connect(ui.image0, SIGNAL(clicked()), this, SLOT(on_MyLabel_clicked()));
	connect(ui.image1, SIGNAL(clicked()), this, SLOT(on_MyLabel_clicked()));
	connect(ui.image2, SIGNAL(clicked()), this, SLOT(on_MyLabel_clicked()));
	connect(ui.image3, SIGNAL(clicked()), this, SLOT(on_MyLabel_clicked()));
	connect(ui.image4, SIGNAL(clicked()), this, SLOT(on_MyLabel_clicked()));
	connect(ui.image5, SIGNAL(clicked()), this, SLOT(on_MyLabel_clicked()));

	//��һ�����н���ʱ�ĳ�ʼ��
	if (ui.RadioButton_QRCode->isChecked())
	{
		this->resize(952, 720);//��ά��
		CreateDirectory((*appExeFolder) + "/QRCodes");//����һ����Ŷ�ά��ͼƬ���ļ���
		s_buildCount = 0;
		simpleCodeOrQRCode = 1;
	}
	else
	{
		this->resize(952, 307);//����
		CreateDirectory((*appExeFolder) + "/SimpleCodes");//����һ�����SimpleCodesͼƬ���ļ���
		s_buildCount = 0;
		simpleCodeOrQRCode = 0;
	}

	//��һ�����н���ʱ��Ҫֱ����ʾ
	button_Build_Click();
}

//���������������ͷ��ڴ�
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
*�������ܣ���λ��ʽ�������룬��ť���
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-11-V2.0
***************************************/
void QRcodeBuilder::RadioButton_SimpleCode_Checked()//��λ��ʽһ
{
	this->resize(952, 307);//����
	CreateDirectory((*appExeFolder) + "/SimpleCodes");//����һ�����SimpleCodesͼƬ���ļ���
	s_buildCount = 0;
	simpleCodeOrQRCode = 0;
	button_Build_Click();
}


/**************************************
*�������ܣ���λ��ʽһ����ά�룬��ť���
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-11-V2.0
***************************************/
void QRcodeBuilder::RadioButton_QRCode_Checked()//��λ��ʽ��
{
	this->resize(952, 720);//��ά��
	//this->resize(1011, 800);
	CreateDirectory((*appExeFolder) + "/QRCodes");//����һ����Ŷ�ά��ͼƬ���ļ���
	s_buildCount = 0;
	simpleCodeOrQRCode = 1;
	button_Build_Click();
}


/***************************************
*�������ܣ�����ѡ��ͼ��ť
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-11-V2.0
***************************************/
void QRcodeBuilder::button_Copy_Click()
{
	if (*oldSelectLabelName == "")
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("û��ѡ���ͼƬ��"));
		return;
	}
	int n = atoi((&((*oldSelectLabelName).toStdString())[((*oldSelectLabelName).size() - 1)]));
	//qDebug() << "n = " << n;

	int PixelSizeLength = 0;
	int PixelSizeWidth = 0;
	if (simpleCodeOrQRCode == 0)
	{//����
		PixelSizeLength = appConfig->SimpleCodePixelSizeLength;
		PixelSizeWidth = appConfig->SimpleCodePixelSizeWidth;
	}
	else
	{//��ά��
		PixelSizeLength = appConfig->QRcodePixelSize;
		PixelSizeWidth = appConfig->QRcodePixelSize;
	}

	QPixmap pix;
	QImage image;
	switch (n)
	{
	case 0:
		//�ؼ���ͼ����ŵ�clipboard
		//pix = QWidget::grab(ui.frame_image0->rect());
		pix = QPixmap::grabWidget(ui.frame_image0);
		image = pix.toImage().scaled(PixelSizeLength, PixelSizeWidth);
		qDebug() << image.size();
		QApplication::clipboard()->setImage(image);
		//QApplication::clipboard()->setPixmap(pix);
		break;
	case 1:
		//�ؼ���ͼ����ŵ�clipboard
		//pix = QWidget::grab(ui.frame_image1->rect());
		pix = QPixmap::grabWidget(ui.frame_image1);
		image = pix.toImage().scaled(PixelSizeLength, PixelSizeWidth);
		//qDebug() << image.size();
		QApplication::clipboard()->setImage(image);
		break;
	case 2:
		//�ؼ���ͼ����ŵ�clipboard
		//pix = QWidget::grab(ui.frame_image2->rect());
		pix = QPixmap::grabWidget(ui.frame_image2);
		image = pix.toImage().scaled(PixelSizeLength, PixelSizeWidth);
		//qDebug() << image.size();
		QApplication::clipboard()->setImage(image);
		break;
	case 3:
		//�ؼ���ͼ����ŵ�clipboard
		//pix = QWidget::grab(ui.frame_image3->rect());
		pix = QPixmap::grabWidget(ui.frame_image3);
		image = pix.toImage().scaled(PixelSizeLength, PixelSizeWidth);
		//qDebug() << image.size();
		QApplication::clipboard()->setImage(image);
		break;
	case 4:
		//�ؼ���ͼ����ŵ�clipboard
		//pix = QWidget::grab(ui.frame_image4->rect());
		pix = QPixmap::grabWidget(ui.frame_image4);
		image = pix.toImage().scaled(PixelSizeLength, PixelSizeWidth);
		//qDebug() << image.size();
		QApplication::clipboard()->setImage(image);
		break;
	case 5:
		//�ؼ���ͼ����ŵ�clipboard
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
*�������ܣ���������ͼƬ��ť
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-11-V2.0
***************************************/
void QRcodeBuilder::button_Build_Click()
{
	if (ui.voteID->text().toInt() >= pow(2, appConfig->SimplecodeLen - 1))
	{//����ѡƱID����������[0,pow(2,appConfig->SimplecodeLen-1))֮�����
		QString maxvoteIDMessage = (QStringLiteral("����ѡƱID��������������[0,") + QString::number(pow(2, appConfig->SimplecodeLen - 1)) + QStringLiteral(")֮�ڵ�����"));
		QMessageBox::warning(this, QString::fromLocal8Bit("����"), maxvoteIDMessage);
		return;
	}

	//���û������IDֵ��������
	*voteID = ui.voteID->text();

	//����ͼƬ
	QImage image0;
	QImage image1;
	QImage image2;
	QImage image3;
	QImage image4;
	QImage image5;
	int PixelSizeLength = 0;//ͼƬ���ش�С
	int PixelSizeWidth = 0;//ͼƬ���ش�С
	if (simpleCodeOrQRCode == 0)
	{//���ɼ���
		//qDebug() << (ui.voteID->text() + "-" + QString::number((s_buildCount), 10));
		image0 = GenerateSimpleCodeImage();//Qt�Ѿ����ع��ȺŲ�����
		image1 = GenerateSimpleCodeImage();
		image2 = GenerateSimpleCodeImage();
		image3 = GenerateSimpleCodeImage();
		image4 = GenerateSimpleCodeImage();
		image5 = GenerateSimpleCodeImage();
		PixelSizeLength = appConfig->SimpleCodePixelSizeLength;
		PixelSizeWidth = appConfig->SimpleCodePixelSizeWidth;
	}
	else
	{//���ɶ�ά��
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

	//��ʾͼƬ
	ShowCodeImage(image0, ui.image0, appConfig->SimplecodeWriteText, (ui.voteID->text() + "-" + QString::number((s_buildCount + 6) % 12, 10)), ui.text0);
	ShowCodeImage(image1, ui.image1, appConfig->SimplecodeWriteText, (ui.voteID->text() + "-" + QString::number((s_buildCount + 7) % 12, 10)), ui.text1);
	ShowCodeImage(image2, ui.image2, appConfig->SimplecodeWriteText, (ui.voteID->text() + "-" + QString::number((s_buildCount + 8) % 12, 10)), ui.text2);
	ShowCodeImage(image3, ui.image3, appConfig->SimplecodeWriteText, (ui.voteID->text() + "-" + QString::number((s_buildCount + 9) % 12, 10)), ui.text3);
	ShowCodeImage(image4, ui.image4, appConfig->SimplecodeWriteText, (ui.voteID->text() + "-" + QString::number((s_buildCount + 10) % 12, 10)), ui.text4);
	ShowCodeImage(image5, ui.image5, appConfig->SimplecodeWriteText, (ui.voteID->text() + "-" + QString::number((s_buildCount + 11) % 12, 10)), ui.text5);

	//����ͼƬ
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
	image0 = pix0.toImage().scaled(PixelSizeLength, PixelSizeWidth);//����ͼƬ���ش�С
	image1 = pix1.toImage().scaled(PixelSizeLength, PixelSizeWidth);
	image2 = pix2.toImage().scaled(PixelSizeLength, PixelSizeWidth);
	image3 = pix3.toImage().scaled(PixelSizeLength, PixelSizeWidth);
	image4 = pix4.toImage().scaled(PixelSizeLength, PixelSizeWidth);
	image5 = pix5.toImage().scaled(PixelSizeLength, PixelSizeWidth);

	QString imageFormat = ".jpg";//����ͼƬ�ĸ�ʽ
	if (simpleCodeOrQRCode == 0)//�������ͼƬ
	{
		//qDebug() << image5.size();
		SaveCodeImageToFile(image0, ((*appExeFolder) + "/SimpleCodes" + "/SimpleCode" + ui.voteID->text() + "-" + QString::number((s_buildCount + 6) % 12, 10)), imageFormat);
		SaveCodeImageToFile(image1, ((*appExeFolder) + "/SimpleCodes" + "/SimpleCode" + ui.voteID->text() + "-" + QString::number((s_buildCount + 7) % 12, 10)), imageFormat);
		SaveCodeImageToFile(image2, ((*appExeFolder) + "/SimpleCodes" + "/SimpleCode" + ui.voteID->text() + "-" + QString::number((s_buildCount + 8) % 12, 10)), imageFormat);
		SaveCodeImageToFile(image3, ((*appExeFolder) + "/SimpleCodes" + "/SimpleCode" + ui.voteID->text() + "-" + QString::number((s_buildCount + 9) % 12, 10)), imageFormat);
		SaveCodeImageToFile(image4, ((*appExeFolder) + "/SimpleCodes" + "/SimpleCode" + ui.voteID->text() + "-" + QString::number((s_buildCount + 10) % 12, 10)), imageFormat);
		SaveCodeImageToFile(image5, ((*appExeFolder) + "/SimpleCodes" + "/SimpleCode" + ui.voteID->text() + "-" + QString::number((s_buildCount + 11) % 12, 10)), imageFormat);
	}
	else//�����ά��ͼƬ
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
*�������ܣ�MyLabel�Զ���ؼ��Ĳۺ���
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-11-V2.0
***************************************/
void QRcodeBuilder::on_MyLabel_clicked()
{
	MyLabel *senderLabel = dynamic_cast<MyLabel*>(QObject::sender());//��ǰ�����Label
	QGroupBox *senderGroupBox = dynamic_cast<QGroupBox*>(senderLabel->parent()->parent());//��ǰ�����Label�Ļ��࣬����ǰ�����QGroupBox
	*newSelectLabelName = senderLabel->objectName();//����
	if (*oldSelectLabelName == "")//��һ��ѡ��
	{
		senderGroupBox->setStyleSheet("QGroupBox{border:1px solid red;}");
		//senderGroupBox->setStyleSheet("border:none");
		senderLabel->setFrameShadow(QFrame::Sunken);//Sunken  �½�
		*oldSelectLabelName = senderLabel->objectName();//����
		senderLabel = nullptr;
		ui.button_Copy->setEnabled(true);
		return;
	}
	else//���ǵ�һ��ѡ��
	{
		if (*oldSelectLabelName == *newSelectLabelName)//�ٴε��ͬһ���ؼ�����ȡ��ѡ��
		{
			*oldSelectLabelName = "";
			*newSelectLabelName = "";
			//��ǰ�ؼ�Label��ԭ��ʽ
			senderGroupBox->setStyleSheet("QGroupBox{}");
			senderLabel->setFrameShadow(QFrame::Raised);//Raised  �ϸ�
			senderLabel = nullptr;
			ui.button_Copy->setEnabled(false);
			return;
		}
		else//���һ���µĿؼ�
		{
			//�ɵĿؼ�
			MyLabel *oldSelectLabel = ui.centralWidget->findChild<MyLabel *>(*oldSelectLabelName);
			QGroupBox *oldGroupBox = dynamic_cast<QGroupBox*>(oldSelectLabel->parent()->parent());//��һ�ε�QGroupBox
			oldGroupBox->setStyleSheet("QGroupBox{}");
			oldSelectLabel->setFrameShadow(QFrame::Raised);//Raised  �ϸ�
			oldSelectLabel = nullptr;
			oldGroupBox = nullptr;
			//�µĿؼ�--�źŷ�����
			senderGroupBox->setStyleSheet("QGroupBox{border:1px solid red;}");
			senderLabel->setFrameShadow(QFrame::Sunken);//Sunken  �½�
			*oldSelectLabelName = senderLabel->objectName();//����
			senderLabel = nullptr;
			ui.button_Copy->setEnabled(true);
			return;
		}
	}
}


/***************************************
*�������ܣ�����һ�ż����ͼƬ
*���룺
*	void
*�����
*	QImage:����һ�ż����ͼƬ�����ؾֲ��������󣬶��ǵ�ַ
*���ߣ�JZQ
*ʱ��汾��2019-06-11-V2.0
***************************************/
QImage QRcodeBuilder::GenerateSimpleCodeImage()
{
	//ͼƬ�У�appConfig->SimplecodeLen-1��+ 2(��ʼ��������)�У�ֻ��2��
	QImage image(240, 40, QImage::Format_RGB888);//�ֲ������������������������������ȥ��ʼ���������Ǹ�ֵ��=����
	image.fill(QColor(Qt::white).rgb());

	//�ȴ�����ʼ�������е����ء�
	for (int i = 0; i < image.height(); i++)
	{
		for (int j = 0; j < image.width() / ((appConfig->SimplecodeLen - 1 + 2) * 2); j++)
		{
			//ͼƬ���ı䣬�����ڶ������⣬��Ч�ʽ���
			image.setPixelColor(j, i, QColor(Qt::black));
		}
		for (int j = image.width() * ((appConfig->SimplecodeLen - 1 + 2) * 2 - 1) / ((appConfig->SimplecodeLen - 1 + 2) * 2); j < image.width(); j++)
		{
			//ͼƬ�Ҳ�ı䣬�����ڶ������⣬��Ч�ʽ���
			image.setPixelColor(j, i, QColor(Qt::black));
		}
	}

	//�ٴ���ʣ���У�appConfig->SimplecodeLen-1������һ�У�����ѡƱID������
	int begin_N = 0;
	int end_N = 0;
	string theFirstLine = QStringToStdstringWithLength(QString::number(ui.voteID->text().toInt(), 2), appConfig->SimplecodeLen - 1);
	for (int x = 0; theFirstLine[x] != '\0'; x++)
	{//����
		if (theFirstLine[x] == '1')
		{
			begin_N = (image.width() / (appConfig->SimplecodeLen - 1 + 2)) * (x + 1);
			end_N = begin_N + (image.width() / (appConfig->SimplecodeLen - 1 + 2));
			for (int i = 0; i < image.height() / 2; i++)//��һ��
			{
				for (int j = begin_N; j < end_N; j++)
				{//ÿ��ֻ����һ�С�
					image.setPixelColor(j, i, QColor(Qt::black));
				}
			}
		}
	}

	//�ٴ���ʣ���У�appConfig->SimplecodeLen-1�����ڶ��У�ҳ�룬��������6��[0,5]��[6,11]
	string theSecondLine = QStringToStdstringWithLength(QString::number(s_buildCount, 2), appConfig->SimplecodeLen - 1);//��������������������ͼƬ
	for (int x = 0; theSecondLine[x] != '\0'; x++)
	{//����
		if (theSecondLine[x] == '1')
		{
			begin_N = (image.width() / (appConfig->SimplecodeLen - 1 + 2)) * (x + 1);
			end_N = begin_N + (image.width() / (appConfig->SimplecodeLen - 1 + 2));
			for (int i = image.height() / 2; i < image.height(); i++)//�ڶ���
			{
				for (int j = begin_N; j < end_N; j++)
				{//ÿ��ֻ����һ�С�
					image.setPixelColor(j, i, QColor(Qt::black));
				}
			}
		}
	}
	s_buildCount += 1;//ÿһ�ε���1
	if (s_buildCount >= 12)
	{
		s_buildCount = 0;//��0�ٿ�ʼ
	}
	return image;
}


/***************************************
*�������ܣ�����һ�Ŷ�ά���ͼƬ
*���룺
*	data:ɨ��ά����ʾ����Ϣ
*�����
*	QImage:����һ�ż����ͼƬ�����ؾֲ��������󣬶��ǵ�ַ
*���ߣ�JZQ
*ʱ��汾��2019-06-11-V2.0
***************************************/
QImage QRcodeBuilder::GenerateQRCodeImage(const QString &data)
{
	qrcodegen::QrCode qrCode = qrcodegen::QrCode::encodeText(data.toUtf8().constData(), qrcodegen::QrCode::Ecc::LOW);
	const int qrCodeSize = qrCode.getSize() > 0 ? qrCode.getSize() : 1;//��С��data����
	float scale = appConfig->QRcodePixelSize / qrCodeSize;//�û�����ͼƬ������qrCodeSize�����ű�����

	QImage image(qrCodeSize, qrCodeSize, QImage::Format_RGB888);
	image.fill(QColor(Qt::white).rgb());

	for (int y = 0; y < qrCodeSize; y++) {
		for (int x = 0; x < qrCodeSize; x++) {
			/*
			bool getModule(int x, int y)
			���ظ���������ģ��(����)����ɫ����ɫΪfalse����ɫΪtrue�����Ͻ�������(x=0, y=0)��������������곬�����ޣ��򷵻�false(��ɫ)��
			*/
			const int color = qrCode.getModule(x, y); // 0 for white, 1 for black
			if (0 != color)
			{
				image.setPixelColor(x, y, QColor(Qt::black));
			}
		}
	}
	s_buildCount += 1;//ÿһ�ε���1
	if (s_buildCount >= 12)
	{
		s_buildCount = 0;//��0�ٿ�ʼ
	}

	image = image.scaled(240, 240);
	//qDebug() << "image_r.rect().height() = " << image_r.rect().height();
	return image;
}


/***************************************
*�������ܣ���һ��ͼƬ��ʾ���ؼ�imageLabel��
*���룺
*	image:��Ҫ��ʾ��ͼƬ
*	imageLabel:��ʾͼƬ�Ŀؼ�
*	writeText:�Ƿ���Ҫ��ͼƬ�·�д����
*	text:��Ҫ��ʾ�����֣����ָ�ʽ:X-X����һ��X����ѡƱID���ڶ���X����ҳ��
*	textLabel:��ʾ���ֵĿؼ�
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-11-V2.0
***************************************/
void QRcodeBuilder::ShowCodeImage(const QImage &image, QLabel *imageLabel, bool writeText, const QString &text, QLabel *textLabel)
{
	//��ʾͼƬ
	imageLabel->setScaledContents(true);
	QSize resize = imageLabel->rect().size();
	imageLabel->setPixmap(QPixmap::fromImage(image).scaled(resize));

	//��ʾ����
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
*�������ܣ��������ɵ�ͼƬ���ļ����£���ȡ��ͬ������
*���룺
*	image:��Ҫ�����ͼƬ
*	filePath:����ͼƬ��·��
*	imageFormat:ͼƬ����ĸ�ʽ
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-05-29-V1.0
***************************************/
void QRcodeBuilder::SaveCodeImageToFile(QImage & image, const QString & filePath, const QString & imageFormat)
{
	//��ͼƬ���浽·����filePath��
	//qDebug() << "savefilePath:" << (filePath + imageFormat);
	QFile file(filePath + imageFormat);
	if (!file.open(QIODevice::ReadWrite))
	{
		//qDebug() << QString::fromLocal8Bit("���ļ�ʧ�ܣ�");
		QMessageBox::warning(this, QStringLiteral("����"), QStringLiteral("ͼƬ����ʧ�ܣ�"));
		return;
	}
	QByteArray data;
	QBuffer buffer(&data);
	buffer.open(QIODevice::WriteOnly);
	image.save(&buffer, "jpg");//��Ҫ����ĸ�ʽimageFormat.toStdString().c_str()
	file.write(data);
	file.close();
	buffer.close();
}


/***************************************
*�������ܣ�QString�Ͷ�����ת���string�Ͷ����ƣ����ҹ̶�λ��Ϊ��length����λ����
*���룺
*	num:��Ҫת����QString�Ͷ�����
*	length:�̶�λ��ĳ���
*�����
*	string:ת����ľ���lengthλ���string�Ͷ�����
*���ߣ�JZQ
*ʱ��汾��2019-05-28-V1.0
***************************************/
string QRcodeBuilder::QStringToStdstringWithLength(QString num, int length)
{
	int renderSize = 0;
	renderSize = length - num.size();
	char* ch = new char[length + 1];//ʹ����Ҫ�ͷ�
	memset(ch, '0', length + 1);
	for (int j = 0; j < num.size(); j++)
	{
		ch[j + renderSize] = num.toStdString()[j];
	}
	ch[length] = '\0';//�ĩβ

	string ret(ch);
	delete[] ch;
	return ret;
}


/***************************************
*�������ܣ������µ��ļ��У����ļ��д��ڣ���ɾ�������½����������ڣ�ֱ���½�
*���룺
*	filePath:�ļ��е�ַ
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-05-28-V1.0
***************************************/
void QRcodeBuilder::CreateDirectory(const QString & filePath)
{
	QString dir_str = filePath;
	QDir dir;
	if (dir.exists(dir_str))// ���Ŀ¼�Ƿ���ڣ���������ɾ�������½�
	{
		if (!DeleteDirectory(dir_str))
		{
			//�ļ���δɾ���ɹ�
			QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�ļ���δɾ���ɹ���"));
			return;
		}
		if (!dir.mkpath(dir_str))
		{
			//�ļ���δ�����ɹ�
			QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�ļ���δ�����ɹ���"));
			return;
		}
	}
	else// ����������ֱ���½�
	{
		if (!dir.mkpath(dir_str))
		{
			//�ļ���δ�����ɹ�
			QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�ļ���δ�����ɹ���"));
			return;
		}
	}
}


/***************************************
*�������ܣ�ɾ���ļ��У������������������
*���룺
*	filePath:�ļ��е�ַ
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-05-28-V1.0
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
	dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot); //���ù���
	QFileInfoList fileList = dir.entryInfoList(); // ��ȡ���е��ļ���Ϣ
	foreach(QFileInfo file, fileList) { //�����ļ���Ϣ
		if (file.isFile()) { // ���ļ���ɾ��
			file.dir().remove(file.fileName());
		}
		else { // �ݹ�ɾ��
			DeleteDirectory(file.absoluteFilePath());
		}
	}
	return dir.rmpath(dir.absolutePath()); // ɾ���ļ���
}


