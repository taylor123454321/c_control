/*
 * motor_control.c
 *
 *  Created on: 28/08/2015
 *      Author: Ryan Taylor
 */

#include "inc/hw_types.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"
#include "driverlib/gpio.h"
#include "driverlib/systick.h"
#include "driverlib/interrupt.h"





#define GPIOHigh(x) GPIOPinWrite(GPIO_PORTF_BASE, x, x)//GPIO_PIN_1
#define GPIOLow(x) GPIOPinWrite(GPIO_PORTF_BASE, x, 0)
#define MAX_24BIT_VAL 0X0FFFFFF
#define FACTOR 13000000


int time_last = 0;
int thisStep = 0;


void stepper_motor(int direction){
	switch (thisStep) {
    	case 0:  // 1010
    		GPIOHigh(GPIO_PIN_1);
    		GPIOLow(GPIO_PIN_2);
    		GPIOHigh(GPIO_PIN_3);
    		GPIOLow(GPIO_PIN_4);
    		if (direction == 0){
    			thisStep = 1;
    		}
    		else {
    			thisStep = 3;
    		}
    		break;
    	case 1:  // 0110
    		GPIOLow(GPIO_PIN_1);
    		GPIOHigh(GPIO_PIN_2);
    		GPIOHigh(GPIO_PIN_3);
    		GPIOLow(GPIO_PIN_4);
    		if (direction == 0){
    			thisStep = 2;
    		}
    		else {
    			thisStep = 0;
    		}
    		break;
    	case 2:  //0101
    		GPIOLow(GPIO_PIN_1);
    		GPIOHigh(GPIO_PIN_2);
    		GPIOLow(GPIO_PIN_3);
    		GPIOHigh(GPIO_PIN_4);
    		if (direction == 0){
    		    thisStep = 3;
    		}
    		else {
    		    thisStep = 1;
    		}
    		break;
    	case 3:  //1001
    		GPIOHigh(GPIO_PIN_1);
    		GPIOLow(GPIO_PIN_2);
    		GPIOLow(GPIO_PIN_3);
    		GPIOHigh(GPIO_PIN_4);
    		if (direction == 0){
    		    thisStep = 0;
    		}
    		else {
    			thisStep = 2;
    		}
    	break;
    }
}


int step_mode_return(void){
	return thisStep;
}

void stepper_motor_off(void){
	GPIOHigh(GPIO_PIN_1);
	GPIOHigh(GPIO_PIN_2);
	GPIOHigh(GPIO_PIN_3);
	GPIOHigh(GPIO_PIN_4);
}

float stepper_system(float time_step){
	float time = 0;
	if (time_step > 300){
		time_step = 300;
	}
	if (time_step != 0){
		time = 1/time_step;
	}
	if ( time_step == 0){
		time = 0;
	}
	return time;
}

int step(float time_step){
	int current_time = SysTickValueGet();
	int diff = 0;
	int direction = 0; //0 = clockwise, 1 = anti clockwise

	if (time_step < 0){
		direction = 1;
		time_step = -1*time_step;
	}
	//if time less then 0, change direction

	if (current_time <= time_last){
		diff = time_last - current_time;
	}
	else {
		diff = (time_last + MAX_24BIT_VAL) - current_time;
	}
	if (diff > (time_step*FACTOR) && time_step != 0) {

		stepper_motor(direction);
		time_last = current_time;
	}
	return current_time;
}

float step_motor_control(int encoder, int aim_pos){
	int error = 0;
	float time_step = 0;
	error = aim_pos - encoder;
	time_step = 10*error; //gain
	time_step = stepper_system(time_step);
	step(time_step);

	return error;
}





