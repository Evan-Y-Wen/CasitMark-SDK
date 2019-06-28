#pragma once

//using namespace System;
//using namespace System::Collections::Generic;
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace Cm2
{
	namespace FormPattern {
		// 填涂块组结果显示方式
		enum MResultMode
		{
			Binary,
			SingleSelect
		};
		// 填涂块组
		//[Serializable] 
		class MMarkGroup
		{
		public:
			MMarkGroup(string &groupName);
			~MMarkGroup();

			// 组名
			string GroupName;
			// 结果显示方式
			MResultMode ResultMode;//enum MResultMode
			// 组内填涂块索引
			vector<int> *BlockIndexs;
		};
	};
};

