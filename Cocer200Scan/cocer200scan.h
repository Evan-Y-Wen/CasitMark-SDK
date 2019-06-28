#pragma once

#include <QObject>

#include "cocer200scan_global.h"

namespace cs200
{
    enum eDeviceInfo
    {
        eStandby,
        ePaperOn,
        eScanning,
        eError_UpcoverOpen,
        eError_PaperIn,
        eError_Lift,
        eError_Jam,
        eError_Double
    };

    class DeviceConfig;
    class UsbImp;
    class DeviceStateQuery;
    class ImgProcess;
    class COCER200SCAN_EXPORT Cocer200Scan : public QObject
    {
        Q_OBJECT

    signals:
        // 扫描状态变化
        void InfoChanged(eDeviceInfo info);

        // 扫描得到图像，需在槽函数内释放内存空间 
        void ImageGenerated(uchar *fImgBuf, int fBufLen, uchar *bImgBuf, int bBufLen);

    public:
        Cocer200Scan();
        ~Cocer200Scan();

        bool Initialize();

        bool OpenDevice();

        bool StartScan(ushort limitPageCount = 0);

        void AbortScan();

        void CloseDevice();

        void Release();

        DeviceConfig* GetDevCfg() const;

    private:

        bool _isInitialized;
        bool _isOpened;
        DeviceConfig *_devCfg;
        UsbImp *_usbImp;
        DeviceStateQuery *_devStateQuery;
        ImgProcess *_imgProcess;
    };
};
