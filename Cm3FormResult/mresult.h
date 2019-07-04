#pragma once

#include "cm3formresult_global.h"
#include "mformresult.h"
#include <QString>
#include <QList>



namespace Cm3
{
	namespace FormResult
	{
		class CM3FORMRESULT_EXPORT MResult
		{
		public:
			MResult();
			~MResult();

			bool Initialize();

			//新建模式
			void CreatePattern();

			//添加模板
			void AddPattern();

			void Release();

		private:
			bool _isInitialized;

			// 表格结果
			QList<MFormResult *> * _formReuslts;// 存放所有扫描出来的图片对应填涂快的结果。

		};
	}
}
