#pragma once

#include <QDialog>
#include "ui_scansetting.h"
#include "deviceconfig.h"

class ScanSetting: public QDialog
{
    Q_OBJECT

public:
    ScanSetting(cs200::DeviceConfig *devCfg, QWidget *parent = Q_NULLPTR);
    ~ScanSetting();

public slots:
    // 确认修改
    void Confirm();

    // 选择的图像类型改变
    void ImageTypeChanged();

private:
    Ui::ScanSetting ui;
    cs200::DeviceConfig *_devCfg;

public:
	QString _mDPI;
	QString _mImageType;
	QString _mLightColor;
	QString _mCheckBox_DoubleCheck;
};
