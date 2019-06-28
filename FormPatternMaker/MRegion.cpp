#include "MRegion.h"
#include <iostream>
#include <string>
using namespace std;

Cm2::FormPattern::MRegion::MRegion(void)
{
	cout << "MRegion 默认构造函数测试" << endl;
	Name = BackgroundColor = BorderColor = "";
	X = Y = Width = Height = 0;
}

Cm2::FormPattern::MRegion::MRegion(int x, int y, int w, int h)
{
	Name = "";
	X = x;
	Y = y;
	Width = w;
	Height = h;
}

Cm2::FormPattern::MRegion::~MRegion()
{
	//该类里没有指针类型的成员变量。
}

void Cm2::FormPattern::MRegion::InRegion( int x, int y, int w, int h )
{
	if(X < x)
	{
		Width -= x - X;
		X = x;
	}
	if(X + Width > x + w)
		Width -= X + Width - x - w;
	if(Y < y)
	{
		Height -= y - Y;
		Y = y;
	}
	if(Y + Height > y + h)
		Height -= Y + Height - y - h;
	if(X < 0)
		X = 0;
	if(Y < 0)
		Y = 0;
	if(Width < 0)
		Width = 0;
	if(Height < 0)
		Height = 0;
}

void Cm2::FormPattern::MRegion::InRegion( MRegion &region )
{
	if(X < region.X)
	{
		Width -= region.X - X;
		X = region.X;
	}
	if(X + Width > region.X + region.Width)
		Width -= X + Width - region.X - region.Width;
	if(Y < region.Y)
	{
		Height -= region.Y - Y;
		Y = region.Y;
	}
	if(Y + Height > region.Y + region.Height)
		Height -= Y + Height - region.Y - region.Height;
	if(X < 0)
		X = 0;
	if(Y < 0)
		Y = 0;
	if(Width < 0)
		Width = 0;
	if(Height < 0)
		Height = 0;
}

Cm2::FormPattern::MRegion *Cm2::FormPattern::MRegion::DeepClone()
{
	MRegion *rst = new MRegion();
	if (rst == nullptr)
	{
		cout << "MRegion *rst = new MRegion();分配内存失败" << endl;
		return nullptr;
	}
	rst->Name = Name;
	rst->X = X;
	rst->Y = Y;
	rst->Width = Width;
	rst->Height = Height;
	rst->BackgroundColor = BackgroundColor;
	rst->BorderColor = BorderColor;
	return rst;//返回局部变量地址，匿名对象问题，需要将匿名对象扶正。
}
