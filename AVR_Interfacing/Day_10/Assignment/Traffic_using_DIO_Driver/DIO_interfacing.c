#include "Bit_Math.h"
#include "Std_Types.h"
#include "avr/io.h"
#include "avr/delay.h"



void DIO_voidSetPinDirection(u8 copy_u8port, u8 copy_u8pin, u8 copy_u8Direction)
{
	if (copy_u8Direction == 1)
	{
		switch(copy_u8port)
		{
		case 0: SET_BIT(DDRA,copy_u8pin);break;
		case 1: SET_BIT(DDRB,copy_u8pin);break;
		case 2: SET_BIT(DDRC,copy_u8pin);break;
		case 3: SET_BIT(DDRD,copy_u8pin);break;
		}
	}
	else if (copy_u8Direction == 0)
	{
		switch(copy_u8port)
		{
		case 0: CLR_BIT(DDRA,copy_u8pin);break;
		case 1: CLR_BIT(DDRB,copy_u8pin);break;
		case 2: CLR_BIT(DDRC,copy_u8pin);break;
		case 3: CLR_BIT(DDRD,copy_u8pin);break;
		}
	}
}

void DIO_voidSetPinValue(u8 copy_u8port, u8 copy_u8pin, u8 copy_u8Value)
{
	if (copy_u8Value == 1)
		{
			switch(copy_u8port)
			{
			case 0: SET_BIT(PORTA,copy_u8pin);break;
			case 1: SET_BIT(PORTB,copy_u8pin);break;
			case 2: SET_BIT(PORTC,copy_u8pin);break;
			case 3: SET_BIT(PORTD,copy_u8pin);break;
			}
		}
		else if (copy_u8Value == 0)
		{
			switch(copy_u8port)
			{
			case 0: CLR_BIT(PORTA,copy_u8pin);break;
			case 1: CLR_BIT(PORTB,copy_u8pin);break;
			case 2: CLR_BIT(PORTC,copy_u8pin);break;
			case 3: CLR_BIT(PORTD,copy_u8pin);break;
			}
		}

}

u8 DIO_u8GetPinValue(u8 copy_u8port, u8 copy_u8pin)
{
	u8 value;
	switch(copy_u8port)
		{
		case 0:
			value= GET_BIT(PINA,copy_u8pin);
			break;
		case 1:
			value= GET_BIT(PINB,copy_u8pin);
			break;
		case 2:
			value= GET_BIT(PINC,copy_u8pin);
			break;
		case 3:
			value= GET_BIT(PIND,copy_u8pin);
			break;
		}
	return value;
}

void DIO_voidSetPortDirection(u8 copy_u8port, u8 copy_u8Direction)
{
	if (copy_u8Direction == 1)
		{
			switch (copy_u8port){
				case 0 :
					DDRA = 0xff;
					break;
				case 1 :
					DDRB = 0xff;
					break;
				case 2 :
					DDRC = 0xff;
					break;
				case 3 :
					DDRD = 0xff;
					break;
			}
		}
		else if (copy_u8Direction == 0)
				{
					switch (copy_u8port){
						case 0 :
							DDRA = 0;
							break;
						case 1 :
							DDRB = 0;
							break;
						case 2 :
							DDRC = 0;
							break;
						case 3 :
							DDRD = 0;
							break;
					}
				}
		}

void DIO_voidSetPortValue(u8 copy_u8port, u8 copy_u8Value)
{
	switch (copy_u8port){
			case 0 :
				PORTA = copy_u8Value;
				break;
			case 1 :
				PORTB = copy_u8Value;
				break;
			case 2 :
				PORTC = copy_u8Value;
				break;
			case 3 :
				PORTD = copy_u8Value;
				break;
		}
}
void DIO_voidTogglePinValue(u8 copy_u8port,u8 copy_u8pin)
{
switch(copy_u8port)
		{
		case 0:
			TOG_BIT(PORTA,copy_u8pin);
			break;
		case 1:
			TOG_BIT(PORTB,copy_u8pin);
			break;
		case 2:
			TOG_BIT(PORTC,copy_u8pin);
			break;
		case 3:
			TOG_BIT(PORTD,copy_u8pin);
			break;
		}
}
