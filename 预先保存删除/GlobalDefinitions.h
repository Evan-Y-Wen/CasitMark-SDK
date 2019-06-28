#pragma once


#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>
using namespace std;

//另一个工程项目：FormPattern，的头文件
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


/////记得释放内存。。。。。*****
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
/// 当前编辑模式的表单索引
/// </summary>
static int32_t s_CurrentSelectedFormIndex = 0;
static MRegion *m_clipRegion = nullptr;
static bool _deleteBlock = false;
static bool _deleteGroup = false;

/// <summary>
/// 当前拥有的所有模式
/// </summary>
static unordered_map<string, Cm2::FormPattern::MPattern *> *s_Patterns = new unordered_map<string, Cm2::FormPattern::MPattern *>;

//当前路径
static QString openFilePath = QCoreApplication::applicationDirPath();
