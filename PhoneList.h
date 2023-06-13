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

void AddNumToEEPROM(u8 * PhoneNum);

void PhoneList_INIT();

void PhoneList_ADD(u8 * PhoneNum);

void PhoneList_Delete(u8 * PhoneNum);

void PhoneList_Search(u8 NumID);

void print_numbers(void);

void Add_to_eeprom(u8 * Num);


#endif /* PHONELIST_H_ */
