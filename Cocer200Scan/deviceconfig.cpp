#include "deviceconfig.h"

#include <QFile>

cs200::DeviceConfig::DeviceConfig():
    USB_VID(0x154F),
    USB_PID(0x3204),
    BulkOut_CmdSend(0x01),
    BulkIn_CmdFeedback(0x82),
    BulkIn_DeviceState(0x83),
    BulkIn_ImageData(0x84),
    InterruptIn_KeyState(0x81),
    Cmd_SendTimeOut(2000),
    Cmd_QueryStateLen(3),
    State_QueryInterval(50),
    Cmd_StartScanLen(5),
    Cmd_AbortScanLen(4),
    Cmd_SetDPILen(14),
    Cmd_SetImageTypeLen(7),
    Cmd_SetDoubleCheckLen(7),
    Cmd_FeedbackTimeOut(2000),
    Image_DataTransferTimeOut(1000),
    Image_DataReadBufLen(10 * 1024 * 1024),
    Image_ProcessInterval(50),
    Dev_ImageDataPixelPerInch(8.64),
    Dev_DPI(200),
    Dev_ImageType(0),
    Dev_LightColor(7),
    Dev_DoublePaperCheck(true)
{
    Cmd_QueryState[0] = 0x1A;
    Cmd_QueryState[1] = 0x1B;
    Cmd_QueryState[2] = 0x43;

    Cmd_StartScan[0] = 0x1A;
    Cmd_StartScan[1] = 0x40;
    Cmd_StartScan[2] = 0;
    Cmd_StartScan[4] = 0;
    Cmd_StartScan[5] = 0;

    Cmd_AbortScan[0] = 0x1A;
    Cmd_AbortScan[1] = 0x1B;
    Cmd_AbortScan[2] = 0x41;
    Cmd_AbortScan[3] = 0x01;

    Cmd_SetDPI[0] = 0x1A;
    Cmd_SetDPI[1] = 0x52;
    Cmd_SetDPI[2] = Dev_DPI % 256;
    Cmd_SetDPI[3] = Dev_DPI / 256;
    Cmd_SetDPI[4] = Dev_DPI % 256;
    Cmd_SetDPI[5] = Dev_DPI / 256;
    Cmd_SetDPI[6] = 0x0;
    Cmd_SetDPI[7] = 0x0;
    Cmd_SetDPI[8] = 0x0;
    Cmd_SetDPI[9] = 0x0;
    Cmd_SetDPI[10] = 0x0;
    Cmd_SetDPI[11] = 0x0;
    Cmd_SetDPI[12] = 0x0;
    Cmd_SetDPI[13] = 0x0;

    Cmd_SetImageType[0] = 0x1A;
    Cmd_SetImageType[1] = 0x53;
    Cmd_SetImageType[2] = 0x01;
    Cmd_SetImageType[3] = Dev_ImageType;
    Cmd_SetImageType[4] = 0x08;
    Cmd_SetImageType[5] = Dev_LightColor;
    Cmd_SetImageType[6] = 0x1A;

    Cmd_SetDoubleCheck[0] = 0x1A;
    Cmd_SetDoubleCheck[1] = 0x5D;
    Cmd_SetDoubleCheck[2] = Dev_DoublePaperCheck;
    Cmd_SetDoubleCheck[3] = 0x0;
    Cmd_SetDoubleCheck[4] = 0x0;
    Cmd_SetDoubleCheck[5] = 0x0;
    Cmd_SetDoubleCheck[6] = 0x0;
}


cs200::DeviceConfig::~DeviceConfig()
{
}

void cs200::DeviceConfig::SaveToFile(QString filePath)
{
    // 应用配置
    Cmd_SetDPI[0] = 0x1A;
    Cmd_SetDPI[1] = 0x52;
    Cmd_SetDPI[2] = Dev_DPI % 256;
    Cmd_SetDPI[3] = Dev_DPI / 256;
    Cmd_SetDPI[4] = Dev_DPI % 256;
    Cmd_SetDPI[5] = Dev_DPI / 256;
    Cmd_SetDPI[6] = 0x0;
    Cmd_SetDPI[7] = 0x0;
    Cmd_SetDPI[8] = 0x0;
    Cmd_SetDPI[9] = 0x0;
    Cmd_SetDPI[10] = 0x0;
    Cmd_SetDPI[11] = 0x0;
    Cmd_SetDPI[12] = 0x0;
    Cmd_SetDPI[13] = 0x0;

    Cmd_SetImageType[0] = 0x1A;
    Cmd_SetImageType[1] = 0x53;
    Cmd_SetImageType[2] = 0x01;
    Cmd_SetImageType[3] = Dev_ImageType;
    Cmd_SetImageType[4] = 0x08;
    Cmd_SetImageType[5] = Dev_LightColor;
    Cmd_SetImageType[6] = 0x1A;

    Cmd_SetDoubleCheck[0] = 0x1A;
    Cmd_SetDoubleCheck[1] = 0x5D;
    Cmd_SetDoubleCheck[2] = Dev_DoublePaperCheck;
    Cmd_SetDoubleCheck[3] = 0x0;
    Cmd_SetDoubleCheck[4] = 0x0;
    Cmd_SetDoubleCheck[5] = 0x0;
    Cmd_SetDoubleCheck[6] = 0x0;

    QFile file(filePath);
    file.open(QIODevice::Truncate | QIODevice::WriteOnly);
    QDataStream ds(&file);
    ds << this;
    file.close();
}

void cs200::DeviceConfig::ReadFromFile(QString filePath)
{
    QFile file(filePath);
    if (file.exists())
    {
        file.open(QIODevice::ReadOnly);
        QDataStream ds(&file);
        ds >> this;
        file.close();
    }
}

QDataStream & cs200::operator<<(QDataStream & output, const DeviceConfig *dev)
{
    output << dev->USB_VID << dev->USB_PID << dev->BulkOut_CmdSend << dev->BulkIn_CmdFeedback << dev->BulkIn_DeviceState \
        << dev->BulkIn_ImageData << dev->InterruptIn_KeyState << dev->Cmd_SendTimeOut;
    output.writeRawData((const char*)dev->Cmd_QueryState, dev->Cmd_QueryStateLen); 
    output << dev->State_QueryInterval;
    output.writeRawData((const char*)dev->Cmd_StartScan, dev->Cmd_StartScanLen);
    output.writeRawData((const char*)dev->Cmd_AbortScan, dev->Cmd_AbortScanLen);
    output.writeRawData((const char*)dev->Cmd_SetDPI, dev->Cmd_SetDPILen);
    output.writeRawData((const char*)dev->Cmd_SetImageType, dev->Cmd_SetImageTypeLen);
    output.writeRawData((const char*)dev->Cmd_SetDoubleCheck, dev->Cmd_SetDoubleCheckLen);
    output  << dev->Cmd_FeedbackTimeOut << dev->Image_DataTransferTimeOut << dev->Image_DataReadBufLen << dev->Image_ProcessInterval \
        << dev->Dev_ImageDataPixelPerInch << dev->Dev_DPI << dev->Dev_ImageType << dev->Dev_LightColor << dev->Dev_DoublePaperCheck;
    return output;
}

QDataStream & cs200::operator>>(QDataStream & input, DeviceConfig *dev)
{
    input >> dev->USB_VID >> dev->USB_PID >> dev->BulkOut_CmdSend >> dev->BulkIn_CmdFeedback >> dev->BulkIn_DeviceState \
        >> dev->BulkIn_ImageData >> dev->InterruptIn_KeyState >> dev->Cmd_SendTimeOut;
    input.readRawData((char*)dev->Cmd_QueryState, dev->Cmd_QueryStateLen);
    input >> dev->State_QueryInterval;
    input.readRawData((char*)dev->Cmd_StartScan, dev->Cmd_StartScanLen);
    input.readRawData((char*)dev->Cmd_AbortScan, dev->Cmd_AbortScanLen);
    input.readRawData((char*)dev->Cmd_SetDPI, dev->Cmd_SetDPILen);
    input.readRawData((char*)dev->Cmd_SetImageType, dev->Cmd_SetImageTypeLen);
    input.readRawData((char*)dev->Cmd_SetDoubleCheck, dev->Cmd_SetDoubleCheckLen);
    input >> dev->Cmd_FeedbackTimeOut >> dev->Image_DataTransferTimeOut >> dev->Image_DataReadBufLen >> dev->Image_ProcessInterval \
        >> dev->Dev_ImageDataPixelPerInch >> dev->Dev_DPI >> dev->Dev_ImageType >> dev->Dev_LightColor >> dev->Dev_DoublePaperCheck;
    return input;
}
