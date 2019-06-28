#include "MSevenSectionPattern.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Cm2::FormPattern::MSevenSectionPattern::MSevenSectionPattern(void)
{
	cout << "MSevenSectionPattern 默认构造函数测试" << endl;
	SevenSections = new vector<MRegion*>;
	SyncLocates = new vector<MSyncLocate*>;
	if (SevenSections == nullptr || SyncLocates == nullptr)
	{
		cout << "SevenSections = new vector<MRegion*>;分配内存失败" << endl;
		return;
	}
}

Cm2::FormPattern::MSevenSectionPattern::~MSevenSectionPattern()
{
	if (SevenSections != nullptr)
	{
		SevenSections->clear();
		SevenSections = nullptr;
	}
	if (SyncLocates != nullptr)
	{
		SyncLocates->clear();
		SyncLocates = nullptr;
	}
}
