#pragma once

#include <QLabel>
#include <QEvent>
#include <QMouseEvent>


class MyLabel : public QLabel
{
	Q_OBJECT

public:
	MyLabel(QWidget *parent);
	~MyLabel();


signals:
	void MyLabelWheelSignal(int delta);

protected:
	//Êó±êÊÂ¼þ
	void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;
	//void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	//void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	//void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
};