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
#include"DIO_interface.h"
#include "BIT_MATH.h"

#include<util/delay.h>
#define delay(x)	_delay_ms(x)

#include"CLCD_interface.h"
#include"CLCD_config.h"
#include"CLCD_private.h"


#if	CLCD_OPERATION == 8
void CLCD_vidInit(){
	delay(30);
	DIO_u8SetPinDirection(CLCD_u8CONTROL_PORT, CLCD_U8RS_PIN, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_u8CONTROL_PORT, CLCD_U8RW_PIN, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_OUTPUT);
	DIO_u8SetPortDirection(CLCD_u8DATA_PORT, DIO_u8PORT_OUTPUT);

	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8RS_PIN, DIO_u8PIN_LOW);
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8RW_PIN, DIO_u8PIN_LOW);

	//	Initialising LCD in 8-bit mode Function Set 2 Lines, 5X7 characters Mode
	CLCD_u8SendCommand(0x3C);

	// Display ON, Cursor OFF, Blinking OFF
	CLCD_u8SendCommand(0x0C);

	//Clear Display
	CLCD_u8SendCommand(0x01);

}

u8 CLCD_u8SendCommand( u8 Copy_u8Command ){
	u8 CLC_u8ErrorState = 0;

	/* Set RS to LOW for command */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8RS_PIN, DIO_u8PIN_LOW);

	/* Set RW to LOW for write */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8RW_PIN, DIO_u8PIN_LOW);

	/* Set EN to LOW */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_LOW);

	/* Send Command */
	DIO_u8SetPortValue(CLCD_u8DATA_PORT, Copy_u8Command);

	/* Send Enabling Pulse */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_HIGH);
	delay(CLCD_u8EN_PULSE);
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_LOW);


	return CLC_u8ErrorState;
}

u8 CLCD_u8SendData( u8 Copy_u8Data ){
	u8 CLC_u8ErrorState = 0;
	/* Set RS to High for data */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8RS_PIN, DIO_u8PIN_HIGH);

	/* Set RW to LOW for write */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8RW_PIN, DIO_u8PIN_LOW);

	/* Set EN to LOW */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_LOW);

	/* Send Data */
	DIO_u8SetPortValue(CLCD_u8DATA_PORT, Copy_u8Data);

	/* Send Enabling Pulse */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_HIGH);
	delay(CLCD_u8EN_PULSE);
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_LOW);
	return CLC_u8ErrorState;
}
#elif CLCD_OPERATION == 4
void CLCD_vidInit(){
	delay(30);
	DIO_u8SetPinDirection(CLCD_u8CONTROL_PORT, CLCD_U8RS_PIN, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_u8CONTROL_PORT, CLCD_U8RW_PIN, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_OUTPUT);

	DIO_u8SetPinDirection(CLCD_u8DATA_PORT4, CLCD_u8DATA_PIN4, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_u8DATA_PORT5, CLCD_u8DATA_PIN5, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_u8DATA_PORT6, CLCD_u8DATA_PIN6, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_u8DATA_PORT7, CLCD_u8DATA_PIN7, DIO_u8PIN_OUTPUT);

	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8RS_PIN, DIO_u8PIN_LOW);
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8RW_PIN, DIO_u8PIN_LOW);

	// Initialising LCD in 4-bit mode
	CLCD_u8SendCommand(0X02);

	//	Function Set 2 Lines, 5X7 characters Mode
	CLCD_u8SendCommand(0x28);

	// Display ON, Cursor OFF, Blinking OFF
	CLCD_u8SendCommand(0x0C);

	//Clear Display
	CLCD_u8SendCommand(0x01);

}

u8 CLCD_u8SendCommand( u8 Copy_u8Command ){
	u8 CLC_u8ErrorState = 0;

	/* Set RS to LOW for command */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8RS_PIN, DIO_u8PIN_LOW);

	/* Set RW to LOW for write */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8RW_PIN, DIO_u8PIN_LOW);

	/* Set EN to LOW */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_LOW);

	/* Send Command */
	DIO_u8SetPinValue(CLCD_u8DATA_PORT4, CLCD_u8DATA_PIN4, GET_BIT(Copy_u8Command, 4));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT5, CLCD_u8DATA_PIN5, GET_BIT(Copy_u8Command, 5));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT6, CLCD_u8DATA_PIN6, GET_BIT(Copy_u8Command, 6));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT7, CLCD_u8DATA_PIN7, GET_BIT(Copy_u8Command, 7));

	/* Send Enabling Pulse */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_HIGH);
	delay(CLCD_u8EN_PULSE);
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_LOW);

	/* Send Command */
	DIO_u8SetPinValue(CLCD_u8DATA_PORT4, CLCD_u8DATA_PIN4, GET_BIT(Copy_u8Command, 0));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT5, CLCD_u8DATA_PIN5, GET_BIT(Copy_u8Command, 1));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT6, CLCD_u8DATA_PIN6, GET_BIT(Copy_u8Command, 2));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT7, CLCD_u8DATA_PIN7, GET_BIT(Copy_u8Command, 3));

	/* Send Enabling Pulse */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_HIGH);
	delay(CLCD_u8EN_PULSE);
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_LOW);
	return CLC_u8ErrorState;
}

u8 CLCD_u8SendData( u8 Copy_u8Data ){
	u8 CLC_u8ErrorState = 0;

	/* Set RS to High for data */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8RS_PIN, DIO_u8PIN_HIGH);

	/* Set RW to LOW for write */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8RW_PIN, DIO_u8PIN_LOW);

	/* Set EN to LOW */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_LOW);

	//* Send Command */
	DIO_u8SetPinValue(CLCD_u8DATA_PORT4, CLCD_u8DATA_PIN4, GET_BIT(Copy_u8Data, 4));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT5, CLCD_u8DATA_PIN5, GET_BIT(Copy_u8Data, 5));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT6, CLCD_u8DATA_PIN6, GET_BIT(Copy_u8Data, 6));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT7, CLCD_u8DATA_PIN7, GET_BIT(Copy_u8Data, 7));

	/* Send Enabling Pulse */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_HIGH);
	delay(CLCD_u8EN_PULSE);
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_LOW);

	/* Send Command */
	DIO_u8SetPinValue(CLCD_u8DATA_PORT4, CLCD_u8DATA_PIN4, GET_BIT(Copy_u8Data, 0));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT5, CLCD_u8DATA_PIN5, GET_BIT(Copy_u8Data, 1));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT6, CLCD_u8DATA_PIN6, GET_BIT(Copy_u8Data, 2));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT7, CLCD_u8DATA_PIN7, GET_BIT(Copy_u8Data, 3));

	/* Send Enabling Pulse */
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_HIGH);
	delay(CLCD_u8EN_PULSE);
	DIO_u8SetPinValue(CLCD_u8CONTROL_PORT, CLCD_U8EN_PIN, DIO_u8PIN_LOW);


	delay(20);
	return CLC_u8ErrorState;
}



#endif
