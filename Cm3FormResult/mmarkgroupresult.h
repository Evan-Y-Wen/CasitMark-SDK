#pragma once

#include <QString>

namespace Cm3
{
	namespace FormResult
	{
		class MMarkGroupResult
		{
		public:
			MMarkGroupResult();
			~MMarkGroupResult();

		private:
			bool _isValid;

			// ����ı�
			QString _resultText;
		};
	}
}
