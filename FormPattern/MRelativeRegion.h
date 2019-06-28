#pragma once

//using namespace System;
//using namespace System::Collections::Generic;

namespace Cm2
{
	namespace FormPattern {
		//[Serializable] 
		class MRelativeRegion
		{
		public:
			MRelativeRegion(void);
			~MRelativeRegion();

			// 区域类型0-填涂块，1-截图，2-条码，3-七段码，4-ocr
			int RegionType;

			// 原块索引
			int RegionIndex;

			// 相对坐标
			int RelativeX;
			int RelativeY;

			// 0:靠近填涂块；1：靠近起始定位标识；2：靠近结束定位标识
			int CloseType;

			// 模版图像黑点数
			int TmpBlackDots;
		};
	};
};

