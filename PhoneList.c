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


u8 current_address = 0;

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
	for(u8 i = 0;i<11;i++)
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

	Node* iterator = pl->Head;
	while(iterator != NULL)
	{

		eeprom_write_block((const void*) iterator->value,(void*)current_address,(11 * sizeof(u8)));
		current_address+= (11 * sizeof(u8));
		eeprom_write_byte(current_address,iterator->SMSCALL);
		current_address++;
		iterator = iterator->Next;
	}
}

void PrintList(List* pl)
{
	u8 size = pl->size;
	Node* current;
	current = pl->Head;
	if(current == NULL)
	{
		UART_SendStringSync("\n List Is Empty!\n\n");
	}
	else
	{
		while(size)
		{
			for(u8 i = 0;i<11;i++)
			{
				UART_SendByteSynch(current->value[i]);
			}
			UART_SendByteSynch(current->SMSCALL);
			UART_SendByteSynch('\n');
			current = current->Next;
			size--;
		}
	}

}

void Delete(u8* Data,List* pl)
{
	u8 Data_copy_search[11];
	u8 Data_copy_head[11];

	u8 exist = 0;
	u8 flag = 0;
	Node *pn,*qn;
	pn = pl->Head;
	qn = pl->Head;

	for(u8 i =0;i<11;i++)
		Data_copy_search[i]=Data[i];

	for(u8 i =0;i<11;i++)
		Data_copy_head[i]=pl->Head->value[i];

	for(u8 i=0;i<11;i++)
	{
	    if(Data_copy_search[i]==Data_copy_head[i])
	         flag=0;
	    else {flag=1; break;}
	}
	if(!flag)
	{
		exist = 1;
		pl->Head = pn->Next;
		free(pn);
		pl->size--;
	}


	if(pn == NULL)
	{
		UART_SendStringSync("\n List Is Empty!\n\n");
	}


	while(pn != NULL && exist != 1)
	{
		u8 Data_copy2[11];
		for(u8 i =0;i<11;i++)
			Data_copy2[i]=pn->value[i];

		for(u8 i=0;i<11;i++)
		{
		    if(Data_copy_search[i]==Data_copy2[i])
		         flag=0;
		    else {flag=1; break;}
		}

		if(!flag)
		{
			exist = 1;
			qn->Next = pn->Next;
			free(pn);
			pl->size--;
			break;
		}
		qn = pn;
		pn = pn->Next;
	}
	if(exist == 0)
		UART_SendStringSync("There is Not element You Entered!\n");

	Node* iterator = pl->Head;
	while(iterator != NULL)
	{

		eeprom_write_block((const void*) iterator->value,(void*)current_address,(11 * sizeof(u8)));
		current_address+= (11 * sizeof(u8));
		eeprom_write_byte(current_address,iterator->SMSCALL);
		current_address++;
		iterator = iterator->Next;
	}
}

void RetrieveElement(u8* pe,const u8* Data,List* pl)
{
	u8 copy_data[11];
	u8 copy_head[11];
	Node* pn = pl->Head;
	u8 *ptr;
	u8 exist = 0;
	u8 flag = 0;
	for(u8 i = 0; i<11 ; i++)
	{
		copy_data[i] = Data[i];
		copy_head[i] = pn->value[i];
	}

	for(u8 i=0;i<11;i++)
	{
	    if(copy_data[i]==copy_head[i])
	         flag=0;
	    else {flag=1; break;}
	}

	if(!flag)
	{
		exist = 1;
		for(u8 i =0;i<11;i++)
		{
			pe[i] = pn->value[i];
		}
	}

	while(pn != NULL && exist == 0)
	{
		for(u8 i = 0; i<11 ; i++)
			copy_head[i] = pn->value[i];

		for(u8 i=0;i<11;i++)
		{
		    if(copy_data[i]==copy_head[i])
		         flag=0;
		    else {flag=1; break;}
		}
		if(!flag)
		{
			exist = 1;
			for(u8 i =0;i<11;i++)
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
	while(pn != NULL)
	{

		eeprom_write_block((const void*) pn->value,(void*)current_address,(11 * sizeof(u8)));
		current_address+= (11 * sizeof(u8));
		eeprom_write_byte(current_address,pn->SMSCALL);
		current_address++;
		pn = pn->Next;
	}
	//eeprom_write_byte(current_address,'N');


}


void ReadListFromEEPROM(List* l,u8 ListSize)
{
	current_address = 0;

	while(ListSize != 0)
	{
		u8 Value[11];
		eeprom_read_block((const void*)Value,(const void*)current_address,(11 * sizeof(u8)));
		current_address+= (11 * sizeof(u8));
		u8 SMSCALL = eeprom_read_byte((const u8*)current_address);
		current_address++;
		AddNodeAtLast(l,Value,SMSCALL);
		ListSize--;
	}


}
