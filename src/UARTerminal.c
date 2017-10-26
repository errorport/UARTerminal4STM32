/**
  ******************************************************************************
  * @file    UARTerminal.c
  * @author  Gergely Bencsik
  * @version V0.1
  * @date    26-April-2017
  * @brief   Source for UARTerminal.c module
  ******************************************************************************
*/

#include "UARTerminal.h"

UART_HandleTypeDef uartHandle;

HAL_StatusTypeDef InitUARTerminal()
{

  /*  Initializing GPIO ports for UART communication.

  */
  InitGPIO();

  uartHandle.Instance           =   UART_INSTANCE;

  uartHandle.Init.WordLength    =   UART_WORDLENGTH_9B;

  uartHandle.Init.BaudRate      =   UART_BAUDRATE;

  uartHandle.Init.StopBits      =   UART_STOPBITS_1;

  uartHandle.Init.Parity        =   UART_PARITY_ODD;

  uartHandle.Init.HwFlowCtl     =   UART_HWCONTROL_NONE;

  uartHandle.Init.Mode          =   UART_MODE_TX_RX;
/*
  uartHandle.Init.OverSampling  = 	 UART_OVERSAMPLING_16;

  uartHandle.Init.OneBitSampling 		  =	UART_ONE_BIT_SAMPLE_DISABLE;

  uartHandle.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;*/


  /*  Drop back the HAL defined status.

  */
  return HAL_UART_Init(&uartHandle);

}

void InitGPIO()
{
  GPIO_InitTypeDef      GPIOinit;
  SET_UART_TX_PIN_CLK();
  SET_UART_RX_PIN_CLK();
  UART_CLK();

  /*  Setting up GPIO ports for UART

  */
  /*  Setting up basic pin values

  */
  GPIOinit.Mode         =     GPIO_MODE_AF_PP;
  GPIOinit.Pull         =     GPIO_PULLUP;
  GPIOinit.Speed        =     GPIO_SPEED_FREQ_VERY_HIGH;

  /*  Setting up TX pin.
      UART transceiver pin.
  */
  GPIOinit.Alternate    =     UART_TX_AF;
  GPIOinit.Pin          =     UART_TX_PIN;
  HAL_GPIO_Init(UART_TX_GPIO_PORT, &GPIOinit);

  /*  Setting up RX pin.
      UART receiver pin.
  */
  GPIOinit.Alternate    =     UART_RX_AF;
  GPIOinit.Pin          =     UART_RX_PIN;
  HAL_GPIO_Init(UART_RX_GPIO_PORT, &GPIOinit);

}

HAL_StatusTypeDef printu(char * ch)
{
    return HAL_UART_Transmit(&uartHandle, (uint8_t *)ch, 1, 0xFFFF);
}


void setUARTerminal(UART_HandleTypeDef * uh)
{
  uartHandle = *uh;
}

PUTCHAR_PROTOTYPE
{
	printu(&ch);
	return ch;
}

