#include "imgprocess.h"
#include "cocer200scan.h"
#include "deviceconfig.h"
#include "dibfile.h"

#include <chrono>

cs200::ImgProcess::ImgProcess(Cocer200Scan *cocer, DeviceConfig *devCfg):
    _cocer(cocer),
    _devCfg(devCfg),
    _runningFlag(false),
    _processThread(NULL)
{
}

cs200::ImgProcess::~ImgProcess()
{
}

void cs200::ImgProcess::dataEnqueue(unsigned char *data, int len, int imgDPI, int imgChannel)
{
    cs200::ImgProcess::DataInfo *dataInfo = new cs200::ImgProcess::DataInfo();
    dataInfo->Data = data;
    dataInfo->DataLen = len;
    dataInfo->ImgDPI = imgDPI;
    dataInfo->ImgChannel = imgChannel;
    
    std::lock_guard<std::mutex> lock(_queueLock);
    _dataInfoQueue.push(dataInfo);
}

void cs200::ImgProcess::startThread()
{
    _runningFlag = true;
    _processThread = new std::thread(&cs200::ImgProcess::process, this);
}

void cs200::ImgProcess::stopThread()
{
    _runningFlag = false;
    _processThread->join();
    delete _processThread;
}

cs200::ImgProcess::DataInfo::DataInfo() :
    Data(NULL),
    DataLen(0),
    ImgDPI(200),
    ImgChannel(1)
{
}

cs200::ImgProcess::DataInfo::~DataInfo()
{
    if (Data != NULL)
        delete[] Data;
}

cs200::ImgProcess::DataInfo* cs200::ImgProcess::dataDequeue()
{
    cs200::ImgProcess::DataInfo *ret = NULL;
    std::lock_guard<std::mutex> lock(_queueLock);
    if (!_dataInfoQueue.empty())
    {
        ret = _dataInfoQueue.front();
        _dataInfoQueue.pop();
    }
    return ret;
}

void cs200::ImgProcess::process()
{
    cs200::ImgProcess::DataInfo *dataInfo = NULL;
    unsigned char *dataFront, *dataBack;
    int wFront, hFront, wBack, hBack;
    unsigned char *bmpFront, *bmpBack;
    int frontBmpLen, backBmpLen;
    while (_runningFlag)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(_devCfg->Image_ProcessInterval));
        dataInfo = dataDequeue();
        if (dataInfo != NULL)
        {
            extractFrontAndBackImageData(dataInfo, dataFront, wFront, hFront, dataBack, wBack, hBack);
            bmpFront = cs200::DibFile::CreateDibFile(dataFront, wFront, hFront, dataInfo->ImgChannel, frontBmpLen);
            delete[] dataFront;
            bmpBack = cs200::DibFile::CreateDibFile(dataBack, wBack, hBack, dataInfo->ImgChannel, backBmpLen);
            delete[] dataBack;

            emit _cocer->ImageGenerated(bmpFront, frontBmpLen, bmpBack, backBmpLen);

            delete dataInfo;
            dataInfo = NULL;
        }
    }
}

void cs200::ImgProcess::reverse(unsigned char *& arr, int arrLen)
{
    unsigned char swap = 0;
    int half = arrLen / 2;
    for (int i = 0; i < half; ++i)
    {
        swap = arr[i];
        arr[i] = arr[arrLen - i - 1];
        arr[arrLen - i - 1] = swap;
    }
}

unsigned char* cs200::ImgProcess::yuv442ToRGB(unsigned char *yuv, int w, int h)
{
    // YUV422编码规则-每四个像素点有四个Y分量，U、V分量各2个，即Y0 U0 Y1 V1 Y2 U2 Y3 V3表示四个像素点的彩色值
    unsigned char* rgb = new unsigned char[w * h * 3];
    int Y, U, V, B, G, R;
    for (int y = 0; y < h; ++y)
    {
        for (int x = 0; x < w; ++x)
        {
            // Y
            Y = yuv[y * w * 2 + x * 2];
            if (x % 2 == 0)
            {
                // U
                U = yuv[y * w * 2 + x * 2 + 1];
                // V
                V = yuv[y * w * 2 + (x + 1) * 2 + 1];
            }
            else
            {
                // U
                U = yuv[y * w * 2 + (x - 1) * 2 + 1];
                // V
                V = yuv[y * w * 2 + x * 2 + 1];
            }
            R = (298 * Y + 411 * V - 57344) >> 8;
            G = (298 * Y - 101 * U - 211 * V + 34739) >> 8;
            B = (298 * Y + 519 * U - 71117) >> 8;
            R = R < 0 ? 0 : R > 255 ? 255 : R;
            G = G < 0 ? 0 : G > 255 ? 255 : G;
            B = B < 0 ? 0 : B > 255 ? 255 : B;
            rgb[y * w * 3 + x * 3 + 0] = R;
            rgb[y * w * 3 + x * 3 + 1] = G;
            rgb[y * w * 3 + x * 3 + 2] = B;
        }
    }
    return rgb;
}

void cs200::ImgProcess::extractFrontAndBackImageData(cs200::ImgProcess::DataInfo* dataInfo, 
    unsigned char *&dataFront, int &wFront, int &hFront, 
    unsigned char *&dataBack, int &wBack, int &hBack)
{
    // 将像素数据处理成图片
    int imgDataW = _devCfg->Dev_ImageDataPixelPerInch * dataInfo->ImgDPI * 2;
    wFront = wBack = imgDataW / 2;
    int frontOffset = 0;
    int backOffset = 0;
    if (dataInfo->ImgChannel == 1)
    {
        int segmentLen = imgDataW / 3;
        int seg1 = 0;
        int seg2 = segmentLen;
        int seg3 = 2 * segmentLen;
        hFront = hBack = dataInfo->DataLen / imgDataW;
        dataFront = new unsigned char[wFront * hFront * dataInfo->ImgChannel];
        dataBack = new unsigned char[wBack * hBack * dataInfo->ImgChannel];
        unsigned char* tmp = new unsigned char[dataInfo->DataLen];
        for (int y = 0; y < hFront; ++y)
        {
            seg1 = 0;
            seg2 = segmentLen;
            seg3 = 2 * segmentLen;
            for (int x = 0; x < imgDataW; ++x)
            {
                if (x / 32 % 3 == 0)
                {
                    tmp[seg1 + y * imgDataW] = dataInfo->Data[y * imgDataW + x];
                    seg1++;
                }
                else if (x / 32 % 3 == 1)
                {
                    tmp[seg2 + y * imgDataW] = dataInfo->Data[y * imgDataW + x];
                    seg2++;
                }
                else
                {
                    tmp[seg3 + y * imgDataW] = dataInfo->Data[y * imgDataW + x];
                    seg3++;
                }
            }
        }
        for (int i = 0; i < dataInfo->DataLen / 16; ++i)
        {
            unsigned char *segP = tmp + i * 16;
            reverse(segP, 16);
            for (int j = 0; j < 16; j += 2)
            {
                unsigned char swap = segP[j];
                segP[j] = segP[j + 1];
                segP[j + 1] = swap;
            }
        }

        for (int i = 0; i < dataInfo->DataLen; ++i)
        {
            if (i / 16 % 2 == 0)
                dataBack[frontOffset++] = tmp[i];
            else
                dataFront[backOffset++] = tmp[i];
        }
        delete[] tmp;
    }
    else
    {
        int segmentLen = imgDataW / 3;
        int seg1 = 0;
        int seg2 = segmentLen * 2;
        int seg3 = 2 * segmentLen * 2;
        hFront = hBack = dataInfo->DataLen / imgDataW / 2;
        unsigned char *yuvFront = new unsigned char[wFront * hFront * 2];
        unsigned char *yuvBack = new unsigned char[wBack * hBack * 2];
        unsigned char* tmp = new unsigned char[dataInfo->DataLen];
        for (int y = 0; y < hFront; ++y)
        {
            seg1 = 0;
            seg2 = segmentLen * 2;
            seg3 = 2 * segmentLen * 2;
            for (int x = 0; x < imgDataW; ++x)
            {
                if (x / 16 % 3 == 0)
                {
                    tmp[seg1 + y * imgDataW * 2 + 0] = dataInfo->Data[y * imgDataW * 2 + x * 2 + 0];
                    tmp[seg1 + y * imgDataW * 2 + 1] = dataInfo->Data[y * imgDataW * 2 + x * 2 + 1];
                    seg1 += 2;
                }
                else if (x / 16 % 3 == 1)
                {
                    tmp[seg2 + y * imgDataW * 2 + 0] = dataInfo->Data[y * imgDataW * 2 + x * 2 + 0];
                    tmp[seg2 + y * imgDataW * 2 + 1] = dataInfo->Data[y * imgDataW * 2 + x * 2 + 1];
                    seg2 += 2;
                }
                else
                {
                    tmp[seg3 + y * imgDataW * 2 + 0] = dataInfo->Data[y * imgDataW * 2 + x * 2 + 0];
                    tmp[seg3 + y * imgDataW * 2 + 1] = dataInfo->Data[y * imgDataW * 2 + x * 2 + 1];
                    seg3 += 2;
                }
            }
        }
        for (int i = 0; i < dataInfo->DataLen / 8 / 2; ++i)
        {
            unsigned char *segP = tmp + i * 8 * 2;
            for (int j = 0; j < 4; ++j)
            {
                unsigned char swap1 = segP[j * 2];
                unsigned char swap2 = segP[j * 2 + 1];
                segP[j * 2] = segP[(8 - j - 1) * 2];
                segP[j * 2 + 1] = segP[(8 - j - 1) * 2 + 1];
                segP[(8 - j - 1) * 2] = swap1;
                segP[(8 - j - 1) * 2 + 1] = swap2;
            }
        }

        for (int i = 0; i < dataInfo->DataLen; ++i)
        {
            if (i / 16 % 2 == 0)
                yuvBack[frontOffset++] = tmp[i];
            else
                yuvFront[backOffset++] = tmp[i];
        }
        delete[] tmp;

        dataFront = yuv442ToRGB(yuvFront, wFront, hFront);
        delete[] yuvFront;
        dataBack = yuv442ToRGB(yuvBack, wBack, hBack);
        delete[] yuvBack;
    }

    // 水平镜像变换数据
    unsigned char mirror = 0;
    int half = wFront / 2;
    int left = 0, right = 0;
    for (int y = 0; y < hFront; ++y)
    {
        for (int x = 0; x < half; ++x)
        {
            for (int i = 0; i < dataInfo->ImgChannel; ++i)
            {
                left = y * wFront * dataInfo->ImgChannel + x * dataInfo->ImgChannel + i;
                right = y * wFront * dataInfo->ImgChannel + (wFront - x - 1) * dataInfo->ImgChannel + i;
                mirror = dataFront[left];
                dataFront[left] = dataFront[right];
                dataFront[right] = mirror;
            }
        }
    }
    half = wBack / 2;
    for (int y = 0; y < hBack; ++y)
    {
        for (int x = 0; x < half; ++x)
        {
            for (int i = 0; i < dataInfo->ImgChannel; ++i)
            {
                left = y * wBack * dataInfo->ImgChannel + x * dataInfo->ImgChannel + i;
                right = y * wBack * dataInfo->ImgChannel + (wBack - x - 1) * dataInfo->ImgChannel + i;
                mirror = dataBack[left];
                dataBack[left] = dataBack[right];
                dataBack[right] = mirror;
            }
        }
    }
}

unsigned char * cs200::ImgProcess::imageTiltCorrection(unsigned char *pixel, int &w, int &h, int imgChannel)
{
    unsigned char* sGray = pixel;
    if (imgChannel == 3)
    {
        // rgb to gray
        sGray = new unsigned char[w * h];
        int grayPixel = 0;
        int r = 0, g = 0, b = 0;
        for (int y = 0; y < h; ++y)
        {
            for (int x = 0; x < w; ++x)
            {
                r = y * w * imgChannel + x * imgChannel;
                g = r + 1;
                b = g + 1;
                grayPixel = (30 * pixel[r] + 59 * pixel[g] * 11 * pixel[b]) / 100;
                grayPixel = grayPixel > 255 ? 255 : grayPixel < 0 ? 0 : grayPixel;
                sGray[y * w + x] = grayPixel;
            }
        }
    }

    // 缩小到100dpi，近邻插值，并搜索有效图像边界
    int sw = 100 * _devCfg->Dev_ImageDataPixelPerInch;
    float scale = sw / w;
    int sh = h * scale;
    float tx, ty;
    int dx, dy;
    int rx = sw, ry = sh, rw = 0, rh = 0;
    unsigned char *dGray = new unsigned char[sw * sh];
    for (int y = 0; y < sh; ++y)
    {
        for (int x = 0; x < sw; ++x)
        {
            tx = x / scale;
            ty = y / scale;
            dx = (int)(tx + 0.5);
            dy = (int)(ty + 0.5);
            if (dx >= 0 && dx < w && dy >= 0 && dy < h)
            {
                dGray[y * sw + x] = sGray[dy * w + dx];

            }
        }
    }

    delete[] dGray;
    if (imgChannel == 3)
        delete[] sGray;

    return nullptr;
}
