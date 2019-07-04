#pragma once

namespace Cm3
{
	namespace FormResult
	{
		class MCellResult
		{
		public:
			MCellResult();
			~MCellResult();

		private:
			int _cellIndex;
			int _rowIndex;
			int _colIndex;
		};
	}
}
