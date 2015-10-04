/*
 * speed.c
 *
 *  Created on: 28/08/2015
 *      Author: Ryan Taylor
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include "speed.h"
#include "debounce.h"
#include "display.h"
#include "driverlib/uart.h"
#include "inc/hw_uart.h"
#include "inc/hw_memmap.h"
#include "data_process.h"

#define PI 3.14159265358979323846

bool flag1;

/*char uart_reading(void){
	char string = 0;
	string = UARTCharGet(UART0_BASE);
	while(string != '$'){
		string = UARTCharGet(UART0_BASE);
		UARTCharPut(UART0_BASE, string);
	}
	return string;
}*/

float read_speed(void){
	float speed = 0;
	speed = get_speed();
	speed = speed*1.852;
	return speed;
}

int set_speed(int set_speed){
	int button_data = return_button();
	bool down = bit_check(button_data, 0);
	bool up = bit_check(button_data, 1);

	//bool left = button_data & (1 << 2);
	//bool right = button_data & (1 << 3);
	//bool select = button_data & (1 << 4);

	if (up == 1 && set_speed < 140 && flag1 == 1){
		set_speed ++;
		flag1 = 0;
	}
	else if(down == 1 && set_speed > 0 && flag1 == 1){
		set_speed --;
		flag1 = 0;
		if (set_speed == 99){
			clearDisplay();
		}
	}
	else if (down == 0 && up == 0){
		flag1 = 1;
	}
	return set_speed;
}

double toRadians(double degree) {
	double r = degree * PI / 180;
	return r;
}

double getDistance(double lat1, double lon1, double lat2, double lon2) {
	double a = 6378137, b = 6356752.314245, f = 1 / 298.257223563;
	double L = toRadians(lon2 - lon1);


	double U1 = atan((1 - f) * tan(toRadians(lat1)));
	double U2 = atan((1 - f) * tan(toRadians(lat2)));
	double sinU1 = sin(U1), cosU1 = cos(U1);
	double sinU2 = sin(U2), cosU2 = cos(U2);
	double cosSqAlpha;
	double sinSigma;
	double cos2SigmaM;
	double cosSigma;
	double sigma;

	double lambda = L, lambdaP, iterLimit = 100;
	do {
		double sinLambda = sin(lambda), cosLambda = cos(lambda);
		sinSigma = sqrt(	(cosU2 * sinLambda)
						* (cosU2 * sinLambda)
							+ (cosU1 * sinU2 - sinU1 * cosU2 * cosLambda)
								* (cosU1 * sinU2 - sinU1 * cosU2 * cosLambda)
							);
		if (sinSigma == 0) {
			return 0;
		}

		cosSigma = sinU1 * sinU2 + cosU1 * cosU2 * cosLambda;
		sigma = atan2(sinSigma, cosSigma);
		double sinAlpha = cosU1 * cosU2 * sinLambda / sinSigma;
		cosSqAlpha = 1 - sinAlpha * sinAlpha;
		cos2SigmaM = cosSigma - 2 * sinU1 * sinU2 / cosSqAlpha;

		double C = f / 16 * cosSqAlpha * (4 + f * (4 - 3 * cosSqAlpha));
		lambdaP = lambda;
		lambda = 	L + (1 - C) * f * sinAlpha
					* 	(sigma + C * sinSigma
						* 	(cos2SigmaM + C * cosSigma
							* 	(-1 + 2 * cos2SigmaM * cos2SigmaM)
							)
						);

	}
	while (abs(lambda - lambdaP) > 1e-12 && --iterLimit > 0);

	if (iterLimit == 0) {
		return 0;
	}

	double uSq = cosSqAlpha * (a * a - b * b) / (b * b);
	double A = 1 + uSq / 16384
			* (4096 + uSq * (-768 + uSq * (320 - 175 * uSq)));
	double B = uSq / 1024 * (256 + uSq * (-128 + uSq * (74 - 47 * uSq)));
	double deltaSigma =
				B * sinSigma
					* (cos2SigmaM + B / 4
						* (cosSigma
							* (-1 + 2 * cos2SigmaM * cos2SigmaM) - B / 6 * cos2SigmaM
								* (-3 + 4 * sinSigma * sinSigma)
									* (-3 + 4 * cos2SigmaM * cos2SigmaM)));

	double s = b * A * (sigma - deltaSigma);

	return s;
}

