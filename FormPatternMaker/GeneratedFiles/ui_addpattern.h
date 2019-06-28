/********************************************************************************
** Form generated from reading UI file 'addpattern.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPATTERN_H
#define UI_ADDPATTERN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddPattern
{
public:
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QTextEdit *textEdit_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_2;
    QToolButton *BTN_AddPatternFromDevice;
    QToolButton *BTN_AddPatternFromPDF;
    QToolButton *BTN_AddPatternFromWord;
    QToolButton *BTN_AddPatternFromFile;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QTextEdit *textEdit_2;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_5;
    QGroupBox *SP_FormDetail;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_11;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_9;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_13;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_7;
    QWidget *widget_2;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_10;
    QToolButton *BTN_Left;
    QToolButton *BTN_Right;
    QSpacerItem *horizontalSpacer_8;
    QToolButton *BTN_Comfirm;

    void setupUi(QWidget *AddPattern)
    {
        if (AddPattern->objectName().isEmpty())
            AddPattern->setObjectName(QString::fromUtf8("AddPattern"));
        AddPattern->resize(913, 789);
        AddPattern->setMinimumSize(QSize(900, 789));
        AddPattern->setStyleSheet(QString::fromUtf8(""));
        gridLayout_8 = new QGridLayout(AddPattern);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new QWidget(AddPattern);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(251, 281));
        widget->setStyleSheet(QString::fromUtf8("QFrame{\n"
"    font-family: Microsoft YaHei Light;\n"
"    background-color: white;\n"
"    font: 'FangSong_GB2312';\n"
"    font-size: 12px;\n"
"}\n"
"\n"
"QFrame{\n"
"     background-color:white;/*\350\203\214\346\231\257\350\211\262*/\n"
"}\n"
"\n"
"QFrame[objectName='frameMuneBar']{\n"
"     background-color: #0e8fe3;\n"
"}"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(230, 0));
        groupBox_2->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(5);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(5, 5, 5, 5);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(0, 35));

        horizontalLayout_6->addWidget(label_5);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(0, 35));

        horizontalLayout_6->addWidget(label_6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_6);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(6);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(5);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(5, 5, 5, 5);
        textEdit_3 = new QTextEdit(groupBox_2);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit_3->sizePolicy().hasHeightForWidth());
        textEdit_3->setSizePolicy(sizePolicy);
        textEdit_3->setMinimumSize(QSize(0, 120));

        horizontalLayout_7->addWidget(textEdit_3);


        gridLayout_3->addLayout(horizontalLayout_7, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);


        gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(230, 0));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(5, 5, 5, 5);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(0, 35));

        horizontalLayout_5->addWidget(label_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(0, 35));

        horizontalLayout_5->addWidget(label_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_5);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(6);
        BTN_AddPatternFromDevice = new QToolButton(groupBox);
        BTN_AddPatternFromDevice->setObjectName(QString::fromUtf8("BTN_AddPatternFromDevice"));
        sizePolicy.setHeightForWidth(BTN_AddPatternFromDevice->sizePolicy().hasHeightForWidth());
        BTN_AddPatternFromDevice->setSizePolicy(sizePolicy);
        BTN_AddPatternFromDevice->setMinimumSize(QSize(210, 40));
        BTN_AddPatternFromDevice->setStyleSheet(QString::fromUtf8(""));
        BTN_AddPatternFromDevice->setIconSize(QSize(10, 10));
        BTN_AddPatternFromDevice->setCheckable(false);
        BTN_AddPatternFromDevice->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        BTN_AddPatternFromDevice->setAutoRaise(true);

        gridLayout_2->addWidget(BTN_AddPatternFromDevice, 3, 0, 1, 1);

        BTN_AddPatternFromPDF = new QToolButton(groupBox);
        BTN_AddPatternFromPDF->setObjectName(QString::fromUtf8("BTN_AddPatternFromPDF"));
        sizePolicy.setHeightForWidth(BTN_AddPatternFromPDF->sizePolicy().hasHeightForWidth());
        BTN_AddPatternFromPDF->setSizePolicy(sizePolicy);
        BTN_AddPatternFromPDF->setMinimumSize(QSize(210, 40));
        BTN_AddPatternFromPDF->setStyleSheet(QString::fromUtf8(""));
        BTN_AddPatternFromPDF->setIconSize(QSize(10, 10));
        BTN_AddPatternFromPDF->setCheckable(false);
        BTN_AddPatternFromPDF->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        BTN_AddPatternFromPDF->setAutoRaise(true);

        gridLayout_2->addWidget(BTN_AddPatternFromPDF, 5, 0, 1, 1);

        BTN_AddPatternFromWord = new QToolButton(groupBox);
        BTN_AddPatternFromWord->setObjectName(QString::fromUtf8("BTN_AddPatternFromWord"));
        sizePolicy.setHeightForWidth(BTN_AddPatternFromWord->sizePolicy().hasHeightForWidth());
        BTN_AddPatternFromWord->setSizePolicy(sizePolicy);
        BTN_AddPatternFromWord->setMinimumSize(QSize(210, 40));
        BTN_AddPatternFromWord->setStyleSheet(QString::fromUtf8(""));
        BTN_AddPatternFromWord->setIconSize(QSize(10, 10));
        BTN_AddPatternFromWord->setCheckable(false);
        BTN_AddPatternFromWord->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        BTN_AddPatternFromWord->setAutoRaise(true);

        gridLayout_2->addWidget(BTN_AddPatternFromWord, 4, 0, 1, 1);

        BTN_AddPatternFromFile = new QToolButton(groupBox);
        BTN_AddPatternFromFile->setObjectName(QString::fromUtf8("BTN_AddPatternFromFile"));
        sizePolicy.setHeightForWidth(BTN_AddPatternFromFile->sizePolicy().hasHeightForWidth());
        BTN_AddPatternFromFile->setSizePolicy(sizePolicy);
        BTN_AddPatternFromFile->setMinimumSize(QSize(210, 40));
        BTN_AddPatternFromFile->setStyleSheet(QString::fromUtf8(""));
        BTN_AddPatternFromFile->setIconSize(QSize(10, 10));
        BTN_AddPatternFromFile->setCheckable(false);
        BTN_AddPatternFromFile->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        BTN_AddPatternFromFile->setAutoRaise(true);

        gridLayout_2->addWidget(BTN_AddPatternFromFile, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(5, 5, 5, 5);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 30));

        horizontalLayout_4->addWidget(label_2);

        textEdit_2 = new QTextEdit(groupBox);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        sizePolicy.setHeightForWidth(textEdit_2->sizePolicy().hasHeightForWidth());
        textEdit_2->setSizePolicy(sizePolicy);
        textEdit_2->setMinimumSize(QSize(0, 30));

        horizontalLayout_4->addWidget(textEdit_2);


        gridLayout_2->addLayout(horizontalLayout_4, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(widget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(230, 0));
        groupBox_4->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(5);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(5, 5, 5, 5);
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(0, 35));

        horizontalLayout_8->addWidget(label_7);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(0, 35));

        horizontalLayout_8->addWidget(label_8);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_8);

        SP_FormDetail = new QGroupBox(groupBox_4);
        SP_FormDetail->setObjectName(QString::fromUtf8("SP_FormDetail"));
        gridLayout_7 = new QGridLayout(SP_FormDetail);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setHorizontalSpacing(6);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(5);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(5, 5, 5, 5);
        label_11 = new QLabel(SP_FormDetail);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(0, 30));

        horizontalLayout_9->addWidget(label_11);

        label_12 = new QLabel(SP_FormDetail);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(0, 30));

        horizontalLayout_9->addWidget(label_12);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_6);


        gridLayout_6->addLayout(horizontalLayout_9, 3, 0, 1, 1);

        label_9 = new QLabel(SP_FormDetail);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(0, 35));

        gridLayout_6->addWidget(label_9, 1, 0, 1, 1);

        label_10 = new QLabel(SP_FormDetail);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(0, 35));

        gridLayout_6->addWidget(label_10, 2, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(5);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(5, 5, 5, 5);
        label_13 = new QLabel(SP_FormDetail);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(0, 30));

        horizontalLayout_10->addWidget(label_13);

        label_14 = new QLabel(SP_FormDetail);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(0, 30));

        horizontalLayout_10->addWidget(label_14);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_7);


        gridLayout_6->addLayout(horizontalLayout_10, 4, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 0, 0, 1, 1);


        verticalLayout_3->addWidget(SP_FormDetail);


        gridLayout->addWidget(groupBox_4, 2, 0, 1, 1);


        horizontalLayout->addWidget(widget);

        widget_2 = new QWidget(AddPattern);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("QFrame{\n"
"    font-family: Microsoft YaHei Light;\n"
"    background-color: white;\n"
"    font: 'FangSong_GB2312';\n"
"    font-size: 12px;\n"
"}\n"
"\n"
"QFrame{\n"
"     background-color:white;/*\350\203\214\346\231\257\350\211\262*/\n"
"}\n"
"\n"
"QFrame[objectName='frameMuneBar']{\n"
"     background-color: #0e8fe3;\n"
"}"));
        gridLayout_4 = new QGridLayout(widget_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox_3 = new QGroupBox(widget_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(600, 503));
        gridLayout_5 = new QGridLayout(groupBox_3);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(250, 250));

        gridLayout_5->addWidget(label, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer, 2, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_2, 0, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 0, 0, 1, 1);

        groupBox_5 = new QGroupBox(widget_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_5);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_9);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_10);

        BTN_Left = new QToolButton(groupBox_5);
        BTN_Left->setObjectName(QString::fromUtf8("BTN_Left"));
        BTN_Left->setMinimumSize(QSize(50, 40));

        horizontalLayout_2->addWidget(BTN_Left);

        BTN_Right = new QToolButton(groupBox_5);
        BTN_Right->setObjectName(QString::fromUtf8("BTN_Right"));
        BTN_Right->setMinimumSize(QSize(50, 40));

        horizontalLayout_2->addWidget(BTN_Right);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);

        BTN_Comfirm = new QToolButton(groupBox_5);
        BTN_Comfirm->setObjectName(QString::fromUtf8("BTN_Comfirm"));
        BTN_Comfirm->setMinimumSize(QSize(112, 40));

        horizontalLayout_2->addWidget(BTN_Comfirm);


        gridLayout_4->addWidget(groupBox_5, 1, 0, 1, 1);


        horizontalLayout->addWidget(widget_2);


        gridLayout_8->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(AddPattern);
        QObject::connect(BTN_AddPatternFromFile, SIGNAL(clicked()), AddPattern, SLOT(BTN_AddPatternFromFile_Click()));
        QObject::connect(BTN_AddPatternFromDevice, SIGNAL(clicked()), AddPattern, SLOT(BTN_AddPatternFromDevice_Click()));
        QObject::connect(BTN_AddPatternFromWord, SIGNAL(clicked()), AddPattern, SLOT(BTN_AddPatternFromWord_Click()));
        QObject::connect(BTN_AddPatternFromPDF, SIGNAL(clicked()), AddPattern, SLOT(BTN_AddPatternFromPDF_Click()));
        QObject::connect(BTN_Comfirm, SIGNAL(clicked()), AddPattern, SLOT(BTN_Comfirm_Click()));
        QObject::connect(BTN_Left, SIGNAL(clicked()), AddPattern, SLOT(BTN_Left_Click()));
        QObject::connect(BTN_Right, SIGNAL(clicked()), AddPattern, SLOT(BTN_Right_Click()));

        QMetaObject::connectSlotsByName(AddPattern);
    } // setupUi

    void retranslateUi(QWidget *AddPattern)
    {
        AddPattern->setWindowTitle(QApplication::translate("AddPattern", "AddPattern", nullptr));
        groupBox_2->setTitle(QString());
        label_5->setText(QApplication::translate("AddPattern", "Icon", nullptr));
        label_6->setText(QApplication::translate("AddPattern", "\345\267\262\350\216\267\345\217\226\346\226\207\344\273\266", nullptr));
        textEdit_3->setHtml(QApplication::translate("AddPattern", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei 53'; font-size:12px; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        groupBox->setTitle(QString());
        label_3->setText(QApplication::translate("AddPattern", "Icon", nullptr));
        label_4->setText(QApplication::translate("AddPattern", "\345\233\276\345\203\217\346\226\207\344\273\266", nullptr));
        BTN_AddPatternFromDevice->setText(QApplication::translate("AddPattern", "\350\216\267\345\217\226\345\233\276\345\203\217\346\226\207\344\273\266", nullptr));
        BTN_AddPatternFromPDF->setText(QApplication::translate("AddPattern", "\351\200\211\346\213\251PDF\346\250\241\346\235\277", nullptr));
        BTN_AddPatternFromWord->setText(QApplication::translate("AddPattern", "\351\200\211\346\213\251word\346\250\241\346\235\277", nullptr));
        BTN_AddPatternFromFile->setText(QApplication::translate("AddPattern", "\351\200\211\346\213\251\345\233\276\345\203\217\346\226\207\344\273\266", nullptr));
        label_2->setText(QApplication::translate("AddPattern", "\351\230\210\345\200\274\357\274\232", nullptr));
        textEdit_2->setHtml(QApplication::translate("AddPattern", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei 53'; font-size:12px; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12px;\">0</span></p></body></html>", nullptr));
        groupBox_4->setTitle(QString());
        label_7->setText(QApplication::translate("AddPattern", "Icon", nullptr));
        label_8->setText(QApplication::translate("AddPattern", "\350\257\246\347\273\206\344\277\241\346\201\257", nullptr));
        SP_FormDetail->setTitle(QString());
        label_11->setText(QApplication::translate("AddPattern", "\346\226\207\344\273\266\345\220\215\357\274\232", nullptr));
        label_12->setText(QApplication::translate("AddPattern", ".....", nullptr));
        label_9->setText(QApplication::translate("AddPattern", "\350\241\250\345\215\225\345\220\215\347\247\260\357\274\232", nullptr));
        label_10->setText(QApplication::translate("AddPattern", "FormName\357\274\232", nullptr));
        label_13->setText(QApplication::translate("AddPattern", "\347\261\273\345\236\213\357\274\232", nullptr));
        label_14->setText(QApplication::translate("AddPattern", "....", nullptr));
        groupBox_3->setTitle(QString());
        label->setText(QApplication::translate("AddPattern", "TextLabel", nullptr));
        groupBox_5->setTitle(QString());
        BTN_Left->setText(QApplication::translate("AddPattern", "\345\267\246", nullptr));
        BTN_Right->setText(QApplication::translate("AddPattern", "\345\217\263", nullptr));
        BTN_Comfirm->setText(QApplication::translate("AddPattern", "\345\256\214\346\210\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPattern: public Ui_AddPattern {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPATTERN_H
