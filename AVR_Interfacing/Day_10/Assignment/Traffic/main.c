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

	SET_BIT(DDRA,0);
	SET_BIT(DDRA,1);
	SET_BIT(DDRA,2);

	while(1)
	{
// Green Led
	SET_BIT(PORTA,2);
	for(s8 j=10;j>=0;--j)
		{
			u8 tens =j%10;
			u8 ones =j/10;
			PORTD=Arr[tens];
			PORTC=Arr[ones];
			_delay_ms(1000);
		}
	CLR_BIT(PORTA,2);
	PORTD=0x00;
	PORTC=0x00;
//Yelow
	SET_BIT(PORTA,1);
	for(s8 j=3;j>=0;--j)
		{
			u8 tens =j%10;
			u8 ones =j/10;
			PORTD=Arr[tens];
			PORTC=Arr[ones];
			_delay_ms(1000);
		}
	CLR_BIT(PORTA,1);
	PORTD=0x00;
	PORTC=0x00;
//Red
		SET_BIT(PORTA,0);
		for(s8 j=10;j>=0;--j)
			{
				u8 tens =j%10;
				u8 ones =j/10;
				PORTD=Arr[tens];
				PORTC=Arr[ones];
				_delay_ms(1000);
			}

	CLR_BIT(PORTA,0);
	PORTD=0x00;
	PORTC=0x00;











	}




return 0;
}

