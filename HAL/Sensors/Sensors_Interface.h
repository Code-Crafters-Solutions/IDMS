/*
 * Sensors_Interface.h
 *
 *  Created on: May 27, 2023
 *      Author: user
 */

#ifndef HAL_SENSORS_SENSORS_INTERFACE_H_
#define HAL_SENSORS_SENSORS_INTERFACE_H_

void LM35_ReadTemperture(u8 ADC_Channel ,u16 *ADC_Result);
void PT100_ReadTemperture(u8 ADC_Channel ,u16 *ADC_Result);

void ACS712_ReadCurrentValue(u8 Channel ,u16* CurrentValue);

#endif /* HAL_SENSORS_SENSORS_INTERFACE_H_ */
