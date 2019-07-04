#pragma once

namespace Cm3
{
	namespace FormPattern
	{
		class MCell
		{
		public:
			MCell();
			~MCell();

		private:
			int _cellIndex;
			int _rowIndex;
			int _colIndex;
		};
	}
}

