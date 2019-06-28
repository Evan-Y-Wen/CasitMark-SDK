#include "pixitem.h"

PixItem::PixItem(QPixmap *pixmap)
{
	pix = *pixmap;
	_mMousePos = QPointF(0, 0);
	_mIsPress = false;
	this->setFlag(GraphicsItemFlag::ItemIsMovable);
}

QRectF PixItem::boundingRect() const
{
	return QRectF(-2 - pix.width() / 2, -2 - pix.height() / 2, pix.width() + 4, pix.height() + 4);
}

void PixItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawPixmap(-pix.width() / 2, -pix.height() / 2, pix);
}

void PixItem::mouseMoveEvent(QMouseEvent * event)
{
	if (_mIsPress)
	{
		QPointF point = event->pos() - _mMousePos;
		qDebug() << "MousePos = " << point;
		this->moveBy(point.x(), point.y());
	}
}

void PixItem::mousePressEvent(QMouseEvent * event)
{
	_mMousePos = event->pos();
	qDebug() << _mMousePos;

	_mIsPress = true;
}

void PixItem::mouseReleaseEvent(QMouseEvent * event)
{
	_mIsPress = false;
	_mMousePos = event->pos();
}
