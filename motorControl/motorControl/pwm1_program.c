/*
 * pwm1_program.c
 *
 * Created: 3/3/2025 2:03:26 AM
 *  Author: Ahmad abdullatif
 */
#include "std_types.h"
#include "bit_math.h"
#include "pwm1_interface.h"
#include "pwm1_registers.h"

void PWM1_voidInit(){
	//setting non inverting mode and PWM output on pin OC1A
	CLEAR_BIT(TCCR1A_REGISTER,COM1A0_BIT);
	SET_BIT  (TCCR1A_REGISTER,COM1A1_BIT);
	//choosing fast PWM with top value of ICR1 (mode 14 in data sheet)
	CLEAR_BIT(TCCR1A_REGISTER,WGM10_BIT);
	SET_BIT  (TCCR1A_REGISTER,WGM11_BIT);
	SET_BIT  (TCCR1B_REGISTER,WGM12_BIT);
	SET_BIT  (TCCR1B_REGISTER,WGM13_BIT);
}
void PWM1_voidStart(f32 copy_f32DutycycleValue,u16 copy_u16PWMfrequency){
	//set frequency
	ICR1_REGISTER  = (PWM1_TIMER1_FREQUENCY/copy_u16PWMfrequency)-1;
	//set duty cycle
	OCR1A_REGISTER = (copy_f32DutycycleValue*(ICR1_REGISTER+1)/100)-1;
	//set prescaller to 1024
	SET_BIT  (TCCR1B_REGISTER, CS10_BIT );
	SET_BIT  (TCCR1B_REGISTER, CS11_BIT );
	CLEAR_BIT(TCCR1B_REGISTER, CS12_BIT); 
}
void PWM1_voidStop (){
	CLEAR_BIT(TCCR1B_REGISTER, CS10_BIT);
	CLEAR_BIT(TCCR1B_REGISTER, CS11_BIT);
	CLEAR_BIT(TCCR1B_REGISTER, CS12_BIT);
}