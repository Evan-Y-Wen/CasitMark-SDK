#include "MRelativeRegion.h"
#include <iostream>
#include <string>
using namespace std;


Cm2::FormPattern::MRelativeRegion::MRelativeRegion(void)
{
	cout << "MRelativeRegion 默认构造函数测试" << endl;
	RegionType = 0;
	RegionIndex = -1;
	RelativeX = 0;
	RelativeY = 0;
	CloseType = 0;
	TmpBlackDots = 0;
}

Cm2::FormPattern::MRelativeRegion::~MRelativeRegion()
{
	//没有指针类型的成员变量
}
