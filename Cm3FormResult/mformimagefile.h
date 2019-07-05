#pragma once

#include <QString>

namespace Cm3
{
	namespace FormResult
	{
		class MFormImageFile
		{
		public:
			MFormImageFile();
			~MFormImageFile();

		private:
			// 表格图像索引名
			QString _formImageName;

			// 表格图像所在结果文件的位置
			int _positionFolder;

			// 表格图像长度
			int Length;

		};
	}
}
