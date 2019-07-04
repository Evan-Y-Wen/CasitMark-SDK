#pragma once
#include <QString>

namespace Cm3
{
	namespace FormPattern
	{
		class MRegion
		{
		public:
			MRegion();
			~MRegion();

			MRegion(double x, double y, double w, double h);

			MRegion * DeepClone();

		private:
			// ��������
			QString _name;
			// ������������X
			double _x;
			// ������������Y
			double _y;
			// ������
			double _width;
			// ����߶�
			double _height;
			// ���򱳾�ɫ
			QString _backgroundColor;
			// ����߿���ɫ
			QString _borderColor;
		};
	}
}

