#pragma once

#include <QString>
#include <QList>
#include "cm3formpattern_global.h"
#include "MFormPattern.h"


namespace Cm3
{
	namespace FormPattern
	{
		class CM3FORMPATTERN_EXPORT MPattern
		{
		public:
			MPattern();
			~MPattern();

			bool Initialize();

			//新建模式
			void CreatePattern();

			//添加模板
			void AddPattern();

			void Release();

		private:
			bool _isInitialized;

			// 模式名称
			QString _patternName;
			// 模式唯一编号，全球唯一码
			QString _patternGUID;

			// 该模式下的表单模式
			QList<MFormPattern *> * _formPatterns;// 存放所有扫描出来的图片。
		};
	}
}

