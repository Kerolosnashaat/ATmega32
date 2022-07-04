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

#define CLCD_u8FIRST_LINE	0
#define CLCD_u8SECOND_LINE	1

#define CLCD_u8CLEAR_SCREEN							0x01
#define CLCD_u8RETURN_HOME							0x02
#define CLCD_u8DISPLAY_ON_CURSOR_OFF_BLINKING_OFF	0x0C

void CLCD_voidInit();

u8 CLCD_u8SendCommand( u8 Copy_u8Command );

u8 CLCD_u8SendCharacter( u8 Copy_u8Character );

u8 CLCD_u8SendString( u8 *Copy_pu8String );

u8 CLCD_u8SendNumber( u32 const Copy_u32Number );

u8 CLCD_u8CursorLocation(u8 Copy_u8XPosition, u8 Copy_u8YPosition);

void CLCD_voidClearScreen();

u8 CLCD_u8SendSpecialCharacter( u8 *pCopy_u8Array, u8 Copy_u8BlockNumber, u8 Copy_u8XPosition, u8 Copy_u8YPosition);

#endif
