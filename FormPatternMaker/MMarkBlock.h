#pragma once

//using namespace System;
#include <iostream>
#include <string>
#include "MRegion.h"
using namespace std;

namespace Cm2
{
	namespace FormPattern {
		//class MRegion;
		// ��Ϳ����Ϣ
		//[Serializable] 
		class MMarkBlock
		{
		public:
			MMarkBlock(void);
			~MMarkBlock();

			// ��Ϳ��ģʽ����
			MRegion *Position;
			// ��Ϳ�϶���ֵ,0~1Ϊ�ٷֱȣ�>1Ϊ����
			double MarkValidThreshold;
			// ��Ϳ���ı���ǩ
			string LabelText;
		};
	};
};

