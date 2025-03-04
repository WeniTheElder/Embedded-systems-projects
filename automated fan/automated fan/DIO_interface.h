/*
 * DIO_interface.h
 *
 * Created: 2/13/2025 5:30:25 AM
 *  Author: Ahmad abdullatif
 */


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


//Pins macros
#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

//Ports macros
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

//DIO macros
#define DIO_INPUT  0
#define DIO_OUTPUT 1
#define DIO_LOW    0
#define DIO_HIGH   1
 
//DIO API's
void DIO_voidSetPinDirection(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8DataDirection);
void DIO_voidSetPinValue    (u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8PinValue);
void DIO_voidTogglePinValue (u8 copy_u8PortId,u8 copy_u8PinId);
void DIO_voidGetPinValue    (u8 copy_u8PortId,u8 copy_u8PinId,u8* copy_pu8InputValue);




#endif /* DIO_INTERFACE_H_ */
