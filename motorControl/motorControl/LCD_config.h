/*
 * LCD_config.h
 *
 * Created: 2/14/2025 5:32:40 AM
 *  Author: Ahmad abdullatif
 */


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_
#include "DIO_interface.h"

//macros for data pins
#define LCD_DB4_PORT    DIO_PORTA
#define LCD_DB4_PIN     DIO_PIN3
#define LCD_DB5_PORT    DIO_PORTA
#define LCD_DB5_PIN     DIO_PIN4
#define LCD_DB6_PORT    DIO_PORTA
#define LCD_DB6_PIN     DIO_PIN5
#define LCD_DB7_PORT    DIO_PORTA
#define LCD_DB7_PIN     DIO_PIN6

//macros for control pins
#define LCD_RS_PORT     DIO_PORTA
#define LCD_RS_PIN      DIO_PIN0
#define LCD_RW_PORT     DIO_PORTA
#define LCD_RW_PIN      DIO_PIN1
#define LCD_ENABLE_PORT DIO_PORTA
#define LCD_ENABLE_PIN  DIO_PIN2

/*LCD settings*/

//0-> 4-bit mode   1-> 8-bit mode 
#define LCD_DATA_LENGTH 0

//0-> 1 line       1-> 2 lines
#define LCD_NUMBER_OF_DISPLAY_LINES 1

//0-> cursor off   1-> cursor on
#define LCD_CURSOR 0

//0-> blinking off 1-> blinking on
#define LCD_CURSOR_BLINKING 0

//0-> 5*8 font     1-> 5*11 font
#define LCD_FONT_TYPE 0



#endif /* LCD_CONFIG_H_ */
