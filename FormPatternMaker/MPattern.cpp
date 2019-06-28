#include <vector>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "MPattern.h"
#include "MFormPattern.h"
#include "MToolKit.h"
#include "MLocatePattern.h"
#include "MRegion.h"
#include "MMarkPattern.h"
#include "MMarkBlock.h"
#include "MRelativeRegion.h"
#include "MSyncLocate.h"
#include "MSyncRowPattern.h"
#include "MBarcodePattern.h"
#include "MImageShotPattern.h"
#include "MSevenSectionPattern.h"
#include "MOCRPattern.h"
#include "LWindowsHelper.h"
#include "ObjBase.h"//C++实现GUID

//using namespace System::IO;
//using namespace System::Runtime::InteropServices;
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
using namespace Cm2::FormPattern;

string GenerateGuid()
{
	GUID guid;
	CoCreateGuid(&guid);
	char cBuffer[64] = { 0 };
	sprintf_s(cBuffer, sizeof(cBuffer),
		"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",
		guid.Data1, guid.Data2,
		guid.Data3, guid.Data4[0],
		guid.Data4[1], guid.Data4[2],
		guid.Data4[3], guid.Data4[4],
		guid.Data4[5], guid.Data4[6],
		guid.Data4[7]);
	return string(cBuffer);
}

Cm2::FormPattern::MPattern::MPattern(void)
{
	cout << "MPattern 默认构造函数测试" << endl;
	PatternName = "新建模式";//可能会修改
	//PatternGUID = System::Guid::NewGuid().ToString("N");//Type: System.String，N代表32 位数字
	PatternGUID = GenerateGuid();//原代码生成："632a7c3d87564143b287c444756d3c64"
	LocateMode = SimpleCodeForLocateMode;//枚举
	ShapeMatchThreshold = 0.8;
	MarkBlockStretch = 1.5;
	try
	{
		FormPatterns = new vector<MFormPattern>;
	}
	catch (bad_alloc &)
	{
		cout << "FormPatterns = new vector<MFormPattern>;分配内存失败" << endl;
		exit(-1);
	}
}

Cm2::FormPattern::MPattern::~MPattern(void)
{//记得释放内存啊。。。。。
	//if (PatternName != nullptr)
	//{
	//	delete PatternName;
	//	PatternName = nullptr;
	//}
	//if (PatternGUID != nullptr)
	//{
	//	delete PatternGUID;
	//	PatternGUID = nullptr;
	//}
	if (FormPatterns->size() != 0)
	{
		FormPatterns->clear();
		FormPatterns = nullptr;
	}

}

/*
void Cm2::FormPattern::MPattern::DecompressionData()
{
	for (int i = 0; i < FormPatterns->size(); ++i)
	{
		// 解压tiff图像
		ofstream file;
		file.//这里有问题。。。。。。。。。。。。。。。。。
	
		File::WriteAllBytes(Path::GetDirectoryName(System::Diagnostics::Process::GetCurrentProcess()->MainModule->FileName) + "\\tmp.tiff", FormPatterns[i]->PatternImage);
		cv::Mat cvMat = cv::imread(LWindowsHelper::GetCurrentEXEPath() + "\\tmp.tiff", 0);
		// 二值化
		int thred = FormPatterns[i]->TemplateImageBinirizeThreshold;
		if (thred <= 0)
			thred = LWindowsHelper::OSTUThreshold(cvMat);
		cv::Mat bcvMat(cvMat.rows, cvMat.cols, CV_8UC1, cv::Scalar::all(0xFF));
		cv::threshold(cvMat, bcvMat, thred, 255, cv::THRESH_BINARY);
		FormPatterns[i]->PatternImageData = new array<Byte>(cvMat.cols * cvMat.rows);
		Marshal::Copy((IntPtr)bcvMat.data, FormPatterns[i]->PatternImageData, 0, cvMat.cols * cvMat.rows);
		FormPatterns[i]->PatternImageWidth = cvMat.cols;
		FormPatterns[i]->PatternImageHeight = cvMat.rows;
#ifdef _DEBUG
		System::Drawing::Bitmap* bitmap = MToolKit::CreateGrayImage(FormPatterns[i]->PatternImageData, FormPatterns[i]->PatternImageWidth, FormPatterns[i]->PatternImageHeight);
		bitmap->Save(Path::GetDirectoryName(System::Diagnostics::Process::GetCurrentProcess()->MainModule->FileName) + "\\tmp.jpg", System::Drawing::Imaging::ImageFormat::Jpeg);
#endif
		// 模版图像定位标记连线角度
		FormPatterns[i]->LocateAngle = atan((double)(FormPatterns[i]->LocatePattern->EndShapeRegion->Y - FormPatterns[i]->LocatePattern->StartShapeRegion->Y)
			/ (double)(FormPatterns[i]->LocatePattern->EndShapeRegion->X - FormPatterns[i]->LocatePattern->StartShapeRegion->X));
		// 模版图像定位标记连线长度
		FormPatterns[i]->LocateDistance = Math::Sqrt(Math::Pow(FormPatterns[i]->LocatePattern->EndShapeRegion->X - FormPatterns[i]->LocatePattern->StartShapeRegion->X, 2.0) + Math::Pow(FormPatterns[i]->LocatePattern->EndShapeRegion->Y - FormPatterns[i]->LocatePattern->StartShapeRegion->Y, 2.0));

		vector<MRegion*>* syncCenters = new vector<MRegion*>();
		if (FormPatterns[i]->SyncRowPattern != nullptr)
		{
			// 计算同步道所有中心点
			for (int j = 0; j < FormPatterns[i]->SyncRowPattern->LeftSyncRows->Count; ++j)
			{
				MRegion* center = new MRegion();
				center->X = (FormPatterns[i]->SyncRowPattern->LeftSyncRows[j]->X + FormPatterns[i]->SyncRowPattern->LeftSyncRows[j]->Width / 2
					+ FormPatterns[i]->SyncRowPattern->RightSyncRows[j]->X + FormPatterns[i]->SyncRowPattern->RightSyncRows[j]->Width / 2) / 2;
				center->Y = (FormPatterns[i]->SyncRowPattern->LeftSyncRows[j]->Y + FormPatterns[i]->SyncRowPattern->LeftSyncRows[j]->Height / 2
					+ FormPatterns[i]->SyncRowPattern->RightSyncRows[j]->Y + FormPatterns[i]->SyncRowPattern->RightSyncRows[j]->Height / 2) / 2;
				syncCenters->Add(center);
			}
			// 距离同步道中心距离最近
			if (FormPatterns[i]->MarkPattern != nullptr)
			{
				for (int j = 0; j < FormPatterns[i]->MarkPattern->MarkBlockSet->Count; ++j)
				{
					MSyncLocate* syncLoc = new MSyncLocate();
					syncLoc->SyncRowIndex = MToolKit::FindMostClosestRegion(syncCenters, FormPatterns[i]->MarkPattern->MarkBlockSet[j]->Position);
					syncLoc->SyncRowElapseX = FormPatterns[i]->MarkPattern->MarkBlockSet[j]->Position->X - syncCenters[syncLoc->SyncRowIndex]->X;
					syncLoc->SyncRowElapseY = FormPatterns[i]->MarkPattern->MarkBlockSet[j]->Position->Y - syncCenters[syncLoc->SyncRowIndex]->Y;
					syncLoc->TmpBlackDots = FormPatterns[i]->CountBlackDotsOnRegion(FormPatterns[i]->MarkPattern->MarkBlockSet[j]->Position);
					FormPatterns[i]->MarkPattern->SyncLocates->Add(syncLoc);
				}
			}
			if (FormPatterns[i]->ImageShotPattern != nullptr)
			{
				for (int j = 0; j < FormPatterns[i]->ImageShotPattern->ShotRegions->Count; ++j)
				{
					MSyncLocate* syncLoc = new MSyncLocate();
					syncLoc->SyncRowIndex = MToolKit::FindMostClosestRegion(syncCenters, FormPatterns[i]->ImageShotPattern->ShotRegions[j]);
					syncLoc->SyncRowElapseX = FormPatterns[i]->ImageShotPattern->ShotRegions[j]->X - syncCenters[syncLoc->SyncRowIndex]->X;
					syncLoc->SyncRowElapseY = FormPatterns[i]->ImageShotPattern->ShotRegions[j]->Y - syncCenters[syncLoc->SyncRowIndex]->Y;
					syncLoc->TmpBlackDots = FormPatterns[i]->CountBlackDotsOnRegion(FormPatterns[i]->ImageShotPattern->ShotRegions[j]);
					FormPatterns[i]->ImageShotPattern->SyncLocates->Add(syncLoc);
				}
			}
			if (FormPatterns[i]->BarcodePattern != nullptr)
			{
				for (int j = 0; j < FormPatterns[i]->BarcodePattern->BarCodeSearchRegions->Count; ++j)
				{
					MSyncLocate* syncLoc = new MSyncLocate();
					syncLoc->SyncRowIndex = MToolKit::FindMostClosestRegion(syncCenters, FormPatterns[i]->BarcodePattern->BarCodeSearchRegions[j]);
					syncLoc->SyncRowElapseX = FormPatterns[i]->BarcodePattern->BarCodeSearchRegions[j]->X - syncCenters[syncLoc->SyncRowIndex]->X;
					syncLoc->SyncRowElapseY = FormPatterns[i]->BarcodePattern->BarCodeSearchRegions[j]->Y - syncCenters[syncLoc->SyncRowIndex]->Y;
					syncLoc->TmpBlackDots = FormPatterns[i]->CountBlackDotsOnRegion(FormPatterns[i]->BarcodePattern->BarCodeSearchRegions[j]);
					FormPatterns[i]->BarcodePattern->SyncLocates->Add(syncLoc);
				}
			}
			if (FormPatterns[i]->SevenSectionPattern != nullptr)
			{
				for (int j = 0; j < FormPatterns[i]->SevenSectionPattern->SevenSections->Count; ++j)
				{
					MSyncLocate* syncLoc = new MSyncLocate();
					syncLoc->SyncRowIndex = MToolKit::FindMostClosestRegion(syncCenters, FormPatterns[i]->SevenSectionPattern->SevenSections[j]);
					syncLoc->SyncRowElapseX = FormPatterns[i]->SevenSectionPattern->SevenSections[j]->X - syncCenters[syncLoc->SyncRowIndex]->X;
					syncLoc->SyncRowElapseY = FormPatterns[i]->SevenSectionPattern->SevenSections[j]->Y - syncCenters[syncLoc->SyncRowIndex]->Y;
					syncLoc->TmpBlackDots = FormPatterns[i]->CountBlackDotsOnRegion(FormPatterns[i]->SevenSectionPattern->SevenSections[j]);
					FormPatterns[i]->SevenSectionPattern->SyncLocates->Add(syncLoc);
				}
			}
			if (FormPatterns[i]->OCRPattern != nullptr)
			{
				for (int j = 0; j < FormPatterns[i]->OCRPattern->OCRRegions->Count; ++j)
				{
					MSyncLocate* syncLoc = new MSyncLocate();
					syncLoc->SyncRowIndex = MToolKit::FindMostClosestRegion(syncCenters, FormPatterns[i]->OCRPattern->OCRRegions[j]);
					syncLoc->SyncRowElapseX = FormPatterns[i]->OCRPattern->OCRRegions[j]->X - syncCenters[syncLoc->SyncRowIndex]->X;
					syncLoc->SyncRowElapseY = FormPatterns[i]->OCRPattern->OCRRegions[j]->Y - syncCenters[syncLoc->SyncRowIndex]->Y;
					syncLoc->TmpBlackDots = FormPatterns[i]->CountBlackDotsOnRegion(FormPatterns[i]->OCRPattern->OCRRegions[j]);
					FormPatterns[i]->OCRPattern->SyncLocates->Add(syncLoc);
				}
			}
		}

		// 不依赖同步道，只依赖定位标记
		vector<MRelativeRegion*>* tmpRRegion = nullptr;
		int haveCount = 0;
		if (FormPatterns[i]->MarkPattern != nullptr)
		{
			tmpRRegion = new vector<MRelativeRegion*>();
			for (int j = 0; j < FormPatterns[i]->MarkPattern->MarkBlockSet->Count; ++j)
			{
				MRelativeRegion* relativeRegion = new MRelativeRegion();
				relativeRegion->RegionIndex = j;
				relativeRegion->RegionType = 0;
				relativeRegion->RelativeX = FormPatterns[i]->MarkPattern->MarkBlockSet[j]->Position->X;
				relativeRegion->RelativeY = FormPatterns[i]->MarkPattern->MarkBlockSet[j]->Position->Y;
				tmpRRegion->Add(relativeRegion);
			}
			if (tmpRRegion->Count > 0)
			{
				haveCount += tmpRRegion->Count;
				// 生成搜索顺序
				vector<bool>* ignoreList = new vector<bool>();
				for (int j = 0; j < tmpRRegion->Count; ++j)
					ignoreList->Add(false);
				int lastRIndex = 0;
				// 距离定位块最近
				MRegion* topLoc = new MRegion();
				topLoc->X = FormPatterns[i]->LocatePattern->StartShapeRegion->X;
				topLoc->Y = FormPatterns[i]->LocatePattern->StartShapeRegion->Y;
				int topClosestIndex = MToolKit::FindMostClosestRelativeRegion(tmpRRegion, topLoc);
				MRegion* bottomLoc = new MRegion();
				bottomLoc->X = FormPatterns[i]->LocatePattern->EndShapeRegion->X;
				bottomLoc->Y = FormPatterns[i]->LocatePattern->EndShapeRegion->Y;
				int bottomClosestIndex = MToolKit::FindMostClosestRelativeRegion(tmpRRegion, bottomLoc);
				MRelativeRegion* last = new MRelativeRegion();
				last->CloseType = 1;
				last->RegionIndex = tmpRRegion[topClosestIndex]->RegionIndex;
				last->RegionType = tmpRRegion[topClosestIndex]->RegionType;
				last->RelativeX = tmpRRegion[topClosestIndex]->RelativeX - topLoc->X;
				last->RelativeY = tmpRRegion[topClosestIndex]->RelativeY - topLoc->Y;
				lastRIndex = topClosestIndex;
				if (topClosestIndex != bottomClosestIndex)
				{
					if (MToolKit::Distance(FormPatterns[i]->MarkPattern->MarkBlockSet[topClosestIndex]->Position, topLoc) > MToolKit::Distance(FormPatterns[i]->MarkPattern->MarkBlockSet[bottomClosestIndex]->Position, bottomLoc))
					{
						last->CloseType = 2;
						last->RegionIndex = tmpRRegion[bottomClosestIndex]->RegionIndex;
						last->RegionType = tmpRRegion[bottomClosestIndex]->RegionType;
						last->RelativeX = tmpRRegion[bottomClosestIndex]->RelativeX - bottomLoc->X;
						last->RelativeY = tmpRRegion[bottomClosestIndex]->RelativeY - bottomLoc->Y;
						lastRIndex = bottomClosestIndex;
					}
				}
				last->TmpBlackDots = FormPatterns[i]->CountBlackDotsOnRegion(FormPatterns[i]->MarkPattern->MarkBlockSet[last->RegionIndex]->Position);
				FormPatterns[i]->SearchSeq->Add(last);
				ignoreList[lastRIndex] = true;
				MRelativeRegion* current = nullptr;
				int currentRIndex = 0;
				while (FormPatterns[i]->SearchSeq->Count < haveCount)
				{
					current = new MRelativeRegion();
					current->CloseType = 0;
					currentRIndex = MToolKit::FindMostClosestRelativeRegionWithIgnore(tmpRRegion, ignoreList, FormPatterns[i]->MarkPattern->MarkBlockSet[last->RegionIndex]->Position);
					current->RegionType = tmpRRegion[currentRIndex]->RegionType;
					current->RegionIndex = tmpRRegion[currentRIndex]->RegionIndex;
					current->RelativeX = tmpRRegion[currentRIndex]->RelativeX - tmpRRegion[lastRIndex]->RelativeX;
					current->RelativeY = tmpRRegion[currentRIndex]->RelativeY - tmpRRegion[lastRIndex]->RelativeY;
					current->TmpBlackDots = FormPatterns[i]->CountBlackDotsOnRegion(FormPatterns[i]->MarkPattern->MarkBlockSet[current->RegionIndex]->Position);
					ignoreList[currentRIndex] = true;
					last = current;
					lastRIndex = currentRIndex;
					FormPatterns[i]->SearchSeq->Add(current);
				}
			}
		}
		if (FormPatterns[i]->ImageShotPattern != nullptr)
		{
			tmpRRegion = new vector<MRelativeRegion*>();
			for (int j = 0; j < FormPatterns[i]->ImageShotPattern->ShotRegions->Count; ++j)
			{
				MRelativeRegion* relativeRegion = new MRelativeRegion();
				relativeRegion->RegionIndex = j;
				relativeRegion->RegionType = 1;
				relativeRegion->RelativeX = FormPatterns[i]->ImageShotPattern->ShotRegions[j]->X;
				relativeRegion->RelativeY = FormPatterns[i]->ImageShotPattern->ShotRegions[j]->Y;
				tmpRRegion->Add(relativeRegion);
			}
			if (tmpRRegion->Count > 0)
			{
				haveCount += tmpRRegion->Count;
				// 生成搜索顺序
				vector<bool>* ignoreList = new vector<bool>();
				for (int j = 0; j < tmpRRegion->Count; ++j)
					ignoreList->Add(false);
				int lastRIndex = 0;
				// 距离定位块最近
				MRegion* topLoc = new MRegion();
				topLoc->X = FormPatterns[i]->LocatePattern->StartShapeRegion->X;
				topLoc->Y = FormPatterns[i]->LocatePattern->StartShapeRegion->Y;
				int topClosestIndex = MToolKit::FindMostClosestRelativeRegion(tmpRRegion, topLoc);
				MRegion* bottomLoc = new MRegion();
				bottomLoc->X = FormPatterns[i]->LocatePattern->EndShapeRegion->X;
				bottomLoc->Y = FormPatterns[i]->LocatePattern->EndShapeRegion->Y;
				int bottomClosestIndex = MToolKit::FindMostClosestRelativeRegion(tmpRRegion, bottomLoc);
				MRelativeRegion* last = new MRelativeRegion();
				last->CloseType = 1;
				last->RegionIndex = tmpRRegion[topClosestIndex]->RegionIndex;
				last->RegionType = tmpRRegion[topClosestIndex]->RegionType;
				last->RelativeX = tmpRRegion[topClosestIndex]->RelativeX - topLoc->X;
				last->RelativeY = tmpRRegion[topClosestIndex]->RelativeY - topLoc->Y;
				lastRIndex = topClosestIndex;
				if (topClosestIndex != bottomClosestIndex)
				{
					if (MToolKit::Distance(FormPatterns[i]->ImageShotPattern->ShotRegions[topClosestIndex], topLoc) > MToolKit::Distance(FormPatterns[i]->ImageShotPattern->ShotRegions[bottomClosestIndex], bottomLoc))
					{
						last->CloseType = 2;
						last->RegionIndex = tmpRRegion[bottomClosestIndex]->RegionIndex;
						last->RegionType = tmpRRegion[bottomClosestIndex]->RegionType;
						last->RelativeX = tmpRRegion[bottomClosestIndex]->RelativeX - bottomLoc->X;
						last->RelativeY = tmpRRegion[bottomClosestIndex]->RelativeY - bottomLoc->Y;
						lastRIndex = bottomClosestIndex;
					}
				}
				last->TmpBlackDots = FormPatterns[i]->CountBlackDotsOnRegion(FormPatterns[i]->ImageShotPattern->ShotRegions[last->RegionIndex]);
				FormPatterns[i]->SearchSeq->Add(last);
				ignoreList[lastRIndex] = true;
				MRelativeRegion* current = nullptr;
				int currentRIndex = 0;
				while (FormPatterns[i]->SearchSeq->Count < haveCount)
				{
					current = new MRelativeRegion();
					current->CloseType = 0;
					currentRIndex = MToolKit::FindMostClosestRelativeRegionWithIgnore(tmpRRegion, ignoreList, FormPatterns[i]->ImageShotPattern->ShotRegions[last->RegionIndex]);
					current->RegionType = tmpRRegion[currentRIndex]->RegionType;
					current->RegionIndex = tmpRRegion[currentRIndex]->RegionIndex;
					current->RelativeX = tmpRRegion[currentRIndex]->RelativeX - tmpRRegion[lastRIndex]->RelativeX;
					current->RelativeY = tmpRRegion[currentRIndex]->RelativeY - tmpRRegion[lastRIndex]->RelativeY;
					current->TmpBlackDots = FormPatterns[i]->CountBlackDotsOnRegion(FormPatterns[i]->ImageShotPattern->ShotRegions[current->RegionIndex]);
					ignoreList[currentRIndex] = true;
					last = current;
					lastRIndex = currentRIndex;
					FormPatterns[i]->SearchSeq->Add(current);
				}
			}
		}
		if (FormPatterns[i]->BarcodePattern != nullptr)
		{
			tmpRRegion = new vector<MRelativeRegion*>();
			for (int j = 0; j < FormPatterns[i]->BarcodePattern->BarCodeSearchRegions->Count; ++j)
			{
				MRelativeRegion* relativeRegion = new MRelativeRegion();
				relativeRegion->RegionIndex = j;
				relativeRegion->RegionType = 2;
				relativeRegion->RelativeX = FormPatterns[i]->BarcodePattern->BarCodeSearchRegions[j]->X;
				relativeRegion->RelativeY = FormPatterns[i]->BarcodePattern->BarCodeSearchRegions[j]->Y;
				tmpRRegion->Add(relativeRegion);
			}
			if (tmpRRegion->Count > 0)
			{
				haveCount += tmpRRegion->Count;
				// 生成搜索顺序
				vector<bool>* ignoreList = new vector<bool>();
				for (int j = 0; j < tmpRRegion->Count; ++j)
					ignoreList->Add(false);
				int lastRIndex = 0;
				// 距离定位块最近
				MRegion* topLoc = new MRegion();
				topLoc->X = FormPatterns[i]->LocatePattern->StartShapeRegion->X;
				topLoc->Y = FormPatterns[i]->LocatePattern->StartShapeRegion->Y;
				int topClosestIndex = MToolKit::FindMostClosestRelativeRegion(tmpRRegion, topLoc);
				MRegion* bottomLoc = new MRegion();
				bottomLoc->X = FormPatterns[i]->LocatePattern->EndShapeRegion->X;
				bottomLoc->Y = FormPatterns[i]->LocatePattern->EndShapeRegion->Y;
				int bottomClosestIndex = MToolKit::FindMostClosestRelativeRegion(tmpRRegion, bottomLoc);
				MRelativeRegion* last = new MRelativeRegion();
				last->CloseType = 1;
				last->RegionIndex = tmpRRegion[topClosestIndex]->RegionIndex;
				last->RegionType = tmpRRegion[topClosestIndex]->RegionType;
				last->RelativeX = tmpRRegion[topClosestIndex]->RelativeX - topLoc->X;
				last->RelativeY = tmpRRegion[topClosestIndex]->RelativeY - topLoc->Y;
				lastRIndex = topClosestIndex;
				if (topClosestIndex != bottomClosestIndex)
				{
					if (MToolKit::Distance(FormPatterns[i]->BarcodePattern->BarCodeSearchRegions[topClosestIndex], topLoc) > MToolKit::Distance(FormPatterns[i]->BarcodePattern->BarCodeSearchRegions[bottomClosestIndex], bottomLoc))
					{
						last->CloseType = 2;
						last->RegionIndex = tmpRRegion[bottomClosestIndex]->RegionIndex;
						last->RegionType = tmpRRegion[bottomClosestIndex]->RegionType;
						last->RelativeX = tmpRRegion[bottomClosestIndex]->RelativeX - bottomLoc->X;
						last->RelativeY = tmpRRegion[bottomClosestIndex]->RelativeY - bottomLoc->Y;
						lastRIndex = bottomClosestIndex;
					}
				}
				last->TmpBlackDots = FormPatterns[i]->CountBlackDotsOnRegion(FormPatterns[i]->BarcodePattern->BarCodeSearchRegions[last->RegionIndex]);
				FormPatterns[i]->SearchSeq->Add(last);
				ignoreList[lastRIndex] = true;
				MRelativeRegion* current = nullptr;
				int currentRIndex = 0;
				while (FormPatterns[i]->SearchSeq->Count < haveCount)
				{
					current = new MRelativeRegion();
					current->CloseType = 0;
					currentRIndex = MToolKit::FindMostClosestRelativeRegionWithIgnore(tmpRRegion, ignoreList, FormPatterns[i]->BarcodePattern->BarCodeSearchRegions[last->RegionIndex]);
					current->RegionType = tmpRRegion[currentRIndex]->RegionType;
					current->RegionIndex = tmpRRegion[currentRIndex]->RegionIndex;
					current->RelativeX = tmpRRegion[currentRIndex]->RelativeX - tmpRRegion[lastRIndex]->RelativeX;
					current->RelativeY = tmpRRegion[currentRIndex]->RelativeY - tmpRRegion[lastRIndex]->RelativeY;
					current->TmpBlackDots = FormPatterns[i]->CountBlackDotsOnRegion(FormPatterns[i]->BarcodePattern->BarCodeSearchRegions[current->RegionIndex]);
					ignoreList[currentRIndex] = true;
					last = current;
					lastRIndex = currentRIndex;
					FormPatterns[i]->SearchSeq->Add(current);
				}
			}
		}
		if (FormPatterns[i]->SevenSectionPattern != nullptr)
		{
			tmpRRegion = new vector<MRelativeRegion*>();
			for (int j = 0; j < FormPatterns[i]->SevenSectionPattern->SevenSections->Count; ++j)
			{
				MRelativeRegion* relativeRegion = new MRelativeRegion();
				relativeRegion->RegionIndex = j;
				relativeRegion->RegionType = 3;
				relativeRegion->RelativeX = FormPatterns[i]->SevenSectionPattern->SevenSections[j]->X;
				relativeRegion->RelativeY = FormPatterns[i]->SevenSectionPattern->SevenSections[j]->Y;
				tmpRRegion->Add(relativeRegion);
			}
			if (tmpRRegion->Count > 0)
			{
				haveCount += tmpRRegion->Count;
				// 生成搜索顺序
				vector<bool>* ignoreList = new vector<bool>();
				for (int j = 0; j < tmpRRegion->Count; ++j)
					ignoreList->Add(false);
				int lastRIndex = 0;
				// 距离定位块最近
				MRegion* topLoc = new MRegion();
				topLoc->X = FormPatterns[i]->LocatePattern->StartShapeRegion->X;
				topLoc->Y = FormPatterns[i]->LocatePattern->StartShapeRegion->Y;
				int topClosestIndex = MToolKit::FindMostClosestRelativeRegion(tmpRRegion, topLoc);
				MRegion* bottomLoc = new MRegion();
				bottomLoc->X = FormPatterns[i]->LocatePattern->EndShapeRegion->X;
				bottomLoc->Y = FormPatterns[i]->LocatePattern->EndShapeRegion->Y;
				int bottomClosestIndex = MToolKit::FindMostClosestRelativeRegion(tmpRRegion, bottomLoc);
				MRelativeRegion* last = new MRelativeRegion();
				last->CloseType = 1;
				last->RegionIndex = tmpRRegion[topClosestIndex]->RegionIndex;
				last->RegionType = tmpRRegion[topClosestIndex]->RegionType;
				last->RelativeX = tmpRRegion[topClosestIndex]->RelativeX - topLoc->X;
				last->RelativeY = tmpRRegion[topClosestIndex]->RelativeY - topLoc->Y;
				lastRIndex = topClosestIndex;
				if (topClosestIndex != bottomClosestIndex)
				{
					if (MToolKit::Distance(FormPatterns[i]->SevenSectionPattern->SevenSections[topClosestIndex], topLoc) > MToolKit::Distance(FormPatterns[i]->SevenSectionPattern->SevenSections[bottomClosestIndex], bottomLoc))
					{
						last->CloseType = 2;
						last->RegionIndex = tmpRRegion[bottomClosestIndex]->RegionIndex;
						last->RegionType = tmpRRegion[bottomClosestIndex]->RegionType;
						last->RelativeX = tmpRRegion[bottomClosestIndex]->RelativeX - bottomLoc->X;
						last->RelativeY = tmpRRegion[bottomClosestIndex]->RelativeY - bottomLoc->Y;
						lastRIndex = bottomClosestIndex;
					}
				}
				last->TmpBlackDots = FormPatterns[i]->CountBlackDotsOnRegion(FormPatterns[i]->SevenSectionPattern->SevenSections[last->RegionIndex]);
				FormPatterns[i]->SearchSeq->Add(last);
				ignoreList[lastRIndex] = true;
				MRelativeRegion* current = nullptr;
				int currentRIndex = 0;
				while (FormPatterns[i]->SearchSeq->Count < haveCount)
				{
					current = new MRelativeRegion();
					current->CloseType = 0;
					currentRIndex = MToolKit::FindMostClosestRelativeRegionWithIgnore(tmpRRegion, ignoreList, FormPatterns[i]->SevenSectionPattern->SevenSections[last->RegionIndex]);
					current->RegionType = tmpRRegion[currentRIndex]->RegionType;
					current->RegionIndex = tmpRRegion[currentRIndex]->RegionIndex;
					current->RelativeX = tmpRRegion[currentRIndex]->RelativeX - tmpRRegion[lastRIndex]->RelativeX;
					current->RelativeY = tmpRRegion[currentRIndex]->RelativeY - tmpRRegion[lastRIndex]->RelativeY;
					current->TmpBlackDots = FormPatterns[i]->CountBlackDotsOnRegion(FormPatterns[i]->SevenSectionPattern->SevenSections[current->RegionIndex]);
					ignoreList[currentRIndex] = true;
					last = current;
					lastRIndex = currentRIndex;
					FormPatterns[i]->SearchSeq->Add(current);
				}
			}
		}
		if (FormPatterns[i]->OCRPattern != nullptr)
		{
			tmpRRegion = new vector<MRelativeRegion*>();
			for (int j = 0; j < FormPatterns[i]->OCRPattern->OCRRegions->Count; ++j)
			{
				MRelativeRegion* relativeRegion = new MRelativeRegion();
				relativeRegion->RegionIndex = j;
				relativeRegion->RegionType = 4;
				relativeRegion->RelativeX = FormPatterns[i]->OCRPattern->OCRRegions[j]->X;
				relativeRegion->RelativeY = FormPatterns[i]->OCRPattern->OCRRegions[j]->Y;
				tmpRRegion->Add(relativeRegion);
			}
			if (tmpRRegion->Count > 0)
			{
				haveCount += tmpRRegion->Count;
				// 生成搜索顺序
				vector<bool>* ignoreList = new vector<bool>();
				for (int j = 0; j < tmpRRegion->Count; ++j)
					ignoreList->Add(false);
				int lastRIndex = 0;
				// 距离定位块最近
				MRegion* topLoc = new MRegion();
				topLoc->X = FormPatterns[i]->LocatePattern->StartShapeRegion->X;
				topLoc->Y = FormPatterns[i]->LocatePattern->StartShapeRegion->Y;
				int topClosestIndex = MToolKit::FindMostClosestRelativeRegion(tmpRRegion, topLoc);
				MRegion* bottomLoc = new MRegion();
				bottomLoc->X = FormPatterns[i]->LocatePattern->EndShapeRegion->X;
				bottomLoc->Y = FormPatterns[i]->LocatePattern->EndShapeRegion->Y;
				int bottomClosestIndex = MToolKit::FindMostClosestRelativeRegion(tmpRRegion, bottomLoc);
				MRelativeRegion* last = new MRelativeRegion();
				last->CloseType = 1;
				last->RegionIndex = tmpRRegion[topClosestIndex]->RegionIndex;
				last->RegionType = tmpRRegion[topClosestIndex]->RegionType;
				last->RelativeX = tmpRRegion[topClosestIndex]->RelativeX - topLoc->X;
				last->RelativeY = tmpRRegion[topClosestIndex]->RelativeY - topLoc->Y;
				lastRIndex = topClosestIndex;
				if (topClosestIndex != bottomClosestIndex)
				{
					if (MToolKit::Distance(FormPatterns[i]->OCRPattern->OCRRegions[topClosestIndex], topLoc) > MToolKit::Distance(FormPatterns[i]->OCRPattern->OCRRegions[bottomClosestIndex], bottomLoc))
					{
						last->CloseType = 2;
						last->RegionIndex = tmpRRegion[bottomClosestIndex]->RegionIndex;
						last->RegionType = tmpRRegion[bottomClosestIndex]->RegionType;
						last->RelativeX = tmpRRegion[bottomClosestIndex]->RelativeX - bottomLoc->X;
						last->RelativeY = tmpRRegion[bottomClosestIndex]->RelativeY - bottomLoc->Y;
						lastRIndex = bottomClosestIndex;
					}
				}
				last->TmpBlackDots = FormPatterns[i]->CountBlackDotsOnRegion(FormPatterns[i]->OCRPattern->OCRRegions[last->RegionIndex]);
				FormPatterns[i]->SearchSeq->Add(last);
				ignoreList[lastRIndex] = true;
				MRelativeRegion* current = nullptr;
				int currentRIndex = 0;
				while (FormPatterns[i]->SearchSeq->Count < haveCount)
				{
					current = new MRelativeRegion();
					current->CloseType = 0;
					currentRIndex = MToolKit::FindMostClosestRelativeRegionWithIgnore(tmpRRegion, ignoreList, FormPatterns[i]->OCRPattern->OCRRegions[last->RegionIndex]);
					current->RegionType = tmpRRegion[currentRIndex]->RegionType;
					current->RegionIndex = tmpRRegion[currentRIndex]->RegionIndex;
					current->RelativeX = tmpRRegion[currentRIndex]->RelativeX - tmpRRegion[lastRIndex]->RelativeX;
					current->RelativeY = tmpRRegion[currentRIndex]->RelativeY - tmpRRegion[lastRIndex]->RelativeY;
					current->TmpBlackDots = FormPatterns[i]->CountBlackDotsOnRegion(FormPatterns[i]->OCRPattern->OCRRegions[current->RegionIndex]);
					ignoreList[currentRIndex] = true;
					last = current;
					lastRIndex = currentRIndex;
					FormPatterns[i]->SearchSeq->Add(current);
				}
			}
		}
	}
}

void Cm2::FormPattern::MPattern::SaveToFile(string &filePath)
{
	System::Runtime::Serialization::Formatters::Binary::BinaryFormatter* serial = new System::Runtime::Serialization::Formatters::Binary::BinaryFormatter();
	System::IO::Stream* stream = new System::IO::FileStream(filePath, System::IO::FileMode::Create, System::IO::FileAccess::Write, System::IO::FileShare::Read);
	serial->Serialize(stream, this);
	stream->Close();
}

Cm2::FormPattern::MPattern* Cm2::FormPattern::MPattern::LoadFromFile(string &filePath)
{
	Object* obj = nullptr;
	System::Runtime::Serialization::Formatters::Binary::BinaryFormatter* serial = new System::Runtime::Serialization::Formatters::Binary::BinaryFormatter();
	try
	{
		System::IO::Stream* stream = new System::IO::FileStream(filePath, System::IO::FileMode::Open, System::IO::FileAccess::Read, System::IO::FileShare::Read);
		obj = serial->Deserialize(stream);
		stream->Close();
	}
	catch (Exception* e)
	{
	}

	return  (Cm2::FormPattern::MPattern*)obj;
}
*/
