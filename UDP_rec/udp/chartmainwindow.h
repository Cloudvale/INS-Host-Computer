#ifndef CHARTMAINWINDOW_H
#define CHARTMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class ChartMainWindow;
}

class ChartMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChartMainWindow(QWidget *parent = nullptr);
    ~ChartMainWindow();

private:
    Ui::ChartMainWindow *ui;
};

#endif // CHARTMAINWINDOW_H
