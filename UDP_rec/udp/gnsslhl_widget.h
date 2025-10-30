#ifndef GNSSLHL_WIDGET_H
#define GNSSLHL_WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QChartView>
#include <QValueAxis>
#include <QLineSeries>
#include <QRandomGenerator>
#include <QtGlobal>
#include <QTime>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class Gnsslhl_Widget;
}

class Gnsslhl_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Gnsslhl_Widget(QWidget *parent = nullptr);
    ~Gnsslhl_Widget();
    void chart_lon_run();
    void chart_lat_run();
    void chart_height_run();
    void lhl_text_run();
    void working(int num);

private slots:
    void slotTimeout_lhl();

private:
    Ui::Gnsslhl_Widget *ui;
    /* 用于模拟生成实时数据的定时器 */
    QTimer* m_timer_lhl;

    /* 图表对象 */
    QChart* m_chart_lon;
    QChart* m_chart_lat;
    QChart* m_chart_height;


    /* 横纵坐标轴对象 */
    QValueAxis *m_axis_lonX, *m_axis_lonY;
    QValueAxis *m_axis_latX, *m_axis_latY;
    QValueAxis *m_axis_heightX, *m_axis_heightY;

    /* 曲线图对象-温度曲线 */
    QLineSeries* m_lineSeries_lon;
    QLineSeries* m_lineSeries_lat;
    QLineSeries* m_lineSeries_height;


    /* 横纵坐标最大显示范围 */
    const float AXIS_MAX_X = 2, AXIS_MAX_Y = 180;
    const float AXIS_MIN_X = 0, AXIS_MIN_Y = 0;

    /* 用来记录数据点数 */
    double pointCount = 0;
};

#endif // GNSSLHL_WIDGET_H
