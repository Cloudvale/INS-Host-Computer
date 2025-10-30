#-------------------------------------------------
#
# Project created by QtCreator 2022-09-27T20:15:14
#
#-------------------------------------------------

QT       += core gui

QT       += network
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = udp
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11


#MATERILA_ADD
LIBS += $$PWD/libs/libcomponents.a
INCLUDEPATH += $$PWD/libs/Include
#PRE_TARGETDEPS += $$PWD/libs
PRE_TARGETDEPS += $$PWD/libs/libcomponents.a

SOURCES += \
        chartwidget.cpp \
        datatransfer.cpp \
        framelessWidget.cpp \
        gnss_dbtwidget.cpp \
        gnsslhl_widget.cpp \
        main.cpp \
        Widget.cpp \
        mainwindow.cpp \
        mythread.cpp \
        precision_factorwidget.cpp \
        tempwidget.cpp \
        utctext.cpp

HEADERS += \
        Widget.h \
        chartwidget.h \
        datatransfer.h \
        framelessWidget.h \
        gnss_dbtwidget.h \
        gnsslhl_widget.h \
        mainwindow.h \
        mythread.h \
        precision_factorwidget.h \
        tempwidget.h \
        utctext.h

FORMS += \
        Widget.ui \
        chartwidget.ui \
        framelessWidget.ui \
        gnss_dbtwidget.ui \
        gnsslhl_widget.ui \
        mainwindow.ui \
        precision_factorwidget.ui \
        tempwidget.ui \
        utctext.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES += \
    resource.qrc
