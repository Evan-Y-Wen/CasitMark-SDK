#pragma once

#include <QGraphicsItem>
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
#include <QLine>
#include <QPoint>
#include <QItemSelectionModel>

#include "mygraphicsview.h"

class PixItem : public QGraphicsItem
{
public:
	PixItem(QPixmap *pixmap);

	~PixItem();

	QRectF boundingRect() const;

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	//为selections赋初值
	void setSelectionModel(QItemSelectionModel *selectionModel);

private:
	QPixmap pix;     		//作为图元显示的图片
	bool _mIsPress;
	QPointF _mMousePos;
	QItemSelectionModel *_mSelectionModel;

protected:
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
	void wheelEvent(QGraphicsSceneWheelEvent *event);


};
