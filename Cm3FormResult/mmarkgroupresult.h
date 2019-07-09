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

			// 分组名称
			QString _groupName;

			// 分组结果类型
			GroupResultType _mGroupResultType;

			// 该组的文本结果，A、B、C。。。。。。
			QString _textResult;

			// 该组的二进制结果，由MarkSymbolResult获得。
			QString _binaryResrlt;
		};
	}
}
