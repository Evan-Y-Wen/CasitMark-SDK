#include "formpatternmaker.h"//主窗口头文件
#include "createpattern.h"//新建模式子窗口
#include "addpattern.h"//添加模板子窗口
//#include "GlobalDefinitions.h"//引用全局变量
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

	//设置title
	setWindowTitle(QString::fromLocal8Bit("模式制作"));

}

FormPatternMaker::~FormPatternMaker()
{
	//记得释放内存。以后修改。*****
}



static bool PatternModified = false;//当前Pattern是否被修改了
QTextEdit *CurrentPatternContent = nullptr;//用来保存当前模式文件的内容

//此处定义供其他函数调用的小功能函数////////////////////////////////////////////////////////////////////////
//此处定义供其他函数调用的小功能函数////////////////////////////////////////////////////////////////////////
//此处定义供其他函数调用的小功能函数////////////////////////////////////////////////////////////////////////
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
//创建新文件
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

//此处定义工具栏按键点击操作后的具体操作////////////////////////////////////////////////////////////////////////
//此处定义工具栏按键点击操作后的具体操作////////////////////////////////////////////////////////////////////////
//此处定义工具栏按键点击操作后的具体操作////////////////////////////////////////////////////////////////////////
//新建模式——具体操作
//时间：2019-05-13
//作者：JZQ
void FormPatternMaker::CreatePatternFun()
{
	qDebug() << "CreatePatternFun Test!";
	ui.L_ShowTipMessage->setText(QString::fromLocal8Bit("对新建模式进行配置，选择本模式需要识别的模板图像。"));

	//弹出新建模式窗口新窗口--Button_NewFile按钮点击事件后的消息弹窗之后显示
	CreatePattern *cpwnd = new CreatePattern(this);
	cpwnd->exec();

	if (cpwnd->m_CreatePatternSuccessed)
	{
		QString dir_str = QCoreApplication::applicationDirPath() + "/NewPatternImages";//获得应用程序当前工作目录。
		//原文件："E:\\My projection\\Zhongke_Information\\CasitMark\\CasitMark SDK\\Cm2.FormPatternMaker\\bin\\x86\\Debug\\NewPatternImages"
		//dir_str	G:/Qt/Qt5.12.1/User/CasitMark SDK/x64/Debug\NewPatternImages
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
//打开模式——具体操作
//时间：2019-05-13
//作者：JZQ
QFile * FormPatternMaker::OpenPatternFromFileFun(const QString & openFileNames)
{
	bool IsLoadPattern = false;
	QFile *_CurrentEditPattern = nullptr;
	qDebug() << "OpenPatternFromFileFun Test!";
	if (IsLoadPattern == true)//返回加载的模式文件，这里先不执行
	{
		qDebug() << "OpenPatternFromFileFun Test!";
		return _CurrentEditPattern;
	}
	return nullptr;

	/*
	if (!File.Exists(iFilePath))
	{
		L_ShowTipMessage.Content = "文件" + System.IO.Path.GetFileName(iFilePath) + "不存在！";
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
			L_ShowTipMessage.Content = "文件" + System.IO.Path.GetFileName(iFilePath) + "内容被修改。";
			IsLoadPattern = false;
			return null;
		}
		if (_CurrentEditPattern.PatternGUID != null)
		{
			L_ShowTipMessage.Content = "已打开文件" + System.IO.Path.GetFileName(iFilePath) + "。";
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
		L_ShowTipMessage.Content = "文件" + System.IO.Path.GetFileName(iFilePath) + "无法打开！";
		return null;
	}

	L_ShowTipMessage.Content = "模式文件打开成功，可修改此模式或者直接使用该模式进行图像识别。";
	return _CurrentEditPattern;
	*/
}
//保存模式——具体操作
//时间：2019-05-13
//作者：JZQ
void FormPatternMaker::SavePatternFun(const QString & iFilePath)
{
	qDebug() << "SavePatternFun Test!";
}
//添加模板——具体操作
//时间：2019-05-13
//作者：JZQ
void FormPatternMaker::AddPatternFun()
{
	//弹出添加模板窗口新窗口--Button_AddPattern按钮点击事件后显示
	AddPattern *cpwnd = new AddPattern;
	cpwnd->show();//在子窗口内做添加模板的操作。
	qDebug() << "AddPatternFun Test!";
}


//此处定义鼠标移动操作的槽函数////////////////////////////////////////////////////////////////////////
//此处定义鼠标移动操作的槽函数////////////////////////////////////////////////////////////////////////
//此处定义鼠标移动操作的槽函数////////////////////////////////////////////////////////////////////////
/*
[virtual protected] void QWidget::mouseMoveEvent(QMouseEvent *event)
这个事件处理程序(用于事件事件)可以在子类中重新实现，以接收小部件的鼠标移动事件。
如果关闭鼠标跟踪，则只有在鼠标移动时按下鼠标按钮才会发生鼠标移动事件。如果打开鼠标跟踪，即使没有按下鼠标按钮，也会发生鼠标移动事件。
*/

//此处定义工具栏按键点击操作的槽函数////////////////////////////////////////////////////////////////////////
//此处定义工具栏按键点击操作的槽函数////////////////////////////////////////////////////////////////////////
//此处定义工具栏按键点击操作的槽函数////////////////////////////////////////////////////////////////////////
//新建模式按键：Button_NewFile
//时间：2019-04-24
//作者：JZQ
void FormPatternMaker::Button_NewFile_Click()
{
	qDebug() << "Button_NewFile_Click Test!";
	ui.label_Msg->setVisible(false); //标签不可视
	ui.L_ShowTipMessage->setText(QString::fromLocal8Bit("对新建模式进行配置，填写模式名称。"));
	//弹出的消息对话框，点击确认操作。//0对应“确定”//1对应“取消”
	if (0 == QMessageBox::question(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("是否要清空目前的模式信息，并新建模式？"),
		QString::fromLocal8Bit("确定"), QString::fromLocal8Bit("取消")))//QMessageBox::Yes | QMessageBox::No
	{
		CreatePatternFun();
	}
}



//打开模式按键：Button_OpenFile
//时间：2019-04-26
//作者：JZQ
void FormPatternMaker::Button_OpenFile_Click()
{
	qDebug() << "Button_OpenFile_Click Test!";
	ui.label_Msg->setVisible(false); //标签不可视
	QFileDialog *openFileDialog = new QFileDialog(this);//创建一个QFileDialog对象，构造函数中的参数可以有所添加。
	openFileDialog->setWindowTitle(QString::fromLocal8Bit("打开模式文件"));//设置文件保存对话框的标题
	openFileDialog->setAcceptMode(QFileDialog::AcceptOpen);//设置文件对话框为打开模式
	//openFileDialog->setFileMode(QFileDialog::AnyFile);//设置文件对话框弹出的时候显示任何文件，不论是文件夹还是文件
	//openFileDialog->setViewMode(QFileDialog::Detail);//文件以详细的形式显示，显示文件名，大小，创建日期等信息；
	//openFileDialog->setGeometry(10, 30, 300, 200);//设置文件对话框的显示位置
	//openFileDialog->setDirectory(".");//设置文件对话框打开时初始打开的位置
	openFileDialog->setNameFilter(QString::fromLocal8Bit("CasitMark2.0模式文件(*.cpm)|*.cpm"));//设置文件类型过滤器
	//openFileDialog->setFileMode(QFileDialog::ExistingFiles);//设置可以选择多个文件,默认为只能选择一个文件QFileDialog::ExistingFiles

	QString path = "";
	if (openFileDialog->exec())//返回Int类型
	{
		//1.得到path
		path = openFileDialog->selectedFiles()[0];//"G:/干部评测系统/第一轮模式.cpm",路径+文件名
		//打印测试存储的fileNames
		qDebug() << path;
		//2.具体操作函数
		//_CurrentEditPattern = OpenPatternFromFileFun(path);
		//3.界面显示
		//ui.TB_PatternName->setText(_CurrentEditPattern->fileName());//这里TB_PatternName是一个TextEdit，用于显示打开的文件名
		//给树形视图添加条目
		QStandardItemModel * model = new QStandardItemModel();//新建一个Model，这里，需要我们自定义一个新的model、
		//model->setHorizontalHeaderLabels(QStringList() << QString::fromLocal8Bit("项目名"));//添加表头
		ui.TV_ShowPattern->setHeaderHidden(true);//隐藏表头
		ui.TV_ShowPattern->setModel(model);//将该model添加到树形试图
		QStandardItem * itemProject = new QStandardItem(QString::fromLocal8Bit("项目"));
		model->appendRow(itemProject);//model->setItem(0,itemProject);	
		QStandardItem* itemChild = new QStandardItem(QString::fromLocal8Bit("文件夹1"));//定义子目录表
		itemProject->appendRow(itemChild);//itemProject->setChild(0,itemChild);//添加子目录表

		//源文件C#：TV_ShowPattern.ItemsSource = _CurrentPatternStruct;
	}
}
//保存模式按键：Button_SaveFile
//时间：2019-04-28
//作者：JZQ
void Save_FileAs(FormPatternMaker *thethis)
{//Qt 文件的新建、打开、保存、另存为 (改进版本)《https://blog.csdn.net/WQ_1996/article/details/78265279》
	//这里先打开一个测试用例：先打开一个文件，再将其另存为：要修改。
	CurrentPatternContent = new QTextEdit(thethis);
	CurrentPatternContent->document()->setModified(false);
	CurrentPatternContent->setVisible(false);//在界面不可见
	thethis->openFilePath = QString::fromLocal8Bit("G:/11111.txt");//"G:/干部评测系统/第一轮模式.cpm"或G:/11111.txt
	QFile *file = new QFile(thethis->openFilePath);
	if (!file->open(QFile::ReadWrite | QIODevice::Text))
	{
		QMessageBox::warning(thethis, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("文件打开失败！"));
		thethis->openFilePath = "";
		return;
	}
	QTextStream textStream(file);
	while (!textStream.atEnd())
	{
		CurrentPatternContent->setText(textStream.readAll());//保存打开的文件里的内容
	}
	file->close();

	//将内容另存为一个文件。
	QFileDialog *saveFileDialog = new QFileDialog(thethis);//创建一个QFileDialog对象，构造函数中的参数可以有所添加。
	QString title = QString::fromLocal8Bit("将模式：")
		+ QString::fromLocal8Bit("模式名称")
		+ QString::fromLocal8Bit("保存为");
	saveFileDialog->setWindowTitle(title);//设置文件保存对话框的标题
	saveFileDialog->setAcceptMode(QFileDialog::AcceptSave);//设置文件对话框为保存模式
	//saveFileDialog->setNameFilter(QString::fromLocal8Bit("CasitMark2.0模式文件(*.cpm)|*.cpm"));//设置文件类型过滤器
	saveFileDialog->setNameFilter(QString::fromLocal8Bit("*.txt"));//设置文件类型过滤器
	saveFileDialog->setOptions(QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);//只显示文件夹

	if (saveFileDialog->exec())//对话窗口正确执行了。
	{
		QString CurrentFilePath = saveFileDialog->selectedFiles()[0];
		QFile *file = new QFile(CurrentFilePath);
		if (!file->open(QIODevice::WriteOnly | QIODevice::Text))
		{
			QMessageBox::warning(thethis, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("文件保存失败！"));
			CurrentFilePath = "";
			return;
		}
		QTextStream textStream(file);
		textStream << CurrentPatternContent->toPlainText();//将打开的文件内容写入另存的文件
		file->close();
		QMessageBox::warning(thethis, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("文件保存成功！"));

		QFileInfo fileInfo(CurrentFilePath);//
		if (fileInfo.exists())//exists() 函数判断一个文件是否存在
		{
			QFile::remove(CurrentFilePath);//存在了，就先删除。
		}
		QString Path = fileInfo.absolutePath();//只有路径
		QString Name = fileInfo.fileName();//只有文件名（有后缀）
	}
}
void FormPatternMaker::Button_SaveFile_Click()
{
	qDebug() << "Button_SaveFile_Click Test!";
	ui.label_Msg->setVisible(false); //标签不可视
	if (true /*_CurrentEditPattern != nullptr*/)//要修改
	{
		if (true /*openFilePath != ""*/)//要修改
		{
			//弹出的消息对话框，点击确认操作。//0对应“确定”//1对应“另存为”
			if (0 == QMessageBox::question(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("是否覆盖当前模式进行保存？"),
				QString::fromLocal8Bit("确定"), QString::fromLocal8Bit("另存为")))//QMessageBox::Yes | QMessageBox::No
			{
				SavePatternFun(openFilePath);//Save(openFilePath);
				PatternModified = true;
			}
			else//点击另存为操作，即不覆盖当前模式进行保存。
			{//根据存储路径保存
				Save_FileAs(this);
				/*这两句还没法测试。
				Cm2.Common.AppConfig.AddOnePath(saveFileDialog.FileName);
				_CurrentEditPattern.SaveToFile(saveFileDialog.FileName);
				*/
				QString Text = QString::fromLocal8Bit("文件")
					+ QString::fromLocal8Bit("模式名称")
					+ QString::fromLocal8Bit("保存成功。");
				ui.L_ShowTipMessage->setText(Text);
				PatternModified = true;
			}
		}
		else
		{
			//根据存储路径保存
			SavePatternFun(openFilePath);
			PatternModified = true;
		}
	}
}
//添加模板按键：Button_AddPattern
//时间：2019-04-29
//作者：JZQ
void FormPatternMaker::Button_AddPattern_Click()
{
	qDebug() << "Button_AddPattern_Click Test!";
	ui.label_Msg->setVisible(false); //标签不可视
	ui.L_ShowTipMessage->setText(QString::fromLocal8Bit("对新建模式进行配置，选择本模式需要识别的模板图像。"));
	AddPatternFun();
}


