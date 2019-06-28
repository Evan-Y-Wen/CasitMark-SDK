#pragma once

//using namespace System;

namespace Cm2
{
	namespace FormPattern {
		//[Serializable] 
		class MSyncLocate
		{
		public:
			MSyncLocate(void);
			~MSyncLocate();

			// 关联的同步道索引
			int SyncRowIndex;
			// 相对于同步道中心的X坐标
			int SyncRowElapseX;
			// 相对于同步道中心的Y坐标
			int SyncRowElapseY;
			// 模版图像黑点数
			int TmpBlackDots;
		};
	};
};

