/********************************************************************************
** Form generated from reading UI file 'formimagegetter.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMIMAGEGETTER_H
#define UI_FORMIMAGEGETTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormImageGetterClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QSplitter *splitter;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_10;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_11;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *TextBox_ImageFileNamePrefix;
    QLabel *label_2;
    QComboBox *ComboBox_ImageType;
    QGroupBox *groupBox_12;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *Button_SelectFolder;
    QGroupBox *groupBox_13;
    QHBoxLayout *horizontalLayout_4;
    QTextEdit *TextBox_ImageSaveFolder;
    QFrame *line_4;
    QGroupBox *GroupBox_Scanner;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_15;
    QGridLayout *gridLayout;
    QPushButton *Button_ScannerStart1;
    QLabel *label_4;
    QComboBox *ComboBox_Position;
    QLabel *label_6;
    QPushButton *Button_ScannerContinue1;
    QLabel *Label_Pages1;
    QLabel *label_5;
    QLabel *label_7;
    QComboBox *ComboBox_Light;
    QComboBox *ComboBox_DeviceCount;
    QCheckBox *CheckBox_IsRectify;
    QFrame *line_5;
    QGroupBox *GroupBox_TWAIN;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_18;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *Button_TwainSelect;
    QPushButton *Button_TwainConfig;
    QPushButton *Button_TwainControl;
    QFrame *line_6;
    QGroupBox *groupBox_17;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_19;
    QGridLayout *gridLayout_2;
    QLabel *label_14;
    QLabel *Label_FileName;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_13;
    QLabel *label_16;
    QLabel *Label_ImageFolder;
    QLabel *label_11;
    QLabel *Label_ImageSize;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_4;
    QLabel *Label_FileSize;
    QLabel *Label_ImageType;
    QSpacerItem *verticalSpacer_5;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_5;
    QGraphicsView *graphicsView;
    QFrame *frame_1;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_ListTitle;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *groupBox_image1;
    QGridLayout *gridLayout_6;
    QLabel *label_8;
    QRadioButton *radioButton_image1;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_9;
    QGroupBox *groupBox_image2;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_image2;
    QLabel *label_12;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer_8;
    QGroupBox *groupBox_image3;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *radioButton_image3;
    QLabel *label_17;
    QLabel *label_18;
    QSpacerItem *horizontalSpacer_9;
    QGroupBox *groupBox_image4;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *radioButton_image4;
    QLabel *label_19;
    QLabel *label_20;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *FormImageGetterClass)
    {
        if (FormImageGetterClass->objectName().isEmpty())
            FormImageGetterClass->setObjectName(QString::fromUtf8("FormImageGetterClass"));
        FormImageGetterClass->resize(1470, 790);
        FormImageGetterClass->setMinimumSize(QSize(0, 790));
        centralWidget = new QWidget(FormImageGetterClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMinimumSize(QSize(1470, 790));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setMinimumSize(QSize(1452, 772));
        splitter->setFrameShape(QFrame::Panel);
        splitter->setOrientation(Qt::Horizontal);
        frame_2 = new QFrame(splitter);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setMinimumSize(QSize(370, 700));
        frame_2->setMaximumSize(QSize(370, 16777215));
        frame_2->setFrameShape(QFrame::Panel);
        verticalLayout_5 = new QVBoxLayout(frame_2);
        verticalLayout_5->setSpacing(18);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox_10 = new QGroupBox(frame_2);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setMinimumSize(QSize(351, 191));
        verticalLayout = new QVBoxLayout(groupBox_10);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_11 = new QGroupBox(groupBox_10);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        groupBox_11->setMinimumSize(QSize(0, 50));
        horizontalLayout_2 = new QHBoxLayout(groupBox_11);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(groupBox_11);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        TextBox_ImageFileNamePrefix = new QLineEdit(groupBox_11);
        TextBox_ImageFileNamePrefix->setObjectName(QString::fromUtf8("TextBox_ImageFileNamePrefix"));
        sizePolicy.setHeightForWidth(TextBox_ImageFileNamePrefix->sizePolicy().hasHeightForWidth());
        TextBox_ImageFileNamePrefix->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(TextBox_ImageFileNamePrefix);

        label_2 = new QLabel(groupBox_11);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        ComboBox_ImageType = new QComboBox(groupBox_11);
        ComboBox_ImageType->addItem(QString());
        ComboBox_ImageType->addItem(QString());
        ComboBox_ImageType->addItem(QString());
        ComboBox_ImageType->addItem(QString());
        ComboBox_ImageType->setObjectName(QString::fromUtf8("ComboBox_ImageType"));
        sizePolicy.setHeightForWidth(ComboBox_ImageType->sizePolicy().hasHeightForWidth());
        ComboBox_ImageType->setSizePolicy(sizePolicy);
        ComboBox_ImageType->setMinimumSize(QSize(70, 0));
        ComboBox_ImageType->setLayoutDirection(Qt::LeftToRight);
        ComboBox_ImageType->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\256\213\344\275\223\";"));

        horizontalLayout_2->addWidget(ComboBox_ImageType);


        verticalLayout->addWidget(groupBox_11);

        groupBox_12 = new QGroupBox(groupBox_10);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        groupBox_12->setMinimumSize(QSize(0, 50));
        horizontalLayout_3 = new QHBoxLayout(groupBox_12);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox_12);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        Button_SelectFolder = new QPushButton(groupBox_12);
        Button_SelectFolder->setObjectName(QString::fromUtf8("Button_SelectFolder"));
        sizePolicy.setHeightForWidth(Button_SelectFolder->sizePolicy().hasHeightForWidth());
        Button_SelectFolder->setSizePolicy(sizePolicy);
        Button_SelectFolder->setMinimumSize(QSize(70, 30));

        horizontalLayout_3->addWidget(Button_SelectFolder);


        verticalLayout->addWidget(groupBox_12);

        groupBox_13 = new QGroupBox(groupBox_10);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        groupBox_13->setMinimumSize(QSize(0, 50));
        horizontalLayout_4 = new QHBoxLayout(groupBox_13);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        TextBox_ImageSaveFolder = new QTextEdit(groupBox_13);
        TextBox_ImageSaveFolder->setObjectName(QString::fromUtf8("TextBox_ImageSaveFolder"));
        sizePolicy.setHeightForWidth(TextBox_ImageSaveFolder->sizePolicy().hasHeightForWidth());
        TextBox_ImageSaveFolder->setSizePolicy(sizePolicy);
        TextBox_ImageSaveFolder->setMinimumSize(QSize(0, 30));
        TextBox_ImageSaveFolder->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_4->addWidget(TextBox_ImageSaveFolder);


        verticalLayout->addWidget(groupBox_13);


        verticalLayout_5->addWidget(groupBox_10);

        line_4 = new QFrame(frame_2);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_4);

        GroupBox_Scanner = new QGroupBox(frame_2);
        GroupBox_Scanner->setObjectName(QString::fromUtf8("GroupBox_Scanner"));
        GroupBox_Scanner->setMinimumSize(QSize(351, 150));
        verticalLayout_2 = new QVBoxLayout(GroupBox_Scanner);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_15 = new QGroupBox(GroupBox_Scanner);
        groupBox_15->setObjectName(QString::fromUtf8("groupBox_15"));
        groupBox_15->setMinimumSize(QSize(0, 50));
        gridLayout = new QGridLayout(groupBox_15);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(20);
        Button_ScannerStart1 = new QPushButton(groupBox_15);
        Button_ScannerStart1->setObjectName(QString::fromUtf8("Button_ScannerStart1"));
        Button_ScannerStart1->setMinimumSize(QSize(70, 30));

        gridLayout->addWidget(Button_ScannerStart1, 2, 2, 1, 1);

        label_4 = new QLabel(groupBox_15);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        ComboBox_Position = new QComboBox(groupBox_15);
        ComboBox_Position->addItem(QString());
        ComboBox_Position->addItem(QString());
        ComboBox_Position->addItem(QString());
        ComboBox_Position->setObjectName(QString::fromUtf8("ComboBox_Position"));
        sizePolicy.setHeightForWidth(ComboBox_Position->sizePolicy().hasHeightForWidth());
        ComboBox_Position->setSizePolicy(sizePolicy);
        ComboBox_Position->setMinimumSize(QSize(70, 30));
        ComboBox_Position->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\256\213\344\275\223\";"));

        gridLayout->addWidget(ComboBox_Position, 0, 3, 1, 1);

        label_6 = new QLabel(groupBox_15);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(label_6, 0, 2, 1, 1);

        Button_ScannerContinue1 = new QPushButton(groupBox_15);
        Button_ScannerContinue1->setObjectName(QString::fromUtf8("Button_ScannerContinue1"));
        Button_ScannerContinue1->setMinimumSize(QSize(70, 30));

        gridLayout->addWidget(Button_ScannerContinue1, 2, 3, 1, 1);

        Label_Pages1 = new QLabel(groupBox_15);
        Label_Pages1->setObjectName(QString::fromUtf8("Label_Pages1"));
        Label_Pages1->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(Label_Pages1, 2, 1, 1, 1);

        label_5 = new QLabel(groupBox_15);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        label_7 = new QLabel(groupBox_15);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        ComboBox_Light = new QComboBox(groupBox_15);
        ComboBox_Light->addItem(QString());
        ComboBox_Light->addItem(QString());
        ComboBox_Light->addItem(QString());
        ComboBox_Light->addItem(QString());
        ComboBox_Light->setObjectName(QString::fromUtf8("ComboBox_Light"));
        sizePolicy.setHeightForWidth(ComboBox_Light->sizePolicy().hasHeightForWidth());
        ComboBox_Light->setSizePolicy(sizePolicy);
        ComboBox_Light->setMinimumSize(QSize(70, 30));
        ComboBox_Light->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\256\213\344\275\223\";"));

        gridLayout->addWidget(ComboBox_Light, 1, 1, 1, 1);

        ComboBox_DeviceCount = new QComboBox(groupBox_15);
        ComboBox_DeviceCount->addItem(QString());
        ComboBox_DeviceCount->addItem(QString());
        ComboBox_DeviceCount->setObjectName(QString::fromUtf8("ComboBox_DeviceCount"));
        sizePolicy.setHeightForWidth(ComboBox_DeviceCount->sizePolicy().hasHeightForWidth());
        ComboBox_DeviceCount->setSizePolicy(sizePolicy);
        ComboBox_DeviceCount->setMinimumSize(QSize(70, 30));
        ComboBox_DeviceCount->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\256\213\344\275\223\";"));

        gridLayout->addWidget(ComboBox_DeviceCount, 0, 1, 1, 1);

        CheckBox_IsRectify = new QCheckBox(groupBox_15);
        CheckBox_IsRectify->setObjectName(QString::fromUtf8("CheckBox_IsRectify"));
        CheckBox_IsRectify->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(CheckBox_IsRectify, 1, 3, 1, 1);


        verticalLayout_2->addWidget(groupBox_15);


        verticalLayout_5->addWidget(GroupBox_Scanner);

        line_5 = new QFrame(frame_2);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_5);

        GroupBox_TWAIN = new QGroupBox(frame_2);
        GroupBox_TWAIN->setObjectName(QString::fromUtf8("GroupBox_TWAIN"));
        GroupBox_TWAIN->setMinimumSize(QSize(351, 81));
        verticalLayout_3 = new QVBoxLayout(GroupBox_TWAIN);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_18 = new QGroupBox(GroupBox_TWAIN);
        groupBox_18->setObjectName(QString::fromUtf8("groupBox_18"));
        groupBox_18->setMinimumSize(QSize(0, 50));
        horizontalLayout_6 = new QHBoxLayout(groupBox_18);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        Button_TwainSelect = new QPushButton(groupBox_18);
        Button_TwainSelect->setObjectName(QString::fromUtf8("Button_TwainSelect"));
        Button_TwainSelect->setMinimumSize(QSize(0, 30));

        horizontalLayout_6->addWidget(Button_TwainSelect);

        Button_TwainConfig = new QPushButton(groupBox_18);
        Button_TwainConfig->setObjectName(QString::fromUtf8("Button_TwainConfig"));
        Button_TwainConfig->setMinimumSize(QSize(0, 30));

        horizontalLayout_6->addWidget(Button_TwainConfig);

        Button_TwainControl = new QPushButton(groupBox_18);
        Button_TwainControl->setObjectName(QString::fromUtf8("Button_TwainControl"));
        Button_TwainControl->setMinimumSize(QSize(0, 30));

        horizontalLayout_6->addWidget(Button_TwainControl);


        verticalLayout_3->addWidget(groupBox_18);


        verticalLayout_5->addWidget(GroupBox_TWAIN);

        line_6 = new QFrame(frame_2);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_6);

        groupBox_17 = new QGroupBox(frame_2);
        groupBox_17->setObjectName(QString::fromUtf8("groupBox_17"));
        groupBox_17->setMinimumSize(QSize(351, 0));
        verticalLayout_4 = new QVBoxLayout(groupBox_17);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox_19 = new QGroupBox(groupBox_17);
        groupBox_19->setObjectName(QString::fromUtf8("groupBox_19"));
        groupBox_19->setMinimumSize(QSize(0, 50));
        gridLayout_2 = new QGridLayout(groupBox_19);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(6);
        label_14 = new QLabel(groupBox_19);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(60, 30));

        gridLayout_2->addWidget(label_14, 3, 0, 1, 1);

        Label_FileName = new QLabel(groupBox_19);
        Label_FileName->setObjectName(QString::fromUtf8("Label_FileName"));
        Label_FileName->setMinimumSize(QSize(100, 30));

        gridLayout_2->addWidget(Label_FileName, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 3, 1, 1);

        label_10 = new QLabel(groupBox_19);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(60, 30));

        gridLayout_2->addWidget(label_10, 1, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 4, 3, 1, 1);

        label_13 = new QLabel(groupBox_19);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(60, 30));

        gridLayout_2->addWidget(label_13, 0, 0, 1, 1);

        label_16 = new QLabel(groupBox_19);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMinimumSize(QSize(60, 30));

        gridLayout_2->addWidget(label_16, 4, 0, 1, 1);

        Label_ImageFolder = new QLabel(groupBox_19);
        Label_ImageFolder->setObjectName(QString::fromUtf8("Label_ImageFolder"));
        Label_ImageFolder->setMinimumSize(QSize(100, 30));

        gridLayout_2->addWidget(Label_ImageFolder, 3, 2, 1, 1);

        label_11 = new QLabel(groupBox_19);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(60, 30));

        gridLayout_2->addWidget(label_11, 2, 0, 1, 1);

        Label_ImageSize = new QLabel(groupBox_19);
        Label_ImageSize->setObjectName(QString::fromUtf8("Label_ImageSize"));
        Label_ImageSize->setMinimumSize(QSize(100, 30));

        gridLayout_2->addWidget(Label_ImageSize, 2, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 3, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 2, 3, 1, 1);

        Label_FileSize = new QLabel(groupBox_19);
        Label_FileSize->setObjectName(QString::fromUtf8("Label_FileSize"));
        Label_FileSize->setMinimumSize(QSize(100, 30));

        gridLayout_2->addWidget(Label_FileSize, 4, 2, 1, 1);

        Label_ImageType = new QLabel(groupBox_19);
        Label_ImageType->setObjectName(QString::fromUtf8("Label_ImageType"));
        Label_ImageType->setMinimumSize(QSize(100, 30));

        gridLayout_2->addWidget(Label_ImageType, 1, 2, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 5, 2, 1, 1);


        verticalLayout_4->addWidget(groupBox_19);


        verticalLayout_5->addWidget(groupBox_17);

        splitter->addWidget(frame_2);
        frame_3 = new QFrame(splitter);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy1);
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
        scrollArea = new QScrollArea(groupBox_2);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 778, 716));
        gridLayout_5 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        graphicsView = new QGraphicsView(scrollAreaWidgetContents);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout_5->addWidget(graphicsView, 0, 1, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_4->addWidget(scrollArea, 0, 0, 1, 1);


        verticalLayout_7->addWidget(groupBox_2);

        splitter->addWidget(frame_3);
        frame_1 = new QFrame(splitter);
        frame_1->setObjectName(QString::fromUtf8("frame_1"));
        sizePolicy.setHeightForWidth(frame_1->sizePolicy().hasHeightForWidth());
        frame_1->setSizePolicy(sizePolicy);
        frame_1->setMinimumSize(QSize(250, 0));
        frame_1->setMaximumSize(QSize(250, 16777215));
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
        groupBox_image1 = new QGroupBox(groupBox_ListTitle);
        groupBox_image1->setObjectName(QString::fromUtf8("groupBox_image1"));
        gridLayout_6 = new QGridLayout(groupBox_image1);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setVerticalSpacing(10);
        label_8 = new QLabel(groupBox_image1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_6->addWidget(label_8, 0, 1, 1, 1);

        radioButton_image1 = new QRadioButton(groupBox_image1);
        radioButton_image1->setObjectName(QString::fromUtf8("radioButton_image1"));
        radioButton_image1->setMinimumSize(QSize(20, 0));

        gridLayout_6->addWidget(radioButton_image1, 0, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_7, 0, 3, 1, 1);

        label_9 = new QLabel(groupBox_image1);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_6->addWidget(label_9, 0, 2, 1, 1);


        verticalLayout_8->addWidget(groupBox_image1);

        groupBox_image2 = new QGroupBox(groupBox_ListTitle);
        groupBox_image2->setObjectName(QString::fromUtf8("groupBox_image2"));
        horizontalLayout = new QHBoxLayout(groupBox_image2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButton_image2 = new QRadioButton(groupBox_image2);
        radioButton_image2->setObjectName(QString::fromUtf8("radioButton_image2"));
        radioButton_image2->setMinimumSize(QSize(20, 0));

        horizontalLayout->addWidget(radioButton_image2);

        label_12 = new QLabel(groupBox_image2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout->addWidget(label_12);

        label_15 = new QLabel(groupBox_image2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout->addWidget(label_15);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);


        verticalLayout_8->addWidget(groupBox_image2);

        groupBox_image3 = new QGroupBox(groupBox_ListTitle);
        groupBox_image3->setObjectName(QString::fromUtf8("groupBox_image3"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_image3);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        radioButton_image3 = new QRadioButton(groupBox_image3);
        radioButton_image3->setObjectName(QString::fromUtf8("radioButton_image3"));
        radioButton_image3->setMinimumSize(QSize(20, 0));

        horizontalLayout_5->addWidget(radioButton_image3);

        label_17 = new QLabel(groupBox_image3);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_5->addWidget(label_17);

        label_18 = new QLabel(groupBox_image3);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_5->addWidget(label_18);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);


        verticalLayout_8->addWidget(groupBox_image3);

        groupBox_image4 = new QGroupBox(groupBox_ListTitle);
        groupBox_image4->setObjectName(QString::fromUtf8("groupBox_image4"));
        horizontalLayout_7 = new QHBoxLayout(groupBox_image4);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        radioButton_image4 = new QRadioButton(groupBox_image4);
        radioButton_image4->setObjectName(QString::fromUtf8("radioButton_image4"));
        radioButton_image4->setMinimumSize(QSize(20, 0));

        horizontalLayout_7->addWidget(radioButton_image4);

        label_19 = new QLabel(groupBox_image4);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_7->addWidget(label_19);

        label_20 = new QLabel(groupBox_image4);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_7->addWidget(label_20);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_10);


        verticalLayout_8->addWidget(groupBox_image4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);


        verticalLayout_6->addWidget(groupBox_ListTitle);

        splitter->addWidget(frame_1);

        gridLayout_3->addWidget(splitter, 0, 0, 1, 1);

        FormImageGetterClass->setCentralWidget(centralWidget);

        retranslateUi(FormImageGetterClass);
        QObject::connect(Button_SelectFolder, SIGNAL(clicked(bool)), FormImageGetterClass, SLOT(Button_SelectFolder_Click()));
        QObject::connect(Button_ScannerStart1, SIGNAL(clicked(bool)), FormImageGetterClass, SLOT(Button_ScannerStart1_Click()));
        QObject::connect(Button_ScannerContinue1, SIGNAL(clicked(bool)), FormImageGetterClass, SLOT(Button_ScannerContinue1_Click()));

        QMetaObject::connectSlotsByName(FormImageGetterClass);
    } // setupUi

    void retranslateUi(QMainWindow *FormImageGetterClass)
    {
        FormImageGetterClass->setWindowTitle(QApplication::translate("FormImageGetterClass", "FormImageGetter", nullptr));
        groupBox_10->setTitle(QApplication::translate("FormImageGetterClass", "\345\233\276\345\203\217\351\205\215\347\275\256", nullptr));
        groupBox_11->setTitle(QString());
        label->setText(QApplication::translate("FormImageGetterClass", "\345\233\276\345\203\217\346\226\207\344\273\266\345\220\215\345\211\215\347\274\200\357\274\232", nullptr));
        TextBox_ImageFileNamePrefix->setText(QApplication::translate("FormImageGetterClass", "\345\233\276\345\203\217", nullptr));
        label_2->setText(QApplication::translate("FormImageGetterClass", "\347\261\273\345\236\213:", nullptr));
        ComboBox_ImageType->setItemText(0, QApplication::translate("FormImageGetterClass", "JPG", nullptr));
        ComboBox_ImageType->setItemText(1, QApplication::translate("FormImageGetterClass", "BMP", nullptr));
        ComboBox_ImageType->setItemText(2, QApplication::translate("FormImageGetterClass", "PNG", nullptr));
        ComboBox_ImageType->setItemText(3, QApplication::translate("FormImageGetterClass", "TIFF", nullptr));

        groupBox_12->setTitle(QString());
        label_3->setText(QApplication::translate("FormImageGetterClass", "\345\233\276\345\203\217\345\255\230\345\202\250\344\275\215\347\275\256\357\274\232", nullptr));
        Button_SelectFolder->setText(QApplication::translate("FormImageGetterClass", "\346\265\217\350\247\210", nullptr));
        groupBox_13->setTitle(QString());
        TextBox_ImageSaveFolder->setHtml(QApplication::translate("FormImageGetterClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\233\276\345\203\217\346\226\207\344\273\266\345\244\271</p></body></html>", nullptr));
        GroupBox_Scanner->setTitle(QApplication::translate("FormImageGetterClass", "\351\253\230\351\200\237\351\230\205\350\257\273\344\273\252", nullptr));
        groupBox_15->setTitle(QString());
        Button_ScannerStart1->setText(QApplication::translate("FormImageGetterClass", "\345\274\200\345\247\213\351\230\205\350\257\273", nullptr));
        label_4->setText(QApplication::translate("FormImageGetterClass", "\350\256\276\345\244\207\346\225\260\351\207\217\357\274\232", nullptr));
        ComboBox_Position->setItemText(0, QApplication::translate("FormImageGetterClass", "\344\270\212\351\235\242", nullptr));
        ComboBox_Position->setItemText(1, QApplication::translate("FormImageGetterClass", "\344\270\213\351\235\242", nullptr));
        ComboBox_Position->setItemText(2, QApplication::translate("FormImageGetterClass", "\344\270\244\351\235\242", nullptr));

        label_6->setText(QApplication::translate("FormImageGetterClass", "\351\230\205\350\257\273\347\272\270\345\274\240\344\275\215", nullptr));
        Button_ScannerContinue1->setText(QApplication::translate("FormImageGetterClass", "\347\273\247\347\273\255\351\230\205\350\257\273", nullptr));
        Label_Pages1->setText(QApplication::translate("FormImageGetterClass", "0\345\274\240", nullptr));
        label_5->setText(QApplication::translate("FormImageGetterClass", "\345\205\211\346\272\220\357\274\232", nullptr));
        label_7->setText(QApplication::translate("FormImageGetterClass", "\345\233\276\345\203\217\346\225\2601\357\274\232", nullptr));
        ComboBox_Light->setItemText(0, QApplication::translate("FormImageGetterClass", "\347\272\242\345\205\211", nullptr));
        ComboBox_Light->setItemText(1, QApplication::translate("FormImageGetterClass", "\347\273\277\345\205\211", nullptr));
        ComboBox_Light->setItemText(2, QApplication::translate("FormImageGetterClass", "\350\223\235\345\205\211", nullptr));
        ComboBox_Light->setItemText(3, QApplication::translate("FormImageGetterClass", "\347\231\275\345\205\211", nullptr));

        ComboBox_DeviceCount->setItemText(0, QApplication::translate("FormImageGetterClass", "1", nullptr));
        ComboBox_DeviceCount->setItemText(1, QApplication::translate("FormImageGetterClass", "2", nullptr));

        CheckBox_IsRectify->setText(QApplication::translate("FormImageGetterClass", "\345\220\257\347\224\250\350\243\201\345\211\252", nullptr));
        GroupBox_TWAIN->setTitle(QApplication::translate("FormImageGetterClass", "TWAIN\346\211\253\346\217\217\344\273\252", nullptr));
        groupBox_18->setTitle(QString());
        Button_TwainSelect->setText(QApplication::translate("FormImageGetterClass", "\351\200\211\346\213\251\346\211\253\346\217\217\344\273\252", nullptr));
        Button_TwainConfig->setText(QApplication::translate("FormImageGetterClass", "\351\205\215\347\275\256\346\211\253\346\217\217\344\273\252", nullptr));
        Button_TwainControl->setText(QApplication::translate("FormImageGetterClass", "\346\211\253\346\217\217", nullptr));
        groupBox_17->setTitle(QApplication::translate("FormImageGetterClass", "\345\233\276\345\203\217\345\261\236\346\200\247", nullptr));
        groupBox_19->setTitle(QString());
        label_14->setText(QApplication::translate("FormImageGetterClass", "\344\275\215\347\275\256\357\274\232", nullptr));
        Label_FileName->setText(QApplication::translate("FormImageGetterClass", "\345\233\276\345\203\2172.jpg", nullptr));
        label_10->setText(QApplication::translate("FormImageGetterClass", "\347\261\273\345\236\213\357\274\232", nullptr));
        label_13->setText(QApplication::translate("FormImageGetterClass", "\346\226\207\344\273\266\345\220\215\357\274\232", nullptr));
        label_16->setText(QApplication::translate("FormImageGetterClass", "\345\244\247\345\260\217\357\274\232", nullptr));
        Label_ImageFolder->setText(QApplication::translate("FormImageGetterClass", "E:\\\345\233\276\345\203\217", nullptr));
        label_11->setText(QApplication::translate("FormImageGetterClass", "\345\260\272\345\257\270\357\274\232", nullptr));
        Label_ImageSize->setText(QApplication::translate("FormImageGetterClass", "1648 x 2356", nullptr));
        Label_FileSize->setText(QApplication::translate("FormImageGetterClass", "564KB", nullptr));
        Label_ImageType->setText(QApplication::translate("FormImageGetterClass", "JEPG", nullptr));
        groupBox_2->setTitle(QApplication::translate("FormImageGetterClass", "\345\233\276\345\203\217\346\230\276\347\244\272", nullptr));
        groupBox_ListTitle->setTitle(QApplication::translate("FormImageGetterClass", "\345\233\276\345\203\217\345\210\227\350\241\250 \346\200\273\346\225\260\357\274\2320\345\274\240", nullptr));
        groupBox_image1->setTitle(QString());
        label_8->setText(QApplication::translate("FormImageGetterClass", "ICON", nullptr));
        radioButton_image1->setText(QString());
        label_9->setText(QApplication::translate("FormImageGetterClass", "\345\233\276\345\203\2171.jpg", nullptr));
        groupBox_image2->setTitle(QString());
        radioButton_image2->setText(QString());
        label_12->setText(QApplication::translate("FormImageGetterClass", "ICON", nullptr));
        label_15->setText(QApplication::translate("FormImageGetterClass", "\345\233\276\345\203\2172.jpg", nullptr));
        groupBox_image3->setTitle(QString());
        radioButton_image3->setText(QString());
        label_17->setText(QApplication::translate("FormImageGetterClass", "ICON", nullptr));
        label_18->setText(QApplication::translate("FormImageGetterClass", "\345\233\276\345\203\2173.jpg", nullptr));
        groupBox_image4->setTitle(QString());
        radioButton_image4->setText(QString());
        label_19->setText(QApplication::translate("FormImageGetterClass", "ICON", nullptr));
        label_20->setText(QApplication::translate("FormImageGetterClass", "\345\233\276\345\203\2174.jpg", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormImageGetterClass: public Ui_FormImageGetterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMIMAGEGETTER_H
