/********************************************************************************
** Form generated from reading UI file 'gnsslhl_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GNSSLHL_WIDGET_H
#define UI_GNSSLHL_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_Gnsslhl_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QtCharts::QChartView *graphicsView_lon;
    QtCharts::QChartView *graphicsView_lat;
    QtCharts::QChartView *graphicsView_height;
    QLineEdit *lineEdit_lhl;

    void setupUi(QWidget *Gnsslhl_Widget)
    {
        if (Gnsslhl_Widget->objectName().isEmpty())
            Gnsslhl_Widget->setObjectName(QString::fromUtf8("Gnsslhl_Widget"));
        Gnsslhl_Widget->resize(538, 360);
        verticalLayout = new QVBoxLayout(Gnsslhl_Widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graphicsView_lon = new QtCharts::QChartView(Gnsslhl_Widget);
        graphicsView_lon->setObjectName(QString::fromUtf8("graphicsView_lon"));

        verticalLayout->addWidget(graphicsView_lon);

        graphicsView_lat = new QtCharts::QChartView(Gnsslhl_Widget);
        graphicsView_lat->setObjectName(QString::fromUtf8("graphicsView_lat"));

        verticalLayout->addWidget(graphicsView_lat);

        graphicsView_height = new QtCharts::QChartView(Gnsslhl_Widget);
        graphicsView_height->setObjectName(QString::fromUtf8("graphicsView_height"));

        verticalLayout->addWidget(graphicsView_height);

        lineEdit_lhl = new QLineEdit(Gnsslhl_Widget);
        lineEdit_lhl->setObjectName(QString::fromUtf8("lineEdit_lhl"));

        verticalLayout->addWidget(lineEdit_lhl);


        retranslateUi(Gnsslhl_Widget);

        QMetaObject::connectSlotsByName(Gnsslhl_Widget);
    } // setupUi

    void retranslateUi(QWidget *Gnsslhl_Widget)
    {
        Gnsslhl_Widget->setWindowTitle(QApplication::translate("Gnsslhl_Widget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Gnsslhl_Widget: public Ui_Gnsslhl_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GNSSLHL_WIDGET_H
