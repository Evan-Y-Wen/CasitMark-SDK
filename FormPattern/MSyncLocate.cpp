#include "MSyncLocate.h"
#include <iostream>
#include <string>
using namespace std;

Cm2::FormPattern::MSyncLocate::MSyncLocate(void)
{
	cout << "MSyncLocate 默认构造函数测试" << endl;
	SyncRowIndex = -1;
	SyncRowElapseX = SyncRowElapseY = TmpBlackDots = 0;
}

Cm2::FormPattern::MSyncLocate::~MSyncLocate()
{
	//没有指针类型成员变量
}
