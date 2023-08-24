/*
 * main.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Ahmed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "UART.h"
#include "KPD_Interface.h"
int main (void)
{
	u8 data;
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN0,DIO_INPUT);
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN1,DIO_OUTPUT);

	KPD_voidInit();
	UART_voidInit();
	while(1)
	{
		data =KPD_u8GetKeyValue();
		if (data != KPD_KEY_NOT_PRESSED )
		{
			UART_voidSendData(data);
		}
	}


}
