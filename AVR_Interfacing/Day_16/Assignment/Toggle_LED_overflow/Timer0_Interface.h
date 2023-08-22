#ifndef		TIMER0_H_
#define 	TIMER0_H_



void TIMER0_voidTimer0OVFInit(f32 COPY_f32TimeInSec);
void TIMER0_voidTimer0CTCInit(f32 COPY_f32TimeInSec);

void TIMER0_voidTimer0OVFSetCallBack (void (*Copy_PFvoidTimer0OVF) (void));
void TIMER0_voidTimer0CTCSetCallBack (void (*Copy_PFvoidTimer0CTC) (void));

void TIMER2_voidTimer2OVFInit(f32 COPY_f32TimeInSec);
void TIMER2_voidTimer2CTCInit(f32 COPY_f32TimeInSec);

void TIMER2_voidTimer2OVFSetCallBack (void (*Copy_PFvoidTimer2OVF) (void));
void TIMER2_voidTimer2CTCSetCallBack (void (*Copy_PFvoidTimer2CTC) (void));

#endif
