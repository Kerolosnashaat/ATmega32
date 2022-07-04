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

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"CLCD_private.h"
#include"CLCD_interface.h"
#include"CLCD_config.h"

#include"DIO_interface.h"




#include<util/delay.h>
#define delay(x)	_delay_ms(x)

#if	CLCD_OPERATION == CLCD_u88BIT
void CLCD_voidInit(){
	delay(30);

	/* Set RS and R/W to Low for Instruction write operation */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8RS_PIN, DIO_u8PIN_LOW);
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8RW_PIN, DIO_u8PIN_LOW);

	//	Initialising LCD in 8-bit mode Function Set 2 Lines, 5X7 characters Mode
	CLCD_u8SendCommand(0x3C);

	// Display ON, Cursor OFF, Blinking OFF
	CLCD_u8SendCommand(CLCD_u8DISPLAY_ON_CURSOR_OFF_BLINKING_OFF);

	//Clear Display
	CLCD_u8SendCommand(CLCD_u8CLEAR_SCREEN);

}

u8 CLCD_u8SendCommand( u8 Copy_u8Command ){
	u8 Local_u8ErrorState = 0;

	/* Set RS to LOW for command */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8RS_PIN, DIO_u8PIN_LOW);

	/* Set R/W to LOW for write */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8RW_PIN, DIO_u8PIN_LOW);

	/* Set EN to LOW */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_LOW);

	/* Send Command */
	DIO_u8SetPortValue(CLCD_u8DATA_PORT, Copy_u8Command);

	/* Send Enabling Pulse */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_HIGH);
	delay(CLCD_u8EN_PULSE);
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_LOW);


	return Local_u8ErrorState;
}

u8 CLCD_u8SendCharacter( u8 Copy_u8Character ){
	u8 Local_u8ErrorState = 0;
	/* Set RS to High for data */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8RS_PIN, DIO_u8PIN_HIGH);

	/* Set R/W to LOW for write */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8RW_PIN, DIO_u8PIN_LOW);

	/* Set EN to LOW */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_LOW);

	/* Send Data */
	DIO_u8SetPortValue(CLCD_u8DATA_PORT, Copy_u8Character);

	/* Send Enabling Pulse */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_HIGH);
	delay(CLCD_u8EN_PULSE);
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_LOW);
	return Local_u8ErrorState;
}
#elif CLCD_OPERATION == CLCD_u84BIT
void CLCD_voidInit(){
	delay(30);

	/* Set RS and R/W to Low for Instruction write operation */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8RS_PIN, DIO_u8PIN_LOW);
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8RW_PIN, DIO_u8PIN_LOW);

	// Initialising LCD in 4-bit mode
	CLCD_u8SendCommand(CLCD_u8RETURN_HOME);

	//	Function Set 2 Lines, 5X7 characters Mode
	CLCD_u8SendCommand(0x28);

	// Display ON, Cursor OFF, Blinking OFF
	CLCD_u8SendCommand(CLCD_u8DISPLAY_ON_CURSOR_OFF_BLINKING_OFF);

	//Clear Display
	CLCD_u8SendCommand(CLCD_u8CLEAR_SCREEN);

}

u8 CLCD_u8SendCommand( u8 Copy_u8Command ){
	u8 Local_u8ErrorState = 0;

	/* Set RS to LOW for command */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8RS_PIN, DIO_u8PIN_LOW);

	/* Set R/W to LOW for write */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8RW_PIN, DIO_u8PIN_LOW);

	/* Set EN to LOW */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_LOW);

	/* Send Command MSB*/
	DIO_u8SetPinValue(CLCD_u8DATA_PORT4, CLCD_u8DATA_PIN4, GET_BIT(Copy_u8Command, 4));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT5, CLCD_u8DATA_PIN5, GET_BIT(Copy_u8Command, 5));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT6, CLCD_u8DATA_PIN6, GET_BIT(Copy_u8Command, 6));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT7, CLCD_u8DATA_PIN7, GET_BIT(Copy_u8Command, 7));

	/* Send Enabling Pulse */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_HIGH);
	delay(CLCD_u8EN_PULSE);
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_LOW);

	/* Send Command LSB */
	DIO_u8SetPinValue(CLCD_u8DATA_PORT4, CLCD_u8DATA_PIN4, GET_BIT(Copy_u8Command, 0));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT5, CLCD_u8DATA_PIN5, GET_BIT(Copy_u8Command, 1));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT6, CLCD_u8DATA_PIN6, GET_BIT(Copy_u8Command, 2));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT7, CLCD_u8DATA_PIN7, GET_BIT(Copy_u8Command, 3));

	/* Send Enabling Pulse */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_HIGH);
	delay(CLCD_u8EN_PULSE);
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_LOW);
	return Local_u8ErrorState;
}

u8 CLCD_u8SendCharacter( u8 Copy_u8Character ){
	u8 Local_u8ErrorState = 0;

	/* Set RS to High for data */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8RS_PIN, DIO_u8PIN_HIGH);

	/* Set R/W to LOW for write */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8RW_PIN, DIO_u8PIN_LOW);

	/* Set EN to LOW */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_LOW);

	/* Send Command MSB */
	DIO_u8SetPinValue(CLCD_u8DATA_PORT4, CLCD_u8DATA_PIN4, GET_BIT(Copy_u8Character, 4));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT5, CLCD_u8DATA_PIN5, GET_BIT(Copy_u8Character, 5));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT6, CLCD_u8DATA_PIN6, GET_BIT(Copy_u8Character, 6));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT7, CLCD_u8DATA_PIN7, GET_BIT(Copy_u8Character, 7));

	/* Send Enabling Pulse */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_HIGH);
	delay(CLCD_u8EN_PULSE);
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_LOW);

	/* Send Command LSB */
	DIO_u8SetPinValue(CLCD_u8DATA_PORT4, CLCD_u8DATA_PIN4, GET_BIT(Copy_u8Character, 0));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT5, CLCD_u8DATA_PIN5, GET_BIT(Copy_u8Character, 1));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT6, CLCD_u8DATA_PIN6, GET_BIT(Copy_u8Character, 2));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT7, CLCD_u8DATA_PIN7, GET_BIT(Copy_u8Character, 3));

	/* Send Enabling Pulse */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_HIGH);
	delay(CLCD_u8EN_PULSE);
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_LOW);


	delay(20);
	return Local_u8ErrorState;
}



#endif



u8 CLCD_u8SendString( u8 *Copy_pu8String ){
	u8 Local_u8ErrorState = 0;
	u8 Local_u8Counter = 0;
	/* Send the string Character by Character */
	while( *(Copy_pu8String + Local_u8Counter) != '\0'){
		CLCD_u8SendCharacter(*(Copy_pu8String + Local_u8Counter));
		Local_u8Counter++;
		if( Local_u8Counter > 15 ) CLCD_u8CursorLocation(Local_u8Counter - 16, CLCD_u8SECOND_LINE);
	}
	return Local_u8ErrorState;
}

u8 CLCD_u8CursorLocation(u8 Copy_u8XPosition, u8 Copy_u8YPosition){
	u8 Local_u8ErrorState = 0;
	u8 Local_u8Address;
	/* Checking on the Max number of lines */
	if(Copy_u8YPosition > CLCD_u8SECOND_LINE) Local_u8ErrorState = 1;

	/* Calculating the Address value according to the X, & Y values */
	switch(Copy_u8YPosition){
	case CLCD_u8FIRST_LINE:	Local_u8Address = Copy_u8XPosition;			break;
	case CLCD_u8SECOND_LINE:Local_u8Address = Copy_u8XPosition + 0x40;	break;
	}

	/* The Address command with 7th bit HIGH */
	Local_u8Address += 128;

	/* Send LCD DDRAM Address command */
	CLCD_u8SendCommand(Local_u8Address);
	return Local_u8ErrorState;
}

u8 CLCD_u8SendNumber( u32 const Copy_u32Number ){
	u8 Local_u8ErrorState = 0, Local_u8ArraySize = 1;
	u32 Local_32Number = Copy_u32Number;
	/* Checking the Number of Digits */
	if (Local_32Number > 9			)	Local_u8ArraySize = 2  ;
	if (Local_32Number > 99			)	Local_u8ArraySize = 3  ;
	if (Local_32Number > 999		)	Local_u8ArraySize = 4  ;
	if (Local_32Number > 9999		)	Local_u8ArraySize = 5  ;
	if (Local_32Number > 99999		)	Local_u8ArraySize = 6  ;
	if (Local_32Number > 999999		)	Local_u8ArraySize = 7  ;
	if (Local_32Number > 9999999	)	Local_u8ArraySize = 8  ;
	if (Local_32Number > 99999999	)	Local_u8ArraySize = 9  ;
	if (Local_32Number > 999999999	)	Local_u8ArraySize = 10 ;

	/* Define an array with the Number of Digits */
	u8 Local_u8NumbersArray[Local_u8ArraySize];

	/* Divide the number into separated digits, each one as an array element  */
	for( u8 Local_u8_Counter = 0 ; Local_u8_Counter < Local_u8ArraySize ; Local_u8_Counter++ ){
		/* But each reminder as an array element */
		Local_u8NumbersArray[Local_u8_Counter] = Local_32Number % 10;
		/* Remove the last digit */
		Local_32Number /= 10;
	}

	/* Display the array */
	for( u8 Local_u8_Counter = (Local_u8ArraySize) ; Local_u8_Counter > 0 ; Local_u8_Counter-- ){
		/* adding the Value of the ASCII table */
		CLCD_u8SendCharacter(Local_u8NumbersArray[Local_u8_Counter-1]+0x30);
	}
	return Local_u8ErrorState;
}

void CLCD_voidClearScreen(){
	CLCD_u8SendCommand(CLCD_u8CLEAR_SCREEN);
}


u8 CLCD_u8SendSpecialCharacter( u8 *Copy_pu8Array, u8 Copy_u8BlockNumber, u8 Copy_u8XPosition, u8 Copy_u8YPosition){
	u8 Local_u8ErrorState = 0;
	u8 Local_u8Address;
	/* Checking for the block Number from 0 to 7 */
	if( Copy_u8BlockNumber > 7 ){
		Local_u8ErrorState = 1;
	}else{
		/* Calculating the Address Location in CGRAM for each block is 8 bytes */
		Local_u8Address = Copy_u8BlockNumber * 8;


		/* Address command, with 6th bit HIGH & 7th bit LOW*/
		Local_u8Address += 64;

		/* Send LCD CGRAM Address command */
		CLCD_u8SendCommand(Local_u8Address);

		/* Setting the new character pattern in the CGRAM*/
		for( u8 Local_u8DataCounter = 0 ; Local_u8DataCounter < 8 ; Local_u8DataCounter++ ){
			CLCD_u8SendCharacter(*(Copy_pu8Array + Local_u8DataCounter));
		}

		/* Back to DDRAM with X, Y Position */
		CLCD_u8CursorLocation( Copy_u8XPosition, Copy_u8YPosition);

		/* Show the new character from the CGRAM in the screen */
		CLCD_u8SendCharacter(Copy_u8BlockNumber);
	}

	return Local_u8ErrorState;
}
