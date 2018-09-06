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
  int vol = ReadVoltage(1);
	if(vol!=-1)
  {
		//���ɹ�
    delay(10);
	}
	else
	{
		//��ʧ��
		delay(2000);
	}
}
