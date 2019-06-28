/********************************************************************************
** Form generated from reading UI file 'createpattern.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPATTERN_H
#define UI_CREATEPATTERN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreatePattern
{
public:
    QGroupBox *groupBox;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *TB_PatternName;
    QGroupBox *groupBox_3;
    QRadioButton *CB_Bihe;
    QRadioButton *CB_QR;
    QLabel *LB_Message;
    QToolButton *BTN_Submit;

    void setupUi(QWidget *CreatePattern)
    {
        if (CreatePattern->objectName().isEmpty())
            CreatePattern->setObjectName(QString::fromUtf8("CreatePattern"));
        CreatePattern->resize(400, 307);
        CreatePattern->setStyleSheet(QString::fromUtf8(""));
        groupBox = new QGroupBox(CreatePattern);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 30, 381, 211));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 20, 31, 31));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 20, 51, 31));
        TB_PatternName = new QLineEdit(groupBox);
        TB_PatternName->setObjectName(QString::fromUtf8("TB_PatternName"));
        TB_PatternName->setGeometry(QRect(130, 19, 231, 31));
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 60, 361, 141));
        CB_Bihe = new QRadioButton(groupBox_3);
        CB_Bihe->setObjectName(QString::fromUtf8("CB_Bihe"));
        CB_Bihe->setGeometry(QRect(10, 30, 161, 31));
        CB_QR = new QRadioButton(groupBox_3);
        CB_QR->setObjectName(QString::fromUtf8("CB_QR"));
        CB_QR->setGeometry(QRect(10, 60, 161, 31));
        LB_Message = new QLabel(groupBox_3);
        LB_Message->setObjectName(QString::fromUtf8("LB_Message"));
        LB_Message->setGeometry(QRect(10, 90, 251, 31));
        BTN_Submit = new QToolButton(CreatePattern);
        BTN_Submit->setObjectName(QString::fromUtf8("BTN_Submit"));
        BTN_Submit->setGeometry(QRect(270, 250, 101, 41));
        BTN_Submit->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));

        retranslateUi(CreatePattern);
        QObject::connect(BTN_Submit, SIGNAL(clicked()), CreatePattern, SLOT(BTN_Submit_Click()));
        QObject::connect(CB_Bihe, SIGNAL(clicked()), CreatePattern, SLOT(CB_Bihe_Click()));
        QObject::connect(CB_QR, SIGNAL(clicked()), CreatePattern, SLOT(CB_QR_Click()));

        QMetaObject::connectSlotsByName(CreatePattern);
    } // setupUi

    void retranslateUi(QWidget *CreatePattern)
    {
        CreatePattern->setWindowTitle(QApplication::translate("CreatePattern", "CreatePattern", nullptr));
        groupBox->setTitle(QString());
        label_3->setText(QApplication::translate("CreatePattern", "\345\233\276\346\240\207", nullptr));
        label_4->setText(QApplication::translate("CreatePattern", "\346\250\241\345\274\217\345\220\215\347\247\260", nullptr));
        TB_PatternName->setText(QApplication::translate("CreatePattern", "\350\257\267\350\276\223\345\205\245\346\250\241\345\274\217\345\220\215\347\247\260\357\274\232", nullptr));
        groupBox_3->setTitle(QString());
        CB_Bihe->setText(QApplication::translate("CreatePattern", "\345\256\232\344\275\215\346\226\271\345\274\217\344\270\200", nullptr));
        CB_QR->setText(QApplication::translate("CreatePattern", "\345\256\232\344\275\215\346\226\271\345\274\217\344\272\214", nullptr));
        LB_Message->setText(QApplication::translate("CreatePattern", "Tips", nullptr));
        BTN_Submit->setText(QApplication::translate("CreatePattern", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreatePattern: public Ui_CreatePattern {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPATTERN_H
