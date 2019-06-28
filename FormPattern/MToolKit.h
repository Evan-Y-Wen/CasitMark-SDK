#pragma once

//using namespace System;
//using namespace System::Collections::Generic;
#include "MMarkBlock.h"
#include "MRegion.h"
#include "MRelativeRegion.h"
#include <iostream>
#include <string>
#include <vector>
//#include <QBitmap>//打不开源文件，应该是要下载该扩展文件。
using namespace std;

namespace Cm2
{
	namespace FormPattern {
		//ref class MMarkBlock;
		//ref class MRegion;
		//ref class MRelativeRegion;
		class MToolKit
		{
		public:
			MToolKit(void);
			~MToolKit();

			static void ConvertToStdString(string &mstr, std::string& str);

			static double Distance(Cm2::FormPattern::MRegion &from, Cm2::FormPattern::MRegion &to);
			static double Distance(Cm2::FormPattern::MRelativeRegion &from, Cm2::FormPattern::MRegion &to);

			static int FindMostClosestRegion(vector<Cm2::FormPattern::MRegion*> &regions, Cm2::FormPattern::MRegion &relative);

			static int FindMostClosestRegionWithIgnore(vector<Cm2::FormPattern::MRegion*> &regions, vector<bool> &ignore, Cm2::FormPattern::MRegion &relative);

			static int FindMostClosestBlock(vector<Cm2::FormPattern::MMarkBlock*> &blocks, Cm2::FormPattern::MRegion &relative);

			static int FindMostClosestBlockWithIgnore(vector<Cm2::FormPattern::MMarkBlock*> &blocks, vector<bool> &ignore, Cm2::FormPattern::MRegion &relative);

			static int FindMostClosestRelativeRegion(vector<Cm2::FormPattern::MRelativeRegion*> &regions, Cm2::FormPattern::MRegion &relative);

			static int FindMostClosestRelativeRegionWithIgnore(vector<Cm2::FormPattern::MRelativeRegion*> &regions, vector<bool> &ignore, Cm2::FormPattern::MRegion &relative);

			// 根据灰度图像数据创建Bitmap
			//需要修改。不会、、、、QT里有QBitmap，C++  STL里有bitset
			//static System::Drawing::Bitmap* CreateGrayImage(vector<unsigned char> &imageData, int width, int height);
		};
	};
};

