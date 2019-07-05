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
			// ������
			QString _groupName;

			// ��Ϳ����
			QList<MCellResult *> *_cellResults;// MCell,ͼ���еĵ�Ԫ����Ϳ�죩

			// ��Ϳ�������
			QList<MMarkGroupResult *> *_markGroupResults;// todo:�Ҿ���������ݲ���Ҫ�����ˡ�

		};
	}
}