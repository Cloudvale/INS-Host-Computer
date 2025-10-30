#ifndef CHARTWIDGET_H
#define CHARTWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QChartView>
#include <QValueAxis>
#include <QLineSeries>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class ChartWidget;
}

class ChartWidget : public QWidget/*, public QWidget*/
{
    Q_OBJECT

public:
    explicit ChartWidget(QWidget *parent = nullptr);
    ~ChartWidget();
    void chart_accel_run();
    void chart_accel_rate_run();
    void working(int num);

private slots:
    void on_btnclear_clicked();

    void on_btnStartAndStop_clicked();

    void slotTimeout();

private:
    Ui::ChartWidget *ui;

    /* 用于模拟生成实时数据的定时器 */
    QTimer* m_timer;

    /* 图表对象 */
    QChart* m_chart;
    QChart* m_chart_rate;


    /* 横纵坐标轴对象 */
    QValueAxis *m_axisX, *m_axisY;
    QValueAxis *m_axis_aX, *m_axis_aY;

    /* 曲线图对象-加速度曲线 */
    QLineSeries* m_lineSeries_x;
    QLineSeries* m_lineSeries_y;
    QLineSeries* m_lineSeries_z;

    /* 曲线图对象-角加速度曲线 */
    QLineSeries* m_lineSeries_ax;
    QLineSeries* m_lineSeries_ay;
    QLineSeries* m_lineSeries_az;

    /* 横纵坐标最大显示范围 */
    const int AXIS_MAX_X = 2, AXIS_MAX_Y = 20;
    const int AXIS_MIN_X = 0, AXIS_MIN_Y = -20;

    /* 用来记录数据点数 */
    double pointCount = 0;
};

#endif // CHARTWIDGET_H
