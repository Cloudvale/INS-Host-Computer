#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>
#include <QFileDialog>
#include <QMainWindow>

namespace Ui {
class Widget;
}

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:

    Ui::Widget *ui;
    QUdpSocket *udpSocket;//
    QString getLocalIP();                //获取本机IP地址
    QFile file;                          //电脑保存txt的文件
    int save_flag;                       //关闭保存标志位
    QString PDOP;                        //精度因子
    QString HDOP;                        //精度因子
    QString TDOP;                        //精度因子
    QString VDOP;                        //精度因子
    QString GDOP;                        //精度因子
    QString Lon;                         //经度
    QString Lat;                         //纬度
    QString Height;                      //高度
    QString EastVel;                     //东向速度
    QString NorthVel;                    //北向速度
    QString UpVel;                       //天向速度
    QString ac_x;                        //x轴加速度
    QString ac_y;                        //y轴加速度
    QString ac_z;                        //z轴加速度
    QString angle_rate_x;                //x轴角速率
    QString angle_rate_y;                //y轴角速率
    QString angle_rate_z;                //z轴角速率
    QString sig;
    QString heading;
    int num;


private slots:
    void onSocketReadyRead();                       //读取socket传入的数据
    void on_pushButton_clicked();                   //对端口号进行绑定
    void on_pushButton_save_start_clicked();        //开始进行txt文件保存
    void on_pushButton_save_end_clicked();          //结束txt保存
    void on_pushButton_2_clicked();
};

#endif // WIDGET_H
