/*
 * motors.h
 *
 *  Created on: Oct 12, 2023
 *      Author: Mahy Mahrous
 */

#ifndef MOTORS_H_
#define MOTORS_H_
#include "gpio.h"
#include "pwm.h"
#define DCMOTOR_IN1 PIN0_ID
#define DCMOTOR_IN2 PIN1_ID
#define DCMOTOR_PORT_ID PORTB_ID
typedef enum{
	 STOP,CW,ACW
}DcMotor_State;
void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);





#endif /* MOTORS_H_ */
