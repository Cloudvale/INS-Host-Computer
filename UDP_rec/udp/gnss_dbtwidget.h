#ifndef GNSS_DBTWIDGET_H
#define GNSS_DBTWIDGET_H

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
class Gnss_dbtWidget;
}

class Gnss_dbtWidget : public QWidget
{
    Q_OBJECT

public:
    explicit Gnss_dbtWidget(QWidget *parent = nullptr);
    ~Gnss_dbtWidget();
    void chart_East_run();
    void chart_North_run();
    void chart_Up_run();
    void DNU_text_run();
    void working(int num);

private slots:
    void slotTimeout_DNU();

private:
    Ui::Gnss_dbtWidget *ui;
    /* 用于模拟生成实时数据的定时器 */
    QTimer* m_timer_DNU;

    /* 图表对象 */
    QChart* m_chart_east;
    QChart* m_chart_north;
    QChart* m_chart_up;


    /* 横纵坐标轴对象 */
    QValueAxis *m_axis_eastX, *m_axis_eastY;
    QValueAxis *m_axis_northX, *m_axis_northY;
    QValueAxis *m_axis_upX, *m_axis_upY;

    /* 曲线图对象-温度曲线 */
    QLineSeries* m_lineSeries_east;
    QLineSeries* m_lineSeries_north;
    QLineSeries* m_lineSeries_up;


    /* 横纵坐标最大显示范围 */
    const int AXIS_MAX_X = 2, AXIS_MAX_Y = 10;
    const int AXIS_MIN_X = 0, AXIS_MIN_Y = -10;

    /* 用来记录数据点数 */
    double pointCount = 0;
};

#endif // GNSS_DBTWIDGET_H
