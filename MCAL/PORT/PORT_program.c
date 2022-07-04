/******************************************************/
/******************************************************/
/***********								***********/
/***********	Author	: Kerolos Hanna		***********/
/***********	Layer	: MCAL				***********/
/***********	SWC		: PORT				***********/
/***********	Version	: 1.00				***********/
/***********								***********/
/******************************************************/
/******************************************************/

#include "STD_TYPES.h"
#include "PORT_config.h"
#include "PORT_private.h"
#include "PORT_register.h"
#include "PORT_interface.h"

void PORT_voidInit(){
	DA = PORTA_DIRECTIONS;

	DB = PORTB_DIRECTIONS;
						
	DC = PORTC_DIRECTIONS;
		
	DD = PORTD_DIRECTIONS;
}

void PORT_voidInitValue(){
	PA = PORTA_VALUES;
			   
	PB = PORTB_VALUES;
				
	PC = PORTC_VALUES;
			   
	PD = PORTD_VALUES;
}
