/*
 * LM35_Interface.h
 *
 *  Created on: May 13, 2023
 *      Author: user
 */

#ifndef HAL_LM35_LM35_INTERFACE_H_
#define HAL_LM35_LM35_INTERFACE_H_

void LM35_ReadTemperture(u8 ADC_Channel ,u16 *ADC_Result);
void PT100_ReadTemperture(u8 ADC_Channel ,u16 *ADC_Result);

void Current_SensorReader(u8 ADC_Channel ,u16 *ADC_Result);
#endif /* HAL_LM35_LM35_INTERFACE_H_ */
