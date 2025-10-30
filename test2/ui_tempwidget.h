/********************************************************************************
** Form generated from reading UI file 'tempwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPWIDGET_H
#define UI_TEMPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_TempWidget
{
public:
    QVBoxLayout *verticalLayout;
    QtCharts::QChartView *graphicsView;
    QLineEdit *lineEdit;

    void setupUi(QWidget *TempWidget)
    {
        if (TempWidget->objectName().isEmpty())
            TempWidget->setObjectName(QString::fromUtf8("TempWidget"));
        TempWidget->resize(462, 339);
        verticalLayout = new QVBoxLayout(TempWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graphicsView = new QtCharts::QChartView(TempWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout->addWidget(graphicsView);

        lineEdit = new QLineEdit(TempWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);


        retranslateUi(TempWidget);

        QMetaObject::connectSlotsByName(TempWidget);
    } // setupUi

    void retranslateUi(QWidget *TempWidget)
    {
        TempWidget->setWindowTitle(QApplication::translate("TempWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TempWidget: public Ui_TempWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPWIDGET_H
