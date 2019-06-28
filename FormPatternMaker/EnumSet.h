#pragma once

namespace Cm2
{
	namespace FormPatternMaker
	{
		class EnumSet
		{
			/// <summary>
			/// 区域识别类型
			/// </summary>
		public:
			enum RecognizeType
			{
				/// <summary>
				/// 定位标志
				/// </summary>
				LocationMark = 0,
				Mark,
				MarkRegion,
				ImageShot,
				BarOr2DCode,
				Seven,
				OCR,
				SyncRow,
				Rect
			};

		public:
			/// <summary>
			/// Mark块约束类型
			/// </summary>
			enum RestraintType
			{
				/// <summary>
				/// 二进制
				/// </summary>
				Binary = 0,
				/// <summary>
				/// 单选
				/// </summary>
				Radio,
			};

		public:
			/// <summary>
			/// 条码或二维码类型
			/// </summary>
			enum BarOr2DCodeType
			{
				// 不认识
				UNRECOGNIZED = 0,
				// 条码
				UPC_A,
				UPC_E,
				EAN_8,
				EAN_13,
				CODE_128,
				CODE_39,
				ITF,
				PDF417,

				// 二维码
				QR_CODE,
				DATAMATRIX
			};
		};
	}
}

