/*
 * pwm0_registers.h
 *
 * Created: 3/1/2025 10:21:42 PM
 *  Author: Ahmad abdullatif
 */


#ifndef PWM0_REGISTERS_H_
#define PWM0_REGISTERS_H_

#define TCCR0_REGISTER (*(volatile u8*)0x53)
#define FOC0_BIT  7
#define WGM00_BIT 6
#define COM01_BIT 5
#define COM00_BIT 4
#define WGM01_BIT 3
#define CS02_BIT  2
#define CS01_BIT  1
#define CS00_BIT  0

#define TCNT0_REGISTER (*(volatile u8*)0x52)

#define OCR0_REGISTER  (*(volatile u8*)0x5C)

#define TIMSK_REGISTER (*(volatile u8*)0x59)
#define OCIE0_BIT 1
#define TOIE0_BIT 0

#define TIFR_REGISTER  (*(volatile u8*)0x58)
#define OCF0_BIT  1
#define TOV0_BIT  1

#define SFIOR_REGISTER (*(volatile u8*)0x50)
#define PSR10_BIT 0



#endif /* PWM0_REGISTERS_H_ */
