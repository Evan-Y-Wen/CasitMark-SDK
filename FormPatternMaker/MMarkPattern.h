#pragma once

//using namespace System;
//using namespace System::Collections::Generic;
#include "MMarkBlock.h"
#include "MMarkGroup.h"
#include "MSyncLocate.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace Cm2
{
	namespace FormPattern {
		//class MMarkBlock;
		//class MMarkGroup;
		//class MSyncLocate;
		// ��Ϳ����Ϣ
		class MMarkPattern
		{
		public:
			MMarkPattern(void);
			~MMarkPattern();

			// ��Ϳ�򼯺�
			vector<MMarkBlock*> *MarkBlockSet;
			// ��Ϳ�������Ϣ
			vector<MMarkGroup*> *MarkGroups;

			// ����ͬ����ʱ��¼ÿ���������ͬ�������ݣ�����ģʽʱ���Բ��ù�
			vector<MSyncLocate*> *SyncLocates;
		};
	};
};

