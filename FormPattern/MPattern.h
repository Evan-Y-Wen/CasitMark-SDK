#pragma once

//using namespace System;
//using namespace System::Collections::Generic;
#include "MFormPattern.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace Cm2
{
	namespace FormPattern {
		// ��λ��ʽ
		//[Serializable]
		enum MLocateMode
		{
			// ͼ��ƥ��
			ShapeMatch,
			// ���룬��"MBarcodePattern.h"��Ҳ�и�SimpleCode���������������ı�
			SimpleCodeForLocateMode
		};

		//class MFormPattern;
		//class LPattern;
		//[Serializable]
		class MPattern
		{
		public:
			MPattern(void);
			~MPattern();//ԭ�ļ�Ϊ�й��࣬��׼C++��Ҫ�ֶ��ͷ��ڴ�

			// ģʽ����
			string PatternName;//String^ PatternName;ԭ�ļ�Ϊ�������ͣ������
			// ģʽΨһ���
			string PatternGUID;
			// ��λ��ʽ
			MLocateMode LocateMode;//ʵ������ö��enum MLocateMode
			// ͼ��ƥ�����ƶȣ���ƥ��ʱ���ڸ����ƶ���Ϊƥ����
			double ShapeMatchThreshold;
			// ��Ϳ������ʱ��Χ�Ŵ����
			double MarkBlockStretch;
			// ��ģʽ�µı�ģʽ
			vector<MFormPattern*> *FormPatterns;//�ǵ��ͷ��ڴ氡������

			// ��ѹģʽ����
			//void DecompressionData();

			// ���浽�ļ�
			//void SaveToFile(string &filePath);

			// ���ļ��ж�ȡ
			//static MPattern *LoadFromFile(string &filePath);

		};
	};
};
