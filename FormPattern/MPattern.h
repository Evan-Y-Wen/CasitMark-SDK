#pragma once

//using namespace System;
//using namespace System::Collections::Generic;
#include "MFormPattern.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace Cm2
{
	namespace FormPattern {
		// 定位方式
		//[Serializable]
		enum MLocateMode
		{
			// 图形匹配
			ShapeMatch,
			// 简单码，在"MBarcodePattern.h"里也有个SimpleCode，所以这里稍作改变
			SimpleCodeForLocateMode
		};

		//class MFormPattern;
		//class LPattern;
		//[Serializable]
		class MPattern
		{
		public:
			MPattern(void);
			~MPattern();//原文件为托管类，标准C++需要手动释放内存

			// 模式名称
			string PatternName;//String^ PatternName;原文件为引用类型，句柄。
			// 模式唯一编号
			string PatternGUID;
			// 定位方式
			MLocateMode LocateMode;//实例化，枚举enum MLocateMode
			// 图形匹配相似度，即匹配时大于该相似度认为匹配上
			double ShapeMatchThreshold;
			// 填涂块搜索时范围放大比例
			double MarkBlockStretch;
			// 该模式下的表单模式
			vector<MFormPattern*> *FormPatterns;//记得释放内存啊。。。

			// 解压模式数据
			//void DecompressionData();

			// 保存到文件
			//void SaveToFile(string &filePath);

			// 从文件中读取
			//static MPattern *LoadFromFile(string &filePath);

		};
	};
};
