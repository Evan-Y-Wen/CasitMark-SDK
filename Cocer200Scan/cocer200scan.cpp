#include "cocer200scan.h"
#include "deviceconfig.h"
#include "libusbimp.h"
#include "devicestatequery.h"
#include "imgprocess.h"

#include <QMetaType>
#include <QDebug>

cs200::Cocer200Scan::Cocer200Scan() :
    _isInitialized(false),
    _isOpened(false),
    _devCfg(NULL),
    _usbImp(NULL),
    _devStateQuery(NULL),
    _imgProcess(NULL)
{
    qRegisterMetaType<cs200::eDeviceInfo>("eDeviceInfo");//自定义的类型如果想使用signal/slot来传送，需要注册
    _devCfg = new cs200::DeviceConfig();
}

cs200::Cocer200Scan::~Cocer200Scan()
{
	if (_devCfg != nullptr)
	{
		delete  _devCfg;
	}
	_devCfg = nullptr;
}

bool cs200::Cocer200Scan::Initialize()
{
    // 初始化libusb模块
    int r = libusb_init(NULL);
    if (r < 0)
        return false;
    libusb_set_debug(NULL, LIBUSB_LOG_LEVEL_WARNING);
    _usbImp = new cs200::UsbImp();
    _imgProcess = new cs200::ImgProcess(this, _devCfg);
    _devStateQuery = new cs200::DeviceStateQuery(this, _usbImp, _imgProcess, _devCfg);
    _isInitialized = true;
    return true;
}

bool cs200::Cocer200Scan::OpenDevice()
{
    libusb_device **devs;
    ssize_t cnt = libusb_get_device_list(NULL, &devs);
    if (cnt < 0)
    {
        qDebug() << "libusb_get_device_list count = " << libusb_error_name(cnt);
        return false;
    }

    // 查找Cocer200设备
    int i = 0, r = 0;
    libusb_device *dev = NULL;
    while ((dev = devs[i++]) != NULL)
    {
        struct libusb_device_descriptor desc;
        r = libusb_get_device_descriptor(dev, &desc);
        if (r < 0)
        {
            qDebug() << "libusb_get_device_descriptor error: " << libusb_error_name(r);
            continue;
        }

        if (desc.idVendor == _devCfg->USB_VID && desc.idProduct == _devCfg->USB_PID)
            break;
    }
    if (dev == NULL)
    {
        libusb_free_device_list(devs, 1);
        return false;
    }

    r = libusb_open(dev, &_usbImp->Dev_handle);
    if (r < 0)
    {
        qDebug() << "libusb_open error: " << libusb_error_name(r);
        _usbImp->Dev_handle = NULL;
        libusb_free_device_list(devs, 1);
        return false;
    }

    if (libusb_kernel_driver_active(_usbImp->Dev_handle, 0) == 1)
    {
        if (libusb_detach_kernel_driver(_usbImp->Dev_handle, 0) == 0)
        {
            
        }
    }

    r = libusb_claim_interface(_usbImp->Dev_handle, 0);
    if (r < 0)
    {
        qDebug() << "libusb_claim_interface error: " << libusb_error_name(r);
        libusb_close(_usbImp->Dev_handle);
        libusb_free_device_list(devs, 1);
        return false;
    }

    libusb_free_device_list(devs, 1);

    // 配置扫描参数
    int transferred = 0;
    libusb_bulk_transfer(_usbImp->Dev_handle,
        _devCfg->BulkOut_CmdSend,
        _devCfg->Cmd_SetDPI,
        _devCfg->Cmd_SetDPILen,
        &transferred,
        _devCfg->Cmd_SendTimeOut);

    libusb_bulk_transfer(_usbImp->Dev_handle,
        _devCfg->BulkOut_CmdSend,
        _devCfg->Cmd_SetImageType,
        _devCfg->Cmd_SetImageTypeLen,
        &transferred,
        _devCfg->Cmd_SendTimeOut);

    libusb_bulk_transfer(_usbImp->Dev_handle,
        _devCfg->BulkOut_CmdSend,
        _devCfg->Cmd_SetDoubleCheck,
        _devCfg->Cmd_SetDoubleCheckLen,
        &transferred,
        _devCfg->Cmd_SendTimeOut);

    // 启动状态查询线程
    _devStateQuery->startThread();
    // 启动图像处理线程
    _imgProcess->startThread();
    
    _isOpened = true;
    return true;
}

bool cs200::Cocer200Scan::StartScan(ushort limitPageCount)
{
    if (_devStateQuery->CurrentInfo != ePaperOn)
        return false;
    int transferred = 0, r = 0;
    if (limitPageCount > 0)
    {
        _devCfg->Cmd_StartScan[2] = limitPageCount % 256;
        _devCfg->Cmd_StartScan[3] = limitPageCount / 256;
    }
    else
    {
        _devCfg->Cmd_StartScan[2] = 0;
        _devCfg->Cmd_StartScan[3] = 0;
    }
    r = libusb_bulk_transfer(_usbImp->Dev_handle, 
        _devCfg->BulkOut_CmdSend, 
        _devCfg->Cmd_StartScan,
        _devCfg->Cmd_StartScanLen, 
        &transferred, 
        _devCfg->Cmd_SendTimeOut);
    if (r != 0 || transferred != _devCfg->Cmd_StartScanLen)
    {
        if(r != 0)
            qDebug() << "libusb_claim_interface error: " << libusb_error_name(r);
        return false;
    }
    return true;
}

void cs200::Cocer200Scan::AbortScan()
{
    int transferred = 0;
    int r = libusb_bulk_transfer(_usbImp->Dev_handle, 
        _devCfg->BulkOut_CmdSend, 
        _devCfg->Cmd_AbortScan, 
        _devCfg->Cmd_AbortScanLen, 
        &transferred, 
        _devCfg->Cmd_SendTimeOut);
    if (r != 0)
        qDebug() << "libusb_claim_interface error: " << libusb_error_name(r);
}

void cs200::Cocer200Scan::CloseDevice()
{
    _devStateQuery->stopThread();
    _imgProcess->stopThread();

    libusb_release_interface(_usbImp->Dev_handle, 0);
    libusb_close(_usbImp->Dev_handle);

    _isOpened = false;
}

void cs200::Cocer200Scan::Release()
{
    if (_isOpened)
        CloseDevice();
    if (_isInitialized)
    {
        libusb_exit(NULL);
        delete _devStateQuery;
        delete _imgProcess;
        delete _usbImp;
    }
}

cs200::DeviceConfig * cs200::Cocer200Scan::GetDevCfg() const
{
    return _devCfg;
}
