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
		//ref class MRegion;
		//ref class MSyncLocate;
		// OCR信息
		//[Serializable] 
		class MOCRPattern
		{
		public:
			MOCRPattern(void);
			~MOCRPattern();

			// 是否使用封闭图形定位
			vector<bool> *IsNeedClosedShapeSure;
			// 识别区域
			vector<MRegion*> *OCRRegions;
			// 识别语言
			vector<string*> *LanguageOption;

			// 当有同步道时记录每个块关联的同步道数据，制作模式时可以不用管
			vector<MSyncLocate*> *SyncLocates;
		};
	};
};

