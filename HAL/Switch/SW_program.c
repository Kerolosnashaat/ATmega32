/******************************************************/
/******************************************************/
/***********								***********/
/***********	Author	: Kerolos Hanna		***********/
/***********	Layer	: HAL				***********/
/***********	SWC		: Switch			***********/
/***********	Version	: 1.00				***********/
/***********								***********/
/******************************************************/
/******************************************************/


#include "STD_TYPES.h"
#include "SW_interface.h"
#include "DIO_interface.h"

#include <util/delay.h>
#define delay(x)	_delay_ms(x)

u8 SW_u8GetReadings(Switch *Copy_Switch, u8* Copy_pu8Value){
	u8 SW_u8ErrorState = 0, SW_u8Delay, SW_u8Reading;
	/*  Momentary Switch Denounce */
	switch(Copy_Switch->SW_u8Type){
	case SW_u8LATCH:	SW_u8Delay = 0;		break;
	case SW_u8MOMETARY:	SW_u8Delay = 250;	break;
	}
	/* Set the Pin Direction To Input */
	DIO_u8SetPinDirection(Copy_Switch->SW_u8Port, Copy_Switch->SW_u8Pin, DIO_u8PIN_INPUT);
	/* Set the Pull up Resistor If Needed */
	if(Copy_Switch->Sw_u8PullType == SW_u8PULL_UP){
		DIO_u8SetPinValue(Copy_Switch->SW_u8Port, Copy_Switch->SW_u8Pin, DIO_u8PIN_HIGH);
		SW_u8Reading = 1;
	}else if(Copy_Switch->Sw_u8PullType == SW_u8PULL_DOWN){
		DIO_u8SetPinValue(Copy_Switch->SW_u8Port, Copy_Switch->SW_u8Pin, DIO_u8PIN_LOW);
		SW_u8Reading = 0;
	}else{
		SW_u8ErrorState = 1;
	}
	/* Get the Reading */
	DIO_u8GetPinValue(Copy_Switch->SW_u8Port, Copy_Switch->SW_u8Pin, &SW_u8Reading);
	delay(SW_u8Delay);

	switch(Copy_Switch->Sw_u8PullType){
	case SW_u8PULL_UP:
		if(SW_u8Reading == 1)		*Copy_pu8Value = SW_u8NOT_PRESSED;
		else if(SW_u8Reading == 0)	*Copy_pu8Value = SW_u8PRESSED;
		break;
	case SW_u8PULL_DOWN:
		if(SW_u8Reading == 1)		*Copy_pu8Value = SW_u8PRESSED;
		else if(SW_u8Reading == 0)	*Copy_pu8Value = SW_u8NOT_PRESSED;
		break;
	}
	return SW_u8ErrorState;
}
