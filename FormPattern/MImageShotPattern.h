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
		// ��ͼ��Ϣ
		class MImageShotPattern
		{
		public:
			MImageShotPattern(void);
			~MImageShotPattern();

			// �Ƿ�ʹ�÷��ͼ�ζ�λ
			vector<bool> *IsNeedClosedShapeSure;
			// ��ͼλ����Ϣ
			vector<MRegion*> *ShotRegions;
			// �Ƿ�����ֵ�ж�
			vector<bool> *IsThresholdDetermine;
			// ��ͼ��ֵ��0~1Ϊ�ٷֱȣ�>1Ϊ����
			vector<double> *ShotThresholds;

			// ����ͬ����ʱ��¼ÿ���������ͬ��������
			vector<MSyncLocate*> *SyncLocates;
		};
	};
};

