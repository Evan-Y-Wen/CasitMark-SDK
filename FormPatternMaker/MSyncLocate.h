#pragma once

//using namespace System;

namespace Cm2
{
	namespace FormPattern {
		//[Serializable] 
		class MSyncLocate
		{
		public:
			MSyncLocate(void);
			~MSyncLocate();

			// ������ͬ��������
			int SyncRowIndex;
			// �����ͬ�������ĵ�X����
			int SyncRowElapseX;
			// �����ͬ�������ĵ�Y����
			int SyncRowElapseY;
			// ģ��ͼ��ڵ���
			int TmpBlackDots;
		};
	};
};

