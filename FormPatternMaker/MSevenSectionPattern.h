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
		// �߶�����Ϣ
		//[Serializable] 
		class MSevenSectionPattern
		{
		public:
			MSevenSectionPattern(void);
			~MSevenSectionPattern();

			// �߶���ʶ������
			vector<MRegion*> *SevenSections;

			// ����ͬ����ʱ��¼ÿ���������ͬ�������ݣ�����ģʽʱ���Բ��ù�
			vector<MSyncLocate*> *SyncLocates;
		};
	};
};

