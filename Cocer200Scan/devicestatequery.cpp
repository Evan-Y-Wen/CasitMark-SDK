#include "devicestatequery.h"
#include "deviceconfig.h"
#include "libusbimp.h"
#include "dibfile.h"
#include "imgprocess.h"

#include <vector>
#include <cstring>
#include <chrono>

#include <QDebug>

cs200::DeviceStateQuery::DeviceStateQuery(cs200::Cocer200Scan *cocer, cs200::UsbImp *usbImp, cs200::ImgProcess *imgProcess,
    cs200::DeviceConfig *devCfg) :
    CurrentInfo(eStandby),
    _cocer(cocer),
    _usbImp(usbImp),
    _imgProcess(imgProcess),
    _devCfg(devCfg), 
    _runningFlag(true),
    _queryThread(NULL),
    _dev_StateLen(12),
    _state_PaperPassing(0x04),
    _state_Scanning(0x20),
    _state_CISAdjust(0x40),
    _state_ErrorFlag(0x80),
    _error_CoverClose(0x01),
    _error_UpcoverOpen(0x02),
    _error_Jam(0x04),
    _error_PaperIn(0x08),
    _error_Lift(0x20),
    _error_Double(0x40),
    _error_FPGA(0x80),
    _image_BufferReady(0x02),
    _sensor_PaperReady(0x02),
    _sensor_PaperInTunnel(0x08),
    _imageDataActualReadLen(0),
    _imageDataLen(0)
    
{
    memset(_dev_State, 0, _dev_StateLen);
}

cs200::DeviceStateQuery::~DeviceStateQuery()
{
}

void cs200::DeviceStateQuery::query()
{
    int transferred = 0, r = 0;
    uchar state = 0;
    uchar error = 0;
    uchar image = 0;
    uchar sensor = 0;

    int imgChannel = 1;
    if (_devCfg->Dev_ImageType == 1)
        imgChannel = 3;
    
    uchar* bmpFront = NULL;
    int frontBmpLen = 0;
    uchar* bmpBack = NULL;
    int backBmpLen = 0;
    while (_runningFlag)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(_devCfg->State_QueryInterval));
        transferred = r = 0;
        r = libusb_bulk_transfer(_usbImp->Dev_handle, _devCfg->BulkOut_CmdSend, _devCfg->Cmd_QueryState, _devCfg->Cmd_QueryStateLen, &transferred, _devCfg->Cmd_SendTimeOut);
        if (r != 0 || transferred != _devCfg->Cmd_QueryStateLen)
            continue;
        transferred = 0;
        r = libusb_bulk_transfer(_usbImp->Dev_handle, _devCfg->BulkIn_DeviceState, _dev_State, 12, &transferred, _devCfg->Cmd_FeedbackTimeOut);
        if (r != 0 || transferred != _dev_StateLen)
            continue;
        state = _dev_State[0];
        error = _dev_State[1];
        image = _dev_State[2];
        sensor = _dev_State[3];

        // 优先处理错误，再处理传感器状态
        if (error & _error_UpcoverOpen)
        {
            if (CurrentInfo != eError_UpcoverOpen)
            {
                emit _cocer->InfoChanged(eError_UpcoverOpen);
                CurrentInfo = eError_UpcoverOpen;
                qDebug() << "state=0x" << QString::number(state, 16)
                    << "error=0x" << QString::number(error, 16)
                    << "image=0x" << QString::number(image, 16)
                    << "sensor=0x" << QString::number(sensor, 16);
                qDebug() << "eError_UpcoverOpen";
            }
        }
        else if (error & _error_PaperIn)
        {
            if (CurrentInfo != eError_PaperIn)
            {
                emit _cocer->InfoChanged(eError_PaperIn);
                CurrentInfo = eError_PaperIn;
                qDebug() << "state=0x" << QString::number(state, 16)
                    << "error=0x" << QString::number(error, 16)
                    << "image=0x" << QString::number(image, 16)
                    << "sensor=0x" << QString::number(sensor, 16);
                qDebug() << "eError_PaperIn";
            }
        }
        else if (error & _error_Lift)
        {
            if (CurrentInfo != eError_Lift)
            {
                emit _cocer->InfoChanged(eError_Lift);
                CurrentInfo = eError_Lift;
                qDebug() << "state=0x" << QString::number(state, 16)
                    << "error=0x" << QString::number(error, 16)
                    << "image=0x" << QString::number(image, 16)
                    << "sensor=0x" << QString::number(sensor, 16);
                qDebug() << "eError_Lift";
            }
        }
        else if (error & _error_Jam)
        {
            if (CurrentInfo != eError_Jam)
            {
                emit _cocer->InfoChanged(eError_Jam);
                CurrentInfo = eError_Jam;
                qDebug() << "state=0x" << QString::number(state, 16)
                    << "error=0x" << QString::number(error, 16)
                    << "image=0x" << QString::number(image, 16)
                    << "sensor=0x" << QString::number(sensor, 16);
                qDebug() << "eError_Double";
            }
        }
        else if (error & _error_Double)
        {
            if (CurrentInfo != eError_Double)
            {
                emit _cocer->InfoChanged(eError_Double);
                CurrentInfo = eError_Double;
                qDebug() << "state=0x" << QString::number(state, 16)
                    << "error=0x" << QString::number(error, 16)
                    << "image=0x" << QString::number(image, 16)
                    << "sensor=0x" << QString::number(sensor, 16);
                qDebug() << "eError_Double";
            }
        }
        else if ((state & _state_PaperPassing) == 0 && (sensor & _sensor_PaperReady) != 0)
        {
            // 非走纸状态下若托盘传感器检测到有纸，则认为是准备状态
            if (CurrentInfo != ePaperOn)
            {
                emit _cocer->InfoChanged(ePaperOn);
                CurrentInfo = ePaperOn;
                qDebug() << "state=0x" << QString::number(state, 16)
                    << "error=0x" << QString::number(error, 16)
                    << "image=0x" << QString::number(image, 16)
                    << "sensor=0x" << QString::number(sensor, 16);
                qDebug() << "ePaperOn";
            }
        }
        else if (state & _state_PaperPassing)
        {
            // 走纸状态下认为是扫描中
            if (CurrentInfo != eScanning)
            {
                emit _cocer->InfoChanged(eScanning);
                CurrentInfo = eScanning;
                qDebug() << "state=0x" << QString::number(state, 16)
                    << "error=0x" << QString::number(error, 16)
                    << "image=0x" << QString::number(image, 16)
                    << "sensor=0x" << QString::number(sensor, 16);
                qDebug() << "eScanning";
            }
        }
        else
        {
            if (CurrentInfo != eStandby)
            {
                emit _cocer->InfoChanged(eStandby);
                CurrentInfo = eStandby;
                qDebug() << "state=0x" << QString::number(state, 16)
                    << "error=0x" << QString::number(error, 16)
                    << "image=0x" << QString::number(image, 16)
                    << "sensor=0x" << QString::number(sensor, 16);
                qDebug() << "eStandby";
            }
        }

        // 检查是否有图像可取
        if (image & _image_BufferReady)
        {
            // 读取图像数据
            int r = 0;
            _imageDataLen = 0;
            do
            {
                _imageDataActualReadLen = 0;
                r = libusb_bulk_transfer(_usbImp->Dev_handle,
                    _devCfg->BulkIn_ImageData,
                    _imageDataReadBuf,
                    _devCfg->Image_DataReadBufLen,
                    &_imageDataActualReadLen,
                    _devCfg->Image_DataTransferTimeOut);
                if (r == 0)
                {
                    if (_imageDataActualReadLen > 0)
                    {
                        memcpy(_imageDataBuf + _imageDataLen, _imageDataReadBuf, _imageDataActualReadLen);
                        _imageDataLen += _imageDataActualReadLen;
                    }
                    qDebug() << "read image data len =" << _imageDataActualReadLen;
                }
                else
                {
                    qDebug() << "libusb_bulk_transfer error: " << libusb_error_name(r);
                }
            } while (r == 0 && _imageDataActualReadLen == _imageDataReadLen);
            if (_imageDataLen > 0)
            {
                qDebug() << "image data total len =" << _imageDataLen;

                uchar* imgData = new uchar[_imageDataLen];
                memcpy(imgData, _imageDataBuf, _imageDataLen);
                _imgProcess->dataEnqueue(imgData, _imageDataLen, _devCfg->Dev_DPI, imgChannel);
            }
        }
    }
}

void cs200::DeviceStateQuery::startThread()
{
    // 若扫描仪中数据则先取出
    int transferred = 0;
    int r = libusb_bulk_transfer(_usbImp->Dev_handle, _devCfg->BulkOut_CmdSend, _devCfg->Cmd_QueryState, _devCfg->Cmd_QueryStateLen, &transferred, _devCfg->Cmd_SendTimeOut);
    if (r == 0 && transferred == _devCfg->Cmd_QueryStateLen)
    {
        transferred = 0;
        r = libusb_bulk_transfer(_usbImp->Dev_handle, _devCfg->BulkIn_DeviceState, _dev_State, 12, &transferred, _devCfg->Cmd_FeedbackTimeOut);
        if (r == 0 && transferred == _dev_StateLen)
        {
            uchar image = _dev_State[2];
            if (image & _image_BufferReady)
            {
                // 读取图像数据
                r = 0;
                _imageDataLen = 0;
                do
                {
                    _imageDataActualReadLen = 0;
                    r = libusb_bulk_transfer(_usbImp->Dev_handle,
                        _devCfg->BulkIn_ImageData,
                        _imageDataReadBuf,
                        _devCfg->Image_DataReadBufLen,
                        &_imageDataActualReadLen,
                        _devCfg->Image_DataTransferTimeOut);
                    if (r == 0)
                    {
                        if (_imageDataActualReadLen > 0)
                        {
                            memcpy(_imageDataBuf + _imageDataLen, _imageDataReadBuf, _imageDataActualReadLen);
                            _imageDataLen += _imageDataActualReadLen;
                        }
                    }
                } while (r == 0 && _imageDataActualReadLen == _imageDataReadLen);
                if (_imageDataLen > 0)
                {
                    qDebug() << "Reserved image data len =" << _imageDataLen;
                }
            }
        }
    }

    CurrentInfo = eStandby;
    _imageDataReadLen = 10 * 1024 * 1024;
    _imageDataReadBuf = new uchar[_imageDataReadLen];
    // A4尺寸纸张以600DPI扫描彩色图像时，yuv442图像数据约177M，所以这里申请内存200M
    _imageDataBuf = new uchar[_imageDataReadLen * 20];
    _runningFlag = true;
    _queryThread = new std::thread(&cs200::DeviceStateQuery::query, this);
}

void cs200::DeviceStateQuery::stopThread()
{
    delete[] _imageDataReadBuf;
    delete[] _imageDataBuf;
    _runningFlag = false;
    _queryThread->join();
    delete _queryThread;
}
