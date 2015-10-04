/*
 * speed.h
 *
 *  Created on: 28/08/2015
 *      Author: Ryan Taylor
 */

#ifndef SPEED_H_
#define SPEED_H_

//char uart_reading(void);

float read_speed(void);

int set_speed(int set_speed);

double toRadians(double degree);

double getDistance(double lat1, double lon1, double lat2, double lon2);



#endif
