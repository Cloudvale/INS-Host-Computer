#include "utctext.h"
#include "ui_utctext.h"
#include "QDateTime"
#include "mainwindow.h"
#include "datatransfer.h"


using test::UTC_flag;
UTCtext::UTCtext(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UTCtext)
{

//    m_timer_utc = new QTimer(this);
//    m_timer_utc->setSingleShot(false);
//    QObject::connect(m_timer_utc, SIGNAL(timeout()), this, SLOT(slotTimeout_utc()));

    ui->setupUi(this);
    ui->lineEdit->setGeometry(25,25,150,25);
    QFont font;
    font.setPointSize(30); //字号大小
    font.setFamily(("wenquanyi")); //字体样式
    font.setBold(false);
    ui->lineEdit->setFont(font); // 为控件设置格式

//    //开始时即开始进行曲线显示
//    pointCount_utc = 0;
//    m_timer_utc->start(100);

}

UTCtext::~UTCtext()
{
    test::UTC_flag = 0;
    thread.quit();
    thread.wait();
    delete ui;
}


void UTCtext::slotTimeout_utc()
{
    static QDateTime current_date_time =QDateTime::currentDateTime();
    static QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss");
    ui->lineEdit->setText(current_date);
    ui->lineEdit->setAlignment(Qt::AlignCenter);            //水平居中
    ui->lineEdit->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");


}

void UTCtext::working(int num)
{
//    qDebug() << "utc生成随机数的线程的线程地址: " << QThread::currentThread();
    QVector<int> list;
//    QElapsedTimer time;

//    m_timer_utc = new QTimer(this);
//    m_timer_utc->setSingleShot(false);
    slotTimeout_utc();   //

//    QObject::connect(m_timer_utc, SIGNAL(timeout()), this, SLOT(slotTimeout_utc()));

//    ui->setupUi(this);
//    ui->lineEdit->setGeometry(25,25,150,25);
//    QFont font;
//    font.setPointSize(30); //字号大小
//    font.setFamily(("wenquanyi")); //字体样式
//    font.setBold(false);
//    ui->lineEdit->setFont(font); // 为控件设置格式

    //开始时即开始进行曲线显示
//    pointCount_utc = 0;
//    m_timer_utc->start(100);
//    qDebug() << "生成" << num << "个随机数总共用时:" << milsec << "毫秒";
//    emit sendArray(list);
}

void UTCtext::test_utc()
{
    static int record_utc = 0;
    record_utc++;
    if(record_utc==40){
        record_utc = 0;
        slotTimeout_utc();
    }
//    QDateTime current_date_time =QDateTime::currentDateTime();
//    QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss");
//    ui->lineEdit->setText(current_date);
//    ui->lineEdit->setAlignment(Qt::AlignCenter);            //水平居中
//    ui->lineEdit->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");


}
