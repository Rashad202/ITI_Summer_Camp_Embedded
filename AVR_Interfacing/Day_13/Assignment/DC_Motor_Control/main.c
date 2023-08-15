/*
 * main.c
 *
 *  Created on: 15 Aug 2023
 *      Author: Rashad
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

/* MCAL */
#include "DIO_Interface.h"

/* HAL */
#include "LCD_Interface.h"
#include "DCMOTOR_Interface.h"


int main()
{

	LCD_voidInit();
	DCMOTOR_voidInit();
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN2,DIO_INPUT);
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN3,DIO_INPUT);
	u8 RIGHT_BUTTUN ;
	u8 LEFT_BUTTUN ;
	while(1)
	{
		RIGHT_BUTTUN =DIO_u8GetPinValue(DIO_PORTD,DIO_PIN2);
		LEFT_BUTTUN  =DIO_u8GetPinValue(DIO_PORTD,DIO_PIN3);

		if(RIGHT_BUTTUN == 0 &&  LEFT_BUTTUN ==0)
		{
			LCD_voidSendCommand(LCD_CLEAR);
			LCD_voidSendString("Wrong");

			DCMOTOR_voidStop();
			_delay_ms(20);
		}
		else if (LEFT_BUTTUN ==0 )
		{
			LCD_voidSendCommand(LCD_CLEAR);
			LCD_voidSendString("Left ");
			DCMOTOR_voidRotateCCW();
			_delay_ms(20);
		}
		else if (RIGHT_BUTTUN == 0)
		{
			LCD_voidSendCommand(LCD_CLEAR);
			LCD_voidSendString("Right ");
			DCMOTOR_voidRotateCW();
			_delay_ms(20);
		}



	}
return 0;
}
