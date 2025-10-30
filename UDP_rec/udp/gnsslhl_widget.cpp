#include "gnsslhl_widget.h"
#include "ui_gnsslhl_widget.h"
#include <mainwindow.h>
#include "datatransfer.h"
using namespace test;

Gnsslhl_Widget::Gnsslhl_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gnsslhl_Widget)
{
    ui->setupUi(this);
    chart_lon_run();
    chart_lat_run();
    chart_height_run();
//    m_timer_lhl = new QTimer(this);
//    m_timer_lhl->setSingleShot(false);
//    QObject::connect(m_timer_lhl, SIGNAL(timeout()), this, SLOT(slotTimeout_lhl()));


    lhl_text_run();
    //开始时即开始进行曲线显示
//    pointCount = 0;
//    m_timer_lhl->start(5);
}

Gnsslhl_Widget::~Gnsslhl_Widget()
{
    test::GNSS_LHL_flag = 0;
    delete ui;
}

void Gnsslhl_Widget::chart_lon_run()
{
    // 创建横纵坐标轴并设置显示范围
    QFont font("Arial", 8);  // 设置字体和字号
    m_axis_lonX = new QValueAxis();m_axis_lonY = new QValueAxis();
    m_axis_lonX->setTitleFont(font);m_axis_lonY->setTitleFont(font);  // 修改时间轴标题字体
    m_axis_lonX->setTitleText("时间");QString str_lon = QString::fromUtf8("度");m_axis_lonY->setTitleText("经度");
    m_axis_lonX->setMin(AXIS_MIN_X); m_axis_lonY->setMin(AXIS_MIN_Y);m_axis_lonX->setMax(AXIS_MAX_X);m_axis_lonY->setMax(AXIS_MAX_Y);

    m_axis_lonX->setTickCount(5);m_axis_lonX->setMinorTickCount(2);m_axis_lonX->setGridLineVisible(true); // 显示网格线
    m_axis_lonY->setTickCount(4);m_axis_lonY->setLabelFormat("%.2f");m_axis_lonY->setMinorTickCount(5); m_axis_lonY->setGridLineVisible(true); // 显示网格线

    m_lineSeries_lon = new QLineSeries();m_lineSeries_lon->setName("经度曲线");m_lineSeries_lon->setPointsVisible(true);                         // 设置数据点可见

    QPen *pen_lon = new QPen;pen_lon->setWidth(1);pen_lon->setColor(Qt::red);

    m_lineSeries_lon->setPen(*pen_lon);

    m_chart_lon = new QChart();                                        // 创建图表对象
    m_chart_lon->addAxis(m_axis_lonY, Qt::AlignLeft);                      // 将X轴添加到图表上
    m_chart_lon->addAxis(m_axis_lonX, Qt::AlignBottom);                    // 将Y轴添加到图表上
    m_chart_lon->addSeries(m_lineSeries_lon);                              // 将曲线对象添加到图表上,x轴加速度进行关联
//    m_chart_lon->setAnimationOptions(QChart::SeriesAnimations);        // 动画：能使曲线绘制显示的更平滑，过渡效果更好看

    m_lineSeries_lon->attachAxis(m_axis_lonX);                             // 曲线对象关联上X轴，此步骤必须在m_chart->addSeries之后,x轴加速度进行关联
    m_lineSeries_lon->attachAxis(m_axis_lonY);                             // 曲线对象关联上Y轴，此步骤必须在m_chart->addSeries之后,x轴加速度进行关联


    ui->graphicsView_lon->setChart(m_chart_lon);                           // 将图表对象设置到graphicsView上进行显示
    ui->graphicsView_lon->setRenderHint(QPainter::Antialiasing);       // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑
    m_chart_lon->setMargins(QMargins(0,0,0,0));

}

void Gnsslhl_Widget::chart_lat_run()
{
    // 创建横纵坐标轴并设置显示范围
    QFont font("Arial", 8);  // 设置字体和字号
    m_axis_latX = new QValueAxis();m_axis_latY = new QValueAxis();
    m_axis_latX->setTitleFont(font);m_axis_latY->setTitleFont(font);  // 修改时间轴标题字体
    m_axis_latX->setTitleText("时间");QString str_lat = QString::fromUtf8("度");m_axis_latY->setTitleText("纬度");
    m_axis_latX->setMin(AXIS_MIN_X); m_axis_latY->setMin(AXIS_MIN_Y);m_axis_latX->setMax(AXIS_MAX_X);m_axis_latY->setMax(AXIS_MAX_Y);
    m_axis_latX->setTickCount(5);m_axis_latX->setMinorTickCount(2);m_axis_latX->setGridLineVisible(true); // 显示网格线
    m_axis_latY->setTickCount(4);m_axis_latY->setLabelFormat("%.2f");m_axis_latY->setMinorTickCount(5); m_axis_lonY->setGridLineVisible(true); // 显示网格线



    m_lineSeries_lat = new QLineSeries();m_lineSeries_lat->setName("纬度曲线");m_lineSeries_lat->setPointsVisible(true);                         // 设置数据点可见

    QPen *pen_lat = new QPen;pen_lat->setWidth(1);pen_lat->setColor(Qt::blue);

    m_lineSeries_lat->setPen(*pen_lat);

    m_chart_lat = new QChart();                                        // 创建图表对象
    m_chart_lat->addAxis(m_axis_latY, Qt::AlignLeft);                      // 将X轴添加到图表上
    m_chart_lat->addAxis(m_axis_latX, Qt::AlignBottom);                    // 将Y轴添加到图表上
    m_chart_lat->addSeries(m_lineSeries_lat);                              // 将曲线对象添加到图表上,x轴加速度进行关联
//    m_chart_lat->setAnimationOptions(QChart::SeriesAnimations);        // 动画：能使曲线绘制显示的更平滑，过渡效果更好看

    m_lineSeries_lat->attachAxis(m_axis_latX);                             // 曲线对象关联上X轴，此步骤必须在m_chart->addSeries之后,x轴加速度进行关联
    m_lineSeries_lat->attachAxis(m_axis_latY);                             // 曲线对象关联上Y轴，此步骤必须在m_chart->addSeries之后,x轴加速度进行关联


    ui->graphicsView_lat->setChart(m_chart_lat);                           // 将图表对象设置到graphicsView上进行显示
    ui->graphicsView_lat->setRenderHint(QPainter::Antialiasing);       // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑
    m_chart_lat->setMargins(QMargins(0,0,0,0));

}

void Gnsslhl_Widget::chart_height_run()
{
    // 创建横纵坐标轴并设置显示范围
    QFont font("Arial", 8);  // 设置字体和字号
    m_axis_heightX = new QValueAxis();m_axis_heightY = new QValueAxis();
    m_axis_heightX->setTitleFont(font);m_axis_heightY->setTitleFont(font);  // 修改时间轴标题字体
    m_axis_heightX->setTitleText("时间");QString str_lat = QString::fromUtf8("m");m_axis_heightY->setTitleText("高度");
    m_axis_heightX->setMin(0); m_axis_heightY->setMin(0);m_axis_heightX->setMax(AXIS_MAX_X);m_axis_heightY->setMax(AXIS_MAX_Y);
    m_axis_heightX->setTickCount(5);m_axis_heightX->setMinorTickCount(2);m_axis_heightX->setGridLineVisible(true); // 显示网格线
    m_axis_heightY->setTickCount(4);m_axis_heightY->setLabelFormat("%.2f");m_axis_heightY->setMinorTickCount(5); m_axis_heightY->setGridLineVisible(true); // 显示网格线



    m_lineSeries_height = new QLineSeries();m_lineSeries_height->setName("高度曲线");m_lineSeries_height->setPointsVisible(true);                         // 设置数据点可见

    QPen *pen_height = new QPen;pen_height->setWidth(1);pen_height->setColor(Qt::green);

    m_lineSeries_lat->setPen(*pen_height);

    m_chart_height = new QChart();                                        // 创建图表对象
    m_chart_height->addAxis(m_axis_heightY, Qt::AlignLeft);                      // 将X轴添加到图表上
    m_chart_height->addAxis(m_axis_heightX, Qt::AlignBottom);                    // 将Y轴添加到图表上
    m_chart_height->addSeries(m_lineSeries_height);                              // 将曲线对象添加到图表上,x轴加速度进行关联
//    m_chart_height->setAnimationOptions(QChart::SeriesAnimations);        // 动画：能使曲线绘制显示的更平滑，过渡效果更好看

    m_lineSeries_height->attachAxis(m_axis_heightX);                             // 曲线对象关联上X轴，此步骤必须在m_chart->addSeries之后,x轴加速度进行关联
    m_lineSeries_height->attachAxis(m_axis_heightY);                             // 曲线对象关联上Y轴，此步骤必须在m_chart->addSeries之后,x轴加速度进行关联


    ui->graphicsView_height->setChart(m_chart_height);                           // 将图表对象设置到graphicsView上进行显示
    ui->graphicsView_height->setRenderHint(QPainter::Antialiasing);       // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑
    m_chart_lat->setMargins(QMargins(0,0,0,0));

}


void Gnsslhl_Widget::lhl_text_run()
{
    ui->lineEdit_lhl->setGeometry(25,25,150,25);
    QFont font;
    font.setPointSize(15); //字号大小
    font.setFamily(("wenquanyi")); //字体样式
    font.setBold(false);
    ui->lineEdit_lhl->setFont(font); // 为控件设置格式

//    float lats = 114.32;
//    float lons = 30.16;
//    float height = 30.1;

    // 使用 QString 的格式化功能将文字和数值拼接成字符串



}


void Gnsslhl_Widget::slotTimeout_lhl()
{
    if(pointCount > AXIS_MAX_X)
    {
        m_lineSeries_lon->remove(0);
        m_lineSeries_lat->remove(0);
        m_lineSeries_height->remove(0);


        m_chart_lon->axisX()->setMin(pointCount - AXIS_MAX_X);
        m_chart_lon->axisX()->setMax(pointCount);                    // 更新X轴范围

        m_chart_lat->axisX()->setMin(pointCount - AXIS_MAX_X);
        m_chart_lat->axisX()->setMax(pointCount);                    // 更新X轴范围

        m_chart_height->axisX()->setMin(pointCount - AXIS_MAX_X);
        m_chart_height->axisX()->setMax(pointCount);                    // 更新X轴范围

    }

    m_lineSeries_lon->append(QPointF(pointCount, num_Lon));  // 更新显示（随机生成10以内的一个数）
    m_lineSeries_lat->append(QPointF(pointCount, num_Lat));  // 更新显示（随机生成10以内的一个数）
    m_lineSeries_height->append(QPointF(pointCount, num_Height));  // 更新显示（随机生成10以内的一个数）

    static QString latString = QString("纬度: %1").arg(num_Lat);
    static QString lonString = QString("经度: %1").arg(num_Lon);
    static QString heightString = QString("高度: %1").arg(num_Height);

//    num_Lat=0;num_Lon=0;num_Height=0;

    ui->lineEdit_lhl->setText(QString("%1, %2, %3").arg(latString).arg(lonString).arg(heightString));
    ui->lineEdit_lhl->setAlignment(Qt::AlignCenter);            //水平居中
    ui->lineEdit_lhl->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");

//    m_lineSeries_lon->append(QPointF(pointCount, rand() % AXIS_MAX_Y));  // 更新显示（随机生成10以内的一个数）
//    m_lineSeries_lat->append(QPointF(pointCount, rand() % AXIS_MAX_Y));  // 更新显示（随机生成10以内的一个数）
//    m_lineSeries_height->append(QPointF(pointCount, rand() % AXIS_MAX_Y));  // 更新显示（随机生成10以内的一个数）

    pointCount+=0.2;


}

void Gnsslhl_Widget::working(int num)
{
    static int record_lhl = 0;
    record_lhl++;
    if(record_lhl==40){
        record_lhl = 0;
        slotTimeout_lhl();
    }

}
