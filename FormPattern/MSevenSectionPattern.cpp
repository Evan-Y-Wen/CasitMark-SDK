#include "MSevenSectionPattern.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Cm2::FormPattern::MSevenSectionPattern::MSevenSectionPattern(void)
{
	cout << "MSevenSectionPattern Ĭ�Ϲ��캯������" << endl;
	SevenSections = new vector<MRegion*>;
	SyncLocates = new vector<MSyncLocate*>;
	if (SevenSections == nullptr || SyncLocates == nullptr)
	{
		cout << "SevenSections = new vector<MRegion*>;�����ڴ�ʧ��" << endl;
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
