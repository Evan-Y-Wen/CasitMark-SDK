#pragma once

#include <QString>
#include "mgroupresult.h"
#include "midentifierresult.h"


namespace Cm3
{
	namespace FormResult
	{
		class MFormResult
		{
		public:
			MFormResult();
			~MFormResult();


		private:
			// �������
			QString _formName;

			// �����ģʽ�е�����
			int _formIndex;

			// ���ͼ���ļ���
			QString _formImageName;

			// todo:�����������Զ��Ǳ������Ӧͼ�����Ϣ���Ҿ��÷���MFormImageFile���и��á�

			// ���ͼ���Ƿ�Ϊ�հ�ֽ
			bool _isBlank;

			// ����Ƿ�����
			bool _isForwardDirection;

			// �ý���Ƿ�Ϊ��������
			bool _isRectified;

			// ʶ�����Ϳ����
			MGroupResult * _markGroupResult;

			// ��ͼ���
			MGroupResult * _imageShotResult;

			// ��־������������ά��
			MIdentifierResult * _identifierResult;

		};
	}
}