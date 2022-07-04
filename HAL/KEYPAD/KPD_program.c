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
	static u8 Local_u8Array[KPD_ROWS][KPD_COLUMNS]= KPD_ARRAY_VALUES;
	static u8 Local_u8ColumnArray[KPD_COLUMNS] = {KPD_COLUMN0, KPD_COLUMN1, KPD_COLUMN2, KPD_COLUMN3};
	static u8 Local_u8ROWArray[KPD_ROWS] = {KPD_ROW0, KPD_ROW1, KPD_ROW2, KPD_ROW3};

	for(Local_u8ColumnIterator = 0 ; Local_u8ColumnIterator < KPD_COLUMNS ; Local_u8ColumnIterator++ ){
		/* Current Column Activation */
		DIO_u8SetPinValue(KPD_PORT, Local_u8ColumnArray[Local_u8ColumnIterator], DIO_u8PIN_LOW);
		/* Scanning the Rows */
		for(Local_u8RowIterator = 0 ; Local_u8RowIterator < KPD_ROWS ; Local_u8RowIterator++ ){
			/* Row Reading */
			DIO_u8GetPinValue(KPD_PORT, Local_u8ROWArray[Local_u8RowIterator], &Local_u8Value);
			/* Check if a switch is pressed */
			if( Local_u8Value == 0 ){
				/* Assigning the value from the array */
				Local_u8PressedKey = Local_u8Array[Local_u8RowIterator][Local_u8ColumnIterator];
				/* Checking for a Rising Edge */
				while( Local_u8Value == 0 ){
					/* Row Reading */
					DIO_u8GetPinValue(KPD_PORT, Local_u8ROWArray[Local_u8RowIterator], &Local_u8Value);
				}
				/* Current Column Deactivate */
				DIO_u8SetPinValue(KPD_PORT, Local_u8ColumnArray[Local_u8ColumnIterator], DIO_u8PIN_HIGH);
				return Local_u8PressedKey;
			}
		}
		/* Current Column Deactivate */
		DIO_u8SetPinValue(KPD_PORT, Local_u8ColumnArray[Local_u8ColumnIterator], DIO_u8PIN_HIGH);
	}
	return Local_u8PressedKey;
}
