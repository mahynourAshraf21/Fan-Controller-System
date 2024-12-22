/*
 * adc.c
 *
 *  Created on: Oct 10, 2023
 *      Author: Mahy Mahrous
 */
#include <avr/io.h>
#include "adc.h"
#include "common_macros.h"

void ADC_init(const ADC_ConfigType * Config_Ptr){
	if(Config_Ptr->ref_volt==INTERNAL){
		ADMUX = (1<<REFS1) | (1<<REFS0);
	}
	else if(Config_Ptr->ref_volt==AVCC){
		ADMUX = (1<<REFS0);
	}
	else if(Config_Ptr->ref_volt==AREF){
		ADMUX = 0;
	}
//	if(Config_Ptr->prescaler==Prescaler2){
//		ADCSRA |= (1<<ADPS0);
//	}
//	else if(Config_Ptr->prescaler==Prescaler4){
//		ADCSRA |= (1<<ADPS1);
//	}
//	else if(Config_Ptr->prescaler==Prescaler8){
//		ADCSRA |= (1<<ADPS0) | (1<<ADPS1);
//	}
//	else if(Config_Ptr->prescaler==Prescaler16){
//		ADCSRA |= (1<<ADPS2);
//	}
//	else if(Config_Ptr->prescaler==Prescaler32){
//		ADCSRA |= (1<<ADPS0) | (1<<ADPS2);
//	}
//	else if(Config_Ptr->prescaler==Prescaler64){
//		ADCSRA |= (1<<ADPS2) | (1<<ADPS1);
//	}
//	else if(Config_Ptr->prescaler==Prescaler128){
//		ADCSRA |= (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2);
//	}
	//ADMUX = (ADMUX>>6) | (Config_Ptr->ref_volt);
	ADCSRA |= (1<<ADEN);
	ADCSRA |= (Config_Ptr->prescaler)&0x07;
}
uint16 ADC_readChannel(uint8 pin_num){
	pin_num &= 0x07;
	ADMUX &= 0xE0;
	ADMUX |= pin_num;
	ADCSRA |= (1<<ADSC);
	while(!(ADCSRA & (1<<ADIF)));
	ADCSRA |= (1<<ADIF);
    return ADC;
}
