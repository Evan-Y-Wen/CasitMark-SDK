#include "MRegion.h"
using namespace Cm3::FormPattern;

#include <QString>


MRegion::MRegion()
{
	_name = _backgroundColor = _borderColor = "";
	_x = _y = _width = _height = 0;
}

MRegion::MRegion(double x, double y, double w, double h)
{
	_name = _backgroundColor = _borderColor = "";
	_x = x;
	_y = y;
	_width = w;
	_height = h;
}

MRegion::~MRegion()
{
}
