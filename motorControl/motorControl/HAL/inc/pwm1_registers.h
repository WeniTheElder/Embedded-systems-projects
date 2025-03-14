/*
 * pwm1_registers.h
 *
 * Created: 3/3/2025 2:03:46 AM
 *  Author: Ahmad abdullatif
 */


#ifndef PWM1_REGISTERS_H_
#define PWM1_REGISTERS_H_


#define TCCR1A_REGISTER (*(volatile u8*)0x4F)
#define COM1A1_BIT 7
#define COM1A0_BIT 6
#define COM1B1_BIT 5
#define COM1B0_BIT 4
#define FOC1A_BIT  3
#define FOC1B_BIT  2
#define WGM11_BIT  1
#define WGM10_BIT  0

#define TCCR1B_REGISTER (*(volatile u8*)0x4E)
#define ICNC1_BIT  7
#define ICES1_BIT  6
#define WGM13_BIT  4
#define WGM12_BIT  3
#define CS12_BIT   2
#define CS11_BIT   1
#define CS10_BIT   0

#define TCNT1_REGISTER  (*(volatile u16*)0x4C)

#define OCR1A_REGISTER  (*(volatile u16*)0x4A)

#define OCR1B_REGISTER  (*(volatile u16*)0x48)

#define ICR1_REGISTER   (*(volatile u16*)0x46)


#define TIMSK_REGISTER  (*(volatile u8*)0x59)
#define TICIE_BIT  5
#define OCIE1A_BIT 4
#define OCIE1B_BIT 3
#define TOIE1_BIT  2

#define TIFR_REGISTER   (*(volatile u8*)0x58)
#define ICF1_BIT   5
#define OCF1A_BIT  4
#define OCF1B_BIT  3
#define TOV1_BIT   2



#endif /* PWM1_REGISTERS_H_ */
