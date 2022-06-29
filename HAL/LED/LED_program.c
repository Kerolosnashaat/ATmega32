/******************************************************/
/******************************************************/
/***********								***********/
/***********	Author	: Kerolos Hanna		***********/
/***********	Layer	: HAL				***********/
/***********	SWC		: LED				***********/
/***********	Version	: 1.00				***********/
/***********								***********/
/******************************************************/
/******************************************************/

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "LED_interface.h"


u8 LED_u8Control(LED *Copy_LED, u8 Copy_u8Switching){
	u8 LED_u8ErrorState = 0;
	u8 Local_u8On, Local_u8Off;
	DIO_u8SetPinDirection(Copy_LED->LED_u8Port, Copy_LED->LED_u8Pin, DIO_u8PIN_OUTPUT);

	if( Copy_LED->LED_u8Connection_Type == LED_u8SINK_CONNECTION ){
		Local_u8On=0;
		Local_u8Off=1;
	}else if( Copy_LED->LED_u8Connection_Type == LED_u8SOURCE_CONNECTION){
		Local_u8On=1;
		Local_u8Off=0;
	}

	if(Copy_u8Switching == LED_u8TurnOff){
		DIO_u8SetPinValue(Copy_LED->LED_u8Port, Copy_LED->LED_u8Pin, Local_u8Off);
	}else if(Copy_u8Switching == LED_u8TurnOn){
		DIO_u8SetPinValue(Copy_LED->LED_u8Port, Copy_LED->LED_u8Pin, Local_u8On);
	}else{
		LED_u8ErrorState = 1;
	}
	return LED_u8ErrorState;
}
