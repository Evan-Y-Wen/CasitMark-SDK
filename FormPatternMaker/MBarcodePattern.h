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
		//[Serializable] 
		enum MBarCodeType
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
			DATAMATRIX,

			// ���룬��"MPattern.h"��Ҳ�и�SimpleCode���������������ı�
			SimpleCodeForBarCodeType
		};
		//class MRegion;
		//class MSyncLocate;
		// ������Ϣ
		//[Serializable] 
		class MBarcodePattern
		{
		public:
			MBarcodePattern(void);
			~MBarcodePattern();

			// ����ʶ������
			vector<MRegion*> *BarCodeSearchRegions;
			// ����ʶ������
			vector<MBarCodeType> *BarCodeTypes;//enum MBarCodeType��ָ��ָ��ö�����͵����顣

			// ����ͬ����ʱ��¼ÿ���������ͬ�������ݣ�����ģʽʱ���Բ��ù�
			vector<MSyncLocate*> *SyncLocates;
		};
	};
};

