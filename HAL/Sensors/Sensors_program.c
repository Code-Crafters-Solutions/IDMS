/*
 * Sensors_program.c
 *
 *  Created on: May 27, 2023
 *      Author: user
 */

#include "../../LIB/STD_TYPES.h"
#include "Sensors_Interface.h"
#include "../../MCAL/ADC/ADC_Interface.h"
#include "../../MCAL/ADC/ADC_Config.h"

void LM35_ReadTemperture(u8 ADC_Channel ,u16 *ADC_Result)
{
    ADC_Select_Channal(ADC_Channel);
    ADC_Enable();
    ADC_Start_Conversion();
    ADC_Wait_Flag();
    ADC_Get_Result(ADC_Result);
    *ADC_Result = ((5000UL*(*ADC_Result))>> 10) / 10 ;
    _delay_ms(5);
}

void PT100_ReadTemperture(u8 ADC_Channel ,u16 *ADC_Result)
{
    ADC_Select_Channal(ADC_Channel);
    ADC_Enable();
    ADC_Start_Conversion();
    ADC_Wait_Flag();
    ADC_Get_Result(ADC_Result);
    *ADC_Result= (u16)(((*ADC_Result)*1.36)-685.75);
    _delay_ms(5);
}
void ACS712_ReadCurrentValue(u8 Channel ,u16* CurrentValue)
{
	f32 Offset=2500;
	f32 Sensitivity=186;
	f32 Sum=0;
	u32 Sum2=0;
	f32 Avarage=0.0;
	f32 Result=0.0;
	u8 counter=0;
	for(u8 y=0;y<10;y++)
	{
	ADC_Select_Channal(Channel);
	ADC_Enable();
	for(u8 i=0;i<150;i++)
	{
		ADC_Start_Conversion();
	    ADC_Wait_Flag();
		ADC_Get_Result(CurrentValue);
		*CurrentValue = ((5000UL*(*CurrentValue))>> 10) ;
		if(*CurrentValue>Offset)
		{
			Result=((*CurrentValue-Offset)/Sensitivity);
			Sum+=Result;
			counter++;
		}
	}
	Avarage=Sum/(f32)counter;
	Avarage=Avarage*1000;
	Sum=0;
	Sum2+=Avarage;
	}
	Avarage=Sum2/10.0;
	*CurrentValue=(u16)Avarage;
}

