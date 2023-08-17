/*
 * main.c
 *
 *  Created on: 17 Aug 2023
 *      Author: Rashad
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include "DIO_Interface.h"
#include "EXTI_Interface.h"

int main()
{
 // INT0
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN2,DIO_INPUT);
	DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,DIO_HIGH);
	// INT1
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN3,DIO_INPUT);
	DIO_voidSetPinValue(DIO_PORTD,DIO_PIN3,DIO_HIGH);
	//LEDS
	DIO_voidSetPinDirection(DIO_PORTC,DIO_PIN0,DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTC,DIO_PIN1,DIO_OUTPUT);
	//GIE
	EXTI_voidGIE();
	EXTI_voidInit();
	while(1);
return 0;
}
ISR(INT0_vect)
{
	DIO_voidTogglePinValue(DIO_PORTC,DIO_PIN0);
}

/* ISR  for External interrupt 1 */
ISR(INT1_vect)
{
	DIO_voidTogglePinValue(DIO_PORTC,DIO_PIN1);

}
