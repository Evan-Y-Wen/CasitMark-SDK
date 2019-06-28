#pragma once

namespace Cm2
{
	namespace FormPatternMaker
	{
		class EnumSet
		{
			/// <summary>
			/// ����ʶ������
			/// </summary>
		public:
			enum RecognizeType
			{
				/// <summary>
				/// ��λ��־
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
			/// Mark��Լ������
			/// </summary>
			enum RestraintType
			{
				/// <summary>
				/// ������
				/// </summary>
				Binary = 0,
				/// <summary>
				/// ��ѡ
				/// </summary>
				Radio,
			};

		public:
			/// <summary>
			/// ������ά������
			/// </summary>
			enum BarOr2DCodeType
			{
				// ����ʶ
				UNRECOGNIZED = 0,
				// ����
				UPC_A,
				UPC_E,
				EAN_8,
				EAN_13,
				CODE_128,
				CODE_39,
				ITF,
				PDF417,

				// ��ά��
				QR_CODE,
				DATAMATRIX
			};
		};
	}
}

