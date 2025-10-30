#ifndef TEMPWIDGET_H
#define TEMPWIDGET_H

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
class TempWidget;
}

class TempWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TempWidget(QWidget *parent = nullptr);
    ~TempWidget();
    void chart_temp_run();
    void temp_text_run();
    void working(int num);

    float temp;

private slots:
    void slotTimeout_temp();

private:
    Ui::TempWidget *ui;
    /* 用于模拟生成实时数据的定时器 */
    QTimer* m_timer_temp;

    /* 图表对象 */
    QChart* m_chart_temp;
//    QChart* m_chart_rate;


    /* 横纵坐标轴对象 */
    QValueAxis *m_axis_tX, *m_axis_tY;

    /* 曲线图对象-温度曲线 */
    QLineSeries* m_lineSeries_temp;



    /* 横纵坐标最大显示范围 */
    const int AXIS_MAX_X = 2, AXIS_MAX_Y = 50;
    const int AXIS_MIN_X = 0, AXIS_MIN_Y = -20;
    /* 用来记录数据点数 */
    double pointCount = 0;
};

#endif // TEMPWIDGET_H
