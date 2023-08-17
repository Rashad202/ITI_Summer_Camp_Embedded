/*
 * main.c
 *
 *  Created on: 17 Aug 2023
 *      Author: Rashad
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/interrupt.h>
#include "util/delay.h"
#include "DIO_Interface.h"
#include "EXTI_Interface.h"

void Change_Mode(void);
void main()
{
	// intialize INT0
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN2,DIO_INPUT);
	DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,DIO_HIGH);

	DIO_voidSetPortDirection(DIO_PORTC,0xff);

	//LEDS
	EXTI_voidGIE();
	EXTI_voidInit();
	EXTI_voidEXTISetCallBack(0,&Change_Mode);
	while(1)
	{
		for(s8 Local_counter=0 ; Local_counter<8;Local_counter++)
		{
			DIO_voidSetPinValue(DIO_PORTC,Local_counter,DIO_HIGH);
			_delay_ms(500);
			DIO_voidSetPinValue(DIO_PORTC,Local_counter,DIO_LOW);
		}
	}


}

void Change_Mode(void)
{
	DIO_voidSetPortValue(DIO_PORTC,0x00);
	for(s8 Local_counter=7 ; Local_counter>=0 ;--Local_counter)
			{
				DIO_voidSetPinValue(DIO_PORTC,Local_counter,DIO_HIGH);
				_delay_ms(500);
				DIO_voidSetPinValue(DIO_PORTC,Local_counter,DIO_LOW);
			}

}
