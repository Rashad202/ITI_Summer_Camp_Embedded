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
#include "DIO_interfacing.h"


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

DIO_voidSetPortDirection(2,1);
DIO_voidSetPortDirection(3,1);

DIO_voidSetPinDirection(0,0,1);
DIO_voidSetPinDirection(0,1,1);
DIO_voidSetPinDirection(0,2,1);


while(1)
{
	 // Green Led

	 DIO_voidSetPinValue(0,2,1);
	 for(s8 j=10;j>=0;--j)
	 		{
	 			u8 tens =j%10;
	 			u8 ones =j/10;
	 			DIO_voidSetPortValue(3,Arr[tens]);
	 			DIO_voidSetPortValue(2,Arr[ones]);
	 			_delay_ms(1000);
	 		}
	 DIO_voidSetPinValue(0,2,0);
	 DIO_voidSetPortValue(3,0x00);
	 DIO_voidSetPortValue(2,0x00);



	 //Yelow LED
	 	 DIO_voidSetPinValue(0,1,1);
		 for(s8 j=3;j>=0;--j)
				{
					u8 tens =j%10;
					u8 ones =j/10;
					DIO_voidSetPortValue(3,Arr[tens]);
					DIO_voidSetPortValue(2,Arr[ones]);
					_delay_ms(1000);
				}
		 DIO_voidSetPinValue(0,1,0);
		 DIO_voidSetPortValue(3,0x00);
		 DIO_voidSetPortValue(2,0x00);

		 //Red LED
		 DIO_voidSetPinValue(0,0,1);
			 for(s8 j=10;j>=0;--j)
					{
						u8 tens =j%10;
						u8 ones =j/10;
						DIO_voidSetPortValue(3,Arr[tens]);
						DIO_voidSetPortValue(2,Arr[ones]);
						_delay_ms(1000);
					}
			 DIO_voidSetPinValue(0,0,0);
			 DIO_voidSetPortValue(3,0x00);
			 DIO_voidSetPortValue(2,0x00);

}
return 0;
}
