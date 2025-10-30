/********************************************************************************
** Form generated from reading UI file 'adata.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADATA_H
#define UI_ADATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_AData
{
public:
    QVBoxLayout *verticalLayout;
    QtCharts::QChartView *graphicsView;

    void setupUi(QWidget *AData)
    {
        if (AData->objectName().isEmpty())
            AData->setObjectName(QString::fromUtf8("AData"));
        AData->resize(400, 300);
        verticalLayout = new QVBoxLayout(AData);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graphicsView = new QtCharts::QChartView(AData);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout->addWidget(graphicsView);


        retranslateUi(AData);

        QMetaObject::connectSlotsByName(AData);
    } // setupUi

    void retranslateUi(QWidget *AData)
    {
        AData->setWindowTitle(QApplication::translate("AData", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AData: public Ui_AData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADATA_H
