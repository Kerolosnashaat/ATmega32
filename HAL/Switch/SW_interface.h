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

#ifndef	SW_INTERFACE_H_
#define SW_INTERFACE_H_

typedef struct{
	u8 SW_u8Port;
	u8 SW_u8Pin;
	u8 Sw_u8PullType;
	u8 SW_u8Type;
}Switch;

#define SW_u8PULL_DOWN	0
#define SW_u8PULL_UP	1

#define SW_u8LATCH		0
#define SW_u8MOMETARY	1

#define SW_u8NOT_PRESSED	0
#define SW_u8PRESSED		1

u8 SW_u8GetReadings(Switch *Copy_Switch, u8* Copy_pu8Value);

#endif
