#pragma once

#include <QList>
#include "mcellresult.h"
#include "mmarkgroupresult.h"

namespace Cm3
{
	namespace FormResult
	{
		class MGroupResult
		{
		public:
			MGroupResult();
			~MGroupResult();

		private:
			// 已填涂的单元格结果
			QList<MCellResult *> *_cellResults;// MCell,图像中的单元格（填涂快）

			// 已填涂的单元格对应在哪个分组的结果  分组结果好像不需要了。
			QList<MMarkGroupResult *> *_markGroupResults;// todo:我觉得这块内容放在MCellResult里更好。

		};
	}
}