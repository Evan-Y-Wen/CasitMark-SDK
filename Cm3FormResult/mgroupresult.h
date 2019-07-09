#pragma once

#include <QList>
#include "mcellresult.h"
#include "mmarkgroupresult.h"

namespace Cm3
{
	namespace FormResult
	{
		class MGroupResult
		{ // ��Ӧһ������
		public:
			MGroupResult();
			~MGroupResult();

		private:
			// ���һ�������е����е�Ԫ����
			QList<MCellResult *> *_cellResults;

			// ��Ԫ���Ӧ���ĸ�����Ľ��
			MMarkGroupResult *_markGroupResults;

		};
	}
}