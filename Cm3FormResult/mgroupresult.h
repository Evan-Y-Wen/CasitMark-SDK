#pragma once

#include <QList>
#include "mcellresult.h"
#include "mmarkgroupresult.h"

namespace Cm3
{
	namespace FormResult
	{
		class MGroupResult
		{ // 对应一个分组
		public:
			MGroupResult();
			~MGroupResult();

		private:
			// 存放一个分组中的所有单元格结果
			QList<MCellResult *> *_cellResults;

			// 单元格对应在哪个分组的结果
			MMarkGroupResult *_markGroupResults;

		};
	}
}