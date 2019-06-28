#include "pixitem.h"

/***************************************
*函数功能：构造函数初始化了变量mPixmap
*输入：
*	pixmap:初始化需要显示的图片
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-13-V1.0
***************************************/
PixItem::PixItem(QPixmap *pixmap)
{
	mScaleValue = 0;   //缩放值，0代表原图大小，+1代表放大0.1，-1代表缩小0.1
	mPixmap = *pixmap;    //作为图元显示的图片
	mIsPress = false; //鼠标点击标志
	mStartPos = QPointF();
	mZoomState = NOSTATE;//缩放状态：放大、缩小
	mRotationState = UP;//旋转状态

	setAcceptDrops(true);   //设置可拖拽
	setFlag(GraphicsItemFlag::ItemIsMovable);//设置图元可移动
}


/***************************************
*函数功能：实现自己的图元边界函数
*输入：
*	void
*输出：
*	QRectF:返回一个矩形坐标，图元边界
*作者：JZQ
*时间版本：2019-06-13-V1.0
***************************************/
QRectF PixItem::boundingRect() const
{
	return QRectF(-2 - mPixmap.width() / 2, -2 - mPixmap.height() / 2, mPixmap.width() + 4, mPixmap.height() + 4);
}


/***************************************
*函数功能：重画图形，重载抽象函数：void QGraphicsItem::paint(QPainter *,const QStyleOptionGraphicsItem *,QWidget *)
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-13-V1.0
***************************************/
void PixItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(-mPixmap.width() / 2, -mPixmap.height() / 2, mPixmap);
}


/***************************************
*函数功能：使用滚轮整体缩放
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-13-V1.0
***************************************/
void PixItem::wheelEvent(QGraphicsSceneWheelEvent *event)
{
	setZoomState(NOSTATE);

	int scaleValue = mScaleValue;
	if (event->delta() > 0)  //delta（）为正，滚轮向上滚
	{
		scaleValue++;
	}
	else
	{
		scaleValue--;
	}

	if (scaleValue > ZOOMINRange || scaleValue < ZOOMOUTRange)
		return;//超过这个范围，就不再缩放
		

	mScaleValue = scaleValue;//新的缩放值
	qreal s;//真正的缩放比例
	if (mScaleValue > 0)//放大 
	{
		s = pow(1.1, mScaleValue);        //计算x的y方次 参数都是double类型
	}
	else//缩小
	{
		s = pow(1 / 1.1, -mScaleValue);
	}

	setTransformOriginPoint(0, 0);
	setScale(s);
	//qDebug() << "Rotation pos()：" << event->pos();
}


/***************************************
*函数功能：鼠标点击事件，单击可实现拖拽图片功能；双击可实现放大图片功能
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-13-V1.0
***************************************/
void PixItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    mStartPos = event->pos();
	qDebug() << mStartPos;
	
	if (event->type() == QMouseEvent::GraphicsSceneMouseDoubleClick)
	{//鼠标双击放大
		int scaleValue = mScaleValue + 2;//放大0.2

		if (scaleValue > ZOOMINRange || scaleValue < ZOOMOUTRange)
			return;

		setTransformOriginPoint(event->pos().x(), event->pos().y());
		mScaleValue = scaleValue;//将信息值赋给成员变量
		qreal s = pow(1.1, mScaleValue);        //放大 计算x的y方次 参数都是double类型
		setScale(s);
		mIsPress = false;
	}
	else//单击
	{
		mIsPress = true;
	}
}


/***************************************
*函数功能：鼠标移动事件，与单击事件配合，可实现图片拖拽功能
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-13-V1.0
***************************************/
void PixItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	QPointF point = event->pos() - mStartPos;
	qDebug() << point;
    if(mIsPress)
    {
		if (abs(point.x()) > 1)
		{
			point.setX(point.x() / abs(point.x()) * 1.2);
		}
		if (abs(point.y()) > 1)
		{
			point.setY(point.y() / abs(point.y()) * 1.2);
		}

		QPointF point1;
		switch (mRotationState)
		{//绝对坐标变换
		case UP:
			point1.setX(point.x());
			point1.setY(point.y());
			break;
		case DOWN:
			point1.setX(-point.x());
			point1.setY(-point.y());
			break;
		case LEFT:
			point1.setX(point.y());
			point1.setY(-point.x());
			break;
		case RIGHT:
			point1.setX(-point.y());
			point1.setY(point.x());
			break;
		default:
			break;
		}
        QGraphicsItem::moveBy(point1.x(),point1.y());
		//QGraphicsItem::moveBy(event->pos().x(), event->pos().y());
    }
}


/***************************************
*函数功能：鼠标释放事件，
*输入：
*	void
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-13-V1.0
***************************************/
void PixItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    mIsPress = false;
	//mStartPos = event->pos();
}


/***************************************
*函数功能：设置缩放状态
*输入：
*	zoomState:缩放状态
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-13-V1.0
***************************************/
void PixItem::setZoomState(const Enum_ZoomState &zoomState)
{
	mZoomState = zoomState;
	if (mZoomState == RESET)
	{
		mScaleValue = 0;
		setScale(1);//设置缩放比例
		setTransformOriginPoint(0, 0);//设置当前图形原点
		//将当前图形原点移动到新的坐标系中心位置。
		//setTransformOriginPoint(boundingRect().center());
	}
}


/***************************************
*函数功能：设置缩放值
*输入：
*	scaleValue:缩放值，0代表原图大小，+1代表放大0.1，-1代表缩小0.1
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-13-V1.0
***************************************/
void PixItem::setScaleValue(const int &scaleValue)
{
    if (scaleValue > ZOOMINRange || scaleValue < ZOOMOUTRange)
        return;

    mScaleValue = scaleValue;

    qreal s;
    if(mScaleValue > 0)
    {
        s = pow(1.1, mScaleValue);        //放大 计算x的y方次 参数都是double类型
    }
    else
    {
        s = pow(1 / 1.1, -mScaleValue);      //缩小
    }

    setScale(s);
}


/***************************************
*函数功能：设置旋转状态
*输入：
*	rotationState:旋转值。
*输出：
*	void
*作者：JZQ
*时间版本：2019-06-17-V1.0
***************************************/
void PixItem::setRotationValue(const int & rotationState)
{
	int mRotation = rotationState;
	if (mRotation > 360 || mRotation < -360)
	{
		mRotation = mRotation % 360;
	}
	//setTransformOriginPoint(0, 0);//以坐标系原点为旋转中心
	qDebug() << "mRotationState:" << mRotationState;
	if (rotationState == 0 || rotationState == 360)
	{
		mRotationState = UP;
		setRotation(UP);
		//this->parentItem->rotate(UP);//view旋转
		return;
	}
	if (rotationState == 180 || rotationState == -180)
	{
		mRotationState = DOWN;
		setRotation(DOWN);
		//this->parentItem->rotate(DOWN);
		return;
	}
	if (rotationState == 90 || rotationState == -270)
	{
		mRotationState = RIGHT;
		setRotation(RIGHT);
		//this->parentItem->rotate(RIGHT);
		return;
	}
	if (rotationState == 270 || rotationState == -90)
	{
		mRotationState = LEFT;
		setRotation(LEFT);
		//this->parentItem->rotate(LEFT);
		return;
	}
}


/***************************************
*函数功能：获取旋转状态
*输入：
*	void
*输出：
*	rotation:获取当前的旋转状态
*作者：JZQ
*时间版本：2019-06-17-V1.0
***************************************/
int PixItem::getRotationValue() const
{
	return rotation();
}


/***************************************
*函数功能：获取缩放值
*输入：
*	void
*输出：
*	mScaleValue:获取当前的缩放值
*作者：JZQ
*时间版本：2019-06-13-V1.0
***************************************/
int PixItem::getScaleValue() const
{
    return mScaleValue;
}
