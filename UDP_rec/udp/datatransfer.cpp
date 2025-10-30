#include "datatransfer.h"
#include "qlabel.h"

namespace test {
//class MainWindow;
int UTC_flag=0;int IMU_flag;int GNSS_DBT_flag;int GNSS_LHL_flag;int TEMP_flag;int FACOTR_flag;
float num_PDOP;float num_HDOP;float num_VDOP;float num_TDOP;float num_GDOP;
float num_Lon;float num_Lat;float num_Height;float num_EastVel;float num_NorthVel;float num_UpVel;float num_heading;
float num_ac_x;float num_ac_y;float num_ac_z;
float num_angle_rate_x;float num_angle_rate_y;float num_angle_rate_z;float num_sig;float num_temp;

struct Inertial_navigation_char Inertial_navigation_chars = {};
};

short get_signed_short(unsigned char *data)
{
    short temp = 0;

    temp = (short)((data[1] << 8)  |  data[0]);

    return temp;
}

int get_signed_int(unsigned char *data)
{
    int temp = 0;
    qSwap(data[0],data[3]);
    qSwap(data[1],data[2]);

    temp = (int)((data[3] << 24)  |  (data[2] << 16)  |  (data[1] << 8)  |  data[0]);

    return temp;
}



DataTransfer::DataTransfer()
{

}
