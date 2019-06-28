#include "formpatternmaker.h"//������ͷ�ļ�
#include "createpattern.h"//�½�ģʽ�Ӵ���
#include "addpattern.h"//���ģ���Ӵ���
//#include "GlobalDefinitions.h"//����ȫ�ֱ���
//#include "RegionArgumentBuilder.h"
#include <QStandardItemModel>
#include <QToolButton>
#include <QPushButton>
#include <QMessageBox>
#include <QFileDialog>
#include <QTreeView>
#include <QTextEdit>
#include <QFile>
#include <QDebug>


FormPatternMaker::FormPatternMaker(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//����title
	setWindowTitle(QString::fromLocal8Bit("ģʽ����"));

}

FormPatternMaker::~FormPatternMaker()
{
	//�ǵ��ͷ��ڴ档�Ժ��޸ġ�*****
}



static bool PatternModified = false;//��ǰPattern�Ƿ��޸���
QTextEdit *CurrentPatternContent = nullptr;//�������浱ǰģʽ�ļ�������

//�˴����幩�����������õ�С���ܺ���////////////////////////////////////////////////////////////////////////
//�˴����幩�����������õ�С���ܺ���////////////////////////////////////////////////////////////////////////
//�˴����幩�����������õ�С���ܺ���////////////////////////////////////////////////////////////////////////
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
//�������ļ�
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

//�˴����幤�����������������ľ������////////////////////////////////////////////////////////////////////////
//�˴����幤�����������������ľ������////////////////////////////////////////////////////////////////////////
//�˴����幤�����������������ľ������////////////////////////////////////////////////////////////////////////
//�½�ģʽ�����������
//ʱ�䣺2019-05-13
//���ߣ�JZQ
void FormPatternMaker::CreatePatternFun()
{
	qDebug() << "CreatePatternFun Test!";
	ui.L_ShowTipMessage->setText(QString::fromLocal8Bit("���½�ģʽ�������ã�ѡ��ģʽ��Ҫʶ���ģ��ͼ��"));

	//�����½�ģʽ�����´���--Button_NewFile��ť����¼������Ϣ����֮����ʾ
	CreatePattern *cpwnd = new CreatePattern(this);
	cpwnd->exec();

	if (cpwnd->m_CreatePatternSuccessed)
	{
		QString dir_str = QCoreApplication::applicationDirPath() + "/NewPatternImages";//���Ӧ�ó���ǰ����Ŀ¼��
		//ԭ�ļ���"E:\\My projection\\Zhongke_Information\\CasitMark\\CasitMark SDK\\Cm2.FormPatternMaker\\bin\\x86\\Debug\\NewPatternImages"
		//dir_str	G:/Qt/Qt5.12.1/User/CasitMark SDK/x64/Debug\NewPatternImages
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
		ui.TB_PatternName->setText(QString::fromLocal8Bit((_CurrentEditPattern->PatternName).c_str()));
		this->openFilePath = "";
		//RegionArgumentBuilder::IsMark = false;
		s_Patterns->insert(pair<string, MPattern *>(_CurrentEditPattern->PatternGUID, _CurrentEditPattern));
		//CasitMarkPatternActionManager.CreatePatternAction(_CurrentEditPattern);
		//_CurrentPatternStruct = new ObservableCollection<SelfDefineUC.PatternNode>();
		//_currentConfig = new AppConfig();
		//FormPatternMakerHelper = new List<Cm2.FormProcess.FormPatternMakerHelper>();
		s_CurrentSelectedFormIndex = 0;
		//TV_ShowPattern.ItemsSource = _CurrentPatternStruct;
		
		ui.Button_AddPattern->setEnabled(true);
		ui.Button_OpenFile->setEnabled(true);
		ui.Button_SaveFile->setEnabled(false);
		ui.Button_Add7Region->setEnabled(false);
		ui.Button_AddBarCodeRegion->setEnabled(false);
		ui.Button_AddImageShotRegion->setEnabled(false);
		ui.Button_AddMarkRegion->setEnabled(false);
		ui.Button_AddMark->setEnabled(false);
		ui.Button_AddOCRRegion->setEnabled(false);
		ui.Button_AddSycnRRegion->setEnabled(false);
		ui.Button_Delete->setEnabled(false);
		ui.Button_Rectangle->setEnabled(false);
		ui.Button_Eraser->setEnabled(false);
		ui.Button_Undo->setEnabled(false);
		ui.Button_Redo->setEnabled(false);
		//canvas_RectangleContainer.Children.Clear();
		//Image_View.Source = nullptr;

		AddPattern *apwnd = new AddPattern(this);
		apwnd->exec();

		if (apwnd->m_AddFormPatternSuccessed)
		{
			for (int i = 0; i < apwnd->_HasCreatedFromPattern->size(); ++i)
			{
				//Cm2.SelfDefineUC.PatternNode formNode = new SelfDefineUC.PatternNode();
				//formNode.IconUri = "pack://application:,,,/Cm2.Resources;component/Icons/Form.ico";
				//formNode.Text = apwnd._HasCreatedFromPattern[i].FormName;
				//formNode.FormIndex = i;
				//formNode.IsExpanded = true;
				//formNode.TypeNode = Cm2.SelfDefineUC.TypeNode.Form;
				//formNode.DataContext = apwnd._HasCreatedFromPattern[i];
				//formNode.IsSelectedVisible = Visibility.Hidden;
				//_CurrentPatternStruct.Add(formNode);

				(*_CurrentEditPattern->FormPatterns)[i].LocatePattern = new Cm2::FormPattern::MLocatePattern;
			}
			ui.Button_AddSycnRRegion->setEnabled(true);
			ui.Button_Delete->setEnabled(true);
			ui.Button_Rectangle->setEnabled(true);
			ui.Button_Eraser->setEnabled(true);
			ui.Button_Undo->setEnabled(false);
			ui.Button_Redo->setEnabled(false);
		}
	}
}
//��ģʽ�����������
//ʱ�䣺2019-05-13
//���ߣ�JZQ
QFile * FormPatternMaker::OpenPatternFromFileFun(const QString & openFileNames)
{
	bool IsLoadPattern = false;
	QFile *_CurrentEditPattern = nullptr;
	qDebug() << "OpenPatternFromFileFun Test!";
	if (IsLoadPattern == true)//���ؼ��ص�ģʽ�ļ��������Ȳ�ִ��
	{
		qDebug() << "OpenPatternFromFileFun Test!";
		return _CurrentEditPattern;
	}
	return nullptr;

	/*
	if (!File.Exists(iFilePath))
	{
		L_ShowTipMessage.Content = "�ļ�" + System.IO.Path.GetFileName(iFilePath) + "�����ڣ�";
		IsLoadPattern = false;
	}

	try
	{
		_CurrentEditPattern = Cm2.FormPattern.MPattern.LoadFromFile(iFilePath);
		FormPatternMakerHelper.Clear();
		for (int i = 0; i < _CurrentEditPattern.FormPatterns.Count; ++i)
		{
			App.TheMainWindow.FormPatternMakerHelper.Add(new Cm2.FormProcess.FormPatternMakerHelper(_CurrentEditPattern.FormPatterns[i].PatternImage, _currentConfig.SimplecodeLen));
		}
		_CurrentPatternStruct = SelfDefineUC.PatternStruct.CreatePatternTreeViewSource(_CurrentEditPattern);
		if (_CurrentEditPattern == null)
		{
			L_ShowTipMessage.Content = "�ļ�" + System.IO.Path.GetFileName(iFilePath) + "���ݱ��޸ġ�";
			IsLoadPattern = false;
			return null;
		}
		if (_CurrentEditPattern.PatternGUID != null)
		{
			L_ShowTipMessage.Content = "�Ѵ��ļ�" + System.IO.Path.GetFileName(iFilePath) + "��";
			openFilePath = iFilePath;
			IsLoadPattern = true;
			TB_PatternName.Text = _CurrentEditPattern.PatternName;
			Button_Add7Region.IsEnabled = true;
			Button_AddBarCodeRegion.IsEnabled = true;
			Button_AddImageShotRegion.IsEnabled = true;
			Button_AddMark.IsEnabled = true;
			Button_AddMarkRegion.IsEnabled = true;
			Button_AddOCRRegion.IsEnabled = true;
			Button_AddSycnRRegion.IsEnabled = true;
			Button_OpenFile.IsEnabled = true;
			Button_SaveFile.IsEnabled = true;
			Button_AddPattern.IsEnabled = true;
			Button_Delete.IsEnabled = true;
			Button_Rectangle.IsEnabled = true;
			Button_Eraser.IsEnabled = true;
			Button_Undo.IsEnabled = false;
			Button_Redo.IsEnabled = false;
			s_Patterns.Clear();
			PatternModified = true;
			s_Patterns.Add(_CurrentEditPattern.PatternGUID, _CurrentEditPattern);
			//CasitMarkPatternActionManager.ClearCurrentActions();
			CasitMarkPatternActionManager.CreatePatternAction(_CurrentEditPattern);
			ActivePattern(App.TheMainWindow._CurrentEditPattern.PatternGUID);

			TV_ShowPattern.ItemsSource = _CurrentPatternStruct;
			_SCurrentPatternStruct = _CurrentPatternStruct;
			return null;

		}

		// ((MainWindow)App.Current.MainWindow).AddPattern(CasitMarkPatternManager.BuildTreeViewItemFromPattern(pattern));
		Cm2.Common.AppConfig.AddOnePath(iFilePath);
	}
	catch (Exception ex)
	{
		L_ShowTipMessage.Content = "�ļ�" + System.IO.Path.GetFileName(iFilePath) + "�޷��򿪣�";
		return null;
	}

	L_ShowTipMessage.Content = "ģʽ�ļ��򿪳ɹ������޸Ĵ�ģʽ����ֱ��ʹ�ø�ģʽ����ͼ��ʶ��";
	return _CurrentEditPattern;
	*/
}
//����ģʽ�����������
//ʱ�䣺2019-05-13
//���ߣ�JZQ
void FormPatternMaker::SavePatternFun(const QString & iFilePath)
{
	qDebug() << "SavePatternFun Test!";
}
//���ģ�塪���������
//ʱ�䣺2019-05-13
//���ߣ�JZQ
void FormPatternMaker::AddPatternFun()
{
	//�������ģ�崰���´���--Button_AddPattern��ť����¼�����ʾ
	AddPattern *cpwnd = new AddPattern;
	cpwnd->show();//���Ӵ����������ģ��Ĳ�����
	qDebug() << "AddPatternFun Test!";
}


//�˴���������ƶ������Ĳۺ���////////////////////////////////////////////////////////////////////////
//�˴���������ƶ������Ĳۺ���////////////////////////////////////////////////////////////////////////
//�˴���������ƶ������Ĳۺ���////////////////////////////////////////////////////////////////////////
/*
[virtual protected] void QWidget::mouseMoveEvent(QMouseEvent *event)
����¼��������(�����¼��¼�)����������������ʵ�֣��Խ���С����������ƶ��¼���
����ر������٣���ֻ��������ƶ�ʱ������갴ť�Żᷢ������ƶ��¼�������������٣���ʹû�а�����갴ť��Ҳ�ᷢ������ƶ��¼���
*/

//�˴����幤����������������Ĳۺ���////////////////////////////////////////////////////////////////////////
//�˴����幤����������������Ĳۺ���////////////////////////////////////////////////////////////////////////
//�˴����幤����������������Ĳۺ���////////////////////////////////////////////////////////////////////////
//�½�ģʽ������Button_NewFile
//ʱ�䣺2019-04-24
//���ߣ�JZQ
void FormPatternMaker::Button_NewFile_Click()
{
	qDebug() << "Button_NewFile_Click Test!";
	ui.label_Msg->setVisible(false); //��ǩ������
	ui.L_ShowTipMessage->setText(QString::fromLocal8Bit("���½�ģʽ�������ã���дģʽ���ơ�"));
	//��������Ϣ�Ի��򣬵��ȷ�ϲ�����//0��Ӧ��ȷ����//1��Ӧ��ȡ����
	if (0 == QMessageBox::question(NULL, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�Ƿ�Ҫ���Ŀǰ��ģʽ��Ϣ�����½�ģʽ��"),
		QString::fromLocal8Bit("ȷ��"), QString::fromLocal8Bit("ȡ��")))//QMessageBox::Yes | QMessageBox::No
	{
		CreatePatternFun();
	}
}



//��ģʽ������Button_OpenFile
//ʱ�䣺2019-04-26
//���ߣ�JZQ
void FormPatternMaker::Button_OpenFile_Click()
{
	qDebug() << "Button_OpenFile_Click Test!";
	ui.label_Msg->setVisible(false); //��ǩ������
	QFileDialog *openFileDialog = new QFileDialog(this);//����һ��QFileDialog���󣬹��캯���еĲ�������������ӡ�
	openFileDialog->setWindowTitle(QString::fromLocal8Bit("��ģʽ�ļ�"));//�����ļ�����Ի���ı���
	openFileDialog->setAcceptMode(QFileDialog::AcceptOpen);//�����ļ��Ի���Ϊ��ģʽ
	//openFileDialog->setFileMode(QFileDialog::AnyFile);//�����ļ��Ի��򵯳���ʱ����ʾ�κ��ļ����������ļ��л����ļ�
	//openFileDialog->setViewMode(QFileDialog::Detail);//�ļ�����ϸ����ʽ��ʾ����ʾ�ļ�������С���������ڵ���Ϣ��
	//openFileDialog->setGeometry(10, 30, 300, 200);//�����ļ��Ի������ʾλ��
	//openFileDialog->setDirectory(".");//�����ļ��Ի����ʱ��ʼ�򿪵�λ��
	openFileDialog->setNameFilter(QString::fromLocal8Bit("CasitMark2.0ģʽ�ļ�(*.cpm)|*.cpm"));//�����ļ����͹�����
	//openFileDialog->setFileMode(QFileDialog::ExistingFiles);//���ÿ���ѡ�����ļ�,Ĭ��Ϊֻ��ѡ��һ���ļ�QFileDialog::ExistingFiles

	QString path = "";
	if (openFileDialog->exec())//����Int����
	{
		//1.�õ�path
		path = openFileDialog->selectedFiles()[0];//"G:/�ɲ�����ϵͳ/��һ��ģʽ.cpm",·��+�ļ���
		//��ӡ���Դ洢��fileNames
		qDebug() << path;
		//2.�����������
		//_CurrentEditPattern = OpenPatternFromFileFun(path);
		//3.������ʾ
		//ui.TB_PatternName->setText(_CurrentEditPattern->fileName());//����TB_PatternName��һ��TextEdit��������ʾ�򿪵��ļ���
		//��������ͼ�����Ŀ
		QStandardItemModel * model = new QStandardItemModel();//�½�һ��Model�������Ҫ�����Զ���һ���µ�model��
		//model->setHorizontalHeaderLabels(QStringList() << QString::fromLocal8Bit("��Ŀ��"));//��ӱ�ͷ
		ui.TV_ShowPattern->setHeaderHidden(true);//���ر�ͷ
		ui.TV_ShowPattern->setModel(model);//����model��ӵ�������ͼ
		QStandardItem * itemProject = new QStandardItem(QString::fromLocal8Bit("��Ŀ"));
		model->appendRow(itemProject);//model->setItem(0,itemProject);	
		QStandardItem* itemChild = new QStandardItem(QString::fromLocal8Bit("�ļ���1"));//������Ŀ¼��
		itemProject->appendRow(itemChild);//itemProject->setChild(0,itemChild);//�����Ŀ¼��

		//Դ�ļ�C#��TV_ShowPattern.ItemsSource = _CurrentPatternStruct;
	}
}
//����ģʽ������Button_SaveFile
//ʱ�䣺2019-04-28
//���ߣ�JZQ
void Save_FileAs(FormPatternMaker *thethis)
{//Qt �ļ����½����򿪡����桢���Ϊ (�Ľ��汾)��https://blog.csdn.net/WQ_1996/article/details/78265279��
	//�����ȴ�һ�������������ȴ�һ���ļ����ٽ������Ϊ��Ҫ�޸ġ�
	CurrentPatternContent = new QTextEdit(thethis);
	CurrentPatternContent->document()->setModified(false);
	CurrentPatternContent->setVisible(false);//�ڽ��治�ɼ�
	thethis->openFilePath = QString::fromLocal8Bit("G:/11111.txt");//"G:/�ɲ�����ϵͳ/��һ��ģʽ.cpm"��G:/11111.txt
	QFile *file = new QFile(thethis->openFilePath);
	if (!file->open(QFile::ReadWrite | QIODevice::Text))
	{
		QMessageBox::warning(thethis, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�ļ���ʧ�ܣ�"));
		thethis->openFilePath = "";
		return;
	}
	QTextStream textStream(file);
	while (!textStream.atEnd())
	{
		CurrentPatternContent->setText(textStream.readAll());//����򿪵��ļ��������
	}
	file->close();

	//���������Ϊһ���ļ���
	QFileDialog *saveFileDialog = new QFileDialog(thethis);//����һ��QFileDialog���󣬹��캯���еĲ�������������ӡ�
	QString title = QString::fromLocal8Bit("��ģʽ��")
		+ QString::fromLocal8Bit("ģʽ����")
		+ QString::fromLocal8Bit("����Ϊ");
	saveFileDialog->setWindowTitle(title);//�����ļ�����Ի���ı���
	saveFileDialog->setAcceptMode(QFileDialog::AcceptSave);//�����ļ��Ի���Ϊ����ģʽ
	//saveFileDialog->setNameFilter(QString::fromLocal8Bit("CasitMark2.0ģʽ�ļ�(*.cpm)|*.cpm"));//�����ļ����͹�����
	saveFileDialog->setNameFilter(QString::fromLocal8Bit("*.txt"));//�����ļ����͹�����
	saveFileDialog->setOptions(QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);//ֻ��ʾ�ļ���

	if (saveFileDialog->exec())//�Ի�������ȷִ���ˡ�
	{
		QString CurrentFilePath = saveFileDialog->selectedFiles()[0];
		QFile *file = new QFile(CurrentFilePath);
		if (!file->open(QIODevice::WriteOnly | QIODevice::Text))
		{
			QMessageBox::warning(thethis, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�ļ�����ʧ�ܣ�"));
			CurrentFilePath = "";
			return;
		}
		QTextStream textStream(file);
		textStream << CurrentPatternContent->toPlainText();//���򿪵��ļ�����д�������ļ�
		file->close();
		QMessageBox::warning(thethis, QString::fromLocal8Bit("�ɹ�"), QString::fromLocal8Bit("�ļ�����ɹ���"));

		QFileInfo fileInfo(CurrentFilePath);//
		if (fileInfo.exists())//exists() �����ж�һ���ļ��Ƿ����
		{
			QFile::remove(CurrentFilePath);//�����ˣ�����ɾ����
		}
		QString Path = fileInfo.absolutePath();//ֻ��·��
		QString Name = fileInfo.fileName();//ֻ���ļ������к�׺��
	}
}
void FormPatternMaker::Button_SaveFile_Click()
{
	qDebug() << "Button_SaveFile_Click Test!";
	ui.label_Msg->setVisible(false); //��ǩ������
	if (true /*_CurrentEditPattern != nullptr*/)//Ҫ�޸�
	{
		if (true /*openFilePath != ""*/)//Ҫ�޸�
		{
			//��������Ϣ�Ի��򣬵��ȷ�ϲ�����//0��Ӧ��ȷ����//1��Ӧ�����Ϊ��
			if (0 == QMessageBox::question(NULL, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�Ƿ񸲸ǵ�ǰģʽ���б��棿"),
				QString::fromLocal8Bit("ȷ��"), QString::fromLocal8Bit("���Ϊ")))//QMessageBox::Yes | QMessageBox::No
			{
				SavePatternFun(openFilePath);//Save(openFilePath);
				PatternModified = true;
			}
			else//������Ϊ�������������ǵ�ǰģʽ���б��档
			{//���ݴ洢·������
				Save_FileAs(this);
				/*�����仹û�����ԡ�
				Cm2.Common.AppConfig.AddOnePath(saveFileDialog.FileName);
				_CurrentEditPattern.SaveToFile(saveFileDialog.FileName);
				*/
				QString Text = QString::fromLocal8Bit("�ļ�")
					+ QString::fromLocal8Bit("ģʽ����")
					+ QString::fromLocal8Bit("����ɹ���");
				ui.L_ShowTipMessage->setText(Text);
				PatternModified = true;
			}
		}
		else
		{
			//���ݴ洢·������
			SavePatternFun(openFilePath);
			PatternModified = true;
		}
	}
}
//���ģ�尴����Button_AddPattern
//ʱ�䣺2019-04-29
//���ߣ�JZQ
void FormPatternMaker::Button_AddPattern_Click()
{
	qDebug() << "Button_AddPattern_Click Test!";
	ui.label_Msg->setVisible(false); //��ǩ������
	ui.L_ShowTipMessage->setText(QString::fromLocal8Bit("���½�ģʽ�������ã�ѡ��ģʽ��Ҫʶ���ģ��ͼ��"));
	AddPatternFun();
}


