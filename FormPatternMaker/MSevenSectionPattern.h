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
		// 七段码信息
		//[Serializable] 
		class MSevenSectionPattern
		{
		public:
			MSevenSectionPattern(void);
			~MSevenSectionPattern();

			// 七段码识别区域
			vector<MRegion*> *SevenSections;

			// 当有同步道时记录每个块关联的同步道数据，制作模式时可以不用管
			vector<MSyncLocate*> *SyncLocates;
		};
	};
};

