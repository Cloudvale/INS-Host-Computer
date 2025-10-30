#include "chartwidget.h"
#include "ui_chartwidget.h"
#include <QChart>
#include <mainwindow.h>
#include "datatransfer.h"

using namespace test;

ChartWidget::ChartWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChartWidget)
{
    ui->setupUi(this);

//    ui->ChartWidget->resize(1000, 700);
//    resize(1000,700);


//    m_timer = new QTimer(this);
//    m_timer->setSingleShot(false);
//    QObject::connect(m_timer, SIGNAL(timeout()), this, SLOT(slotTimeout()));

    chart_accel_run();                //加速度（accel）图表实现函数
    chart_accel_rate_run();           //角加速度（angle_accel）图表实现函数


    //开始时即开始进行曲线显示
//    pointCount = 0;
//    m_timer->start(5);
//    ui->btnStartAndStop->setText("停止定时器");

}

ChartWidget::~ChartWidget()
{
    test::IMU_flag = 0;   //没有执行
    delete ui;
}

void ChartWidget::on_btnclear_clicked()
{
    m_lineSeries_x->clear();
    m_lineSeries_y->clear();
    m_lineSeries_z->clear();
    m_chart->axisX()->setMin(AXIS_MIN_X);
    m_chart->axisX()->setMax(AXIS_MAX_X);

    m_lineSeries_ax->clear();
    m_lineSeries_ay->clear();
    m_lineSeries_az->clear();
    m_chart_rate->axisX()->setMin(AXIS_MIN_X);
    m_chart_rate->axisX()->setMax(AXIS_MAX_X);

    pointCount = 0;

}

void ChartWidget::on_btnStartAndStop_clicked()
{
//    if(m_timer->isActive())
//    {
//        m_timer->stop();
//        ui->btnStartAndStop->setText("启动定时器");
//    }else
//    {
//        pointCount = 0;
//        m_timer->start(5);
//        ui->btnStartAndStop->setText("停止定时器");
//    }

}

void ChartWidget::slotTimeout()
{
    static int i=0;
//    qDebug() << "imu生成随机数的线程的线程地址: "<<i++ <<"pointCount:"<<pointCount<< QThread::currentThread();
    if(pointCount > AXIS_MAX_X)
    {
        m_lineSeries_x->remove(0);
        m_lineSeries_y->remove(0);
        m_lineSeries_z->remove(0);
        m_lineSeries_ax->remove(0);
        m_lineSeries_ay->remove(0);
        m_lineSeries_az->remove(0);

        m_chart->axisX()->setMin(pointCount - AXIS_MAX_X);
        m_chart->axisX()->setMax(pointCount);                    // 更新X轴范围
        m_chart_rate->axisX()->setMin(pointCount - AXIS_MAX_X);
        m_chart_rate->axisX()->setMax(pointCount);                    // 更新X轴范围
    }

    m_lineSeries_x->append(QPointF(pointCount, num_ac_x));  // 更新显示（随机生成10以内的一个数）
    m_lineSeries_y->append(QPointF(pointCount, num_ac_y));  // 更新显示（随机生成10以内的一个数）
    m_lineSeries_z->append(QPointF(pointCount, num_ac_z));  // 更新显示（随机生成10以内的一个数）

    m_lineSeries_ax->append(QPointF(pointCount, num_angle_rate_x));  // 更新显示（随机生成10以内的一个数）
    m_lineSeries_ay->append(QPointF(pointCount, num_angle_rate_y));  // 更新显示（随机生成10以内的一个数）
    m_lineSeries_az->append(QPointF(pointCount, num_angle_rate_z));  // 更新显示（随机生成10以内的一个数）

//    num_ac_x=0;num_ac_y=0;num_ac_z=0;num_angle_rate_x=0;num_angle_rate_y=0;num_angle_rate_z=0;

//    m_lineSeries_x->append(QPointF(pointCount, rand() % AXIS_MAX_Y));  // 更新显示（随机生成10以内的一个数）
//    m_lineSeries_y->append(QPointF(pointCount, rand() % AXIS_MAX_Y));  // 更新显示（随机生成10以内的一个数）
//    m_lineSeries_z->append(QPointF(pointCount, rand() % AXIS_MAX_Y));  // 更新显示（随机生成10以内的一个数）

//    m_lineSeries_ax->append(QPointF(pointCount, rand() % AXIS_MAX_Y));  // 更新显示（随机生成10以内的一个数）
//    m_lineSeries_ay->append(QPointF(pointCount, rand() % AXIS_MAX_Y));  // 更新显示（随机生成10以内的一个数）
//    m_lineSeries_az->append(QPointF(pointCount, rand() % AXIS_MAX_Y));  // 更新显示（随机生成10以内的一个数）
    pointCount+=0.2;
}

void ChartWidget::chart_accel_run()
{
    // 创建横纵坐标轴并设置显示范围
    //
    QFont font("Arial", 10);  // 设置字体和字号
    m_axisX = new QValueAxis();
    m_axisY = new QValueAxis();
    m_axisX->setTitleFont(font);  // 修改时间轴标题字体
    m_axisY->setTitleFont(font);  // 修改时间轴标题字体
    m_axisX->setTitleText("时间");
    QString str = QString::fromUtf8("m/x\xC2\xB2");
    m_axisY->setTitleText(str);
    m_axisX->setMin(AXIS_MIN_X);
    m_axisY->setMin(AXIS_MIN_Y);
    m_axisX->setMax(AXIS_MAX_X);
    m_axisY->setMax(AXIS_MAX_Y);

    m_axisY->setTickCount(4);
    m_axisY->setLabelFormat("%.2f");
    m_axisY->setMinorTickCount(5); // 设置次要刻度线数量
    m_axisY->setGridLineVisible(true); // 显示网格线

    m_axisX->setTickCount(5);
    m_axisX->setMinorTickCount(2); // 设置次要刻度线数量
    m_axisX->setGridLineVisible(true); // 显示网格线

    m_lineSeries_x = new QLineSeries();m_lineSeries_x->setName("X轴加速度");                             // 创建曲线绘制对象，x轴加速度
    m_lineSeries_y = new QLineSeries();m_lineSeries_y->setName("Y轴加速度");                             // 创建曲线绘制对象，y轴加速度
    m_lineSeries_z = new QLineSeries();m_lineSeries_z->setName("Z轴加速度");                             // 创建曲线绘制对象，z轴加速度
//    m_lineSeries_x->setPointsVisible(true);                         // 设置数据点可见
//    m_lineSeries_y->setPointsVisible(true);                         // 设置数据点可见
//    m_lineSeries_z->setPointsVisible(true);                         // 设置数据点可见

    QPen *pen_x= new QPen;QPen *pen_y= new QPen;QPen *pen_z= new QPen;
    pen_x->setWidth(1);pen_y->setWidth(1);pen_z->setWidth(1);
    pen_x->setColor(Qt::red);pen_y->setColor(Qt::blue);pen_z->setColor(Qt::green);

    m_lineSeries_x->setPen(*pen_x);
    m_lineSeries_y->setPen(*pen_y);
    m_lineSeries_z->setPen(*pen_z);


    m_chart = new QChart();                                        // 创建图表对象
//    m_chart->legend()->setVisible(false);  // 隐藏图例,即把曲线标识取消
    m_chart->addAxis(m_axisY, Qt::AlignLeft);                      // 将X轴添加到图表上
    m_chart->addAxis(m_axisX, Qt::AlignBottom);                    // 将Y轴添加到图表上
    m_chart->addSeries(m_lineSeries_x);                              // 将曲线对象添加到图表上,x轴加速度进行关联
    m_chart->addSeries(m_lineSeries_y);                          // 将曲线对象添加到图表上,y轴加速度进行关联
    m_chart->addSeries(m_lineSeries_z);                      // 将曲线对象添加到图表上,z轴加速度进行关联
//    m_chart->setAnimationOptions(QChart::SeriesAnimations);        // 动画：能使曲线绘制显示的更平滑，过渡效果更好看

    m_lineSeries_x->attachAxis(m_axisX);                             // 曲线对象关联上X轴，此步骤必须在m_chart->addSeries之后,x轴加速度进行关联
    m_lineSeries_x->attachAxis(m_axisY);                             // 曲线对象关联上Y轴，此步骤必须在m_chart->addSeries之后,x轴加速度进行关联
    m_lineSeries_y->attachAxis(m_axisX);                             // 曲线对象关联上X轴，此步骤必须在m_chart->addSeries之后,y轴加速度进行关联
    m_lineSeries_y->attachAxis(m_axisY);                             // 曲线对象关联上Y轴，此步骤必须在m_chart->addSeries之后,y轴加速度进行关联
    m_lineSeries_z->attachAxis(m_axisX);                             // 曲线对象关联上X轴，此步骤必须在m_chart->addSeries之后,z轴加速度进行关联
    m_lineSeries_z->attachAxis(m_axisY);                             // 曲线对象关联上Y轴，此步骤必须在m_chart->addSeries之后,z轴加速度进行关联

    ui->graphicsView->setChart(m_chart);                           // 将图表对象设置到graphicsView上进行显示
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);       // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑
    m_chart->setMargins(QMargins(0,0,0,0));


}


void ChartWidget::chart_accel_rate_run()
{
    // 创建横纵坐标轴并设置显示范围
    //
    QFont font("Arial", 10);  // 设置字体和字号
    m_axis_aX = new QValueAxis();
    m_axis_aY = new QValueAxis();
    m_axis_aX->setTitleFont(font);  // 修改时间轴标题字体
    m_axis_aY->setTitleFont(font);  // 修改时间轴标题字体
    m_axis_aX->setTitleText("时间");
    QString str = QString::fromUtf8("m/x\xC2\xB2");
    m_axis_aY->setTitleText(str);
    m_axis_aX->setMin(AXIS_MIN_X);
    m_axis_aY->setMin(AXIS_MIN_Y);
    m_axis_aX->setMax(AXIS_MAX_X);
    m_axis_aY->setMax(AXIS_MAX_Y);

    m_axis_aY->setTickCount(4);
    m_axis_aY->setLabelFormat("%.2f");
    m_axis_aY->setMinorTickCount(5); // 设置次要刻度线数量
    m_axis_aY->setGridLineVisible(true); // 显示网格线

    m_axis_aX->setTickCount(5);
    m_axis_aX->setMinorTickCount(2); // 设置次要刻度线数量
    m_axis_aX->setGridLineVisible(true); // 显示网格线

    m_lineSeries_ax = new QLineSeries();m_lineSeries_ax->setName("X轴角加速度");                             // 创建曲线绘制对象，x轴加速度
    m_lineSeries_ay = new QLineSeries();m_lineSeries_ay->setName("Y轴角加速度");                             // 创建曲线绘制对象，y轴加速度
    m_lineSeries_az = new QLineSeries();m_lineSeries_az->setName("Z轴角加速度");                             // 创建曲线绘制对象，z轴加速度
//    m_lineSeries_ax->setPointsVisible(true);                         // 设置数据点可见
//    m_lineSeries_ay->setPointsVisible(true);                         // 设置数据点可见
//    m_lineSeries_az->setPointsVisible(true);                         // 设置数据点可见

    QPen *pen_ax= new QPen;QPen *pen_ay= new QPen;QPen *pen_az= new QPen;
    pen_ax->setWidth(1);pen_ay->setWidth(1);pen_az->setWidth(1);
    pen_ax->setColor(Qt::red);pen_ay->setColor(Qt::blue);pen_az->setColor(Qt::green);

    m_lineSeries_ax->setPen(*pen_ax);
    m_lineSeries_ay->setPen(*pen_ay);
    m_lineSeries_az->setPen(*pen_az);


    m_chart_rate = new QChart();                                        // 创建图表对象
//    m_chart->legend()->setVisible(false);  // 隐藏图例,即把曲线标识取消
    m_chart_rate->addAxis(m_axis_aY, Qt::AlignLeft);                      // 将X轴添加到图表上
    m_chart_rate->addAxis(m_axis_aX, Qt::AlignBottom);                    // 将Y轴添加到图表上
    m_chart_rate->addSeries(m_lineSeries_ax);                              // 将曲线对象添加到图表上,x轴加速度进行关联
    m_chart_rate->addSeries(m_lineSeries_ay);                          // 将曲线对象添加到图表上,y轴加速度进行关联
    m_chart_rate->addSeries(m_lineSeries_az);                      // 将曲线对象添加到图表上,z轴加速度进行关联
//    m_chart_rate->setAnimationOptions(QChart::SeriesAnimations);        // 动画：能使曲线绘制显示的更平滑，过渡效果更好看

    m_lineSeries_ax->attachAxis(m_axis_aX);                             // 曲线对象关联上X轴，此步骤必须在m_chart->addSeries之后,x轴加速度进行关联
    m_lineSeries_ax->attachAxis(m_axis_aY);                             // 曲线对象关联上Y轴，此步骤必须在m_chart->addSeries之后,x轴加速度进行关联
    m_lineSeries_ay->attachAxis(m_axis_aX);                             // 曲线对象关联上X轴，此步骤必须在m_chart->addSeries之后,y轴加速度进行关联
    m_lineSeries_ay->attachAxis(m_axis_aY);                             // 曲线对象关联上Y轴，此步骤必须在m_chart->addSeries之后,y轴加速度进行关联
    m_lineSeries_az->attachAxis(m_axis_aX);                             // 曲线对象关联上X轴，此步骤必须在m_chart->addSeries之后,z轴加速度进行关联
    m_lineSeries_az->attachAxis(m_axis_aY);                             // 曲线对象关联上Y轴，此步骤必须在m_chart->addSeries之后,z轴加速度进行关联

    ui->graphicsView_ac_rate->setChart(m_chart_rate);                           // 将图表对象设置到graphicsView上进行显示
    ui->graphicsView_ac_rate->setRenderHint(QPainter::Antialiasing);       // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑
    m_chart_rate->setMargins(QMargins(0,0,0,0));
}


void ChartWidget::working(int num)
{
    static int record_imu = 0;
    record_imu++;
    if(record_imu==40){
        record_imu = 0;
        slotTimeout();
    }
}
