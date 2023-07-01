/*
 * PhoneList.h
 *
 *  Created on: Jun 8, 2023
 *      Author: Abdelrahman Hegazy
 */

#ifndef PHONELIST_H_
#define PHONELIST_H_

typedef struct
{
	u8  * Number;
	u8 Location;
	struct PhoneNum * Next;

}PhoneNum;

typedef struct Node
{
	u8 value[11];
	u8 SMSCALL;
	struct Node* Next;
}Node;

typedef struct List
{
	Node* Head;
	u16 size;
}List;

void CreateList(List* l);
void AddNodeAtLast(List* pl,u8* data, u8 SMSCALL);
void PrintList(List* pl);
void Delete(u8* Data,List* pl);
void RetrieveElement(u8* pe,const u8* Data,List* pl);

void AddNumToEEPROM(const u8 * PhoneNum);

void PhoneList_INIT();

void PhoneList_ADD(u8 * PhoneNum);

void PhoneList_Delete(u8 * PhoneNum);

void PhoneList_Search(u8 NumID);

void print_numbers(void);

void Add_to_eeprom(u8 * Num);

void StoreListToEEPROM(List* l);
void ReadListFromEEPROM(List* l,u8 ListSize);

#endif /* PHONELIST_H_ */
