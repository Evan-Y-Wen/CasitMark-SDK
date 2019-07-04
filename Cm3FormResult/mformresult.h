#pragma once

#include <QString>
#include "mgroupresult.h"


namespace Cm3
{
	namespace FormResult
	{
		class MFormResult
		{
		public:
			MFormResult();
			~MFormResult();


		private:
			// 表格在模式中的索引
			int _formIndex;

			// 表格图像文件名
			QString _formImageName;

			// 表格图像是否为空白纸
			bool _isBlank;

			// 表格是否正向
			bool _isForwardDirection;

			// 该结果是否为矫正后结果
			bool _isRectified;

			// 填涂块结果
			MGroupResult * _markGroupResult;

		};
	}
}