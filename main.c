/*
 * main.c
 *
 *  Created on: May 27, 2023
 *      Author: aaa
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "UART_Interface.h"
//#include "INTERNAL_EEPROM.h"
#include <avr/eeprom.h>
#include "PhoneList.h"
#include "TopWayLCD_Interface.h"
#include "avr/delay.h"
#include "LCD_Interface.h"
#include "KEYPAD_Interface.h"

int main(void)
{
	DIO_INIT();
	UART_Init();

	List L;
	List L2;
	CreateList(&L);
	AddNodeAtLast(&L,"1024912688",1);
	AddNodeAtLast(&L,"1156751790",2);
	AddNodeAtLast(&L,"1234567890",1);
	PrintList(&L);
	_delay_ms(500);

	StoreListToEEPROM(&L);
	_delay_ms(1000);
	ReadListFromEEPROM(&L2);
	_delay_ms(1000);

	PrintList(&L2);
	 while(1)
	 {
		 u8 Num[10];
		 u8 i = 0;
		 while(i < 10)
		 {
			 if(KEYPAD_GetKeyPressed() != 0)
			 {
				 Num[i] = KEYPAD_GetKeyPressed();
			 	 i++;
			 	 LCD_WriteCharacter(Num[i]);
			 }
		 }
//		 const u8* phon = Num;
//		 AddNumToEEPROM(phon);
//		 u8 eeprom_data[10] = "01156751790";
//		 for (u8 i = 0; i < 10; i++)
//		 {
//			 eeprom_data[i] = eeprom_read_byte((u8*) i);
//		 }
		 LCD_WriteInstruction(LCD_Clear);
		 LCD_WriteString(Num);

	 }

	 return 0;
}
