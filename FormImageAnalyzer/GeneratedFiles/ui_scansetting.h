/********************************************************************************
** Form generated from reading UI file 'scansetting.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCANSETTING_H
#define UI_SCANSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ScanSetting
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QComboBox *comboBox_ImageDPI;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *radioButton_TypeColor;
    QRadioButton *radioButton_TypeGray;
    QRadioButton *radioButton_LightWhite;
    QRadioButton *radioButton_LightRed;
    QRadioButton *radioButton_LightGreen;
    QRadioButton *radioButton_LightBlue;
    QCheckBox *checkBox_DoubleCheck;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Confirm;
    QPushButton *pushButton_Cancel;

    void setupUi(QDialog *ScanSetting)
    {
        if (ScanSetting->objectName().isEmpty())
            ScanSetting->setObjectName(QString::fromUtf8("ScanSetting"));
        ScanSetting->resize(600, 400);
        verticalLayout_2 = new QVBoxLayout(ScanSetting);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_2 = new QGroupBox(ScanSetting);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(16);
        groupBox_2->setFont(font);
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        comboBox_ImageDPI = new QComboBox(groupBox_2);
        comboBox_ImageDPI->addItem(QString());
        comboBox_ImageDPI->addItem(QString());
        comboBox_ImageDPI->addItem(QString());
        comboBox_ImageDPI->setObjectName(QString::fromUtf8("comboBox_ImageDPI"));
        comboBox_ImageDPI->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(comboBox_ImageDPI, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox = new QGroupBox(ScanSetting);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFont(font);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        radioButton_TypeColor = new QRadioButton(groupBox);
        radioButton_TypeColor->setObjectName(QString::fromUtf8("radioButton_TypeColor"));

        gridLayout->addWidget(radioButton_TypeColor, 0, 0, 2, 1);

        radioButton_TypeGray = new QRadioButton(groupBox);
        radioButton_TypeGray->setObjectName(QString::fromUtf8("radioButton_TypeGray"));

        gridLayout->addWidget(radioButton_TypeGray, 2, 0, 2, 1);

        radioButton_LightWhite = new QRadioButton(groupBox);
        radioButton_LightWhite->setObjectName(QString::fromUtf8("radioButton_LightWhite"));
        radioButton_LightWhite->setFont(font);

        gridLayout->addWidget(radioButton_LightWhite, 0, 1, 1, 1);

        radioButton_LightRed = new QRadioButton(groupBox);
        radioButton_LightRed->setObjectName(QString::fromUtf8("radioButton_LightRed"));

        gridLayout->addWidget(radioButton_LightRed, 1, 1, 1, 1);

        radioButton_LightGreen = new QRadioButton(groupBox);
        radioButton_LightGreen->setObjectName(QString::fromUtf8("radioButton_LightGreen"));

        gridLayout->addWidget(radioButton_LightGreen, 2, 1, 1, 1);

        radioButton_LightBlue = new QRadioButton(groupBox);
        radioButton_LightBlue->setObjectName(QString::fromUtf8("radioButton_LightBlue"));

        gridLayout->addWidget(radioButton_LightBlue, 3, 1, 1, 1);


        verticalLayout_2->addWidget(groupBox);

        checkBox_DoubleCheck = new QCheckBox(ScanSetting);
        checkBox_DoubleCheck->setObjectName(QString::fromUtf8("checkBox_DoubleCheck"));
        checkBox_DoubleCheck->setFont(font);

        verticalLayout_2->addWidget(checkBox_DoubleCheck);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, -1, 20, -1);
        pushButton_Confirm = new QPushButton(ScanSetting);
        pushButton_Confirm->setObjectName(QString::fromUtf8("pushButton_Confirm"));
        pushButton_Confirm->setFont(font);

        horizontalLayout->addWidget(pushButton_Confirm);

        pushButton_Cancel = new QPushButton(ScanSetting);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setFont(font);

        horizontalLayout->addWidget(pushButton_Cancel);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(ScanSetting);
        QObject::connect(radioButton_TypeColor, SIGNAL(clicked()), ScanSetting, SLOT(ImageTypeChanged()));
        QObject::connect(radioButton_TypeGray, SIGNAL(clicked()), ScanSetting, SLOT(ImageTypeChanged()));
        QObject::connect(pushButton_Confirm, SIGNAL(clicked()), ScanSetting, SLOT(Confirm()));
        QObject::connect(pushButton_Cancel, SIGNAL(clicked()), ScanSetting, SLOT(reject()));

        QMetaObject::connectSlotsByName(ScanSetting);
    } // setupUi

    void retranslateUi(QDialog *ScanSetting)
    {
        ScanSetting->setWindowTitle(QApplication::translate("ScanSetting", "\346\211\253\346\217\217\350\256\276\347\275\256", nullptr));
        groupBox_2->setTitle(QApplication::translate("ScanSetting", "\345\233\276\345\203\217DPI", nullptr));
        comboBox_ImageDPI->setItemText(0, QApplication::translate("ScanSetting", "200", nullptr));
        comboBox_ImageDPI->setItemText(1, QApplication::translate("ScanSetting", "300", nullptr));
        comboBox_ImageDPI->setItemText(2, QApplication::translate("ScanSetting", "600", nullptr));

        groupBox->setTitle(QApplication::translate("ScanSetting", "\345\233\276\345\203\217\347\261\273\345\236\213", nullptr));
        radioButton_TypeColor->setText(QApplication::translate("ScanSetting", "\345\275\251\350\211\262", nullptr));
        radioButton_TypeGray->setText(QApplication::translate("ScanSetting", "\347\201\260\345\272\246", nullptr));
        radioButton_LightWhite->setText(QApplication::translate("ScanSetting", "\347\231\275\350\211\262\345\205\211\346\272\220", nullptr));
        radioButton_LightRed->setText(QApplication::translate("ScanSetting", "\347\272\242\350\211\262\345\205\211\346\272\220", nullptr));
        radioButton_LightGreen->setText(QApplication::translate("ScanSetting", "\347\273\277\350\211\262\345\205\211\346\272\220", nullptr));
        radioButton_LightBlue->setText(QApplication::translate("ScanSetting", "\350\223\235\350\211\262\345\205\211\346\272\220", nullptr));
        checkBox_DoubleCheck->setText(QApplication::translate("ScanSetting", "\345\274\200\345\220\257\351\207\215\345\274\240\346\243\200\346\265\213", nullptr));
        pushButton_Confirm->setText(QApplication::translate("ScanSetting", "\347\241\256\350\256\244", nullptr));
        pushButton_Cancel->setText(QApplication::translate("ScanSetting", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScanSetting: public Ui_ScanSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANSETTING_H
