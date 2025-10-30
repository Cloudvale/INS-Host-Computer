#include "Widget.h"
#include "ui_Widget.h"
#include  <QtNetwork>
#include <QFileDialog>
#include <QMessageBox>
#include <QRegExp>
#include <QStringList>
#include <QDateTime>
#include "mainwindow.h"



Widget::Widget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);                                                        //开启ui界面

    QString localIP=getLocalIP();                                             //本机IP
    this->setWindowTitle(this->windowTitle()+"----本机IP："+localIP);

    udpSocket=new QUdpSocket(this);                                           //用于与连接的客户端通讯的QTcpSocket
    connect(udpSocket,&QUdpSocket::readyRead,
            this,&Widget::onSocketReadyRead);



    //避免文件对话框弹出两次
    //Qt::UniqueConnection确保同一信号与同一个槽函数之间只有一个连接,避免按钮点击后槽函数触发两次
//    connect(ui->pushButton_save_end, SIGNAL(clicked()), this, SLOT(on_pushButton_save_end_clicked()), Qt::UniqueConnection);
//    connect(ui->pushButton_save_start, SIGNAL(clicked()), this, SLOT(on_pushButton_save_start_clicked()), Qt::UniqueConnection);




}

Widget::~Widget()
{
    udpSocket->abort();
    delete udpSocket;
    delete ui;
}

QString Widget::getLocalIP()
{
    QString hostName=QHostInfo::localHostName();                          //本地主机名
    QHostInfo   hostInfo=QHostInfo::fromName(hostName);                   //
    QString   localIP="";

    QList<QHostAddress> addList=hostInfo.addresses();                     //

    if (!addList.isEmpty())
    for (int i=0;i<addList.count();i++)
    {
        QHostAddress aHost=addList.at(i);
        if (QAbstractSocket::IPv4Protocol==aHost.protocol())
        {
            localIP=aHost.toString();
            break;
        }
    }
    return localIP;
}

void Widget::onSocketReadyRead()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());                 //数据格式统一

        QHostAddress peerAddr;
        quint16 peerPort;
        udpSocket->readDatagram(datagram.data(),
                                datagram.size(),&peerAddr,&peerPort);      //接收数据
        QString str=datagram.data();                                       //数据转换为QT的ui界面使用的QString类型

        QString peer="[From "+peerAddr.toString()+":"
                +QString::number(peerPort)+"] ";



//        ui->plainTextEdit->appendPlainText(peer+str);
        /*如何构造一个能满足txt文件的格式呢*/
//        if()
//        QString header = "#";                                          //进行收到数据的头帧校验“#”
//        if(str.startsWith(header))
//        {
//            QRegExp regex(",");
//            QStringList list = str.split(regex);                      //将收到的数据进行逗号“,”分离（英文逗号）
//            PDOP=list.at(0);                                          //进行数据填充
//            HDOP=list.at(1);
//            VDOP=list.at(2);
//            TDOP=list.at(3);
//            GDOP=list.at(4);
//            Lon=list.at(5);
//            Lat=list.at(6);
//            Height=list.at(7);
//            EastVel=list.at(8);
//            NorthVel=list.at(9);
//            UpVel=list.at(10);
//            heading=list.at(11);
//            ac_x=list.at(12);
//            ac_y=list.at(13);
//            ac_z=list.at(14);
//            angle_rate_x=list.at(15);
//            angle_rate_y=list.at(16);
//            angle_rate_z=list.at(17);
//            sig=list.at(18);


//            PDOP.remove(0, 1);
//            ui->lineEdit_PDOP->setText(PDOP);
//            ui->lineEdit_HDOP->setText(HDOP);
//            ui->lineEdit_VDOP->setText(VDOP);
//            ui->lineEdit_TDOP->setText(TDOP);
//            ui->lineEdit_GDOP->setText(GDOP);
//            ui->lineEdit_Lon->setText(Lon);
//            ui->lineEdit_Lat->setText(Lat);
//            ui->lineEdit_ALts->setText(Height);
//            ui->lineEdit_EastVel->setText(EastVel);
//            ui->lineEdit_NorthVel->setText(NorthVel);
//            ui->lineEdit_UpVel->setText(UpVel);
//            ui->lineEdit_headings->setText(heading);
//            ui->lineEdit_ac_x->setText(ac_x);
//            ui->lineEdit_ac_y->setText(ac_y);
//            ui->lineEdit_ac_z->setText(ac_z);
//            ui->lineEdit_angl_x->setText(angle_rate_x);
//            ui->lineEdit_angl_y->setText(angle_rate_y);
//            ui->lineEdit_angl_z->setText(angle_rate_z);
//            ui->lineEdit_sig->setText(sig);


             if(save_flag)                                           //开始保存标志位判断
             {
                num++;                                               //存储数据的序号排列
                if( file.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append) )
                {
                QTextStream out(&file); //IO设备对象的地址对其进行初始化

                QString num_str = QString("%1").arg(num,6,10,QLatin1Char('0'));
                /* txt 文件首行的各种数据的title */
                  out<<str;
//                out<<"  "<<num_str<<"    ";
//                out<<PDOP<<" "<<HDOP<<" "<<VDOP<<" "<<TDOP<<" "<<GDOP<<" ";
//                out<<Lon<<" "<<Lat<<" "<<Height<<" "<<EastVel<<" "<<NorthVel<<" "<<UpVel<<" "<<heading<<" ";
//                out<<ac_x<<" "<<ac_y<<" "<<ac_z<<" "<<angle_rate_x<<" "<<angle_rate_y<<" "<<angle_rate_z<<" "<<sig;
                file.close();
                }

//             }

           }
    }
}

void Widget::on_pushButton_clicked()
{
//    quint16 port = MainWindow::ui->combo->value(); //本机UDP端口
    quint16 port = ui->spinBox->value(); //本机UDP端口
    if (udpSocket->bind(port)) //绑定端口成功
    {
//        ui->plainTextEdit->appendPlainText("**成功绑定端口");
//        ui->plainTextEdit->appendPlainText("**绑定端口：" +QString::number(udpSocket->localPort()));
    }
}

void Widget::on_pushButton_save_start_clicked()
{
    QFileDialog dlg(this);

        //获取内容的保存路径
        QString fileName = dlg.getSaveFileName(this, tr("Save As"), "./", tr("Text File(*.txt)"));

        if( fileName == "" )
        {
            return;
        }

        //内容保存到路径文件
        file.setFileName(fileName);
        save_flag=1;

        //以文本方式打开
        if( file.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append) )
        {
            QTextStream out(&file); //IO设备对象的地址对其进行初始化
            /* 对数据进行保存 */

            // 获取当前日期和时间
            QDateTime currentDateTime = QDateTime::currentDateTime();
            // 格式化为字符串
            QString currentDateTimeString = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");
            out<<"% Date time:"<<currentDateTimeString<<endl;

            out<<"% ";
            QString chineseText = "序号";
            out << chineseText;
            out<<" PDOP  ";
            out<<"HDOP  ";
            out<<"VDOP  ";
            out<<"TDOP  ";
            out<<"GDOP  ";
            out<<"Lon        ";
            out<<"Lat     ";
            out<<"Heig   ";
            out<<"Evel  ";
            out<<"Nvel  ";
            out<<"Uvel  ";
            out<<"heading  ";
            out<<"ac_x   ";
            out<<"ac_y   ";
            out<<"ac_z   ";
            out<<"ar_x   ";
            out<<"ar_y   ";
            out<<"ar_z   ";
            out<<"sig   "<<endl;
            num=0;
            file.close();
        }
        else
        {
            QMessageBox::warning(this, tr("Error"), tr("File to open file!"));
        }


}

void Widget::on_pushButton_save_end_clicked()
{
        save_flag=0;                            //保存标志位，置0不再进行保存
        num=0;
        QMessageBox::warning(this, tr("Finish"), tr("Successfully save the file!"));
        file.close();
}

void Widget::on_pushButton_2_clicked()
{
//    QString targetIP=ui->lineEdit->text();
//    QHostAddress targetAddr(targetIP);  //目标IP

//    quint16 targetPort = ui->spinBox->value();  //目标端口号
//    QString msg = ui->plainTextEdit->toPlainText(); //发送内容
//    QByteArray str = msg.toUtf8();

//    udpSocket->writeDatagram(str, targetAddr, targetPort);  //发送函数

//    ui->plainTextEdit_send->appendPlainText("[send]" + msg);   //信息栏显示

//    ui->plainTextEdit->clear();
//    ui->plainTextEdit->setFocus();
}
