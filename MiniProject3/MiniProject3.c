/*
 * MiniProject3.c
 *
 *  Created on: Oct 11, 2023
 *      Author: Mahy Mahrous
 */
#include "lcd.h"
#include "adc.h"
#include "motors.h"
#include "lm35_sensor.h"
#include <util/delay.h>
int main(void){

	ADC_ConfigType ADC_Configuration;
	LCD_init();
	ADC_Configuration.ref_volt=INTERNAL;
	ADC_Configuration.prescaler=Prescaler8;
	ADC_init(&ADC_Configuration);
	uint8 temperature;
	DcMotor_Init();
	LCD_displayString("FAN is   ");
	LCD_displayStringRowColumn(1,0,"Temp =     C");
	while(1){
		temperature=LM35_getTemperature();
		if(temperature<30){
			DcMotor_Rotate(STOP,0);
			LCD_displayStringRowColumn(0,7,"OFF");
			LCD_moveCursor(1,7);
			LCD_intgerToString(temperature);
			LCD_displayCharacter(' ');
		}
		else if(temperature>=30 && temperature<60){
			DcMotor_Rotate(CW,25);
			LCD_displayStringRowColumn(0,7,"ON");
			LCD_displayCharacter(' ');
			LCD_moveCursor(1,7);
			LCD_intgerToString(temperature);
			LCD_displayCharacter(' ');
		}
		else if(temperature>=60 && temperature<90){
			DcMotor_Rotate(CW,50);
			LCD_displayStringRowColumn(0,7,"ON");
			LCD_displayCharacter(' ');
			LCD_moveCursor(1,7);
			LCD_intgerToString(temperature);
			LCD_displayCharacter(' ');
		}
		else if(temperature>=90 && temperature<120){
			DcMotor_Rotate(CW,75);
			LCD_displayStringRowColumn(0,7,"ON");
			LCD_displayCharacter(' ');
			LCD_moveCursor(1,7);
			LCD_intgerToString(temperature);
            if(temperature<=100){
            	LCD_displayCharacter(' ');
            }

		}
		else if(temperature>=120){
			DcMotor_Rotate(CW,100);
			LCD_displayStringRowColumn(0,7,"ON");
			LCD_displayCharacter(' ');
			LCD_moveCursor(1,7);
			LCD_intgerToString(temperature);
	}

	}
}


