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
*�������ܣ�������ͼ��תֵ
*���룺
*	value����תֵ
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-19-V1.0
***************************************/
void MyGraphicsView::setRotate(int value)
{
	this->rotate(value - _mAngle);
	_mAngle = value;
}


/***************************************
*�������ܣ������ͼ��תֵ
*���룺
*	void
*�����
*	int����תֵ
*���ߣ�JZQ
*ʱ��汾��2019-06-19-V1.0
***************************************/
int MyGraphicsView::getRotate(void)
{
	return _mAngle;
}


/***************************************
*�������ܣ�������ͼ����ֵ
*���룺
*	value������ֵ
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-19-V1.0
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
*�������ܣ������ͼ����ֵ
*���룺
*	void
*�����
*	qreal������ֵ
*���ߣ�JZQ
*ʱ��汾��2019-06-19-V1.0
***************************************/
qreal MyGraphicsView::getScale(void)
{
	return _mScaleValue;
}


/***************************************
*�������ܣ�ʵ����ͼ��ԭ����
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-19-V1.0
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

