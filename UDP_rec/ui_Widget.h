/********************************************************************************
** Form generated from reading UI file 'Widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPlainTextEdit *plainTextEdit;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label;
    QSpinBox *spinBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_save_start;
    QPushButton *pushButton_save_end;
    QLabel *label_PDOP;
    QLabel *label_HDOP;
    QLabel *label_VDOP;
    QLabel *label_TDOP;
    QLabel *label_GDOP;
    QLabel *label_Lon;
    QLineEdit *lineEdit_PDOP;
    QLineEdit *lineEdit_HDOP;
    QLabel *label_Lat;
    QLabel *label_Alts;
    QLabel *label_EastVel;
    QLabel *label_NorthVel;
    QLabel *label_UphVel;
    QLabel *label_ac_x;
    QLabel *label_ac_y;
    QLabel *label_ac_z;
    QLabel *label_angl_x;
    QLabel *label_angl_y;
    QLabel *label_angl_z;
    QLineEdit *lineEdit_VDOP;
    QLineEdit *lineEdit_TDOP;
    QLineEdit *lineEdit_GDOP;
    QLineEdit *lineEdit_Lat;
    QLineEdit *lineEdit_Lon;
    QLineEdit *lineEdit_ALts;
    QLineEdit *lineEdit_EastVel;
    QLineEdit *lineEdit_NorthVel;
    QLineEdit *lineEdit_UpVel;
    QLineEdit *lineEdit_ac_x;
    QLineEdit *lineEdit_ac_y;
    QLineEdit *lineEdit_ac_z;
    QLineEdit *lineEdit_angl_x;
    QLineEdit *lineEdit_angl_y;
    QLineEdit *lineEdit_angl_z;
    QLabel *label_sig;
    QLineEdit *lineEdit_sig;
    QLabel *label_heading;
    QLineEdit *lineEdit_headings;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(798, 418);
        QFont font;
        font.setPointSize(12);
        Widget->setFont(font);
        plainTextEdit = new QPlainTextEdit(Widget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 90, 531, 211));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 11, 568, 76));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setFont(font);

        gridLayout->addWidget(lineEdit, 0, 4, 1, 1);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font);

        gridLayout->addWidget(pushButton, 1, 3, 1, 2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        spinBox = new QSpinBox(layoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setFont(font);
        spinBox->setMaximum(99999);
        spinBox->setValue(1200);

        gridLayout->addWidget(spinBox, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(110, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        pushButton_save_start = new QPushButton(Widget);
        pushButton_save_start->setObjectName(QString::fromUtf8("pushButton_save_start"));
        pushButton_save_start->setGeometry(QRect(10, 310, 121, 31));
        pushButton_save_start->setFont(font);
        pushButton_save_end = new QPushButton(Widget);
        pushButton_save_end->setObjectName(QString::fromUtf8("pushButton_save_end"));
        pushButton_save_end->setGeometry(QRect(20, 350, 101, 31));
        pushButton_save_end->setFont(font);
        label_PDOP = new QLabel(Widget);
        label_PDOP->setObjectName(QString::fromUtf8("label_PDOP"));
        label_PDOP->setGeometry(QRect(600, 20, 54, 12));
        label_PDOP->setFont(font);
        label_HDOP = new QLabel(Widget);
        label_HDOP->setObjectName(QString::fromUtf8("label_HDOP"));
        label_HDOP->setGeometry(QRect(600, 50, 54, 12));
        label_HDOP->setFont(font);
        label_VDOP = new QLabel(Widget);
        label_VDOP->setObjectName(QString::fromUtf8("label_VDOP"));
        label_VDOP->setGeometry(QRect(600, 80, 54, 12));
        label_VDOP->setFont(font);
        label_TDOP = new QLabel(Widget);
        label_TDOP->setObjectName(QString::fromUtf8("label_TDOP"));
        label_TDOP->setGeometry(QRect(600, 110, 54, 12));
        label_TDOP->setFont(font);
        label_GDOP = new QLabel(Widget);
        label_GDOP->setObjectName(QString::fromUtf8("label_GDOP"));
        label_GDOP->setGeometry(QRect(600, 140, 54, 12));
        label_GDOP->setFont(font);
        label_Lon = new QLabel(Widget);
        label_Lon->setObjectName(QString::fromUtf8("label_Lon"));
        label_Lon->setGeometry(QRect(600, 170, 31, 16));
        label_Lon->setFont(font);
        lineEdit_PDOP = new QLineEdit(Widget);
        lineEdit_PDOP->setObjectName(QString::fromUtf8("lineEdit_PDOP"));
        lineEdit_PDOP->setGeometry(QRect(660, 20, 113, 20));
        lineEdit_PDOP->setFont(font);
        lineEdit_HDOP = new QLineEdit(Widget);
        lineEdit_HDOP->setObjectName(QString::fromUtf8("lineEdit_HDOP"));
        lineEdit_HDOP->setGeometry(QRect(660, 50, 113, 20));
        label_Lat = new QLabel(Widget);
        label_Lat->setObjectName(QString::fromUtf8("label_Lat"));
        label_Lat->setGeometry(QRect(600, 210, 31, 16));
        label_Lat->setFont(font);
        label_Alts = new QLabel(Widget);
        label_Alts->setObjectName(QString::fromUtf8("label_Alts"));
        label_Alts->setGeometry(QRect(600, 240, 31, 16));
        label_Alts->setFont(font);
        label_EastVel = new QLabel(Widget);
        label_EastVel->setObjectName(QString::fromUtf8("label_EastVel"));
        label_EastVel->setGeometry(QRect(600, 280, 61, 16));
        label_EastVel->setFont(font);
        label_NorthVel = new QLabel(Widget);
        label_NorthVel->setObjectName(QString::fromUtf8("label_NorthVel"));
        label_NorthVel->setGeometry(QRect(590, 320, 61, 16));
        label_NorthVel->setFont(font);
        label_UphVel = new QLabel(Widget);
        label_UphVel->setObjectName(QString::fromUtf8("label_UphVel"));
        label_UphVel->setGeometry(QRect(610, 350, 61, 16));
        label_UphVel->setFont(font);
        label_ac_x = new QLabel(Widget);
        label_ac_x->setObjectName(QString::fromUtf8("label_ac_x"));
        label_ac_x->setGeometry(QRect(160, 310, 61, 16));
        label_ac_x->setFont(font);
        label_ac_y = new QLabel(Widget);
        label_ac_y->setObjectName(QString::fromUtf8("label_ac_y"));
        label_ac_y->setGeometry(QRect(160, 340, 61, 16));
        label_ac_y->setFont(font);
        label_ac_z = new QLabel(Widget);
        label_ac_z->setObjectName(QString::fromUtf8("label_ac_z"));
        label_ac_z->setGeometry(QRect(160, 370, 61, 16));
        label_ac_z->setFont(font);
        label_angl_x = new QLabel(Widget);
        label_angl_x->setObjectName(QString::fromUtf8("label_angl_x"));
        label_angl_x->setGeometry(QRect(320, 310, 101, 20));
        label_angl_x->setFont(font);
        label_angl_y = new QLabel(Widget);
        label_angl_y->setObjectName(QString::fromUtf8("label_angl_y"));
        label_angl_y->setGeometry(QRect(320, 340, 101, 20));
        label_angl_y->setFont(font);
        label_angl_z = new QLabel(Widget);
        label_angl_z->setObjectName(QString::fromUtf8("label_angl_z"));
        label_angl_z->setGeometry(QRect(320, 370, 101, 20));
        label_angl_z->setFont(font);
        lineEdit_VDOP = new QLineEdit(Widget);
        lineEdit_VDOP->setObjectName(QString::fromUtf8("lineEdit_VDOP"));
        lineEdit_VDOP->setGeometry(QRect(660, 80, 113, 20));
        lineEdit_TDOP = new QLineEdit(Widget);
        lineEdit_TDOP->setObjectName(QString::fromUtf8("lineEdit_TDOP"));
        lineEdit_TDOP->setGeometry(QRect(660, 110, 113, 20));
        lineEdit_GDOP = new QLineEdit(Widget);
        lineEdit_GDOP->setObjectName(QString::fromUtf8("lineEdit_GDOP"));
        lineEdit_GDOP->setGeometry(QRect(660, 140, 113, 20));
        lineEdit_Lat = new QLineEdit(Widget);
        lineEdit_Lat->setObjectName(QString::fromUtf8("lineEdit_Lat"));
        lineEdit_Lat->setGeometry(QRect(660, 170, 113, 20));
        lineEdit_Lon = new QLineEdit(Widget);
        lineEdit_Lon->setObjectName(QString::fromUtf8("lineEdit_Lon"));
        lineEdit_Lon->setGeometry(QRect(660, 210, 113, 20));
        lineEdit_ALts = new QLineEdit(Widget);
        lineEdit_ALts->setObjectName(QString::fromUtf8("lineEdit_ALts"));
        lineEdit_ALts->setGeometry(QRect(660, 240, 113, 20));
        lineEdit_EastVel = new QLineEdit(Widget);
        lineEdit_EastVel->setObjectName(QString::fromUtf8("lineEdit_EastVel"));
        lineEdit_EastVel->setGeometry(QRect(660, 280, 113, 20));
        lineEdit_NorthVel = new QLineEdit(Widget);
        lineEdit_NorthVel->setObjectName(QString::fromUtf8("lineEdit_NorthVel"));
        lineEdit_NorthVel->setGeometry(QRect(660, 320, 113, 20));
        lineEdit_UpVel = new QLineEdit(Widget);
        lineEdit_UpVel->setObjectName(QString::fromUtf8("lineEdit_UpVel"));
        lineEdit_UpVel->setGeometry(QRect(660, 350, 113, 20));
        lineEdit_ac_x = new QLineEdit(Widget);
        lineEdit_ac_x->setObjectName(QString::fromUtf8("lineEdit_ac_x"));
        lineEdit_ac_x->setGeometry(QRect(230, 310, 81, 20));
        lineEdit_ac_y = new QLineEdit(Widget);
        lineEdit_ac_y->setObjectName(QString::fromUtf8("lineEdit_ac_y"));
        lineEdit_ac_y->setGeometry(QRect(230, 340, 81, 20));
        lineEdit_ac_z = new QLineEdit(Widget);
        lineEdit_ac_z->setObjectName(QString::fromUtf8("lineEdit_ac_z"));
        lineEdit_ac_z->setGeometry(QRect(230, 370, 81, 20));
        lineEdit_angl_x = new QLineEdit(Widget);
        lineEdit_angl_x->setObjectName(QString::fromUtf8("lineEdit_angl_x"));
        lineEdit_angl_x->setGeometry(QRect(430, 310, 91, 20));
        lineEdit_angl_y = new QLineEdit(Widget);
        lineEdit_angl_y->setObjectName(QString::fromUtf8("lineEdit_angl_y"));
        lineEdit_angl_y->setGeometry(QRect(430, 340, 91, 20));
        lineEdit_angl_z = new QLineEdit(Widget);
        lineEdit_angl_z->setObjectName(QString::fromUtf8("lineEdit_angl_z"));
        lineEdit_angl_z->setGeometry(QRect(430, 370, 91, 20));
        label_sig = new QLabel(Widget);
        label_sig->setObjectName(QString::fromUtf8("label_sig"));
        label_sig->setGeometry(QRect(610, 380, 61, 16));
        label_sig->setFont(font);
        lineEdit_sig = new QLineEdit(Widget);
        lineEdit_sig->setObjectName(QString::fromUtf8("lineEdit_sig"));
        lineEdit_sig->setGeometry(QRect(660, 380, 113, 20));
        label_heading = new QLabel(Widget);
        label_heading->setObjectName(QString::fromUtf8("label_heading"));
        label_heading->setGeometry(QRect(10, 390, 71, 16));
        label_heading->setFont(font);
        lineEdit_headings = new QLineEdit(Widget);
        lineEdit_headings->setObjectName(QString::fromUtf8("lineEdit_headings"));
        lineEdit_headings->setGeometry(QRect(80, 390, 113, 20));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        lineEdit->setText(QCoreApplication::translate("Widget", "192.168.1.106", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\347\273\221\345\256\232\347\253\257\345\217\243", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\347\233\256\346\240\207\345\234\260\345\235\200", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\347\233\256\346\240\207\347\253\257\345\217\243", nullptr));
        pushButton_save_start->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213\344\277\235\345\255\230", nullptr));
        pushButton_save_end->setText(QCoreApplication::translate("Widget", "\345\205\263\351\227\255\344\277\235\345\255\230", nullptr));
        label_PDOP->setText(QCoreApplication::translate("Widget", "PDOP", nullptr));
        label_HDOP->setText(QCoreApplication::translate("Widget", "HDOP", nullptr));
        label_VDOP->setText(QCoreApplication::translate("Widget", "VDOP", nullptr));
        label_TDOP->setText(QCoreApplication::translate("Widget", "TDOP", nullptr));
        label_GDOP->setText(QCoreApplication::translate("Widget", "GDOP", nullptr));
        label_Lon->setText(QCoreApplication::translate("Widget", "Lon", nullptr));
        label_Lat->setText(QCoreApplication::translate("Widget", "Lat", nullptr));
        label_Alts->setText(QCoreApplication::translate("Widget", "Alts", nullptr));
        label_EastVel->setText(QCoreApplication::translate("Widget", "EastVel", nullptr));
        label_NorthVel->setText(QCoreApplication::translate("Widget", "NorthVel", nullptr));
        label_UphVel->setText(QCoreApplication::translate("Widget", "UpVel", nullptr));
        label_ac_x->setText(QCoreApplication::translate("Widget", "accel_x", nullptr));
        label_ac_y->setText(QCoreApplication::translate("Widget", "accel_y", nullptr));
        label_ac_z->setText(QCoreApplication::translate("Widget", "accel_z", nullptr));
        label_angl_x->setText(QCoreApplication::translate("Widget", "angle_rate_x", nullptr));
        label_angl_y->setText(QCoreApplication::translate("Widget", "angle_rate_y", nullptr));
        label_angl_z->setText(QCoreApplication::translate("Widget", "angle_rate_z", nullptr));
        label_sig->setText(QCoreApplication::translate("Widget", "sig", nullptr));
        label_heading->setText(QCoreApplication::translate("Widget", "heading", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
