#include "scansetting.h"

#include <QButtonGroup>
#include <QString>

ScanSetting::ScanSetting(cs200::DeviceConfig *devCfg, QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);

    _devCfg = devCfg;
	_mDPI.isNull();
	_mImageType.isNull();
	_mLightColor.isNull();
	_mCheckBox_DoubleCheck.isNull();

    Qt::WindowFlags flags = this->windowFlags();
    setWindowFlags(flags&~Qt::WindowContextHelpButtonHint);

	//ui.comboBox_ImageDPI->setView(new QListView());//调整ComboBox下拉项目的间隔
    ui.comboBox_ImageDPI->setCurrentText(QString::number(_devCfg->Dev_DPI));
    QButtonGroup *bg = new QButtonGroup(this);
    bg->addButton(ui.radioButton_TypeColor);
    bg->addButton(ui.radioButton_TypeGray);
    bg = new QButtonGroup(this);
    bg->addButton(ui.radioButton_LightWhite);
    bg->addButton(ui.radioButton_LightRed);
    bg->addButton(ui.radioButton_LightGreen);
    bg->addButton(ui.radioButton_LightBlue);
    if (_devCfg->Dev_ImageType)
    {
        // 彩色
        ui.radioButton_TypeColor->setChecked(true);
        ui.radioButton_LightWhite->setEnabled(false);
        ui.radioButton_LightRed->setEnabled(false);
        ui.radioButton_LightGreen->setEnabled(false);
        ui.radioButton_LightBlue->setEnabled(false);
    }
    else
    {
        // 灰度
        ui.radioButton_TypeGray->setChecked(true);
        switch (_devCfg->Dev_LightColor)
        {
        case 1:
            ui.radioButton_LightRed->setChecked(true);
            break;
        case 2:
            ui.radioButton_LightGreen->setChecked(true);
            break;
        case 4:
            ui.radioButton_LightBlue->setChecked(true);
            break;
        case 7:
            ui.radioButton_LightWhite->setChecked(true);
            break;
        default:
            break;
        }
    }
    if (_devCfg->Dev_DoublePaperCheck)
        ui.checkBox_DoubleCheck->setChecked(true);
    else
        ui.checkBox_DoubleCheck->setChecked(false);
    ui.pushButton_Confirm->setFocus();
}

ScanSetting::~ScanSetting()
{
}

void ScanSetting::Confirm()
{
    QString str = ui.comboBox_ImageDPI->currentText();
	_mDPI = ui.comboBox_ImageDPI->currentText();
    _devCfg->Dev_DPI = str.toInt();
    if (ui.radioButton_TypeColor->isChecked())
    {
        _devCfg->Dev_ImageType = 1;
		_mImageType = u8"彩色";
    }
    else
    {
		_mImageType = u8"灰色";
        _devCfg->Dev_ImageType = 0;
		if (ui.radioButton_LightRed->isChecked())
		{
			_devCfg->Dev_LightColor = 1;
			_mLightColor = u8"红色光源";
		}
        else if (ui.radioButton_LightGreen->isChecked())
		{
			_devCfg->Dev_LightColor = 2;
			_mLightColor = u8"绿色光源";
		}
        else if (ui.radioButton_LightBlue->isChecked())
		{
			_devCfg->Dev_LightColor = 4;
			_mLightColor = u8"蓝色光源";
		}
        else if (ui.radioButton_LightWhite->isChecked())
		{
			_devCfg->Dev_LightColor = 7;
			_mLightColor = u8"白色光源";
		}
    }
	if (ui.checkBox_DoubleCheck->isChecked())
	{
		_devCfg->Dev_DoublePaperCheck = true;
		_mCheckBox_DoubleCheck = u8"已开启重张检测";
	}
	else
	{
		_devCfg->Dev_DoublePaperCheck = false;
		_mCheckBox_DoubleCheck = u8"未开启重张检测";
	}

    this->accept();
}

void ScanSetting::ImageTypeChanged()
{
    if (ui.radioButton_TypeColor->isChecked())
    {
        ui.radioButton_LightWhite->setEnabled(false);
        ui.radioButton_LightRed->setEnabled(false);
        ui.radioButton_LightGreen->setEnabled(false);
        ui.radioButton_LightBlue->setEnabled(false);
    }
    else
    {
        ui.radioButton_LightWhite->setEnabled(true);
        ui.radioButton_LightRed->setEnabled(true);
        ui.radioButton_LightGreen->setEnabled(true);
        ui.radioButton_LightBlue->setEnabled(true);
    }
}