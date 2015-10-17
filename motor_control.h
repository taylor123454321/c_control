/*
 * motor_control.h
 *
 *  Created on: 8/09/2015
 *      Author: Ryan Taylor
 */

#ifndef MOTOR_CONTROL_H_
#define MOTOR_CONTROL_H_



int step_mode_return(void);

void stepper_motor(int direction);

void stepper_motor_off(void);

float stepper_system(float time_step);

int step(float time_step);

float step_motor_control(int encoder, int aim_pos);



#endif /* MOTOR_CONTROL_H_ */
