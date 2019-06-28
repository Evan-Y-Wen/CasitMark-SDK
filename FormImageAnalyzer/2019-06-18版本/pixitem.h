#pragma once

#include <QPixmap>
#include <QPainter>
#include <QRectF>
#include <QPointF>
#include <QMouseEvent>
#include <QGraphicsItem>
#include <QGraphicsSceneWheelEvent>
#include <QGraphicsSceneMouseEvent>
#include <math.h>
#include <QDebug>


//枚举类型定义
enum Enum_ZoomState{//缩放状态
    NOSTATE,//初始化
    RESET,//还原
    ZOOMIN,//放大
    ZOOMOUT,//缩小
};
enum Enum_ZoomRange{//缩放范围设置
    ZOOMINRange = 10,
    ZOOMOUTRange = -50,
};
enum Enum_RotationState {
	UP = 0,//向上，原始状态
	DOWN = 180,//向下，倒转
	LEFT = -90,//向左
	RIGHT = 90,//向右
};


class PixItem : public QGraphicsItem
{
public:
    PixItem(QPixmap *pixmap); 

//成员函数
public:
    QRectF boundingRect() const;    
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //重画图形函数
	void setZoomState(const Enum_ZoomState &zoomState);  //设置缩放状态
    int getScaleValue() const;
    void setScaleValue(const int &);
	void setRotationValue(const int &);
	int getRotationValue() const;

protected:
	void wheelEvent(QGraphicsSceneWheelEvent *event);  //鼠标滚轮滚动缩放
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

//成员变量
private:
    int mScaleValue;   //缩放值，0代表原图大小，+1代表放大0.1，-1代表缩小0.1
    QPixmap mPixmap;    //作为图元显示的图片
	bool mIsPress; //鼠标点击标志
	QPointF mStartPos;
	Enum_ZoomState mZoomState;//缩放状态：放大、缩小
	Enum_ZoomRange mZoomRange;//缩放范围
	Enum_RotationState mRotationState;//旋转状态
};
