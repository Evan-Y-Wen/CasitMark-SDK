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
*���壺��Ա����
*���ԣ�����
***************************************/
public:
	void newExcel();//�½�һ�������ڵ�excel
	void openExcel();//��һ���Ѵ��ڵ�excel
	void readExcel();//��ȡExcel��ֻ�ܶ�ȡ�ı���//todo:���ܲ���ʹ�������������ȷ����ʹ�ã�����ɾ��������
	void writeExcel(const int iRow, const int iColumn, const QString content);
	void mergeCells(const int firstRow, const int firstColumn, const int lastRow, const int lastColumn);//�ϲ���Ԫ��(����ϲ���������ϲ�)
	void unmergeCells(const int firstRow, const int firstColumn, const int lastRow, const int lastColumn);//���ĳ������Ԫ��

/***************************************
*���壺��Ա����
*���ԣ�˽��
***************************************/
private:
	QXlsx::Document *_mExcel = nullptr;
};
