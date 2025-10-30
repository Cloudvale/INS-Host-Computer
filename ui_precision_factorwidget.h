/********************************************************************************
** Form generated from reading UI file 'precision_factorwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRECISION_FACTORWIDGET_H
#define UI_PRECISION_FACTORWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Precision_factorWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit_PF;

    void setupUi(QWidget *Precision_factorWidget)
    {
        if (Precision_factorWidget->objectName().isEmpty())
            Precision_factorWidget->setObjectName(QString::fromUtf8("Precision_factorWidget"));
        Precision_factorWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(Precision_factorWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit_PF = new QTextEdit(Precision_factorWidget);
        textEdit_PF->setObjectName(QString::fromUtf8("textEdit_PF"));

        verticalLayout->addWidget(textEdit_PF);


        retranslateUi(Precision_factorWidget);

        QMetaObject::connectSlotsByName(Precision_factorWidget);
    } // setupUi

    void retranslateUi(QWidget *Precision_factorWidget)
    {
        Precision_factorWidget->setWindowTitle(QApplication::translate("Precision_factorWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Precision_factorWidget: public Ui_Precision_factorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRECISION_FACTORWIDGET_H
