#pragma once
#include <QEvent>

enum DeviceState
{
	/// <summary>
	/// ��״̬����ʼ��ʹ��
	/// </summary>
	Null,
	/// <summary>
	/// ɨ���ǶϿ�����
	/// </summary>
	Disconnected,
	/// <summary>
	/// ɨ���Ǵ�����
	/// </summary>
	Standby,
	/// <summary>
	/// ɨ���Ǽ�⵽ֽ��
	/// </summary>
	PaperOn,
	/// <summary>
	/// ɨ��������ɨ��
	/// </summary>
	Scanning,
	/// <summary>
	/// ����ɨ��ʱȱֽ
	/// </summary>
	LackPaper,
	/// <summary>
	/// ������ֽ
	/// </summary>
	PaperError,
	/// <summary>
	/// �ϸǴ�
	/// </summary>
	ConverError,
	/// <summary>
	/// ˫�Ž���
	/// </summary>
	DoublePaper,
	/// <summary>
	/// ��������
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
	/// �ı�ǰ��״̬
	/// </summary>
	DeviceState LastState;
	/// <summary>
	/// �ı���״̬
	/// </summary>
	DeviceState CurrentState;
};

class HighSpeedScanner
{
public:
	HighSpeedScanner();
	virtual ~HighSpeedScanner();
};

