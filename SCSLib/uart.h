#ifndef		_UART_H
#define		_UART_H

#include <stdint.h>
extern void Uart_Init(uint32_t baudRate);
extern void Uart_Flush(void);
extern short Uart_Read(void);
extern void Uart_DmaSend(uint8_t *buf , uint8_t len);

#endif
