#include "mygraphicsview.h"

MyGraphicsView::MyGraphicsView(QObject *parent)
{
	_mAngle = 0;
	_mScaleValue = 0;
	_mScaleCount = 0;
}

MyGraphicsView::~MyGraphicsView()
{
}


/***************************************
*函数功能：设置视图旋转值
*输入：
*	value：旋转值
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-19-V1.0
***************************************/
void MyGraphicsView::setRotate(int value)
{
	this->rotate(value - _mAngle);
	_mAngle = value;
}


/***************************************
*函数功能：获得视图旋转值
*输入：
*	void
*输出：
*	int：旋转值
*作者：JZQ
*时间版本：2019-06-19-V1.0
***************************************/
int MyGraphicsView::getRotate(void)
{
	return _mAngle;
}


/***************************************
*函数功能：设置视图缩放值
*输入：
*	value：缩放值
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-19-V1.0
***************************************/
void MyGraphicsView::setScale(int value)
{
	_mScaleCount += (value - _mScaleValue);
	qreal s;
	if (value > _mScaleValue)
		s = pow(1.1, (value - _mScaleValue));
	else
		s = pow(1 / 1.1, (_mScaleValue - value));
	this->scale(s, s);
	_mScaleValue = value;
}


/***************************************
*函数功能：获得视图缩放值
*输入：
*	void
*输出：
*	qreal：缩放值
*作者：JZQ
*时间版本：2019-06-19-V1.0
***************************************/
qreal MyGraphicsView::getScale(void)
{
	return _mScaleValue;
}


/***************************************
*函数功能：实现视图复原功能
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-19-V1.0
***************************************/
void MyGraphicsView::stateRecover(void)
{
	qreal s;
	if (_mScaleCount < 0)
		s = pow(1.1, (-_mScaleCount));
	else
		s = pow(1 / 1.1, (_mScaleCount));
	this->scale(s, s);
	this->setRotate(0);
	_mScaleCount = 0;
	_mScaleValue = 0;
	_mAngle = 0;
}

