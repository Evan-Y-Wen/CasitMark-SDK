#pragma once

//using namespace System;
//using namespace System::Collections::Generic;
#include "MRegion.h"
#include "MLocatePattern.h"
#include "MMarkPattern.h"
#include "MImageShotPattern.h"
#include "MSevenSectionPattern.h"
#include "MBarcodePattern.h"
#include "MOCRPattern.h"
#include "MSyncRowPattern.h"
#include "MRelativeRegion.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace Cm2
{
	namespace FormPattern {
		// ģ������
		enum MTemplateFileType
		{
			Image,
			WordFile
		};
		//class MRegion;
		//class MLocatePattern;
		//class MMarkPattern;
		//class MImageShotPattern;
		//class MSevenSectionPattern;
		//class MBarcodePattern;
		//class MOCRPattern;
		//class MSyncRowPattern;
		//class MRelativeRegion;
		// ���ģʽ
		//[Serializable] 
		class MFormPattern
		{
		public:
			MFormPattern(string &formName);
			~MFormPattern();

			// �������
			string FormName;
			// ģ���ļ�����
			MTemplateFileType TemplateFileType;//enum MTemplateFileType
			// ģ��ͼ���ֵ����ֵ
			int TemplateImageBinirizeThreshold;
			// ��Ϊͼ�����ݣ���ʽΪ2λ���tiff�ڰ�ͼ
			vector<unsigned char> *PatternImage;
			// ģʽͼ���Ű淽��
			bool IsLandscape;
			// ��λ��Ϣ
			MLocatePattern *LocatePattern;
			// ��Ϳ����Ϣ
			MMarkPattern *MarkPattern;
			// ��ͼ��Ϣ
			MImageShotPattern *ImageShotPattern;
			// ������Ϣ
			MBarcodePattern *BarcodePattern;
			// �߶�����Ϣ
			MSevenSectionPattern *SevenSectionPattern;
			// OCR��Ϣ
			MOCRPattern *OCRPattern;
			// ����ͬ����ģʽ
			MSyncRowPattern *SyncRowPattern;

			// ģʽ�ļ��ͷź�õ���ʱ����
			// ʶ��ʱ��tiff�ڰ�ͼ��ѹ��ͼ������
			vector<unsigned char> *PatternImageData;
			// ģʽͼ���
			int PatternImageWidth;
			// ģʽͼ���
			int PatternImageHeight;
			// ��λ�����߽Ƕ�
			double LocateAngle;
			// ��λ�����߳���
			double LocateDistance;
			// ����˳��
			vector<MRelativeRegion*> *SearchSeq;

			// ��һ����ն�λ����
			MRegion *firstRegion;
			int CountBlackDotsOnRegion(Cm2::FormPattern::MRegion &region);
			// �������ͼ��
			vector<unsigned char> *GetRegionImgData(Cm2::FormPattern::MRegion &region);//����ָ�����ͣ��ǵý������������
		};
	};
};

