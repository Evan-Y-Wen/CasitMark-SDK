#include "mylabel.h"

MyLabel::MyLabel(QWidget *parent)
	: QLabel(parent)
{
}

MyLabel::~MyLabel()
{
}

void MyLabel::mousePressEvent(QMouseEvent * ev)
{
	Q_UNUSED(ev);//È¥µôwarning
	emit clicked();
}

/*
void MyLabel::mouseReleaseEvent(QMouseEvent * ev)
{
	Q_UNUSED(ev);//È¥µôwarning
	emit release();
}
*/