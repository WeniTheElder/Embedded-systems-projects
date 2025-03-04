/*
 * LCD_interface.h
 *
 * Created: 2/14/2025 5:32:08 AM
 *  Author: Ahmad abdullatif
 */


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "std_types.h"


//APIs prototypes
void LCD_voidSendCommand    (u8 copy_u8Command);
void LCD_voidDisplayChar    (u8 copy_u8Data);
void LCD_voidDisplayString  (u8* copy_u8Data);
void LCD_voidInit           (void);
void LCD_voidDisplayNumber  (u32 copy_u32Number);
void LCD_voidClearLCD       (void);
void LCD_voidMoveToLine2    (void);
void LCD_voidTurnCursorOff  (void);
void LCD_voidTurnCursorOn   (void);
void LCD_voidShiftRight     (u8 copy_u8NumberOfShifts);
void LCD_voidTurnBlinkingOn (void);
void LCD_voidTurnBlinkingOff(void);
#endif /* LCD_INTERFACE_H_ */