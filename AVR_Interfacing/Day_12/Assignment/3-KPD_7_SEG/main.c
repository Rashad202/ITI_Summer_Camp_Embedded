
/*
 * main.c
 *
 *  Created on: 15 Aug 2023
 *      Author: Rashad
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "stdio.h"
#include "util/delay.h"

#include "DIO_Interface.h"
#include "KPD_Interface.h"


u8 Arr_DecToSeg[10] = {0b00111111,   /* 0 */
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
int main(void)
{
	u8 local ;
	KPD_voidInit();

DIO_voidSetPortDirection(DIO_PORTD,0xff);

	while (1)
	{
		local =KPD_u8GetKeyValue();
		if (local != KPD_KEY_NOT_PRESSED)
		{
			local =local-48;
			DIO_voidSetPortValue(DIO_PORTD, Arr_DecToSeg[local]);


		}


	}



return 0;
}
