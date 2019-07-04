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
			//todo:这个文件未做完

		private:
			// 填涂块结果
			QList<MCellResult *> *_cellResults;// MCell,图像中的单元格（填涂快）

			// 填涂块分组结果
			QList<MMarkGroupResult *> *_markGroupResults;

		};
	}
}