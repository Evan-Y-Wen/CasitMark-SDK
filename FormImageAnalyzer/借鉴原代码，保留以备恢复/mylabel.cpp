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
	Q_UNUSED(ev);//ȥ��warning
	int delta = 0;
	if (ev->delta() > 0)
	{
		delta = 1;//��ǰ����
	}
	else
	{
		delta = 0;//������
	}
	emit MyLabelWheelSignal(delta);
}
//void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
//void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
//void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
