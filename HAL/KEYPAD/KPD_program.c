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


#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "KPD_interface.h"
#include "KPD_config.h"
#include "KPD_private.h"

#include <util/delay.h>
#define delay(x)	_delay_ms(x)

u8 KPD_u8PressedKey(){
	u8 Local_u8PressedKey = KPD_NO_KEY_IS_PRESSED;
	u8 Local_u8RowIterator, Local_u8ColumnIterator, Local_u8Value = 1;
	u8 Local_u8Array[KPD_ROWS][KPD_COLUMNS]= KPD_ARRAY_VALUES;
	u8 Local_u8ColumnArray[KPD_COLUMNS] = {KPD_COLUMN0, KPD_COLUMN1, KPD_COLUMN2, KPD_COLUMN3};
	u8 Local_u8ROWArray[KPD_ROWS] = {KPD_ROW0, KPD_ROW1, KPD_ROW2, KPD_ROW3};

	for(Local_u8ColumnIterator = 0 ; Local_u8ColumnIterator < KPD_COLUMNS ; Local_u8ColumnIterator++ ){
		DIO_u8SetPinValue(KPD_PORT, Local_u8ColumnArray[Local_u8ColumnIterator], DIO_u8PIN_LOW);
		for(Local_u8RowIterator = 0 ; Local_u8RowIterator < KPD_ROWS ; Local_u8RowIterator++ ){
			DIO_u8GetPinValue(KPD_PORT, Local_u8ROWArray[Local_u8RowIterator], &Local_u8Value);
			delay(50);
			if( Local_u8Value != 1 ){
				Local_u8PressedKey = Local_u8Array[Local_u8RowIterator][Local_u8ColumnIterator];
				break;
			}
		}
		DIO_u8SetPinValue(KPD_PORT, Local_u8ColumnArray[Local_u8ColumnIterator], DIO_u8PIN_HIGH);
		if( Local_u8Value != 1 ) break;
	}
	return Local_u8PressedKey;
}
