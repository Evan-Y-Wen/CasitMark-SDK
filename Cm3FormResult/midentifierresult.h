#pragma once

#include <QList>
#include "mregionresult.h"

namespace Cm3
{
	namespace FormResult
	{
		// ��־������(��־����Ա�ʾѡƱ���ͺ�ѡƱҳ���)
		enum MIdentifierTypeResult // ��Ҫ��ģʽ�е�һһ��Ӧ���������������ַ�ʽȡ����ȷ��ö��ֵ��
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

		class MIdentifierResult
		{
		public:
			MIdentifierResult();
			~MIdentifierResult();

		private:
			// ��־��ʶ��������ֵ
			QList<MRegionResult *> * _identifierCodeSearchRegions;

			// ��־��ʶ�����ͽ��ֵ
			QList<MIdentifierTypeResult> * _barIdentifierCodeTypes;

		};
	}
}
