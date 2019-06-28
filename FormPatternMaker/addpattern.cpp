#include "addpattern.h"
#include "formpatternmaker.h"
#include <QFileDialog>
#include <QDebug>

AddPattern::AddPattern(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	//设置title
	setWindowTitle(QString::fromLocal8Bit("添加模板"));
	setWindowFlag(Qt::WindowMaximizeButtonHint, false);////默认是ture，false就是去掉这个按钮
	//信息列表先隐藏起来
	//ui.SP_FormDetail->setVisible(true);
}

AddPattern::~AddPattern()
{
}

void AddPattern::BTN_AddPatternFromFile_Click()
{
	qDebug() << "BTN_AddPatternFromFile_Click Test!";
	QFileDialog *openFileDialog = new QFileDialog(this);//创建一个QFileDialog对象，构造函数中的参数可以有所添加。
	openFileDialog->setWindowTitle(QString::fromLocal8Bit("选择图像文件"));//设置文件保存对话框的标题
	openFileDialog->setAcceptMode(QFileDialog::AcceptOpen);//设置文件对话框为打开模式
	openFileDialog->setNameFilter(QString::fromLocal8Bit("图像文件|*.bmp;*.jpg;*jpeg;*.png;*.tif;*.tiff"));//设置文件类型过滤器

	QString path = "";
	if (openFileDialog->exec())//返回Int类型
	{
		m_AddImage = true;
		//1.得到path
		path = openFileDialog->selectedFiles()[0];//"G:/干部评测系统/第一轮模式.cpm",路径+文件名
		//打印测试存储的fileNames
		qDebug() << path;
		//2.下面写具体的操作
		//......
	}

	/*
			OpenFileDialog openFileDialog = new OpenFileDialog();
			openFileDialog.Title = "选择图像文件";
			openFileDialog.Multiselect = true;
			openFileDialog.Filter = "图像文件|*.bmp;*.jpg;*jpeg;*.png;*.tif;*.tiff";
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
				if (System.IO.Directory.Exists(App.AppExeFolder + "\\图像文件夹"))
				{
					System.IO.Directory.Delete(App.AppExeFolder + "\\图像文件夹", true);
					System.IO.Directory.CreateDirectory(App.AppExeFolder + "\\图像文件夹");
				}
				else
				{
					System.IO.Directory.CreateDirectory(App.AppExeFolder + "\\图像文件夹");
				}
				Process process = System.Diagnostics.Process.Start("Cm2.FormImageGetter.exe", "\"" + App.AppExeFolder + "\\图像文件夹\"");
				process.WaitForExit();
				CheckGetImage();
			}
	*/

}

void AddPattern::BTN_AddPatternFromWord_Click()
{
	qDebug() << "BTN_AddPatternFromWord_Click Test!";
	QFileDialog *openFileDialog = new QFileDialog(this);//创建一个QFileDialog对象，构造函数中的参数可以有所添加。
	openFileDialog->setWindowTitle(QString::fromLocal8Bit("选择word模板"));//设置文件保存对话框的标题
	openFileDialog->setAcceptMode(QFileDialog::AcceptOpen);//设置文件对话框为打开模式
	openFileDialog->setNameFilter(QString::fromLocal8Bit("Word模板(*.docx;*.doc)|*.docx;*.doc"));//设置文件类型过滤器

	QString path = "";
	if (openFileDialog->exec())//返回Int类型
	{
		m_AddImage = true;
		//1.得到path
		path = openFileDialog->selectedFiles()[0];//"G:/干部评测系统/第一轮模式.cpm",路径+文件名
		//打印测试存储的fileNames
		qDebug() << path;
		//2.下面写具体的操作
		//......
	}

	/*
		OpenFileDialog openFileDialog = new OpenFileDialog();
		openFileDialog.Title = "选择word模板";
		openFileDialog.Multiselect = false;
		openFileDialog.Filter = "Word模板(*.docx;*.doc)|*.docx;*.doc";
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
	QFileDialog *openFileDialog = new QFileDialog(this);//创建一个QFileDialog对象，构造函数中的参数可以有所添加。
	openFileDialog->setWindowTitle(QString::fromLocal8Bit("选择PDF模板"));//设置文件保存对话框的标题
	openFileDialog->setAcceptMode(QFileDialog::AcceptOpen);//设置文件对话框为打开模式
	openFileDialog->setNameFilter(QString::fromLocal8Bit("PDF模板(*.pdf)|*.pdf"));//设置文件类型过滤器

	QString path = "";
	if (openFileDialog->exec())//返回Int类型
	{
		m_AddImage = true;
		//1.得到path
		path = openFileDialog->selectedFiles()[0];//"G:/干部评测系统/第一轮模式.cpm",路径+文件名
		//打印测试存储的fileNames
		qDebug() << path;
		//2.下面写具体的操作
		//......
	}
	/*
				readStatus = 1;
			System.IO.Directory.Delete(App.AppExeFolder + "\\图像文件夹\\", true);
			System.IO.Directory.CreateDirectory(App.AppExeFolder + "\\图像文件夹\\");
			OpenFileDialog openFileDialog = new OpenFileDialog();
			PDFRender pdfRender = new PDFRender();
			openFileDialog.Title = "选择PDF模板";
			openFileDialog.Multiselect = true;
			openFileDialog.Filter = "PDF模板(*.pdf)|*.pdf";

			if (openFileDialog.ShowDialog() == true)
			{
				_threshold = Convert.ToInt32(TB_Threshold.Text);
				for (int i = 0; i < openFileDialog.FileNames.Count(); ++i)
				{
					pdfRender.ConvertPDF2Image(openFileDialog.FileNames[i], App.AppExeFolder + "\\图像文件夹\\", System.IO.Path.GetFileNameWithoutExtension(openFileDialog.FileNames[i]), 1, 10, System.Drawing.Imaging.ImageFormat.Tiff, 10);//把PDF转换为图片文件
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


// 窗体打开后开始加载模式
void LoadPatternFileStart()
{
	//List<String> desfiles = Cm2.FormProcess.WordHelper.ChangeWordFileToImg(System.Windows.Forms.Application.StartupPath + "\\NewPatternImages", srcfiles);
	//AddFormToList(desfiles, srcfiles);
}

// 显示图像
void ShowImage()//String imagePath)
{
	//
}

// 删除该图像
void MenuItem_DeleteImage_Click()//object sender, RoutedEventArgs e)
{
	//
}

// 旋转图像文件
void RotateImageFile()//String imageFile, System.Drawing.RotateFlipType type)
{
	//
}

//检查文件
void CheckGetImage()
{

}

//
void AddFormToList()
{

}


//.......后面还有很多函数，，，

