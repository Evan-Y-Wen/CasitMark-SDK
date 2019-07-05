#pragma once

#include <QString>
#include "mgroupresult.h"
#include "midentifierresult.h"


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
			// 表格名称
			QString _formName;

			// 表格在模式中的索引
			int _formIndex;

			// 表格图像文件名
			QString _formImageName;

			// todo:上面三个属性都是表格结果对应图像的信息，我觉得放在MFormImageFile类中更好。

			// 表格图像是否为空白纸
			bool _isBlank;

			// 表格是否正向
			bool _isForwardDirection;

			// 该结果是否为矫正后结果
			bool _isRectified;

			// 识别的填涂块结果
			MGroupResult * _markGroupResult;

			// 截图结果
			MGroupResult * _imageShotResult;

			// 标志码结果：简单码或二维码
			MIdentifierResult * _identifierResult;

		};
	}
}