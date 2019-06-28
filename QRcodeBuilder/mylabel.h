#pragma once

#include <QLabel>
#include <QMouseEvent>


class MyLabel : public QLabel
{
	Q_OBJECT

public:
	MyLabel(QWidget *parent);
	~MyLabel();


signals:
	void clicked();
	//void release();//暂时用不上释放点击信号

protected:
	void mousePressEvent(QMouseEvent* ev);
	//void mouseReleaseEvent(QMouseEvent* ev);
};