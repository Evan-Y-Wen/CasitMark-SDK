#pragma once

//using namespace System;
#include "MRegion.h"
#include <iostream>
#include <string>
using namespace std;

namespace Cm2
{
	namespace FormPattern {
		//class MRegion;
		//[Serializable] 
		class MLocatePattern
		{
		public:
			MLocatePattern();
			~MLocatePattern();

			// 起始搜索区域
			MRegion *StartSearchRegion;
			// 起始搜索区域
			MRegion *EndSearchRegion;
			// 若是图形匹配，则记录起始图形区域位置
			MRegion *StartShapeRegion;
			// 若是图形匹配，则记录结束图形区域位置
			MRegion *EndShapeRegion;
			// 若是简单码匹配，则记录起始简单码的值
			int StartSimpleCodeValue;
			// 若是简单码匹配，则记录结束简单码的值
			int EndSimpleCodeValue;
		};
	};
};

