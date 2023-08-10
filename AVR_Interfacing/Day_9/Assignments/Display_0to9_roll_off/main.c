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
void main ()
{
	DDRA=0xff;


	while(1)
	{
		// display from 0 t 9
		for(u8 counter=0;counter<10;counter++)
		{
			PORTA=Arr[counter];
			_delay_ms(500);
		}
		PORTA=0x00;
		_delay_ms(800);


		// display from 9 t 0

		for(s8 counter=9;counter>=0;counter--)
		{
			PORTA=Arr[counter];
			_delay_ms(500);
		}
		_delay_ms(800);
	}
}
