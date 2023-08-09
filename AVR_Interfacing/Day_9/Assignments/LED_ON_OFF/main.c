/*
 * MAIN.C
 *
 *  Created on: 10 Aug 2023
 *      Author: Rashad
 */

#include "avr/io.h"
#include "avr/delay.h"

void main (void)
{
	// Direction
	DDRA = 0xff;

	while(1)
	{
		_delay_ms(1000);
		PORTA = 0b00000001;

		_delay_ms(1000);
		PORTA = 0b00000000;
	}

}

