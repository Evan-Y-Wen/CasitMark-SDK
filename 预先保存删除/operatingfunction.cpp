#include "operatingfunction.h"
#include "formpatternmaker.h"//������ͷ�ļ�
#include "createpattern.h"//�½�ģʽ�Ӵ���
#include "addpattern.h"//���ģ���Ӵ���
#include <QDebug>
#include <QDir>

// �˴��������в��������Ķ���

// �½�ģʽ
void CreatePatternFun(FormPatternMaker *TheMainWindow)
{
	//L_ShowTipMessage.Content = "���½�ģʽ�������ã�ѡ��ģʽ��Ҫʶ���ģ��ͼ��";

	//�����½�ģʽ�����´���--Button_NewFile��ť����¼������Ϣ����֮����ʾ
	CreatePattern *cpwnd = new CreatePattern(TheMainWindow);
	cpwnd->exec();//���Ӵ��������½��ļ��Ĳ�����

	qDebug() << "CreatePatternFun Test!";
	/*
	if (cpwnd->m_CreatePatternSuccessed)
	{
		QString dir_str = QDir::currentPath() + "\\NewPatternImages";//���Ӧ�ó���ǰ����Ŀ¼��

		// ���Ŀ¼�Ƿ���ڣ������������½�
		QDir dir;
		if (!dir.exists(dir_str))
		{
			bool res = dir.mkpath(dir_str);
			qDebug() << "�½�Ŀ¼�Ƿ�ɹ�" << res;
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

// ��ģʽ
// ���ؼ��ص�ģʽ�ļ�(public Cm2.FormPattern.MPattern���͵��ļ�)�����ش���ʱ���ؿ�.
QFile *OpenPatternFromFileFun(const QString &openFileNames)
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

//����ģʽ
void SavePatternFun(const QString & iFilePath)
{
	qDebug() << "SavePatternFun Test!";
}

//���ģ��
void AddPatternFun()
{
	//�������ģ�崰���´���--Button_AddPattern��ť����¼�����ʾ
	AddPattern *cpwnd = new AddPattern;
	cpwnd->show();//���Ӵ����������ģ��Ĳ�����
	qDebug() << "AddPatternFun Test!";
}
