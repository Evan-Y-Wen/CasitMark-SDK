#pragma once

#include <QDialog>
#include "ui_recognizeform.h"
#include "appconfig.h"
#include "cocer200scan.h"//��ȡ�Ķ��豸״̬��Ϣ
#include "scansetting.h"//���á���ȡ�Ķ��豸������Ϣ

#include <QFileDialog>
#include <QMessageBox>
#include <QStringList>
#include <QFileInfoList>
#include <QFileInfo>
#include <QFile>
#include <QDir>
#include <QDebug>

class RecognizeForm : public QDialog
{
	Q_OBJECT

public:
	RecognizeForm(AppConfig * appConfig, QString *appExeFolder, QWidget *parent = Q_NULLPTR);
	~RecognizeForm();

private:
	Ui::RecognizeForm ui;


/***************************************
*���壺�ۺ���
*���ԣ�����
***************************************/
public slots:
	//��һҳ��ר���豸
	void CheckBox_Rotate90_Click();
	void CheckBox_AutoFilterWhitePage_Click();
	void OpenDevice();	// �Ķ��豸����
	void StartScan();
	void StopScan();
	void CloseDeivce();
	void Setting();
	void SaveImage();
	// �Ķ��豸�ź���Ӧ��
	void OnDeviceInfoChanged(cs200::eDeviceInfo info);
	// ͼ�����ݲɼ�����Ӧ�ۣ����ڲ�ʹʱ�����ͷ��ڴ�ռ�
	void OnDeviceImageGenerated(uchar *fImgBuf, int fBufLen, uchar *bImgBuf, int bBufLen);

	//�ڶ�ҳ��ͼ���ļ�
	void Button_OpenDirs_Click();
	void Button_OpenFiles_Click();



/***************************************
*���壺��Ա����
*���ԣ�˽��
***************************************/
private:
	//���������ָ�룬��δ���ڸ��Ӵ��ڷ����ڴ棬���������ڷ�����ڴ档
	QString *_mAppExeFolder = nullptr;//��������Ŀ¼
	AppConfig *_mAppConfig = nullptr;//XML�ļ����ö�ȡ
	QString _imageSaveFolder;
	int _imageIndex;// ��Чʶ��ż���
	int _imageCount;// �����ۺ��������

	QString _cfgFilePath;
	cs200::Cocer200Scan _dev;//Cocer200Scan���涨���������źţ����������������źŷ����ߡ�
};
