#pragma once

//using namespace System;
//using namespace System::Collections::Generic;

namespace Cm2
{
	namespace FormPattern {
		//[Serializable] 
		class MRelativeRegion
		{
		public:
			MRelativeRegion(void);
			~MRelativeRegion();

			// ��������0-��Ϳ�飬1-��ͼ��2-���룬3-�߶��룬4-ocr
			int RegionType;

			// ԭ������
			int RegionIndex;

			// �������
			int RelativeX;
			int RelativeY;

			// 0:������Ϳ�飻1��������ʼ��λ��ʶ��2������������λ��ʶ
			int CloseType;

			// ģ��ͼ��ڵ���
			int TmpBlackDots;
		};
	};
};

