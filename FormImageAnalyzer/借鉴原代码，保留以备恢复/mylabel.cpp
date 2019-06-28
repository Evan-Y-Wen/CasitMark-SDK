#include "mylabel.h"

MyLabel::MyLabel(QWidget *parent)
	: QLabel(parent)
{
}

MyLabel::~MyLabel()
{
}

void MyLabel::wheelEvent(QWheelEvent *ev)
{
	Q_UNUSED(ev);//去掉warning
	int delta = 0;
	if (ev->delta() > 0)
	{
		delta = 1;//向前滚动
	}
	else
	{
		delta = 0;//向后滚动
	}
	emit MyLabelWheelSignal(delta);
}
//void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
//void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
//void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
