#include "MToolKit.h"
#include "MRegion.h"
#include "MMarkBlock.h"
#include "MRelativeRegion.h"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

//using namespace System::Runtime::InteropServices;

Cm2::FormPattern::MToolKit::MToolKit(void)
{
	cout << "MToolKit Ĭ�Ϲ��캯������" << endl;
}

Cm2::FormPattern::MToolKit::~MToolKit()
{
	//û�г�Ա����
}

void Cm2::FormPattern::MToolKit::ConvertToStdString(string &mstr, std::string &str)
{
	//��������������ǣ�cli�﷨ �� System::String^ ת��Ϊ std::string
	//��Ϊ��д�������Ƕ���Ϊstd::string�����Բ���Ҫת���ˡ�

	//���й� String �е����ݸ��Ƶ����й��ڴ棬���ڸ���ʱת��Ϊ ANSI ��ʽ��
	//StringToHGlobalAnsi �����Զ�����ʹ�������ڻ���йܺͷ��йܴ���ʱ�����á�
	//���ڸ÷��������ַ�������ķ��й��ڴ棬���Ӧʼ��ͨ������ FreeHGlobal �ͷ��ڴ档

	//char* p = (char*)(int)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(mstr);//cli�﷨ �� System::String^ ת��Ϊ char*
	//str = p;
	//System::Runtime::InteropServices::Marshal::FreeHGlobal((System::IntPtr)p);
	mstr = str;
}

double Cm2::FormPattern::MToolKit::Distance(Cm2::FormPattern::MRegion &from, Cm2::FormPattern::MRegion &to)
{
	return sqrt(pow(to.X - from.X, 2.0) + pow(to.Y - from.Y, 2.0));
}

double Cm2::FormPattern::MToolKit::Distance(Cm2::FormPattern::MRelativeRegion &from, Cm2::FormPattern::MRegion &to)
{
	return sqrt(pow(to.X - from.RelativeX, 2.0) + pow(to.Y - from.RelativeY, 2.0));
}

int Cm2::FormPattern::MToolKit::FindMostClosestRegion(vector<Cm2::FormPattern::MRegion*> &regions, Cm2::FormPattern::MRegion &relative)
{
	double min = Distance(*(regions[0]), relative);
	int rst = 0;
	for (int i = 0; i < regions.size(); ++i)
	{
		double dis = Distance(*(regions[i]), relative);
		if(dis < min)
		{
			rst = i;
			min = dis;
		}
	}

	return rst;
}

int Cm2::FormPattern::MToolKit::FindMostClosestRegionWithIgnore(vector<Cm2::FormPattern::MRegion*> &regions, vector<bool> &ignore, Cm2::FormPattern::MRegion &relative)
{
	double min = Distance(*(regions[0]), relative);
	int rst = 0;
	for (int i = 0; i < regions.size(); ++i)
	{
		if(!ignore[i])
		{
			double dis = Distance(*(regions[i]), relative);
			if(dis < min)
			{
				rst = i;
				min = dis;
			}
		}
	}

	return rst;
}

int Cm2::FormPattern::MToolKit::FindMostClosestBlock(vector<Cm2::FormPattern::MMarkBlock*> &blocks, Cm2::FormPattern::MRegion &relative)
{
	double min = Distance(*(blocks[0]->Position), relative);
	int rst = 0;
	for (int i = 0; i < blocks.size(); ++i)
	{
		double dis = Distance(*(blocks[i]->Position), relative);
		if(dis < min)
		{
			rst = i;
			min = dis;
		}
	}

	return rst;
}

int Cm2::FormPattern::MToolKit::FindMostClosestBlockWithIgnore(vector<Cm2::FormPattern::MMarkBlock*> &blocks, vector<bool> &ignore, Cm2::FormPattern::MRegion &relative)
{
	double min = Distance(*(blocks[0]->Position), relative);
	int rst = 0;
	for (int i = 0; i < blocks.size(); ++i)
	{
		if(!ignore[i])
		{
			double dis = Distance(*(blocks[i]->Position), relative);
			if(dis < min)
			{
				rst = i;
				min = dis;
			}
		}
	}

	return rst;
}

int Cm2::FormPattern::MToolKit::FindMostClosestRelativeRegion(vector<Cm2::FormPattern::MRelativeRegion*> &regions, Cm2::FormPattern::MRegion &relative)
{
	double min = 5000;
	int rst = 0;
	for (int i = 0; i < regions.size(); ++i)
	{
		double dis = Distance(*(regions[i]), relative);
		if(dis < min)
		{
			rst = i;
			min = dis;
		}
	}

	return rst;
}

int Cm2::FormPattern::MToolKit::FindMostClosestRelativeRegionWithIgnore(vector<Cm2::FormPattern::MRelativeRegion*> &regions, vector<bool> &ignore, Cm2::FormPattern::MRegion &relative)
{
	double min = 5000;
	int rst = 0;
	for (int i = 0; i < regions.size(); ++i)
	{
		if(!ignore[i])
		{
			double dis = Distance(*(regions[i]), relative);
			if(dis < min)
			{
				rst = i;
				min = dis;
			}
		}
	}

	return rst;
}

//��Ҫ�޸ġ����ᡢ������
//System::Drawing::Bitmap* Cm2::FormPattern::MToolKit::CreateGrayImage( vector<unsigned char> &imageData, int width, int height )
//{
//	System::Drawing::Bitmap* bitmap = gcnew System::Drawing::Bitmap(width, height, System::Drawing::Imaging::PixelFormat::Format8bppIndexed);
//	System::Drawing::Rectangle rect(0, 0, bitmap.Width, bitmap.Height);
//	System::Drawing::Imaging::BitmapData* grayBmpData = bitmap.LockBits(rect, System::Drawing::Imaging::ImageLockMode::WriteOnly, bitmap.PixelFormat);
//	int stride = grayBmpData.Stride;  // ɨ���ߵĿ��  
//	int scanBytes = stride * height;// ��stride��ȣ���ʾ�����ڴ�����Ĵ�С
//	array<Byte>* pixelValues = gcnew array<Byte>(scanBytes);  //ΪĿ����������ڴ�     
//	for (int y = 0; y < height; y++)  
//		Array::Copy(imageData, y * width, pixelValues, y * stride, width);
//	Marshal::Copy(pixelValues, 0, grayBmpData.Scan0, scanBytes);
//	bitmap.UnlockBits(grayBmpData);  // �����ڴ�����
//	System::Drawing::Imaging::ColorPalette* cp = bitmap.Palette;
//	for (int i = 0; i < 256; i++) 
//	{ 
//		cp.Entries[i] = System::Drawing::Color::FromArgb(i, i, i);
//	} 
//	bitmap.Palette = cp;
//	return bitmap;
//}
