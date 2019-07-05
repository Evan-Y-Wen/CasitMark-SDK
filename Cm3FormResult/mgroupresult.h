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
			// ����Ϳ�ĵ�Ԫ����
			QList<MCellResult *> *_cellResults;// MCell,ͼ���еĵ�Ԫ����Ϳ�죩

			// ����Ϳ�ĵ�Ԫ���Ӧ���ĸ�����Ľ��  ������������Ҫ�ˡ�
			QList<MMarkGroupResult *> *_markGroupResults;// todo:�Ҿ���������ݷ���MCellResult����á�

		};
	}
}