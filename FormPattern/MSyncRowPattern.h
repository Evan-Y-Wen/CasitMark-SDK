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

			// ��ͬ������������
			MRegion *LeftSyncRowSearchArea;
			// ��ͬ���������С����
			vector<MRegion*> *LeftSyncRows;
			// ��ͬ������������
			MRegion *RightSyncRowSearchArea;
			// ��ͬ���������С����
			vector<MRegion*> *RightSyncRows;
		};
	};
};

