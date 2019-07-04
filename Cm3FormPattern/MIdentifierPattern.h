#pragma once

#include <QString>
#include "MRegion.h"

namespace Cm3
{
	namespace FormPattern
	{
		// ��־������(��־����Ա�ʾѡƱ���ͺ�ѡƱҳ���)
		enum MIdentifierType
		{
			// ����
			SimpleCode = 0,

			// ��ά��
			QR_CODE,
			DATAMATRIX,

			// ����
			UPC_A,
			UPC_E,
			EAN_8,
			EAN_13,
			CODE_128,
			CODE_39,
			ITF,
			PDF417
		};

		class MIdentifierPattern
		{
		public:
			MIdentifierPattern();
			~MIdentifierPattern();

		private:
			// ��־��ʶ������
			QList<MRegion *> * IdentifierCodeSearchRegions;
			// ��־��ʶ������
			QList<MIdentifierType> * BarIdentifierCodeTypes;
		};
	}
}

