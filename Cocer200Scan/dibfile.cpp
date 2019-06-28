#include "dibfile.h"

#include <cstring>

cs200::DibFile::DibFile()
{
}


cs200::DibFile::~DibFile()
{
}

uchar* cs200::DibFile::CreateDibFile(uchar *pixData, int w, int h, int c, int &len)
{
    uchar* rDibFile = NULL;
    uchar* data = NULL;

    BITMAPFILEHEADER file;
    file.bfType = 0x4d42;
    file.bfSize = 0;
    file.bfReserved1 = 0;
    file.bfReserved2 = 0;
    file.bfOffBits = 0;
    BITMAPINFOHEADER info;
    info.biSize = 40;
    info.biWidth = w;
    info.biHeight = h;
    info.biBitCount = 8 * c;
    info.biPlanes = 1;
    info.biCompression = 0;
    info.biSizeImage = 0;
    info.biXPelsPerMeter = 0;
    info.biYPelsPerMeter = 0;
    info.biClrUsed = 0;
    info.biClrImportant = 0;

    int dataSizePerLine = (info.biWidth * info.biBitCount + 31) / 8;
    dataSizePerLine = dataSizePerLine / 4 * 4;
    int dataSize = dataSizePerLine * info.biHeight;
    switch (c)
    {
    case 1:
    {
        file.bfOffBits = 14 + 40 + sizeof(RGBQUAD) * 256;
        file.bfSize = file.bfOffBits + dataSize;
        rDibFile = new uchar[file.bfSize];
        data = rDibFile;
        *(int16_t*)data = file.bfType;
        data += 2;
        *(int32_t*)data = file.bfSize;
        data += 4;
        *(int16_t*)data = file.bfReserved1;
        data += 2;
        *(int16_t*)data = file.bfReserved2;
        data += 2;
        *(int32_t*)data = file.bfOffBits;
        data += 4;
        *(int32_t*)data = info.biSize;
        data += 4;
        *(int32_t*)data = info.biWidth;
        data += 4;
        *(int32_t*)data = info.biHeight;
        data += 4;
        *(int16_t*)data = info.biPlanes;
        data += 2;
        *(int16_t*)data = info.biBitCount;
        data += 2;
        *(int32_t*)data = info.biCompression;
        data += 4;
        *(int32_t*)data = info.biSizeImage;
        data += 4;
        *(int32_t*)data = info.biXPelsPerMeter;
        data += 4;
        *(int32_t*)data = info.biYPelsPerMeter;
        data += 4;
        *(int32_t*)data = info.biClrUsed;
        data += 4;
        *(int32_t*)data = info.biClrImportant;
        data += 4;
        for (int i = 0; i < 256; ++i)
        {
            RGBQUAD *quad = (RGBQUAD*)(data + i * sizeof(RGBQUAD));
            quad->rgbBlue = quad->rgbGreen = quad->rgbRed = i;
            quad->rgbReserved = 0;
        }
        data = rDibFile + file.bfOffBits;
        for (int i = 0; i < info.biHeight; ++i)
            memcpy(data + dataSizePerLine * i, pixData + info.biWidth * (info.biHeight - i - 1), info.biWidth);
    }
    break;
    case 3:
    {
        file.bfOffBits = 14 + 40;
        file.bfSize = file.bfOffBits + dataSize;
        rDibFile = new uchar[file.bfSize];
        data = rDibFile;
        *(int16_t*)data = file.bfType;
        data += 2;
        *(int32_t*)data = file.bfSize;
        data += 4;
        *(int16_t*)data = file.bfReserved1;
        data += 2;
        *(int16_t*)data = file.bfReserved2;
        data += 2;
        *(int32_t*)data = file.bfOffBits;
        data += 4;
        *(int32_t*)data = info.biSize;
        data += 4;
        *(int32_t*)data = info.biWidth;
        data += 4;
        *(int32_t*)data = info.biHeight;
        data += 4;
        *(int16_t*)data = info.biPlanes;
        data += 2;
        *(int16_t*)data = info.biBitCount;
        data += 2;
        *(int32_t*)data = info.biCompression;
        data += 4;
        *(int32_t*)data = info.biSizeImage;
        data += 4;
        *(int32_t*)data = info.biXPelsPerMeter;
        data += 4;
        *(int32_t*)data = info.biYPelsPerMeter;
        data += 4;
        *(int32_t*)data = info.biClrUsed;
        data += 4;
        *(int32_t*)data = info.biClrImportant;
        data = rDibFile + file.bfOffBits;
        for (int i = 0; i < info.biHeight; ++i)
            memcpy(data + dataSizePerLine * i, pixData + info.biWidth * c * (info.biHeight - i - 1), info.biWidth * c);
    }
    break;
    default:
    {
        len = 0;
        return NULL;
    }
    break;
    }

    len = file.bfSize;
    return rDibFile;
}
