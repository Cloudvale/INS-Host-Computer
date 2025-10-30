#include "precision_factorwidget.h"
#include "ui_precision_factorwidget.h"
#include <QTimer>
#include <mainwindow.h>
#include "datatransfer.h"

using namespace test;


Precision_factorWidget::Precision_factorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Precision_factorWidget)
{

//    m_timer_factor = new QTimer(this);
//    m_timer_factor->setSingleShot(false);
//    QObject::connect(m_timer_factor, SIGNAL(timeout()), this, SLOT(slotTimeout_factor()));

    ui->setupUi(this);
    ui->textEdit_PF->setGeometry(25,25,150,25);
    QFont font;
    font.setPointSize(30); //字号大小
    font.setFamily(("wenquanyi")); //字体样式
    font.setBold(false);
    ui->textEdit_PF->setFont(font); // 为控件设置格式


    //开始时即开始进行曲线显示
//    pointCount_factor = 0;
//    m_timer_factor->start(50);


//    // 使用 QString 的格式化功能将文字和数值拼接成字符串
//    QString PDOPString = QString("PDOP: %1").arg(PDOP);
//    QString HDOPString = QString("HDOP: %1").arg(HDOP);
//    QString VDOPString = QString("VDOP: %1").arg(VDOP);
//    QString TDOPString = QString("TDOP: %1").arg(TDOP);
//    QString GDOPString = QString("GDOP: %1").arg(GDOP);

//    ui->textEdit_PF->setText(QString("%1, %2, %3, %4, %5").arg(PDOPString).arg(HDOPString).arg(VDOPString).arg(TDOPString).arg(GDOPString));
//    ui->textEdit_PF->setAlignment(Qt::AlignCenter);            //水平居中
//    ui->textEdit_PF->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
}

Precision_factorWidget::~Precision_factorWidget()
{
    test::FACOTR_flag = 0;
    delete ui;
}


void Precision_factorWidget::para_for_chart(float *P,float *H,float *V,float *T,float *G)
{
//    *P = Precision_factorWidget::PDOP;*H = Precision_factorWidget::HDOP;*V = Precision_factorWidget::VDOP;*T = Precision_factorWidget::TDOP;*G = Precision_factorWidget::GDOP;
//    *P = para->PDOP;*H = para->HDOP;*V = para->VDOP;*T = para->TDOP;*G = para->GDOP;

    // 使用 QString 的格式化功能将文字和数值拼接成字符串
//    QString PDOPString = QString("PDOP: %1").arg(*P);
//    QString HDOPString = QString("HDOP: %1").arg(*H);
//    QString VDOPString = QString("VDOP: %1").arg(*V);
//    QString TDOPString = QString("TDOP: %1").arg(*T);
//    QString GDOPString = QString("GDOP: %1").arg(*G);

//    ui->textEdit_PF->setText(QString("%1<br/>%2<br/>%3<br/>%4<br/>%5").arg(PDOPString).arg(HDOPString).arg(VDOPString).arg(TDOPString).arg(GDOPString));
//    ui->textEdit_PF->setAlignment(Qt::AlignCenter);            //水平居中
    //    ui->textEdit_PF->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
}



//void Precision_factorWidget::para_for_chart_test()
//{
//    *P = Precision_factorWidget::PDOP;*H = Precision_factorWidget::HDOP;*V = Precision_factorWidget::VDOP;*T = Precision_factorWidget::TDOP;*G = Precision_factorWidget::GDOP;
//    *P = para->PDOP;*H = para->HDOP;*V = para->VDOP;*T = para->TDOP;*G = para->GDOP;

//    // 使用 QString 的格式化功能将文字和数值拼接成字符串
//    QString PDOPString = QString("PDOP: %1").arg(*P);
//    QString HDOPString = QString("HDOP: %1").arg(*H);
//    QString VDOPString = QString("VDOP: %1").arg(*V);
//    QString TDOPString = QString("TDOP: %1").arg(*T);
//    QString GDOPString = QString("GDOP: %1").arg(*G);

//    ui->textEdit_PF->setText(QString("%1<br/>%2<br/>%3<br/>%4<br/>%5").arg(PDOPString).arg(HDOPString).arg(VDOPString).arg(TDOPString).arg(GDOPString));
//    ui->textEdit_PF->setAlignment(Qt::AlignCenter);            //水平居中
//    ui->textEdit_PF->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
//}


void Precision_factorWidget::slotTimeout_factor()
{
//    para_for_chart();
    static QString PDOPString = QString("PDOP: %1").arg(num_PDOP);
    static QString HDOPString = QString("HDOP: %1").arg(num_HDOP);
    static QString VDOPString = QString("VDOP: %1").arg(num_VDOP);
    static QString TDOPString = QString("TDOP: %1").arg(num_TDOP);
    static QString GDOPString = QString("GDOP: %1").arg(num_GDOP);

    ui->textEdit_PF->setText(QString("%1<br/>%2<br/>%3<br/>%4<br/>%5").arg(PDOPString).arg(HDOPString).arg(VDOPString).arg(TDOPString).arg(GDOPString));
    ui->textEdit_PF->setAlignment(Qt::AlignCenter);            //水平居中
    ui->textEdit_PF->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");

}


void Precision_factorWidget::working(int num)
{
    static int record_p = 0;
    record_p++;
    if(record_p==40){
        record_p = 0;
        slotTimeout_factor();
    }

}
