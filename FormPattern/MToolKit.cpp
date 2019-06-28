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
	cout << "MToolKit 默认构造函数测试" << endl;
}

Cm2::FormPattern::MToolKit::~MToolKit()
{
	//没有成员变量
}

void Cm2::FormPattern::MToolKit::ConvertToStdString(string &mstr, std::string &str)
{
	//这个函数的作用是：cli语法 将 System::String^ 转换为 std::string
	//因为重写后本来就是定义为std::string，所以不需要转换了。

	//将托管 String 中的内容复制到非托管内存，并在复制时转换为 ANSI 格式。
	//StringToHGlobalAnsi 对于自定义封送处理或者在混合托管和非托管代码时很有用。
	//由于该方法分配字符串所需的非托管内存，因此应始终通过调用 FreeHGlobal 释放内存。

	//char* p = (char*)(int)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(mstr);//cli语法 将 System::String^ 转换为 char*
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

//需要修改。不会、、、、
//System::Drawing::Bitmap* Cm2::FormPattern::MToolKit::CreateGrayImage( vector<unsigned char> &imageData, int width, int height )
//{
//	System::Drawing::Bitmap* bitmap = gcnew System::Drawing::Bitmap(width, height, System::Drawing::Imaging::PixelFormat::Format8bppIndexed);
//	System::Drawing::Rectangle rect(0, 0, bitmap.Width, bitmap.Height);
//	System::Drawing::Imaging::BitmapData* grayBmpData = bitmap.LockBits(rect, System::Drawing::Imaging::ImageLockMode::WriteOnly, bitmap.PixelFormat);
//	int stride = grayBmpData.Stride;  // 扫描线的宽度  
//	int scanBytes = stride * height;// 用stride宽度，表示这是内存区域的大小
//	array<Byte>* pixelValues = gcnew array<Byte>(scanBytes);  //为目标数组分配内存     
//	for (int y = 0; y < height; y++)  
//		Array::Copy(imageData, y * width, pixelValues, y * stride, width);
//	Marshal::Copy(pixelValues, 0, grayBmpData.Scan0, scanBytes);
//	bitmap.UnlockBits(grayBmpData);  // 解锁内存区域
//	System::Drawing::Imaging::ColorPalette* cp = bitmap.Palette;
//	for (int i = 0; i < 256; i++) 
//	{ 
//		cp.Entries[i] = System::Drawing::Color::FromArgb(i, i, i);
//	} 
//	bitmap.Palette = cp;
//	return bitmap;
//}
