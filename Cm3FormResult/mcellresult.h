#pragma once

namespace Cm3
{
	namespace FormResult
	{
		enum MarkSymbolResult
		{
			TICK = 1, // ��
			FORK = 2, // ��
			RING = 3, // ��
			TRIANGULAR = 4, // ��
			UNKNOWN = 5, // δ֪����
			UNMARK = 0 // û����Ϳ
		};

		class MCellResult
		{
			// ���һ�������е�һ����Ԫ������
		public:
			MCellResult();
			~MCellResult();

		private:
			// ��Ԫ������
			int _cellIndex;

			// ������
			int _rowIndex;

			// ������
			int _colIndex;
			 
			// ��Ϳ��Ϣ
			MarkSymbolResult _mMarkSymbolResult;

		};
	}
}
