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

	//����title
	setWindowTitle(QString::fromLocal8Bit("�½�ģʽ"));
	setWindowFlag(Qt::WindowMaximizeButtonHint, false);////Ĭ����ture��false����ȥ�������ť
}

CreatePattern::~CreatePattern()
{
}
/*
void CreateNewFile(CreatePattern *thethis, QString FileName)        //�������ļ�
{
	QString CurrentFilePath = "G:/";
	CurrentFilePath += FileName;             //��ǰ�ļ�·��G:/11111.txt
	CurrentFilePath += ".cmp";
	QTextEdit *CurrentContent = new QTextEdit(thethis);
	CurrentContent->setText("1a2s1d321asd5as6c1w351a---CreateNewFile---d1a5fa1sf");
	CurrentContent->setVisible(false);
	QFile *file = new QFile(CurrentFilePath);
	if (!file->open(QIODevice::WriteOnly | QIODevice::Text))
	{
		//ShowWarning_WhenSaveFailed();
		QMessageBox::warning(thethis, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�ļ�����ʧ�ܣ�"));
		CurrentFilePath = "";
		return;
	}
	QTextStream textStream(file);
	file->resize(0);
	textStream << CurrentContent->toPlainText();
	QMessageBox::warning(thethis, QString::fromLocal8Bit("�ɹ�"), QString::fromLocal8Bit("�ļ�����ɹ���"));
	file->close();
}*/

void CreatePattern::BTN_Submit_Click()//ToolButtonȷ����ť
{
	//����Ҫȡ�������ڡ�
	FormPatternMaker *TheMainWindow = (FormPatternMaker *)this->parentWidget();

	//�½�һ��ģʽ�ļ�������
	if (TheMainWindow->_CurrentEditPattern != nullptr /*App.TheMainWindow.TheMainWindow->_CurrentEditPattern != null*/)//��ǰ����һ��ģʽ�����½�һ��
	{
		if (QString::fromStdString(TheMainWindow->_CurrentEditPattern->PatternName) == ui.TB_PatternName->text() /*App.TheMainWindow.TheMainWindow->_CurrentEditPattern.PatternName == TB_PatternName.Text*/)
		{
			ui.LB_Message->setText(QString::fromLocal8Bit("��ǰģʽ�����Ѵ��ڣ����޸ģ�"));
		}
		else if (ui.TB_PatternName->text() != QString::fromStdString("") && ui.CB_QR->isChecked() == true && ui.CB_Bihe->isChecked() == false)
		{//�½�һ��ģʽ�ļ�,��λ��ʽ����
			ui.LB_Message->setText(QString::fromLocal8Bit("��λ��ʽ����"));
			//���������½��ļ����ԣ������޸ġ�
			//CreateNewFile(this, ui.LB_Message->text());
			TheMainWindow->_CurrentEditPattern = new Cm2::FormPattern::MPattern();
			TheMainWindow->_CurrentEditPattern->PatternName = ui.TB_PatternName->text().toStdString();
			TheMainWindow->_CurrentEditPattern->LocateMode = Cm2::FormPattern::MLocateMode::ShapeMatch;
			//Cm2.Common.AppConfig.CurrentConfig.LastLocateMode = 1;// ��һ��ʹ�õĶ�λ��ʽ 0-���� 1-����ͼ��...
			m_CreatePatternSuccessed = true;//������ģʽ�ɹ���
			this->close();//�ر��½�ģʽ�Ӵ���
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
		{//�½�һ��ģʽ�ļ�,��λ��ʽһ��
			//���������½��ļ����ԣ������޸ġ�
			//CreateNewFile(this, ui.LB_Message->text());
			TheMainWindow->_CurrentEditPattern = new Cm2::FormPattern::MPattern();
			TheMainWindow->_CurrentEditPattern->PatternName = ui.TB_PatternName->text().toStdString();
			TheMainWindow->_CurrentEditPattern->LocateMode = Cm2::FormPattern::MLocateMode::ShapeMatch;
			//Cm2.Common.AppConfig.CurrentConfig.LastLocateMode = 1;// ��һ��ʹ�õĶ�λ��ʽ 0-���� 1-����ͼ��...
			m_CreatePatternSuccessed = true;//������ģʽ�ɹ���
			this->close();//�ر��½�ģʽ�Ӵ���
		}
		else
		{
			ui.LB_Message->setText(QString::fromLocal8Bit("ģʽ����Ϊ�ջ�λ��ʽδѡ��"));
		}
	}
	else//��ǰ�������κ�ģʽ�ļ����½�һ��
	{
		if (ui.TB_PatternName->text() != QString::fromStdString("") && ui.CB_QR->isChecked() == true && ui.CB_Bihe->isChecked() == false)
		{//�½�һ��ģʽ�ļ�,��λ��ʽ����
			ui.LB_Message->setText(QString::fromLocal8Bit("��λ��ʽ����"));
			//���������½��ļ����ԣ������޸ġ�
			//CreateNewFile(this, ui.LB_Message->text());
			TheMainWindow->_CurrentEditPattern = new Cm2::FormPattern::MPattern();
			TheMainWindow->_CurrentEditPattern->PatternName = ui.TB_PatternName->text().toStdString();
			TheMainWindow->_CurrentEditPattern->LocateMode = Cm2::FormPattern::MLocateMode::ShapeMatch;
			//Cm2.Common.AppConfig.CurrentConfig.LastLocateMode = 1;// ��һ��ʹ�õĶ�λ��ʽ 0-���� 1-����ͼ��...
			m_CreatePatternSuccessed = true;//������ģʽ�ɹ���
			this->close();//�ر��½�ģʽ�Ӵ���
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
		{//�½�һ��ģʽ�ļ�,��λ��ʽһ��
			ui.LB_Message->setText(QString::fromLocal8Bit("��λ��ʽһ��"));
			//���������½��ļ����ԣ������޸ġ�
			//CreateNewFile(this, ui.LB_Message->text());
			TheMainWindow->_CurrentEditPattern = new Cm2::FormPattern::MPattern();
			TheMainWindow->_CurrentEditPattern->PatternName = ui.TB_PatternName->text().toStdString();
			TheMainWindow->_CurrentEditPattern->LocateMode = Cm2::FormPattern::MLocateMode::ShapeMatch;
			//Cm2.Common.AppConfig.CurrentConfig.LastLocateMode = 1;// ��һ��ʹ�õĶ�λ��ʽ 0-���� 1-����ͼ��...
			m_CreatePatternSuccessed = true;//������ģʽ�ɹ���
			this->close();//�ر��½�ģʽ�Ӵ���
		}
		else
		{
			ui.LB_Message->setText(QString::fromLocal8Bit("ģʽ����Ϊ�ջ�λ��ʽδѡ��"));
		}
	}
}

void CreatePattern::CB_Bihe_Click()//RadioButton��λ��ʽһ
{
	//Cm2.Common.AppConfig.CurrentConfig.LastLocateMode = 1;
}

void CreatePattern::CB_QR_Click()//RadioButton��λ��ʽ��
{
	//Cm2.Common.AppConfig.CurrentConfig.LastLocateMode = 0;
}