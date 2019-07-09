#pragma once

#include <QString>

namespace Cm3
{
	namespace FormResult
	{
		enum GroupResultType
		{
			TEXT = 0,
			BINARY = 1
		};

		class MMarkGroupResult
		{
		public:
			MMarkGroupResult();
			~MMarkGroupResult();

		private:
			bool _isValid;

			// ��������
			QString _groupName;

			// ����������
			GroupResultType _mGroupResultType;

			// ������ı������A��B��C������������
			QString _textResult;

			// ����Ķ����ƽ������MarkSymbolResult��á�
			QString _binaryResrlt;
		};
	}
}
