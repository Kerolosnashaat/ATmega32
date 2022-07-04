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

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

#define CLCD_OPERATION			4

#define CLCD_u8SAME_PORT		0
#define CLCD_u8MULTIPLE_PORTS	1

#define	CLCD_u8DATA_PORT				DIO_u8PORTA
#define CLCD_8uDATA_PORT_CONNECTION		CLCD_u8SAME_PORT

#if CLCD_8uDATA_PORT_CONNECTION == CLCD_u8MULTIPLE_PORTS
#define CLCD_u8DATA_PORT4	DIO_u8PORTA
#define CLCD_u8DATA_PORT5	DIO_u8PORTB
#define CLCD_u8DATA_PORT6	DIO_u8PORTC
#define CLCD_u8DATA_PORT7	DIO_u8PORTD
#elif CLCD_8uDATA_PORT_CONNECTION == CLCD_u8SAME_PORT
#define CLCD_u8DATA_PORT4	CLCD_u8DATA_PORT
#define CLCD_u8DATA_PORT5	CLCD_u8DATA_PORT
#define CLCD_u8DATA_PORT6	CLCD_u8DATA_PORT
#define CLCD_u8DATA_PORT7	CLCD_u8DATA_PORT
#endif

#if	CLCD_OPERATION == 4

#define	CLCD_u8DATA_PIN4		DIO_u8PIN4
#define	CLCD_u8DATA_PIN5		DIO_u8PIN5
#define	CLCD_u8DATA_PIN6		DIO_u8PIN6
#define	CLCD_u8DATA_PIN7		DIO_u8PIN7

#endif



#define CLCD_u8CONTROL_PORT		DIO_u8PORTB
#define	CLCD_U8RS_PIN			DIO_u8PIN0		// 0 for Commands	, 1 for Data
#define	CLCD_U8RW_PIN			DIO_u8PIN1		// 0 for Write		, 1 for Read
#define	CLCD_U8EN_PIN			DIO_u8PIN2
#define CLCD_u8EN_PULSE			10

#endif
