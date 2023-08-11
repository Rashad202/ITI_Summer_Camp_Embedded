/*
 * main.c
 *
 *  Created on: 11 Aug 2023
 *      Author: Rashad
 */
#include <avr/io.h>
#include <util/delay.h>
#include "Std_Types.h"
#include "Bit_Math.h"

int main()
{
    DDRA = 0xff;
    DDRB = 0x00;
    PORTB = 0x00000111;

    while (1)
    {

        //Flashing every 500 ms

        if (GET_BIT(PINB, 0) == 0 && GET_BIT(PINB, 1) == 0 && GET_BIT(PINB, 2) == 0)
        {
            PORTA = 0xff;
            _delay_ms(500);
            PORTA = 0x00;
            _delay_ms(500);
        }

        // Shifting Left every 250 ms

         if (GET_BIT(PINB, 0) == 0 && GET_BIT(PINB, 1) == 0 && GET_BIT(PINB, 2) == 1)
        {
            for (s8 i = 7; i >= 0; i--)
            {
                SET_BIT(PORTA, i);
                _delay_ms(250);
                CLR_BIT(PORTA, i);
            }
        }

        // Shifting Right every 250 ms

        if (GET_BIT(PINB, 0) == 0 && GET_BIT(PINB, 1) == 1 && GET_BIT(PINB, 2) == 0)
        {
            for (s8 i = 0; i <= 7; i++)
            {
                SET_BIT(PORTA, i);
                _delay_ms(250);
                CLR_BIT(PORTA, i);
            }
        }

        // LEDs Converging every 300 ms

         if (GET_BIT(PINB, 0) == 0 && GET_BIT(PINB, 1) == 1 && GET_BIT(PINB, 2) == 1)
        {
            for (u8 i = 0; i <= 3; i++)
            {
                SET_BIT(PORTA, i);
                SET_BIT(PORTA, 7 - i);
                _delay_ms(300);
                CLR_BIT(PORTA, i);
                CLR_BIT(PORTA, 7 - i);
            }
        }

        // LEDs Diverging every 300 ms

         if (GET_BIT(PINB, 0) == 1 && GET_BIT(PINB, 1) == 0 && GET_BIT(PINB, 2) == 0)
        {
            for (s8 i = 3; i >= 0; i--)
            {
                SET_BIT(PORTA, i);
                SET_BIT(PORTA, 7 - i);
                _delay_ms(300);
                CLR_BIT(PORTA, i);
                CLR_BIT(PORTA, 7 - i);
            }
        }

        // Ping Pong effect every 250 ms

        if (GET_BIT(PINB, 0) == 1 && GET_BIT(PINB, 1) == 0 && GET_BIT(PINB, 2) == 1)
        {
            for (u8 i = 0; i <= 3; i++)
            {
                SET_BIT(PORTA, i);
                SET_BIT(PORTA, 7 - i);
                _delay_ms(250);
            }

            for (s8 i = 3; i >= 0; i--)
            {
                CLR_BIT(PORTA, i);
                CLR_BIT(PORTA, 7 - i);
                _delay_ms(250);
            }
        }

        // Incrementing (Snake effect) every 300 ms

         if (GET_BIT(PINB, 0) == 1 && GET_BIT(PINB, 1) == 1 && GET_BIT(PINB, 2) == 0)
        {
            for (u8 i = 0; i <= 7; i++)
            {
                SET_BIT(PORTA, i);
                _delay_ms(300);
            }
            PORTA = 0x00;
            _delay_ms(300);
        }

       // 2-LEDs Converging/Diverging every 300 ms

        if (GET_BIT(PINB, 0) == 1 && GET_BIT(PINB, 1) == 1 && GET_BIT(PINB, 2) == 1)
        {
            for (u8 i = 0; i <= 3; i++)
            {
                SET_BIT(PORTA, i);
                SET_BIT(PORTA, 7 - i);
                _delay_ms(300);
                CLR_BIT(PORTA, i);
                CLR_BIT(PORTA, 7 - i);
            }

            for (s8 i = 2; i >= 1; i--)
            {
                SET_BIT(PORTA, i);
                SET_BIT(PORTA, 7 - i);
                _delay_ms(300);
                CLR_BIT(PORTA, i);
                CLR_BIT(PORTA, 7 - i);
            }
        }
    }
return 0;
}
