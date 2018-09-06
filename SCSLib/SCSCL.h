/*
 * SCSCL.h
 * 飞特SCSCL系列串行舵机应用层程序
 * 日期: 2018.7.3
 * 作者: 谭雄乐
 */

#ifndef _SCSCL_H
#define _SCSCL_H

//波特率定义
#define		SCSCL_1M			0
#define		SCSCL_0_5M		1
#define		SCSCL_250K		2
#define		SCSCL_128K		3
#define		SCSCL_115200	4
#define		SCSCL_76800		5
#define		SCSCL_57600		6
#define		SCSCL_38400		7

//内存表定义
//-------EPROM(只读)--------
#define SCSCL_VERSION_L 0
#define SCSCL_VERSION_H 1
#define SCSCL_MODEL_L 3
#define SCSCL_MODEL_H 4

//-------EPROM(读写)--------
#define SCSCL_ID 5
#define SCSCL_BAUD_RATE 6
#define SCSCL_RETURN_DELAY_TIME 7
#define SCSCL_RETURN_LEVEL 8
#define SCSCL_MIN_ANGLE_LIMIT_L 9
#define SCSCL_MIN_ANGLE_LIMIT_H 10
#define SCSCL_MAX_ANGLE_LIMIT_L 11
#define SCSCL_MAX_ANGLE_LIMIT_H 12
#define SCSCL_LIMIT_TEMPERATURE 13
#define SCSCL_MAX_LIMIT_VOLTAGE 14
#define SCSCL_MIN_LIMIT_VOLTAGE 15
#define SCSCL_MAX_TORQUE_L 16
#define SCSCL_MAX_TORQUE_H 17
#define SCSCL_ALARM_LED 19
#define SCSCL_ALARM_SHUTDOWN 20
#define SCSCL_COMPLIANCE_P 21
#define SCSCL_COMPLIANCE_D 22
#define SCSCL_COMPLIANCE_I 23
#define SCSCL_PUNCH_L 24
#define SCSCL_PUNCH_H 25
#define SCSCL_CW_DEAD 26
#define SCSCL_CCW_DEAD 27
#define SCSCL_PROTECT_TORQUE 37
#define SCSCL_PROTECT_TIME 38
#define SCSCL_OVLOAD_TORQUE 39

//-------SRAM(读写)--------
#define SCSCL_TORQUE_ENABLE 40
#define SCSCL_GOAL_POSITION_L 42
#define SCSCL_GOAL_POSITION_H 43
#define SCSCL_GOAL_TIME_L 44
#define SCSCL_GOAL_TIME_H 45
#define SCSCL_GOAL_SPEED_L 46
#define SCSCL_GOAL_SPEED_H 47
#define SCSCL_LOCK 48

//-------SRAM(只读)--------
#define SCSCL_PRESENT_POSITION_L 56
#define SCSCL_PRESENT_POSITION_H 57
#define SCSCL_PRESENT_SPEED_L 58
#define SCSCL_PRESENT_SPEED_H 59
#define SCSCL_PRESENT_LOAD_L 60
#define SCSCL_PRESENT_LOAD_H 61
#define SCSCL_PRESENT_VOLTAGE 62
#define SCSCL_PRESENT_TEMPERATURE 63
#define SCSCL_MOVING 66



extern int WritePos(uint8_t ID, uint16_t Position, uint16_t Time, uint16_t Speed);//普通写位置指令
extern int RegWritePos(uint8_t ID, uint16_t Position, uint16_t Time, uint16_t Speed);//异步写位置指令
extern void SyncWritePos(uint8_t ID[], uint8_t IDN, uint16_t Position, uint16_t Time, uint16_t Speed);//同步写位置指令	
extern int wheelMode(uint8_t ID);//多圈轮子模式
extern int joinMode(uint8_t ID, uint16_t minAngle, uint16_t maxAngle);//普通伺服模式
extern int ReadPos(uint8_t ID);//读位置
extern int WriteSpe(uint8_t ID, int16_t Speed);//多圈控制指令
extern int EnableTorque(uint8_t ID, uint8_t Enable);//扭力控制指令
extern void RegWriteAction(void);//执行异步写指令
extern int ReadLoad(uint8_t ID);//读当负载
extern int ReadVoltage(uint8_t ID);//读电压
extern int ReadTemper(uint8_t ID);//读温度
extern int Ping(uint8_t ID);//Ping指令



#endif
