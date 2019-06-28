#pragma once


#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>
using namespace std;

//��һ��������Ŀ��FormPattern����ͷ�ļ�
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


/////�ǵ��ͷ��ڴ档��������*****
static MPattern *_CurrentEditPattern = nullptr;
static MFormPattern *_CurrentEditFormPattern = nullptr;
static MLocatePattern *_mLocatePattern = new MLocatePattern();
static MMarkPattern *_mMarkPattern = new MMarkPattern();
static MOCRPattern *_mOCRPattern = new MOCRPattern();
static MBarcodePattern *_mBarcodePattern = new MBarcodePattern();
static MSevenSectionPattern *_mSevenSectionPattern = new MSevenSectionPattern();
static MSyncRowPattern *_mSyncRowPattern = new MSyncRowPattern();
static MImageShotPattern *_mImageShotPattern = new MImageShotPattern();
static MMarkPattern *g_MarkPattern = new MMarkPattern();

/// <summary>
/// ��ǰ�༭ģʽ�ı�����
/// </summary>
static int32_t s_CurrentSelectedFormIndex = 0;
static MRegion *m_clipRegion = nullptr;
static bool _deleteBlock = false;
static bool _deleteGroup = false;

/// <summary>
/// ��ǰӵ�е�����ģʽ
/// </summary>
static unordered_map<string, Cm2::FormPattern::MPattern *> *s_Patterns = new unordered_map<string, Cm2::FormPattern::MPattern *>;

//��ǰ·��
static QString openFilePath = QCoreApplication::applicationDirPath();
