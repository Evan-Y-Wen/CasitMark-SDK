#include "mregionresult.h"
using namespace Cm3::FormResult;


MRegionResult::MRegionResult()
{
	_name = _backgroundColor = _borderColor = "";
	_x = _y = _width = _height = 0;
}

MRegionResult::~MRegionResult()
{
}

MRegionResult::MRegionResult(double x, double y, double w, double h)
{
	_name = _backgroundColor = _borderColor = "";
	_x = x;
	_y = y;
	_width = w;
	_height = h;
}

MRegionResult * MRegionResult::DeepClone()
{
	return nullptr;
}
