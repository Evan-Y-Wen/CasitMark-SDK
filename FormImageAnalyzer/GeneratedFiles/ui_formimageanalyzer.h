/********************************************************************************
** Form generated from reading UI file 'formimageanalyzer.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMIMAGEANALYZER_H
#define UI_FORMIMAGEANALYZER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mygraphicsview.h"

QT_BEGIN_NAMESPACE

class Ui_FormImageAnalyzerClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QFrame *centra_frame;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *Button_OpenPattern;
    QToolButton *Button_Recognize;
    QToolButton *Button_Rerecognize;
    QToolButton *Button_AddData;
    QToolButton *Button_SaveData;
    QToolButton *Button_ExcelRead;
    QSplitter *splitter;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QFrame *frame_2;
    QGridLayout *gridLayout_3;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *Button_ZoomIn;
    QToolButton *Button_ZoomOut;
    QToolButton *Button_Recover;
    QSpacerItem *horizontalSpacer;
    QToolButton *Button_Clockwise;
    QToolButton *Button_Negative;
    MyGraphicsView *graphicsView;
    QFrame *frame_1;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_ListTitle;
    QVBoxLayout *verticalLayout_8;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_2;
    QTableView *tableView;

    void setupUi(QMainWindow *FormImageAnalyzerClass)
    {
        if (FormImageAnalyzerClass->objectName().isEmpty())
            FormImageAnalyzerClass->setObjectName(QString::fromUtf8("FormImageAnalyzerClass"));
        FormImageAnalyzerClass->resize(1178, 824);
        centralWidget = new QWidget(FormImageAnalyzerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        centra_frame = new QFrame(centralWidget);
        centra_frame->setObjectName(QString::fromUtf8("centra_frame"));
        centra_frame->setFrameShape(QFrame::StyledPanel);
        centra_frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(centra_frame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(centra_frame);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 80));
        frame->setMaximumSize(QSize(16777215, 80));
        frame->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\256\213\344\275\223\";"));
        frame->setFrameShape(QFrame::WinPanel);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(50);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Button_OpenPattern = new QToolButton(frame);
        Button_OpenPattern->setObjectName(QString::fromUtf8("Button_OpenPattern"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Button_OpenPattern->sizePolicy().hasHeightForWidth());
        Button_OpenPattern->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(Button_OpenPattern);

        Button_Recognize = new QToolButton(frame);
        Button_Recognize->setObjectName(QString::fromUtf8("Button_Recognize"));
        sizePolicy.setHeightForWidth(Button_Recognize->sizePolicy().hasHeightForWidth());
        Button_Recognize->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(Button_Recognize);

        Button_Rerecognize = new QToolButton(frame);
        Button_Rerecognize->setObjectName(QString::fromUtf8("Button_Rerecognize"));
        sizePolicy.setHeightForWidth(Button_Rerecognize->sizePolicy().hasHeightForWidth());
        Button_Rerecognize->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(Button_Rerecognize);

        Button_AddData = new QToolButton(frame);
        Button_AddData->setObjectName(QString::fromUtf8("Button_AddData"));
        sizePolicy.setHeightForWidth(Button_AddData->sizePolicy().hasHeightForWidth());
        Button_AddData->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(Button_AddData);

        Button_SaveData = new QToolButton(frame);
        Button_SaveData->setObjectName(QString::fromUtf8("Button_SaveData"));
        sizePolicy.setHeightForWidth(Button_SaveData->sizePolicy().hasHeightForWidth());
        Button_SaveData->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(Button_SaveData);

        Button_ExcelRead = new QToolButton(frame);
        Button_ExcelRead->setObjectName(QString::fromUtf8("Button_ExcelRead"));
        sizePolicy.setHeightForWidth(Button_ExcelRead->sizePolicy().hasHeightForWidth());
        Button_ExcelRead->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(Button_ExcelRead);


        verticalLayout->addWidget(frame);

        splitter = new QSplitter(centra_frame);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setMinimumSize(QSize(1140, 700));
        splitter->setFrameShape(QFrame::Panel);
        splitter->setOrientation(Qt::Horizontal);
        frame_3 = new QFrame(splitter);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy1);
        frame_3->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\256\213\344\275\223\";"));
        frame_3->setFrameShape(QFrame::Panel);
        verticalLayout_7 = new QVBoxLayout(frame_3);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        groupBox_2 = new QGroupBox(frame_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        frame_2 = new QFrame(groupBox_2);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Plain);
        gridLayout_3 = new QGridLayout(frame_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        frame_4 = new QFrame(frame_2);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setMinimumSize(QSize(0, 40));
        frame_4->setMaximumSize(QSize(16777215, 40));
        frame_4->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_3 = new QHBoxLayout(frame_4);
        horizontalLayout_3->setSpacing(50);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 2, -1, 2);
        Button_ZoomIn = new QToolButton(frame_4);
        Button_ZoomIn->setObjectName(QString::fromUtf8("Button_ZoomIn"));
        sizePolicy.setHeightForWidth(Button_ZoomIn->sizePolicy().hasHeightForWidth());
        Button_ZoomIn->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(Button_ZoomIn);

        Button_ZoomOut = new QToolButton(frame_4);
        Button_ZoomOut->setObjectName(QString::fromUtf8("Button_ZoomOut"));
        sizePolicy.setHeightForWidth(Button_ZoomOut->sizePolicy().hasHeightForWidth());
        Button_ZoomOut->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(Button_ZoomOut);

        Button_Recover = new QToolButton(frame_4);
        Button_Recover->setObjectName(QString::fromUtf8("Button_Recover"));
        sizePolicy.setHeightForWidth(Button_Recover->sizePolicy().hasHeightForWidth());
        Button_Recover->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(Button_Recover);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        Button_Clockwise = new QToolButton(frame_4);
        Button_Clockwise->setObjectName(QString::fromUtf8("Button_Clockwise"));
        sizePolicy.setHeightForWidth(Button_Clockwise->sizePolicy().hasHeightForWidth());
        Button_Clockwise->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(Button_Clockwise);

        Button_Negative = new QToolButton(frame_4);
        Button_Negative->setObjectName(QString::fromUtf8("Button_Negative"));
        sizePolicy.setHeightForWidth(Button_Negative->sizePolicy().hasHeightForWidth());
        Button_Negative->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(Button_Negative);


        gridLayout_3->addWidget(frame_4, 1, 0, 1, 1);

        graphicsView = new MyGraphicsView(frame_2);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout_3->addWidget(graphicsView, 0, 0, 1, 1);


        gridLayout_4->addWidget(frame_2, 0, 0, 1, 1);


        verticalLayout_7->addWidget(groupBox_2);

        splitter->addWidget(frame_3);
        frame_1 = new QFrame(splitter);
        frame_1->setObjectName(QString::fromUtf8("frame_1"));
        sizePolicy.setHeightForWidth(frame_1->sizePolicy().hasHeightForWidth());
        frame_1->setSizePolicy(sizePolicy);
        frame_1->setMinimumSize(QSize(300, 0));
        frame_1->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\256\213\344\275\223\";"));
        frame_1->setFrameShape(QFrame::Panel);
        verticalLayout_6 = new QVBoxLayout(frame_1);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        groupBox_ListTitle = new QGroupBox(frame_1);
        groupBox_ListTitle->setObjectName(QString::fromUtf8("groupBox_ListTitle"));
        verticalLayout_8 = new QVBoxLayout(groupBox_ListTitle);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        scrollArea_2 = new QScrollArea(groupBox_ListTitle);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 276, 637));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tableView = new QTableView(scrollAreaWidgetContents_2);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout_2->addWidget(tableView, 0, 0, 1, 1);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_8->addWidget(scrollArea_2);


        verticalLayout_6->addWidget(groupBox_ListTitle);

        splitter->addWidget(frame_1);

        verticalLayout->addWidget(splitter);


        gridLayout->addWidget(centra_frame, 0, 0, 1, 1);

        FormImageAnalyzerClass->setCentralWidget(centralWidget);

        retranslateUi(FormImageAnalyzerClass);
        QObject::connect(Button_OpenPattern, SIGNAL(clicked(bool)), FormImageAnalyzerClass, SLOT(OnButtonOpenPatten()));
        QObject::connect(Button_ZoomIn, SIGNAL(clicked(bool)), FormImageAnalyzerClass, SLOT(OnButtonZoomIn()));
        QObject::connect(Button_ZoomOut, SIGNAL(clicked(bool)), FormImageAnalyzerClass, SLOT(OnButtonZoomOut()));
        QObject::connect(Button_Recover, SIGNAL(clicked(bool)), FormImageAnalyzerClass, SLOT(OnButtonRecover()));
        QObject::connect(Button_Clockwise, SIGNAL(clicked(bool)), FormImageAnalyzerClass, SLOT(OnButtonNegativeRotate()));
        QObject::connect(Button_Negative, SIGNAL(clicked(bool)), FormImageAnalyzerClass, SLOT(OnButtonClockwiseRotate()));
        QObject::connect(Button_AddData, SIGNAL(clicked(bool)), FormImageAnalyzerClass, SLOT(OnButtonAddData()));
        QObject::connect(Button_Recognize, SIGNAL(clicked(bool)), FormImageAnalyzerClass, SLOT(OnButtonRecognize()));
        QObject::connect(Button_SaveData, SIGNAL(clicked(bool)), FormImageAnalyzerClass, SLOT(OnButtonSaveData()));
        QObject::connect(Button_Rerecognize, SIGNAL(clicked(bool)), FormImageAnalyzerClass, SLOT(OnButtonReRecognize()));

        QMetaObject::connectSlotsByName(FormImageAnalyzerClass);
    } // setupUi

    void retranslateUi(QMainWindow *FormImageAnalyzerClass)
    {
        FormImageAnalyzerClass->setWindowTitle(QApplication::translate("FormImageAnalyzerClass", "FormImageAnalyzer", nullptr));
        Button_OpenPattern->setText(QApplication::translate("FormImageAnalyzerClass", "\345\210\207\346\215\242\346\250\241\345\274\217", nullptr));
        Button_Recognize->setText(QApplication::translate("FormImageAnalyzerClass", "\350\257\206\345\210\253\350\241\250\346\240\274", nullptr));
        Button_Rerecognize->setText(QApplication::translate("FormImageAnalyzerClass", "\351\207\215\346\226\260\350\257\206\345\210\253", nullptr));
        Button_AddData->setText(QApplication::translate("FormImageAnalyzerClass", "\346\267\273\345\212\240\346\225\260\346\215\256", nullptr));
        Button_SaveData->setText(QApplication::translate("FormImageAnalyzerClass", "\345\257\274\345\207\272\346\225\260\346\215\256", nullptr));
        Button_ExcelRead->setText(QApplication::translate("FormImageAnalyzerClass", "\347\273\223\346\236\234\350\275\254\345\214\226", nullptr));
        groupBox_2->setTitle(QApplication::translate("FormImageAnalyzerClass", "\350\241\250\346\240\274\345\233\276\345\203\217", nullptr));
        Button_ZoomIn->setText(QApplication::translate("FormImageAnalyzerClass", "\346\224\276\345\244\247", nullptr));
        Button_ZoomOut->setText(QApplication::translate("FormImageAnalyzerClass", "\347\274\251\345\260\217", nullptr));
        Button_Recover->setText(QApplication::translate("FormImageAnalyzerClass", "\350\277\230\345\216\237", nullptr));
        Button_Clockwise->setText(QApplication::translate("FormImageAnalyzerClass", "\351\200\206\346\227\266\351\222\210\346\227\213\350\275\254", nullptr));
        Button_Negative->setText(QApplication::translate("FormImageAnalyzerClass", "\351\241\272\346\227\266\351\222\210\346\227\213\350\275\254", nullptr));
        groupBox_ListTitle->setTitle(QApplication::translate("FormImageAnalyzerClass", "\346\200\273\350\257\206\345\210\253\350\241\250\346\240\274\346\225\260\357\274\2320\345\274\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormImageAnalyzerClass: public Ui_FormImageAnalyzerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMIMAGEANALYZER_H
