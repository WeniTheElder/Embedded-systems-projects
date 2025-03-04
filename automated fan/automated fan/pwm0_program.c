/*
 * pwm0_program.c
 *
 * Created: 3/1/2025 10:22:17 PM
 *  Author: Ahmad abdullatif
 */
#include "std_types.h"
#include "bit_math.h"
#include "DIO_interface.h"
#include "pwm0_interface.h"
#include "pwm0_registers.h"


void PWM0_voidInit (){
	//set fast PWM mode
	SET_BIT(TCCR0_REGISTER,WGM00_BIT);
	SET_BIT(TCCR0_REGISTER,WGM01_BIT);
	//set PWM mode to non inverting
	SET_BIT  (TCCR0_REGISTER,COM01_BIT);
	CLEAR_BIT(TCCR0_REGISTER,COM00_BIT);
}
void PWM0_voidStart(u8 copy_u8DutyCycle){
	OCR0_REGISTER = (((copy_u8DutyCycle*256)/100)-1);
	
	//set prescaller to 64 & start timer
	SET_BIT  (TCCR0_REGISTER,CS00_BIT);
	SET_BIT  (TCCR0_REGISTER,CS01_BIT);
	CLEAR_BIT(TCCR0_REGISTER,CS02_BIT);
}
void PWM0_voidStop (){
	CLEAR_BIT(TCCR0_REGISTER,CS00_BIT);
	CLEAR_BIT(TCCR0_REGISTER,CS01_BIT);
	CLEAR_BIT(TCCR0_REGISTER,CS02_BIT);
}
