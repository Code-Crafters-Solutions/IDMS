/*
 * PhoneList,.c
 *
 *  Created on: Jun 8, 2023
 *      Author: Abdelrahman Hegazy
 */

#include<stdlib.h>
#include "avr/delay.h"
#include "STD_TYPES.h"
#include "PhoneList.h"
#include <avr/eeprom.h>
#include "UART_Interface.h"

PhoneNum * head = NULL;

u8 CurrentLocation = 0;
u8 size = 0;
void PhoneList_ADD(u8 * Phonenum)
{
	//Step 1===>Create Node
	PhoneNum * Temp = (PhoneNum*)malloc(sizeof(PhoneNum));
	//Step 2===>init value of the created node with the input function
	Temp->Number = Phonenum;
	Temp->Location = CurrentLocation;
	CurrentLocation += sizeof(PhoneNum);
	//Step 3===>created node =>node implemented in head
	Temp->Next=head;
	//Head =Temp
	head=Temp;
}



void Add_to_eeprom(u8 * Num)
{
	u8 i=0;
	while(i<=11)
	{
		eeprom_write_byte((u8 *)(size),Num[i]);
		size++;
		i++;
		_delay_ms(10);
	}
}

void print_numbers(void)
{
	for(u8 i = 0; i<size ;i++)
	{
			UART_SendByteSynch(eeprom_read_byte(i));
	}
}
