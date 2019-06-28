#include "pixitem.h"

PixItem::PixItem(QPixmap *pixmap)
{
	_mPix = pixmap;
	_mMousePos = QPointF(0, 0);
	_mIsPress = false;
	_mSelectionModel = nullptr;
	this->setFlag(GraphicsItemFlag::ItemIsMovable);
}

PixItem::~PixItem()
{
	_mSelectionModel = nullptr;
}


/***************************************
*函数功能：重载函数，限定图元边界，并保留2个像素点的冗余
*输入：
*	void
*输出：
*	QRectF：返回图元边界区域
*作者：JZQ
*时间版本：2019-06-19-V1.0
***************************************/
QRectF PixItem::boundingRect() const
{
	return QRectF(-2 - _mPix->width() / 2, -2 - _mPix->height() / 2, _mPix->width() + 4, _mPix->height() + 4);
}


/***************************************
*函数功能：重载函数，重新绘制图元
*输入：
*	painter：绘图器
*	option：重绘图元样式选择
*	widget：绘图窗口
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-19-V1.0
***************************************/
void PixItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawPixmap(-_mPix->width() / 2, -_mPix->height() / 2, *_mPix);

	if (_mSelectionModel == nullptr)
	{
		return;
	}
	if (_mSelectionModel->currentIndex().isValid())
	{
		int column = _mSelectionModel->currentIndex().column();
		QPoint start(0, 0);//得到的起始点//todo:修改坐标
		int Steep = 200;//下一个框的步长
		int height = 100;//框高
		int width = 200;//框长
		QPoint lefttop(start.x(), start.y() + column * Steep);
		QPoint leftbottom(start.x(), start.y() + column * Steep + height);
		QPoint righttop(start.x() + width, start.y() + column * Steep);
		QPoint rightbottom(start.x() + width, start.y() + column * Steep + height);

		QLine line1(lefttop, righttop);
		QLine line2(lefttop, leftbottom);
		QLine line3(leftbottom, rightbottom);
		QLine line4(righttop, rightbottom);
		painter->setBrush(Qt::red);
		painter->setPen(Qt::red);
		painter->drawLine((line1));
		painter->drawLine((line2));
		painter->drawLine((line3));
		painter->drawLine((line4));
	}

}


/***************************************
*函数功能：鼠标移动事件
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-19-V1.0
***************************************/
void PixItem::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
	if (_mIsPress)
	{
		QPointF point = event->pos() - _mMousePos;
		//qDebug() << "MousePos = " << point;
		this->moveBy(point.x(), point.y());
	}
}


/***************************************
*函数功能：鼠标点击事件
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-19-V1.0
***************************************/
void PixItem::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
	_mMousePos = event->pos();
	qDebug() << "mousePressPos(Item):" << _mMousePos;
	qDebug() << "mousePressPos(Scene):" << this->mapToScene(_mMousePos);
	MyGraphicsView *view = static_cast<MyGraphicsView *>(this->scene()->views()[0]);
	qDebug() << "mousePressPos(View):" << view->mapFromScene(this->mapToScene(_mMousePos));
	int ScaleValue = view->getScale();
	if (event->type() == QMouseEvent::GraphicsSceneMouseDoubleClick)
	{//鼠标双击放大
		view->setScale(ScaleValue + 5);
		_mIsPress = false;
	}
	else//单击
	{
		_mIsPress = true;
	}
}


/***************************************
*函数功能：鼠标释放事件
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-19-V1.0
***************************************/
void PixItem::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
	_mIsPress = false;
	_mMousePos = event->pos();
}


/***************************************
*函数功能：鼠标滚轮滚动事件
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-19-V1.0
***************************************/
void PixItem::wheelEvent(QGraphicsSceneWheelEvent * event)
{
	MyGraphicsView *view = static_cast<MyGraphicsView *>(this->scene()->views()[0]);
	int ScaleValue = view->getScale();
	if (event->delta() > 0)  //delta为正，滚轮向上滚
	{
		ScaleValue++;
	}
	else
	{
		ScaleValue--;
	}
	view->setScale(ScaleValue);
}


/***************************************
*函数功能：设置当前选中的Item，实现Item和图元的通信
*输入：
*	selectionModel：当前选中的Item
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-26-V1.0
***************************************/
void PixItem::setSelectionModel(QItemSelectionModel * selectionModel)
{
	_mSelectionModel = selectionModel;
}