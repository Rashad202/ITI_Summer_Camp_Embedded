/*
 * main.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Rashad
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/delay.h>
#include "DIO_Interface.h"
#include "Timer0_Interface.h"

void TOG(void);

int main(void){
	DIO_voidSetPinDirection(DIO_PORTC,DIO_PIN0,DIO_OUTPUT);
	GIE_voidEnable();
	TIMER2_voidTimer2OVFInit(1);
	TIMER2_voidTimer2OVFSetCallBack(TOG);
	while(1);
	return 0;
}
void TOG(void){
	DIO_voidSetPinValue(DIO_PORTC,DIO_PIN0,DIO_HIGH);
	_delay_ms(500);
	DIO_voidSetPinValue(DIO_PORTC,DIO_PIN0,DIO_LOW);
	_delay_ms(500);
}
