#pragma once

#include <QString>
#include <QList>
#include "cm3formpattern_global.h"
#include "MFormPattern.h"


namespace Cm3
{
	namespace FormPattern
	{
		class CM3FORMPATTERN_EXPORT MPattern
		{
		public:
			MPattern();
			~MPattern();

			bool Initialize();

			//�½�ģʽ
			void CreatePattern();

			//���ģ��
			void AddPattern();

			void Release();

		private:
			bool _isInitialized;

			// ģʽ����
			QString _patternName;
			// ģʽΨһ��ţ�ȫ��Ψһ��
			QString _patternGUID;

			// ��ģʽ�µı�ģʽ
			QList<MFormPattern *> * _formPatterns;// �������ɨ�������ͼƬ��
		};
	}
}

