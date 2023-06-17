/*
 * main.c
 *
 *  Created on: May 27, 2023
 *      Author: aaa
 */
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/UART/UART_Interface.h"
//#include "INTERNAL_EEPROM.h"
#include <avr/eeprom.h>
#include "PhoneList/PhoneList.h"
#include "../HAL/LCD/TopWayLCD_Interface.h"
#include "avr/delay.h"

int main(void)
{
	 UART_Init();
	 LCD_Init();
	 u8 Num_size = 0;
	 u8 *valid = "Valid Number";
	 u8 *Invalid = "InValid Number";
	 u8 *ptr = "";

	 while(1)
	 {
		 Num_size=0;
		for(u8 i=0; i<=200; i++)
		{
			LCD_SendNum16(0x00080000,i);
			LCD_SendNum16(0x00080002,200-i);
		}

		u8* data = "";
		LCD_GetString(0x00000080,data);
		ptr = data;
		if(data[0] == '0' && data[1] == '1')
		{
			while(*data != '\0')
			{
				Num_size++;
				data++;
			}
			if(Num_size == 11)
			{
				LCD_SendNum16(0x00080004,Num_size);
				LCD_SendString(0x00000100,valid);

				Add_to_eeprom(ptr);
//				print_numbers();
//				UART_SendStringSync(ptr);
				//u8 * mesg = "Hello CodeCrafters";
				//UART_voidDisable();
				//SIM_SendSMS(ptr,"Hello CodeCrafters");
				LCD_SendString(0x00000080,"\0");
			}
			else
			{
				LCD_SendString(0x00000100,Invalid);
			}

		}
		else
		{
			LCD_SendString(0x00000100,Invalid);
		}

	 }

	 return 0;
}
