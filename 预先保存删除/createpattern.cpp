#include "createpattern.h"
#include "formpatternmaker.h"
#include <QTextEdit>
#include <QTextStream>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QCoreApplication>

CreatePattern::CreatePattern(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//设置title
	setWindowTitle(QString::fromLocal8Bit("新建模式"));
	//setWindowFlag(Qt::WindowMaximizeButtonHint, false);////默认是ture，false就是去掉这个按钮

	setWindowFlags(Qt::Dialog);//Qt::Dialog这个属性会告诉Qt这个窗口是要被当做对话框对待的，从而实现预期的效果。
	//setWindowModality(Qt::WindowModal);//阻挡父亲窗口内其他控件，除非本dialog关闭
}

CreatePattern::~CreatePattern()
{
}

void CreateNewFile(CreatePattern *thethis, QString FileName)        //创建新文件
{
	QString CurrentFilePath = "G:/";
	CurrentFilePath += FileName;             //当前文件路径G:/11111.txt
	CurrentFilePath += ".cmp";
	QTextEdit *CurrentContent = new QTextEdit(thethis);
	CurrentContent->setText("1a2s1d321asd5as6c1w351a---CreateNewFile---d1a5fa1sf");
	CurrentContent->setVisible(false);
	QFile *file = new QFile(CurrentFilePath);
	if (!file->open(QIODevice::WriteOnly | QIODevice::Text))
	{
		//ShowWarning_WhenSaveFailed();
		QMessageBox::warning(thethis, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("文件保存失败！"));
		CurrentFilePath = "";
		return;
	}
	QTextStream textStream(file);
	file->resize(0);
	textStream << CurrentContent->toPlainText();
	QMessageBox::warning(thethis, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("文件保存成功！"));
	file->close();
}

//删除文件夹
bool DeleteDirectory(const QString &path)
{
	if (path.isEmpty()) {
		return false;
	}
	QDir dir(path);
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

void CreatePatternFun(CreatePattern *cpwnd, FormPatternMaker *TheMainWindow)
{
	if (cpwnd->m_CreatePatternSuccessed)
	{
		//QString dir_str = QDir::currentPath() + "\\NewPatternImages";//获得应用程序当前工作目录。
		QString dir_str = QCoreApplication::applicationDirPath() + "\\NewPatternImages";//获得应用程序当前工作目录。
		
		QDir dir;
		if (dir.exists(dir_str))// 检查目录是否存在，若存在则删除后再新建
		{
			if (!DeleteDirectory(dir_str))
			{
				//文件夹未删除成功
				QMessageBox::warning(cpwnd, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("文件夹未删除成功！"));
			}
			if (!dir.mkpath(dir_str))
			{
				//文件夹未创建成功
				QMessageBox::warning(cpwnd, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("文件夹未创建成功！"));
			}
		}
		else// 若不存在则直接新建
		{
			if (!dir.mkpath(dir_str))
			{
				//文件夹未创建成功
				QMessageBox::warning(cpwnd, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("文件夹未创建成功！"));
			}
		}
		//这里破坏了封装性。ui改成了Public
		TheMainWindow->ui.TB_PatternName->setText(QString::fromLocal8Bit((TheMainWindow->_CurrentEditPattern->PatternName).c_str()));
		TheMainWindow->openFilePath = "";
		//RegionArgumentBuilder.IsMark = false;
		//s_Patterns.Add(_CurrentEditPattern.PatternGUID, _CurrentEditPattern);
		//CasitMarkPatternActionManager.CreatePatternAction(_CurrentEditPattern);
		//_CurrentPatternStruct = new ObservableCollection<SelfDefineUC.PatternNode>();
		//_currentConfig = new AppConfig();
		//FormPatternMakerHelper = new List<Cm2.FormProcess.FormPatternMakerHelper>();
		//s_CurrentSelectedFormIndex = 0;
		//TV_ShowPattern.ItemsSource = _CurrentPatternStruct;
		//Button_AddPattern.IsEnabled = true;

		//Button_OpenFile.IsEnabled = true;
		//Button_SaveFile.IsEnabled = false;

		//Button_Add7Region.IsEnabled = false;

		//Button_AddBarCodeRegion.IsEnabled = false;
		//Button_AddImageShotRegion.IsEnabled = false;
		//Button_AddMarkRegion.IsEnabled = false;
		//Button_AddMark.IsEnabled = false;
		//Button_AddOCRRegion.IsEnabled = false;
		//Button_AddSycnRRegion.IsEnabled = false;
		//Button_Delete.IsEnabled = false;
		//Button_Rectangle.IsEnabled = false;
		//Button_Eraser.IsEnabled = false;
		//Button_Undo.IsEnabled = false;
		//Button_Redo.IsEnabled = false;
		//canvas_RectangleContainer.Children.Clear();
		//Image_View.Source = null;

		//AddPattern apwnd = new AddPattern();
		//apwnd.ShowDialog();

		//if (apwnd.m_AddFormPatternSuccessed)
		//{
		//	for (int i = 0; i < apwnd._HasCreatedFromPattern.Count; ++i)
		//	{
		//		Cm2.SelfDefineUC.PatternNode formNode = new SelfDefineUC.PatternNode();
		//		formNode.IconUri = "pack://application:,,,/Cm2.Resources;component/Icons/Form.ico";
		//		formNode.Text = apwnd._HasCreatedFromPattern[i].FormName;
		//		formNode.FormIndex = i;
		//		formNode.IsExpanded = true;
		//		formNode.TypeNode = Cm2.SelfDefineUC.TypeNode.Form;
		//		formNode.DataContext = apwnd._HasCreatedFromPattern[i];
		//		formNode.IsSelectedVisible = Visibility.Hidden;
		//		_CurrentPatternStruct.Add(formNode);

		//		_CurrentEditPattern.FormPatterns[i].LocatePattern = new FormPattern.MLocatePattern();
		//	}
		//	Button_AddLocationRegion.IsEnabled = true;
		//	Button_Delete.IsEnabled = true;
		//	Button_Rectangle.IsEnabled = true;
		//	Button_Eraser.IsEnabled = true;
		//	Button_Undo.IsEnabled = false;
		//	Button_Redo.IsEnabled = false;
		//}
	}
}

void CreatePattern::BTN_Submit_Click()//ToolButton确定按钮
{
	//这里要取到主窗口。
	FormPatternMaker *TheMainWindow = (FormPatternMaker *)this->parentWidget();

	//新建一个模式文件操作。
	if (TheMainWindow->_CurrentEditPattern != nullptr /*App.TheMainWindow._CurrentEditPattern != null*/)//当前存在一个模式，再新建一个
	{
		if (QString::fromStdString(TheMainWindow->_CurrentEditPattern->PatternName) == ui.TB_PatternName->text() /*App.TheMainWindow._CurrentEditPattern.PatternName == TB_PatternName.Text*/)
		{
			ui.LB_Message->setText(QString::fromLocal8Bit("当前模式名称已存在，请修改！"));
		}
		else if (ui.TB_PatternName->text() != QString::fromStdString("") && ui.CB_QR->isChecked() == true && ui.CB_Bihe->isChecked() == false)
		{//新建一个模式文件,定位方式二。
			ui.LB_Message->setText(QString::fromLocal8Bit("定位方式二！"));
			//这里做个新建文件测试，后期修改。
			//CreateNewFile(this, ui.LB_Message->text());
			TheMainWindow->_CurrentEditPattern = new Cm2::FormPattern::MPattern();
			TheMainWindow->_CurrentEditPattern->PatternName = ui.TB_PatternName->text().toStdString();
			TheMainWindow->_CurrentEditPattern->LocateMode = Cm2::FormPattern::MLocateMode::ShapeMatch;
			//Cm2.Common.AppConfig.CurrentConfig.LastLocateMode = 1;// 上一次使用的定位方式 0-简单码 1-田字图形...
			m_CreatePatternSuccessed = true;//创建新模式成功。
			this->close();//关闭新建模式子窗口
			/*
			App.TheMainWindow._CurrentEditPattern = new FormPattern.MPattern();
			App.TheMainWindow._CurrentEditPattern.PatternName = TB_PatternName.Text;
			App.TheMainWindow._CurrentEditPattern.LocateMode = Cm2.FormPattern.MLocateMode.SimpleCode;
			Cm2.Common.AppConfig.CurrentConfig.LastLocateMode = 0;
			m_CreatePatternSuccessed = true;
			this.Close();
			*/
		}
		else if (ui.TB_PatternName->text() != QString::fromStdString("") && ui.CB_QR->isChecked() == false && ui.CB_Bihe->isChecked() == true)
		{//新建一个模式文件,定位方式一。
			//这里做个新建文件测试，后期修改。
			//CreateNewFile(this, ui.LB_Message->text());
			TheMainWindow->_CurrentEditPattern = new Cm2::FormPattern::MPattern();
			TheMainWindow->_CurrentEditPattern->PatternName = ui.TB_PatternName->text().toStdString();
			TheMainWindow->_CurrentEditPattern->LocateMode = Cm2::FormPattern::MLocateMode::ShapeMatch;
			//Cm2.Common.AppConfig.CurrentConfig.LastLocateMode = 1;// 上一次使用的定位方式 0-简单码 1-田字图形...
			m_CreatePatternSuccessed = true;//创建新模式成功。
			this->close();//关闭新建模式子窗口
		}
		else
		{
			ui.LB_Message->setText(QString::fromLocal8Bit("模式名称为空或定位方式未选！"));
		}
	}
	else//当前不存在任何模式文件，新建一个
	{
		if (ui.TB_PatternName->text() != QString::fromStdString("") && ui.CB_QR->isChecked() == true && ui.CB_Bihe->isChecked() == false)
		{//新建一个模式文件,定位方式二。
			ui.LB_Message->setText(QString::fromLocal8Bit("定位方式二！"));
			//这里做个新建文件测试，后期修改。
			//CreateNewFile(this, ui.LB_Message->text());
			TheMainWindow->_CurrentEditPattern = new Cm2::FormPattern::MPattern();
			TheMainWindow->_CurrentEditPattern->PatternName = ui.TB_PatternName->text().toStdString();
			TheMainWindow->_CurrentEditPattern->LocateMode = Cm2::FormPattern::MLocateMode::ShapeMatch;
			//Cm2.Common.AppConfig.CurrentConfig.LastLocateMode = 1;// 上一次使用的定位方式 0-简单码 1-田字图形...
			m_CreatePatternSuccessed = true;//创建新模式成功。
			this->close();//关闭新建模式子窗口
			/*
			App.TheMainWindow._CurrentEditPattern = new FormPattern.MPattern();
			App.TheMainWindow._CurrentEditPattern.PatternName = TB_PatternName.Text;
			App.TheMainWindow._CurrentEditPattern.LocateMode = Cm2.FormPattern.MLocateMode.ShapeMatch;
			Cm2.Common.AppConfig.CurrentConfig.LastLocateMode = 1;
			m_CreatePatternSuccessed = true;
			this.Close();
			*/
		}
		else if (ui.TB_PatternName->text() != QString::fromStdString("") && ui.CB_QR->isChecked() == false && ui.CB_Bihe->isChecked() == true)
		{//新建一个模式文件,定位方式一。
			ui.LB_Message->setText(QString::fromLocal8Bit("定位方式一！"));
			//这里做个新建文件测试，后期修改。
			//CreateNewFile(this, ui.LB_Message->text());
			TheMainWindow->_CurrentEditPattern = new Cm2::FormPattern::MPattern();
			TheMainWindow->_CurrentEditPattern->PatternName = ui.TB_PatternName->text().toStdString();
			TheMainWindow->_CurrentEditPattern->LocateMode = Cm2::FormPattern::MLocateMode::ShapeMatch;
			//Cm2.Common.AppConfig.CurrentConfig.LastLocateMode = 1;// 上一次使用的定位方式 0-简单码 1-田字图形...
			m_CreatePatternSuccessed = true;//创建新模式成功。
			this->close();//关闭新建模式子窗口
		}
		else
		{
			ui.LB_Message->setText(QString::fromLocal8Bit("模式名称为空或定位方式未选！"));
		}
	}

	CreatePatternFun(this, TheMainWindow);
}

void CreatePattern::CB_Bihe_Click()//RadioButton定位方式一
{
	//Cm2.Common.AppConfig.CurrentConfig.LastLocateMode = 1;
}

void CreatePattern::CB_QR_Click()//RadioButton定位方式二
{
	//Cm2.Common.AppConfig.CurrentConfig.LastLocateMode = 0;
}