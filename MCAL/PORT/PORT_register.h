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

#ifndef PORT_REGISTER_H_
#define	PORT_REGISTER_H_

#define	DA		*( (volatile u8*) 0x3A )
#define	DB		*( (volatile u8*) 0x37 )
#define	DC		*( (volatile u8*) 0x34 )
#define	DD		*( (volatile u8*) 0x31 )

#define	PA		*( (volatile u8*) 0x3B )
#define	PB		*( (volatile u8*) 0x38 )
#define	PC		*( (volatile u8*) 0x35 )
#define	PD		*( (volatile u8*) 0x32 )

#endif
