#pragma once

#include <QScrollArea>
#include <QEvent>
#include <QMouseEvent>

class MyScrollArea : public QScrollArea
{
	Q_OBJECT

public:
	MyScrollArea(QObject *parent);
	~MyScrollArea();



protected:
	//����¼�
	void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;
};
