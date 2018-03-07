/*
 * uart.h
 *
 *  Created on: 8 Apr 2017
 *      Author: kevin
 */

#ifndef UART_H_
#define UART_H_


void uart_init (UART_MemMapPtr, int, int);
char uart_getchar (UART_MemMapPtr);
void uart_putchar (UART_MemMapPtr, char);
int uart_getchar_present (UART_MemMapPtr);


#endif /* UART_H_ */
