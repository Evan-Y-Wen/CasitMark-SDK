#include "MMarkGroup.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Cm2::FormPattern::MMarkGroup::MMarkGroup(string &groupName)
{
	cout << "MMarkGroup Ĭ�Ϲ��캯������" << endl;
	GroupName = groupName;
	ResultMode = MResultMode::Binary;
	BlockIndexs = new vector<int>;
	if (BlockIndexs == nullptr)
	{
		cout << "BlockIndexs = new vector<int>;�����ڴ�ʧ��" << endl;
		return;
	}
}

Cm2::FormPattern::MMarkGroup::~MMarkGroup()
{
	if (BlockIndexs != nullptr)
	{
		BlockIndexs->clear();
		BlockIndexs = nullptr;
	}
}
