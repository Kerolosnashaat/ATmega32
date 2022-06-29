/******************************************************/
/******************************************************/
/***********								***********/
/***********	Author	: Kerolos Hanna		***********/
/***********	Layer	: HAL				***********/
/***********	SWC		: Seven Segment		***********/
/***********	Version	: 1.00				***********/
/***********								***********/
/******************************************************/
/******************************************************/

#include"STD_TYPES.h"
#include"DIO_interface.h"

#include<util/delay.h>
#define delay(x)	_delay_ms(x)

#include"SSD_private.h"
#include"SSD_config.h"
#include"SSD_interface.h"


u8 SSD_u8ShowNumber(SSD_INIT *Copy_SSD, u8 *Copy_pu8Number){
	u8 Local_u8ErrorState = 0;
	u8 Number = *Copy_pu8Number;
	if( ((Copy_SSD->u8Port) > DIO_u8PORTD) || (Number > 9) || ((Copy_SSD->u8EnablePort) > DIO_u8PORTD) || ((Copy_SSD->u8EnablePin) > DIO_u8PIN7) ){
		Local_u8ErrorState = 1;
	}

	DIO_u8SetPortDirection(Copy_SSD->u8Port, DIO_u8PORT_OUTPUT);
	DIO_u8SetPinDirection(Copy_SSD->u8EnablePort, Copy_SSD->u8EnablePin, DIO_u8PIN_OUTPUT);

	switch(Copy_SSD->u8Type){
	case SSD_u8COMMON_CATHOD:
		DIO_u8SetPinValue(Copy_SSD->u8EnablePort, Copy_SSD->u8EnablePin, DIO_u8PIN_LOW);
		DIO_u8SetPortValue(Copy_SSD->u8Port, seg[Number]);
		break;
	case SSD_u8COMMON_ANODE:
		DIO_u8SetPinValue(Copy_SSD->u8EnablePort, Copy_SSD->u8EnablePin, DIO_u8PIN_HIGH);
		DIO_u8SetPortValue(Copy_SSD->u8Port, ~(seg[Number]));
		break;
	default:Local_u8ErrorState = 1; break;
	}
	return Local_u8ErrorState;
}

u8 SSD_u8ShowMultipleNumbers(SSD_Multiple *Copy_SSDs[], u8 *Copy_pu8Number ,SSD_CONST *Copy_SSDConstants){
	u8 Local_u8ErrorState = 0;
	u16 Local_u16DisplayedNumber = *Copy_pu8Number;
	u8 Local_u8ArrayOfNumbers[Copy_SSDConstants->u8NumberOfDigits];

	/*	Divide the Number into 1 Digit */
	for(u8 u8DividCounter = 1 ; u8DividCounter <= Copy_SSDConstants->u8NumberOfDigits ; u8DividCounter++ ){
		Local_u8ArrayOfNumbers[Copy_SSDConstants->u8NumberOfDigits-u8DividCounter] = Local_u16DisplayedNumber%10;
		Local_u16DisplayedNumber /= 10;
	}

	/* Assign the 7-Segment Port to Output */
	DIO_u8SetPortDirection(Copy_SSDConstants->u8Port, DIO_u8PORT_OUTPUT);

	/* Assign the 7-Segment Enabling Pins to Output */
	for( u8 u8Digit = 0 ; u8Digit < Copy_SSDConstants->u8NumberOfDigits ; u8Digit++ ){
		DIO_u8SetPinDirection(Copy_SSDs[u8Digit]->u8EnablePort, Copy_SSDs[u8Digit]->u8EnablePin, DIO_u8PIN_OUTPUT);
	}

	for( u8 u8Digit = 0 ; u8Digit < Copy_SSDConstants->u8NumberOfDigits ; u8Digit++ ){
		switch(Copy_SSDs[u8Digit]->u8Type){
		case SSD_u8COMMON_CATHOD:
			DIO_u8SetPinValue(Copy_SSDs[u8Digit]->u8EnablePort, Copy_SSDs[u8Digit]->u8EnablePin, DIO_u8PIN_LOW);
			DIO_u8SetPortValue(Copy_SSDConstants->u8Port, seg[Local_u8ArrayOfNumbers[u8Digit]]);
			delay(Copy_SSDConstants->u8Speed);
			DIO_u8SetPinValue(Copy_SSDs[u8Digit]->u8EnablePort, Copy_SSDs[u8Digit]->u8EnablePin, DIO_u8PIN_HIGH);
			break;
		case SSD_u8COMMON_ANODE:
			DIO_u8SetPinValue(Copy_SSDs[u8Digit]->u8EnablePort, Copy_SSDs[u8Digit]->u8EnablePin, DIO_u8PIN_HIGH);
			DIO_u8SetPortValue(Copy_SSDConstants->u8Port, ~(seg[Local_u8ArrayOfNumbers[u8Digit]]));
			delay(Copy_SSDConstants->u8Speed);
			DIO_u8SetPinValue(Copy_SSDs[u8Digit]->u8EnablePort, Copy_SSDs[u8Digit]->u8EnablePin, DIO_u8PIN_LOW);
			break;
		}
	}

	return Local_u8ErrorState;
}
