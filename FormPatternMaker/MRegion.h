#pragma once

//using namespace System;
#include <iostream>
#include <string>
using namespace std;

namespace Cm2
{
	namespace FormPattern {
		//[Serializable] 
		class MRegion
		{
		public:
			MRegion(void);
			MRegion(int x, int y, int w, int h);
			~MRegion();//手动管理内存

			// 区域名称
			string Name;
			// 区域中心坐标X
			int X;
			// 区域中心坐标Y
			int Y;
			// 区域宽度
			int Width;
			// 区域高度
			int Height;
			/// 区域背景色
			string BackgroundColor;
            /// 区域边框颜色
			string BorderColor;

			void InRegion(int x, int y, int w, int h);

			void InRegion(MRegion &region);//传入参数是指针还是引用，意义相同没用区别，只是用法不同

			MRegion *DeepClone();//这里返回局部变量地址，匿名对象问题，需要将匿名对象扶正。

		};
	};
};

