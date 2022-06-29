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

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

typedef struct{
	u8 LED_u8Port;
	u8 LED_u8Pin;
	u8 LED_u8Connection_Type;
}LED;

#define LED_u8SINK_CONNECTION	0
#define LED_u8SOURCE_CONNECTION 1

#define LED_u8TurnOff	0
#define LED_u8TurnOn	1

u8 LED_u8Control(LED *Copy_LED, u8 Copy_Switching);

#endif
