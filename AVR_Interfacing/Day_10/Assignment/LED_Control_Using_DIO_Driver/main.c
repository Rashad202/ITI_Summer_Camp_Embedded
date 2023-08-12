/*
 * main.c
 *
 *  Created on: 11 Aug 2023
 *      Author: Rashad
 */
#include "avr/io.h"
#include <util/delay.h>
#include "Std_Types.h"
#include "Bit_Math.h"
#include "DIO_interfacing.h"

int main()
{

	DIO_voidSetPortDirection(0,1);
	DIO_voidSetPortDirection(1,0);

	DIO_voidSetPortValue(1,0x07);


    while (1)
    {

        //Flashing every 500 ms
        if (DIO_u8GetPinValue(1,0) == 0 && DIO_u8GetPinValue(1,1) == 0 && DIO_u8GetPinValue(1,2) == 0)
        {

        	DIO_voidSetPortValue(0,0xff);
            _delay_ms(500);
            DIO_voidSetPortValue(0,0x00);
            _delay_ms(500);
        }

        // Shifting Left every 250 ms

         if (DIO_u8GetPinValue(1,0) == 0 &&DIO_u8GetPinValue(1,1) == 0 && DIO_u8GetPinValue(1,2) == 1)
        {
            for (s8 i = 7; i >= 0; i--)
            {
                DIO_voidSetPinValue(0,i,1);
                _delay_ms(250);
                DIO_voidSetPinValue(0,i,0);
            }
        }

        // Shifting Right every 250 ms

        if (DIO_u8GetPinValue(1,0) == 0 && DIO_u8GetPinValue(1,1) == 1 && DIO_u8GetPinValue(1,2) == 0)
        {
            for (s8 i = 0; i <= 7; i++)
            {
            	DIO_voidSetPinValue(0,i,1);
				_delay_ms(250);
				DIO_voidSetPinValue(0,i,0);
            }
        }

        // LEDs Converging every 300 ms

         if (DIO_u8GetPinValue(1,0) == 0 && DIO_u8GetPinValue(1,1)== 1 && DIO_u8GetPinValue(1,2)== 1)
        {
            for (u8 i = 0; i <= 3; i++)
            {
            	DIO_voidSetPinValue(0,i,1);
				DIO_voidSetPinValue(0,7-i,1);
                _delay_ms(300);
                DIO_voidSetPinValue(0,i,0);
                DIO_voidSetPinValue(0,7-i,0);
            }
        }

        // LEDs Diverging every 300 ms

         if (DIO_u8GetPinValue(1,0) == 1 && DIO_u8GetPinValue(1,1) == 0 && DIO_u8GetPinValue(1,2)== 0)
        {
            for (s8 i = 3; i >= 0; i--)
            {
            	DIO_voidSetPinValue(0,i,1);
				DIO_voidSetPinValue(0,7-i,1);
				_delay_ms(300);
				DIO_voidSetPinValue(0,i,0);
				DIO_voidSetPinValue(0,7-i,0);
            }
        }

        // Ping Pong effect every 250 ms

        if (DIO_u8GetPinValue(1,0) == 1 && DIO_u8GetPinValue(1,1) == 0 && DIO_u8GetPinValue(1,2) == 1)
        {
            for (u8 i = 0; i <= 3; i++)
            {
				DIO_voidSetPinValue(0,i,1);
				DIO_voidSetPinValue(0,7-i,1);
                _delay_ms(250);
            }

            for (s8 i = 3; i >= 0; i--)
            {
            	DIO_voidSetPinValue(0,i,0);
            	DIO_voidSetPinValue(0,7-i,0);
                _delay_ms(250);
            }
        }

        // Incrementing (Snake effect) every 300 ms

         if (DIO_u8GetPinValue(1,0)== 1 &&DIO_u8GetPinValue(1,1)  == 1 && DIO_u8GetPinValue(1,2) == 0)
        {
            for (u8 i = 0; i <= 7; i++)
            {
				DIO_voidSetPinValue(0,i,1);
                _delay_ms(300);
            }
            DIO_voidSetPortValue(0,0x00);
            _delay_ms(300);
        }

       // 2-LEDs Converging/Diverging every 300 ms

        if (DIO_u8GetPinValue(1,0) == 1 && DIO_u8GetPinValue(1,1) == 1 && DIO_u8GetPinValue(1,2) == 1)
        {
            for (u8 i = 0; i <= 3; i++)
            {
            	DIO_voidSetPinValue(0,i,1);
				DIO_voidSetPinValue(0,7-i,1);
				_delay_ms(300);
				DIO_voidSetPinValue(0,i,0);
				DIO_voidSetPinValue(0,7-i,0);
            }

            for (s8 i = 2; i >= 1; i--)
            {
            	DIO_voidSetPinValue(0,i,1);
				DIO_voidSetPinValue(0,7-i,1);
				_delay_ms(300);
				DIO_voidSetPinValue(0,i,0);
				DIO_voidSetPinValue(0,7-i,0);

            }
        }
    }
return 0;
}
