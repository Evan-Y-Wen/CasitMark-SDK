#include "mygraphicsview.h"

MyGraphicsView::MyGraphicsView(QObject *parent)
{
	_mAngle = 0;
	_mScaleValue = 0;
}

MyGraphicsView::~MyGraphicsView()
{
}


void MyGraphicsView::setRotate(int value)
{
	this->rotate(value - _mAngle);
	_mAngle = value;
}

int MyGraphicsView::getRotate(void)
{
	return _mAngle;
}

void MyGraphicsView::setScale(int value)
{
	qreal s;
	if (value > _mScaleValue)
		s = pow(1.1, (value - _mScaleValue));
	else
		s = pow(1 / 1.1, (_mScaleValue - value));
	this->scale(s, s);
	_mScaleValue = value;
}

qreal MyGraphicsView::getScale(void)
{
	return _mScaleValue;
}


void MyGraphicsView::wheelEvent(QWheelEvent * event)
{
	int ScaleValue = _mScaleValue;
	if (event->delta() > 0)  //delta为正，滚轮向上滚
	{
		ScaleValue++;
	}
	else
	{
		ScaleValue--;
	}

	qreal s;
	if (ScaleValue > _mScaleValue)
		s = pow(1.1, (ScaleValue - _mScaleValue));
	else
		s = pow(1 / 1.1, (_mScaleValue - ScaleValue));
	this->scale(s, s);
	_mScaleValue = ScaleValue;
}


