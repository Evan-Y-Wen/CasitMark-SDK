#pragma once

#include "libusb-1.0/libusb.h"

namespace cs200
{
    class UsbImp
    {
    public:
        UsbImp();
        ~UsbImp();

        libusb_device_handle *Dev_handle;
    };
};
