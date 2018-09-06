#include "stm32f10x.h"
#include "SCServo.h"
#include "uart.h"
#include "wiring.h"

void setup(void)
{
  Uart_Init(1000000);
	delay(500);
}

void loop(void)
{
	RegWritePos(1, 1023, 2000, 0);
	RegWritePos(2, 1023, 2000, 0);
	RegWriteAction();
	delay(2020);
  
	RegWritePos(1, 0, 3000, 0);
	RegWritePos(2, 0, 3000, 0);
	RegWriteAction();
	delay(3020);
}
