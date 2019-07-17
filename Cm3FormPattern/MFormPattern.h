#pragma once
#include <QString>
#include "MIdentifierPattern.h"
#include "MCell.h"
#include "MGroupPattern.h"

namespace Cm3
{
	namespace FormPattern
	{
		// ģ�����ͣ�ͼƬ��word
		enum MTemplateFileType
		{
			Image,
			WordFile
		};


		class MFormPattern// ÿһ��ɨ�������ͼƬ����Ϣ
		{
		public:
			MFormPattern();
			~MFormPattern();

		private:
			// �������
			QString _formName;

			// ģ���ļ����ͣ�ͼƬ��word
			MTemplateFileType _templateFileType;

			// ģ��ͼ���ֵ����ֵ
			int _templateImageBinirizeThreshold;

			// ��Ϊͼ�����ݣ���ʽΪ2λ���tiff�ڰ�ͼ
			//array<Byte>* _patternImage;

			// ģʽͼ���Ű淽��
			bool _isLandscape;

			// ��������е�Ԫ����Ϣ����Ԫ����������������������
			QList<MCell> * _allCellsPattern;

			// ��־����Ϣ��������ά��
			MIdentifierPattern * _identifierPattern;

			// ��Ҫʶ�����Ϳ����Ϣ
			QList<MGroupPattern *> * _markGroupPattern;

			// ��ͼ��Ϣ
			QList<MGroupPattern *> * _imageShotPattern;

			// ģʽ�ļ��ͷź�õ���ʱ����
			// ʶ��ʱ��tiff�ڰ�ͼ��ѹ��ͼ������
			//array<Byte>^ PatternImageData;
			// ģʽͼ���
			int _patternImageWidth;
			// ģʽͼ���
			int _patternImageHeight;
		};
	}
}

