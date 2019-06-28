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
	//void release();//��ʱ�ò����ͷŵ���ź�

protected:
	void mousePressEvent(QMouseEvent* ev);
	//void mouseReleaseEvent(QMouseEvent* ev);
};