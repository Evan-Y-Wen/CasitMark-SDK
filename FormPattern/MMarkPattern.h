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
		// 填涂块信息
		class MMarkPattern
		{
		public:
			MMarkPattern(void);
			~MMarkPattern();

			// 填涂框集合
			vector<MMarkBlock*> *MarkBlockSet;
			// 填涂块分组信息
			vector<MMarkGroup*> *MarkGroups;

			// 当有同步道时记录每个块关联的同步道数据，制作模式时可以不用管
			vector<MSyncLocate*> *SyncLocates;
		};
	};
};

