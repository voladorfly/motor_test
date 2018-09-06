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
  int T = ReadTemper(1);
	if(T!=-1)
	{
		//∂¡≥…π¶
    delay(10);
  }
  else
  {
		//∂¡ ß∞‹
    delay(2000);    
  }
}
