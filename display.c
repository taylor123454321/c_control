/*
 * display.c
 *
 *  Created on: 28/08/2015
 *      Author: Ryan Taylor
 */

#include <stdio.h>
#include <stdint.h>
#include "display.h"
#include "rit128x96x4.h"
#include "init.h"


// This function clears the display
void clearDisplay(void){
	RIT128x96x4Clear();
}

void password_display(void){
	char stringA[30];
	char stringB[30];
	char stringC[30];
	char stringD[30];
	char stringE[30];
	char stringF[30];
	char stringG[30];
	sprintf(stringA, "Enter Password ");
	sprintf(stringB, "  ");
	sprintf(stringC, "  ");
	sprintf(stringD, "  ");
	sprintf(stringE, "  ");
	sprintf(stringF, "  ");
	sprintf(stringG, "  ");
	RIT128x96x4StringDraw (stringA, 6, 12, 15);
	RIT128x96x4StringDraw (stringB, 6, 24, 15);
	RIT128x96x4StringDraw (stringC, 6, 34, 15);
	RIT128x96x4StringDraw (stringD, 6, 46, 15);
	RIT128x96x4StringDraw (stringE, 6, 58, 15);
	RIT128x96x4StringDraw (stringF, 6, 70, 15);
	RIT128x96x4StringDraw (stringG, 6, 82, 15);
}

void init_password(void){
	int password = 0;
	while(password != 1){
		password_display();
	}
}

void set_speed_display(int speed_set){
	char stringA[30];
	char stringB[30];
	char stringC[30];
	char stringD[30];
	char stringE[30];
	char stringF[30];
	char stringG[30];
	sprintf(stringA, "Set Speed Now!");
	sprintf(stringB, "%d",speed_set);
	sprintf(stringC, "  ");
	sprintf(stringD, "  ");
	sprintf(stringE, "  ");
	sprintf(stringF, "  ");
	sprintf(stringG, "  ");
	RIT128x96x4StringDraw (stringA, 6, 12, 15);
	RIT128x96x4StringDraw (stringB, 6, 24, 15);
	RIT128x96x4StringDraw (stringC, 6, 34, 15);
	RIT128x96x4StringDraw (stringD, 6, 46, 15);
	RIT128x96x4StringDraw (stringE, 6, 58, 15);
	RIT128x96x4StringDraw (stringF, 6, 70, 15);
	RIT128x96x4StringDraw (stringG, 6, 82, 15);
}

void enter_fuel_display(void){
	char stringA[30];
	char stringB[30];
	char stringC[30];
	sprintf(stringA, "Fuel put in car");
	sprintf(stringB, "In liters");
	sprintf(stringC, "  ");
	RIT128x96x4StringDraw (stringA, 6, 12, 15);
	RIT128x96x4StringDraw (stringB, 6, 24, 15);
	RIT128x96x4StringDraw (stringC, 6, 34, 15);
}

void review_fuel_display(void){
	char stringA[30];
	char stringB[30];
	char stringC[30];
	char stringD[30];
	char stringE[30];
	char stringF[30];
	char stringG[30];
	sprintf(stringA, "Data of old fuel");
	sprintf(stringB, "  ");
	sprintf(stringC, "  ");
	sprintf(stringD, "  ");
	sprintf(stringE, "  ");
	sprintf(stringF, "  ");
	sprintf(stringG, "  ");
	RIT128x96x4StringDraw (stringA, 6, 12, 15);
	RIT128x96x4StringDraw (stringB, 6, 24, 15);
	RIT128x96x4StringDraw (stringC, 6, 34, 15);
	RIT128x96x4StringDraw (stringD, 6, 46, 15);
	RIT128x96x4StringDraw (stringE, 6, 58, 15);
	RIT128x96x4StringDraw (stringF, 6, 70, 15);
	RIT128x96x4StringDraw (stringG, 6, 82, 15);
}

void no_fix_screen(clock time, uint8_t satellite, int step_mode, int encoder, float error, char* stuff){
	char stringA[30];
	char stringB[30];
	char stringC[30];
	char stringD[30];
	char stringE[30];
	char stringF[30];
	char stringG[30];
	sprintf(stringA, "Time %d.%d.%d.%d      ", time.hour, time.minute, time.seconds, time.milliseconds);
	sprintf(stringB, "There is no fix :(  ");
	sprintf(stringC, "Satellites  %d   ", satellite);
	sprintf(stringD, "Step Mode %d   ", step_mode);
	sprintf(stringE, "Encoder %d    ", encoder);
	sprintf(stringF, "error  %f     ", error);
	sprintf(stringG, "  ");
	RIT128x96x4StringDraw (stringA, 6, 12, 15);
	RIT128x96x4StringDraw (stringB, 6, 24, 15);
	RIT128x96x4StringDraw (stringC, 6, 34, 15);
	RIT128x96x4StringDraw (stringD, 6, 46, 15);
	RIT128x96x4StringDraw (stringE, 6, 58, 15);
	RIT128x96x4StringDraw (stringF, 6, 70, 15);
	RIT128x96x4StringDraw (stringG, 6, 82, 15);
	RIT128x96x4StringDraw (stuff, 6, 82, 15);
}


void display(int screen, float speed, float acc, float max_acc, int speed_set, uint8_t satellite,
		int encoder, clock time, float distance, float quality, char * stuff, int step_mode, float error){
	if (screen == 1){
		set_speed_display(speed_set);
	}
	else if (screen == 4){
		no_fix_screen(time, satellite, step_mode, encoder, error, stuff);
	}
	else {
		char stringA[30];
		char stringB[30];
		char stringC[30];
		char stringD[30];
		char stringE[30];
		//char stringF[30];
		char stringG[30];
		sprintf(stringA, "Speed %.2f  %d.%d.%d  ", speed, time.hour, time.minute, time.seconds);
		sprintf(stringB, "Acc %.1f Max %.1f   ", acc, max_acc);
		sprintf(stringC, "Set speed %d", speed_set);
		sprintf(stringD, "Satellites %d ", satellite);
		sprintf(stringE, "Quality %.2f ", quality);
		//sprintf(stringF, "  ");
		sprintf(stringG, "Distance  %.2f   ", distance);
		RIT128x96x4StringDraw (stringA, 6, 12, 15);
		RIT128x96x4StringDraw (stringB, 6, 24, 15);
		RIT128x96x4StringDraw (stringC, 6, 34, 15);
		RIT128x96x4StringDraw (stringD, 6, 46, 15);
		RIT128x96x4StringDraw (stringE, 6, 58, 15);
		RIT128x96x4StringDraw (stuff, 6, 70, 15);
		RIT128x96x4StringDraw (stringG, 6, 82, 15);
	}
}
