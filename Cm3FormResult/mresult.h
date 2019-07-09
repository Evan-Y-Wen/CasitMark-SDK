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

			// 初始化
			bool Initialize();

			// 释放内存
			void Release();

		private:
			// 是否初始化
			bool _isInitialized;

			// 有效表格数量
			int _validFormCount;

			// 表格结果
			QList<MFormResult *> * _formReuslts;// 存放所有扫描出来的图片对应填涂快的结果。
			
		};
	}
}
