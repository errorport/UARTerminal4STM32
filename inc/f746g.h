/**
  ******************************************************************************
  * @file    UARTerminal.c
  * @author  Gergely Bencsik
  * @version V0.1
  * @date    26-April-2017
  * @brief   header for STM32L053R8
  ******************************************************************************
*/

#ifndef __F746G_H
#define __F746G_H


/*  Basic UART configuration for
    STM32F746G-DISCOVERY board

    */

#include "stm32f7xx_hal.h"
#include "stm32f7xx.h"

    #define UART_INSTANCE                    USART2;
    #define UART_CLK()                       __HAL_RCC_USART1_CLK_ENABLE()
    #define SET_UART_TX_PIN_CLK()            __HAL_RCC_GPIOA_CLK_ENABLE()
    #define SET_UART_RX_PIN_CLK()            __HAL_RCC_GPIOA_CLK_ENABLE()
    #define UART_FORCE_RESET()               __HAL_RCC_USART1_FORCE_RESET()
    #define UART_RELEASE_RESET()             __HAL_RCC_USART1_RELEASE_RESET()
    #define UART_TX_PIN                      GPIO_PIN_2
    #define UART_TX_GPIO_PORT                GPIOA
    #define UART_TX_AF                       GPIO_AF7_USART1
    #define UART_RX_PIN                      GPIO_PIN_3
    #define UART_RX_GPIO_PORT                GPIOA
    #define UART_RX_AF                       GPIO_AF7_USART1


#endif 
