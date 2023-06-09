/*
 * DIO_Registers.h
 *
 *  Created on: Feb 10, 2023
 *      Author: aaa
 */

#ifndef DIO_REGISTERS_H_
#define DIO_REGISTERS_H_

#define Conc(b7,b6,b5,b4,b3,b2,b1,b0)	Conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)	0b##b7##b6##b5##b4##b3##b2##b1##b0

#define PORTA_REG 	*((volatile u8*)0x3B)
#define DDRA_REG	*((volatile u8*)0x3A)
#define PINA_REG	*((volatile u8*)0x39)

#define PORTB_REG 	*((volatile u8*)0x38)
#define DDRB_REG	*((volatile u8*)0x37)
#define PINB_REG	*((volatile u8*)0x36)

#define PORTC_REG 	*((volatile u8*)0x35)
#define DDRC_REG	*((volatile u8*)0x34)
#define PINC_REG	*((volatile u8*)0x33)

#define PORTD_REG 	*((volatile u8*)0x32)
#define DDRD_REG	*((volatile u8*)0x31)
#define PIND_REG	*((volatile u8*)0x30)

#define PORTE_REG 	*((volatile u8*)0x23)
#define DDRE_REG	*((volatile u8*)0x22)
#define PINE_REG	*((volatile u8*)0x21)

#define PORTF_REG 	*((volatile u8*)0x62)
#define DDRF_REG	*((volatile u8*)0x61)
#define PINF_REG	*((volatile u8*)0x20)

#define PORTG_REG 	*((volatile u8*)0x65)
#define DDRG_REG	*((volatile u8*)0x64)
#define PING_REG	*((volatile u8*)0x63)
#endif /* MCAL_DIO_DIO_REGISTERS_H_ */
