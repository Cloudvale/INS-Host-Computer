/********************************************************************************
** Form generated from reading UI file 'utctext.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UTCTEXT_H
#define UI_UTCTEXT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UTCtext
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;

    void setupUi(QWidget *UTCtext)
    {
        if (UTCtext->objectName().isEmpty())
            UTCtext->setObjectName(QString::fromUtf8("UTCtext"));
        UTCtext->resize(355, 212);
        verticalLayout = new QVBoxLayout(UTCtext);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit = new QLineEdit(UTCtext);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);


        retranslateUi(UTCtext);

        QMetaObject::connectSlotsByName(UTCtext);
    } // setupUi

    void retranslateUi(QWidget *UTCtext)
    {
        UTCtext->setWindowTitle(QApplication::translate("UTCtext", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UTCtext: public Ui_UTCtext {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UTCTEXT_H
