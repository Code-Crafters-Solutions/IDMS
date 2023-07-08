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
#include "ADC_Interface.h"
#include "ADC_Config.h"
#include "LM35_Interface.h"
int main(void)
{
	 UART_Init();
	 LCD_Init();
	 ADC_VidINIT();
	 u8 Num_size = 0;
	 u8 *valid = "Valid Number";
	 u8 *Invalid = "InValid Number";
	 u8 *ptr = "";
	 u8 valid_phone = 0;
	 u8* data = "";
	 u8 list;
	 u8* calling_Array[20] = {"01063482890","01077777777","01000000000"};
	 u8* sms_Array[20];
	 static u8 calling_size = 0;
	 u8 sms_size = 0;
	 u8* p = "";
	 u8* pp = "";
	 u16 ADC_Result1=0;
	 u16 ADC_Result2=0;
	 u8* clear = " ";

	 /*Creating phone list*/
	List L;
	CreateList(&L);
	//_delay_ms(500);

	for(u8 i =0; i < (27*2); i++)
	{
		LCD_SendString(CList_address + (128*i) ,clear);
	}
	ReadListFromEEPROM(&L);
	 while(1)
	 {
		 Num_size=0;
		 /*Just for test */
		for(u8 i=0; i<=200; i++)
		{
			LCD_SendNum16(In,i);
			LCD_SendNum16(Out,200-i);
			LCD_SendNum16(In_Num,i-50);
			LCD_SendNum16(Out_Num,(200-i)-50);
		}
//		PT100_ReadTemperture(ADC0,&ADC_Result1);
//		PT100_ReadTemperture(ADC1,&ADC_Result2);
//		LCD_SendNum16(In,ADC_Result1+50);
//		LCD_SendNum16(Out,ADC_Result1+50);
//		LCD_SendNum16(In_Num,ADC_Result1);
//		LCD_SendNum16(Out_Num,ADC_Result2);

		data = "";
		LCD_GetString(0x00000000,data);
		ptr = data;

		/*Phone Number Validation*/
		if(data[0] == '0' && data[1] == '1')
		{
			while(*data != '\0')
			{
				Num_size++;
				data++;
			}
			if(Num_size == 11)
			{
				//LCD_SendNum16(0x00080004,Num_size);
				LCD_SendString(Validation,valid);
				valid_phone = 1;
			}
			else
			{
				LCD_SendString(Validation,Invalid);
				LCD_SendNum16(Add,0);
			}
		}
		else
		{
			LCD_SendString(Validation,Invalid);
			LCD_SendNum16(Add,0);
		}

		/*Checking if user press ADD button and insert the number to its correct list*/
		if(valid_phone && LCD_GetNum16(Add))
		{
			list = LCD_GetNum16(L_type);
			if(list == Calling_list)
			{
				LCD_SendString(Phone,ptr);
				LCD_SendNum16(0x0008000C,list);//just for test
				AddNodeAtLast(&L,ptr,list);

			}else if(list == SMS_list)
			{
				LCD_SendString(Phone,ptr);
				LCD_SendNum16(0x0008000C,list);//just for test
				AddNodeAtLast(&L,ptr,list);
			}

			LCD_SendNum16(Add,0);
			LCD_SendNum16(Clear_BUFF,1);
			valid_phone = 0;
			StoreListToEEPROM(&L);
		}
		else if(valid_phone && LCD_GetNum16(Remove)) /*Checking if user want to remove specific number and remove it*/
		{
			Delete(ptr,&L);
			LCD_SendNum16(Remove,0);
			LCD_SendNum16(Clear_BUFF,1);
			valid_phone = 0;
			StoreListToEEPROM(&L);

			LCD_SendString(CList_address ,clear);
			for(u8 i =0; i < (27*2); i++)
			{
				LCD_SendString(CList_address + (128*i) ,clear);
			}
		}

		PrintList(&L,CList_address , SList_address);
	 }

	 return 0;
}
