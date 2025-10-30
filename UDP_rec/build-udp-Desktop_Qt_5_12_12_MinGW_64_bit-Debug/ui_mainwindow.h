/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_close;
    QAction *action_com;
    QAction *actionUTC;
    QAction *action_temp;
    QAction *actionGPS;
    QAction *actionip;
    QAction *action_start;
    QAction *action_exit;
    QAction *action_send;
    QAction *action_end;
    QAction *action;
    QAction *action_3;
    QAction *action_5;
    QAction *action_9;
    QAction *action_11;
    QAction *action_13;
    QAction *action_14;
    QAction *action_16;
    QAction *actionUTC_2;
    QAction *action_DNU;
    QAction *action_THDV;
    QAction *action_20;
    QAction *action_pos;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout;
    QMdiArea *mdiArea;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menuIMU;
    QMenu *menuIMU_2;
    QMenu *menu_3;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QDockWidget *dockWidget_recv;
    QWidget *dockWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    QPlainTextEdit *plainTextEdit;
    QDockWidget *dockWidget_5;
    QWidget *dockWidgetContents_6;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLineEdit *lineEdit_lon;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLineEdit *lineEdit_lat;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *lineEdit_height;
    QPlainTextEdit *plainTextEdit_send;
    QPushButton *pushButton;
    QDockWidget *dockWidget_7;
    QWidget *dockWidgetContents_9;
    QHBoxLayout *horizontalLayout_4;
    QPlainTextEdit *plainTextEdit_message;
    QToolBar *toolBar_5;
    QToolBar *toolBar_6;
    QToolBar *toolBar_7;
    QToolBar *toolBar_8;
    QToolBar *toolBar_9;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1006, 674);
        action_close = new QAction(MainWindow);
        action_close->setObjectName(QString::fromUtf8("action_close"));
        action_com = new QAction(MainWindow);
        action_com->setObjectName(QString::fromUtf8("action_com"));
        actionUTC = new QAction(MainWindow);
        actionUTC->setObjectName(QString::fromUtf8("actionUTC"));
        action_temp = new QAction(MainWindow);
        action_temp->setObjectName(QString::fromUtf8("action_temp"));
        actionGPS = new QAction(MainWindow);
        actionGPS->setObjectName(QString::fromUtf8("actionGPS"));
        actionip = new QAction(MainWindow);
        actionip->setObjectName(QString::fromUtf8("actionip"));
        action_start = new QAction(MainWindow);
        action_start->setObjectName(QString::fromUtf8("action_start"));
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QString::fromUtf8("action_exit"));
        action_send = new QAction(MainWindow);
        action_send->setObjectName(QString::fromUtf8("action_send"));
        action_end = new QAction(MainWindow);
        action_end->setObjectName(QString::fromUtf8("action_end"));
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        action_5 = new QAction(MainWindow);
        action_5->setObjectName(QString::fromUtf8("action_5"));
        action_9 = new QAction(MainWindow);
        action_9->setObjectName(QString::fromUtf8("action_9"));
        action_9->setEnabled(false);
        action_11 = new QAction(MainWindow);
        action_11->setObjectName(QString::fromUtf8("action_11"));
        action_13 = new QAction(MainWindow);
        action_13->setObjectName(QString::fromUtf8("action_13"));
        action_14 = new QAction(MainWindow);
        action_14->setObjectName(QString::fromUtf8("action_14"));
        action_16 = new QAction(MainWindow);
        action_16->setObjectName(QString::fromUtf8("action_16"));
        actionUTC_2 = new QAction(MainWindow);
        actionUTC_2->setObjectName(QString::fromUtf8("actionUTC_2"));
        action_DNU = new QAction(MainWindow);
        action_DNU->setObjectName(QString::fromUtf8("action_DNU"));
        action_THDV = new QAction(MainWindow);
        action_THDV->setObjectName(QString::fromUtf8("action_THDV"));
        action_20 = new QAction(MainWindow);
        action_20->setObjectName(QString::fromUtf8("action_20"));
        action_pos = new QAction(MainWindow);
        action_pos->setObjectName(QString::fromUtf8("action_pos"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_5 = new QHBoxLayout(centralwidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));

        horizontalLayout->addWidget(mdiArea);


        horizontalLayout_5->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1006, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menuIMU = new QMenu(menu_2);
        menuIMU->setObjectName(QString::fromUtf8("menuIMU"));
        menuIMU_2 = new QMenu(menu_2);
        menuIMU_2->setObjectName(QString::fromUtf8("menuIMU_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMovable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        dockWidget_recv = new QDockWidget(MainWindow);
        dockWidget_recv->setObjectName(QString::fromUtf8("dockWidget_recv"));
        dockWidget_recv->setMaximumSize(QSize(800, 1000));
        dockWidget_recv->setFloating(false);
        dockWidget_recv->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::TopDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        horizontalLayout_2 = new QHBoxLayout(dockWidgetContents);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        plainTextEdit = new QPlainTextEdit(dockWidgetContents);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        horizontalLayout_2->addWidget(plainTextEdit);

        dockWidget_recv->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_recv);
        dockWidget_5 = new QDockWidget(MainWindow);
        dockWidget_5->setObjectName(QString::fromUtf8("dockWidget_5"));
        dockWidgetContents_6 = new QWidget();
        dockWidgetContents_6->setObjectName(QString::fromUtf8("dockWidgetContents_6"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents_6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget = new QWidget(dockWidgetContents_6);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setPointSize(12);
        label_5->setFont(font);

        horizontalLayout_7->addWidget(label_5);

        lineEdit_lon = new QLineEdit(widget_3);
        lineEdit_lon->setObjectName(QString::fromUtf8("lineEdit_lon"));

        horizontalLayout_7->addWidget(lineEdit_lon);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_6 = new QLabel(widget_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        horizontalLayout_3->addWidget(label_6);

        lineEdit_lat = new QLineEdit(widget_3);
        lineEdit_lat->setObjectName(QString::fromUtf8("lineEdit_lat"));

        horizontalLayout_3->addWidget(lineEdit_lat);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(widget_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        horizontalLayout_6->addWidget(label_7);

        lineEdit_height = new QLineEdit(widget_3);
        lineEdit_height->setObjectName(QString::fromUtf8("lineEdit_height"));

        horizontalLayout_6->addWidget(lineEdit_height);


        verticalLayout->addLayout(horizontalLayout_6);


        verticalLayout_2->addWidget(widget_3);

        plainTextEdit_send = new QPlainTextEdit(widget);
        plainTextEdit_send->setObjectName(QString::fromUtf8("plainTextEdit_send"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plainTextEdit_send->sizePolicy().hasHeightForWidth());
        plainTextEdit_send->setSizePolicy(sizePolicy);
        plainTextEdit_send->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_2->addWidget(plainTextEdit_send);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);


        verticalLayout_3->addWidget(widget);

        dockWidget_5->setWidget(dockWidgetContents_6);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_5);
        dockWidget_7 = new QDockWidget(MainWindow);
        dockWidget_7->setObjectName(QString::fromUtf8("dockWidget_7"));
        dockWidget_7->setMaximumSize(QSize(524287, 100));
        dockWidget_7->setFloating(false);
        dockWidgetContents_9 = new QWidget();
        dockWidgetContents_9->setObjectName(QString::fromUtf8("dockWidgetContents_9"));
        horizontalLayout_4 = new QHBoxLayout(dockWidgetContents_9);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        plainTextEdit_message = new QPlainTextEdit(dockWidgetContents_9);
        plainTextEdit_message->setObjectName(QString::fromUtf8("plainTextEdit_message"));
        plainTextEdit_message->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_4->addWidget(plainTextEdit_message);

        dockWidget_7->setWidget(dockWidgetContents_9);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidget_7);
        toolBar_5 = new QToolBar(MainWindow);
        toolBar_5->setObjectName(QString::fromUtf8("toolBar_5"));
        toolBar_5->setMovable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_5);
        MainWindow->insertToolBarBreak(toolBar_5);
        toolBar_6 = new QToolBar(MainWindow);
        toolBar_6->setObjectName(QString::fromUtf8("toolBar_6"));
        toolBar_6->setMovable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_6);
        toolBar_7 = new QToolBar(MainWindow);
        toolBar_7->setObjectName(QString::fromUtf8("toolBar_7"));
        toolBar_7->setMovable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_7);
        toolBar_8 = new QToolBar(MainWindow);
        toolBar_8->setObjectName(QString::fromUtf8("toolBar_8"));
        toolBar_8->setMovable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_8);
        toolBar_9 = new QToolBar(MainWindow);
        toolBar_9->setObjectName(QString::fromUtf8("toolBar_9"));
        toolBar_9->setMovable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_9);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(action_close);
        menu->addSeparator();
        menu->addAction(action_exit);
        menu->addSeparator();
        menu->addAction(action_send);
        menu_2->addAction(menuIMU->menuAction());
        menu_2->addSeparator();
        menu_2->addAction(menuIMU_2->menuAction());
        menuIMU->addAction(action);
        menuIMU->addSeparator();
        menuIMU->addSeparator();
        menuIMU->addAction(action_13);
        menuIMU_2->addAction(action_14);
        menuIMU_2->addSeparator();
        menuIMU_2->addAction(action_16);
        menuIMU_2->addSeparator();
        menuIMU_2->addAction(actionUTC_2);
        toolBar->addAction(action_pos);
        toolBar->addAction(actionUTC);
        toolBar->addAction(action_temp);
        toolBar->addAction(actionGPS);
        toolBar->addAction(action_DNU);
        toolBar->addAction(action_THDV);
        toolBar->addAction(action_start);
        toolBar->addAction(action_end);
        toolBar_5->addAction(action_11);
        toolBar_6->addAction(action_3);
        toolBar_7->addAction(action_20);
        toolBar_7->addSeparator();
        toolBar_8->addAction(action_9);
        toolBar_9->addAction(action_5);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        MainWindow->setWindowFilePath(QString());
        action_close->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255", nullptr));
        action_com->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243\345\217\267", nullptr));
        actionUTC->setText(QApplication::translate("MainWindow", "UTC\346\227\266\351\227\264", nullptr));
        action_temp->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246\346\230\276\347\244\272", nullptr));
        actionGPS->setText(QApplication::translate("MainWindow", "GPS", nullptr));
        actionip->setText(QApplication::translate("MainWindow", "IP\350\256\276\347\275\256", nullptr));
#ifndef QT_NO_TOOLTIP
        actionip->setToolTip(QApplication::translate("MainWindow", "IP\350\256\276\347\275\256", nullptr));
#endif // QT_NO_TOOLTIP
        action_start->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\344\277\235\345\255\230", nullptr));
        action_exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        action_send->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272", nullptr));
#ifndef QT_NO_WHATSTHIS
        action_send->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        action_end->setText(QApplication::translate("MainWindow", "\347\273\223\346\235\237\344\277\235\345\255\230", nullptr));
        action->setText(QApplication::translate("MainWindow", "\347\273\217\347\272\254\351\253\230\345\272\246", nullptr));
        action_3->setText(QApplication::translate("MainWindow", "\350\265\267\345\247\213\344\275\215", nullptr));
#ifndef QT_NO_TOOLTIP
        action_3->setToolTip(QApplication::translate("MainWindow", "\350\265\267\345\247\213\344\275\215", nullptr));
#endif // QT_NO_TOOLTIP
        action_5->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", nullptr));
#ifndef QT_NO_TOOLTIP
        action_5->setToolTip(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", nullptr));
#endif // QT_NO_TOOLTIP
        action_9->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\351\200\211\346\213\251", nullptr));
#ifndef QT_NO_TOOLTIP
        action_9->setToolTip(QApplication::translate("MainWindow", "\344\270\262\345\217\243\351\200\211\346\213\251", nullptr));
#endif // QT_NO_TOOLTIP
        action_11->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        action_13->setText(QApplication::translate("MainWindow", "\347\262\276\345\272\246\345\233\240\345\255\220", nullptr));
        action_14->setText(QApplication::translate("MainWindow", "\345\216\237\345\247\213\346\225\260\346\215\256", nullptr));
        action_16->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246", nullptr));
        actionUTC_2->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264UTC", nullptr));
#ifndef QT_NO_TOOLTIP
        actionUTC_2->setToolTip(QApplication::translate("MainWindow", "\346\227\266\351\227\264UTC", nullptr));
#endif // QT_NO_TOOLTIP
        action_DNU->setText(QApplication::translate("MainWindow", "\344\270\234\345\214\227\345\244\251\351\200\237\345\272\246", nullptr));
        action_THDV->setText(QApplication::translate("MainWindow", "\347\262\276\345\272\246\345\233\240\345\255\220", nullptr));
        action_20->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\346\223\215\344\275\234", nullptr));
#ifndef QT_NO_TOOLTIP
        action_20->setToolTip(QApplication::translate("MainWindow", "\344\270\262\345\217\243\346\223\215\344\275\234", nullptr));
#endif // QT_NO_TOOLTIP
        action_pos->setText(QApplication::translate("MainWindow", "\345\247\277\346\200\201\346\225\260\346\215\256", nullptr));
#ifndef QT_NO_TOOLTIP
        action_pos->setToolTip(QApplication::translate("MainWindow", "\345\247\277\346\200\201\346\225\260\346\215\256", nullptr));
#endif // QT_NO_TOOLTIP
        menu->setTitle(QApplication::translate("MainWindow", " \346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\350\247\206\345\233\276", nullptr));
        menuIMU->setTitle(QApplication::translate("MainWindow", "GNSS\346\225\260\346\215\256", nullptr));
        menuIMU_2->setTitle(QApplication::translate("MainWindow", "IMU\346\225\260\346\215\256", nullptr));
        menu_3->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
#ifndef QT_NO_WHATSTHIS
        dockWidget_recv->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        dockWidget_recv->setWindowTitle(QApplication::translate("MainWindow", "\345\275\223\345\211\215\346\216\245\346\224\266\346\225\260\346\215\256\346\230\276\347\244\272", "send"));
#ifndef QT_NO_WHATSTHIS
        dockWidgetContents->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        dockWidget_5->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        dockWidget_5->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        dockWidget_5->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        dockWidget_5->setWindowTitle(QApplication::translate("MainWindow", "\345\275\223\345\211\215\345\217\221\351\200\201\346\225\260\346\215\256\350\276\223\345\205\245", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\347\273\217\345\272\246", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\347\272\254\345\272\246", nullptr));
        lineEdit_lat->setText(QString());
        label_7->setText(QApplication::translate("MainWindow", "\351\253\230\345\272\246", nullptr));
        lineEdit_height->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\345\217\221\351\200\201", nullptr));
        dockWidget_7->setWindowTitle(QApplication::translate("MainWindow", "\346\266\210\346\201\257\346\217\220\347\244\272", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        dockWidgetContents_9->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        toolBar_5->setWindowTitle(QApplication::translate("MainWindow", "toolBar_5", nullptr));
        toolBar_6->setWindowTitle(QApplication::translate("MainWindow", "toolBar_6", nullptr));
        toolBar_7->setWindowTitle(QApplication::translate("MainWindow", "toolBar_8", nullptr));
        toolBar_8->setWindowTitle(QApplication::translate("MainWindow", "toolBar_3", nullptr));
        toolBar_9->setWindowTitle(QApplication::translate("MainWindow", "toolBar_7", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
