#pragma once
#include <QFile>
#include <QStringList>
#include "formpatternmaker.h"//主窗口头文件
#include "createpattern.h"//新建模式子窗口
#include "addpattern.h"//添加模板子窗口
// 此处定义所有操作函数的声明

// 新建模式
void CreatePatternFun(FormPatternMaker *TheMainWindow);

//打开模式   // 返回加载的模式文件(public Cm2.FormPattern.MPattern类型的文件)，加载错误时返回空.
QFile *OpenPatternFromFileFun(const QString &openFileNames);

//保存模式
void SavePatternFun(const QString &iFilePath);

//添加模板
void AddPatternFun();