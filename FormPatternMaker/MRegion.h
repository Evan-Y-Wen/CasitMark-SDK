#pragma once

//using namespace System;
#include <iostream>
#include <string>
using namespace std;

namespace Cm2
{
	namespace FormPattern {
		//[Serializable] 
		class MRegion
		{
		public:
			MRegion(void);
			MRegion(int x, int y, int w, int h);
			~MRegion();//�ֶ������ڴ�

			// ��������
			string Name;
			// ������������X
			int X;
			// ������������Y
			int Y;
			// ������
			int Width;
			// ����߶�
			int Height;
			/// ���򱳾�ɫ
			string BackgroundColor;
            /// ����߿���ɫ
			string BorderColor;

			void InRegion(int x, int y, int w, int h);

			void InRegion(MRegion &region);//���������ָ�뻹�����ã�������ͬû������ֻ���÷���ͬ

			MRegion *DeepClone();//���ﷵ�ؾֲ�������ַ�������������⣬��Ҫ���������������

		};
	};
};

