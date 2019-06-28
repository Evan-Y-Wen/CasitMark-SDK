#pragma once

//#include "GlobalDefinitions.h"
#include "MRegion.h"
#include "EnumSet.h"
#include <QRect>
#include <QColor>

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <math.h>
using namespace std;

namespace Cm2
{
	namespace FormPatternMaker
	{
		/// <summary>
		/// 参数构造器
		/// </summary>
		static class RegionArgumentBuilder
		{
		public:
			RegionArgumentBuilder();
			~RegionArgumentBuilder();

		public:
			static vector<Cm2::FormPattern::MRegion*> *S_lastMarkRegion;//这里用一维指针数组来实现，二维数组
			static Cm2::FormPattern::MRegion *S_region;
			static unordered_set<string> *s_allChangeMatrix;
			static double centerX;
			static double centerY;
			static string barCodeValue;
			static bool IsMark;
			static bool IsCheck;
			static int32_t indexSeven;
			static int32_t indexSycn;

			/// <summary>
			/// 创建区域参数
			/// </summary>
			/// <param name="iRect">区域</param>
			/// <param name="iType">区域类型</param>
			/// <returns></returns>
		public:
			static Cm2::FormPattern::MRegion *BuildRegionArgument(QRect &iRect, Cm2::FormPatternMaker::EnumSet::RecognizeType &iType);
/*
			/// <summary>
			/// 创建定位标志区域
			/// </summary>
			/// <param name="iRect">区域范围</param>
			/// <returns>创建成功与否</returns>
		public:
			static Cm2::FormPattern::MRegion *BuildLocationMarkRegionArgument(QRect &iRect, bool iRemoveOldNode = false);
		private:
			static Cm2::FormPattern::MRegion *BuildMarkRegionArgument(QRect &iRect);
			

			/// <summary>
			/// 创建填涂块识别区域
			/// </summary>
			/// <param name="iRect"></param>
			/// <returns></returns>
		private :
			static Cm2::FormPattern::MRegion *BuildMarkRegionArgument(QRect &iRect, bool IsContinue);
			

			/// <summary>
			/// 创建截图参数
			/// </summary>
			/// <param name="iRect"></param>
			/// <returns></returns>
		private:
			static Cm2::FormPattern::MRegion *BuildImageshotArgument(QRect &iRect);

			/// <summary>
			/// 创建OCR识别参数
			/// </summary>
			/// <param name="iRect"></param>
			/// <returns></returns>
		private:
			static Cm2::FormPattern::MRegion *BuildOCRArgument(QRect &iRect);

			/// <summary>
			/// 创建条码或二位码识别参数
			/// </summary>
			/// <param name="iRect"></param>
			/// <returns></returns>
		private:
			static Cm2::FormPattern::MRegion *BuildBarOr2DCodeArgument(QRect &iRect);
			

			/// <summary>
			/// 创建七段码识别参数
			/// </summary>
			/// <param name="iRect"></param>
			/// <returns></returns>
		private:
			static Cm2::FormPattern::MRegion *BuildSevenArgument(QRect &iRect);
			

			/// <summary>
			/// 创建同步道识别参数
			/// </summary>
			/// <param name="iRect"></param>
			/// <returns></returns>
		private:
			static Cm2::FormPattern::MRegion *BuildSycnArgument(QRect &iRect, bool iRemoveOldNode = false);
		public:
			static void DeleteFormChangeMatrix(const string &iPatternGUID, const int32_t &iFormIndex);
		public:
			static void DeletePatternMatrix(const string &iPatternGUID);
			*/
		};
	}
}