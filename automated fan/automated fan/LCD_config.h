/*
 * LCD_config.h
 *
 * Created: 2/14/2025 5:32:40 AM
 *  Author: Ahmad abdullatif
 */


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

//RS macros
#define LCD_RS_PORT DIO_PORTC
#define LCD_RS_PIN  DIO_PIN0

//RW macros
#define LCD_RW_PORT DIO_PORTC
#define LCD_RW_PIN  DIO_PIN1

//Enable macros
#define LCD_ENABLE_PORT DIO_PORTC
#define LCD_ENABLE_PIN  DIO_PIN2

//Data port macros
#define LCD_D4_PORT DIO_PORTC
#define LCD_D5_PORT DIO_PORTC
#define LCD_D6_PORT DIO_PORTC
#define LCD_D7_PORT DIO_PORTC

//Data pins macros
#define LCD_D4_PIN  DIO_PIN3
#define LCD_D5_PIN  DIO_PIN4 
#define LCD_D6_PIN  DIO_PIN5
#define LCD_D7_PIN  DIO_PIN6

#endif /* LCD_CONFIG_H_ */