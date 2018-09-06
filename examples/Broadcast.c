#include "stm32f10x.h"
#include "SCServo.h"
#include "uart.h"
#include "wiring.h"

void setup(void)
{
 	Uart_Init(1000000);
  delay(500);
  WritePos(0xfe, 0, 1000, 0);
	delay(1020);	
}

void loop(void)
{
	int i;
  for(i = 0; i<1024; i++)
  {
    WritePos(0xfe,i,20,0);//All Servo(broadcast) rotate to the position:i
    delay(20);
  }
  for(i = 1023; i > 0; i--)
  {
    WritePos(0xfe,i,10,0);//All Servo(broadcast) rotate to the position:i
    delay(10);
  }
}
