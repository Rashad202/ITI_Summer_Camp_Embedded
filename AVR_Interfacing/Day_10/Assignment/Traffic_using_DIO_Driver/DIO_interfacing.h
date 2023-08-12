#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H


void DIO_voidSetPinDirection(u8 copy_u8port, u8 copy_u8pin, u8 copy_u8Direction);

void DIO_voidSetPinValue(u8 copy_u8port, u8 copy_u8pin, u8 copy_u8Value);

u8 DIO_u8GetPinValue(u8 copy_u8port, u8 copy_u8pin);

void DIO_voidSetPortDirection(u8 copy_u8port, u8 copy_u8Direction);

void DIO_voidSetPortValue(u8 copy_u8port, u8 copy_u8Value);

void DIO_voidTogglePinValue(u8 copy_u8port,u8 copy_u8Pin);


#endif