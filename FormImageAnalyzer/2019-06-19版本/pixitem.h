#pragma once

#include <QGraphicsItem>
#include <QPixmap>
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>

class PixItem : public QGraphicsItem
{
public:
	PixItem(QPixmap *pixmap);

	QRectF boundingRect() const;

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
	QPixmap pix;     		//作为图元显示的图片
	bool _mIsPress;
	QPointF _mMousePos;

protected:
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

};
