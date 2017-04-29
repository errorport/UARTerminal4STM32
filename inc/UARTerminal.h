/**
  ******************************************************************************
  * @file    UARTerminal.h
  * @author  Gergely Bencsik
  * @version V0.1
  * @date    26-April-2017
  * @brief   Header for UARTerminal.c module
  ******************************************************************************
*/

#ifndef __UARTERMINAL_H
#define __UARTERMINAL_H
#include "stdio.h"

/*  This program based on STM32 HAL drivers.
    There's no need board specific BSP for it.
*/

/*  Includes :
    In case of You are using boards other than STM32L0xx,
    than uncomment the needed include.
*/
#include "l072czy.h"

/*  MCU specific values
    You have to check these values by the documentation of
    your board. See the README.md!

    The following values are based on STM32L0xx MCUs'.
*/

#define UART_BAUDRATE                    9600;

/* printf to uart*/
#ifdef __GNUC__
/* With GCC, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */


/*  Functions
*/
HAL_StatusTypeDef InitUARTerminal(void);
void InitGPIO(void);
HAL_StatusTypeDef printu(char *);
void setUARTerminal(UART_HandleTypeDef *);

extern UART_HandleTypeDef uartHandle;


#endif /* __UARTERMINAL_H */
