/******************************************************/
/******************************************************/
/***********								***********/
/***********	Author	: Kerolos Hanna		***********/
/***********	Layer	: HAL				***********/
/***********	SWC		: Seven Segment		***********/
/***********	Version	: 1.00				***********/
/***********								***********/
/******************************************************/
/******************************************************/
#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

typedef struct{
	u8	u8Type;
	u8	u8Port;
	u8	u8EnablePort;
	u8	u8EnablePin;
}SSD_INIT;

typedef struct{
	u8	u8Type;
	u8	u8EnablePort;
	u8	u8EnablePin;
}SSD_Multiple;

typedef struct{
	u8 u8NumberOfDigits;
	u8 u8Port;
	u8 u8Speed;
}SSD_CONST;

#define SSD_u8COMMON_CATHOD		0
#define SSD_u8COMMON_ANODE		1

u8 SSD_u8ShowNumber(SSD_INIT *Copy_SSD, u8 *Copy_pu8Number);

u8 SSD_u8ShowMultipleNumbers(SSD_Multiple *Copy_SSDs[], u8 *Copy_pu8Number ,SSD_CONST *Copy_SSDConstants);

#endif
