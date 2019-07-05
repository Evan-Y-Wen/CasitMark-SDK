#pragma once

#include <QString>

namespace Cm3
{
	namespace FormResult
	{
		class MRegionResult
		{
		public:
			MRegionResult();
			~MRegionResult();

			MRegionResult(double x, double y, double w, double h);

			MRegionResult * DeepClone();

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
