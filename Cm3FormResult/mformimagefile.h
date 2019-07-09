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
			// �ñ���Ӧ��ͼ���ļ���
			QString _imageFileName;

			// �ñ���Ӧ��ͼ���ļ����ڵ�λ��
			int _positionFolder;

			// �ñ���Ӧ��ͼ���ļ��Ƿ�Ϊ�հ�ֽ
			bool _isBlank;

			// �ñ���Ӧ��ͼ���ļ��Ƿ��������
			bool _isForwardDirection;

		};
	}
}
