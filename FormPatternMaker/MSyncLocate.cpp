#include "MSyncLocate.h"
#include <iostream>
#include <string>
using namespace std;

Cm2::FormPattern::MSyncLocate::MSyncLocate(void)
{
	cout << "MSyncLocate Ĭ�Ϲ��캯������" << endl;
	SyncRowIndex = -1;
	SyncRowElapseX = SyncRowElapseY = TmpBlackDots = 0;
}

Cm2::FormPattern::MSyncLocate::~MSyncLocate()
{
	//û��ָ�����ͳ�Ա����
}
