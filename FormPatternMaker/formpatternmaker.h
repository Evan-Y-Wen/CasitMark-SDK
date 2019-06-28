#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_formpatternmaker.h"
#include <QFile>
#include <iostream>
#include <unordered_map>
using namespace std;


class FileTreeModel;
class PatternNode;

////另一个工程项目：FormPattern，的头文件，合并到这个工程里了。
#include "LWindowsHelper.h"
#include "MBarcodePattern.h"
#include "MFormPattern.h"
#include "MImageShotPattern.h"
#include "MLocatePattern.h"
#include "MMarkBlock.h"
#include "MMarkGroup.h"
#include "MMarkPattern.h"
#include "MOCRPattern.h"
#include "MPattern.h"
#include "MRegion.h"
#include "MRelativeRegion.h"
#include "MSevenSectionPattern.h"
#include "MSyncLocate.h"
#include "MSyncRowPattern.h"
#include "MToolKit.h"
using namespace Cm2::FormPattern;

class FormPatternMaker : public QMainWindow
{
	Q_OBJECT

public:
	FormPatternMaker(QWidget *parent = Q_NULLPTR);
	~FormPatternMaker();
private:
	Ui::FormPatternMakerClass ui;


// formpatternmaker.h 的交互逻辑的定义

//普通成员变量//////////////////////////////////////////////////////////////////////////
//普通成员变量//////////////////////////////////////////////////////////////////////////
//普通成员变量//////////////////////////////////////////////////////////////////////////
public:
	MPattern *_CurrentEditPattern = nullptr;
	MFormPattern *_CurrentEditFormPattern = nullptr;
	MLocatePattern *_mLocatePattern = new MLocatePattern();
	MMarkPattern *_mMarkPattern = new MMarkPattern();
	MOCRPattern *_mOCRPattern = new MOCRPattern();
	MBarcodePattern *_mBarcodePattern = new MBarcodePattern();
	MSevenSectionPattern *_mSevenSectionPattern = new MSevenSectionPattern();
	MSyncRowPattern *_mSyncRowPattern = new MSyncRowPattern();
	MImageShotPattern *_mImageShotPattern = new MImageShotPattern();
	MMarkPattern *g_MarkPattern = new MMarkPattern();

	/// <summary>
	/// 当前编辑模式的表单索引
	/// </summary>
	int32_t s_CurrentSelectedFormIndex = 0;
	MRegion *m_clipRegion = nullptr;
	bool _deleteBlock = false;
	bool _deleteGroup = false;

	/// <summary>
	/// 当前拥有的所有模式
	/// </summary>
	unordered_map<string, Cm2::FormPattern::MPattern *> *s_Patterns = new unordered_map<string, Cm2::FormPattern::MPattern *>;

	//当前路径
	QString openFilePath = QCoreApplication::applicationDirPath();

	//Tree结构节点
	FileTreeModel *model;

//普通成员函数//////////////////////////////////////////////////////////////////////////
//普通成员函数//////////////////////////////////////////////////////////////////////////
//普通成员函数//////////////////////////////////////////////////////////////////////////
public:
	void CreatePatternFun();//新建模式——具体操作
	// 返回加载的模式文件(public Cm2.FormPattern.MPattern类型的文件)，加载错误时返回空.
	QFile *OpenPatternFromFileFun(const QString &openFileNames);//打开模式——具体操作
	void SavePatternFun(const QString &iFilePath);//保存模式——具体操作
	void AddPatternFun();//添加模板——具体操作


//信号//////////////////////////////////////////////////////////////////////////
//信号//////////////////////////////////////////////////////////////////////////
//信号//////////////////////////////////////////////////////////////////////////
signals:
	void Button_NewFile_Hover_Signal();

//槽函数//////////////////////////////////////////////////////////////////////////
//槽函数//////////////////////////////////////////////////////////////////////////
//槽函数//////////////////////////////////////////////////////////////////////////
public slots:
	//ui_formpatternmaker槽函数
	void Button_NewFile_Click();//工具栏：新建模式按钮点击操作
	void Button_OpenFile_Click();//工具栏：打开模式按钮点击操作
	void Button_SaveFile_Click();//工具栏：保存模式按钮点击操作
	void Button_AddPattern_Click();//工具栏：添加模板按钮点击操作

};