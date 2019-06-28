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
		//[Serializable] 
		enum MBarCodeType
		{
			// 不认识
			UNRECOGNIZED = 0,
			// 条码
			UPC_A,
			UPC_E,
			EAN_8,
			EAN_13,
			CODE_128,
			CODE_39,
			ITF,
			PDF417,

			// 二维码
			QR_CODE,
			DATAMATRIX,

			// 简单码，在"MPattern.h"里也有个SimpleCode，所以这里稍作改变
			SimpleCodeForBarCodeType
		};
		//class MRegion;
		//class MSyncLocate;
		// 条码信息
		//[Serializable] 
		class MBarcodePattern
		{
		public:
			MBarcodePattern(void);
			~MBarcodePattern();

			// 条码识别区域
			vector<MRegion*> *BarCodeSearchRegions;
			// 条码识别类型
			vector<MBarCodeType> *BarCodeTypes;//enum MBarCodeType，指针指向枚举类型的数组。

			// 当有同步道时记录每个块关联的同步道数据，制作模式时可以不用管
			vector<MSyncLocate*> *SyncLocates;
		};
	};
};

