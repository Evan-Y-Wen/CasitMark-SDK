#pragma once

namespace Cm3
{
	namespace FormResult
	{
		class MCellResult
		{
			// 存放已填涂的单元格信息。
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
