#include <QApplication>
#include "mainwindow.h"
#include "datatransfer.h"


using namespace test;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}


