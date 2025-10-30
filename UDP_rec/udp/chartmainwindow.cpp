#include "chartmainwindow.h"
#include "ui_chartmainwindow.h"

ChartMainWindow::ChartMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChartMainWindow)
{
    ui->setupUi(this);
}

ChartMainWindow::~ChartMainWindow()
{
    delete ui;
}
