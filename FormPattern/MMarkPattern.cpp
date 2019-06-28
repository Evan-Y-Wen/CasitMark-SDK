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
	cout << "MMarkPattern Ĭ�Ϲ��캯������" << endl;
	MarkBlockSet = new vector<MMarkBlock*>;
	if (MarkBlockSet == nullptr)
	{
		cout << "MarkBlockSet = new vector<MMarkBlock*>;�����ڴ�ʧ��" << endl;
		return;
	}
	MarkGroups = new vector<MMarkGroup*>;
	if (MarkGroups == nullptr)
	{
		cout << "MarkGroups = new vector<MMarkGroup*>;�����ڴ�ʧ��" << endl;
		return;
	}
	SyncLocates = new vector<MSyncLocate*>;
	if (SyncLocates == nullptr)
	{
		cout << "SyncLocates = new vector<MSyncLocate*>;�����ڴ�ʧ��" << endl;
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
