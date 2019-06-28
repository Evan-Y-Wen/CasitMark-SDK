#include "MMarkBlock.h"
#include "MRegion.h"
#include <iostream>
#include <string>
using namespace std;

Cm2::FormPattern::MMarkBlock::MMarkBlock(void)
{
	cout << "MMarkBlock 默认构造函数测试" << endl;
	Position = new MRegion();
	if (Position == nullptr)
	{
		cout << "Position = new MRegion();分配内存失败" << endl;
		return;
	}
	MarkValidThreshold = 0.02;
	LabelText = "";
}

Cm2::FormPattern::MMarkBlock::~MMarkBlock()
{
	if (Position != nullptr)
	{
		delete Position;
		Position = nullptr;
	}
}
