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
#define EEPROM_START_ADDRESS 0x00  // The starting address of the EEPROM to write to
#define EEPROM_END_ADDRESS (EEPROM_START_ADDRESS + 1023)  // The last address to write to
#define EEPROM_LAST_ADDRESS_ADDRESS 0x0A  // The address of the last used address in the EEPROM

u8 CurrentLocation = 0;
u8 current_address = 0;




void AddNumToEEPROM(const u8* data)
{
    u8 last_address = eeprom_read_byte((u8*)EEPROM_LAST_ADDRESS_ADDRESS);
    if (last_address == 0xFF)
    {
        last_address = EEPROM_START_ADDRESS; // No data written yet, start from the beginning
    }
    u8 address = last_address + 1;
    u8 end_address = address + 9;
    if (end_address > EEPROM_END_ADDRESS)
    {
        // Wrap around to the beginning of the EEPROM if we reach the end
        address = EEPROM_START_ADDRESS;
        end_address = address + 9;
    }
    while (address <= end_address && *data != '\0')
    {
        u8 stored_data = eeprom_read_byte((u8*)address);
        if (stored_data != *data)
        {
            eeprom_write_byte((u8*)address, *data);
            _delay_us(10);  // Wait for EEPROM write to complete
            u8 written_data = eeprom_read_byte((u8*)address);
            while (stored_data != written_data)
            {
                // Retry write until data is written correctly
                eeprom_write_byte((u8*)address, *data);
                _delay_us(10);  // Wait for EEPROM write to complete
                written_data = eeprom_read_byte((u8*)address);
            }
        }
        data++;
        address++;
    }
    eeprom_write_byte((u8*)EEPROM_LAST_ADDRESS_ADDRESS, end_address);
}


void CreateList(List* l)
{
	l->Head = NULL;
	l->size = 0;
}

void AddNodeAtLast(List* pl,u8* data, u8 SMSCALL)
{
	//Allocate Node at memory and return its pointer to pn.
	Node* pn = (Node*)malloc(sizeof(Node));
	//assin data to pointer
	for(u8 i = 0;i<10;i++)
	{
		pn->value[i] = data[i];
	}
	pn->SMSCALL = SMSCALL;
	pn->Next = NULL;

	if(pl->Head == NULL)
	{
		pl->Head = pn;
	}
	else
	{
		Node* current;
		current = pl->Head;
		while(current->Next != NULL)
		{
			current = current->Next;
		}
		current->Next = pn;
	}
	pl->size++;
}

void PrintList(List* pl)
{
	Node* current;
	current = pl->Head;
	if(current == NULL)
	{
		UART_SendStringSync("\n List Is Empty!\n\n");
	}
	else
	{
		while(current)
		{
			for(u8 i = 0;i<11;i++)
			{
				UART_SendByteSynch(current->value[i]);
			}
			UART_SendByteSynch(current->SMSCALL);
			UART_SendByteSynch('\n');
			current = current->Next;
		}
	}
}

u8 Delete(u8* Data,List* pl)
{
	u8 Data_copy_search[10];
	u8 Data_copy_head[10];

	u8 exist = 0;
	Node *pn,*qn;
	pn = pl->Head;
	qn = pl->Head;

	for(u8 i =0;i<10;i++)
		Data_copy_search[i]=Data[i];

	for(u8 i =0;i<10;i++)
		Data_copy_head[i]=pl->Head->value[i];

	if(strstr(Data_copy_search, Data_copy_head))
	{
		exist = 1;
		pl->Head = pn->Next;
		free(pn);
		return 0;
	}


	if(pn == NULL)
	{
		printf("\n List Is Empty!\n\n");
	}


	while(pn != NULL)
	{
		u8 Data_copy2[10];
		for(u8 i =0;i<10;i++)
			Data_copy2[i]=pn->value[i];
		if(strstr(Data_copy2, Data_copy_search))
		{
			exist = 1;
			qn->Next = pn->Next;
			free(pn);
			break;
		}
		qn = pn;
		pn = pn->Next;
	}
	if(exist == 0)
		printf("There is Not element You Entered!\n");

	return 0;
}

void RetrieveElement(u8* pe,const u8* Data,List* pl)
{
	u8 copy_data[10];
	u8 copy_head[10];
	Node* pn = pl->Head;
	u8 *ptr;
	u8 exist = 0;
	for(u8 i = 0; i<10 ; i++)
	{
		copy_data[i] = Data[i];
		copy_head[i] = pn->value[i];
	}


	if(strstr(copy_data, copy_head))
	{
		exist = 1;
		for(u8 i =0;i<10;i++)
		{
			pe[i] = pn->value[i];
		}
	}

	while(pn != NULL && exist == 0)
	{
		for(u8 i = 0; i<10 ; i++)
			copy_head[i] = pn->value[i];

		if(strstr(copy_data ,copy_head))
		{
			exist = 1;
			for(u8 i =0;i<10;i++)
			{
				pe[i] = pn->value[i];
			}
			break;
		}
		pn = pn->Next;
	}
	if(exist == 0)
	{
		pe = "0";
	}
}


void StoreListToEEPROM(List* l)
{
	Node* pn = l->Head;
	while(pn->Next != NULL)
	{
		eeprom_write_block((const void*)&(pn->value),(void*)current_address,(11 * sizeof(u8)));
		current_address+= (11 * sizeof(u8));
		eeprom_write_byte(current_address,pn->SMSCALL);
		current_address++;
		pn = pn->Next;
	}
	eeprom_write_byte(current_address,'N');

}


void ReadListFromEEPROM(List* l)
{
	u8 EndList;
	EndList = eeprom_read_byte((const u8*)current_address);
	while(EndList != 'N')
	{
		u8 Value[11];
		eeprom_read_block((void*)Value,(const void*)current_address,(11 * sizeof(u8)));
		current_address+= (11 * sizeof(u8));
		u8 SMSCALL = eeprom_read_byte((const u8*)current_address);
		current_address++;
		AddNodeAtLast(l,Value,SMSCALL);
		EndList = eeprom_read_byte((const u8*)current_address);
	}


}
