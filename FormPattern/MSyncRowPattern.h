#pragma once

//using namespace System;
//using namespace System::Collections::Generic;
#include "MRegion.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace Cm2
{
	namespace FormPattern {
		//ref class MRegion;
		//[Serializable]
		class MSyncRowPattern
		{
		public:
			MSyncRowPattern(void);
			~MSyncRowPattern();

			// 左同步道搜索区域
			MRegion *LeftSyncRowSearchArea;
			// 左同步道坐标大小参数
			vector<MRegion*> *LeftSyncRows;
			// 右同步道搜索区域
			MRegion *RightSyncRowSearchArea;
			// 右同步道坐标大小参数
			vector<MRegion*> *RightSyncRows;
		};
	};
};

