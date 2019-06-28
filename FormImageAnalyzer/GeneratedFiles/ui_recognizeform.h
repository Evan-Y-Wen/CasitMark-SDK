/********************************************************************************
** Form generated from reading UI file 'recognizeform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECOGNIZEFORM_H
#define UI_RECOGNIZEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecognizeForm
{
public:
    QGridLayout *gridLayout_5;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_StartScan;
    QLabel *Label_Label_ImageNumTitle;
    QLabel *Label_ImageNum;
    QPushButton *pushButton_StopScan;
    QPushButton *pushButton_Close;
    QPushButton *pushButton_Open;
    QFrame *frame_Setting;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox_ImageType;
    QGridLayout *gridLayout_3;
    QLabel *label_13;
    QLabel *label_11;
    QLabel *label_14;
    QLabel *label_ImageDPI;
    QLabel *label_ImageType;
    QLabel *label_OtherFun;
    QPushButton *pushButton_Setting;
    QWidget *tab2;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer_5;
    QPushButton *Button_OpenDirs;
    QSpacerItem *verticalSpacer_4;
    QPushButton *Button_OpenFiles;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *Label_ReadCount;
    QCheckBox *CheckBox_Rotate90;
    QLabel *label_2;
    QPushButton *Button_RecognizeControl;
    QLabel *Label_TotalCount;
    QLineEdit *TextBox_BinarizeThreshold;
    QLabel *label_6;
    QCheckBox *CheckBox_AutoFilterWhitePage;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_7;

    void setupUi(QDialog *RecognizeForm)
    {
        if (RecognizeForm->objectName().isEmpty())
            RecognizeForm->setObjectName(QString::fromUtf8("RecognizeForm"));
        RecognizeForm->resize(682, 481);
        gridLayout_5 = new QGridLayout(RecognizeForm);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        frame = new QFrame(RecognizeForm);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Plain);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(frame);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\256\213\344\275\223\";"));
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        gridLayout_2 = new QGridLayout(tab1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(20);
        pushButton_StartScan = new QPushButton(tab1);
        pushButton_StartScan->setObjectName(QString::fromUtf8("pushButton_StartScan"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_StartScan->sizePolicy().hasHeightForWidth());
        pushButton_StartScan->setSizePolicy(sizePolicy);
        pushButton_StartScan->setMinimumSize(QSize(0, 40));
        pushButton_StartScan->setMaximumSize(QSize(16777215, 50));

        gridLayout_2->addWidget(pushButton_StartScan, 4, 1, 1, 1);

        Label_Label_ImageNumTitle = new QLabel(tab1);
        Label_Label_ImageNumTitle->setObjectName(QString::fromUtf8("Label_Label_ImageNumTitle"));

        gridLayout_2->addWidget(Label_Label_ImageNumTitle, 5, 1, 1, 1);

        Label_ImageNum = new QLabel(tab1);
        Label_ImageNum->setObjectName(QString::fromUtf8("Label_ImageNum"));

        gridLayout_2->addWidget(Label_ImageNum, 5, 2, 1, 1);

        pushButton_StopScan = new QPushButton(tab1);
        pushButton_StopScan->setObjectName(QString::fromUtf8("pushButton_StopScan"));
        pushButton_StopScan->setMinimumSize(QSize(0, 40));
        pushButton_StopScan->setMaximumSize(QSize(16777215, 50));

        gridLayout_2->addWidget(pushButton_StopScan, 4, 3, 1, 1);

        pushButton_Close = new QPushButton(tab1);
        pushButton_Close->setObjectName(QString::fromUtf8("pushButton_Close"));
        pushButton_Close->setMinimumSize(QSize(0, 40));
        pushButton_Close->setMaximumSize(QSize(16777215, 50));

        gridLayout_2->addWidget(pushButton_Close, 2, 3, 1, 1);

        pushButton_Open = new QPushButton(tab1);
        pushButton_Open->setObjectName(QString::fromUtf8("pushButton_Open"));
        pushButton_Open->setMinimumSize(QSize(0, 40));
        pushButton_Open->setMaximumSize(QSize(16777215, 50));

        gridLayout_2->addWidget(pushButton_Open, 2, 1, 1, 1);

        frame_Setting = new QFrame(tab1);
        frame_Setting->setObjectName(QString::fromUtf8("frame_Setting"));
        frame_Setting->setFrameShape(QFrame::Box);
        frame_Setting->setFrameShadow(QFrame::Plain);
        gridLayout_6 = new QGridLayout(frame_Setting);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        groupBox_ImageType = new QGroupBox(frame_Setting);
        groupBox_ImageType->setObjectName(QString::fromUtf8("groupBox_ImageType"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        groupBox_ImageType->setFont(font);
        gridLayout_3 = new QGridLayout(groupBox_ImageType);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setVerticalSpacing(20);
        label_13 = new QLabel(groupBox_ImageType);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_3->addWidget(label_13, 8, 0, 1, 1);

        label_11 = new QLabel(groupBox_ImageType);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_3->addWidget(label_11, 7, 0, 1, 1);

        label_14 = new QLabel(groupBox_ImageType);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_3->addWidget(label_14, 10, 0, 1, 1);

        label_ImageDPI = new QLabel(groupBox_ImageType);
        label_ImageDPI->setObjectName(QString::fromUtf8("label_ImageDPI"));

        gridLayout_3->addWidget(label_ImageDPI, 7, 1, 1, 1);

        label_ImageType = new QLabel(groupBox_ImageType);
        label_ImageType->setObjectName(QString::fromUtf8("label_ImageType"));

        gridLayout_3->addWidget(label_ImageType, 8, 1, 1, 1);

        label_OtherFun = new QLabel(groupBox_ImageType);
        label_OtherFun->setObjectName(QString::fromUtf8("label_OtherFun"));

        gridLayout_3->addWidget(label_OtherFun, 10, 1, 1, 1);

        pushButton_Setting = new QPushButton(groupBox_ImageType);
        pushButton_Setting->setObjectName(QString::fromUtf8("pushButton_Setting"));
        pushButton_Setting->setMinimumSize(QSize(0, 40));
        pushButton_Setting->setMaximumSize(QSize(16777215, 50));

        gridLayout_3->addWidget(pushButton_Setting, 11, 1, 1, 1);


        gridLayout_6->addWidget(groupBox_ImageType, 2, 1, 1, 1);


        gridLayout_2->addWidget(frame_Setting, 1, 1, 1, 3);

        tabWidget->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QString::fromUtf8("tab2"));
        gridLayout_4 = new QGridLayout(tab2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_5, 0, 1, 1, 1);

        Button_OpenDirs = new QPushButton(tab2);
        Button_OpenDirs->setObjectName(QString::fromUtf8("Button_OpenDirs"));
        sizePolicy.setHeightForWidth(Button_OpenDirs->sizePolicy().hasHeightForWidth());
        Button_OpenDirs->setSizePolicy(sizePolicy);
        Button_OpenDirs->setMinimumSize(QSize(250, 60));

        gridLayout_4->addWidget(Button_OpenDirs, 1, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_4, 3, 1, 1, 1);

        Button_OpenFiles = new QPushButton(tab2);
        Button_OpenFiles->setObjectName(QString::fromUtf8("Button_OpenFiles"));
        sizePolicy.setHeightForWidth(Button_OpenFiles->sizePolicy().hasHeightForWidth());
        Button_OpenFiles->setSizePolicy(sizePolicy);
        Button_OpenFiles->setMinimumSize(QSize(250, 60));

        gridLayout_4->addWidget(Button_OpenFiles, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 1, 0, 2, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 1, 2, 2, 1);

        tabWidget->addTab(tab2, QString());

        horizontalLayout->addWidget(tabWidget);

        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(224, 16777215));
        groupBox->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\256\213\344\275\223\";"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(20);
        Label_ReadCount = new QLabel(groupBox);
        Label_ReadCount->setObjectName(QString::fromUtf8("Label_ReadCount"));
        Label_ReadCount->setStyleSheet(QString::fromUtf8("font:20pt \"\345\256\213\344\275\223\";"));

        gridLayout->addWidget(Label_ReadCount, 3, 1, 1, 1);

        CheckBox_Rotate90 = new QCheckBox(groupBox);
        CheckBox_Rotate90->setObjectName(QString::fromUtf8("CheckBox_Rotate90"));

        gridLayout->addWidget(CheckBox_Rotate90, 6, 0, 1, 2);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        Button_RecognizeControl = new QPushButton(groupBox);
        Button_RecognizeControl->setObjectName(QString::fromUtf8("Button_RecognizeControl"));
        sizePolicy.setHeightForWidth(Button_RecognizeControl->sizePolicy().hasHeightForWidth());
        Button_RecognizeControl->setSizePolicy(sizePolicy);
        Button_RecognizeControl->setMinimumSize(QSize(200, 80));

        gridLayout->addWidget(Button_RecognizeControl, 8, 0, 1, 2);

        Label_TotalCount = new QLabel(groupBox);
        Label_TotalCount->setObjectName(QString::fromUtf8("Label_TotalCount"));
        Label_TotalCount->setStyleSheet(QString::fromUtf8("font:20pt \"\345\256\213\344\275\223\";"));

        gridLayout->addWidget(Label_TotalCount, 1, 1, 1, 1);

        TextBox_BinarizeThreshold = new QLineEdit(groupBox);
        TextBox_BinarizeThreshold->setObjectName(QString::fromUtf8("TextBox_BinarizeThreshold"));
        sizePolicy.setHeightForWidth(TextBox_BinarizeThreshold->sizePolicy().hasHeightForWidth());
        TextBox_BinarizeThreshold->setSizePolicy(sizePolicy);

        gridLayout->addWidget(TextBox_BinarizeThreshold, 5, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        CheckBox_AutoFilterWhitePage = new QCheckBox(groupBox);
        CheckBox_AutoFilterWhitePage->setObjectName(QString::fromUtf8("CheckBox_AutoFilterWhitePage"));
        CheckBox_AutoFilterWhitePage->setChecked(true);

        gridLayout->addWidget(CheckBox_AutoFilterWhitePage, 7, 0, 1, 2);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 4, 1, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 5, 0, 1, 1);


        horizontalLayout->addWidget(groupBox);


        gridLayout_5->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(RecognizeForm);
        QObject::connect(pushButton_Setting, SIGNAL(clicked(bool)), RecognizeForm, SLOT(Setting()));
        QObject::connect(pushButton_Open, SIGNAL(clicked(bool)), RecognizeForm, SLOT(OpenDevice()));
        QObject::connect(pushButton_Close, SIGNAL(clicked(bool)), RecognizeForm, SLOT(CloseDeivce()));
        QObject::connect(pushButton_StartScan, SIGNAL(clicked(bool)), RecognizeForm, SLOT(StartScan()));
        QObject::connect(pushButton_StopScan, SIGNAL(clicked(bool)), RecognizeForm, SLOT(StopScan()));
        QObject::connect(Button_RecognizeControl, SIGNAL(clicked(bool)), RecognizeForm, SLOT(Button_RecognizeControl_Click()));
        QObject::connect(CheckBox_AutoFilterWhitePage, SIGNAL(clicked(bool)), RecognizeForm, SLOT(CheckBox_AutoFilterWhitePage_Click()));
        QObject::connect(CheckBox_Rotate90, SIGNAL(clicked(bool)), RecognizeForm, SLOT(CheckBox_Rotate90_Click()));
        QObject::connect(Button_OpenDirs, SIGNAL(clicked(bool)), RecognizeForm, SLOT(Button_OpenDirs_Click()));
        QObject::connect(Button_OpenFiles, SIGNAL(clicked(bool)), RecognizeForm, SLOT(Button_OpenFiles_Click()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RecognizeForm);
    } // setupUi

    void retranslateUi(QDialog *RecognizeForm)
    {
        RecognizeForm->setWindowTitle(QApplication::translate("RecognizeForm", "RecognizeForm", nullptr));
        pushButton_StartScan->setText(QApplication::translate("RecognizeForm", "\345\274\200\345\247\213\346\211\253\346\217\217", nullptr));
        Label_Label_ImageNumTitle->setText(QApplication::translate("RecognizeForm", "\351\230\205\350\257\273\345\233\276\345\203\217\350\256\241\346\225\260\357\274\232", nullptr));
        Label_ImageNum->setText(QApplication::translate("RecognizeForm", "999999", nullptr));
        pushButton_StopScan->setText(QApplication::translate("RecognizeForm", "\345\201\234\346\255\242\346\211\253\346\217\217", nullptr));
        pushButton_Close->setText(QApplication::translate("RecognizeForm", "\345\205\263\351\227\255\351\230\205\350\257\273\344\273\252", nullptr));
        pushButton_Open->setText(QApplication::translate("RecognizeForm", "\346\211\223\345\274\200\351\230\205\350\257\273\344\273\252", nullptr));
        groupBox_ImageType->setTitle(QApplication::translate("RecognizeForm", "\345\233\276\345\203\217\350\256\276\347\275\256", nullptr));
        label_13->setText(QApplication::translate("RecognizeForm", "\345\233\276\345\203\217\347\261\273\345\236\213\357\274\232", nullptr));
        label_11->setText(QApplication::translate("RecognizeForm", "\345\233\276\345\203\217DPI\357\274\232", nullptr));
        label_14->setText(QApplication::translate("RecognizeForm", "\345\205\266\344\273\226\345\212\237\350\203\275\357\274\232", nullptr));
        label_ImageDPI->setText(QApplication::translate("RecognizeForm", "0000000000", nullptr));
        label_ImageType->setText(QApplication::translate("RecognizeForm", "\345\275\251\350\211\262", nullptr));
        label_OtherFun->setText(QApplication::translate("RecognizeForm", "\345\274\200\345\220\257\351\207\215\345\274\240\346\243\200\346\265\213", nullptr));
        pushButton_Setting->setText(QApplication::translate("RecognizeForm", "\350\256\276\347\275\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("RecognizeForm", "\344\270\223\347\224\250\350\256\276\345\244\207", nullptr));
        Button_OpenDirs->setText(QApplication::translate("RecognizeForm", "\344\273\216\346\226\207\344\273\266\345\244\271\345\257\274\345\205\245\345\233\276\347\211\207\346\226\207\344\273\266", nullptr));
        Button_OpenFiles->setText(QApplication::translate("RecognizeForm", "\344\273\216\350\256\241\347\256\227\346\234\272\345\257\274\345\205\245\345\233\276\345\203\217\346\226\207\344\273\266", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QApplication::translate("RecognizeForm", "\345\233\276\345\203\217\346\226\207\344\273\266", nullptr));
        groupBox->setTitle(QApplication::translate("RecognizeForm", "\350\257\206\345\210\253", nullptr));
        Label_ReadCount->setText(QApplication::translate("RecognizeForm", "XXXXXX", nullptr));
        CheckBox_Rotate90->setText(QApplication::translate("RecognizeForm", "\350\242\253\350\257\206\345\210\253\345\233\276\345\203\217\346\227\213\350\275\25490\345\272\246", nullptr));
        label_2->setText(QApplication::translate("RecognizeForm", "\345\267\262\346\234\211\345\233\276\345\203\217\346\225\260\357\274\232", nullptr));
        Button_RecognizeControl->setText(QApplication::translate("RecognizeForm", "\345\220\257\345\212\250\350\257\206\345\210\253", nullptr));
        Label_TotalCount->setText(QApplication::translate("RecognizeForm", "XXXXXX", nullptr));
        label_6->setText(QApplication::translate("RecognizeForm", "\350\257\206\345\210\253\345\233\276\345\203\217\346\225\260\357\274\232", nullptr));
        CheckBox_AutoFilterWhitePage->setText(QApplication::translate("RecognizeForm", "\350\207\252\345\212\250\350\277\207\346\273\244\347\231\275\345\233\276\345\203\217", nullptr));
        label_7->setText(QApplication::translate("RecognizeForm", "\344\272\214\345\200\274\345\214\226\351\230\210\345\200\274\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RecognizeForm: public Ui_RecognizeForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECOGNIZEFORM_H
