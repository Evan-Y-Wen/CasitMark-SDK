#include "excelreader.h"

ExcelReader::ExcelReader(QWidget *parent) : QDialog(parent)
{
	_mExcel = nullptr;
	//���ú���
	//readExcel();
	//changeExcel(1, 2, QStringLiteral("��������"));
	//testPicture();
	//mergeCells(1,1, 3,3);
}

ExcelReader::~ExcelReader()
{
	if (_mExcel != nullptr)
	{
		delete _mExcel;
	}
	_mExcel = nullptr;
}


/***************************************
*�������ܣ��½�һ��Excel
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-07-03-V1.0
***************************************/
void ExcelReader::newExcel()
{
	//�½�Excel�ļ�
	QString excelSaveFileName = QFileDialog::getSaveFileName(0, QStringLiteral("�������ݽ����..."), QString(), "Excel(*.xlsx)");
	if (excelSaveFileName.isEmpty())
	{
		QMessageBox::information(0, QStringLiteral("ȡ���½�"), QStringLiteral("ȡ��EXCEL�½�"));
	}
	if (_mExcel != nullptr)
	{
		delete _mExcel;
		_mExcel = nullptr;
	}
	_mExcel = new QXlsx::Document(excelSaveFileName);
	if (_mExcel == nullptr)
	{
		QMessageBox::critical(0, QStringLiteral("������Ϣ"), QStringLiteral("EXCEL����ʧ"));
		return;
	}
}


/***************************************
*�������ܣ���Excel�ļ�
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-07-03-V1.0
***************************************/
void ExcelReader::openExcel()
{
	//��Excel�ļ�
	QString excelFileName = QFileDialog::getOpenFileName(0, QString(), QString(), "Excel(*.xlsx)");
	if (excelFileName.isEmpty())
	{
		QMessageBox::information(0, QStringLiteral("ȡ��ѡ��"), QStringLiteral("ȡ��EXCELѡ��"));
	}
	if (_mExcel != nullptr)
	{
		delete _mExcel;
		_mExcel = nullptr;
	}
	_mExcel = new QXlsx::Document(excelFileName);
	if (_mExcel == nullptr)
	{
		QMessageBox::critical(0, QStringLiteral("������Ϣ"), QStringLiteral("EXCEL����ʧ"));
		return;
	}
}


/***************************************
*�������ܣ���ȡExcel��ֻ�ܶ�ȡ�ı���
*���룺
*	void
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-12-V2.0
***************************************/
void ExcelReader::readExcel()
{
	if (_mExcel == nullptr)
	{
		QMessageBox::warning(0, QStringLiteral("������Ϣ"), QStringLiteral("�����½����һ��EXCEL����"));
		return;
	}

	QXlsx::Workbook *workBook = _mExcel->workbook();
	QXlsx::Worksheet *workSheet = static_cast<QXlsx::Worksheet*>(workBook->sheet(0));//�򿪵�һ��sheet
	QXlsx::CellRange usedRange = _mExcel->dimension();//ʹ�÷�Χ
	QString value;
	for (int i = 1; i <= usedRange.rowCount(); i++)
	{
		for (int j = 1; j <= usedRange.columnCount(); j++)
		{
			QXlsx::Cell *cell = workSheet->cellAt(i, j);
			if (cell == NULL) continue;
			else
			{
				value = cell->value().toString();
				qDebug() << i << " " << j << " " << value;
			}
		}
	}
	qDebug() << QStringLiteral("��ȡ�ɹ�");
}


/***************************************
*�������ܣ�д�����ݵ�Excel������ֵ���򸲸�ԭ����ֵ��
*���룺
*	iRow:Ҫд�����
*	iColumn:Ҫд�����
*	content:Ҫд�������
*���ߣ�JZQ
*ʱ��汾��2019-07-03-V1.0
***************************************/
void ExcelReader::writeExcel(const int iRow, const int iColumn, const QString content)
{
	if (_mExcel == nullptr)
	{
		QMessageBox::warning(0, QStringLiteral("������Ϣ"), QStringLiteral("�����½����һ��EXCEL����"));
		return;
	}
	if (iRow <= 0 || iColumn <= 0)
	{
		QMessageBox::warning(0, QStringLiteral("������Ϣ"), QStringLiteral("д����л�������С�ڵ���0��"));
		return;
	}
	if (!_mExcel->write(iRow, iColumn, content))
	{
		QMessageBox::warning(0, QStringLiteral("������Ϣ"), QStringLiteral("д�����"));
		return;
	}
	_mExcel->save();
}


/***************************************
*�������ܣ��ϲ���Ԫ��(����ϲ���������ϲ�)
*���룺
*	ͨ����һ�У����һ�У���һ�У����һ���ĸ�������ȷ���ϲ�������
*	firstRow:��һ��
*	firstColumn:��һ��
*	lastRow:���һ��
*	lastColumn:���һ��
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-12-V2.0
***************************************/
void ExcelReader::mergeCells(const int firstRow, const int firstColumn, const int lastRow, const int lastColumn)
{
	if (_mExcel == nullptr)
	{
		QMessageBox::warning(0, QStringLiteral("������Ϣ"), QStringLiteral("�����½����һ��EXCEL����"));
		return;
	}

	QXlsx::CellRange usedRange = _mExcel->dimension();//ʹ�÷�Χ
	if (usedRange.rowCount() != 0 || usedRange.columnCount() != 0)
	{
		QMessageBox::critical(0, QStringLiteral("������Ϣ"), QStringLiteral("EXCEL����Ϊ��"));
		return;
	}

	//���ø�ʽ�����뷽ʽ�������С����ɫ���Ӵ֡�б��ȡ���������
	QXlsx::Format format;
	format.setHorizontalAlignment(QXlsx::Format::AlignHCenter);//�������
	format.setVerticalAlignment(QXlsx::Format::AlignVCenter);//�������
	format.setFontColor(QColor(Qt::red));/*����Ϊ��ɫ*/
	format.setPatternBackgroundColor(QColor(152, 251, 152));/*������ɫ*/
	format.setFontSize(15);/*���������С*/
	format.setBorderStyle(QXlsx::Format::BorderDashDotDot);/*�߿���ʽ*/
	format.setFontBold(true);/*���üӴ�*/
	format.setFontUnderline(QXlsx::Format::FontUnderlineSingle);/*�»���(��������˫��������)*/

	// �����п�
	_mExcel->setColumnWidth(1, 20);
	_mExcel->setColumnWidth(2, 30);

	QXlsx::CellRange mergeRange(firstRow, firstColumn, lastRow, lastColumn);
	_mExcel->mergeCells(mergeRange, format);
	_mExcel->write(firstRow, firstColumn, "Hello Qt!");

	if (_mExcel->save())
	{
		qDebug() << QStringLiteral("�ϲ��ɹ�");
	}
}


/***************************************
*�������ܣ����ĳ������Ԫ��
*���룺
*	ͨ����һ�У����һ�У���һ�У����һ���ĸ�������ȷ����ֵ�����
*	firstRow:��һ��
*	firstColumn:��һ��
*	lastRow:���һ��
*	lastColumn:���һ��
*�����
*	void
*���ߣ�JZQ
*ʱ��汾��2019-06-12-V2.0
***************************************/
void ExcelReader::unmergeCells(const int firstRow, const int firstColumn, const int lastRow, const int lastColumn)
{
	if (_mExcel == nullptr)
	{
		QMessageBox::warning(0, QStringLiteral("������Ϣ"), QStringLiteral("�����½����һ��EXCEL����"));
		return;
	}

	QXlsx::CellRange mergeRange(firstRow, firstColumn, lastRow, lastColumn);

	if (_mExcel->unmergeCells(mergeRange))
	{//ȡ���ϲ������һ����Ԫ���ڣ�
		qDebug() << QStringLiteral("ȡ���ϲ��ɹ�");
	}
	else
	{
		qDebug() << QStringLiteral("ȡ���ϲ����ɹ�");
	}
}