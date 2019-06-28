#include "LWindowsHelper.h"
#include <Windows.h>
#include <tchar.h>
#include <iostream>
#include <string>
using namespace std;

Cm2::FormPattern::LWindowsHelper::LWindowsHelper(void)
{
	cout << "LWindowsHelper Ĭ�Ϲ��캯������" << endl;
}


Cm2::FormPattern::LWindowsHelper::~LWindowsHelper(void)
{
	//û�г�Ա����
}


std::string Cm2::FormPattern::LWindowsHelper::GetCurrentEXEPath()
{
	TCHAR _szPath[MAX_PATH + 1]={0};
	GetModuleFileName(NULL, _szPath, MAX_PATH);
	(_tcsrchr(_szPath, '\\'))[1] = 0;
	int nInputStrLen = wcslen (_szPath);
	int nOutputStrLen = WideCharToMultiByte (CP_ACP, 0, _szPath, nInputStrLen, NULL, 0, 0, 0) + 2; 
	LPSTR pszOut = new char [nOutputStrLen];  
	memset (pszOut, 0x00, nOutputStrLen);  
	WideCharToMultiByte(CP_ACP, 0, _szPath, nInputStrLen, pszOut, nOutputStrLen, 0, 0);  
	std::string strPath(pszOut);
	strPath = strPath.substr(0, strPath.length() - 1);
	return strPath;
}

/*
int Cm2::FormPattern::LWindowsHelper::OSTUThreshold( cv::Mat iImage )
{
	int n, n1, n2;
	int nThresholdValue = 1;            // ��ֵ
	int nImageHistogram[256];           // ֱ��ͼ
	double  Sum,Csum;                       // ������
	double  fmax = -1.0;                    
	double  m1, m2, sb;

	ZeroMemory(nImageHistogram, sizeof(int) * 256);
	// ����ֱ��ͼ
	for(int i = 0; i < iImage.rows; ++i)
	{
		for(int j = 0; j < iImage.cols; ++j)
		{
			nImageHistogram[iImage.at<byte>(i, j)]++;
		}
	}
	Sum = Csum = 0.0;
	n = 0;
	for (int i = 0; i < 256; ++i)
	{
		Sum += (double)i * (double)nImageHistogram[i]; // ������
		n += nImageHistogram[i]; // ����
	}
	n1 = 0;
	for (int i = 0; i < 256; ++i)
	{
		n1 += nImageHistogram[i];
		if(!n1)
			continue;
		n2 = n - n1;
		if(n2 == 0)
			break;
		Csum += (double)i * (double)nImageHistogram[i];
		m1 = Csum / n1;
		m2 = (Sum - Csum) / n2;
		sb = (double)n1 * (double)n2 * (m1 - m2) * (m1 - m2);
		if(sb > fmax)
		{
			fmax = sb;
			nThresholdValue = i;
		}
	}

	return nThresholdValue;
}
*/

