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
    QAction *action_pos;
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
    QAction *action_7;
    QAction *action_9;
    QAction *action_11;
    QAction *action_13;
    QAction *action_14;
    QAction *action_16;
    QAction *actionUTC_2;
    QAction *action_DNU;
    QAction *action_THDV;
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
    QToolBar *toolBar_2;
    QToolBar *toolBar_3;
    QDockWidget *dockWidget_recv;
    QWidget *dockWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    QPlainTextEdit *plainTextEdit;
    QDockWidget *dockWidget_5;
    QWidget *dockWidgetContents_6;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QVBoxLayout *verticalLayout_2;
    QPlainTextEdit *plainTextEdit_send;
    QPushButton *pushButton;
    QDockWidget *dockWidget_7;
    QWidget *dockWidgetContents_9;
    QHBoxLayout *horizontalLayout_4;
    QPlainTextEdit *plainTextEdit_message;
    QToolBar *toolBar_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1006, 674);
        action_close = new QAction(MainWindow);
        action_close->setObjectName(QString::fromUtf8("action_close"));
        action_com = new QAction(MainWindow);
        action_com->setObjectName(QString::fromUtf8("action_com"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/qtsss/MTXX_MH20230811_022920944.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        action_com->setIcon(icon);
        action_pos = new QAction(MainWindow);
        action_pos->setObjectName(QString::fromUtf8("action_pos"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/qtsss/MTXX_MH20230811_022842262.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        action_pos->setIcon(icon1);
        actionUTC = new QAction(MainWindow);
        actionUTC->setObjectName(QString::fromUtf8("actionUTC"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/qtsss/MTXX_MH20230811_022901695.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionUTC->setIcon(icon2);
        action_temp = new QAction(MainWindow);
        action_temp->setObjectName(QString::fromUtf8("action_temp"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/qtsss/MTXX_MH20230811_023019451.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        action_temp->setIcon(icon3);
        actionGPS = new QAction(MainWindow);
        actionGPS->setObjectName(QString::fromUtf8("actionGPS"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/qtsss/MTXX_MH20230811_022940433.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionGPS->setIcon(icon4);
        actionip = new QAction(MainWindow);
        actionip->setObjectName(QString::fromUtf8("actionip"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/qtsss/MTXX_MH20230811_022821689.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionip->setIcon(icon5);
        action_start = new QAction(MainWindow);
        action_start->setObjectName(QString::fromUtf8("action_start"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/qtsss/MTXX_MH20230811_023001342.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        action_start->setIcon(icon6);
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QString::fromUtf8("action_exit"));
        action_send = new QAction(MainWindow);
        action_send->setObjectName(QString::fromUtf8("action_send"));
        action_end = new QAction(MainWindow);
        action_end->setObjectName(QString::fromUtf8("action_end"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/qtsss/MTXX_MH20230811_023250715.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        action_end->setIcon(icon7);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        action_5 = new QAction(MainWindow);
        action_5->setObjectName(QString::fromUtf8("action_5"));
        action_7 = new QAction(MainWindow);
        action_7->setObjectName(QString::fromUtf8("action_7"));
        action_9 = new QAction(MainWindow);
        action_9->setObjectName(QString::fromUtf8("action_9"));
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
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("qtsss/R-C.png"), QSize(), QIcon::Normal, QIcon::On);
        action_DNU->setIcon(icon8);
        action_THDV = new QAction(MainWindow);
        action_THDV->setObjectName(QString::fromUtf8("action_THDV"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("qtsss/QQ\346\210\252\345\233\27620230811020912.png"), QSize(), QIcon::Normal, QIcon::On);
        action_THDV->setIcon(icon9);
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
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        toolBar_2->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);
        toolBar_3 = new QToolBar(MainWindow);
        toolBar_3->setObjectName(QString::fromUtf8("toolBar_3"));
        toolBar_3->setContextMenuPolicy(Qt::DefaultContextMenu);
        toolBar_3->setToolButtonStyle(Qt::ToolButtonFollowStyle);
        toolBar_3->setFloatable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_3);
        dockWidget_recv = new QDockWidget(MainWindow);
        dockWidget_recv->setObjectName(QString::fromUtf8("dockWidget_recv"));
        dockWidget_recv->setMaximumSize(QSize(220, 400));
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
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_6 = new QHBoxLayout(widget_4);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setPointSize(12);
        label_3->setFont(font);

        horizontalLayout_6->addWidget(label_3);

        lineEdit_3 = new QLineEdit(widget_4);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_6->addWidget(lineEdit_3);


        verticalLayout->addWidget(widget_4);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout_3->addWidget(label);

        lineEdit_2 = new QLineEdit(widget_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_3->addWidget(lineEdit_2);


        verticalLayout->addWidget(widget_2);


        verticalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        plainTextEdit_send = new QPlainTextEdit(widget);
        plainTextEdit_send->setObjectName(QString::fromUtf8("plainTextEdit_send"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plainTextEdit_send->sizePolicy().hasHeightForWidth());
        plainTextEdit_send->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(plainTextEdit_send);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);


        verticalLayout_4->addLayout(verticalLayout_2);


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
        toolBar_4 = new QToolBar(MainWindow);
        toolBar_4->setObjectName(QString::fromUtf8("toolBar_4"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_4);

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
        menuIMU->addAction(action_7);
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
        toolBar->addSeparator();
        toolBar_2->addAction(action_com);
        toolBar_3->addAction(actionip);
        toolBar_4->addAction(action_start);
        toolBar_4->addAction(action_end);
        toolBar_4->addAction(action_DNU);
        toolBar_4->addAction(action_THDV);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        MainWindow->setWindowFilePath(QString());
        action_close->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255", nullptr));
        action_com->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243\345\217\267", nullptr));
        action_pos->setText(QApplication::translate("MainWindow", "\345\247\277\346\200\201\346\225\260\346\215\256", nullptr));
        actionUTC->setText(QApplication::translate("MainWindow", "UTC\346\227\266\351\227\264", nullptr));
        action_temp->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246\346\230\276\347\244\272", nullptr));
        actionGPS->setText(QApplication::translate("MainWindow", "GPS", nullptr));
        actionip->setText(QApplication::translate("MainWindow", "ip", nullptr));
        action_start->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\344\277\235\345\255\230", nullptr));
        action_exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        action_send->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272", nullptr));
#ifndef QT_NO_WHATSTHIS
        action_send->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        action_end->setText(QApplication::translate("MainWindow", "\347\273\223\346\235\237\344\277\235\345\255\230", nullptr));
        action->setText(QApplication::translate("MainWindow", "\347\273\217\347\272\254\351\253\230\345\272\246", nullptr));
        action_3->setText(QApplication::translate("MainWindow", "\347\272\254\345\272\246", nullptr));
        action_5->setText(QApplication::translate("MainWindow", "\351\253\230\345\272\246", nullptr));
        action_7->setText(QApplication::translate("MainWindow", "\344\270\234\345\214\227\345\244\251\345\220\221\351\200\237\345\272\246", nullptr));
        action_9->setText(QApplication::translate("MainWindow", "\345\214\227\345\220\221\351\200\237\345\272\246", nullptr));
        action_11->setText(QApplication::translate("MainWindow", "\345\244\251\345\220\221\351\200\237\345\272\246", nullptr));
        action_13->setText(QApplication::translate("MainWindow", "\347\262\276\345\272\246\345\233\240\345\255\220", nullptr));
        action_14->setText(QApplication::translate("MainWindow", "\345\216\237\345\247\213\346\225\260\346\215\256", nullptr));
        action_16->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246", nullptr));
        actionUTC_2->setText(QApplication::translate("MainWindow", "UTC\346\227\266\351\227\264", nullptr));
        action_DNU->setText(QApplication::translate("MainWindow", "\344\270\234\345\214\227\345\244\251\351\200\237\345\272\246", nullptr));
        action_THDV->setText(QApplication::translate("MainWindow", "\347\262\276\345\272\246\345\233\240\345\255\220", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", " \346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\350\247\206\345\233\276", nullptr));
        menuIMU->setTitle(QApplication::translate("MainWindow", "GNSS\346\225\260\346\215\256", nullptr));
        menuIMU_2->setTitle(QApplication::translate("MainWindow", "IMU\346\225\260\346\215\256", nullptr));
        menu_3->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", nullptr));
        toolBar_3->setWindowTitle(QApplication::translate("MainWindow", "toolBar_3", nullptr));
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
        label_3->setText(QApplication::translate("MainWindow", "\347\272\254\345\272\246", nullptr));
        label->setText(QApplication::translate("MainWindow", "\347\273\217\345\272\246", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\345\217\221\351\200\201", nullptr));
        dockWidget_7->setWindowTitle(QApplication::translate("MainWindow", "\346\266\210\346\201\257\346\217\220\347\244\272", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        dockWidgetContents_9->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        toolBar_4->setWindowTitle(QApplication::translate("MainWindow", "toolBar_4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
