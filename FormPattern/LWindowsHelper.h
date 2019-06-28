#pragma once

#include "opencv2/core/core.hpp"
#include <iostream>
#include <string>
using namespace std;

namespace Cm2
{
	namespace FormPattern{
		class LWindowsHelper
		{
		public:
			LWindowsHelper(void);
			~LWindowsHelper(void);

			static std::string GetCurrentEXEPath();

			// OTSU�����ֵ����ֵ
			//static int OSTUThreshold(cv::Mat iImage);
		};
	};
};

