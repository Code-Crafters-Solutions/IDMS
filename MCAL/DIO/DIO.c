/*
 * DIO.c
 *
 *  Created on: Feb 10, 2023
 *      Author: aaa
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIO_Registers.h"
#include "DIO_Config.h"

void DIO_INIT(void)
{

	DDRA_REG = Conc(DIO_PORTA_PIN7_INIT_DIR,DIO_PORTA_PIN6_INIT_DIR,DIO_PORTA_PIN5_INIT_DIR,
					DIO_PORTA_PIN4_INIT_DIR,DIO_PORTA_PIN3_INIT_DIR,DIO_PORTA_PIN2_INIT_DIR,
					DIO_PORTA_PIN1_INIT_DIR,DIO_PORTA_PIN0_INIT_DIR);
	DDRB_REG = Conc(DIO_PORTB_PIN7_INIT_DIR,DIO_PORTB_PIN6_INIT_DIR,DIO_PORTB_PIN5_INIT_DIR,
					DIO_PORTB_PIN4_INIT_DIR,DIO_PORTB_PIN3_INIT_DIR,DIO_PORTB_PIN2_INIT_DIR,
					DIO_PORTB_PIN1_INIT_DIR,DIO_PORTB_PIN0_INIT_DIR);
	DDRC_REG = Conc(DIO_PORTC_PIN7_INIT_DIR,DIO_PORTC_PIN6_INIT_DIR,DIO_PORTC_PIN5_INIT_DIR,
					DIO_PORTC_PIN4_INIT_DIR,DIO_PORTC_PIN3_INIT_DIR,DIO_PORTC_PIN2_INIT_DIR,
					DIO_PORTC_PIN1_INIT_DIR,DIO_PORTC_PIN0_INIT_DIR);
	DDRD_REG = Conc(DIO_PORTD_PIN7_INIT_DIR,DIO_PORTD_PIN6_INIT_DIR,DIO_PORTD_PIN5_INIT_DIR,
					DIO_PORTD_PIN4_INIT_DIR,DIO_PORTD_PIN3_INIT_DIR,DIO_PORTD_PIN2_INIT_DIR,
					DIO_PORTD_PIN1_INIT_DIR,DIO_PORTD_PIN0_INIT_DIR);
	DDRE_REG = Conc(DIO_PORTE_PIN7_INIT_DIR,DIO_PORTE_PIN6_INIT_DIR,DIO_PORTE_PIN5_INIT_DIR,
					DIO_PORTE_PIN4_INIT_DIR,DIO_PORTE_PIN3_INIT_DIR,DIO_PORTE_PIN2_INIT_DIR,
					DIO_PORTE_PIN1_INIT_DIR,DIO_PORTE_PIN0_INIT_DIR);
	DDRF_REG = Conc(DIO_PORTF_PIN7_INIT_DIR,DIO_PORTF_PIN6_INIT_DIR,DIO_PORTF_PIN5_INIT_DIR,
					DIO_PORTF_PIN4_INIT_DIR,DIO_PORTF_PIN3_INIT_DIR,DIO_PORTF_PIN2_INIT_DIR,
					DIO_PORTF_PIN1_INIT_DIR,DIO_PORTF_PIN0_INIT_DIR);
	DDRG_REG = Conc(0,0,0,DIO_PORTG_PIN4_INIT_DIR,
					DIO_PORTG_PIN3_INIT_DIR,DIO_PORTG_PIN2_INIT_DIR,
					DIO_PORTG_PIN1_INIT_DIR,DIO_PORTG_PIN0_INIT_DIR);

	PORTA_REG = Conc(DIO_PORTA_PIN7_INIT_Val,DIO_PORTA_PIN6_INIT_Val,DIO_PORTA_PIN5_INIT_Val,
					DIO_PORTA_PIN4_INIT_Val,DIO_PORTA_PIN3_INIT_Val,DIO_PORTA_PIN2_INIT_Val,
					DIO_PORTA_PIN1_INIT_Val,DIO_PORTA_PIN0_INIT_Val);
	PORTB_REG = Conc(DIO_PORTB_PIN7_INIT_Val,DIO_PORTB_PIN6_INIT_Val,DIO_PORTB_PIN5_INIT_Val,
					DIO_PORTB_PIN4_INIT_Val,DIO_PORTB_PIN3_INIT_Val,DIO_PORTB_PIN2_INIT_Val,
					DIO_PORTB_PIN1_INIT_Val,DIO_PORTB_PIN0_INIT_Val);
	PORTC_REG = Conc(DIO_PORTC_PIN7_INIT_Val,DIO_PORTC_PIN6_INIT_Val,DIO_PORTC_PIN5_INIT_Val,
					 DIO_PORTC_PIN4_INIT_Val,DIO_PORTC_PIN3_INIT_Val,DIO_PORTC_PIN2_INIT_Val,
					 DIO_PORTC_PIN1_INIT_Val,DIO_PORTC_PIN0_INIT_Val);
	PORTD_REG = Conc(DIO_PORTD_PIN7_INIT_Val,DIO_PORTD_PIN6_INIT_Val,DIO_PORTD_PIN5_INIT_Val,
					 DIO_PORTD_PIN4_INIT_Val,DIO_PORTD_PIN3_INIT_Val,DIO_PORTD_PIN2_INIT_Val,
					 DIO_PORTD_PIN1_INIT_Val,DIO_PORTD_PIN0_INIT_Val);
	PORTE_REG = Conc(DIO_PORTE_PIN7_INIT_Val,DIO_PORTE_PIN6_INIT_Val,DIO_PORTE_PIN5_INIT_Val,
					 DIO_PORTE_PIN4_INIT_Val,DIO_PORTE_PIN3_INIT_Val,DIO_PORTE_PIN2_INIT_Val,
					 DIO_PORTE_PIN1_INIT_Val,DIO_PORTE_PIN0_INIT_Val);
	PORTF_REG = Conc(DIO_PORTF_PIN7_INIT_Val,DIO_PORTF_PIN6_INIT_Val,DIO_PORTF_PIN5_INIT_Val,
					 DIO_PORTF_PIN4_INIT_Val,DIO_PORTF_PIN3_INIT_Val,DIO_PORTF_PIN2_INIT_Val,
					 DIO_PORTF_PIN1_INIT_Val,DIO_PORTF_PIN0_INIT_Val);
	PORTG_REG = Conc(0,0,0,DIO_PORTG_PIN4_INIT_Val,
					 DIO_PORTG_PIN3_INIT_Val,DIO_PORTG_PIN2_INIT_Val,
					 DIO_PORTG_PIN1_INIT_Val,DIO_PORTG_PIN0_INIT_Val);

}

u8 DIO_SetPinDirection(u8 Port_ID,u8 Pin_ID,u8 Pin_Dir)
{
	u8 ErrorState = DIO_OK;
	if(Pin_ID >=PIN0 && Pin_ID <= PIN7)
	{
		if(Pin_Dir == OUTPUT)
		{
			switch(Port_ID)
			{
			case PORTA:SET_BIT(DDRA_REG,Pin_ID);break;
			case PORTB:SET_BIT(DDRB_REG,Pin_ID);break;
			case PORTC:SET_BIT(DDRC_REG,Pin_ID);break;
			case PORTD:SET_BIT(DDRD_REG,Pin_ID);break;
			case PORTE:SET_BIT(DDRE_REG,Pin_ID);break;
			case PORTF:SET_BIT(DDRF_REG,Pin_ID);break;
			case PORTG:SET_BIT(DDRG_REG,Pin_ID);break;
			default:ErrorState = DIO_PortOutOfRange; break;
			}
		}
		else if (Pin_Dir == INPUT)
		{
			switch(Port_ID)
			{
			case PORTA:CLR_BIT(DDRA_REG,Pin_ID);break;
			case PORTB:CLR_BIT(DDRB_REG,Pin_ID);break;
			case PORTC:CLR_BIT(DDRC_REG,Pin_ID);break;
			case PORTD:CLR_BIT(DDRD_REG,Pin_ID);break;
			case PORTE:CLR_BIT(DDRE_REG,Pin_ID);break;
			case PORTF:CLR_BIT(DDRF_REG,Pin_ID);break;
			case PORTG:CLR_BIT(DDRG_REG,Pin_ID);break;
			default:ErrorState = DIO_PortOutOfRange;break;
			}
		}
		else
		{
			ErrorState = DIO_DirectionNotCorrect;
		}
	}
	else
	{
		ErrorState = DIO_PinOutOfRange;
	}
	return ErrorState;
}

u8 DIO_SetPinValue(u8 Port_ID,u8 Pin_ID,u8 Pin_Val)
{
	u8 ErrorState = DIO_OK;
	if(Pin_ID >=PIN0 && Pin_ID <= PIN7)
	{
		if(Pin_Val == HIGH)
		{
			switch(Port_ID)
			{
			case PORTA:SET_BIT(PORTA_REG,Pin_ID);break;
			case PORTB:SET_BIT(PORTB_REG,Pin_ID);break;
			case PORTC:SET_BIT(PORTC_REG,Pin_ID);break;
			case PORTD:SET_BIT(PORTD_REG,Pin_ID);break;
			case PORTE:SET_BIT(PORTE_REG,Pin_ID);break;
			case PORTF:SET_BIT(PORTF_REG,Pin_ID);break;
			case PORTG:SET_BIT(PORTG_REG,Pin_ID);break;
			default:ErrorState = DIO_PortOutOfRange; break;
			}
		}
		else if (Pin_Val == LOW)
		{
			switch(Port_ID)
			{
			case PORTA:CLR_BIT(PORTA_REG,Pin_ID);break;
			case PORTB:CLR_BIT(PORTB_REG,Pin_ID);break;
			case PORTC:CLR_BIT(PORTC_REG,Pin_ID);break;
			case PORTD:CLR_BIT(PORTD_REG,Pin_ID);break;
			case PORTE:CLR_BIT(PORTE_REG,Pin_ID);break;
			case PORTF:CLR_BIT(PORTF_REG,Pin_ID);break;
			case PORTG:CLR_BIT(PORTG_REG,Pin_ID);break;
			default:ErrorState = DIO_PortOutOfRange; break;
			}
		}
		else
		{
			ErrorState = DIO_ValueNotCorrect;
		}
	}
	else
	{
		ErrorState = DIO_PinOutOfRange;
	}
	return ErrorState;
}

u8	DIO_ReadPin(u8 Port_ID,u8 Pin_ID,u8 * PinReading)
{
	u8 ErrorState = DIO_OK;
	*PinReading = 0;
	if(Pin_ID >=PIN0 && Pin_ID <= PIN7)
	{
		switch(Port_ID)
		{
			case PORTA:*PinReading = GET_BIT(PINA_REG,Pin_ID);break;
			case PORTB:*PinReading = GET_BIT(PINB_REG,Pin_ID);break;
			case PORTC:*PinReading = GET_BIT(PINC_REG,Pin_ID);break;
			case PORTD:*PinReading = GET_BIT(PIND_REG,Pin_ID);break;
			case PORTE:*PinReading = GET_BIT(PINE_REG,Pin_ID);break;
			case PORTF:*PinReading = GET_BIT(PINF_REG,Pin_ID);break;
			case PORTG:*PinReading = GET_BIT(PING_REG,Pin_ID);break;
			default:ErrorState = DIO_PortOutOfRange; break;
		}
	}
	else
	{
		ErrorState = DIO_PinOutOfRange;
	}
	return ErrorState;
}


u8 DIO_TogglePin(u8 Port_ID,u8 Pin_ID)
{
	u8 ErrorState = DIO_OK;
	if(Pin_ID >=PIN0 && Pin_ID <= PIN7)
	{
		switch(Port_ID)
		{
			case PORTA:TOG_BIT(PORTA_REG,Pin_ID);break;
			case PORTB:TOG_BIT(PORTB_REG,Pin_ID);break;
			case PORTC:TOG_BIT(PORTC_REG,Pin_ID);break;
			case PORTD:TOG_BIT(PORTD_REG,Pin_ID);break;
			case PORTE:TOG_BIT(PORTE_REG,Pin_ID);break;
			case PORTF:TOG_BIT(PORTF_REG,Pin_ID);break;
			case PORTG:TOG_BIT(PORTG_REG,Pin_ID);break;
			default:ErrorState = DIO_PortOutOfRange; break;
		}
	}
	else
	{
		ErrorState = DIO_PinOutOfRange;
	}
	return ErrorState;
}

u8 DIO_SetPortDirection(u8 Port_ID,u8 Port_Dir)
{
	u8 ErrorState = DIO_OK;
	if(Port_ID>=PORTA && Port_ID<=PORTG && Port_Dir>= 0 && Port_Dir<= 255)
	{
		if(Port_Dir == OUTPUT_PORT)
		{
			switch(Port_ID)
			{
			case PORTA:SET_REG(DDRA_REG);break;
			case PORTB:SET_REG(DDRB_REG);break;
			case PORTC:SET_REG(DDRC_REG);break;
			case PORTD:SET_REG(DDRD_REG);break;
			case PORTE:SET_REG(DDRE_REG);break;
			case PORTF:SET_REG(DDRF_REG);break;
			case PORTG:SET_REG(DDRG_REG);break;
			default:break;
			}
		}
		else if(Port_Dir == INPUT_PORT)
		{
			switch(Port_ID)
			{
			case PORTA:CLR_REG(DDRA_REG);break;
			case PORTB:CLR_REG(DDRB_REG);break;
			case PORTC:CLR_REG(DDRC_REG);break;
			case PORTD:CLR_REG(DDRD_REG);break;
			case PORTE:CLR_REG(DDRE_REG);break;
			case PORTF:CLR_REG(DDRF_REG);break;
			case PORTG:CLR_REG(DDRG_REG);break;
			default:break;
			}
		}
		else
		{
			switch(Port_ID)
			{
			case PORTA:DDRA_REG = Port_Dir;break;
			case PORTB:DDRB_REG = Port_Dir;break;
			case PORTC:DDRC_REG = Port_Dir;break;
			case PORTD:DDRD_REG = Port_Dir;break;
			case PORTE:DDRE_REG = Port_Dir;break;
			case PORTF:DDRF_REG = Port_Dir;break;
			case PORTG:DDRG_REG = Port_Dir;break;
			default:break;
			}
		}
	}
	else
	{
		ErrorState = DIO_NOTOK;
	}
	return ErrorState;
}

u8 DIO_SetPortValue(u8 Port_ID,u8 Port_Val)
{
	u8 ErrorState = DIO_OK;
	if(Port_ID>=PORTA && Port_ID<=PORTG && Port_Val>= 0 && Port_Val<= 255)
	{
		if(Port_Val == HIGH_PORT)
		{
			switch(Port_ID)
			{
			case PORTA:SET_REG(PORTA_REG);break;
			case PORTB:SET_REG(PORTB_REG);break;
			case PORTC:SET_REG(PORTC_REG);break;
			case PORTD:SET_REG(PORTD_REG);break;
			case PORTE:SET_REG(PORTE_REG);break;
			case PORTF:SET_REG(PORTF_REG);break;
			case PORTG:SET_REG(PORTG_REG);break;
			default:break;
			}
		}
		else if(Port_Val == LOW_PORT)
		{
			switch(Port_ID)
			{
			case PORTA:CLR_REG(PORTA_REG);break;
			case PORTB:CLR_REG(PORTB_REG);break;
			case PORTC:CLR_REG(PORTC_REG);break;
			case PORTD:CLR_REG(PORTD_REG);break;
			case PORTE:CLR_REG(PORTE_REG);break;
			case PORTF:CLR_REG(PORTF_REG);break;
			case PORTG:CLR_REG(PORTG_REG);break;
			default:break;
			}
		}
		else
		{
			switch(Port_ID)
			{
			case PORTA:PORTA_REG = Port_Val;break;
			case PORTB:PORTB_REG = Port_Val;break;
			case PORTC:PORTC_REG = Port_Val;break;
			case PORTD:PORTD_REG = Port_Val;break;
			case PORTE:PORTE_REG = Port_Val;break;
			case PORTF:PORTF_REG = Port_Val;break;
			case PORTG:PORTG_REG = Port_Val;break;
			default:break;
			}
		}
	}
	else
	{
		ErrorState = DIO_NOTOK;
	}
	return ErrorState;
}

u8	DIO_ReadPort(u8 Port_ID,u8 * PortReading)
{
	u8 ErrorState = DIO_OK;
	*PortReading = 0;
	if(Port_ID>= PORTA && Port_ID <=PORTG)
	{
		switch(Port_ID)
		{
		case PORTA:*PortReading = GET_REG(PINA_REG);break;
		case PORTB:*PortReading = GET_REG(PINB_REG);break;
		case PORTC:*PortReading = GET_REG(PINC_REG);break;
		case PORTD:*PortReading = GET_REG(PIND_REG);break;
		case PORTE:*PortReading = GET_REG(PINE_REG);break;
		case PORTF:*PortReading = GET_REG(PINF_REG);break;
		case PORTG:*PortReading = GET_REG(PING_REG);break;
		default: ErrorState = DIO_PortOutOfRange;break;
		}
	}
	else
	{
		ErrorState = DIO_NOTOK;
	}
	return ErrorState;
}

u8 DIO_TogglePort(u8 Port_ID)
{
	u8 ErrorState = DIO_OK;
	if(Port_ID>= PORTA && Port_ID <=PORTG)
	{
		switch(Port_ID)
		{
		case PORTA:TOG_REG(PORTA_REG);break;
		case PORTB:TOG_REG(PORTB_REG);break;
		case PORTC:TOG_REG(PORTC_REG);break;
		case PORTD:TOG_REG(PORTD_REG);break;
		case PORTE:TOG_REG(PORTE_REG);break;
		case PORTF:TOG_REG(PORTF_REG);break;
		case PORTG:TOG_REG(PORTG_REG);break;
		default:ErrorState = DIO_PortOutOfRange;break;
		}
	}
	else
	{
		ErrorState = DIO_NOTOK;
	}
	return ErrorState;
}

