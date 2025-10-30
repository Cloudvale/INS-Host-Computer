#include "gnss_dbtwidget.h"
#include "ui_gnss_dbtwidget.h"
#include <mainwindow.h>
#include "datatransfer.h"

using namespace test;

Gnss_dbtWidget::Gnss_dbtWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gnss_dbtWidget)
{
    ui->setupUi(this);
    chart_East_run();
    chart_North_run();
    chart_Up_run();
//    m_timer_DNU = new QTimer(this);
//    m_timer_DNU->setSingleShot(false);
//    QObject::connect(m_timer_DNU, SIGNAL(timeout()), this, SLOT(slotTimeout_DNU()));


    DNU_text_run();
    //开始时即开始进行曲线显示
//    pointCount = 0;
//    m_timer_DNU->start(5);
}

Gnss_dbtWidget::~Gnss_dbtWidget()
{
    test::GNSS_DBT_flag = 0;
    delete ui;
}
void Gnss_dbtWidget::chart_East_run()
{
    // 创建横纵坐标轴并设置显示范围
    QFont font("Arial", 8);  // 设置字体和字号
    m_axis_eastX = new QValueAxis();m_axis_eastY = new QValueAxis();
    m_axis_eastX->setTitleFont(font);m_axis_eastY->setTitleFont(font);  // 修改时间轴标题字体
    m_axis_eastX->setTitleText("时间");QString str_lon = QString::fromUtf8("m/s");m_axis_eastY->setTitleText("东速"+str_lon);
    m_axis_eastX->setMin(AXIS_MIN_X); m_axis_eastY->setMin(AXIS_MIN_Y);m_axis_eastX->setMax(AXIS_MAX_X);m_axis_eastY->setMax(AXIS_MAX_Y);

    m_axis_eastX->setTickCount(5);m_axis_eastX->setMinorTickCount(2);m_axis_eastX->setGridLineVisible(true); // 显示网格线
    m_axis_eastY->setTickCount(4);m_axis_eastY->setLabelFormat("%.2f");m_axis_eastY->setMinorTickCount(5); m_axis_eastY->setGridLineVisible(true); // 显示网格线

    m_lineSeries_east = new QLineSeries();m_lineSeries_east->setName("东向速度曲线");m_lineSeries_east->setPointsVisible(true);                         // 设置数据点可见

    QPen *pen_lon = new QPen;pen_lon->setWidth(1);pen_lon->setColor(Qt::red);

    m_lineSeries_east->setPen(*pen_lon);

    m_chart_east = new QChart();                                        // 创建图表对象
    m_chart_east->addAxis(m_axis_eastY, Qt::AlignLeft);                      // 将X轴添加到图表上
    m_chart_east->addAxis(m_axis_eastX, Qt::AlignBottom);                    // 将Y轴添加到图表上
    m_chart_east->addSeries(m_lineSeries_east);                              // 将曲线对象添加到图表上,x轴加速度进行关联
//    m_chart_east->setAnimationOptions(QChart::SeriesAnimations);        // 动画：能使曲线绘制显示的更平滑，过渡效果更好看

    m_lineSeries_east->attachAxis(m_axis_eastX);                             // 曲线对象关联上X轴，此步骤必须在m_chart->addSeries之后,x轴加速度进行关联
    m_lineSeries_east->attachAxis(m_axis_eastY);                             // 曲线对象关联上Y轴，此步骤必须在m_chart->addSeries之后,x轴加速度进行关联


    ui->graphicsView_D->setChart(m_chart_east);                           // 将图表对象设置到graphicsView上进行显示
    ui->graphicsView_D->setRenderHint(QPainter::Antialiasing);       // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑
    m_chart_east->setMargins(QMargins(0,0,0,0));

}

void Gnss_dbtWidget::chart_North_run()
{
    // 创建横纵坐标轴并设置显示范围
    QFont font("Arial", 8);  // 设置字体和字号
    m_axis_northX = new QValueAxis();m_axis_upY = new QValueAxis();
    m_axis_northX->setTitleFont(font);m_axis_upY->setTitleFont(font);  // 修改时间轴标题字体
    m_axis_northX->setTitleText("时间");QString str_lat = QString::fromUtf8("m/s");m_axis_upY->setTitleText("北速"+str_lat);
    m_axis_northX->setMin(AXIS_MIN_X); m_axis_upY->setMin(AXIS_MIN_Y);m_axis_northX->setMax(AXIS_MAX_X);m_axis_upY->setMax(AXIS_MAX_Y);
    m_axis_northX->setTickCount(5);m_axis_northX->setMinorTickCount(2);m_axis_northX->setGridLineVisible(true); // 显示网格线
    m_axis_upY->setTickCount(4);m_axis_upY->setLabelFormat("%.2f");m_axis_upY->setMinorTickCount(5); m_axis_upY->setGridLineVisible(true); // 显示网格线



    m_lineSeries_north = new QLineSeries();m_lineSeries_north->setName("北向速度曲线");m_lineSeries_north->setPointsVisible(true);                         // 设置数据点可见

    QPen *pen_lat = new QPen;pen_lat->setWidth(1);pen_lat->setColor(Qt::blue);

    m_lineSeries_north->setPen(*pen_lat);

    m_chart_north = new QChart();                                        // 创建图表对象
    m_chart_north->addAxis(m_axis_upY, Qt::AlignLeft);                      // 将X轴添加到图表上
    m_chart_north->addAxis(m_axis_northX, Qt::AlignBottom);                    // 将Y轴添加到图表上
    m_chart_north->addSeries(m_lineSeries_north);                              // 将曲线对象添加到图表上,x轴加速度进行关联
//    m_chart_north->setAnimationOptions(QChart::SeriesAnimations);        // 动画：能使曲线绘制显示的更平滑，过渡效果更好看

    m_lineSeries_north->attachAxis(m_axis_northX);                             // 曲线对象关联上X轴，此步骤必须在m_chart->addSeries之后,x轴加速度进行关联
    m_lineSeries_north->attachAxis(m_axis_upY);                             // 曲线对象关联上Y轴，此步骤必须在m_chart->addSeries之后,x轴加速度进行关联


    ui->graphicsView_N->setChart(m_chart_north);                           // 将图表对象设置到graphicsView上进行显示
    ui->graphicsView_N->setRenderHint(QPainter::Antialiasing);       // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑
    m_chart_north->setMargins(QMargins(0,0,0,0));

}

void Gnss_dbtWidget::chart_Up_run()
{
    // 创建横纵坐标轴并设置显示范围
    QFont font("Arial", 8);  // 设置字体和字号
    m_axis_upX = new QValueAxis();m_axis_upY = new QValueAxis();
    m_axis_upX->setTitleFont(font);m_axis_upY->setTitleFont(font);  // 修改时间轴标题字体
    m_axis_upX->setTitleText("时间");QString str_lat = QString::fromUtf8("m/s");m_axis_upY->setTitleText("上速"+str_lat);
    m_axis_upX->setMin(AXIS_MIN_X); m_axis_upY->setMin(AXIS_MIN_Y);m_axis_upX->setMax(AXIS_MAX_X);m_axis_upY->setMax(AXIS_MAX_Y);
    m_axis_upX->setTickCount(5);m_axis_upX->setMinorTickCount(2);m_axis_upX->setGridLineVisible(true); // 显示网格线
    m_axis_upY->setTickCount(4);m_axis_upY->setLabelFormat("%.2f");m_axis_upY->setMinorTickCount(5); m_axis_upY->setGridLineVisible(true); // 显示网格线



    m_lineSeries_up = new QLineSeries();m_lineSeries_up->setName("天向速度曲线");m_lineSeries_up->setPointsVisible(true);                         // 设置数据点可见

    QPen *pen_height = new QPen;pen_height->setWidth(1);pen_height->setColor(Qt::green);

    m_lineSeries_north->setPen(*pen_height);

    m_chart_up = new QChart();                                        // 创建图表对象
    m_chart_up->addAxis(m_axis_upY, Qt::AlignLeft);                      // 将X轴添加到图表上
    m_chart_up->addAxis(m_axis_upX, Qt::AlignBottom);                    // 将Y轴添加到图表上
    m_chart_up->addSeries(m_lineSeries_up);                              // 将曲线对象添加到图表上,x轴加速度进行关联
//    m_chart_up->setAnimationOptions(QChart::SeriesAnimations);        // 动画：能使曲线绘制显示的更平滑，过渡效果更好看

    m_lineSeries_up->attachAxis(m_axis_upX);                             // 曲线对象关联上X轴，此步骤必须在m_chart->addSeries之后,x轴加速度进行关联
    m_lineSeries_up->attachAxis(m_axis_upY);                             // 曲线对象关联上Y轴，此步骤必须在m_chart->addSeries之后,x轴加速度进行关联


    ui->graphicsView_U->setChart(m_chart_up);                           // 将图表对象设置到graphicsView上进行显示
    ui->graphicsView_U->setRenderHint(QPainter::Antialiasing);       // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑
    m_chart_north->setMargins(QMargins(0,0,0,0));

}


void Gnss_dbtWidget::DNU_text_run()
{
    ui->lineEdit_DNU->setGeometry(25,25,150,25);
    QFont font;
    font.setPointSize(15); //字号大小
    font.setFamily(("wenquanyi")); //字体样式
    font.setBold(false);
    ui->lineEdit_DNU->setFont(font); // 为控件设置格式

//    float eastvel = 114.32;
//    float northvel = 30.16;
//    float upvel = 30.1;

//    // 使用 QString 的格式化功能将文字和数值拼接成字符串
//    QString latString = QString("东向速度: %1").arg(eastvel);
//    QString lonString = QString("北向速度: %1").arg(northvel);
//    QString heightString = QString("天向速度: %1").arg(upvel);

//    ui->lineEdit_DNU->setText(QString("%1, %2, %3").arg(latString).arg(lonString).arg(heightString));
//    ui->lineEdit_DNU->setAlignment(Qt::AlignCenter);            //水平居中
//    ui->lineEdit_DNU->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");

}



void Gnss_dbtWidget::slotTimeout_DNU()
{
    if(pointCount > AXIS_MAX_X)
    {
        m_lineSeries_east->remove(0);
        m_lineSeries_north->remove(0);
        m_lineSeries_up->remove(0);


        m_chart_east->axisX()->setMin(pointCount - AXIS_MAX_X);
        m_chart_east->axisX()->setMax(pointCount);                    // 更新X轴范围

        m_chart_north->axisX()->setMin(pointCount - AXIS_MAX_X);
        m_chart_north->axisX()->setMax(pointCount);                    // 更新X轴范围

        m_chart_up->axisX()->setMin(pointCount - AXIS_MAX_X);
        m_chart_up->axisX()->setMax(pointCount);                    // 更新X轴范围

    }

    m_lineSeries_east->append(QPointF(pointCount, num_EastVel));  // 更新显示（随机生成10以内的一个数）
    m_lineSeries_north->append(QPointF(pointCount, num_NorthVel));  // 更新显示（随机生成10以内的一个数）
    m_lineSeries_up->append(QPointF(pointCount, num_UpVel));  // 更新显示（随机生成10以内的一个数）

    // 使用 QString 的格式化功能将文字和数值拼接成字符串
    static QString latString = QString("东向速度: %1").arg(num_EastVel);
    static QString lonString = QString("北向速度: %1").arg(num_NorthVel);
    static QString heightString = QString("天向速度: %1").arg(num_UpVel);

//    num_EastVel=0;num_NorthVel=0;num_UpVel=0;

    ui->lineEdit_DNU->setText(QString("%1, %2, %3").arg(latString).arg(lonString).arg(heightString));
    ui->lineEdit_DNU->setAlignment(Qt::AlignCenter);            //水平居中
    ui->lineEdit_DNU->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");



//    m_lineSeries_east->append(QPointF(pointCount, rand() % AXIS_MAX_Y));  // 更新显示（随机生成10以内的一个数）
//    m_lineSeries_north->append(QPointF(pointCount, rand() % AXIS_MAX_Y));  // 更新显示（随机生成10以内的一个数）
//    m_lineSeries_up->append(QPointF(pointCount, rand() % AXIS_MAX_Y));  // 更新显示（随机生成10以内的一个数）

    pointCount+=0.2;


}


void Gnss_dbtWidget::working(int num)
{

    static int record_dbt = 0;
    record_dbt++;
    if(record_dbt==40){
        record_dbt = 0;
       slotTimeout_DNU();
    }

}
