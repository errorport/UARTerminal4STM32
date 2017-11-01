# [UARTerminal for STM32](https://github.com/errorport/UARTerminal4STM32)
___

Description: _Fast printf-like output with STM32 MCUs over UART-STLINK-USB._

___

Author:	_Gergely Bencsik_

Email:	_[becsegergely@gmail.com](mailto:becsegergely@gmail.com)_

Revision: 0.1
___


## Get started!

The project is for beginners who are looking for a fast and easy-to-implement, arduino-like console. It works with only a 4-step configuration.
The first revision is tested with two boards and worked well. (See the supported boards below.)
I will expand the list of these boards, but feel free to write configuration files for them if You want. 


## How to use it?

_I know that this is the first think what you want to get. See the detailed bullsh*t after the example._

__1. - implementation__

Example main.c:

```c

#include "stm32l0xx.h"
#include "stm32l0xx_nucleo.h"
#include "UARTerminal.h"

int main(void)
{
	HAL_Init();
	InitUARTerminal();
	while(1)
	{
		printf("\n\rUARTerminal is ready for duty!\n\r");
	}
}

```

__2. - include your selected board's header file__

You will fild the relevant line in the UARTerminal.h header file.

__3. - setup the baud rate__

You will fild the relevant line in the UARTerminal.h header file.

__4. - set up the connection [UBUNTU]__

I've used the following way on Ubuntu 17.04

```sh
picocom -d 8 -p o -b [your selected baud rate that lies in UARTerminal.h] /dev/ttyACM0
```
OR

```sh
picocom -d 8 -p o -b [your selected baud rate that lies in UARTerminal.h] /dev/stlinkv2_console

```
In the second one the device name under _/dev_ folder depends on the version of your board's STLINK.  
You should check it with:
```sh
ls /dev/st* | grep "_console"
```
__5. - set up the connection [ARCH]__


```sh
picocom /dev/stlinkv2_console -d 8 -b [your selected baud rate that lies in UARTerminal.h] --parity o 1
```
OR
```sh
minicom -b9600 -8 -D /dev/stlinkv2_console
```

The device name under _/dev_ folder depends on the version of your board's STLINK.  
You should check it with:
```sh
ls /dev/st* | grep "_console"
```


## Supported boards

In some cases, there are other representations of __io_putchar(int ch) 
in HAL drivers. If the compiler notices the conflict, You have to 
comment out the conflicting representations.

###L0:
- B-L072Z-LRWAN1
- Nucleo-64 STM32L053
###F7:
- Discovery STM32F769I-DISC1 // __io_putchar(int ch) confrontation!

## In the future

I want to expand the supported boards' list and making a command reciever module under this one.

## Contact

Feel free to write me on the following e-mail address, if You have any question.
[becsegergely@gmail.com](mailto:becsegergely@gmail.com)

