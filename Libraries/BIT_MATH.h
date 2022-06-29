//******************************************************/
/******************************************************/
/***********								***********/
/***********	Author	: Kerolos Hanna		***********/
/***********	Layer	: Libraries			***********/
/***********	Version	: 1.00				***********/
/***********								***********/
/******************************************************/
/******************************************************/


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(u8_Var, pinNo)		u8_Var |=  ( 1 << pinNo )		//To set the bit to 1
#define CLR_BIT(u8_Var, pinNo)		u8_Var &= ~( 1 << pinNo )		//To set the bit to 0
#define TOGGLE_BIT(u8_Var, pinNo)	u8_Var ^=  ( 1 << pinNo )		//To reverse the bit
#define GET_BIT(u8_Var, pinNo)		( u8_Var >> pinNo ) & 0x1		//To get the pin Input

#endif /* BIT_MATH_H_ */
