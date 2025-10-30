/********************************************************************************
** Form generated from reading UI file 'atemp.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATEMP_H
#define UI_ATEMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_ATemp
{
public:
    QHBoxLayout *horizontalLayout;
    QtCharts::QChartView *graphicsView;

    void setupUi(QWidget *ATemp)
    {
        if (ATemp->objectName().isEmpty())
            ATemp->setObjectName(QString::fromUtf8("ATemp"));
        ATemp->resize(400, 300);
        horizontalLayout = new QHBoxLayout(ATemp);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        graphicsView = new QtCharts::QChartView(ATemp);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        horizontalLayout->addWidget(graphicsView);


        retranslateUi(ATemp);

        QMetaObject::connectSlotsByName(ATemp);
    } // setupUi

    void retranslateUi(QWidget *ATemp)
    {
        ATemp->setWindowTitle(QApplication::translate("ATemp", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ATemp: public Ui_ATemp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATEMP_H
