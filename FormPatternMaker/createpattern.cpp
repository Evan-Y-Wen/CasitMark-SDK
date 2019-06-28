#include "createpattern.h"
#include "formpatternmaker.h"
//#include "GlobalDefinitions.h"
#include <QTextEdit>
#include <QTextStream>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QCoreApplication>
#include "MPattern.h"

CreatePattern::CreatePattern(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	//设置title
	setWindowTitle(QString::fromLocal8Bit("新建模式"));
	setWindowFlag(Qt::WindowMaximizeButtonHint, false);////默认是ture，false就是去掉这个按钮
}

CreatePattern::~CreatePattern()
{
}
/*
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
}*/

void CreatePattern::BTN_Submit_Click()//ToolButton确定按钮
{
	//这里要取到主窗口。
	FormPatternMaker *TheMainWindow = (FormPatternMaker *)this->parentWidget();

	//新建一个模式文件操作。
	if (TheMainWindow->_CurrentEditPattern != nullptr /*App.TheMainWindow.TheMainWindow->_CurrentEditPattern != null*/)//当前存在一个模式，再新建一个
	{
		if (QString::fromStdString(TheMainWindow->_CurrentEditPattern->PatternName) == ui.TB_PatternName->text() /*App.TheMainWindow.TheMainWindow->_CurrentEditPattern.PatternName == TB_PatternName.Text*/)
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
			App.TheMainWindow.TheMainWindow->_CurrentEditPattern = new FormPattern.MPattern();
			App.TheMainWindow.TheMainWindow->_CurrentEditPattern.PatternName = TB_PatternName.Text;
			App.TheMainWindow.TheMainWindow->_CurrentEditPattern.LocateMode = Cm2.FormPattern.MLocateMode.SimpleCode;
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
			App.TheMainWindow.TheMainWindow->_CurrentEditPattern = new FormPattern.MPattern();
			App.TheMainWindow.TheMainWindow->_CurrentEditPattern.PatternName = TB_PatternName.Text;
			App.TheMainWindow.TheMainWindow->_CurrentEditPattern.LocateMode = Cm2.FormPattern.MLocateMode.ShapeMatch;
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
}

void CreatePattern::CB_Bihe_Click()//RadioButton定位方式一
{
	//Cm2.Common.AppConfig.CurrentConfig.LastLocateMode = 1;
}

void CreatePattern::CB_QR_Click()//RadioButton定位方式二
{
	//Cm2.Common.AppConfig.CurrentConfig.LastLocateMode = 0;
}