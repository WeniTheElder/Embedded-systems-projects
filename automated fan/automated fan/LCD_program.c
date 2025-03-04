/*
 * LCD_program.c
 *
 * Created: 2/14/2025 5:32:20 AM
 *  Author: Ahmad abdullatif
 */
#define F_CPU 16000000UL
#include "std_types.h"
#include "DIO_interface.h"
#include <util/delay.h>
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"
#include "bit_math.h"


//private functions
void PRV_voidLcdEnable(void){
	DIO_voidSetPinValue(LCD_ENABLE_PORT,LCD_ENABLE_PIN,DIO_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_ENABLE_PORT,LCD_ENABLE_PIN,DIO_LOW);
}
void PRV_voidWriteHalfPort(u8 copy_u8Data){
	DIO_voidSetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(copy_u8Data,0));
	DIO_voidSetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(copy_u8Data,1));
	DIO_voidSetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(copy_u8Data,2));
	DIO_voidSetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(copy_u8Data,3));
}


//public functions
void LCD_voidInit(void){
	DIO_voidSetPinDirection(LCD_ENABLE_PORT,LCD_ENABLE_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_RS_PORT,LCD_RS_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_RW_PORT,LCD_RW_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_D4_PORT,LCD_D4_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_D5_PORT,LCD_D5_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_D6_PORT,LCD_D6_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_D7_PORT,LCD_D7_PIN,DIO_OUTPUT);
	
	_delay_ms(40);
	
	DIO_voidSetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_LOW);
	DIO_voidSetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_LOW);
	PRV_voidWriteHalfPort(0b0010);
	PRV_voidLcdEnable();
	LCD_voidSendCommand(0b00101000);
	
	_delay_us(45);
	
	LCD_voidSendCommand(0B00001111);
	
	_delay_us(45);
	
	LCD_voidSendCommand(0B00000001);
	
	_delay_ms(2);
	
	LCD_voidSendCommand(0B00000110);
	
	
}
void LCD_voidSendCommand(u8 copy_u8Command){
	//setting RS to command register and RW to write
	DIO_voidSetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_LOW);
	DIO_voidSetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_LOW);
	//sending MSB of data to the LCD
	PRV_voidWriteHalfPort(copy_u8Command>>4);
	//enabling LCD
	PRV_voidLcdEnable();
	//sending LSB of data to the LCD
	PRV_voidWriteHalfPort(copy_u8Command);
	//enabling LCD
	PRV_voidLcdEnable();
}
void LCD_voidDisplayChar(u8 copy_u8Data){
	//setting RS to Data register and RW to write
	DIO_voidSetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_HIGH);
	DIO_voidSetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_LOW);
	//sending MSB of data to the LCD
	PRV_voidWriteHalfPort(copy_u8Data>>4);
	//enabling LCD
	PRV_voidLcdEnable();
	//sending LSB of data to the LCD
	PRV_voidWriteHalfPort(copy_u8Data);
	//enabling LCD
	PRV_voidLcdEnable();
}
void LCD_voidDisplayString(u8* copy_u8Data){
	u8 local_u8Char = copy_u8Data[0];
	u8 local_u8pointer = 0;
	while(local_u8Char != '\0'){
		local_u8Char = copy_u8Data[local_u8pointer];
		LCD_voidDisplayChar(local_u8Char);
		++local_u8pointer;
	}	
}

void LCD_voidDisplayNumber(u32 copy_u32Number){
	u32 local_u32ReservedNumber = 1;
	if(copy_u32Number == 0){
		LCD_voidDisplayNumber('0');
	}
	else{
		while(copy_u32Number != 0){
			local_u32ReservedNumber *= 10;
			local_u32ReservedNumber += copy_u32Number%10;
			copy_u32Number /= 10;
		}
		while(local_u32ReservedNumber != 1){
			LCD_voidDisplayChar((local_u32ReservedNumber%10)+'0');
			local_u32ReservedNumber /=10;
		}
		return;
	}
}
void LCD_voidClearLCD(void){
	LCD_voidSendCommand(0b00000001);
	_delay_ms(2);
}

void LCD_voidMoveToLine2(void){
	LCD_voidSendCommand(0b11000000);
}

void LCD_voidTurnCursorOff(void){
	//turn off cursor
	LCD_voidSendCommand(0b00001100);
}
void LCD_voidTurnCursorOn(void){
	//turn on cursor
	LCD_voidSendCommand(0b00001111);
}
void LCD_voidShiftRight(u8 copy_u8NumberOfShifts){
	for(int i = 0;i < copy_u8NumberOfShifts;++i){
		LCD_voidSendCommand(0b00011100);
	}
}
void LCD_voidTurnBlinkingOn(void){
	LCD_voidSendCommand(0b00001111);
}
void LCD_voidTurnBlinkingOff(void){
	LCD_voidSendCommand(0b00001110);
}