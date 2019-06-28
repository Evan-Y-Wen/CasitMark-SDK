#pragma once

//using namespace System;
//using namespace System::Collections::Generic;
#include "MRegion.h"
#include "MSyncLocate.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace Cm2
{
	namespace FormPattern {
		//class MRegion;
		//class MSyncLocate;
		// 截图信息
		class MImageShotPattern
		{
		public:
			MImageShotPattern(void);
			~MImageShotPattern();

			// 是否使用封闭图形定位
			vector<bool> *IsNeedClosedShapeSure;
			// 截图位置信息
			vector<MRegion*> *ShotRegions;
			// 是否有阈值判定
			vector<bool> *IsThresholdDetermine;
			// 截图阈值，0~1为百分比，>1为点数
			vector<double> *ShotThresholds;

			// 当有同步道时记录每个块关联的同步道数据
			vector<MSyncLocate*> *SyncLocates;
		};
	};
};

