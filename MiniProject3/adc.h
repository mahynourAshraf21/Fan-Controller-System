/*
 * adc.h
 *
 *  Created on: Oct 10, 2023
 *      Author: Mahy Mahrous
 */

#ifndef ADC_H_
#define ADC_H_
#include "std_types.h"
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REFERENCE_VOLT   2.56

typedef enum{
	AREF,AVCC,INTERNAL=3
}ADC_ReferenceVolatge;
typedef enum{
	Prescaler2=1,Prescaler4=2,Prescaler8=3,Prescaler16=4,Prescaler32=5,
	Prescaler64=6,Prescaler128=111
}ADC_Prescaler;
typedef struct{
	 ADC_ReferenceVolatge ref_volt;
	 ADC_Prescaler prescaler;
}ADC_ConfigType;
void ADC_init(const ADC_ConfigType * Config_Ptr);

uint16 ADC_readChannel(uint8 pin_num);


#endif /* ADC_H_ */
