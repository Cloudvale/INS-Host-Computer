#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Widget.h"
#include <QComboBox>
#include <qlineedit.h>
#include <QSpinBox>
#include "chartwidget.h"
#include "utctext.h"
#include <QMdiSubWindow>
#include "tempwidget.h"
#include "gnss_dbtwidget.h"
#include "gnsslhl_widget.h"
#include "precision_factorwidget.h"
#include "mythread.h"
#include "datatransfer.h"

namespace Ui {
class MainWindow;
//extern int UTC_flag;
}



//using namespace test;



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void singal_UTC_block_only();


signals:

    void starting_test1(int num);
    void starting_test2(int num);
    void starting_test3(int num);
private slots:

    void on_action_exit_triggered();

    void on_action_com_triggered();

    void onSocketReadyRead();                       //读取socket传入的数据
//    void on_pushButton_clicked();                   //对端口号进行绑定
//    void on_pushButton_save_start_clicked();        //开始进行txt文件保存
//    void on_pushButton_save_end_clicked();          //结束txt保存

    void on_actionip_triggered();

    void on_action_start_triggered();

    void on_action_end_triggered();

    void on_action_pos_triggered();

    void on_pushButton_clicked();

    void on_actionUTC_triggered();

    void on_action_temp_triggered();

    void on_actionGPS_triggered();

    void on_action_DNU_triggered();

    void on_action_THDV_triggered();


private:
    Ui::MainWindow *ui;
    QSpinBox    spinBox;
    QComboBox   combo;
    QLineEdit   combo_ip;
//    ChartWidget Raw_imu;
    QMainWindow Raw_imu_window;

    QUdpSocket *udpSocket;//
    QThread    *t1;
    QThread    *t2;
    QThread    *t3;
    Generate* gen;
    QString getLocalIP();                //获取本机IP地址
    QFile file;                          //电脑保存txt的文件
    int save_flag;                       //关闭保存标志位
    int num;
    QString PDOP;QString HDOP;QString VDOP;QString TDOP;QString GDOP;
    QString Lon;QString Lat;QString Height;QString EastVel;QString NorthVel;QString UpVel;QString heading;
    QString ac_x;QString ac_y;QString ac_z;
    QString angle_rate_x;QString angle_rate_y;QString angle_rate_z;QString sig;QString Temp;

//    float num_PDOP;float num_HDOP;float num_VDOP;float num_TDOP;float num_GDOP;
//    float num_Lon;float num_Lat;float num_Height;float num_EastVel;float num_NorthVel;float num_UpVel;float num_heading;
//    float num_ac_x;float num_ac_y;float num_ac_z;
//    float num_angle_rate_x;float num_angle_rate_y;float num_angle_rate_z;float num_sig;

    int pre_factor_flag;
    QTimer *m_timer_test;
    UTCtext *utctext;
    ChartWidget *Raw_imu;
    TempWidget *tempwidget;
    Gnsslhl_Widget *lhlwidget;
    Gnss_dbtWidget *dbtwidget;
    Precision_factorWidget *PFtext;

//    QThread* t1;


//    int UTC_flag;
//    Ui::UTC_flag *sds;
//    Ui::UTC_flag *UTC_flags;

};


class Inertial_navigation{
public:
     char data_header[5];
     double data_lon_pre;
     double data_lat_pre;
     double data_height_pre;
     double data_vele_pre;
     double data_veln_pre;
     double data_velu_pre;
     double data_pitch_pre;
     float data_yaw_pre;
//     double data_roll_pre;
//     double data_accelx_pre;
//     double data_accely_pre;
//     double data_accelz_pre;
//     double data_accel_ratex_pre;
//     double data_accel_ratey_pre;
//     double data_accel_ratez_pre;
//     int32_t data_year;
//     int32_t data_month;
//     int32_t data_date;
//     int32_t data_hour;
//     int32_t data_min;
//     double date_sec;
//     char state;
//     float temp_sensor;
//     int32_t timestamps;
//     float data_lon;
//     float data_lat;
//     float data_height;
//     float data_ve;
//     float data_vn;
//     float data_vu;
//     float PDOP;
//     float HDOP;
//     float VDOP;
//     float TDOP;
//     float GDOP;

};

union d8
{
    double pre;
    unsigned char pre_c[8];
};

union f4
{
    float pre;
    unsigned char pre_c[4];
};

union U4
{
    qint32 pre;
    unsigned char pre_c[4];
};



struct Inertial_navigation_char{

    unsigned char header_id[5];
    d8 lon;
    d8 lat;
    f4 height;
    f4 ve;
    f4 vn;
    f4 vu;
    f4 pitch;
    f4 yaw;
    f4 roll;
    f4 accelx;
    f4 accely;
    f4 accelz;
    f4 accel_ratex;
    f4 accel_ratey;
    f4 accel_ratez;
    U4 years;
    U4 months;
    U4 date;
    U4 hours;
    U4 mins;
    U4 secs;
    unsigned char combine_state;
    f4 imu_sensor_temps;
    U4 timestamps;
    d8 lon_n;
    d8 lat_n;
    f4 height_n;
    f4 ve_n;
    f4 vn_n;
    f4 vu_n;
    f4 MagNormX;
    f4 MagNormY;
    f4 MagNormZ;
    f4 MagValueX;
    f4 MagValueY;
    f4 MagValueZ;

    f4 PDOP;
    f4 HDOP;
    f4 VDOP;
    f4 TDOP;
    f4 GDOP;
    f4 SatNumS;

};

#endif // MAINWINDOW_H
