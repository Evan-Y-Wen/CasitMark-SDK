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

			// OTSU计算二值化阈值
			//static int OSTUThreshold(cv::Mat iImage);
		};
	};
};

