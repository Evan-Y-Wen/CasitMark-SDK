#include "MImageShotPattern.h"
#include "MRegion.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Cm2::FormPattern::MImageShotPattern::MImageShotPattern(void)
{
	cout << "MImageShotPattern Ĭ�Ϲ��캯������" << endl;

	try
	{
		IsNeedClosedShapeSure = new vector<bool>;
		ShotRegions = new vector<MRegion*>;
		IsThresholdDetermine = new vector<bool>;
		ShotThresholds = new vector<double>;
		SyncLocates = new vector<MSyncLocate*>;
	}
	catch (const std::exception&)
	{
		cout << "IsNeedClosedShapeSure = new vector<bool>;����ĳ��ָ�룬�����ڴ�ʧ��" << endl;
		exit(-1);
	}
}

Cm2::FormPattern::MImageShotPattern::~MImageShotPattern()
{
	if (IsNeedClosedShapeSure != nullptr)
	{
		IsNeedClosedShapeSure->clear();
		IsNeedClosedShapeSure = nullptr;
	}
	if (ShotRegions != nullptr)
	{
		ShotRegions->clear();
		ShotRegions = nullptr;
	}
	if (IsThresholdDetermine != nullptr)
	{
		IsThresholdDetermine->clear();
		IsThresholdDetermine = nullptr;
	}
	if (ShotThresholds != nullptr)
	{
		ShotThresholds->clear();
		ShotThresholds = nullptr;
	}
	if (SyncLocates != nullptr)
	{
		SyncLocates->clear();
		SyncLocates = nullptr;
	}
}
