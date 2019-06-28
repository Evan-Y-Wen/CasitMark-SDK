#include "addpattern.h"
#include "formpatternmaker.h"
#include <QFileDialog>
#include <QDebug>

AddPattern::AddPattern(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	//����title
	setWindowTitle(QString::fromLocal8Bit("���ģ��"));
	setWindowFlag(Qt::WindowMaximizeButtonHint, false);////Ĭ����ture��false����ȥ�������ť
	//��Ϣ�б�����������
	//ui.SP_FormDetail->setVisible(true);
}

AddPattern::~AddPattern()
{
}

void AddPattern::BTN_AddPatternFromFile_Click()
{
	qDebug() << "BTN_AddPatternFromFile_Click Test!";
	QFileDialog *openFileDialog = new QFileDialog(this);//����һ��QFileDialog���󣬹��캯���еĲ�������������ӡ�
	openFileDialog->setWindowTitle(QString::fromLocal8Bit("ѡ��ͼ���ļ�"));//�����ļ�����Ի���ı���
	openFileDialog->setAcceptMode(QFileDialog::AcceptOpen);//�����ļ��Ի���Ϊ��ģʽ
	openFileDialog->setNameFilter(QString::fromLocal8Bit("ͼ���ļ�|*.bmp;*.jpg;*jpeg;*.png;*.tif;*.tiff"));//�����ļ����͹�����

	QString path = "";
	if (openFileDialog->exec())//����Int����
	{
		m_AddImage = true;
		//1.�õ�path
		path = openFileDialog->selectedFiles()[0];//"G:/�ɲ�����ϵͳ/��һ��ģʽ.cpm",·��+�ļ���
		//��ӡ���Դ洢��fileNames
		qDebug() << path;
		//2.����д����Ĳ���
		//......
	}

	/*
			OpenFileDialog openFileDialog = new OpenFileDialog();
			openFileDialog.Title = "ѡ��ͼ���ļ�";
			openFileDialog.Multiselect = true;
			openFileDialog.Filter = "ͼ���ļ�|*.bmp;*.jpg;*jpeg;*.png;*.tif;*.tiff";
			if (openFileDialog.ShowDialog() == true)
			{
				m_AddImage = true;
				_threshold = Convert.ToInt32(TB_Threshold.Text);
				List<string> srcfiles = new List<string>();
				for (int i = 0; i < openFileDialog.FileNames.Count(); ++i)
					srcfiles.Add(openFileDialog.FileNames[i]);
				List<string> desfiles = Cm2.FormProcess.ImageProcess.ChangeImageFilesToJpg(System.Windows.Forms.Application.StartupPath + "\\NewPatternImages", srcfiles, _threshold);

				AddFormToList(desfiles, srcfiles);
			}
	*/

}

void AddPattern::BTN_AddPatternFromDevice_Click()
{
	qDebug() << "BTN_AddPatternFromDevice_Click Test!";
	
	/*
				if (System.IO.File.Exists(App.AppExeFolder + "\\Cm2.FormImageGetter.exe"))
			{
				_threshold = Convert.ToInt32(TB_Threshold.Text);
				if (System.IO.Directory.Exists(App.AppExeFolder + "\\ͼ���ļ���"))
				{
					System.IO.Directory.Delete(App.AppExeFolder + "\\ͼ���ļ���", true);
					System.IO.Directory.CreateDirectory(App.AppExeFolder + "\\ͼ���ļ���");
				}
				else
				{
					System.IO.Directory.CreateDirectory(App.AppExeFolder + "\\ͼ���ļ���");
				}
				Process process = System.Diagnostics.Process.Start("Cm2.FormImageGetter.exe", "\"" + App.AppExeFolder + "\\ͼ���ļ���\"");
				process.WaitForExit();
				CheckGetImage();
			}
	*/

}

void AddPattern::BTN_AddPatternFromWord_Click()
{
	qDebug() << "BTN_AddPatternFromWord_Click Test!";
	QFileDialog *openFileDialog = new QFileDialog(this);//����һ��QFileDialog���󣬹��캯���еĲ�������������ӡ�
	openFileDialog->setWindowTitle(QString::fromLocal8Bit("ѡ��wordģ��"));//�����ļ�����Ի���ı���
	openFileDialog->setAcceptMode(QFileDialog::AcceptOpen);//�����ļ��Ի���Ϊ��ģʽ
	openFileDialog->setNameFilter(QString::fromLocal8Bit("Wordģ��(*.docx;*.doc)|*.docx;*.doc"));//�����ļ����͹�����

	QString path = "";
	if (openFileDialog->exec())//����Int����
	{
		m_AddImage = true;
		//1.�õ�path
		path = openFileDialog->selectedFiles()[0];//"G:/�ɲ�����ϵͳ/��һ��ģʽ.cpm",·��+�ļ���
		//��ӡ���Դ洢��fileNames
		qDebug() << path;
		//2.����д����Ĳ���
		//......
	}

	/*
		OpenFileDialog openFileDialog = new OpenFileDialog();
		openFileDialog.Title = "ѡ��wordģ��";
		openFileDialog.Multiselect = false;
		openFileDialog.Filter = "Wordģ��(*.docx;*.doc)|*.docx;*.doc";
		if (openFileDialog.ShowDialog() == true)
		{
			m_AddImage = false;
			_threshold = Convert.ToInt32(TB_Threshold.Text);
			List<string> srcfiles = new List<string>();
			for (int i = 0; i < openFileDialog.FileNames.Count(); ++i)
				srcfiles.Add(openFileDialog.FileNames[i]);
			LoadPatternFileStart(srcfiles);
		}
*/
}

void AddPattern::BTN_AddPatternFromPDF_Click()
{
	qDebug() << "BTN_AddPatternFromPDF_Click Test!";
	QFileDialog *openFileDialog = new QFileDialog(this);//����һ��QFileDialog���󣬹��캯���еĲ�������������ӡ�
	openFileDialog->setWindowTitle(QString::fromLocal8Bit("ѡ��PDFģ��"));//�����ļ�����Ի���ı���
	openFileDialog->setAcceptMode(QFileDialog::AcceptOpen);//�����ļ��Ի���Ϊ��ģʽ
	openFileDialog->setNameFilter(QString::fromLocal8Bit("PDFģ��(*.pdf)|*.pdf"));//�����ļ����͹�����

	QString path = "";
	if (openFileDialog->exec())//����Int����
	{
		m_AddImage = true;
		//1.�õ�path
		path = openFileDialog->selectedFiles()[0];//"G:/�ɲ�����ϵͳ/��һ��ģʽ.cpm",·��+�ļ���
		//��ӡ���Դ洢��fileNames
		qDebug() << path;
		//2.����д����Ĳ���
		//......
	}
	/*
				readStatus = 1;
			System.IO.Directory.Delete(App.AppExeFolder + "\\ͼ���ļ���\\", true);
			System.IO.Directory.CreateDirectory(App.AppExeFolder + "\\ͼ���ļ���\\");
			OpenFileDialog openFileDialog = new OpenFileDialog();
			PDFRender pdfRender = new PDFRender();
			openFileDialog.Title = "ѡ��PDFģ��";
			openFileDialog.Multiselect = true;
			openFileDialog.Filter = "PDFģ��(*.pdf)|*.pdf";

			if (openFileDialog.ShowDialog() == true)
			{
				_threshold = Convert.ToInt32(TB_Threshold.Text);
				for (int i = 0; i < openFileDialog.FileNames.Count(); ++i)
				{
					pdfRender.ConvertPDF2Image(openFileDialog.FileNames[i], App.AppExeFolder + "\\ͼ���ļ���\\", System.IO.Path.GetFileNameWithoutExtension(openFileDialog.FileNames[i]), 1, 10, System.Drawing.Imaging.ImageFormat.Tiff, 10);//��PDFת��ΪͼƬ�ļ�
				}
				CheckGetImage();
				//  }
			}
	*/
}

void AddPattern::BTN_Comfirm_Click()
{
	//
	this->close();
}

void AddPattern::BTN_Left_Click()
{

}

void AddPattern::BTN_Right_Click()
{

}


// ����򿪺�ʼ����ģʽ
void LoadPatternFileStart()
{
	//List<String> desfiles = Cm2.FormProcess.WordHelper.ChangeWordFileToImg(System.Windows.Forms.Application.StartupPath + "\\NewPatternImages", srcfiles);
	//AddFormToList(desfiles, srcfiles);
}

// ��ʾͼ��
void ShowImage()//String imagePath)
{
	//
}

// ɾ����ͼ��
void MenuItem_DeleteImage_Click()//object sender, RoutedEventArgs e)
{
	//
}

// ��תͼ���ļ�
void RotateImageFile()//String imageFile, System.Drawing.RotateFlipType type)
{
	//
}

//����ļ�
void CheckGetImage()
{

}

//
void AddFormToList()
{

}


//.......���滹�кܶຯ��������

