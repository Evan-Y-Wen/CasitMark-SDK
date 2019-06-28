#pragma once

#include "cocer200scan_global.h"

namespace cs200
{
    typedef struct tagBITMAPFILEHEADER {
        int16_t bfType;
        int32_t bfSize;
        int16_t bfReserved1;
        int16_t bfReserved2;
        int32_t bfOffBits;
    } BITMAPFILEHEADER;

    typedef struct tagBITMAPINFOHEADER {
        int32_t biSize;
        int32_t biWidth;
        int32_t biHeight;
        int16_t biPlanes;
        int16_t biBitCount;
        int32_t biCompression;
        int32_t biSizeImage;
        int32_t biXPelsPerMeter;
        int32_t biYPelsPerMeter;
        int32_t biClrUsed;
        int32_t biClrImportant;
    } BITMAPINFOHEADER;

    typedef struct tagRGBQUAD {
        uchar rgbBlue;
        uchar rgbGreen;
        uchar rgbRed;
        uchar rgbReserved;
    } RGBQUAD;

    class DibFile
    {
    public:
        DibFile();
        ~DibFile();

        static uchar* CreateDibFile(uchar *pixData, int w, int h, int c, int &len);
    };
};
