#include "tempwidget.h"
#include "ui_tempwidget.h"
#include <mainwindow.h>
#include "datatransfer.h"

using namespace test;

TempWidget::TempWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TempWidget)
{

//    m_timer_temp = new QTimer(this);
//    m_timer_temp->setSingleShot(false);
//    QObject::connect(m_timer_temp, SIGNAL(timeout()), this, SLOT(slotTimeout_temp()));
    ui->setupUi(this);

    temp_text_run();
    chart_temp_run();
    //开始时即开始进行曲线显示
//    pointCount = 0;
//    m_timer_temp->start(50);



}

TempWidget::~TempWidget()
{
    test::TEMP_flag = 0;
    delete ui;
}


void TempWidget::slotTimeout_temp()
{
//     qDebug() << "temp生成随机数的线程的线程地址: " << QThread::currentThread();
    if(pointCount > AXIS_MAX_X)
    {
        m_lineSeries_temp->remove(0);


        m_chart_temp->axisX()->setMin(pointCount - AXIS_MAX_X);
        m_chart_temp->axisX()->setMax(pointCount);                    // 更新X轴范围

    }
//    temp = rand() % AXIS_MAX_Y;
        m_lineSeries_temp->append(QPointF(pointCount,num_temp));         // 更新显示
//    m_lineSeries_temp->append(QPointF(pointCount, rand() % AXIS_MAX_Y));  // 更新显示（随机生成10以内的一个数）
    QString str_C = QString::fromUtf8("°C");
    ui->lineEdit->setText(QString::number(num_temp)+str_C);
    ui->lineEdit->setAlignment(Qt::AlignCenter);            //水平居中
    ui->lineEdit->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");

//    num_temp = 0;
    pointCount+=0.2;


}


void TempWidget::chart_temp_run()
{
    // 创建横纵坐标轴并设置显示范围
    QFont font("Arial", 10);  // 设置字体和字号
    m_axis_tX = new QValueAxis();
    m_axis_tY = new QValueAxis();
    m_axis_tX->setTitleFont(font);  // 修改时间轴标题字体
    m_axis_tY->setTitleFont(font);  // 修改时间轴标题字体
    m_axis_tX->setTitleText("时间");
    QString str = QString::fromUtf8("°C");
    m_axis_tY->setTitleText(str);
    m_axis_tX->setMin(AXIS_MIN_X);
    m_axis_tY->setMin(AXIS_MIN_Y);
    m_axis_tX->setMax(AXIS_MAX_X);
    m_axis_tY->setMax(AXIS_MAX_Y);

    m_axis_tY->setTickCount(4);
    m_axis_tY->setLabelFormat("%.2f");
    m_axis_tY->setMinorTickCount(5); // 设置次要刻度线数量
    m_axis_tY->setGridLineVisible(true); // 显示网格线

    m_axis_tX->setTickCount(5);
    m_axis_tX->setMinorTickCount(2); // 设置次要刻度线数量
    m_axis_tX->setGridLineVisible(true); // 显示网格线

    m_lineSeries_temp = new QLineSeries();m_lineSeries_temp->setName("温度曲线");// 创建曲线绘制对象，x轴加速度
    m_lineSeries_temp->setPointsVisible(true);                         // 设置数据点可见

    QPen *pen_temp= new QPen;
    pen_temp->setWidth(1);
    pen_temp->setColor(Qt::red);

    m_lineSeries_temp->setPen(*pen_temp);

    m_chart_temp = new QChart();                                        // 创建图表对象
//    m_chart->legend()->setVisible(false);  // 隐藏图例,即把曲线标识取消
    m_chart_temp->addAxis(m_axis_tY, Qt::AlignLeft);                      // 将X轴添加到图表上
    m_chart_temp->addAxis(m_axis_tX, Qt::AlignBottom);                    // 将Y轴添加到图表上
    m_chart_temp->addSeries(m_lineSeries_temp);                              // 将曲线对象添加到图表上,x轴加速度进行关联
    m_chart_temp->setAnimationOptions(QChart::SeriesAnimations);        // 动画：能使曲线绘制显示的更平滑，过渡效果更好看

    m_lineSeries_temp->attachAxis(m_axis_tX);                             // 曲线对象关联上X轴，此步骤必须在m_chart->addSeries之后,x轴加速度进行关联
    m_lineSeries_temp->attachAxis(m_axis_tY);                             // 曲线对象关联上Y轴，此步骤必须在m_chart->addSeries之后,x轴加速度进行关联


    ui->graphicsView->setChart(m_chart_temp);                           // 将图表对象设置到graphicsView上进行显示
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);       // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑
    m_chart_temp->setMargins(QMargins(0,0,0,0));


}


void TempWidget::temp_text_run()
{
    ui->lineEdit->setGeometry(25,25,100,25);
    QFont font;
    font.setPointSize(15); //字号大小
    font.setFamily(("wenquanyi")); //字体样式
    font.setBold(false);
    ui->lineEdit->setFont(font); // 为控件设置格式

   // 生成一个12以内的随机数字
//    QRandomGenerator::global()->seed(QTime::currentTime().msec());
//   int randomNum = QRandomGenerator::global()->bounded(12);

//    float randomNum = 9 ;


}

void TempWidget::working(int num)
{
    static int record_temp = 0;
    record_temp++;
    if(record_temp==40){
        record_temp = 0;
        slotTimeout_temp();
    }

}
