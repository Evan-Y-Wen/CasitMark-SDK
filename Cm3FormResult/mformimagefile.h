#pragma once

#include <QString>

namespace Cm3
{
	namespace FormResult
	{
		class MFormImageFile
		{
		public:
			MFormImageFile();
			~MFormImageFile();

		private:
			// ���ͼ��������
			QString _formImageName;

			// ���ͼ�����ڽ���ļ���λ��
			int _positionFolder;

			// ���ͼ�񳤶�
			int Length;

		};
	}
}
