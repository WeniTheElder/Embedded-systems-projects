/*
 * LCD_program.c
 *
 * Created: 2/14/2025 5:32:20 AM
 *  Author: Ahmad abdullatif
 */
#define F_CPU 16000000UL
#include <util/delay.h>
#include "std_types.h"
#include "bit_math.h"
#include "DIO_interface.h"
#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"

void PRIV_voidSendHalfData(u8 copy_u8Data){
	DIO_voidSetPinValue(LCD_DB4_PORT,LCD_DB4_PIN,GET_BIT(copy_u8Data,0));
	DIO_voidSetPinValue(LCD_DB5_PORT,LCD_DB5_PIN,GET_BIT(copy_u8Data,1));
	DIO_voidSetPinValue(LCD_DB6_PORT,LCD_DB6_PIN,GET_BIT(copy_u8Data,2));
	DIO_voidSetPinValue(LCD_DB7_PORT,LCD_DB7_PIN,GET_BIT(copy_u8Data,3));
	PRIV_voidEnable();
}
void PRIV_voidEnable(void){
	DIO_voidSetPinValue(LCD_ENABLE_PORT,LCD_ENABLE_PIN,DIO_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_ENABLE_PORT,LCD_ENABLE_PIN,DIO_LOW);
}
void PRIV_voidSendCommand (u8 copy_u8Command){
	DIO_voidSetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_LOW);
	PRIV_voidSendHalfData(copy_u8Command>>4);
	PRIV_voidSendHalfData(copy_u8Command);
}
void LCD_voidInit(void){
	u8 local_u8InitVar;
	//initializing data pins
	DIO_voidSetPinDirection(LCD_DB4_PORT,LCD_DB4_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_DB5_PORT,LCD_DB5_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_DB6_PORT,LCD_DB6_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_DB7_PORT,LCD_DB7_PIN,DIO_OUTPUT);
	//initializing control pins
	DIO_voidSetPinDirection(LCD_RS_PORT,LCD_RS_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_RW_PORT,LCD_RW_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_ENABLE_PORT,LCD_ENABLE_PIN,DIO_OUTPUT);
	//setting RS to command, RW to read
	DIO_voidSetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_LOW);
	DIO_voidSetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_LOW);
	_delay_ms(40);
	
	/*initializing routine*/
	
	//function set
	PRIV_voidSendCommand(0b00100010);
	local_u8InitVar = 0;
	#if LCD_NUMBER_OF_DISPLAY_LINES == 1
	SET_BIT(local_u8InitVar,3);
	#endif
	#if LCD_FONT_TYPE == 1
	SET_BIT(local_u8InitVar,2);
	#endif
	PRIV_voidSendHalfData(local_u8InitVar);
	_delay_us(50);
	
	//display on-off control
	local_u8InitVar = 0b00001111;
	#if LCD_CURSOR == 0
	CLEAR_BIT(local_u8InitVar,1);
	#endif
	#if LCD_CURSOR_BLINKING == 0
	CLEAR_BIT(local_u8InitVar,0);
	#endif
	PRIV_voidSendCommand(local_u8InitVar);
	_delay_us(50);
	
	//display clear
	local_u8InitVar = 1;
	PRIV_voidSendCommand(local_u8InitVar);
	_delay_ms(2);
	
	//entry mode set
	local_u8InitVar = 0b00000110;
	PRIV_voidSendCommand(local_u8InitVar);
}
void LCD_voidDisplayCharacter(u8 copy_u8char){
	DIO_voidSetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_HIGH);
	PRIV_voidSendHalfData(copy_u8char>>4);
	PRIV_voidSendHalfData(copy_u8char);
}
void LCD_voidShiftDisplayLeft(u8 copy_u8NumberOfShits){
	for(u8 i = 0;i<copy_u8NumberOfShits;++i){
		PRIV_voidSendCommand(0b00011000);
	}
}
void LCD_voidDisplayString(u8 copy_pu8string[]){
	u8 local_u8currentChar = copy_pu8string[0];
	u8 local_u8currentCharindex = 0;
	while(local_u8currentChar != '\0'){
		LCD_voidDisplayCharacter(local_u8currentChar);
		++local_u8currentCharindex;
		local_u8currentChar = copy_pu8string[local_u8currentCharindex];
	}
}
void LCD_voidMoveToSecondLine(void){
	PRIV_voidSendCommand(0b11000000);	
}
void LCD_voidClearDisplay(void){
	PRIV_voidSendCommand(0b0000001);
}
