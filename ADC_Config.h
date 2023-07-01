#ifndef _ADC_CONFIG_H_
#define _ADC_CONFIG_H_

/*****************************************************************************/
/**************** ADC CHANNAL *****************/
/*****************************************************************************/

 #define 		ADC0	0			
 #define 		ADC1	1		
 #define 		ADC2	2		
 #define 		ADC3	3		
 #define 		ADC4	4		
 #define 		ADC5	5		
 #define 		ADC6	6		
 #define 		ADC7	7

/*****************************************************************************/
/**************** ADC Multiplexer Selection Register – ADMUX *****************/
/*****************************************************************************/

#define    REFS1      7
#define    REFS0      6
#define    ADLAR      5
#define    MUX4       4
#define    MUX3       3
#define    MUX2       2
#define    MUX1       1
#define    MUX0       0


/*****************************************************************************/
/****************ADC Control and StatusRegister A – ADCSRA *******************/
/*****************************************************************************/

#define    ADEN 	  7
#define    ADSC 	  6
#define    ADATE 	  5
#define    ADIF 	  4
#define    ADIE 	  3
#define    ADPS2 	  2
#define    ADPS1 	  1
#define    ADPS0	  0

/*****************************************************************************/
/****************** Special FunctionIO Register – SFIOR **********************/
/*****************************************************************************/

#define    ADTS2 	  7							
#define    ADTS1 	  6						
#define    ADTS0 	  5						
						
/****************************************************************************************/
/****************************************************************************************/

#define    ADC_Prescaler_2     0
			 
			 

			 
			 
			 
#define    ADC_Prescaler_4	 2
			 
			 
			 
#define    ADC_Prescaler_8	 3
			 
			 
			 
#define    ADC_Prescaler_16	 4
			 
			 			 
#define    ADC_Prescaler_32	 5
						 
			 
#define    ADC_Prescaler_64	 6			 
			 
			 
#define    ADC_Prescaler_128	 7

/**************************************************************/
#define  	 ADC_Prescaler	ADC_Prescaler_128
/**************************************************************/

/*****************************************************************************/
/******************************** ADC MODE ***********************************/
/*****************************************************************************/
#define ADC_Single_Conversion  0
#define ADC_Free_Running	 1
#define ADC_External_Interrupt_0_Trigger 2

/*************************************************************/
#define ADC_Mode  		ADC_Single_Conversion
/*************************************************************/

/*****************************************************************************/
/************************ Reference Selection Bits ***************************/
/*****************************************************************************/

#define Internal_Vref_turned_off   0
#define Vref_AVCC              1
#define Reserved          2
#define Vref_Internal _V   3

/*************************************************************/
#define ADC_Vref		Vref_AVCC
/*************************************************************/

/*****************************************************************************/
/**************************** ADC SAVE FROM **********************************/
/*****************************************************************************/

#define Right_Adjust 0
#define Left_Adjust  1

/*************************************************************/
#define ADC_SAVE_FROM		Right_Adjust
/*************************************************************/


#endif
