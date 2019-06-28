#pragma once

#include <queue>
#include <thread>
#include <mutex>

namespace cs200
{
    class Cocer200Scan;
    class DeviceConfig;
    class ImgProcess
    {
    public:
        ImgProcess(Cocer200Scan *cocer, DeviceConfig *devCfg);
        ~ImgProcess();

        // 图像数据入队
        void dataEnqueue(unsigned char *data, int len, int imgDPI, int imgChannel);

        // 启动处理线程
        void startThread();

        // 停止处理线程
        void stopThread();

    private:
        class DataInfo
        {
        public:
            DataInfo();
            ~DataInfo();
            
            unsigned char *Data;
            int DataLen;
            int ImgDPI;
            int ImgChannel;
        };

        DataInfo* dataDequeue();

        void process();

        void reverse(unsigned char *&arr, int arrLen);

        unsigned char* yuv442ToRGB(unsigned char *yuv, int w, int h);

        void extractFrontAndBackImageData(DataInfo* dataInfo, 
            unsigned char *&dataFront, int &wFront, int &hFront,
            unsigned char *&dataBack, int &wBack, int &hBack);

        unsigned char* imageTiltCorrection(unsigned char *pixel, int &w, int &h, int imgChannel);

        Cocer200Scan *_cocer;
        DeviceConfig *_devCfg;

        std::queue<DataInfo*> _dataInfoQueue;
        bool _runningFlag;
        std::mutex _queueLock;
        std::thread *_processThread;
    };
}