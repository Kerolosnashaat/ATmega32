/******************************************************/
/******************************************************/
/***********								***********/
/***********	Author	: Kerolos Hanna		***********/
/***********	Layer	: HAL				***********/
/***********	SWC		: KEYPAD			***********/
/***********	Version	: 1.00				***********/
/***********								***********/
/******************************************************/
/******************************************************/


#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

#define KPD_PORT				DIO_u8PORTC

#define KPD_ROW0                0
#define KPD_ROW1                1
#define KPD_ROW2                2
#define KPD_ROW3                3

#define KPD_COLUMN0             4
#define KPD_COLUMN1             5
#define KPD_COLUMN2             6
#define KPD_COLUMN3             7

#define	KPD_NO_KEY_IS_PRESSED	'Z'

#define KPD_ROWS	4
#define KPD_COLUMNS	4

#define KPD_ARRAY_VALUES {{'7', '8', '9', '/'},{'4', '5', '6', '*'},{'1', '2', '3', '-'},{'O', '0', '=', '+'}}

#endif
