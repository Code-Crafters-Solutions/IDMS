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

int main(void)
{
	 UART_Init();
	 LCD_Init();
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
	 while(1)
	 {
		 Num_size=0;
		for(u8 i=0; i<=200; i++)
		{
			LCD_SendNum16(In,i);
			LCD_SendNum16(Out,200-i);
			LCD_SendNum16(In_Num,i-50);
			LCD_SendNum16(Out_Num,(200-i)-50);
		}

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
			list = LCD_GetNum16(List);
			if(list == 1)
			{
				calling_Array[calling_size] = ptr;
				p = (u8*)calling_Array[calling_size];
				LCD_SendString(Phone,p);
				LCD_SendString(Calling_List + (128*calling_size), p);
				LCD_SendNum16(0x0008000C,list);//test
				calling_size++;
			}else if(list == 2)
			{
				sms_Array[sms_size] = ptr;
				p = (u8*)sms_Array[sms_size];
				LCD_SendString(Phone,p);
				p = (u8*)sms_Array[sms_size];
				LCD_SendString(SMS_List + (128*sms_size) , p);
				LCD_SendNum16(0x0008000C,list);//test
				sms_size++;
			}
			LCD_SendNum16(Add,0);
			LCD_SendNum16(Clear_BUFF,1);
			valid_phone = 0;
		}
		else if(valid_phone && LCD_GetNum16(Remove))
		{

		}

//		u8* t = (u8*)calling_Array[0];
////		u8* tt = (u8*)calling_Array[1];
////		u8* ttt = (u8*)calling_Array[2];
//		LCD_SendString(Calling_List , t);
//
//		t = (u8*)calling_Array[1];
//		LCD_SendString(Calling_List + 128, t);
//
//		t = (u8*)calling_Array[2];
//		LCD_SendString(Calling_List +(128*2), t);

//		for(u8 i =0 ; i<calling_size ; i++)
//		{
//			//u8* p = (u8*)calling_Array[i];
//			LCD_SendString(Calling_List + (128*i) , p);
//		}


	 }

	 return 0;
}
