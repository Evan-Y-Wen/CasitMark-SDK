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
			//todo:����ļ�δ����

		private:
			// ��Ϳ����
			QList<MCellResult *> *_cellResults;// MCell,ͼ���еĵ�Ԫ����Ϳ�죩

			// ��Ϳ�������
			QList<MMarkGroupResult *> *_markGroupResults;

		};
	}
}