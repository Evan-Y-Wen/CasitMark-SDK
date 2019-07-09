#pragma once

#include <QList>
#include <QString>
#include "mformimagefile.h"
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

			// �ý���Ƿ�Ϊ��������
			bool _isRectified;

			// ����Ӧ��ͼ����Ϣ
			MFormImageFile * _formImageFiles;// todo:�Ҿ��ý�������Է���ÿһ�������MFormResult�������

			// ʶ��ķ�����
			QList<MGroupResult *> * _markGroupResult;

			// ��ͼ������Ȳ�����
			// MGroupResult * _imageShotResult;

			// ��־������������ά��
			MIdentifierResult * _identifierResult;

		};
	}
}