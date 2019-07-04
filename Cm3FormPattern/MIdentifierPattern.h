#pragma once

#include <QString>
#include "MRegion.h"

namespace Cm3
{
	namespace FormPattern
	{
		// 标志码类型(标志码可以表示选票类型和选票页码等)
		enum MIdentifierType
		{
			// 简单码
			SimpleCode = 0,

			// 二维码
			QR_CODE,
			DATAMATRIX,

			// 条码
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
			// 标志码识别区域
			QList<MRegion *> * IdentifierCodeSearchRegions;
			// 标志码识别类型
			QList<MIdentifierType> * BarIdentifierCodeTypes;
		};
	}
}

