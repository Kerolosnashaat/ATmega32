/******************************************************/
/******************************************************/
/***********								***********/
/***********	Author	: Kerolos Hanna		***********/
/***********	Layer	: Libraries			***********/
/***********	Version	: 1.00				***********/
/***********								***********/
/******************************************************/
/******************************************************/


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char		u8;
typedef unsigned short int	u16;
typedef unsigned long int	u32;

typedef signed char			s8;
typedef signed short int	s16;
typedef signed long int		s32;

typedef float				f32;
typedef	double				f64;
typedef	long double			f128;

typedef enum {
	STD_Low		=	0,
	STD_High	=	1
	}STD_Level;

typedef enum {
	FALSE	=	0,
	TRUE	=	1
	}BOOL;
	

#define NULL	( (void*) 0 )

#define ENABLE	1
#define DISABLE	0

#endif /* STD_TYPES_H_ */
