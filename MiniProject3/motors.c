/*
 * motors.c
 *
 *  Created on: Oct 12, 2023
 *      Author: Mahy Mahrous
 */
#include "motors.h"
#include "gpio.h"
#include "std_types.h"

void DcMotor_Init(void){
	GPIO_setupPinDirection(DCMOTOR_PORT_ID,DCMOTOR_IN1,PIN_OUTPUT);
	GPIO_setupPinDirection(DCMOTOR_PORT_ID,DCMOTOR_IN2,PIN_OUTPUT);
	GPIO_writePin(DCMOTOR_PORT_ID,DCMOTOR_IN1,LOGIC_LOW);
	GPIO_writePin(DCMOTOR_PORT_ID,DCMOTOR_IN2,LOGIC_LOW);

}
void DcMotor_Rotate(DcMotor_State state,uint8 speed){
    uint8 duty_cycle=0;
	duty_cycle = (uint8)((uint16)(speed*255)/100);
	PWM_Timer0_Start(duty_cycle);
	if(state==CW){
		GPIO_writePin(DCMOTOR_PORT_ID,DCMOTOR_IN1,LOGIC_LOW);
		GPIO_writePin(DCMOTOR_PORT_ID,DCMOTOR_IN2,LOGIC_HIGH);
	}
	else if(state==ACW){
		GPIO_writePin(DCMOTOR_PORT_ID,DCMOTOR_IN1,LOGIC_HIGH);
		GPIO_writePin(DCMOTOR_PORT_ID,DCMOTOR_IN2,LOGIC_LOW);
	}
	else if(state==STOP){
		GPIO_writePin(DCMOTOR_PORT_ID,DCMOTOR_IN1,LOGIC_LOW);
		GPIO_writePin(DCMOTOR_PORT_ID,DCMOTOR_IN2,LOGIC_LOW);
	}



}


