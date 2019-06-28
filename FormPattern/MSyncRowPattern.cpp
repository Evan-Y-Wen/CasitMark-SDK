#include "MSyncRowPattern.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


Cm2::FormPattern::MSyncRowPattern::MSyncRowPattern(void)
{
	cout << "MSyncRowPattern 默认构造函数测试" << endl;
	LeftSyncRowSearchArea = nullptr;
	LeftSyncRows = nullptr;
	RightSyncRowSearchArea = nullptr;
	RightSyncRows = nullptr;
}

Cm2::FormPattern::MSyncRowPattern::~MSyncRowPattern()
{
	if (LeftSyncRowSearchArea != nullptr)
	{
		delete LeftSyncRowSearchArea;
		LeftSyncRowSearchArea = nullptr;
	}
	if (LeftSyncRows != nullptr)
	{
		LeftSyncRows->clear();
		LeftSyncRows = nullptr;
	}
	if (RightSyncRowSearchArea != nullptr)
	{
		delete RightSyncRowSearchArea;
		RightSyncRowSearchArea = nullptr;
	}
	if (RightSyncRows != nullptr)
	{
		RightSyncRows->clear();
		RightSyncRows = nullptr;
	}

}
