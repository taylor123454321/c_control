/*
 * display.h
 *
 *  Created on: 28/08/2015
 *      Author: Ryan Taylor
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_


#include <stdint.h>
#include "init.h"

// This function clears the display
void clearDisplay(void);

void password_display(void);

void init_password(void);

void set_speed_display(int speed_set);

void enter_fuel_display(void);

void review_fuel_display(void);

void no_fix_screen(clock time, uint8_t satellite, int step_mode, int encoder, float error, char* stuff);

void display(int screen, float speed, float acc, float max_acc, int speed_set, uint8_t satellite,
		int encoder_3, clock time, float distance, float quality, char * stuff, int step_mode, float error);


#endif /* DISPLAY_H_ */
