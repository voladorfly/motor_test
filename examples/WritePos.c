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
  WritePos(1, 1023, 4000, 0);
  WritePos(2, 1023, 4000, 0);
  delay(4020); 
  WritePos(1,0x0000, 3000, 0);
  WritePos(2, 0x0000, 3000, 0);
  delay(3020);
}
