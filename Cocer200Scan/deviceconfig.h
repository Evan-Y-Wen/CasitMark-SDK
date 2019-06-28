#pragma once

#include "cocer200scan_global.h"

#include <QDataStream>
#include <QString>

namespace cs200
{
    class COCER200SCAN_EXPORT DeviceConfig
    {
    public:
        DeviceConfig();
        ~DeviceConfig();

        // 保存到文件
        void SaveToFile(QString filePath);

        // 从文件读取
        void ReadFromFile(QString filePath);

        friend QDataStream &operator << (QDataStream &output, const DeviceConfig *dev);//QDataStream处理二进制文件

        friend QDataStream &operator >> (QDataStream &input, DeviceConfig *dev);

        uint16_t USB_VID;
        uint16_t USB_PID;

        uchar BulkOut_CmdSend;
        uchar BulkIn_CmdFeedback;
        uchar BulkIn_DeviceState;
        uchar BulkIn_ImageData;
        uchar InterruptIn_KeyState;

        int Cmd_SendTimeOut;
        uchar Cmd_QueryState[3];
        int Cmd_QueryStateLen;
        int State_QueryInterval;
        uchar Cmd_StartScan[5];
        int Cmd_StartScanLen;
        uchar Cmd_AbortScan[4];
        int Cmd_AbortScanLen;
        uchar Cmd_SetDPI[14];
        int Cmd_SetDPILen;
        uchar Cmd_SetImageType[7];
        int Cmd_SetImageTypeLen;
        uchar Cmd_SetDoubleCheck[7];
        int Cmd_SetDoubleCheckLen;

        int Cmd_FeedbackTimeOut;

        int Image_DataTransferTimeOut;
        int Image_DataReadBufLen;

        int Image_ProcessInterval;

        float Dev_ImageDataPixelPerInch;
        ushort Dev_DPI;
        uchar Dev_ImageType;
        uchar Dev_LightColor;
        bool Dev_DoublePaperCheck;
    };
};
