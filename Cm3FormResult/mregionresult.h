#pragma once

#include <QString>

namespace Cm3
{
	namespace FormResult
	{
		class MRegionResult
		{
		public:
			MRegionResult();
			~MRegionResult();

			MRegionResult(double x, double y, double w, double h);

			MRegionResult * DeepClone();

		private:
			// 区域名称
			QString _name;

			// 区域中心坐标X
			double _x;

			// 区域中心坐标Y
			double _y;

			// 区域宽度
			double _width;

			// 区域高度
			double _height;

			// 区域背景色
			QString _backgroundColor;

			// 区域边框颜色
			QString _borderColor;
		};
	}
}
