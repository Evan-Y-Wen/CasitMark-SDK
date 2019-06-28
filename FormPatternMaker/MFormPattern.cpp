#include "MFormPattern.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Cm2::FormPattern::MFormPattern::MFormPattern(string &formName)
{
	cout << "MFormPattern Ĭ�Ϲ��캯������" << endl;
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
		cout << "SearchSeq = new vector<MRelativeRegion*>;�����ڴ�ʧ��" << endl;
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
		//�ڴ����ɹ��Ż��������ִ��
		for (int y = 0; y < region.Height; ++y)
		{
			//Array::Copy(PatternImageData, (region.Y + y) * PatternImageWidth + region.X, imgData, y * region.Width, region.Width);
			//Copy(src, begin_src, des, begin_des, copy_size)
			std::copy(PatternImageData->begin() + (region.Y + y) * PatternImageWidth + region.X,
				PatternImageData->begin() + (region.Y + y) * PatternImageWidth + region.X + region.Width - 1,
				imgData->begin() + y * region.Width);//��std::copy�滻Array::Copy�����������������ӣ�+n
		}
		return imgData;//����ָ�����ͣ��ǵý������������
	}
	catch (bad_alloc &e)
	{
		cout << "vector<unsigned char> *imgData = new vector<unsigned char>(region.Width * region.Height);�����ڴ�ʧ��" << endl;
		exit(-1);
	}
}
