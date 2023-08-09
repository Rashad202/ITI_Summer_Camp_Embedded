/*
 * MAIN.C
 *
 *  Created on: 10 Aug 2023
 *      Author: Rashad
 */

#include "avr/io.h"
#include "util/delay.h"

void main (void)
{
	// Direction
	DDRC = 0xff;
	DDRD = 0xff;
	while(1)
	{
		_delay_ms(1000);
		PORTD= 0b01101101;
		PORTC = 0b00111111;

		_delay_ms(3000);
		PORTC=0x00;
		PORTD=0x00;
		_delay_ms(1000);
		PORTD = 0b01100110;
		PORTC = 0b00111111;
		_delay_ms(3000);
		PORTC=0x00;
		PORTD=0x00;
		_delay_ms(2000);
	}

}

