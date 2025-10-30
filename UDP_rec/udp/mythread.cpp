#include "mythread.h"
#include <QElapsedTimer>
#include <QDebug>
#include <QThread>
#include <QMetaType>
#include "datatransfer.h"
#include "mainwindow.h"


using namespace test;

Generate::Generate(QObject *parent) : QObject(parent)
{
    udpSockets = new QUdpSocket;
//    while(1){
//        onSocketReadyRead();
//    }

}

void Generate::working(int num)
{
//    qDebug() << "生成随机数的线程的线程地址: " << QThread::currentThread();
//    utctext->
//    utctext->working(10000);
//    qRegisterMetaType<QVector<int>>("QVector<int>");
//    QVector<int> list;
//    QElapsedTimer time;
//    time.start();
//    for(int i=0; i<num; ++i).
//    {
//        list.push_back(qrand() % 100000);
//    }
//    int milsec = time.elapsed();
//    qDebug() << "生成" << num << "个随机数总共用时:" << milsec << "毫秒";
//    QVector<int> list;
//    list.push_back(1);
//    emit sendArray(list);
}


void Generate::onSocketReadyRead()
{
    QString str_send = "";
    while(udpSockets->hasPendingDatagrams())
    {
        QByteArray datagram;
        //        char datagram_2[200];
        datagram.resize(udpSockets->pendingDatagramSize());                 //数据格式统一

        QHostAddress peerAddr;
        quint16 peerPort;
        udpSockets->readDatagram(datagram.data(),
                                200,&peerAddr,&peerPort);      //接收数据


    #ifdef BYTE_TARANS
//                char *str1 = datagram_2;
        char *str = (char *)datagram.constData();                                       //数据转换为QT的ui界面使用的QString类型，接受的数据类型为一长串字符


        QString str_data = QString::fromStdString(datagram.toStdString());

        QString peer="[From "+peerAddr.toString()+":"
                       +QString::number(peerPort)+"] ";
        str_send = peer+str;
        //        str = "#0X55,0X55,0XAA,0XAA,0X12,114.307865,30.482618,26.3169,-3.006,1.051,4.113,0,0,0,14.8449,0.3719,9.8397,-1.9564,-2.0844,6.0431,0,0,0,0,0,0,1,39.9,114.307865,30.482618,26.3169,0,0,0,0,0,0,0,0,0,1,2,3,4,5,6,1";
//        ui->plainTextEdit->appendPlainText(peer+str)------
        /*如何构造一个能满足txt文件的格式呢*/

        static QString header_1 = "0x55";static QString header_2 = "0x55";static QString header_3 = "0xAA";static QString header_4 = "0xAA";static QString header_5 = "0x12";


        unsigned char *ucharArray = reinterpret_cast<unsigned char*>(str);

        if(ucharArray[0]==0x55 && ucharArray[1]==0x55 && ucharArray[2]==0xAA && ucharArray[3]==0xAA && ucharArray[4]==0x12)
        {
//            static Inertial_navigation_char Inertial_navigation_chars;
            //mem

            memcpy(Inertial_navigation_chars.header_id,ucharArray,5);
            //       qDebug() << "lon = " << Inertial_navigation_chars.header_id;
            memcpy(Inertial_navigation_chars.lon.pre_c,ucharArray+5,8);
            memcpy(Inertial_navigation_chars.lat.pre_c,ucharArray+13,8);
            memcpy(Inertial_navigation_chars.height.pre_c,ucharArray+21,4);
            memcpy(Inertial_navigation_chars.ve.pre_c,ucharArray+25,4);
            memcpy(Inertial_navigation_chars.vn.pre_c,ucharArray+29,4);
            memcpy(Inertial_navigation_chars.vu.pre_c,ucharArray+33,4);

            memcpy(Inertial_navigation_chars.pitch.pre_c,ucharArray+37,4);
            memcpy(Inertial_navigation_chars.roll.pre_c,ucharArray+41,4);
            memcpy(Inertial_navigation_chars.yaw.pre_c,ucharArray+45,4);

            memcpy(Inertial_navigation_chars.accelx.pre_c,ucharArray+49,4);
            memcpy(Inertial_navigation_chars.accely.pre_c,ucharArray+53,4);
            memcpy(Inertial_navigation_chars.accelz.pre_c,ucharArray+57,4);
            memcpy(Inertial_navigation_chars.accel_ratex.pre_c,ucharArray+61,4);
            memcpy(Inertial_navigation_chars.accel_ratey.pre_c,ucharArray+65,4);
            memcpy(Inertial_navigation_chars.accel_ratez.pre_c,ucharArray+69,4);

            memcpy(Inertial_navigation_chars.years.pre_c,ucharArray+73,4);
            memcpy(Inertial_navigation_chars.months.pre_c,ucharArray+77,4);
            memcpy(Inertial_navigation_chars.date.pre_c,ucharArray+81,4);

            memcpy(Inertial_navigation_chars.hours.pre_c,ucharArray+85,4);
            memcpy(Inertial_navigation_chars.mins.pre_c,ucharArray+89,4);
            memcpy(Inertial_navigation_chars.secs.pre_c,ucharArray+93,4);

            //                Inertial_navigation_chars.imu_sensor_temps = ucharArray[97];
            memcpy(Inertial_navigation_chars.imu_sensor_temps.pre_c,ucharArray+98,4);
            memcpy(Inertial_navigation_chars.timestamps.pre_c,ucharArray+102,4);

            memcpy(Inertial_navigation_chars.lon_n.pre_c,ucharArray+106,8);
            memcpy(Inertial_navigation_chars.lat_n.pre_c,ucharArray+114,8);


            memcpy(Inertial_navigation_chars.height_n.pre_c,ucharArray+122,4);
            memcpy(Inertial_navigation_chars.ve_n.pre_c,ucharArray+126,4);
            memcpy(Inertial_navigation_chars.vn_n.pre_c,ucharArray+130,4);
            memcpy(Inertial_navigation_chars.vu_n.pre_c,ucharArray+134,4);

            memcpy(Inertial_navigation_chars.MagNormX.pre_c,ucharArray+138,4);
            memcpy(Inertial_navigation_chars.MagNormY.pre_c,ucharArray+142,4);
            memcpy(Inertial_navigation_chars.MagNormZ.pre_c,ucharArray+146,4);
            memcpy(Inertial_navigation_chars.MagValueX.pre_c,ucharArray+150,4);
            memcpy(Inertial_navigation_chars.MagValueY.pre_c,ucharArray+154,4);
            memcpy(Inertial_navigation_chars.MagValueZ.pre_c,ucharArray+158,4);

            memcpy(Inertial_navigation_chars.PDOP.pre_c,ucharArray+162,4);
            memcpy(Inertial_navigation_chars.HDOP.pre_c,ucharArray+166,4);
            memcpy(Inertial_navigation_chars.VDOP.pre_c,ucharArray+170,4);
            memcpy(Inertial_navigation_chars.TDOP.pre_c,ucharArray+174,4);
            memcpy(Inertial_navigation_chars.GDOP.pre_c,ucharArray+178,4);

            memcpy(Inertial_navigation_chars.SatNumS.pre_c,ucharArray+182,4);


            num_Lon = Inertial_navigation_chars.lon.pre;num_Lat = Inertial_navigation_chars.lat.pre;num_Height = Inertial_navigation_chars.height.pre;
            num_EastVel = Inertial_navigation_chars.ve.pre;num_NorthVel = Inertial_navigation_chars.vn.pre; num_UpVel = Inertial_navigation_chars.vu.pre;
            num_ac_x = Inertial_navigation_chars.accelx.pre;num_ac_y = Inertial_navigation_chars.accely.pre;num_ac_z = Inertial_navigation_chars.accelz.pre;
            num_angle_rate_x = Inertial_navigation_chars.accel_ratex.pre;num_angle_rate_y = Inertial_navigation_chars.accel_ratey.pre;num_angle_rate_z = Inertial_navigation_chars.accel_ratez.pre;

            num_PDOP = Inertial_navigation_chars.PDOP.pre;num_HDOP = Inertial_navigation_chars.HDOP.pre;num_VDOP = Inertial_navigation_chars.VDOP.pre;

            num_TDOP = Inertial_navigation_chars.TDOP.pre;;num_GDOP = Inertial_navigation_chars.GDOP.pre;

        }


    #endif


        if(save_flag)                                           //开始保存标志位判断
        {
            num++;                                               //存储数据的序号排列
            if( file.open(QIODevice::WriteOnly  |  QIODevice::Text | QIODevice::Append) )
            {                
                static double pick = 0;

                if(pick !=Inertial_navigation_chars.accelx.pre)
                {

                    pick=Inertial_navigation_chars.accelx.pre;

                    QTextStream out(&file); //IO设备对象的地址对其进行初始化

                    QString num_str = QString("%1").arg(num,6,10,QLatin1Char('0'));
                    /* txt 文件首行的各种数据的title */
                    out<<' ';
                    out<<Inertial_navigation_chars.accelx.pre<<' '<<-Inertial_navigation_chars.accelz.pre<<' '<<Inertial_navigation_chars.accely.pre<<' ';
                    out<<Inertial_navigation_chars.accel_ratex.pre<<' '<<Inertial_navigation_chars.accel_ratez.pre<<' '<<Inertial_navigation_chars.accel_ratey.pre<<' ';
                    out<<Inertial_navigation_chars.lat_n.pre<<' '<<Inertial_navigation_chars.lon_n.pre<<' '<<Inertial_navigation_chars.height_n.pre<<' ';
                    out<<Inertial_navigation_chars.pitch.pre<<' '<<Inertial_navigation_chars.roll.pre<<' '<<Inertial_navigation_chars.yaw.pre<<' ';
                    out<<Inertial_navigation_chars.ve_n.pre<<' '<<Inertial_navigation_chars.vn_n.pre<<' '<<Inertial_navigation_chars.vu_n.pre<<' ';
                    out<<Inertial_navigation_chars.lat.pre<<' '<<Inertial_navigation_chars.lon.pre<<' '<<Inertial_navigation_chars.height.pre<<' '<<'\n';

//                    file.close();
                }

                file.close();

            }

        }

        /*开始进行多线程任务的向下传输*/
    //    emit starting_test1(10000);

//        emit sendArray(1);
    }

     emit sendArray(1);
}

BubbleSort::BubbleSort(QObject *parent) : QObject(parent)
{

}

void BubbleSort::working(QVector<int> list)
{
    qDebug() << "冒泡排序的线程的线程地址: " << QThread::currentThread();
    QElapsedTimer time;
    time.start();
    int temp;
    for(int i=0; i<list.size(); ++i)
    {
        for(int j=0; j<list.size()-i-1; ++j)
        {
            if(list[j] > list[j+1])
            {
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
    int milsec = time.elapsed();
    qDebug() << "冒泡排序用时" << milsec << "毫秒";
    emit finish(list);
}

QuickSort::QuickSort(QObject *parent) : QObject(parent)
{

}

void QuickSort::working(QVector<int> list)
{
    qDebug() << "快速排序的线程的线程地址: " << QThread::currentThread();
    QElapsedTimer time;
    time.start();
    quickSort(list, 0, list.size()-1);
    int milsec = time.elapsed();
    qDebug() << "快速排序用时" << milsec << "毫秒";
    emit finish(list);
}

void QuickSort::quickSort(QVector<int> &s, int l, int r)
{
    if (l < r)
    {
        int i = l, j = r;
        // 拿出第一个元素, 保存到x中,第一个位置成为一个坑
        int x = s[l];
        while (i < j)
        {
            // 从右向左找小于x的数
            while (i < j && s[j] >= x)
            {
                //左移, 直到遇到小于等于x的数
                j--;
            }
            if (i < j)
            {
                //将右侧找到的小于x的元素放入左侧坑中, 右侧出现一个坑
                //左侧元素索引后移
                s[i++] = s[j];
            }

            // 从左向右找大于等于x的数
            while (i < j && s[i] < x)
            {
                //右移, 直到遇到大于x的数
                i++;
            }
            if (i < j)
            {
                //将左侧找到的元素放入右侧坑中, 左侧出现一个坑
                //右侧元素索引向前移动
                s[j--] = s[i];
            }
        }
        //此时 i=j,将保存在x中的数填入坑中
        s[i] = x;
        quickSort(s, l, i - 1); // 递归调用
        quickSort(s, i + 1, r);
    }
}

