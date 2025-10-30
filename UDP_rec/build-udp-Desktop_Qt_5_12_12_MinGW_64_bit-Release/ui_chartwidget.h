/********************************************************************************
** Form generated from reading UI file 'chartwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTWIDGET_H
#define UI_CHARTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_ChartWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QtCharts::QChartView *graphicsView;
    QtCharts::QChartView *graphicsView_ac_rate;

    void setupUi(QWidget *ChartWidget)
    {
        if (ChartWidget->objectName().isEmpty())
            ChartWidget->setObjectName(QString::fromUtf8("ChartWidget"));
        ChartWidget->resize(800, 800);
        horizontalLayout = new QHBoxLayout(ChartWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graphicsView = new QtCharts::QChartView(ChartWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout->addWidget(graphicsView);

        graphicsView_ac_rate = new QtCharts::QChartView(ChartWidget);
        graphicsView_ac_rate->setObjectName(QString::fromUtf8("graphicsView_ac_rate"));

        verticalLayout->addWidget(graphicsView_ac_rate);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(ChartWidget);

        QMetaObject::connectSlotsByName(ChartWidget);
    } // setupUi

    void retranslateUi(QWidget *ChartWidget)
    {
        ChartWidget->setWindowTitle(QApplication::translate("ChartWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChartWidget: public Ui_ChartWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTWIDGET_H
