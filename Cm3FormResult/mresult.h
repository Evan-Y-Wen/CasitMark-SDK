#pragma once

#include "cm3formresult_global.h"
#include "mformresult.h"
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

			bool Initialize();

			//�½�ģʽ
			void CreatePattern();

			//���ģ��
			void AddPattern();

			void Release();

		private:
			bool _isInitialized;

			// �����
			QList<MFormResult *> * _formReuslts;// �������ɨ�������ͼƬ��Ӧ��Ϳ��Ľ����

		};
	}
}
