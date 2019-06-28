#pragma once

#include <thread>

#include "cocer200scan.h"

namespace cs200
{
    class UsbImp;
    class DeviceConfig;
    class ImgProcess;
    class DeviceStateQuery
    {
    public:
        DeviceStateQuery(Cocer200Scan *cocer, UsbImp *usbImp, ImgProcess *imgProcess, DeviceConfig *devCfg);
        ~DeviceStateQuery();

        // 启动线程
        void startThread();

        // 停止线程
        void stopThread();

        // 当前设备状态
        eDeviceInfo CurrentInfo;

    private:

        void query();

        Cocer200Scan *_cocer;
        UsbImp *_usbImp;
        ImgProcess *_imgProcess;
        DeviceConfig *_devCfg;

        bool _runningFlag;
        std::thread *_queryThread;

        uchar _dev_State[12];
        int _dev_StateLen;
        uchar _state_PaperPassing;
        uchar _state_Scanning;
        uchar _state_CISAdjust;
        uchar _state_ErrorFlag;
        uchar _error_CoverClose;
        uchar _error_UpcoverOpen;
        uchar _error_Jam;
        uchar _error_PaperIn;
        uchar _error_Lift;
        uchar _error_Double;
        uchar _error_FPGA;
        uchar _image_BufferReady;
        uchar _sensor_PaperReady;
        uchar _sensor_PaperInTunnel;

        uchar *_imageDataReadBuf;
        int _imageDataReadLen;
        int _imageDataActualReadLen;
        uchar *_imageDataBuf;
        int _imageDataLen;
    };
};