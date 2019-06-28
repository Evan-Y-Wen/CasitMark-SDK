#include "MFormPattern.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Cm2::FormPattern::MFormPattern::MFormPattern(string &formName)
{
	cout << "MFormPattern 默认构造函数测试" << endl;
	FormName = formName;
	PatternImage = nullptr;
	IsLandscape = false;
	TemplateImageBinirizeThreshold = 0;
	PatternImageData = nullptr;
	PatternImageWidth = PatternImageHeight = 0;
	try
	{
		SearchSeq = new vector<MRelativeRegion*>;
		firstRegion = new MRegion;
	}
	catch (bad_alloc &)
	{
		cout << "SearchSeq = new vector<MRelativeRegion*>;分配内存失败" << endl;
		exit(-1);
	}
}

Cm2::FormPattern::MFormPattern::~MFormPattern()
{
	if (PatternImage != nullptr)
	{
		PatternImage->clear();
		PatternImage = nullptr;
	}
	if (PatternImageData != nullptr)
	{
		PatternImageData->clear();
		PatternImageData = nullptr;
	}
	if (SearchSeq != nullptr)
	{
		SearchSeq->clear();
		SearchSeq = nullptr;
	}	

	if (firstRegion != nullptr)
	{
		delete firstRegion;
		firstRegion = nullptr;
	}
	if (LocatePattern != nullptr)
	{
		delete LocatePattern;
		LocatePattern = nullptr;
	}
	if (MarkPattern != nullptr)
	{
		delete MarkPattern;
		MarkPattern = nullptr;
	}
	if (ImageShotPattern != nullptr)
	{
		delete ImageShotPattern;
		ImageShotPattern = nullptr;
	}
	if (BarcodePattern != nullptr)
	{
		delete BarcodePattern;
		BarcodePattern = nullptr;
	}
	if (SevenSectionPattern != nullptr)
	{
		delete SevenSectionPattern;
		SevenSectionPattern = nullptr;
	}
	if (OCRPattern != nullptr)
	{
		delete OCRPattern;
		OCRPattern = nullptr;
	}	
	if (SyncRowPattern != nullptr)
	{
		delete SyncRowPattern;
		SyncRowPattern = nullptr;
	}
}

int Cm2::FormPattern::MFormPattern::CountBlackDotsOnRegion(Cm2::FormPattern::MRegion &region)
{
	if (PatternImageData == nullptr)
	{
		return 0;
	}

	int dotCounts = 0;
	for (int y = region.Y; y < region.Y + region.Height; ++y)
	{
		for (int x = region.X; x < region.X + region.Width; ++x)
		{
			if ((*PatternImageData)[y * PatternImageWidth + x] == (unsigned char)'0')
				dotCounts++;
		}
	}
	return dotCounts;
}

vector<unsigned char> *Cm2::FormPattern::MFormPattern::GetRegionImgData(Cm2::FormPattern::MRegion &region)
{
	if (PatternImageData == nullptr)
	{
		return nullptr;
	}

	try
	{
		vector<unsigned char> *imgData = new vector<unsigned char>(region.Width * region.Height);
		//内存分配成功才会继续向下执行
		for (int y = 0; y < region.Height; ++y)
		{
			//Array::Copy(PatternImageData, (region.Y + y) * PatternImageWidth + region.X, imgData, y * region.Width, region.Width);
			//Copy(src, begin_src, des, begin_des, copy_size)
			std::copy(PatternImageData->begin() + (region.Y + y) * PatternImageWidth + region.X,
				PatternImageData->begin() + (region.Y + y) * PatternImageWidth + region.X + region.Width - 1,
				imgData->begin() + y * region.Width);//用std::copy替换Array::Copy。迭代器可以算术加：+n
		}
		return imgData;//返回指针类型，记得将匿名对象扶正
	}
	catch (bad_alloc &e)
	{
		cout << "vector<unsigned char> *imgData = new vector<unsigned char>(region.Width * region.Height);分配内存失败" << endl;
		exit(-1);
	}
}
