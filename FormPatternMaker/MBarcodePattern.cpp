#include "MBarcodePattern.h"
#include "MRegion.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Cm2::FormPattern::MBarcodePattern::MBarcodePattern(void)
{
	cout << "MBarcodePattern 默认构造函数测试" << endl;

	try
	{
		BarCodeSearchRegions = new vector<MRegion*>;
		BarCodeTypes = new vector<MBarCodeType>;
		SyncLocates = new vector<MSyncLocate*>;

	}
	catch (bad_alloc &)
	{
		cout << "BarCodeSearchRegions = new vector<MRegion*>;分配内存失败" << endl;
		exit(-1);
	}
}

Cm2::FormPattern::MBarcodePattern::~MBarcodePattern()
{
	if (BarCodeSearchRegions != nullptr)
	{
		BarCodeSearchRegions->clear();
		BarCodeSearchRegions = nullptr;
	}
	if (BarCodeTypes != nullptr)
	{
		BarCodeTypes->clear();
		BarCodeTypes = nullptr;
	}
	if (SyncLocates != nullptr)
	{
		SyncLocates->clear();
		SyncLocates = nullptr;
	}
}
