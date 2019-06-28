#include "operatingfunction.h"
#include "formpatternmaker.h"//主窗口头文件
#include "createpattern.h"//新建模式子窗口
#include "addpattern.h"//添加模板子窗口
#include <QDebug>
#include <QDir>

// 此处定义所有操作函数的定义

// 新建模式
void CreatePatternFun(FormPatternMaker *TheMainWindow)
{
	//L_ShowTipMessage.Content = "对新建模式进行配置，选择本模式需要识别的模板图像。";

	//弹出新建模式窗口新窗口--Button_NewFile按钮点击事件后的消息弹窗之后显示
	CreatePattern *cpwnd = new CreatePattern(TheMainWindow);
	cpwnd->exec();//在子窗口内做新建文件的操作。

	qDebug() << "CreatePatternFun Test!";
	/*
	if (cpwnd->m_CreatePatternSuccessed)
	{
		QString dir_str = QDir::currentPath() + "\\NewPatternImages";//获得应用程序当前工作目录。

		// 检查目录是否存在，若不存在则新建
		QDir dir;
		if (!dir.exists(dir_str))
		{
			bool res = dir.mkpath(dir_str);
			qDebug() << "新建目录是否成功" << res;
		}
		//else
		//{
		//	System.IO.Directory.CreateDirectory(Directory.GetCurrentDirectory() + "\\NewPatternImages");
		//}
		//TB_PatternName.Text = _CurrentEditPattern.PatternName;
		//openFilePath = "";
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
	}*/
}

// 打开模式
// 返回加载的模式文件(public Cm2.FormPattern.MPattern类型的文件)，加载错误时返回空.
QFile *OpenPatternFromFileFun(const QString &openFileNames)
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

//保存模式
void SavePatternFun(const QString & iFilePath)
{
	qDebug() << "SavePatternFun Test!";
}

//添加模板
void AddPatternFun()
{
	//弹出添加模板窗口新窗口--Button_AddPattern按钮点击事件后显示
	AddPattern *cpwnd = new AddPattern;
	cpwnd->show();//在子窗口内做添加模板的操作。
	qDebug() << "AddPatternFun Test!";
}
