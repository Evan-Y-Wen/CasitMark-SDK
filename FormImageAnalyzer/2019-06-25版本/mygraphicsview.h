#pragma once

#include <QGraphicsView>
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
	int _mScaleCount;

public:
	void setRotate(int);
	int getRotate(void);
	void setScale(int);
	qreal getScale(void);
	void stateRecover(void);


};