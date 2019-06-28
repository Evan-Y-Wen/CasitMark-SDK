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

	//����title
	setWindowTitle(QString::fromLocal8Bit("�½�ģʽ"));
	//setWindowFlag(Qt::WindowMaximizeButtonHint, false);////Ĭ����ture��false����ȥ�������ť

	setWindowFlags(Qt::Dialog);//Qt::Dialog������Ի����Qt���������Ҫ�������Ի���Դ��ģ��Ӷ�ʵ��Ԥ�ڵ�Ч����
	//setWindowModality(Qt::WindowModal);//�赲���״����������ؼ������Ǳ�dialog�ر�
}

CreatePattern::~CreatePattern()
{
}

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
}

//ɾ���ļ���
bool DeleteDirectory(const QString &path)
{
	if (path.isEmpty()) {
		return false;
	}
	QDir dir(path);
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

void CreatePatternFun(CreatePattern *cpwnd, FormPatternMaker *TheMainWindow)
{
	if (cpwnd->m_CreatePatternSuccessed)
	{
		//QString dir_str = QDir::currentPath() + "\\NewPatternImages";//���Ӧ�ó���ǰ����Ŀ¼��
		QString dir_str = QCoreApplication::applicationDirPath() + "\\NewPatternImages";//���Ӧ�ó���ǰ����Ŀ¼��
		
		QDir dir;
		if (dir.exists(dir_str))// ���Ŀ¼�Ƿ���ڣ���������ɾ�������½�
		{
			if (!DeleteDirectory(dir_str))
			{
				//�ļ���δɾ���ɹ�
				QMessageBox::warning(cpwnd, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�ļ���δɾ���ɹ���"));
			}
			if (!dir.mkpath(dir_str))
			{
				//�ļ���δ�����ɹ�
				QMessageBox::warning(cpwnd, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�ļ���δ�����ɹ���"));
			}
		}
		else// ����������ֱ���½�
		{
			if (!dir.mkpath(dir_str))
			{
				//�ļ���δ�����ɹ�
				QMessageBox::warning(cpwnd, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�ļ���δ�����ɹ���"));
			}
		}
		//�����ƻ��˷�װ�ԡ�ui�ĳ���Public
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

void CreatePattern::BTN_Submit_Click()//ToolButtonȷ����ť
{
	//����Ҫȡ�������ڡ�
	FormPatternMaker *TheMainWindow = (FormPatternMaker *)this->parentWidget();

	//�½�һ��ģʽ�ļ�������
	if (TheMainWindow->_CurrentEditPattern != nullptr /*App.TheMainWindow._CurrentEditPattern != null*/)//��ǰ����һ��ģʽ�����½�һ��
	{
		if (QString::fromStdString(TheMainWindow->_CurrentEditPattern->PatternName) == ui.TB_PatternName->text() /*App.TheMainWindow._CurrentEditPattern.PatternName == TB_PatternName.Text*/)
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
			App.TheMainWindow._CurrentEditPattern = new FormPattern.MPattern();
			App.TheMainWindow._CurrentEditPattern.PatternName = TB_PatternName.Text;
			App.TheMainWindow._CurrentEditPattern.LocateMode = Cm2.FormPattern.MLocateMode.SimpleCode;
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
			App.TheMainWindow._CurrentEditPattern = new FormPattern.MPattern();
			App.TheMainWindow._CurrentEditPattern.PatternName = TB_PatternName.Text;
			App.TheMainWindow._CurrentEditPattern.LocateMode = Cm2.FormPattern.MLocateMode.ShapeMatch;
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

	CreatePatternFun(this, TheMainWindow);
}

void CreatePattern::CB_Bihe_Click()//RadioButton��λ��ʽһ
{
	//Cm2.Common.AppConfig.CurrentConfig.LastLocateMode = 1;
}

void CreatePattern::CB_QR_Click()//RadioButton��λ��ʽ��
{
	//Cm2.Common.AppConfig.CurrentConfig.LastLocateMode = 0;
}