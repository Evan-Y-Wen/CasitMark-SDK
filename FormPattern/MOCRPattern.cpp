#include "MOCRPattern.h"
#include "MRegion.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Cm2::FormPattern::MOCRPattern::MOCRPattern(void)
{
	cout << "MOCRPattern 默认构造函数测试" << endl;
	IsNeedClosedShapeSure = new vector<bool>;
	OCRRegions = new vector<MRegion*>;
	LanguageOption = new vector<string*>;
	SyncLocates = new vector<MSyncLocate*>;
	if (IsNeedClosedShapeSure == nullptr || OCRRegions == nullptr || 
		LanguageOption == nullptr || SyncLocates == nullptr)
	{
		cout << "IsNeedClosedShapeSure = new vector<bool>;分配内存失败" << endl;
		return;
	}
}

Cm2::FormPattern::MOCRPattern::~MOCRPattern()
{
	if (IsNeedClosedShapeSure != nullptr)
	{
		IsNeedClosedShapeSure->clear();
		IsNeedClosedShapeSure = nullptr;
	}	
	if (OCRRegions != nullptr)
	{
		OCRRegions->clear();
		OCRRegions = nullptr;
	}	
	if (LanguageOption != nullptr)
	{
		LanguageOption->clear();
		LanguageOption = nullptr;
	}	
	if (SyncLocates != nullptr)
	{
		SyncLocates->clear();
		SyncLocates = nullptr;
	}
}
