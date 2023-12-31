#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/interrupt.h>
#include "DIO_Interface.h"
#include "EXTI_Interface.h"
#define NULL ((void *)0)
static void (*EXTI_pf_EXTI[3])(void) = {NULL,NULL,NULL};
void EXTI_voidInit(void)
{
	/* FOR INT0 */
#if   EXTI_INDEX == INT0
	SET_BIT(GICR, GICR_INT0);
	/* CHOOSE CLOCK */
#if   EXTI_CLOCK == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);
#elif EXTI_CLOCK == ANY_LOGICAL
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);
#elif EXTI_CLOCK == FALLING
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#elif EXTI_CLOCK == RAISING
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#endif

	/* FOR INT1 */
#elif EXTI_INDEX == INT1
	SET_BIT(GICR, GICR_INT1);
	/* CHOOSE CLOCK */
#if   EXTI_CLOCK == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
#elif EXTI_CLOCK == ANY_LOGICAL
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
#elif EXTI_CLOCK == FALLING
	CLR_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#elif EXTI_CLOCK == RAISING
	SET_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#endif
#elif EXTI_INDEX == INT2
	/* FOR INT2 */
	SET_BIT(GICR, GICR_INT2);
#if   EXTI_CLOCK == FALLING
	CLR_BIT(MCUCSR, DIO_PIN6);
#elif EXTI_CLOCK == RAISING
	SET_BIT(MCUCSR, DIO_PIN6);
#endif
#endif
}

void EXTI_voidGIE(void)
{
#if   GIE == ENABLE
	SET_BIT(SREG, SREG_PIN);
#elif GIE == DISABLE
	CLR_BIT(SREG, SREG_PIN);
#endif
}


void EXTI_voidEXTISetCallBack(u8 copy_u8EXTIIndex, void (*copy_pf)(void))
{
	EXTI_pf_EXTI[copy_u8EXTIIndex] = copy_pf;
}

ISR(INT0_vect)
{
	if(EXTI_pf_EXTI[0]!= NULL)
	{
		EXTI_pf_EXTI[0]();
	}
}

ISR(INT1_vect)
{
	if(EXTI_pf_EXTI[1]!= NULL)
	{
		EXTI_pf_EXTI[1]();
	}
}

ISR(INT2_vect)
{
	if(EXTI_pf_EXTI[2]!= NULL)
	{
		EXTI_pf_EXTI[2]();
	}
}

