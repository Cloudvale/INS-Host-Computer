/********************************************************************************
** Form generated from reading UI file 'gdata.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GDATA_H
#define UI_GDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_GData
{
public:
    QVBoxLayout *verticalLayout;
    QtCharts::QChartView *graphicsView;

    void setupUi(QWidget *GData)
    {
        if (GData->objectName().isEmpty())
            GData->setObjectName(QString::fromUtf8("GData"));
        GData->resize(400, 300);
        verticalLayout = new QVBoxLayout(GData);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graphicsView = new QtCharts::QChartView(GData);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout->addWidget(graphicsView);


        retranslateUi(GData);

        QMetaObject::connectSlotsByName(GData);
    } // setupUi

    void retranslateUi(QWidget *GData)
    {
        GData->setWindowTitle(QApplication::translate("GData", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GData: public Ui_GData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GDATA_H
