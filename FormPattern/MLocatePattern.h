#pragma once

//using namespace System;
#include "MRegion.h"
#include <iostream>
#include <string>
using namespace std;

namespace Cm2
{
	namespace FormPattern {
		//class MRegion;
		//[Serializable] 
		class MLocatePattern
		{
		public:
			MLocatePattern();
			~MLocatePattern();

			// ��ʼ��������
			MRegion *StartSearchRegion;
			// ��ʼ��������
			MRegion *EndSearchRegion;
			// ����ͼ��ƥ�䣬���¼��ʼͼ������λ��
			MRegion *StartShapeRegion;
			// ����ͼ��ƥ�䣬���¼����ͼ������λ��
			MRegion *EndShapeRegion;
			// ���Ǽ���ƥ�䣬���¼��ʼ�����ֵ
			int StartSimpleCodeValue;
			// ���Ǽ���ƥ�䣬���¼���������ֵ
			int EndSimpleCodeValue;
		};
	};
};

