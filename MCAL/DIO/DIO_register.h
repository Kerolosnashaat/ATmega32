/******************************************************/
/******************************************************/
/***********								***********/
/***********	Author	: Kerolos Hanna		***********/
/***********	Layer	: MCAL				***********/
/***********	SWC		: DIO				***********/
/***********	Version	: 1.00				***********/
/***********								***********/
/******************************************************/
/******************************************************/

#ifndef DIO_REGISTER_H_
#define	DIO_REGISTER_H_

#define	PA		*( (volatile u8*) 0x3B )
#define	PB		*( (volatile u8*) 0x38 )
#define	PC		*( (volatile u8*) 0x35 )
#define	PD		*( (volatile u8*) 0x32 )

#define	PINA	*( (volatile u8*) 0x39 )
#define	PINB	*( (volatile u8*) 0x36 )
#define	PINC	*( (volatile u8*) 0x33 )
#define	PIND	*( (volatile u8*) 0x30 )

#endif
