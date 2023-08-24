/*
 * main.c
 *
 *  Created on: Aug 21, 2023
 *      Author: Adham
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/delay.h>
#include "DIO_Interface.h"
#include "KPD_Interface.h"
#include "LCD_Interface.h"
#include "SERVOMOTOR_Interface.h"


int main(void){
	u8 Local_u8Key = KPD_KEY_NOT_PRESSED;
	u16 Copy_u8Angle = 0;
	u8 Copy_U8String[]= {"Error"};

	KPD_voidInit();
	LCD_voidInit();

	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN5,DIO_OUTPUT);

	while(1){

		for(u8 local_u8counter = 0; local_u8counter < 3; local_u8counter++){
			while(1)
			{
				Local_u8Key = KPD_u8GetKeyValue();

				if(Local_u8Key != KPD_KEY_NOT_PRESSED)
				{
					if(local_u8counter == 0)
						{
							Copy_u8Angle = ((Local_u8Key-48) * 100);
							LCD_voidSendChar((Local_u8Key));
						}
					else if(local_u8counter == 1)
						{
							Copy_u8Angle = Copy_u8Angle + ((Local_u8Key-48) * 10);
							LCD_voidSendChar((Local_u8Key));
						}
					else if(local_u8counter == 2)
						{
							Copy_u8Angle = Copy_u8Angle + ((Local_u8Key-48) * 1);
							LCD_voidSendChar((Local_u8Key));
						}

					break;
				}
			}
		}

		if(Copy_u8Angle>180)
			{
				LCD_voidSendCommand(LCD_CLEAR);
				LCD_voidSendString(Copy_U8String);
			}
		else if ((Copy_u8Angle>0)&&(Copy_u8Angle<=180))
			{
				TIMER1_voidFPWM();
				SERVO_voidSetAngle(Copy_u8Angle);
			}

		Local_u8Key = KPD_u8GetKeyValue();
		_delay_ms(500);
		LCD_voidSendCommand(LCD_CLEAR);

	}
	return 0;
}
