#ifndef MESSAGE_MANAGER_H
#define MESSAGE_MANAGER_H

#include "stdint.h"
#include "trd_diff_controller/message.h"

class MessageManager{
public:
    MessageManager();
    int connect(const char *serial_port_name, const int baudrate);
    int disconnect();
    // get
    int getEncoderIMU();
    // set
    void setSpeed(char speed_left, char speed_right);
    void setMode();
    void setTimeout();
    void resetEncoder();
    void resetBase();
    int32_t encoder_left, encoder_right;
    double imu_linear_accel_x, imu_linear_accel_y, imu_linear_accel_z; 
    double imu_angular_vel_x, imu_angular_vel_y, imu_angular_vel_z;
    double imu_orientation_x, imu_orientation_y, imu_orientation_z;
private:
    void *serial_handler;
    bool connect_flag;
    // send get msg
    SendMessageGetEncoder msg_get_encoder;
    SendMessageGetIMU msg_get_imu;
    SendMessageGetEncoderIMU msg_get_encoder_imu;
    // send set msg
    SendMessageSetSpeedLeft msg_set_speed_left;
    SendMessageSetSpeedRight msg_set_speed_right;
    SendMessageSetTimeout msg_set_timeout;
    SendMessageResetEncoder msg_reset_encoder;
    SendMessageResetBase msg_reset_base;
    // rx msg
    RxMessage rx_message;
};

#endif
