/*
 * pwm1_interface.h
 *
 * Created: 3/3/2025 2:03:36 AM
 *  Author: Ahmad abdullatif
 */


#ifndef PWM1_INTERFACE_H_
#define PWM1_INTERFACE_H_

#define PWM1_TIMER1_FREQUENCY 250000UL


void PWM1_voidInit ();
void PWM1_voidStart(f32 copy_f32DutycycleValue,u16 copy_u16PWMfrequency);
void PWM1_voidStop ();




#endif /* PWM1_INTERFACE_H_ */
