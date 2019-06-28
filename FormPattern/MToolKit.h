#pragma once

//using namespace System;
//using namespace System::Collections::Generic;
#include "MMarkBlock.h"
#include "MRegion.h"
#include "MRelativeRegion.h"
#include <iostream>
#include <string>
#include <vector>
//#include <QBitmap>//�򲻿�Դ�ļ���Ӧ����Ҫ���ظ���չ�ļ���
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

			// ���ݻҶ�ͼ�����ݴ���Bitmap
			//��Ҫ�޸ġ����ᡢ������QT����QBitmap��C++  STL����bitset
			//static System::Drawing::Bitmap* CreateGrayImage(vector<unsigned char> &imageData, int width, int height);
		};
	};
};

