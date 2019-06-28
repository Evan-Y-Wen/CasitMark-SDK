#pragma once

//using namespace System;
//using namespace System::Collections::Generic;
#include "MRegion.h"
#include "MSyncLocate.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace Cm2
{
	namespace FormPattern {
		//ref class MRegion;
		//ref class MSyncLocate;
		// OCR��Ϣ
		//[Serializable] 
		class MOCRPattern
		{
		public:
			MOCRPattern(void);
			~MOCRPattern();

			// �Ƿ�ʹ�÷��ͼ�ζ�λ
			vector<bool> *IsNeedClosedShapeSure;
			// ʶ������
			vector<MRegion*> *OCRRegions;
			// ʶ������
			vector<string*> *LanguageOption;

			// ����ͬ����ʱ��¼ÿ���������ͬ�������ݣ�����ģʽʱ���Բ��ù�
			vector<MSyncLocate*> *SyncLocates;
		};
	};
};

