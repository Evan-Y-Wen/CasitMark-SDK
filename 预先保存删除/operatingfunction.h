#pragma once
#include <QFile>
#include <QStringList>
#include "formpatternmaker.h"//������ͷ�ļ�
#include "createpattern.h"//�½�ģʽ�Ӵ���
#include "addpattern.h"//���ģ���Ӵ���
// �˴��������в�������������

// �½�ģʽ
void CreatePatternFun(FormPatternMaker *TheMainWindow);

//��ģʽ   // ���ؼ��ص�ģʽ�ļ�(public Cm2.FormPattern.MPattern���͵��ļ�)�����ش���ʱ���ؿ�.
QFile *OpenPatternFromFileFun(const QString &openFileNames);

//����ģʽ
void SavePatternFun(const QString &iFilePath);

//���ģ��
void AddPatternFun();