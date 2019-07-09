#pragma once

namespace Cm3
{
	namespace FormResult
	{
		enum MarkSymbolResult
		{
			TICK = 1, // √
			FORK = 2, // ×
			RING = 3, // ○
			TRIANGULAR = 4, // △
			UNKNOWN = 5, // 未知符号
			UNMARK = 0 // 没有填涂
		};

		class MCellResult
		{
			// 存放一个分组中的一个单元格结果。
		public:
			MCellResult();
			~MCellResult();

		private:
			// 单元格索引
			int _cellIndex;

			// 行索引
			int _rowIndex;

			// 列索引
			int _colIndex;
			 
			// 填涂信息
			MarkSymbolResult _mMarkSymbolResult;

		};
	}
}
