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

#ifndef PORT_CONFIG_H_
#define	PORT_CONFIG_H_

/* Use INPUT or OUTPUT */
#define PORTA_PIN0_DIRECTION    INPUT
#define PORTA_PIN1_DIRECTION    INPUT
#define PORTA_PIN2_DIRECTION    INPUT
#define PORTA_PIN3_DIRECTION    INPUT
#define PORTA_PIN4_DIRECTION    OUTPUT
#define PORTA_PIN5_DIRECTION    OUTPUT
#define PORTA_PIN6_DIRECTION    OUTPUT
#define PORTA_PIN7_DIRECTION    OUTPUT
/***************************/   
#define PORTB_PIN0_DIRECTION    OUTPUT
#define PORTB_PIN1_DIRECTION    OUTPUT
#define PORTB_PIN2_DIRECTION    OUTPUT
#define PORTB_PIN3_DIRECTION    INPUT
#define PORTB_PIN4_DIRECTION    INPUT
#define PORTB_PIN5_DIRECTION    INPUT
#define PORTB_PIN6_DIRECTION    INPUT
#define PORTB_PIN7_DIRECTION    INPUT
/***************************/   
#define PORTC_PIN0_DIRECTION    INPUT
#define PORTC_PIN1_DIRECTION    INPUT
#define PORTC_PIN2_DIRECTION    INPUT
#define PORTC_PIN3_DIRECTION    INPUT
#define PORTC_PIN4_DIRECTION    OUTPUT
#define PORTC_PIN5_DIRECTION    OUTPUT
#define PORTC_PIN6_DIRECTION    OUTPUT
#define PORTC_PIN7_DIRECTION    OUTPUT
/***************************/   
#define PORTD_PIN0_DIRECTION    OUTPUT
#define PORTD_PIN1_DIRECTION    OUTPUT
#define PORTD_PIN2_DIRECTION    OUTPUT
#define PORTD_PIN3_DIRECTION    OUTPUT
#define PORTD_PIN4_DIRECTION    OUTPUT
#define PORTD_PIN5_DIRECTION    OUTPUT
#define PORTD_PIN6_DIRECTION    OUTPUT
#define PORTD_PIN7_DIRECTION    OUTPUT

/* Use HIGH/PULLUP or LOW/PULLDOWN */
#define PORTA_PIN0_VALUE	    LOW
#define PORTA_PIN1_VALUE	    LOW
#define PORTA_PIN2_VALUE	    LOW
#define PORTA_PIN3_VALUE	    LOW
#define PORTA_PIN4_VALUE	    LOW
#define PORTA_PIN5_VALUE	    LOW
#define PORTA_PIN6_VALUE	    LOW
#define PORTA_PIN7_VALUE	    LOW
/***************************/   
#define PORTB_PIN0_VALUE	    LOW
#define PORTB_PIN1_VALUE	    LOW
#define PORTB_PIN2_VALUE	    LOW
#define PORTB_PIN3_VALUE	    LOW
#define PORTB_PIN4_VALUE	    LOW
#define PORTB_PIN5_VALUE	    LOW
#define PORTB_PIN6_VALUE	    LOW
#define PORTB_PIN7_VALUE	    LOW
/***************************/   
#define PORTC_PIN0_VALUE	    PULLUP
#define PORTC_PIN1_VALUE	    PULLUP
#define PORTC_PIN2_VALUE	    PULLUP
#define PORTC_PIN3_VALUE	    PULLUP
#define PORTC_PIN4_VALUE	    HIGH
#define PORTC_PIN5_VALUE	    HIGH
#define PORTC_PIN6_VALUE	    HIGH
#define PORTC_PIN7_VALUE	    HIGH
/***************************/   
#define PORTD_PIN0_VALUE	    LOW
#define PORTD_PIN1_VALUE	    LOW
#define PORTD_PIN2_VALUE	    LOW
#define PORTD_PIN3_VALUE	    LOW
#define PORTD_PIN4_VALUE	    LOW
#define PORTD_PIN5_VALUE	    LOW
#define PORTD_PIN6_VALUE	    LOW
#define PORTD_PIN7_VALUE	    LOW

#endif
