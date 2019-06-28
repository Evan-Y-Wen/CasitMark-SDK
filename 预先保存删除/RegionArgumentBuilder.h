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
		/// ����������
		/// </summary>
		static class RegionArgumentBuilder
		{
		public:
			RegionArgumentBuilder();
			~RegionArgumentBuilder();

		public:
			static vector<Cm2::FormPattern::MRegion*> *S_lastMarkRegion;//������һάָ��������ʵ�֣���ά����
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
			/// �����������
			/// </summary>
			/// <param name="iRect">����</param>
			/// <param name="iType">��������</param>
			/// <returns></returns>
		public:
			static Cm2::FormPattern::MRegion *BuildRegionArgument(QRect &iRect, Cm2::FormPatternMaker::EnumSet::RecognizeType &iType);
/*
			/// <summary>
			/// ������λ��־����
			/// </summary>
			/// <param name="iRect">����Χ</param>
			/// <returns>�����ɹ����</returns>
		public:
			static Cm2::FormPattern::MRegion *BuildLocationMarkRegionArgument(QRect &iRect, bool iRemoveOldNode = false);
		private:
			static Cm2::FormPattern::MRegion *BuildMarkRegionArgument(QRect &iRect);
			

			/// <summary>
			/// ������Ϳ��ʶ������
			/// </summary>
			/// <param name="iRect"></param>
			/// <returns></returns>
		private :
			static Cm2::FormPattern::MRegion *BuildMarkRegionArgument(QRect &iRect, bool IsContinue);
			

			/// <summary>
			/// ������ͼ����
			/// </summary>
			/// <param name="iRect"></param>
			/// <returns></returns>
		private:
			static Cm2::FormPattern::MRegion *BuildImageshotArgument(QRect &iRect);

			/// <summary>
			/// ����OCRʶ�����
			/// </summary>
			/// <param name="iRect"></param>
			/// <returns></returns>
		private:
			static Cm2::FormPattern::MRegion *BuildOCRArgument(QRect &iRect);

			/// <summary>
			/// ����������λ��ʶ�����
			/// </summary>
			/// <param name="iRect"></param>
			/// <returns></returns>
		private:
			static Cm2::FormPattern::MRegion *BuildBarOr2DCodeArgument(QRect &iRect);
			

			/// <summary>
			/// �����߶���ʶ�����
			/// </summary>
			/// <param name="iRect"></param>
			/// <returns></returns>
		private:
			static Cm2::FormPattern::MRegion *BuildSevenArgument(QRect &iRect);
			

			/// <summary>
			/// ����ͬ����ʶ�����
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