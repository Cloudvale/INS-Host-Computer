#ifndef DATATRANSFER_H
#define DATATRANSFER_H


#include <QtGlobal>
#include "mainwindow.h"

//#define  NORMAL_TARANS 0
#define  BYTE_TARANS 1

/*length for specific data id*/
#define HEADER_BYTES_LEN			    (unsigned char)5
#define LHL_LEN					        (unsigned char)5+12
#define ENU_LEN					        (unsigned char)5+12+12
#define AC_X_Y_Z_LEN	      			(unsigned char)5+12+12+12
#define AC_AG_X_Y_Z_LEN		        	(unsigned char)5+12+12+12+12
#define UTC_LEN					        (unsigned char)5+12+12+12+12+28
#define COMBINE_STATE	     			(unsigned char)5+12+12+12+12+28+1

#define LHL_DOUBLE_LEN		            (unsigned int)5+12+12+12+12+28+1+24
#define ENU_DOUBLE_LEN		            (unsigned int)5+12+12+12+12+28+1+24+24
#define MAGNORM_LEN                    	(unsigned int)5+12+12+12+12+28+1+24+24+24
#define PHVTG_LEN				        (unsigned int)5+12+12+12+12+28+1+24+24+24+20
//#define HRES_LOCATION_DATA_LEN			(unsigned int)20
//#define SPEED_DATA_LEN          		(unsigned int)12
//#define NAV_STATUS_DATA_LEN				(unsigned int)1

//#include "mainwindow.h"

namespace test {
//class MainWindow;
extern int UTC_flag;extern int IMU_flag;extern int GNSS_DBT_flag;extern int GNSS_LHL_flag;extern int TEMP_flag;extern int FACOTR_flag;
extern float num_PDOP;extern float num_HDOP;extern float num_VDOP;extern float num_TDOP;extern float num_GDOP;
extern float num_Lon;extern float num_Lat;extern float num_Height;extern float num_EastVel;extern float num_NorthVel;extern float num_UpVel;extern float num_heading;
extern float num_ac_x;extern float num_ac_y;extern float num_ac_z;
extern float num_angle_rate_x;extern float num_angle_rate_y;extern float num_angle_rate_z;extern float num_sig;extern float num_temp;
extern short get_signed_short(unsigned char *data);
extern int get_signed_int(unsigned char *data);

extern struct Inertial_navigation_char Inertial_navigation_chars;

};


class DataTransfer
{
public:
    DataTransfer();
};

#endif // DATATRANSFER_H
