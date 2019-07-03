#pragma once

#include <QDialog>
#include "xlsx\xlsxdocument.h"
#include "xlsx\xlsxdocument_p.h"
#include "xlsx\xlsxformat.h"
#include <QString>
#include <QtCore>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

class ExcelReader : public QDialog
{
	Q_OBJECT

public:
	ExcelReader(QWidget *parent = Q_NULLPTR);
	~ExcelReader();

/***************************************
*定义：成员函数
*属性：公有
***************************************/
public:
	void newExcel();//新建一个不存在的excel
	void openExcel();//打开一个已存在的excel
	void readExcel();//读取Excel，只能读取文本。//todo:可能不会使用这个函数，若确定不使用，可以删除。。。
	void writeExcel(const int iRow, const int iColumn, const QString content);
	void mergeCells(const int firstRow, const int firstColumn, const int lastRow, const int lastColumn);//合并单元格(横向合并或者纵向合并)
	void unmergeCells(const int firstRow, const int firstColumn, const int lastRow, const int lastColumn);//拆分某个区域单元格

/***************************************
*定义：成员变量
*属性：私有
***************************************/
private:
	QXlsx::Document *_mExcel = nullptr;
};
