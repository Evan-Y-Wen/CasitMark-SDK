#pragma once

#include <QString>
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
			// 分组名
			QString _groupName;

			// 填涂块结果
			QList<MCellResult *> *_cellResults;// MCell,图像中的单元格（填涂快）

			// 填涂块分组结果
			QList<MMarkGroupResult *> *_markGroupResults;// todo:我觉得这块内容不需要存在了。

		};
	}
}