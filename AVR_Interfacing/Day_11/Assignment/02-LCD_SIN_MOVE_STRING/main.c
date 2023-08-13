/*
 * main.c
 *
 *  Created on: 14 Aug 2023
 *      Author: Rashad
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "util\delay.h"
/* MCAL */
#include "DIO_Interface.h"
/* HAL */
#include "LCD_interface.h"



int main ()
{

	LCD_voidInit();
	u8 state=0;

	while(1)
		{
			for (u8 i = 0 ; i < 12 ; i+=2)
			{
				if (state == 0)
				{
					LCD_voidSetLocation(1 , i);
					LCD_voidSendString("RASHAD");
					_delay_ms(100);
					LCD_voidSetLocation(1 , i);
					LCD_voidSendString("      ");
					state = 1 ;
				}
				else if (state == 1)
				{
					LCD_voidSetLocation(2 , i);
					LCD_voidSendString("RASHAD");
					_delay_ms(100);
					LCD_voidSetLocation(2 , i);
					LCD_voidSendString("      ");
					state = 0 ;
				}

			}
		}

return 0;
}
