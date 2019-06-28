#include "MLocatePattern.h"
#include "MRegion.h"
#include <iostream>
#include <string>
using namespace std;

Cm2::FormPattern::MLocatePattern::MLocatePattern()
{
	cout << "MLocatePattern Ĭ�Ϲ��캯������" << endl;
	StartSearchRegion = nullptr;
	EndSearchRegion = nullptr;
	StartShapeRegion = nullptr;
	EndShapeRegion = nullptr;
	StartSimpleCodeValue = -1;
	EndSimpleCodeValue = -1;
}

Cm2::FormPattern::MLocatePattern::~MLocatePattern()
{
	if (StartSearchRegion != nullptr)
	{
		delete StartSearchRegion;
		StartSearchRegion = nullptr;
	}
	if (EndSearchRegion != nullptr)
	{
		delete EndSearchRegion;
		EndSearchRegion = nullptr;
	}
	if (StartShapeRegion != nullptr)
	{
		delete StartShapeRegion;
		StartShapeRegion = nullptr;
	}
	if (EndShapeRegion != nullptr)
	{
		delete EndShapeRegion;
		EndShapeRegion = nullptr;
	}
}
