#include "stm32f10x.h"
#include "SCServo.h"
#include "uart.h"
#include "wiring.h"

void setup()
{
  Uart_Init(1000000);
  writeByte(0xfe, SCSCL_LOCK, 0);//打开EPROM保存功能
  writeByte(0xfe, SCSCL_ID, 1);//ID
  delay(50);
  writeWord(0xfe, SCSCL_MIN_ANGLE_LIMIT_L, 0);
  delay(50);
  writeWord(0xfe, SCSCL_MAX_ANGLE_LIMIT_L, 1023);
  delay(50);
  writeByte(0xfe, SCSCL_RETURN_DELAY_TIME, 0);//返回延时0us
  delay(50);
  writeByte(0xfe, SCSCL_BAUD_RATE, SCSCL_1M);//BaundRate=1Mbit/s
  delay(50);
  writeByte(0xfe, SCSCL_LOCK, 1);//关闭EPROM保存功能�
}

void loop()
{

}
