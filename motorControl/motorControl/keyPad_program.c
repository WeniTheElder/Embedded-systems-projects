/*
 * keyPad_program.c
 *
 * Created: 2/14/2025 7:44:49 AM
 *  Author: Ahmad abdullatif
 */
#include "std_types.h"
#include "bit_math.h"
#include "DIO_interface.h"
#include "keyPad_interface.h"
#include "keyPad_config.h"

void KEYPAD_voidInit(void){
	//initializing rows
	DIO_voidSetPinDirection(KEYPAD_ROW0_PORT,KEYPAD_ROW0_PIN,DIO_INPUT);
	DIO_voidSetPinDirection(KEYPAD_ROW1_PORT,KEYPAD_ROW1_PIN,DIO_INPUT);
	DIO_voidSetPinDirection(KEYPAD_ROW2_PORT,KEYPAD_ROW2_PIN,DIO_INPUT);
	DIO_voidSetPinDirection(KEYPAD_ROW3_PORT,KEYPAD_ROW3_PIN,DIO_INPUT);
	//activating internal pull-up resistor for rows
	DIO_voidSetPinValue(KEYPAD_ROW0_PORT,KEYPAD_ROW0_PIN,DIO_HIGH);
	DIO_voidSetPinValue(KEYPAD_ROW1_PORT,KEYPAD_ROW1_PIN,DIO_HIGH);
	DIO_voidSetPinValue(KEYPAD_ROW2_PORT,KEYPAD_ROW2_PIN,DIO_HIGH);
	DIO_voidSetPinValue(KEYPAD_ROW3_PORT,KEYPAD_ROW3_PIN,DIO_HIGH);
	//initializing columns
	DIO_voidSetPinDirection(KEYPAD_COLUMN0_PORT,KEYPAD_COLUMN0_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(KEYPAD_COLUMN1_PORT,KEYPAD_COLUMN1_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(KEYPAD_COLUMN2_PORT,KEYPAD_COLUMN2_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(KEYPAD_COLUMN3_PORT,KEYPAD_COLUMN3_PIN,DIO_OUTPUT);
	DIO_voidSetPinValue(KEYPAD_COLUMN0_PORT,KEYPAD_COLUMN0_PIN,DIO_HIGH);
	DIO_voidSetPinValue(KEYPAD_COLUMN1_PORT,KEYPAD_COLUMN1_PIN,DIO_HIGH);
	DIO_voidSetPinValue(KEYPAD_COLUMN2_PORT,KEYPAD_COLUMN2_PIN,DIO_HIGH);
	DIO_voidSetPinValue(KEYPAD_COLUMN3_PORT,KEYPAD_COLUMN3_PIN,DIO_HIGH);
}


void KEYPAD_voidGetPressedKey(u8* copy_pu8pressedKey){
	//arrays for ports and pins to make iterations easier
	u8 local_u8ColumnPorts[] = {KEYPAD_COLUMN0_PORT,KEYPAD_COLUMN1_PORT,KEYPAD_COLUMN2_PORT,KEYPAD_COLUMN3_PORT};
	u8 local_u8ColumnPins [] = {KEYPAD_COLUMN0_PIN,KEYPAD_COLUMN1_PIN,KEYPAD_COLUMN2_PIN,KEYPAD_COLUMN3_PIN};
	u8 local_u8RowPorts   [] = {KEYPAD_ROW0_PORT,KEYPAD_ROW1_PORT,KEYPAD_ROW2_PORT,KEYPAD_ROW3_PORT};
	u8 local_u8RowPins    [] = {KEYPAD_ROW0_PIN,KEYPAD_ROW1_PIN,KEYPAD_ROW2_PIN,KEYPAD_ROW3_PIN};
	
	
	u8 local_u8KeypadKeys[4][4] = KEYPAD_KEYS;  
	u8 local_u8PinValue;
	for(u8 local_u8ColumnsCounter = 0;local_u8ColumnsCounter<4;++local_u8ColumnsCounter){
		DIO_voidSetPinValue(local_u8ColumnPorts[local_u8ColumnsCounter],local_u8ColumnPins[local_u8ColumnsCounter],DIO_LOW);
		
		for(u8 local_u8RowsCounter = 0;local_u8RowsCounter<4;++local_u8RowsCounter){
			DIO_voidGetPinValue(local_u8RowPorts[local_u8RowsCounter],local_u8RowPins[local_u8RowsCounter],&local_u8PinValue);
			//if a key is pressed
			if(local_u8PinValue == 0){
				//while key is holden 
				while(local_u8PinValue == 0){
					DIO_voidGetPinValue(local_u8RowPorts[local_u8RowsCounter],local_u8RowPins[local_u8RowsCounter],&local_u8PinValue);		
				}
				//return corresponding character
				*copy_pu8pressedKey = local_u8KeypadKeys[local_u8RowsCounter][local_u8ColumnsCounter];
				//terminate the function
				return;
			}
			
		}
		DIO_voidSetPinValue(local_u8ColumnPorts[local_u8ColumnsCounter],local_u8ColumnPins[local_u8ColumnsCounter],DIO_HIGH);
	}
	
}


	