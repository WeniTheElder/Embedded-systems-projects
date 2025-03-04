/*
 * DIO_registers.h
 *
 * Created: 2/13/2025 5:30:42 AM
 *  Author: Ahmad abdullatif
 */


#ifndef DIO_REGISTERS_H_
#define DIO_REGISTERS_H_

#include "std_types.h"


#define PORTA_REGISTER   (*(volatile u8*)0x3B)
#define DDRA_REGISTER    (*(volatile u8*)0x3A)
#define PINA_REGISTER    (*(volatile u8*)0x39)

//PORTB
#define PORTB_REGISTER   (*(volatile u8*)0x38)
#define DDRB_REGISTER    (*(volatile u8*)0x37)
#define PINB_REGISTER    (*(volatile u8*)0x36)

//PORTC
#define PORTC_REGISTER   (*(volatile u8*)0x35)
#define DDRC_REGISTER    (*(volatile u8*)0x34)
#define PINC_REGISTER    (*(volatile u8*)0x33)

//PORTD
#define PORTD_REGISTER   (*(volatile u8*)0x32)
#define DDRD_REGISTER    (*(volatile u8*)0x31)
#define PIND_REGISTER    (*(volatile u8*)0x30)




#endif /* DIO_REGISTERS_H_ */
