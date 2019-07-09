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
			// 该表格对应的图像文件名
			QString _imageFileName;

			// 该表格对应的图像文件所在的位置
			int _positionFolder;

			// 该表格对应的图像文件是否为空白纸
			bool _isBlank;

			// 该表格对应的图像文件是否正向放置
			bool _isForwardDirection;

		};
	}
}
