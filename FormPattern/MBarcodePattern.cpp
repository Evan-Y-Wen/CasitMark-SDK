#include "MBarcodePattern.h"
#include "MRegion.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Cm2::FormPattern::MBarcodePattern::MBarcodePattern(void)
{
	cout << "MBarcodePattern Ĭ�Ϲ��캯������" << endl;

	try
	{
		BarCodeSearchRegions = new vector<MRegion*>;
		BarCodeTypes = new vector<MBarCodeType>;
		SyncLocates = new vector<MSyncLocate*>;

	}
	catch (bad_alloc &)
	{
		cout << "BarCodeSearchRegions = new vector<MRegion*>;�����ڴ�ʧ��" << endl;
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
