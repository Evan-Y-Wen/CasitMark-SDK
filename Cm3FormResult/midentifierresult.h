#pragma once

#include <QList>
#include "mregionresult.h"

namespace Cm3
{
	namespace FormResult
	{
		// 标志码类型(标志码可以表示选票类型和选票页码等)
		enum MIdentifierTypeResult // 需要与模式中的一一对应，这样才能以数字方式取得正确的枚举值。
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

		class MIdentifierResult
		{
		public:
			MIdentifierResult();
			~MIdentifierResult();

		private:
			// 标志码识别区域结果值
			QList<MRegionResult *> * _identifierCodeSearchRegions;

			// 标志码识别类型结果值
			QList<MIdentifierTypeResult> * _barIdentifierCodeTypes;

		};
	}
}
