#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmenubar.h>
#include <qmenu.h>
#include <qcombobox.h>
#include "Widget.h"
#include <qlineedit.h>
#include  <QtNetwork>
#include <QMessageBox>
#include <QRegExp>
#include <QStringList>
#include <QDateTime>
#include "chartwidget.h"
#include <QMdiSubWindow>
#include "tempwidget.h"
#include "gnsslhl_widget.h"
#include "gnss_dbtwidget.h"
#include "precision_factorwidget.h"
#include <QThread>
#include "mythread.h"
#include "QTimer"
#include "qtimer.h"
#include <string.h>
#include "datatransfer.h"


using namespace test;
using test::UTC_flag;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(2500,1500);

    ui->toolBar_2->addWidget(&spinBox);
    spinBox.setGeometry(100, 50, 200, 40);
    spinBox.setMaximum(99999);
    spinBox.setValue(8080);

    ui->toolBar_3->addWidget(&combo_ip);
    combo_ip.setGeometry(100, 50, 200, 40);
    combo_ip.setText("192.168.1.30");

     QString localIP=getLocalIP();                                                          //本机IP
     this->setWindowTitle(this->windowTitle()+"----本机IP："+localIP);


     // 1. 创建子线程对象
      t1 = new QThread;
//     QThread* t2 = new QThread;
//     QThread* t3 = new QThread;

     // 2. 创建任务类的对象
     gen = new Generate;
//     BubbleSort* bubble = new BubbleSort;
//     QuickSort* quick = new QuickSort;

     // 3. 将任务对象移动到某个子线程中
     gen->moveToThread(t1);
//     bubble->moveToThread(t2);
//     quick->moveToThread(t3);


     ui->lineEdit_lon->setPlaceholderText("(double类型)");
     ui->lineEdit_lat->setPlaceholderText("(double类型)");
     ui->lineEdit_height->setPlaceholderText("(float类型)");
     connect(this, &MainWindow::starting_test1, gen, &Generate::onSocketReadyRead);

     emit starting_test1(10000);
     t1->start();
     // 2. 启动子线程
//     connect(ui->starting_test1, &QPushButton::clicked, this, [=]()
//             {

//             });


//     connect(gen, &Generate::sendArray, bubble, &BubbleSort::working);

//     udpSocket=new QUdpSocket(this);                                                        //用于与连接的客户端通讯的QTcpSocket
//     connect(udpSocket,&QUdpSocket::readyRead,this,&MainWindow::onSocketReadyRead);         //进行udp协议的数据接收建立

     //连接两个触发，将imu的原始数据的文字触发和图案触发连接在一起
     connect(ui->action_14, &QAction::triggered, this, &MainWindow::on_action_pos_triggered);
     //连接两个触发，将imu的温度数据的文字触发和图案触发连接在一起
     connect(ui->action_16, &QAction::triggered, this, &MainWindow::on_action_temp_triggered);
     //连接两个触发，将imu的UTC时间的文字触发和图案触发连接在一起
     connect(ui->actionUTC_2, &QAction::triggered, this, &MainWindow::on_actionUTC_triggered);
     //连接两个触发，将imu的东北天速度的文字触发和图案触发连接在一起
     connect(ui->action_7, &QAction::triggered, this, &MainWindow::on_action_DNU_triggered);
     //连接两个触发，将imu的精度因子的文字触发和图案触发连接在一起
     connect(ui->action_13, &QAction::triggered, this, &MainWindow::on_action_THDV_triggered);
     //连接两个触发，将imu的精度因子的文字触发和图案触发连接在一起
     connect(ui->action, &QAction::triggered, this, &MainWindow::on_actionGPS_triggered);


      emit starting_test1(10000);
     connect(gen, &Generate::sendArray, this, [=](int num1){


           emit starting_test1(10000);
//         ui->plainTextEdit->appendPlainText(num);
//         t2->start();
//         t3->start();
//         for(int i=0; i<list.size(); ++i)
//         {
//             ui->randList->addItem(QString::number(list.at(i)));
//         }
     });
//     while(1){
         emit starting_test1(10000);
//     }

}


/* 关闭应用程序 */
void MainWindow::on_action_exit_triggered()
{
    QApplication* app;
    app->quit();
}

void MainWindow::on_action_com_triggered()
{
   quint16 port = spinBox.value(); //本机UDP端口
    if (gen->udpSockets->bind(port)) //绑定端口成功
   {
        ui->plainTextEdit->appendPlainText("**成功绑定端口");
        ui->plainTextEdit->appendPlainText("**绑定端口：" +QString::number(gen->udpSockets->localPort()));
        ui->plainTextEdit_message->appendPlainText("成功绑定端口,绑定端口："+QString::number(gen->udpSockets->localPort()));
   }

//   quint16 port = spinBox.value(); //本机UDP端口
//   if (udpSocket->bind(port)) //绑定端口成功
//   {
//        ui->plainTextEdit->appendPlainText("**成功绑定端口");
//        ui->plainTextEdit->appendPlainText("**绑定端口：" +QString::number(udpSocket->localPort()));
//        ui->plainTextEdit_message->appendPlainText("成功绑定端口,绑定端口："+QString::number(udpSocket->localPort()));
//   }

}

QString MainWindow::getLocalIP()
{
    QString     hostName=QHostInfo::localHostName();                          //本地主机名
    QHostInfo   hostInfo=QHostInfo::fromName(hostName);                   //
    QString     localIP="";

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

void MainWindow::onSocketReadyRead()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
//        char datagram_2[200];
        datagram.resize(udpSocket->pendingDatagramSize());                 //数据格式统一

        QHostAddress peerAddr;
        quint16 peerPort;
        udpSocket->readDatagram(datagram.data(),
                                200,&peerAddr,&peerPort);      //接收数据


#ifdef BYTE_TARANS
//        char *str1 = datagram_2;
         char *str = (char *)datagram.constData();                                       //数据转换为QT的ui界面使用的QString类型，接受的数据类型为一长串字符


        QString str_data = QString::fromStdString(datagram.toStdString());

        QString peer="[From "+peerAddr.toString()+":"
                +QString::number(peerPort)+"] ";
//        str = "#0X55,0X55,0XAA,0XAA,0X12,114.307865,30.482618,26.3169,-3.006,1.051,4.113,0,0,0,14.8449,0.3719,9.8397,-1.9564,-2.0844,6.0431,0,0,0,0,0,0,1,39.9,114.307865,30.482618,26.3169,0,0,0,0,0,0,0,0,0,1,2,3,4,5,6,1";
        ui->plainTextEdit->appendPlainText(peer+str);
        /*如何构造一个能满足txt文件的格式呢*/

        static QString header_1 = "0x55";static QString header_2 = "0x55";static QString header_3 = "0xAA";static QString header_4 = "0xAA";static QString header_5 = "0x12";


        unsigned char *ucharArray = reinterpret_cast<unsigned char*>(str);

        if(ucharArray[0]==0x55 && ucharArray[1]==0x55 && ucharArray[2]==0xAA && ucharArray[3]==0xAA && ucharArray[4]==0x12)
        {
//               Inertial_navigation_chars = 0;
            //mem

//                memcpy(Inertial_navigation_chars.header_id,ucharArray,5);
//            //       qDebug() << "lon = " << Inertial_navigation_chars.header_id;
//                memcpy(Inertial_navigation_chars.lon.pre_c,ucharArray+5,8);
//                memcpy(Inertial_navigation_chars.lat.pre_c,ucharArray+13,8);
//                memcpy(Inertial_navigation_chars.height.pre_c,ucharArray+21,4);
//                memcpy(Inertial_navigation_chars.ve.pre_c,ucharArray+25,4);
//                memcpy(Inertial_navigation_chars.vn.pre_c,ucharArray+29,4);
//                memcpy(Inertial_navigation_chars.vu.pre_c,ucharArray+33,4);

//                memcpy(Inertial_navigation_chars.pitch.pre_c,ucharArray+37,4);
//                memcpy(Inertial_navigation_chars.roll.pre_c,ucharArray+41,4);
//                memcpy(Inertial_navigation_chars.yaw.pre_c,ucharArray+45,4);

//                memcpy(Inertial_navigation_chars.accelx.pre_c,ucharArray+49,4);
//                memcpy(Inertial_navigation_chars.accely.pre_c,ucharArray+53,4);
//                memcpy(Inertial_navigation_chars.accelz.pre_c,ucharArray+57,4);
//                memcpy(Inertial_navigation_chars.accel_ratex.pre_c,ucharArray+61,4);
//                memcpy(Inertial_navigation_chars.accel_ratey.pre_c,ucharArray+65,4);
//                memcpy(Inertial_navigation_chars.accel_ratez.pre_c,ucharArray+69,4);

//                memcpy(Inertial_navigation_chars.years.pre_c,ucharArray+73,4);
//                memcpy(Inertial_navigation_chars.months.pre_c,ucharArray+77,4);
//                memcpy(Inertial_navigation_chars.date.pre_c,ucharArray+81,4);

//                memcpy(Inertial_navigation_chars.hours.pre_c,ucharArray+85,4);
//                memcpy(Inertial_navigation_chars.mins.pre_c,ucharArray+89,4);
//                memcpy(Inertial_navigation_chars.secs.pre_c,ucharArray+93,4);

////                Inertial_navigation_chars.imu_sensor_temps = ucharArray[97];
//                memcpy(Inertial_navigation_chars.imu_sensor_temps.pre_c,ucharArray+98,4);
//                memcpy(Inertial_navigation_chars.timestamps.pre_c,ucharArray+102,4);

//                memcpy(Inertial_navigation_chars.lon_n.pre_c,ucharArray+106,8);
//                memcpy(Inertial_navigation_chars.lat_n.pre_c,ucharArray+114,8);


//                memcpy(Inertial_navigation_chars.height_n.pre_c,ucharArray+122,4);
//                memcpy(Inertial_navigation_chars.ve_n.pre_c,ucharArray+126,4);
//                memcpy(Inertial_navigation_chars.vn_n.pre_c,ucharArray+130,4);
//                memcpy(Inertial_navigation_chars.vu_n.pre_c,ucharArray+134,4);

//                memcpy(Inertial_navigation_chars.MagNormX.pre_c,ucharArray+138,4);
//                memcpy(Inertial_navigation_chars.MagNormY.pre_c,ucharArray+142,4);
//                memcpy(Inertial_navigation_chars.MagNormZ.pre_c,ucharArray+146,4);
//                memcpy(Inertial_navigation_chars.MagValueX.pre_c,ucharArray+150,4);
//                memcpy(Inertial_navigation_chars.MagValueY.pre_c,ucharArray+154,4);
//                memcpy(Inertial_navigation_chars.MagValueZ.pre_c,ucharArray+158,4);

//                memcpy(Inertial_navigation_chars.PDOP.pre_c,ucharArray+162,4);
//                memcpy(Inertial_navigation_chars.HDOP.pre_c,ucharArray+166,4);
//                memcpy(Inertial_navigation_chars.VDOP.pre_c,ucharArray+170,4);
//                memcpy(Inertial_navigation_chars.TDOP.pre_c,ucharArray+174,4);
//                memcpy(Inertial_navigation_chars.GDOP.pre_c,ucharArray+178,4);

//                memcpy(Inertial_navigation_chars.SatNumS.pre_c,ucharArray+182,4);


//                num_Lon = Inertial_navigation_chars.lon.pre;num_Lat = Inertial_navigation_chars.lat.pre;num_Height = Inertial_navigation_chars.height.pre;
//                num_EastVel = Inertial_navigation_chars.ve.pre;num_NorthVel = Inertial_navigation_chars.vn.pre; num_UpVel = Inertial_navigation_chars.vu.pre;
//                num_ac_x = Inertial_navigation_chars.accelx.pre;num_ac_y = Inertial_navigation_chars.accely.pre;num_ac_z = Inertial_navigation_chars.accelz.pre;
//                num_angle_rate_x = Inertial_navigation_chars.accel_ratex.pre;num_angle_rate_y = Inertial_navigation_chars.accel_ratey.pre;num_angle_rate_z = Inertial_navigation_chars.accel_ratez.pre;

//                num_PDOP = Inertial_navigation_chars.PDOP.pre;num_HDOP = Inertial_navigation_chars.HDOP.pre;num_VDOP = Inertial_navigation_chars.VDOP.pre;

//                num_TDOP = Inertial_navigation_chars.TDOP.pre;;num_GDOP = Inertial_navigation_chars.GDOP.pre;

        }


#endif

#ifdef NORMAL_TARANS

        QString str=datagram.data();                                       //数据转换为QT的ui界面使用的QString类型，接受的数据类型为一长串字符

        QString peers="[From "+peerAddr.toString()+":"
                +QString::number(peerPort)+"] ";


//        str = "#0X55,0X55,0XAA,0XAA,0X12,114.307865,30.482618,26.3169,-3.006,1.051,4.113,0,0,0,14.8449,0.3719,9.8397,-1.9564,-2.0844,6.0431,0,0,0,0,0,0,1,39.9,114.307865,30.482618,26.3169,0,0,0,0,0,0,0,0,0,1,2,3,4,5,6,1";
        ui->plainTextEdit->appendPlainText(peers+str);
        QString header = "#";
//        if(str.startsWith(header))
//        {
//            QRegExp regex(",");
//            QStringList list = str.split(regex);                      //将收到的数据进行逗号“,”分离（英文逗号）
//            PDOP=list.at(41);/*PDOP.remove(0, 1);*/num_PDOP = PDOP.trimmed().toFloat();                    //去除前面的#作为检验                                          //进行数据填充
//            HDOP=list.at(42);num_HDOP = HDOP.trimmed().toFloat();
//            VDOP=list.at(43);num_VDOP = VDOP.trimmed().toFloat();
//            TDOP=list.at(44);num_TDOP = TDOP.trimmed().toFloat();
//            GDOP=list.at(45);num_GDOP = GDOP.trimmed().toFloat();
//            Lon=list.at(5);num_Lon = Lon.trimmed().toFloat();
//            Lat=list.at(6);num_Lat = Lat.trimmed().toFloat();
//            Height=list.at(7);num_Height = Height.trimmed().toFloat();
//            EastVel=list.at(8);num_EastVel = EastVel.trimmed().toFloat();
//            NorthVel=list.at(9);num_NorthVel = NorthVel.trimmed().toFloat();
//            UpVel=list.at(10);num_UpVel = UpVel.trimmed().toFloat();
//            heading=list.at(28);num_heading = heading.trimmed().toFloat();  //这里将组合导航暂时替换朝向角

//            ac_x=list.at(14);num_ac_x = ac_x.trimmed().toFloat();
//            ac_y=list.at(15);num_ac_y = ac_y.trimmed().toFloat();
//            ac_z=list.at(16);num_ac_z = ac_z.trimmed().toFloat();
//            angle_rate_x=list.at(17);num_angle_rate_x = angle_rate_x.trimmed().toFloat();
//            angle_rate_y=list.at(18);num_angle_rate_y = angle_rate_y.trimmed().toFloat();
//            angle_rate_z=list.at(19);num_angle_rate_z = angle_rate_z.trimmed().toFloat();
//            sig=list.at(1);num_sig = sig.trimmed().toFloat();   //将sig改为0x55
//            Temp=list.at(27);num_temp = Temp.trimmed().toFloat();


//            QMetaObject::invokeMethod(this, "myFunction", Qt::QueuedConnection);
//        }

#endif

             if(save_flag)                                           //开始保存标志位判断
             {
                num++;                                               //存储数据的序号排列
                if( file.open(QIODevice::WriteOnly  |  QIODevice::Text | QIODevice::Append) )
                {
                    QTextStream out(&file); //IO设备对象的地址对其进行初始化

                    QString num_str = QString("%1").arg(num,6,10,QLatin1Char('0'));
                    /* txt 文件首行的各种数据的title */

//                    out<<Inertial_navigation_chars.+' '<<;
                      out<<str;
    //                out<<"  "<<num_str<<"    ";
    //                out<<PDOP<<" "<<HDOP<<" "<<VDOP<<" "<<TDOP<<" "<<GDOP<<" ";
    //                out<<Lon<<" "<<Lat<<" "<<Height<<" "<<EastVel<<" "<<NorthVel<<" "<<UpVel<<" "<<heading<<" ";
    //                out<<ac_x<<" "<<ac_y<<" "<<ac_z<<" "<<angle_rate_x<<" "<<angle_rate_y<<" "<<angle_rate_z<<" "<<sig;
                    file.close();
                }

           }

          /*开始进行多线程任务的向下传输*/
         emit starting_test1(10000);
    }
}




void MainWindow::on_actionip_triggered()
{
    QMessageBox::question(this,"IP目标地址","是否设置IP",QMessageBox::Yes | QMessageBox::No,QMessageBox::Yes);
    ui->plainTextEdit_message->appendPlainText("成功设置IP地址,目标IP为:"+combo_ip.text());
}

void MainWindow::on_action_start_triggered()
{
    QFileDialog dlg(this);

        //获取内容的保存路径
        QString fileName = dlg.getSaveFileName(this, tr("Save As"), "./", tr("Text File(*.txt)"));

        if( fileName == "" )
        {
            return;
        }

        //内容保存到路径文件
        gen->file.setFileName(fileName);
        save_flag=1;
        gen->save_flag = 1;

        //以文本方式打开
        if( gen->file.open(QIODevice::WriteOnly  |  QIODevice::Text | QIODevice::Append) )
        {
            QTextStream out(&gen->file); //IO设备对象的地址对其进行初始化

//            QTextStream out(&file); //IO设备对象的地址对其进行初始化
            /* 对数据进行保存 */

            // 获取当前日期和时间
            QDateTime currentDateTime = QDateTime::currentDateTime();
            // 格式化为字符串
            QString currentDateTimeString = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");
            out<<"% Date time:"<<currentDateTimeString<<endl;

//            out<<"% ";
//            QString chineseText = "序号";
//            out << chineseText;
//            out<<" PDOP  ";
//            out<<"HDOP  ";
//            out<<"VDOP  ";
//            out<<"TDOP  ";
//            out<<"GDOP  ";
//            out<<"Lon        ";
//            out<<"Lat     ";
//            out<<"Heig   ";
//            out<<"Evel  ";
//            out<<"Nvel  ";
//            out<<"Uvel  ";
//            out<<"heading  ";
//            out<<"ac_x   ";
//            out<<"ac_y   ";
//            out<<"ac_z   ";
//            out<<"ar_x   ";
//            out<<"ar_y   ";
//            out<<"ar_z   ";
//            out<<"sig   "<<endl;
            num=0;
            gen->file.close();
        }
        else
        {
            QMessageBox::warning(this, tr("Error"), tr("File to open file!"));
        }


}

void MainWindow::on_action_end_triggered()
{
    save_flag=0;                            //保存标志位，置0不再进行保存
    gen->save_flag = 0;
    num=0;
    QMessageBox::warning(this, tr("Finish"), tr("Successfully save the file!"));
    file.close();
}

void MainWindow::on_action_pos_triggered()
{
    test::IMU_flag++;
    if(test::IMU_flag==1)
    {

        Raw_imu = new ChartWidget;               //创建imu数据对象
        QMdiSubWindow *subWindow1 = new QMdiSubWindow;
        Raw_imu->resize(1000,800);
        subWindow1->setWidget(Raw_imu);
        subWindow1->resize(Raw_imu->size());

        connect(gen,&Generate::sendArray,Raw_imu,&ChartWidget::working);
        subWindow1->setAttribute(Qt::WA_DeleteOnClose);
        Raw_imu->setAttribute(Qt::WA_DeleteOnClose);
        ui->mdiArea->addSubWindow(subWindow1);
        Raw_imu->show();
        Raw_imu->setWindowTitle("imu原始数据");
    }
}

void MainWindow::on_pushButton_clicked()          //向外发送信号
{
    QString targetIP=combo_ip.text();
    QHostAddress targetAddr(targetIP);  //目标IP

    quint16 targetPort = spinBox.value();  //目标端口号
    QString msg_lon= ui->lineEdit_lon->text()+','; //发送内容

    QString msg_lat = ui->lineEdit_lat->text()+','; //发送内容
    QString msg_height = ui->lineEdit_height->text(); //发送内容

    QByteArray str = msg_lon.toUtf8()+msg_lat.toUtf8()+msg_height.toUtf8();

     gen->udpSockets->writeDatagram(str, targetAddr, targetPort);  //发送函数

    ui->plainTextEdit_send->appendPlainText("[send]" + str);   //信息栏显示
}


void MainWindow::on_actionUTC_triggered()
{
     test::UTC_flag++;
     if(test::UTC_flag==1)
     {
         utctext = new UTCtext;                      //创建utc时间对象
         QMdiSubWindow *subWindow2 = new QMdiSubWindow;
         utctext->resize(800,400);
         subWindow2->setWidget(utctext);
         subWindow2->resize(utctext->size());
         ui->mdiArea->addSubWindow(subWindow2);
         utctext->show();
         utctext->setWindowTitle("UTC时间");
         connect(gen,&Generate::sendArray,utctext,&UTCtext::working);
//         connect(this,&MainWindow::starting_test1,utctext,&UTCtext::working);            //连接程序启动与各对象的working函数，等待emit指令后开始运行程序
         subWindow2->setAttribute(Qt::WA_DeleteOnClose);
         utctext->setAttribute(Qt::WA_DeleteOnClose);
     }
}


void MainWindow::on_action_temp_triggered()
{
    test::TEMP_flag++;
    if(test::TEMP_flag==1)
    {
        tempwidget  = new TempWidget;                //创建温度对象
        QMdiSubWindow *subWindow_temp = new QMdiSubWindow;
        tempwidget->resize(800,400);
        subWindow_temp->setWidget(tempwidget);
        subWindow_temp->resize(tempwidget->size());
        ui->mdiArea->addSubWindow(subWindow_temp);
        tempwidget->show();
        tempwidget->setWindowTitle("IMU温度");
        connect(gen,&Generate::sendArray,tempwidget,&TempWidget::working);
//        connect(this,&MainWindow::starting_test1,tempwidget,&TempWidget::working);            //连接程序启动与各对象的working函数，等待emit指令后开始运行程序
        subWindow_temp->setAttribute(Qt::WA_DeleteOnClose);
        tempwidget->setAttribute(Qt::WA_DeleteOnClose);
     }
}

void MainWindow::on_actionGPS_triggered()
{
    test::GNSS_LHL_flag++;
    if(test::GNSS_LHL_flag==1)
    {
        lhlwidget = new Gnsslhl_Widget;           //创建经纬高对象
        QMdiSubWindow *subWindow_lhl = new QMdiSubWindow;
        lhlwidget->resize(1200,1000);
        subWindow_lhl->setWidget(lhlwidget);
        subWindow_lhl->resize(lhlwidget->size());
        ui->mdiArea->addSubWindow(subWindow_lhl);
        lhlwidget->show();
        lhlwidget->setWindowTitle("GPS数据");
        connect(gen,&Generate::sendArray,lhlwidget,&Gnsslhl_Widget::working);
//        connect(this,&MainWindow::starting_test1,lhlwidget,&Gnsslhl_Widget::working);
        subWindow_lhl->setAttribute(Qt::WA_DeleteOnClose);
        lhlwidget->setAttribute(Qt::WA_DeleteOnClose);
     }
}

void MainWindow::on_action_DNU_triggered()
{
    test::GNSS_DBT_flag++;
    if(test::GNSS_DBT_flag==1)
    {
        dbtwidget = new Gnss_dbtWidget;           //创建东北天速度对象
        QMdiSubWindow *subWindow_dbt = new QMdiSubWindow;
        dbtwidget->resize(1000,1000);
        subWindow_dbt->setWidget(dbtwidget);
        subWindow_dbt->resize(dbtwidget->size());
        ui->mdiArea->addSubWindow(subWindow_dbt);
        dbtwidget->show();
        dbtwidget->setWindowTitle("GPS速度数据");
        connect(gen,&Generate::sendArray,dbtwidget,&Gnss_dbtWidget::working);
//        connect(this,&MainWindow::starting_test1,dbtwidget,&Gnss_dbtWidget::working);
        subWindow_dbt->setAttribute(Qt::WA_DeleteOnClose);
        dbtwidget->setAttribute(Qt::WA_DeleteOnClose);
    }
}

void MainWindow::on_action_THDV_triggered()
{
    test::FACOTR_flag++;
    if(test::FACOTR_flag==1)
    {
        PFtext = new Precision_factorWidget;   //创建精度因子对象
        QMdiSubWindow *subWindow_PF = new QMdiSubWindow;
        PFtext->resize(600,200);
        subWindow_PF->setWidget(PFtext);
        subWindow_PF->resize(PFtext->size());
        ui->mdiArea->addSubWindow(subWindow_PF);
        PFtext->show();
        PFtext->setWindowTitle("精度因子");
        subWindow_PF->setAttribute(Qt::WA_DeleteOnClose);
        PFtext->setAttribute(Qt::WA_DeleteOnClose);
        connect(gen,&Generate::sendArray,PFtext,&Precision_factorWidget::working);
//        connect(this,&MainWindow::starting_test1,PFtext,&Precision_factorWidget::working);
//        PFtext->para_for_chart(&num_PDOP,&num_HDOP,&num_VDOP,&num_TDOP,&num_GDOP);
     }
}


void MainWindow::singal_UTC_block_only()
{
//    MainWindow::/*ui->actionUTC->blockSignals(false);*/
}


MainWindow::~MainWindow()
{
     gen->udpSockets->abort();
    delete  gen->udpSockets;
    delete ui;
}

