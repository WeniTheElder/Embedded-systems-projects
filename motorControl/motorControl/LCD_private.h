/*
 * LCD_private.h
 *
 * Created: 2/14/2025 5:32:29 AM
 *  Author: Ahmad abdullatif
 */


#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

void PRIV_voidSendHalfData(u8 copy_u8Data);
void PRIV_voidEnable      (void);
void PRIV_voidSendCommand (u8 copy_u8Command);



#endif /* LCD_PRIVATE_H_ */
