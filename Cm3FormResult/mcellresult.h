#pragma once

namespace Cm3
{
	namespace FormResult
	{
		class MCellResult
		{
			// �������Ϳ�ĵ�Ԫ����Ϣ��
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
