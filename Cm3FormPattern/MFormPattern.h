#pragma once
#include <QString>
#include "MIdentifierPattern.h"
#include "MCell.h"
#include "MGroupPattern.h"

namespace Cm3
{
	namespace FormPattern
	{
		// 模板类型：图片或word
		enum MTemplateFileType
		{
			Image,
			WordFile
		};


		class MFormPattern// 每一张扫描出来的图片的信息
		{
		public:
			MFormPattern();
			~MFormPattern();

		private:
			// 表格名称
			QString _formName;

			// 模版文件类型：图片或word
			MTemplateFileType _templateFileType;

			// 模版图像二值化阈值
			int _templateImageBinirizeThreshold;

			// 若为图像数据，格式为2位深度tiff黑白图
			//array<Byte>* _patternImage;

			// 模式图像排版方向
			bool _isLandscape;

			// 表格上所有单元格信息：单元格索引、行索引、列索引
			QList<MCell> * _allCellsPattern;

			// 标志码信息：简单码或二维码
			MIdentifierPattern * _identifierPattern;

			// 需要识别的填涂块信息
			QList<MGroupPattern *> * _markGroupPattern;

			// 截图信息
			QList<MGroupPattern *> * _imageShotPattern;

			// 模式文件释放后得到临时数据
			// 识别时，tiff黑白图解压出图像数据
			//array<Byte>^ PatternImageData;
			// 模式图像宽
			int _patternImageWidth;
			// 模式图像高
			int _patternImageHeight;
		};
	}
}

