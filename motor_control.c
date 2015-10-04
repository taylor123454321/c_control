/*
 * motor_control.c
 *
 *  Created on: 28/08/2015
 *      Author: Ryan Taylor
 */

#include "driverlib/gpio.h"


#define GPIOHigh(x) GPIOPinWrite(GPIO_PORTA_BASE, x, x)//GPIO_PIN_1
#define GPIOLow(x) GPIOPinWrite(GPIO_PORTA_BASE, x, 0)





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

}



void stepper_motor_off(void){
	GPIOHigh(GPIO_PIN_1);
	GPIOHigh(GPIO_PIN_2);
	GPIOHigh(GPIO_PIN_3);
	GPIOHigh(GPIO_PIN_4);
}

float stepper_system(float time_step);

int step(float time_step);

float step_motor_control(int encoder, int aim_pos);

void Timer1IntHandler(void);























