/*
 * PhoneList,.c
 *
 *  Created on: Jun 8, 2023
 *      Author: Abdelrahman Hegazy
 */

#include<stdlib.h>
#include "avr/delay.h"
#include "../../LIB/STD_TYPES.h"
#include "PhoneList.h"
#include <avr/eeprom.h>
#include "../../MCAL/UART/UART_Interface.h"

u8 size=0;
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

