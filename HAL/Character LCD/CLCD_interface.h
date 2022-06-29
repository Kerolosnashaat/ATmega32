/******************************************************/
/******************************************************/
/***********								***********/
/***********	Author	: Kerolos Hanna		***********/
/***********	Layer	: HAL				***********/
/***********	SWC		: Character LCD		***********/
/***********	Version	: 1.00				***********/
/***********								***********/
/******************************************************/
/******************************************************/
#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

void CLCD_vidInit();

u8 CLCD_u8SendCommand( u8 Copy_u8Command );

u8 CLCD_u8SendData( u8 Copy_u8Data );


#if	CLCD_OPERATION == 4

void CLCD_vidConvertToArray( u8 Copy_u8Number, u8 *Copy_u8Array);

#endif

#endif
