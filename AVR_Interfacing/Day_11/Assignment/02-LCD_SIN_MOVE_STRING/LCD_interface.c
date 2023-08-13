/*
 * LCD_interface.c
 *
 *  Created on: 13 Aug 2023
 *      Author: Rashad
 */
/* LIB LAYER */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "stdio.h"
#include "util\delay.h"
/* MCAL */
#include "DIO_Interface.h"
/* HAL */
#include "LCD_interface.h"

void LCD_voidInit()
{
		/*  SET DATA_PORT AS OUTPUT */
		DIO_voidSetPortDirection(LCD_DATA_PORT , 0xff);
		/*  SET CONTROL PINS AS OUTPUT */
		DIO_voidSetPinDirection(LCD_CONTROL_PORT , RS , DIO_OUTPUT);
		DIO_voidSetPinDirection(LCD_CONTROL_PORT ,RW , DIO_OUTPUT );
		DIO_voidSetPinDirection(LCD_CONTROL_PORT ,EN , DIO_OUTPUT );
		/* WAIT FOR 30ms */
		_delay_ms(30);
		/* Send command function set */
		LCD_voidSendCommand(LCD_FUNC_SET);
		_delay_ms(10);

		/* Send command dispaly on */
		LCD_voidSendCommand(LCD_ONOFF);
		_delay_ms(10);

		/* Clear the display  */
		LCD_voidSendCommand(LCD_CLEAR);
		_delay_ms(10);

}

void LCD_voidSendCommand(u8 Copy_u8Command)
{
		/* Reset RS and RW */
		DIO_voidSetPinValue(LCD_CONTROL_PORT , RS , DIO_LOW);

		DIO_voidSetPinValue(LCD_CONTROL_PORT , RW , DIO_LOW);

		/* Write the command to data port */
		DIO_voidSetPortValue(LCD_DATA_PORT , Copy_u8Command);

		/* Send Enable signal */
		DIO_voidSetPinValue(LCD_CONTROL_PORT , EN , DIO_HIGH);
		_delay_ms(1);
		DIO_voidSetPinValue(LCD_CONTROL_PORT , EN , DIO_LOW);
		_delay_ms(2);

}
void LCD_voidSendChar(u8 Copy_u8Data)
{
	    /* Reset RS and RW */
		DIO_voidSetPinValue(LCD_CONTROL_PORT , RS , DIO_HIGH);

		DIO_voidSetPinValue(LCD_CONTROL_PORT , RW , DIO_LOW);

		/* Write the command to data port */
		DIO_voidSetPortValue(LCD_DATA_PORT , Copy_u8Data);

		/* Send Enable signal */
		DIO_voidSetPinValue(LCD_CONTROL_PORT , EN , DIO_HIGH);
		_delay_ms(1);
		DIO_voidSetPinValue(LCD_CONTROL_PORT , EN , DIO_LOW);
		_delay_ms(2);

}

void LCD_voidSendString(u8 *Copy_u8String)
{
	while ( (*Copy_u8String) != NULL)
		{
			LCD_voidSendChar(*Copy_u8String);
			Copy_u8String++;
			_delay_ms(2);
		}
}

void LCD_voidSetLocation(u8 Copy_u8LineNum,u8 Copy_u8CharNum)
{

		switch(Copy_u8LineNum)
		    {
			    case LCD_LINE1:
			    	LCD_voidSendCommand(Copy_u8CharNum+0x80);
			    	break;
			    case LCD_LINE2:
			    	LCD_voidSendCommand(Copy_u8CharNum+0xc0);
			    	break;
		    }

}
