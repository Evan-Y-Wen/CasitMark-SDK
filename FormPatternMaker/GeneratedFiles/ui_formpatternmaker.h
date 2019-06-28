/********************************************************************************
** Form generated from reading UI file 'formpatternmaker.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPATTERNMAKER_H
#define UI_FORMPATTERNMAKER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormPatternMakerClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QWidget *widget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QToolButton *Button_NewFile;
    QToolButton *Button_OpenFile;
    QToolButton *Button_SaveFile;
    QToolButton *Button_AddPattern;
    QToolButton *Button_AddLocationRegion;
    QToolButton *Button_AddSycnRRegion;
    QToolButton *Button_AddMark;
    QToolButton *Button_AddMarkRegion;
    QToolButton *Button_AddBarCodeRegion;
    QToolButton *Button_AddImageShotRegion;
    QToolButton *Button_Add7Region;
    QToolButton *Button_AddOCRRegion;
    QToolButton *Button_Delete;
    QToolButton *Button_Rectangle;
    QToolButton *Button_Eraser;
    QToolButton *Button_Undo;
    QToolButton *Button_Redo;
    QToolButton *Button_EditTreeView;
    QWidget *widget_1;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *L_ShowTipMessage;
    QSpacerItem *horizontalSpacer_2;
    QListView *listView;
    QWidget *widget_2;
    QGridLayout *gridLayout_5;
    QGroupBox *GroupBox_Arguments;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QFormLayout *formLayout;
    QLabel *label_8;
    QTextEdit *textEdit;
    QLabel *label_9;
    QTextEdit *textEdit_2;
    QLabel *label_10;
    QTextEdit *textEdit_3;
    QLabel *label_Msg;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *label;
    QTextEdit *TB_PatternName;
    QTreeView *TV_ShowPattern;

    void setupUi(QMainWindow *FormPatternMakerClass)
    {
        if (FormPatternMakerClass->objectName().isEmpty())
            FormPatternMakerClass->setObjectName(QString::fromUtf8("FormPatternMakerClass"));
        FormPatternMakerClass->resize(1326, 813);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FormPatternMakerClass->sizePolicy().hasHeightForWidth());
        FormPatternMakerClass->setSizePolicy(sizePolicy);
        FormPatternMakerClass->setMinimumSize(QSize(1326, 813));
        FormPatternMakerClass->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(FormPatternMakerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMinimumSize(QSize(1309, 715));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(1252, 91));
        widget->setMaximumSize(QSize(2000, 150));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Button_NewFile = new QToolButton(widget);
        Button_NewFile->setObjectName(QString::fromUtf8("Button_NewFile"));
        Button_NewFile->setMinimumSize(QSize(43, 71));
        Button_NewFile->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/Resources/Images/New.png);"));
        Button_NewFile->setIconSize(QSize(2, 2));
        Button_NewFile->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(Button_NewFile);

        Button_OpenFile = new QToolButton(widget);
        Button_OpenFile->setObjectName(QString::fromUtf8("Button_OpenFile"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Button_OpenFile->sizePolicy().hasHeightForWidth());
        Button_OpenFile->setSizePolicy(sizePolicy2);
        Button_OpenFile->setMinimumSize(QSize(43, 71));
        Button_OpenFile->setMaximumSize(QSize(100, 100));
        Button_OpenFile->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(Button_OpenFile);

        Button_SaveFile = new QToolButton(widget);
        Button_SaveFile->setObjectName(QString::fromUtf8("Button_SaveFile"));
        sizePolicy2.setHeightForWidth(Button_SaveFile->sizePolicy().hasHeightForWidth());
        Button_SaveFile->setSizePolicy(sizePolicy2);
        Button_SaveFile->setMinimumSize(QSize(43, 71));
        Button_SaveFile->setMaximumSize(QSize(100, 100));
        Button_SaveFile->setIconSize(QSize(30, 30));
        Button_SaveFile->setCheckable(false);

        horizontalLayout->addWidget(Button_SaveFile);

        Button_AddPattern = new QToolButton(widget);
        Button_AddPattern->setObjectName(QString::fromUtf8("Button_AddPattern"));
        sizePolicy2.setHeightForWidth(Button_AddPattern->sizePolicy().hasHeightForWidth());
        Button_AddPattern->setSizePolicy(sizePolicy2);
        Button_AddPattern->setMinimumSize(QSize(43, 71));
        Button_AddPattern->setMaximumSize(QSize(100, 100));
        Button_AddPattern->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(Button_AddPattern);

        Button_AddLocationRegion = new QToolButton(widget);
        Button_AddLocationRegion->setObjectName(QString::fromUtf8("Button_AddLocationRegion"));
        sizePolicy2.setHeightForWidth(Button_AddLocationRegion->sizePolicy().hasHeightForWidth());
        Button_AddLocationRegion->setSizePolicy(sizePolicy2);
        Button_AddLocationRegion->setMinimumSize(QSize(43, 71));
        Button_AddLocationRegion->setMaximumSize(QSize(100, 100));
        Button_AddLocationRegion->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(Button_AddLocationRegion);

        Button_AddSycnRRegion = new QToolButton(widget);
        Button_AddSycnRRegion->setObjectName(QString::fromUtf8("Button_AddSycnRRegion"));
        sizePolicy2.setHeightForWidth(Button_AddSycnRRegion->sizePolicy().hasHeightForWidth());
        Button_AddSycnRRegion->setSizePolicy(sizePolicy2);
        Button_AddSycnRRegion->setMinimumSize(QSize(43, 71));
        Button_AddSycnRRegion->setMaximumSize(QSize(100, 100));
        Button_AddSycnRRegion->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(Button_AddSycnRRegion);

        Button_AddMark = new QToolButton(widget);
        Button_AddMark->setObjectName(QString::fromUtf8("Button_AddMark"));
        sizePolicy2.setHeightForWidth(Button_AddMark->sizePolicy().hasHeightForWidth());
        Button_AddMark->setSizePolicy(sizePolicy2);
        Button_AddMark->setMinimumSize(QSize(43, 71));
        Button_AddMark->setMaximumSize(QSize(100, 100));
        Button_AddMark->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(Button_AddMark);

        Button_AddMarkRegion = new QToolButton(widget);
        Button_AddMarkRegion->setObjectName(QString::fromUtf8("Button_AddMarkRegion"));
        sizePolicy2.setHeightForWidth(Button_AddMarkRegion->sizePolicy().hasHeightForWidth());
        Button_AddMarkRegion->setSizePolicy(sizePolicy2);
        Button_AddMarkRegion->setMinimumSize(QSize(43, 71));
        Button_AddMarkRegion->setMaximumSize(QSize(100, 100));
        Button_AddMarkRegion->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(Button_AddMarkRegion);

        Button_AddBarCodeRegion = new QToolButton(widget);
        Button_AddBarCodeRegion->setObjectName(QString::fromUtf8("Button_AddBarCodeRegion"));
        sizePolicy2.setHeightForWidth(Button_AddBarCodeRegion->sizePolicy().hasHeightForWidth());
        Button_AddBarCodeRegion->setSizePolicy(sizePolicy2);
        Button_AddBarCodeRegion->setMinimumSize(QSize(43, 71));
        Button_AddBarCodeRegion->setMaximumSize(QSize(100, 100));
        Button_AddBarCodeRegion->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(Button_AddBarCodeRegion);

        Button_AddImageShotRegion = new QToolButton(widget);
        Button_AddImageShotRegion->setObjectName(QString::fromUtf8("Button_AddImageShotRegion"));
        sizePolicy2.setHeightForWidth(Button_AddImageShotRegion->sizePolicy().hasHeightForWidth());
        Button_AddImageShotRegion->setSizePolicy(sizePolicy2);
        Button_AddImageShotRegion->setMinimumSize(QSize(43, 71));
        Button_AddImageShotRegion->setMaximumSize(QSize(100, 100));
        Button_AddImageShotRegion->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(Button_AddImageShotRegion);

        Button_Add7Region = new QToolButton(widget);
        Button_Add7Region->setObjectName(QString::fromUtf8("Button_Add7Region"));
        sizePolicy2.setHeightForWidth(Button_Add7Region->sizePolicy().hasHeightForWidth());
        Button_Add7Region->setSizePolicy(sizePolicy2);
        Button_Add7Region->setMinimumSize(QSize(43, 71));
        Button_Add7Region->setMaximumSize(QSize(100, 100));
        Button_Add7Region->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(Button_Add7Region);

        Button_AddOCRRegion = new QToolButton(widget);
        Button_AddOCRRegion->setObjectName(QString::fromUtf8("Button_AddOCRRegion"));
        sizePolicy2.setHeightForWidth(Button_AddOCRRegion->sizePolicy().hasHeightForWidth());
        Button_AddOCRRegion->setSizePolicy(sizePolicy2);
        Button_AddOCRRegion->setMinimumSize(QSize(43, 71));
        Button_AddOCRRegion->setMaximumSize(QSize(100, 100));
        Button_AddOCRRegion->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(Button_AddOCRRegion);

        Button_Delete = new QToolButton(widget);
        Button_Delete->setObjectName(QString::fromUtf8("Button_Delete"));
        sizePolicy2.setHeightForWidth(Button_Delete->sizePolicy().hasHeightForWidth());
        Button_Delete->setSizePolicy(sizePolicy2);
        Button_Delete->setMinimumSize(QSize(43, 71));
        Button_Delete->setMaximumSize(QSize(100, 100));
        Button_Delete->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(Button_Delete);

        Button_Rectangle = new QToolButton(widget);
        Button_Rectangle->setObjectName(QString::fromUtf8("Button_Rectangle"));
        sizePolicy2.setHeightForWidth(Button_Rectangle->sizePolicy().hasHeightForWidth());
        Button_Rectangle->setSizePolicy(sizePolicy2);
        Button_Rectangle->setMinimumSize(QSize(43, 71));
        Button_Rectangle->setMaximumSize(QSize(100, 100));
        Button_Rectangle->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(Button_Rectangle);

        Button_Eraser = new QToolButton(widget);
        Button_Eraser->setObjectName(QString::fromUtf8("Button_Eraser"));
        sizePolicy2.setHeightForWidth(Button_Eraser->sizePolicy().hasHeightForWidth());
        Button_Eraser->setSizePolicy(sizePolicy2);
        Button_Eraser->setMinimumSize(QSize(43, 71));
        Button_Eraser->setMaximumSize(QSize(100, 100));
        Button_Eraser->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(Button_Eraser);

        Button_Undo = new QToolButton(widget);
        Button_Undo->setObjectName(QString::fromUtf8("Button_Undo"));
        sizePolicy2.setHeightForWidth(Button_Undo->sizePolicy().hasHeightForWidth());
        Button_Undo->setSizePolicy(sizePolicy2);
        Button_Undo->setMinimumSize(QSize(43, 71));
        Button_Undo->setMaximumSize(QSize(100, 100));
        Button_Undo->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(Button_Undo);

        Button_Redo = new QToolButton(widget);
        Button_Redo->setObjectName(QString::fromUtf8("Button_Redo"));
        sizePolicy2.setHeightForWidth(Button_Redo->sizePolicy().hasHeightForWidth());
        Button_Redo->setSizePolicy(sizePolicy2);
        Button_Redo->setMinimumSize(QSize(43, 71));
        Button_Redo->setMaximumSize(QSize(100, 100));
        Button_Redo->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(Button_Redo);

        Button_EditTreeView = new QToolButton(widget);
        Button_EditTreeView->setObjectName(QString::fromUtf8("Button_EditTreeView"));
        sizePolicy2.setHeightForWidth(Button_EditTreeView->sizePolicy().hasHeightForWidth());
        Button_EditTreeView->setSizePolicy(sizePolicy2);
        Button_EditTreeView->setMinimumSize(QSize(43, 71));
        Button_EditTreeView->setMaximumSize(QSize(100, 100));
        Button_EditTreeView->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(Button_EditTreeView);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_3->addWidget(widget, 0, 0, 1, 2);

        widget_1 = new QWidget(centralWidget);
        widget_1->setObjectName(QString::fromUtf8("widget_1"));
        widget_1->setMinimumSize(QSize(1000, 601));
        gridLayout_4 = new QGridLayout(widget_1);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox_3 = new QGroupBox(widget_1);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(6, -1, 6, -1);
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(0, 40));
        label_5->setMaximumSize(QSize(16777215, 40));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_5);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(0, 40));
        label_6->setMaximumSize(QSize(16777215, 40));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_6);

        L_ShowTipMessage = new QLabel(groupBox_3);
        L_ShowTipMessage->setObjectName(QString::fromUtf8("L_ShowTipMessage"));
        L_ShowTipMessage->setMinimumSize(QSize(400, 40));
        L_ShowTipMessage->setMaximumSize(QSize(16777215, 40));
        L_ShowTipMessage->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(L_ShowTipMessage);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_4);

        listView = new QListView(groupBox_3);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout_4->addWidget(listView);


        gridLayout_4->addWidget(groupBox_3, 0, 0, 1, 1);


        gridLayout_3->addWidget(widget_1, 1, 1, 1, 1);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(300, 601));
        widget_2->setMaximumSize(QSize(1000, 1000));
        gridLayout_5 = new QGridLayout(widget_2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        GroupBox_Arguments = new QGroupBox(widget_2);
        GroupBox_Arguments->setObjectName(QString::fromUtf8("GroupBox_Arguments"));
        GroupBox_Arguments->setMinimumSize(QSize(0, 0));
        verticalLayout_3 = new QVBoxLayout(GroupBox_Arguments);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(6, -1, 6, -1);
        label_3 = new QLabel(GroupBox_Arguments);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(30, 40));
        label_3->setMaximumSize(QSize(40, 16777215));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_3);

        label_4 = new QLabel(GroupBox_Arguments);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(40, 40));
        label_4->setMaximumSize(QSize(40, 16777215));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_2);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setVerticalSpacing(4);
        formLayout->setContentsMargins(6, -1, 6, -1);
        label_8 = new QLabel(GroupBox_Arguments);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(50, 30));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_8);

        textEdit = new QTextEdit(GroupBox_Arguments);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMinimumSize(QSize(0, 30));

        formLayout->setWidget(0, QFormLayout::FieldRole, textEdit);

        label_9 = new QLabel(GroupBox_Arguments);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(0, 30));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_9);

        textEdit_2 = new QTextEdit(GroupBox_Arguments);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setMinimumSize(QSize(0, 30));

        formLayout->setWidget(1, QFormLayout::FieldRole, textEdit_2);

        label_10 = new QLabel(GroupBox_Arguments);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(0, 30));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_10);

        textEdit_3 = new QTextEdit(GroupBox_Arguments);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setMinimumSize(QSize(0, 30));

        formLayout->setWidget(2, QFormLayout::FieldRole, textEdit_3);

        label_Msg = new QLabel(GroupBox_Arguments);
        label_Msg->setObjectName(QString::fromUtf8("label_Msg"));
        label_Msg->setMinimumSize(QSize(0, 30));

        formLayout->setWidget(3, QFormLayout::SpanningRole, label_Msg);


        verticalLayout_3->addLayout(formLayout);


        gridLayout_5->addWidget(GroupBox_Arguments, 1, 0, 1, 2);

        groupBox = new QGroupBox(widget_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 0));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(6, -1, 6, -1);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(30, 40));
        label_2->setMaximumSize(QSize(40, 40));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_2);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(50, 40));
        label->setMaximumSize(QSize(40, 40));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label);

        TB_PatternName = new QTextEdit(groupBox);
        TB_PatternName->setObjectName(QString::fromUtf8("TB_PatternName"));
        TB_PatternName->setMinimumSize(QSize(0, 40));

        horizontalLayout_3->addWidget(TB_PatternName);


        verticalLayout_2->addLayout(horizontalLayout_3);

        TV_ShowPattern = new QTreeView(groupBox);
        TV_ShowPattern->setObjectName(QString::fromUtf8("TV_ShowPattern"));
        TV_ShowPattern->setMinimumSize(QSize(0, 400));

        verticalLayout_2->addWidget(TV_ShowPattern);


        gridLayout_5->addWidget(groupBox, 0, 0, 1, 2);


        gridLayout_3->addWidget(widget_2, 1, 0, 1, 1);

        FormPatternMakerClass->setCentralWidget(centralWidget);

        retranslateUi(FormPatternMakerClass);
        QObject::connect(Button_OpenFile, SIGNAL(clicked()), FormPatternMakerClass, SLOT(Button_OpenFile_Click()));
        QObject::connect(Button_SaveFile, SIGNAL(clicked()), FormPatternMakerClass, SLOT(Button_SaveFile_Click()));
        QObject::connect(Button_AddPattern, SIGNAL(clicked()), FormPatternMakerClass, SLOT(Button_AddPattern_Click()));
        QObject::connect(Button_NewFile, SIGNAL(clicked()), FormPatternMakerClass, SLOT(Button_NewFile_Click()));

        QMetaObject::connectSlotsByName(FormPatternMakerClass);
    } // setupUi

    void retranslateUi(QMainWindow *FormPatternMakerClass)
    {
        FormPatternMakerClass->setWindowTitle(QApplication::translate("FormPatternMakerClass", "FormPatternMaker", nullptr));
        Button_NewFile->setText(QApplication::translate("FormPatternMakerClass", "\346\226\260\345\273\272\346\250\241\345\274\217", nullptr));
        Button_OpenFile->setText(QApplication::translate("FormPatternMakerClass", "\346\211\223\345\274\200\346\250\241\345\274\217", nullptr));
        Button_SaveFile->setText(QApplication::translate("FormPatternMakerClass", "\344\277\235\345\255\230\346\250\241\345\274\217", nullptr));
        Button_AddPattern->setText(QApplication::translate("FormPatternMakerClass", "\346\267\273\345\212\240\346\250\241\346\235\277", nullptr));
        Button_AddLocationRegion->setText(QApplication::translate("FormPatternMakerClass", "\346\241\206\351\200\211\345\256\232\344\275\215", nullptr));
        Button_AddSycnRRegion->setText(QApplication::translate("FormPatternMakerClass", "\346\241\206\351\200\211\345\220\214\346\255\245\351\201\223", nullptr));
        Button_AddMark->setText(QApplication::translate("FormPatternMakerClass", "\346\241\206\351\200\211\346\240\207\345\207\206\346\241\206", nullptr));
        Button_AddMarkRegion->setText(QApplication::translate("FormPatternMakerClass", "\346\241\206\351\200\211\345\241\253\346\266\202", nullptr));
        Button_AddBarCodeRegion->setText(QApplication::translate("FormPatternMakerClass", "\346\241\206\351\200\211\346\235\241\347\240\201", nullptr));
        Button_AddImageShotRegion->setText(QApplication::translate("FormPatternMakerClass", "\346\241\206\351\200\211\346\210\252\345\233\276", nullptr));
        Button_Add7Region->setText(QApplication::translate("FormPatternMakerClass", "\346\241\206\351\200\211\344\270\203\346\256\265\347\240\201", nullptr));
        Button_AddOCRRegion->setText(QApplication::translate("FormPatternMakerClass", "\346\241\206\351\200\211\345\255\227\347\254\246", nullptr));
        Button_Delete->setText(QApplication::translate("FormPatternMakerClass", "\345\210\240\351\231\244\350\212\202\347\202\271", nullptr));
        Button_Rectangle->setText(QApplication::translate("FormPatternMakerClass", "\347\224\273\346\241\206", nullptr));
        Button_Eraser->setText(QApplication::translate("FormPatternMakerClass", "\346\223\246\351\231\244", nullptr));
        Button_Undo->setText(QApplication::translate("FormPatternMakerClass", "\346\222\244\351\224\200", nullptr));
        Button_Redo->setText(QApplication::translate("FormPatternMakerClass", "\351\207\215\345\201\232", nullptr));
        Button_EditTreeView->setText(QApplication::translate("FormPatternMakerClass", "\347\274\226\350\276\221\346\250\241\345\274\217", nullptr));
        groupBox_3->setTitle(QString());
        label_5->setText(QApplication::translate("FormPatternMakerClass", "\345\233\276\347\211\207\346\224\276\347\275\256", nullptr));
        label_6->setText(QApplication::translate("FormPatternMakerClass", "\346\250\241\345\274\217\347\273\223\346\236\204", nullptr));
        L_ShowTipMessage->setText(QApplication::translate("FormPatternMakerClass", "Tips", nullptr));
        GroupBox_Arguments->setTitle(QString());
        label_3->setText(QApplication::translate("FormPatternMakerClass", "ICon", nullptr));
        label_4->setText(QApplication::translate("FormPatternMakerClass", "\345\261\236\346\200\247", nullptr));
        label_8->setText(QApplication::translate("FormPatternMakerClass", "\345\220\215\347\247\260", nullptr));
        label_9->setText(QString());
        label_10->setText(QString());
        label_Msg->setText(QApplication::translate("FormPatternMakerClass", "label_Msg", nullptr));
        groupBox->setTitle(QString());
        label_2->setText(QApplication::translate("FormPatternMakerClass", "ICon", nullptr));
        label->setText(QApplication::translate("FormPatternMakerClass", "\346\250\241\345\274\217\347\273\223\346\236\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormPatternMakerClass: public Ui_FormPatternMakerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPATTERNMAKER_H
