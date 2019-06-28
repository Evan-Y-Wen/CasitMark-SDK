/********************************************************************************
** Form generated from reading UI file 'qrcodebuilder.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QRCODEBUILDER_H
#define UI_QRCODEBUILDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mylabel.h"

QT_BEGIN_NAMESPACE

class Ui_QRcodeBuilderClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_10;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox0;
    QGridLayout *gridLayout_14;
    QLabel *text0;
    QFrame *frame_image0;
    QHBoxLayout *horizontalLayout;
    MyLabel *image0;
    QGroupBox *groupBox1;
    QGridLayout *gridLayout_15;
    QLabel *text1;
    QFrame *frame_image1;
    QHBoxLayout *horizontalLayout_2;
    MyLabel *image1;
    QGroupBox *groupBox2;
    QGridLayout *gridLayout_16;
    QLabel *text2;
    QFrame *frame_image2;
    QHBoxLayout *horizontalLayout_6;
    MyLabel *image2;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox3;
    QGridLayout *gridLayout_11;
    QLabel *text3;
    QFrame *frame_image3;
    QHBoxLayout *horizontalLayout_7;
    MyLabel *image3;
    QGroupBox *groupBox4;
    QGridLayout *gridLayout_12;
    QLabel *text4;
    QFrame *frame_image4;
    QHBoxLayout *horizontalLayout_8;
    MyLabel *image4;
    QGroupBox *groupBox5;
    QGridLayout *gridLayout_13;
    QLabel *text5;
    QFrame *frame_image5;
    QHBoxLayout *horizontalLayout_9;
    MyLabel *image5;
    QGroupBox *groupBox_17;
    QGridLayout *gridLayout_17;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_8;
    QRadioButton *RadioButton_QRCode;
    QRadioButton *RadioButton_SimpleCode;
    QGroupBox *groupBox_18;
    QGridLayout *gridLayout_18;
    QLineEdit *voteID;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_9;
    QToolButton *button_Copy;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_10;
    QToolButton *button_Build;

    void setupUi(QMainWindow *QRcodeBuilderClass)
    {
        if (QRcodeBuilderClass->objectName().isEmpty())
            QRcodeBuilderClass->setObjectName(QString::fromUtf8("QRcodeBuilderClass"));
        QRcodeBuilderClass->resize(952, 307);
        QRcodeBuilderClass->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(QRcodeBuilderClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        groupBox_10 = new QGroupBox(centralWidget);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_10->sizePolicy().hasHeightForWidth());
        groupBox_10->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(groupBox_10);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(60);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 6);
        groupBox0 = new QGroupBox(groupBox_10);
        groupBox0->setObjectName(QString::fromUtf8("groupBox0"));
        gridLayout_14 = new QGridLayout(groupBox0);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_14->setVerticalSpacing(6);
        text0 = new QLabel(groupBox0);
        text0->setObjectName(QString::fromUtf8("text0"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(text0->sizePolicy().hasHeightForWidth());
        text0->setSizePolicy(sizePolicy1);
        text0->setAlignment(Qt::AlignCenter);

        gridLayout_14->addWidget(text0, 1, 1, 1, 1);

        frame_image0 = new QFrame(groupBox0);
        frame_image0->setObjectName(QString::fromUtf8("frame_image0"));
        frame_image0->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        horizontalLayout = new QHBoxLayout(frame_image0);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        image0 = new MyLabel(frame_image0);
        image0->setObjectName(QString::fromUtf8("image0"));
        sizePolicy.setHeightForWidth(image0->sizePolicy().hasHeightForWidth());
        image0->setSizePolicy(sizePolicy);
        image0->setMinimumSize(QSize(240, 40));
        image0->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(image0);


        gridLayout_14->addWidget(frame_image0, 0, 1, 1, 1);


        horizontalLayout_5->addWidget(groupBox0);

        groupBox1 = new QGroupBox(groupBox_10);
        groupBox1->setObjectName(QString::fromUtf8("groupBox1"));
        gridLayout_15 = new QGridLayout(groupBox1);
        gridLayout_15->setSpacing(6);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        text1 = new QLabel(groupBox1);
        text1->setObjectName(QString::fromUtf8("text1"));
        sizePolicy1.setHeightForWidth(text1->sizePolicy().hasHeightForWidth());
        text1->setSizePolicy(sizePolicy1);
        text1->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(text1, 2, 1, 1, 1);

        frame_image1 = new QFrame(groupBox1);
        frame_image1->setObjectName(QString::fromUtf8("frame_image1"));
        frame_image1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        horizontalLayout_2 = new QHBoxLayout(frame_image1);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        image1 = new MyLabel(frame_image1);
        image1->setObjectName(QString::fromUtf8("image1"));
        sizePolicy.setHeightForWidth(image1->sizePolicy().hasHeightForWidth());
        image1->setSizePolicy(sizePolicy);
        image1->setMinimumSize(QSize(240, 40));
        image1->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(image1);


        gridLayout_15->addWidget(frame_image1, 1, 1, 1, 1);


        horizontalLayout_5->addWidget(groupBox1);

        groupBox2 = new QGroupBox(groupBox_10);
        groupBox2->setObjectName(QString::fromUtf8("groupBox2"));
        gridLayout_16 = new QGridLayout(groupBox2);
        gridLayout_16->setSpacing(6);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        text2 = new QLabel(groupBox2);
        text2->setObjectName(QString::fromUtf8("text2"));
        sizePolicy1.setHeightForWidth(text2->sizePolicy().hasHeightForWidth());
        text2->setSizePolicy(sizePolicy1);
        text2->setAlignment(Qt::AlignCenter);

        gridLayout_16->addWidget(text2, 2, 1, 1, 1);

        frame_image2 = new QFrame(groupBox2);
        frame_image2->setObjectName(QString::fromUtf8("frame_image2"));
        frame_image2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        horizontalLayout_6 = new QHBoxLayout(frame_image2);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        image2 = new MyLabel(frame_image2);
        image2->setObjectName(QString::fromUtf8("image2"));
        sizePolicy.setHeightForWidth(image2->sizePolicy().hasHeightForWidth());
        image2->setSizePolicy(sizePolicy);
        image2->setMinimumSize(QSize(240, 40));
        image2->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(image2);


        gridLayout_16->addWidget(frame_image2, 1, 1, 1, 1);


        horizontalLayout_5->addWidget(groupBox2);


        gridLayout->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(60);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        groupBox3 = new QGroupBox(groupBox_10);
        groupBox3->setObjectName(QString::fromUtf8("groupBox3"));
        gridLayout_11 = new QGridLayout(groupBox3);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setVerticalSpacing(6);
        text3 = new QLabel(groupBox3);
        text3->setObjectName(QString::fromUtf8("text3"));
        sizePolicy1.setHeightForWidth(text3->sizePolicy().hasHeightForWidth());
        text3->setSizePolicy(sizePolicy1);
        text3->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(text3, 2, 1, 1, 1);

        frame_image3 = new QFrame(groupBox3);
        frame_image3->setObjectName(QString::fromUtf8("frame_image3"));
        frame_image3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        horizontalLayout_7 = new QHBoxLayout(frame_image3);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        image3 = new MyLabel(frame_image3);
        image3->setObjectName(QString::fromUtf8("image3"));
        sizePolicy.setHeightForWidth(image3->sizePolicy().hasHeightForWidth());
        image3->setSizePolicy(sizePolicy);
        image3->setMinimumSize(QSize(240, 40));
        image3->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(image3);


        gridLayout_11->addWidget(frame_image3, 1, 1, 1, 1);


        horizontalLayout_4->addWidget(groupBox3);

        groupBox4 = new QGroupBox(groupBox_10);
        groupBox4->setObjectName(QString::fromUtf8("groupBox4"));
        gridLayout_12 = new QGridLayout(groupBox4);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        text4 = new QLabel(groupBox4);
        text4->setObjectName(QString::fromUtf8("text4"));
        sizePolicy1.setHeightForWidth(text4->sizePolicy().hasHeightForWidth());
        text4->setSizePolicy(sizePolicy1);
        text4->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(text4, 2, 1, 1, 1);

        frame_image4 = new QFrame(groupBox4);
        frame_image4->setObjectName(QString::fromUtf8("frame_image4"));
        frame_image4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        horizontalLayout_8 = new QHBoxLayout(frame_image4);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        image4 = new MyLabel(frame_image4);
        image4->setObjectName(QString::fromUtf8("image4"));
        sizePolicy.setHeightForWidth(image4->sizePolicy().hasHeightForWidth());
        image4->setSizePolicy(sizePolicy);
        image4->setMinimumSize(QSize(240, 40));
        image4->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(image4);


        gridLayout_12->addWidget(frame_image4, 1, 1, 1, 1);


        horizontalLayout_4->addWidget(groupBox4);

        groupBox5 = new QGroupBox(groupBox_10);
        groupBox5->setObjectName(QString::fromUtf8("groupBox5"));
        gridLayout_13 = new QGridLayout(groupBox5);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        text5 = new QLabel(groupBox5);
        text5->setObjectName(QString::fromUtf8("text5"));
        sizePolicy1.setHeightForWidth(text5->sizePolicy().hasHeightForWidth());
        text5->setSizePolicy(sizePolicy1);
        text5->setAlignment(Qt::AlignCenter);

        gridLayout_13->addWidget(text5, 2, 1, 1, 1);

        frame_image5 = new QFrame(groupBox5);
        frame_image5->setObjectName(QString::fromUtf8("frame_image5"));
        frame_image5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        horizontalLayout_9 = new QHBoxLayout(frame_image5);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        image5 = new MyLabel(frame_image5);
        image5->setObjectName(QString::fromUtf8("image5"));
        sizePolicy.setHeightForWidth(image5->sizePolicy().hasHeightForWidth());
        image5->setSizePolicy(sizePolicy);
        image5->setMinimumSize(QSize(240, 40));
        image5->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(image5);


        gridLayout_13->addWidget(frame_image5, 1, 1, 1, 1);


        horizontalLayout_4->addWidget(groupBox5);


        gridLayout->addLayout(horizontalLayout_4, 1, 0, 1, 1);


        verticalLayout->addWidget(groupBox_10);

        groupBox_17 = new QGroupBox(centralWidget);
        groupBox_17->setObjectName(QString::fromUtf8("groupBox_17"));
        sizePolicy1.setHeightForWidth(groupBox_17->sizePolicy().hasHeightForWidth());
        groupBox_17->setSizePolicy(sizePolicy1);
        gridLayout_17 = new QGridLayout(groupBox_17);
        gridLayout_17->setSpacing(6);
        gridLayout_17->setContentsMargins(11, 11, 11, 11);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox_7 = new QGroupBox(groupBox_17);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        gridLayout_8 = new QGridLayout(groupBox_7);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        RadioButton_QRCode = new QRadioButton(groupBox_7);
        RadioButton_QRCode->setObjectName(QString::fromUtf8("RadioButton_QRCode"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(RadioButton_QRCode->sizePolicy().hasHeightForWidth());
        RadioButton_QRCode->setSizePolicy(sizePolicy2);

        gridLayout_8->addWidget(RadioButton_QRCode, 1, 0, 1, 1);

        RadioButton_SimpleCode = new QRadioButton(groupBox_7);
        RadioButton_SimpleCode->setObjectName(QString::fromUtf8("RadioButton_SimpleCode"));
        sizePolicy2.setHeightForWidth(RadioButton_SimpleCode->sizePolicy().hasHeightForWidth());
        RadioButton_SimpleCode->setSizePolicy(sizePolicy2);
        RadioButton_SimpleCode->setChecked(true);

        gridLayout_8->addWidget(RadioButton_SimpleCode, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(groupBox_7);

        groupBox_18 = new QGroupBox(groupBox_17);
        groupBox_18->setObjectName(QString::fromUtf8("groupBox_18"));
        gridLayout_18 = new QGridLayout(groupBox_18);
        gridLayout_18->setSpacing(6);
        gridLayout_18->setContentsMargins(11, 11, 11, 11);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        voteID = new QLineEdit(groupBox_18);
        voteID->setObjectName(QString::fromUtf8("voteID"));
        sizePolicy1.setHeightForWidth(voteID->sizePolicy().hasHeightForWidth());
        voteID->setSizePolicy(sizePolicy1);

        gridLayout_18->addWidget(voteID, 0, 1, 1, 1);

        label = new QLabel(groupBox_18);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_18->addWidget(label, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(groupBox_18);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        groupBox_8 = new QGroupBox(groupBox_17);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        gridLayout_9 = new QGridLayout(groupBox_8);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        button_Copy = new QToolButton(groupBox_8);
        button_Copy->setObjectName(QString::fromUtf8("button_Copy"));
        sizePolicy.setHeightForWidth(button_Copy->sizePolicy().hasHeightForWidth());
        button_Copy->setSizePolicy(sizePolicy);
        button_Copy->setMinimumSize(QSize(120, 38));
        button_Copy->setCheckable(false);

        gridLayout_9->addWidget(button_Copy, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(groupBox_8);

        groupBox_9 = new QGroupBox(groupBox_17);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        gridLayout_10 = new QGridLayout(groupBox_9);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        button_Build = new QToolButton(groupBox_9);
        button_Build->setObjectName(QString::fromUtf8("button_Build"));
        sizePolicy.setHeightForWidth(button_Build->sizePolicy().hasHeightForWidth());
        button_Build->setSizePolicy(sizePolicy);
        button_Build->setMinimumSize(QSize(120, 38));
        button_Build->setCheckable(false);

        gridLayout_10->addWidget(button_Build, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(groupBox_9);


        gridLayout_17->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_17);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        QRcodeBuilderClass->setCentralWidget(centralWidget);
#ifndef QT_NO_SHORTCUT
        label->setBuddy(voteID);
#endif // QT_NO_SHORTCUT

        retranslateUi(QRcodeBuilderClass);
        QObject::connect(button_Copy, SIGNAL(clicked(bool)), QRcodeBuilderClass, SLOT(button_Copy_Click()));
        QObject::connect(button_Build, SIGNAL(clicked(bool)), QRcodeBuilderClass, SLOT(button_Build_Click()));
        QObject::connect(RadioButton_SimpleCode, SIGNAL(clicked(bool)), QRcodeBuilderClass, SLOT(RadioButton_SimpleCode_Checked()));
        QObject::connect(RadioButton_QRCode, SIGNAL(clicked(bool)), QRcodeBuilderClass, SLOT(RadioButton_QRCode_Checked()));

        QMetaObject::connectSlotsByName(QRcodeBuilderClass);
    } // setupUi

    void retranslateUi(QMainWindow *QRcodeBuilderClass)
    {
        QRcodeBuilderClass->setWindowTitle(QApplication::translate("QRcodeBuilderClass", "QRcodeBuilder", nullptr));
        groupBox_10->setTitle(QString());
        groupBox0->setTitle(QString());
        text0->setText(QApplication::translate("QRcodeBuilderClass", "1-0", nullptr));
        image0->setText(QApplication::translate("QRcodeBuilderClass", "image0", nullptr));
        groupBox1->setTitle(QString());
        text1->setText(QApplication::translate("QRcodeBuilderClass", "1-1", nullptr));
        image1->setText(QApplication::translate("QRcodeBuilderClass", "image1", nullptr));
        groupBox2->setTitle(QString());
        text2->setText(QApplication::translate("QRcodeBuilderClass", "1-2", nullptr));
        image2->setText(QApplication::translate("QRcodeBuilderClass", "image2", nullptr));
        groupBox3->setTitle(QString());
        text3->setText(QApplication::translate("QRcodeBuilderClass", "1-3", nullptr));
        image3->setText(QApplication::translate("QRcodeBuilderClass", "image3", nullptr));
        groupBox4->setTitle(QString());
        text4->setText(QApplication::translate("QRcodeBuilderClass", "1-4", nullptr));
        image4->setText(QApplication::translate("QRcodeBuilderClass", "image4", nullptr));
        groupBox5->setTitle(QString());
        text5->setText(QApplication::translate("QRcodeBuilderClass", "1-5", nullptr));
        image5->setText(QApplication::translate("QRcodeBuilderClass", "image5", nullptr));
        groupBox_17->setTitle(QString());
        groupBox_7->setTitle(QString());
        RadioButton_QRCode->setText(QApplication::translate("QRcodeBuilderClass", "\344\272\214\347\273\264\347\240\201", nullptr));
        RadioButton_SimpleCode->setText(QApplication::translate("QRcodeBuilderClass", "\347\256\200\345\215\225\347\240\201", nullptr));
        groupBox_18->setTitle(QString());
        voteID->setText(QApplication::translate("QRcodeBuilderClass", "1", nullptr));
        label->setText(QApplication::translate("QRcodeBuilderClass", "\351\200\211\347\245\250ID\357\274\232", nullptr));
        groupBox_8->setTitle(QString());
        button_Copy->setText(QApplication::translate("QRcodeBuilderClass", "\345\244\215\345\210\266\351\200\211\344\270\255\345\233\276\345\203\217", nullptr));
        groupBox_9->setTitle(QString());
        button_Build->setText(QApplication::translate("QRcodeBuilderClass", "\351\207\215\346\226\260\347\224\237\346\210\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QRcodeBuilderClass: public Ui_QRcodeBuilderClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QRCODEBUILDER_H
