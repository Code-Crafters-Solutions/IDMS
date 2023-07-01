/*
 * LM35_Program.c
 *
 *  Created on: May 13, 2023
 *      Author: user
 */
#include "STD_TYPES.h"
#include "LM35_Interface.h"
#include "ADC_Interface.h"
#include "ADC_Config.h"
#include "avr/delay.h"
void PT100_ReadTemperture(u8 ADC_Channel ,u16 *ADC_Result)
{
    ADC_Select_Channal(ADC_Channel);
    ADC_Enable();
    ADC_Start_Conversion();
    ADC_Wait_Flag();
    ADC_Get_Result(ADC_Result);
    *ADC_Result= (u16)(((*ADC_Result)*1.287)-685.75);
    _delay_ms(5);
}
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

void Current_SensorReader(u8 ADC_Channel ,u16 *ADC_Result)
{
    ADC_Select_Channal(ADC_Channel);
    ADC_Enable();
    ADC_Start_Conversion();
    ADC_Wait_Flag();
    ADC_Get_Result(ADC_Result);
    _delay_ms(5);
}
