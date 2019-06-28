#pragma once
#include <QEvent>

enum DeviceState
{
	/// <summary>
	/// 无状态，初始化使用
	/// </summary>
	Null,
	/// <summary>
	/// 扫描仪断开连接
	/// </summary>
	Disconnected,
	/// <summary>
	/// 扫描仪待机中
	/// </summary>
	Standby,
	/// <summary>
	/// 扫描仪监测到纸张
	/// </summary>
	PaperOn,
	/// <summary>
	/// 扫描仪正在扫描
	/// </summary>
	Scanning,
	/// <summary>
	/// 启动扫描时缺纸
	/// </summary>
	LackPaper,
	/// <summary>
	/// 出现塞纸
	/// </summary>
	PaperError,
	/// <summary>
	/// 上盖打开
	/// </summary>
	ConverError,
	/// <summary>
	/// 双张进入
	/// </summary>
	DoublePaper,
	/// <summary>
	/// 其他错误
	/// </summary>
	OtherError,
};

class ScannerStateEventArgs
{
public:
	ScannerStateEventArgs(DeviceState last, DeviceState changeTo)
	{
		LastState = last;
		CurrentState = changeTo;
	}

	/// <summary>
	/// 改变前的状态
	/// </summary>
	DeviceState LastState;
	/// <summary>
	/// 改变后的状态
	/// </summary>
	DeviceState CurrentState;
};

class HighSpeedScanner
{
public:
	HighSpeedScanner();
	virtual ~HighSpeedScanner();
};

