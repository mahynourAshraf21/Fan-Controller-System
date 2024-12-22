/*
 * lm35_sensor.h
 *
 *  Created on: Oct 11, 2023
 *      Author: Mahy Mahrous
 */

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_
#include "std_types.h"
#include "adc.h"
#define SENSOR_CHANNEL_ID         2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150


uint8 LM35_getTemperature();



#endif /* LM35_SENSOR_H_ */
