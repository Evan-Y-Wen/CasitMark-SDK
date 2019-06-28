#pragma once

//using namespace System;
#include <iostream>
#include <string>
#include "MRegion.h"
using namespace std;

namespace Cm2
{
	namespace FormPattern {
		//class MRegion;
		// 填涂块信息
		//[Serializable] 
		class MMarkBlock
		{
		public:
			MMarkBlock(void);
			~MMarkBlock();

			// 填涂框模式坐标
			MRegion *Position;
			// 填涂认定域值,0~1为百分比，>1为点数
			double MarkValidThreshold;
			// 填涂块文本标签
			string LabelText;
		};
	};
};

