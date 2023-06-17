/*
 * TopWayLCD_Interface.h
 *
 *  Created on: Jun 7, 2023
 *      Author: Adel
 */

#ifndef TOPWAYLCD_INTERFACE_H_
#define TOPWAYLCD_INTERFACE_H_


void LCD_Init();

void LCD_SendNum16(u32 Copy_u32Address , u16 Copy_u16Num);

u16 LCD_GetNum16(u32 Copy_u32Address);

void LCD_SendString(u32 Copy_u32Address , u8 *Copy_u16Str );

void LCD_GetString(u32 Copy_u32Address , u8 *Ptr_ReturnStr);

#endif /* TOPWAYLCD_INTERFACE_H_ */
