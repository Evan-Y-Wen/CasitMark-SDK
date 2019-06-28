#pragma once

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QDebug>

class MyGraphicsView : public QGraphicsView
{
	Q_OBJECT

public:
	MyGraphicsView(QObject *parent);
	~MyGraphicsView();


private:
	int _mAngle;
	qreal _mScaleValue;

public:
	void setRotate(int);
	int getRotate(void);
	void setScale(int);
	qreal getScale(void);

protected:
	void wheelEvent(QWheelEvent *event);


};