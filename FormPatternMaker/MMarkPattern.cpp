#include "MMarkPattern.h"
#include "MMarkBlock.h"
#include "MMarkGroup.h"
#include "MSyncLocate.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Cm2::FormPattern::MMarkPattern::MMarkPattern(void)
{
	cout << "MMarkPattern 默认构造函数测试" << endl;
	MarkBlockSet = new vector<MMarkBlock*>;
	if (MarkBlockSet == nullptr)
	{
		cout << "MarkBlockSet = new vector<MMarkBlock*>;分配内存失败" << endl;
		return;
	}
	MarkGroups = new vector<MMarkGroup*>;
	if (MarkGroups == nullptr)
	{
		cout << "MarkGroups = new vector<MMarkGroup*>;分配内存失败" << endl;
		return;
	}
	SyncLocates = new vector<MSyncLocate*>;
	if (SyncLocates == nullptr)
	{
		cout << "SyncLocates = new vector<MSyncLocate*>;分配内存失败" << endl;
		return;
	}
}

Cm2::FormPattern::MMarkPattern::~MMarkPattern()
{
	if (MarkBlockSet != nullptr)
	{
		MarkBlockSet->clear();
		MarkBlockSet = nullptr;
	}
	if (MarkGroups != nullptr)
	{
		MarkGroups->clear();
		MarkGroups = nullptr;
	}
	if (SyncLocates != nullptr)
	{
		SyncLocates->clear();
		SyncLocates = nullptr;
	}
}
