#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <math.h>
#include "DIO_Interface.h"
#include "Timer0_Interface.h"

static void (*TIMER_PFTimer0OVF) (void) ;
static void (*TIMER_PFTimer0CTC) (void) ;
static void (*TIMER_PFTimer2OVF) (void) ;
static void (*TIMER_PFTimer2CTC) (void) ;
u16 COPY_u16LapsT0;
u8 COPY_u8IntialTicksT0;
u16 COPY_u16LapsT2;
u8 COPY_u8IntialTicksT2;
void TIMER0_voidTimer0OVFInit(f32 COPY_f32TimeInSec)
{
	/* Choose Normal mode */
	CLR_BIT(TCCR0 , WGM00);
	CLR_BIT(TCCR0 , WGM01);

	/* Enable Timer/Counter0 Overflow */
	SET_BIT(TIMSK , TOIE0);

	/* Determine no. of LAPS */
	f32 COPY_u16LapsT0WithDec = COPY_f32TimeInSec * 1000000 / 256;
	COPY_u16LapsT0 = ceil(COPY_u16LapsT0WithDec);

	/* Initial Preload value with Desired Time */
	u16 COPY_u16INTPART = (int)COPY_u16LapsT0WithDec;

	COPY_u8IntialTicksT0 = (256 - (u8)(COPY_u16LapsT0WithDec - COPY_u16INTPART) * 256);
	TCNT0 = COPY_u8IntialTicksT0;

	/* Select clock " CLK \ 8" ==> Prescaler */
	CLR_BIT(TCCR0 , CS00);
	SET_BIT(TCCR0 , CS01);
	CLR_BIT(TCCR0 , CS02);

}

void TIMER0_voidTimer0CTCInit(f32 COPY_f32TimeInSec)
{
	/* Choose CTC mode */
	CLR_BIT(TCCR0 , WGM00);
	SET_BIT(TCCR0 , WGM01);

	/* Enable Timer/Counter0 CTC AND OVF */
	SET_BIT(TIMSK , OCIE0);

	/* Determine no. of LAPS */
	COPY_u16LapsT0 = COPY_f32TimeInSec * 10000;

	/* Initial Preload value with Desired Time */
	OCR0 = 99;

	/*Select clock " CLK \ 8" ==> Prescaler */
	CLR_BIT(TCCR0 , CS00);
	SET_BIT(TCCR0 , CS01);
	CLR_BIT(TCCR0 , CS02);

}

void TIMER0_voidTimer0OVFSetCallBack (void (*Copy_PFvoidTimer0OVF)(void))
{
	TIMER_PFTimer0OVF = Copy_PFvoidTimer0OVF ;
}

void TIMER0_voidTimer0CTCSetCallBack (void (*Copy_PFvoidTimer0CTC) (void))
{
	TIMER_PFTimer0CTC = Copy_PFvoidTimer0CTC ;
}

ISR (TIMER0_OVF_vect)
{
	static u16 Local_u8OVFCounter = 0 ;
	Local_u8OVFCounter ++ ;
	if (Local_u8OVFCounter == COPY_u16LapsT0)
	{
		/* Clear Local_u8OVFCounter */
		Local_u8OVFCounter = 0 ;
		/* Initial Preload value */
		TCNT0 = COPY_u8IntialTicksT0 ;
		/*Action*/
		TIMER_PFTimer0OVF() ;
	}
}

ISR(TIMER0_COMP_vect)
{
	static u16 Local_u8OVCTCCounter = 0 ;
	Local_u8OVCTCCounter ++ ;
	if (Local_u8OVCTCCounter == COPY_u16LapsT0)
	{
		/*Action*/
		TIMER_PFTimer0CTC() ;

		/* Clear Local_u8OVFCounter */
		Local_u8OVCTCCounter = 0 ;
	}
}

/*******************************************************/
void TIMER2_voidTimer2OVFInit(f32 COPY_f32TimeInSec)
{
	/* Choose Normal mode */
	CLR_BIT(TCCR2 , WGM20);
	CLR_BIT(TCCR2 , WGM21);

	/* Enable Timer/Counter2 Overflow */
	SET_BIT(TIMSK , TOIE2);

	/* Determine no. of LAPS */
	f32 COPY_u16LapsT2WithDec = COPY_f32TimeInSec * 1000000 / 256;
	COPY_u16LapsT2 = ceil(COPY_u16LapsT2WithDec);

	/* Initial Preload value with Desired Time */
	u16 COPY_u16INTPART = (int)COPY_u16LapsT2WithDec;

	COPY_u8IntialTicksT2 = (256 - (u8)(COPY_u16LapsT2WithDec - COPY_u16INTPART) * 256);
	TCNT2 = COPY_u8IntialTicksT2;

	/* Select clock " CLK \ 8" ==> Prescaler */
	CLR_BIT(TCCR2 , CS20);
	SET_BIT(TCCR2 , CS21);
	CLR_BIT(TCCR2 , CS22);

}

void TIMER2_voidTimer2CTCInit(f32 COPY_f32TimeInSec)
{
	/* Choose CTC mode */
	CLR_BIT(TCCR2 , WGM20);
	SET_BIT(TCCR2 , WGM21);

	/* Enable Timer/Counter2 CTC AND OVF */
	SET_BIT(TIMSK , OCIE2);

	/* Determine no. of LAPS */
	COPY_u16LapsT2 = COPY_f32TimeInSec * 10000;

	/* Initial Preload value with Desired Time */
	OCR2 = 99;

	/*Select clock " CLK \ 8" ==> Prescaler */
	CLR_BIT(TCCR2 , CS20);
	SET_BIT(TCCR2 , CS21);
	CLR_BIT(TCCR2 , CS22);

}

void TIMER2_voidTimer2OVFSetCallBack (void (*Copy_PFvoidTimer2OVF)(void))
{
	TIMER_PFTimer2OVF = Copy_PFvoidTimer2OVF ;
}

void TIMER2_voidTimer2CTCSetCallBack (void (*Copy_PFvoidTimer2CTC) (void))
{
	TIMER_PFTimer2CTC = Copy_PFvoidTimer2CTC ;
}

ISR (TIMER2_OVF_vect)
{
	static u16 Local_u8OVFCounter = 0 ;
	Local_u8OVFCounter ++ ;
	if (Local_u8OVFCounter == COPY_u16LapsT2)
	{
		/* Clear Local_u8OVFCounter */
		Local_u8OVFCounter = 0 ;
		/* Initial Preload value */
		TCNT2 = COPY_u8IntialTicksT2 ;
		/*Action*/
		TIMER_PFTimer2OVF() ;
	}
}

ISR(TIMER2_COMP_vect)
{
	static u16 Local_u8OVCTCCounter = 0 ;
	Local_u8OVCTCCounter ++ ;
	if (Local_u8OVCTCCounter == COPY_u16LapsT2)
	{
		/*Action*/
		TIMER_PFTimer2CTC() ;

		/* Clear Local_u8OVFCounter */
		Local_u8OVCTCCounter = 0 ;
	}
}

/*******************************************************/
