#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_formpatternmaker.h"
#include <QFile>
#include <iostream>
#include <unordered_map>
using namespace std;


class FileTreeModel;
class PatternNode;

////��һ��������Ŀ��FormPattern����ͷ�ļ����ϲ�������������ˡ�
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


// formpatternmaker.h �Ľ����߼��Ķ���

//��ͨ��Ա����//////////////////////////////////////////////////////////////////////////
//��ͨ��Ա����//////////////////////////////////////////////////////////////////////////
//��ͨ��Ա����//////////////////////////////////////////////////////////////////////////
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
	/// ��ǰ�༭ģʽ�ı�����
	/// </summary>
	int32_t s_CurrentSelectedFormIndex = 0;
	MRegion *m_clipRegion = nullptr;
	bool _deleteBlock = false;
	bool _deleteGroup = false;

	/// <summary>
	/// ��ǰӵ�е�����ģʽ
	/// </summary>
	unordered_map<string, Cm2::FormPattern::MPattern *> *s_Patterns = new unordered_map<string, Cm2::FormPattern::MPattern *>;

	//��ǰ·��
	QString openFilePath = QCoreApplication::applicationDirPath();

	//Tree�ṹ�ڵ�
	FileTreeModel *model;

//��ͨ��Ա����//////////////////////////////////////////////////////////////////////////
//��ͨ��Ա����//////////////////////////////////////////////////////////////////////////
//��ͨ��Ա����//////////////////////////////////////////////////////////////////////////
public:
	void CreatePatternFun();//�½�ģʽ�����������
	// ���ؼ��ص�ģʽ�ļ�(public Cm2.FormPattern.MPattern���͵��ļ�)�����ش���ʱ���ؿ�.
	QFile *OpenPatternFromFileFun(const QString &openFileNames);//��ģʽ�����������
	void SavePatternFun(const QString &iFilePath);//����ģʽ�����������
	void AddPatternFun();//���ģ�塪���������


//�ź�//////////////////////////////////////////////////////////////////////////
//�ź�//////////////////////////////////////////////////////////////////////////
//�ź�//////////////////////////////////////////////////////////////////////////
signals:
	void Button_NewFile_Hover_Signal();

//�ۺ���//////////////////////////////////////////////////////////////////////////
//�ۺ���//////////////////////////////////////////////////////////////////////////
//�ۺ���//////////////////////////////////////////////////////////////////////////
public slots:
	//ui_formpatternmaker�ۺ���
	void Button_NewFile_Click();//���������½�ģʽ��ť�������
	void Button_OpenFile_Click();//����������ģʽ��ť�������
	void Button_SaveFile_Click();//������������ģʽ��ť�������
	void Button_AddPattern_Click();//�����������ģ�尴ť�������

};