/********************************************************************************
** Form generated from reading UI file 'gnss_dbtwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GNSS_DBTWIDGET_H
#define UI_GNSS_DBTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_Gnss_dbtWidget
{
public:
    QVBoxLayout *verticalLayout;
    QtCharts::QChartView *graphicsView_D;
    QtCharts::QChartView *graphicsView_N;
    QtCharts::QChartView *graphicsView_U;
    QLineEdit *lineEdit_DNU;

    void setupUi(QWidget *Gnss_dbtWidget)
    {
        if (Gnss_dbtWidget->objectName().isEmpty())
            Gnss_dbtWidget->setObjectName(QString::fromUtf8("Gnss_dbtWidget"));
        Gnss_dbtWidget->resize(800, 600);
        verticalLayout = new QVBoxLayout(Gnss_dbtWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graphicsView_D = new QtCharts::QChartView(Gnss_dbtWidget);
        graphicsView_D->setObjectName(QString::fromUtf8("graphicsView_D"));

        verticalLayout->addWidget(graphicsView_D);

        graphicsView_N = new QtCharts::QChartView(Gnss_dbtWidget);
        graphicsView_N->setObjectName(QString::fromUtf8("graphicsView_N"));

        verticalLayout->addWidget(graphicsView_N);

        graphicsView_U = new QtCharts::QChartView(Gnss_dbtWidget);
        graphicsView_U->setObjectName(QString::fromUtf8("graphicsView_U"));

        verticalLayout->addWidget(graphicsView_U);

        lineEdit_DNU = new QLineEdit(Gnss_dbtWidget);
        lineEdit_DNU->setObjectName(QString::fromUtf8("lineEdit_DNU"));

        verticalLayout->addWidget(lineEdit_DNU);


        retranslateUi(Gnss_dbtWidget);

        QMetaObject::connectSlotsByName(Gnss_dbtWidget);
    } // setupUi

    void retranslateUi(QWidget *Gnss_dbtWidget)
    {
        Gnss_dbtWidget->setWindowTitle(QApplication::translate("Gnss_dbtWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Gnss_dbtWidget: public Ui_Gnss_dbtWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GNSS_DBTWIDGET_H
