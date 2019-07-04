#pragma once

#include <QString>
#include "mgroupresult.h"


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
			// �����ģʽ�е�����
			int _formIndex;

			// ���ͼ���ļ���
			QString _formImageName;

			// ���ͼ���Ƿ�Ϊ�հ�ֽ
			bool _isBlank;

			// ����Ƿ�����
			bool _isForwardDirection;

			// �ý���Ƿ�Ϊ��������
			bool _isRectified;

			// ��Ϳ����
			MGroupResult * _markGroupResult;

		};
	}
}