#pragma once

//using namespace System;
//using namespace System::Collections::Generic;
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace Cm2
{
	namespace FormPattern {
		// ��Ϳ��������ʾ��ʽ
		enum MResultMode
		{
			Binary,
			SingleSelect
		};
		// ��Ϳ����
		//[Serializable] 
		class MMarkGroup
		{
		public:
			MMarkGroup(string &groupName);
			~MMarkGroup();

			// ����
			string GroupName;
			// �����ʾ��ʽ
			MResultMode ResultMode;//enum MResultMode
			// ������Ϳ������
			vector<int> *BlockIndexs;
		};
	};
};

