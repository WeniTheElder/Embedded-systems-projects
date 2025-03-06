/*
 * DIO_program.c
 *
 * Created: 2/13/2025 5:30:11 AM
 *  Author: Ahmad abdullatif
 */
#include "std_types.h"
#include "bit_math.h"
#include "DIO_interface.h"
#include "DIO_registers.h"


void DIO_voidSetPinDirection(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8DataDirection){
	switch(copy_u8PortId){
		case DIO_PORTA:
		if(copy_u8DataDirection == DIO_OUTPUT){
			SET_BIT(DDRA_REGISTER,copy_u8PinId);
		}
		else{
			CLEAR_BIT(DDRA_REGISTER,copy_u8PinId);
		}
		break;
		case DIO_PORTB:
		if(copy_u8DataDirection == DIO_OUTPUT){
			SET_BIT(DDRB_REGISTER,copy_u8PinId);
		}
		else{
			CLEAR_BIT(DDRB_REGISTER,copy_u8PinId);
		}
		break;
		case DIO_PORTC:
		if(copy_u8DataDirection == DIO_OUTPUT){
			SET_BIT(DDRC_REGISTER,copy_u8PinId);
		}
		else{
			CLEAR_BIT(DDRC_REGISTER,copy_u8PinId);
		}
		break;
		case DIO_PORTD:
		if(copy_u8DataDirection == DIO_OUTPUT){
			SET_BIT(DDRD_REGISTER,copy_u8PinId);
		}
		else{
			CLEAR_BIT(DDRD_REGISTER,copy_u8PinId);
		}
		break;
		
	}
}
void DIO_voidSetPinValue(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8PinValue){
	switch(copy_u8PortId){
		case DIO_PORTA:
		if(copy_u8PinValue == DIO_HIGH){
			SET_BIT(PORTA_REGISTER,copy_u8PinId);
		}
		else{
			CLEAR_BIT(PORTA_REGISTER,copy_u8PinId);
		}
		break;
		case DIO_PORTB:
		if(copy_u8PinValue == DIO_HIGH){
			SET_BIT(PORTB_REGISTER,copy_u8PinId);
		}
		else{
			CLEAR_BIT(PORTB_REGISTER,copy_u8PinId);
		}
		break;
		case DIO_PORTC:
		if(copy_u8PinValue == DIO_HIGH){
			SET_BIT(PORTC_REGISTER,copy_u8PinId);
		}
		else{
			CLEAR_BIT(PORTC_REGISTER,copy_u8PinId);
		}
		break;
		case DIO_PORTD:
		if(copy_u8PinValue == DIO_HIGH){
			SET_BIT(PORTD_REGISTER,copy_u8PinId);
		}
		else{
			CLEAR_BIT(PORTD_REGISTER,copy_u8PinId);
		}
		break;
	}
}
void DIO_voidTogglePinValue(u8 copy_u8PortId,u8 copy_u8PinId){
	switch(copy_u8PortId){
		case DIO_PORTA:
		TOGGLE_BIT(PORTA_REGISTER,copy_u8PinId);
		break;
		case DIO_PORTB:
		TOGGLE_BIT(PORTB_REGISTER,copy_u8PinId);
		break;
		case DIO_PORTC:
		TOGGLE_BIT(PORTC_REGISTER,copy_u8PinId);
		break;
		case DIO_PORTD:
		TOGGLE_BIT(PORTD_REGISTER,copy_u8PinId);
		break;
	}
}
void DIO_voidGetPinValue(u8 copy_u8PortId,u8 copy_u8PinId,u8* copy_pu8InputValue){
	switch(copy_u8PortId){
		case DIO_PORTA:
		*copy_pu8InputValue = GET_BIT(PINA_REGISTER,copy_u8PinId);
		break;
		case DIO_PORTB:
		*copy_pu8InputValue = GET_BIT(PINB_REGISTER,copy_u8PinId);
		break;
		case DIO_PORTC:
		*copy_pu8InputValue = GET_BIT(PINC_REGISTER,copy_u8PinId);
		break;
		case DIO_PORTD:
		*copy_pu8InputValue = GET_BIT(PIND_REGISTER,copy_u8PinId);
		break;
	}
}