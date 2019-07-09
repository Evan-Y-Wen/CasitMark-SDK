#pragma once

#include <QList>
#include <QString>
#include "mformimagefile.h"
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

			// 该结果是否为矫正后结果
			bool _isRectified;

			// 表格对应的图像信息
			MFormImageFile * _formImageFiles;// todo:我觉得将这个属性放在每一个表格结果MFormResult下面更好

			// 识别的分组结果
			QList<MGroupResult *> * _markGroupResult;

			// 截图结果，先不考虑
			// MGroupResult * _imageShotResult;

			// 标志码结果：简单码或二维码
			MIdentifierResult * _identifierResult;

		};
	}
}