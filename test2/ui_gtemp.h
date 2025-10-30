/********************************************************************************
** Form generated from reading UI file 'gtemp.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GTEMP_H
#define UI_GTEMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_GTemp
{
public:
    QHBoxLayout *horizontalLayout;
    QtCharts::QChartView *graphicsView;

    void setupUi(QWidget *GTemp)
    {
        if (GTemp->objectName().isEmpty())
            GTemp->setObjectName(QString::fromUtf8("GTemp"));
        GTemp->resize(400, 300);
        horizontalLayout = new QHBoxLayout(GTemp);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        graphicsView = new QtCharts::QChartView(GTemp);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        horizontalLayout->addWidget(graphicsView);


        retranslateUi(GTemp);

        QMetaObject::connectSlotsByName(GTemp);
    } // setupUi

    void retranslateUi(QWidget *GTemp)
    {
        GTemp->setWindowTitle(QApplication::translate("GTemp", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GTemp: public Ui_GTemp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GTEMP_H
