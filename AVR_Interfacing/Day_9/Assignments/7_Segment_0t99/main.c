/*
 * main.c
 *
 *  Created on: 10 Aug 2023
 *      Author: Rashad
 */
#include <avr/io.h>
#include "util/delay.h"
#include "Bit_Math.h"
#include "Std_Types.h"
u8 Arr[10] = { 0b00111111,   /* 0 */
			   0b00000110,   /* 1 */
			   0b01011011,   /* 2 */
			   0b01001111,   /* 3 */
			   0b01100110,   /* 4 */
			   0b01101101,   /* 5 */
			   0b01111101,   /* 6 */
			   0b00000111,   /* 7 */
			   0b01111111,   /* 8 */
			   0b01101111    /* 9 */
			  };
int main()
{
	DDRC=0xff;
	DDRD=0xff;

	while(1)
	{
	for(s8 j=0;j<10;j++)
		{
			PORTD=Arr[j];
			for(s8 i=0;i<10;i++)
			{
				PORTC=Arr[i];
				_delay_ms(100);
			}
			_delay_ms(10);
			PORTC=0x00;
			PORTD=0x00;

		}
	}




return 0;
}

