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

	// 图元边界函数重载
	QRectF boundingRect() const;

	// 图元重绘函数重载
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	// 为selections赋初值
	void setSelectionModel(QItemSelectionModel *selectionModel);

private:
	QPixmap *_mPix;     		// 作为图元显示的图片，由主调函数分配内存
	bool _mIsPress;
	QPointF _mMousePos;
	QItemSelectionModel *_mSelectionModel;// 用来表示当前选中的Item，实现Item和图元的通信，由主调函数分配内存

protected:
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
	void wheelEvent(QGraphicsSceneWheelEvent *event);


};
