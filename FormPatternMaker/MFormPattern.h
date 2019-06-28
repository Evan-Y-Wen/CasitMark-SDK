#pragma once

//using namespace System;
//using namespace System::Collections::Generic;
#include "MRegion.h"
#include "MLocatePattern.h"
#include "MMarkPattern.h"
#include "MImageShotPattern.h"
#include "MSevenSectionPattern.h"
#include "MBarcodePattern.h"
#include "MOCRPattern.h"
#include "MSyncRowPattern.h"
#include "MRelativeRegion.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace Cm2
{
	namespace FormPattern {
		// 模板类型
		enum MTemplateFileType
		{
			Image,
			WordFile
		};
		//class MRegion;
		//class MLocatePattern;
		//class MMarkPattern;
		//class MImageShotPattern;
		//class MSevenSectionPattern;
		//class MBarcodePattern;
		//class MOCRPattern;
		//class MSyncRowPattern;
		//class MRelativeRegion;
		// 表格模式
		//[Serializable] 
		class MFormPattern
		{
		public:
			MFormPattern(string &formName);
			~MFormPattern();

			// 表格名称
			string FormName;
			// 模版文件类型
			MTemplateFileType TemplateFileType;//enum MTemplateFileType
			// 模版图像二值化阈值
			int TemplateImageBinirizeThreshold;
			// 若为图像数据，格式为2位深度tiff黑白图
			vector<unsigned char> *PatternImage;
			// 模式图像排版方向
			bool IsLandscape;
			// 定位信息
			MLocatePattern *LocatePattern;
			// 填涂块信息
			MMarkPattern *MarkPattern;
			// 截图信息
			MImageShotPattern *ImageShotPattern;
			// 条码信息
			MBarcodePattern *BarcodePattern;
			// 七段码信息
			MSevenSectionPattern *SevenSectionPattern;
			// OCR信息
			MOCRPattern *OCRPattern;
			// 左右同步道模式
			MSyncRowPattern *SyncRowPattern;

			// 模式文件释放后得到临时数据
			// 识别时，tiff黑白图解压出图像数据
			vector<unsigned char> *PatternImageData;
			// 模式图像宽
			int PatternImageWidth;
			// 模式图像高
			int PatternImageHeight;
			// 定位块连线角度
			double LocateAngle;
			// 定位块连线长度
			double LocateDistance;
			// 搜索顺序
			vector<MRelativeRegion*> *SearchSeq;

			// 第一个封闭定位区域
			MRegion *firstRegion;
			int CountBlackDotsOnRegion(Cm2::FormPattern::MRegion &region);
			// 获得区域图像
			vector<unsigned char> *GetRegionImgData(Cm2::FormPattern::MRegion &region);//返回指针类型，记得将匿名对象扶正
		};
	};
};

