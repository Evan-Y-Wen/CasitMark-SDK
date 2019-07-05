#pragma once

#include "cm3formresult_global.h"
#include "mformresult.h"
#include "mformimagefile.h"
#include <QString>
#include <QList>



namespace Cm3
{
	namespace FormResult
	{
		class CM3FORMRESULT_EXPORT MResult
		{
		public:
			MResult();
			~MResult();

			// ��ʼ��
			bool Initialize();

			// �ͷ��ڴ�
			void Release();

		private:
			// �Ƿ��ʼ��
			bool _isInitialized;

			// ��Ч�������
			int _validFormCount;

			// �����
			QList<MFormResult *> * _formReuslts;// �������ɨ�������ͼƬ��Ӧ��Ϳ��Ľ����

			// ����Ӧ��ͼ����Ϣ
			QList<MFormImageFile *> * _formImageFiles;// todo:�Ҿ��ý�������Է���ÿһ�������MFormResult�������
			
		};
	}
}
