/* Cruise control for the kp starlet


Written by Ryan Taylor



*/

// INCUDES
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "speed.h"
#include "rit128x96x4.h"
#include "display.h"
#include "init.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_uart.h"
#include "driverlib/gpio.h"
#include "driverlib/uart.h"
#include "driverlib/interrupt.h"
#include "debounce.h"
#include "data_process.h"
#include "motor_control.h"


//*****************************************************************************
// Constants
//*****************************************************************************
#define BUF_SIZE 8

//GLOBALE VARIABLES
int encoder_1 = 0;
int encoder_2 = 0;

int prev_state = 0;
bool thing = 0;

static circBuf_t speed_buffer; // Buffer

int index = 0;
char UART_char_data[120];
char UART_char_data_old[120];

//float time_array[5];
//float speed_array[5];

bool read_data = 0;

// rate!
#define PMTK_SET_NMEA_UPDATE_5HZ  "$PMTK220,200*2C\r\n"
#define PMTK_SET_NMEA_UPDATE_10HZ "$PMTK220,100*2F\r\n"
// turn on GPRMC and GGA
#define PMTK_SET_NMEA_OUTPUT_RMCGGA "$PMTK314,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*28\r\n"
// request for updates on antenna status
#define PGCMD_ANTENNA "$PGCMD,33,1*6C\r\n"
#define PGCMD_NOANTENNA "$PGCMD,33,0*6D\r\n"


// Interrupt handler
void PinChangeIntHandler (void) {
	unsigned long ul_A_Val;
	unsigned long ul_B_Val;
	int current_state;
	// Clear the interrupt (documentation recommends doing this early)
	GPIOPinIntClear (GPIO_PORTF_BASE, GPIO_PIN_7);
	GPIOPinIntClear (GPIO_PORTF_BASE, GPIO_PIN_5);

	// Read the pin
	ul_A_Val = GPIOPinRead (GPIO_PORTF_BASE, GPIO_PIN_7);
	ul_B_Val = GPIOPinRead (GPIO_PORTF_BASE, GPIO_PIN_5);

	//Check what state the pins at and assign that state to "current state"
	if (!ul_A_Val){
		if(!ul_B_Val){
			current_state = 1;
		}
		else{
			current_state = 2;
		}
	}
	else{
		if(ul_B_Val){
			current_state = 3;
		}
		else{
			current_state = 4;
		}
	}
	// Check if the previous state is different from the current state.
	// Determine what direction the encoder is spinning
	if (current_state != prev_state){
		if (abs(prev_state-current_state) == 1){
			if(current_state>prev_state){
				encoder_1 --;
			}
			else{
				encoder_1 ++;
			}
		}
		else{
			if(current_state<prev_state){
				encoder_1 --;
			}
			else{
				encoder_1 ++;
			}
		}
	}
	prev_state = current_state; // Assign current state for next time the interrupt runs
}

void store_char(long UART_character){
	if (UART_character == '$'){
		UART_char_data_old[0] = '\0';
		strcpy(UART_char_data_old, UART_char_data);
		index = 0;
		read_data = 0;
		UART_char_data[index] = UART_character;
		index++;
	}
	else{
		UART_char_data[index] = UART_character;
		index++;
	}
}

void UARTIntHandler(void) {
    unsigned long ulStatus;
    long UART_character = 0;
    // Get the interrupt status.
    //
    ulStatus = UARTIntStatus(UART0_BASE, true);
    // Clear the asserted interrupts.
    //
    UARTIntClear(UART0_BASE, ulStatus);
    // Loop while there are characters in the receive FIFO.
    //
    while(UARTCharsAvail(UART0_BASE)) {
        // Read the next character from the UART and write it back to the UART.
        //
    	//UARTCharPutNonBlocking(UART0_BASE, UARTCharGetNonBlocking(UART0_BASE));
        UART_character = UARTCharGetNonBlocking(UART0_BASE);
        store_char(UART_character);
    }
}


int read_button_screen(int screen_old, bool fix){
	int screen = screen_old;
	/*BUTTON_DATA
	* 0 bit | DOWN
	* 1 bit | UP
	* 2 bit | LEFT
	* 3 bit | RIGHT
	* 4 bit | SELECT
	*/
	int button_data = return_button();

	bool down = bit_check(button_data, 0);
	bool up = bit_check(button_data, 1);
	//bool left = bit_check(button_data, 2);
	//bool right = bit_check(button_data, 3);
	bool select = bit_check(button_data, 4);

	if (fix == 0){
		screen = 4;//no fix screen
	}
	else{
		if (select == 1 || (fix == 1 && screen == 4)){// back function
			screen = 0;
		}
		if ((up || down) == 1){ // set speed
			screen = 1;
		}
		if (screen_old != screen){
			clearDisplay();
		}
	}
	return screen;
}

//void calculate_feedback(void){}
// calculate_other(long_lat new, long_lat old)


void send_data(void){
	int i = 0;
	while(i <= 100000){ i++; }
	i = 0;
	UARTSend((unsigned char *)PMTK_SET_NMEA_UPDATE_5HZ, 18);

	while(i <= 100000){ i++; }
	i = 0;
	UARTSend((unsigned char *)PMTK_SET_NMEA_OUTPUT_RMCGGA, 53);

	while(i <= 1000000){ i++; }
	UARTSend((unsigned char *)PGCMD_NOANTENNA, 16);
}


// This function stores the altitude in a buffer "speed_buffer" for analysis later
void store_speed(float single_speed){
	speed_buffer.data[speed_buffer.windex] = single_speed;
	speed_buffer.windex ++;
	if (speed_buffer.windex >= speed_buffer.size){
		speed_buffer.windex = 0;
	}
}

float analysis_speed(void){
	int i = 0;
	float speed_sum = 0;
	for (i = 0; i < BUF_SIZE; i++)
	speed_sum += speed_buffer.data[i];
	return (speed_sum/BUF_SIZE);
}

float max_acc_func(float acc, float max){
	if (acc > max){
		return acc;
	}
	return max;
}

// Main function
void main(void) {
	reset_peripheral();
	initClock();
	initTimer();
	initDisplay();
	initPin();
	initGPIO();
	initConsole();
	int i = 0;
	//init_password();
	send_data();

	initCircBuf (&speed_buffer, BUF_SIZE);

	int screen = 0;
	float speed = 0;
	float buffed_speed = 0;
	float acc = 0;
	float max_acc = 0;
	int speed_set = 0;
	//float fuel_eco = 0;
	float distance = 0;

	bool fix = 0;
	uint8_t satillite = 0;
	float quality = 0;
	clock time;
	int step_mode = 0;
	int aim_pos = 30;
	float error = 0;

	// i = 0;
	//while(i >= 100){ i++; }
	//i = 0;
	//long_lat location = read_location();
	//while(i >= 100){ i++; }
	//long_lat location_old = read_location();
	//i = 0;

	IntMasterEnable();

	while(1){
		//reading data
		read_data = split_data(UART_char_data_old, read_data); 	// decode data
		speed = read_speed();									//read data into variables
		//read encoder
		error = step_motor_control(encoder_1/40, aim_pos);
		//stepper_motor(0);

		//storing data
		store_speed(speed);
		buffed_speed = analysis_speed();
		acc = read_acceleration(buffed_speed);
		max_acc = max_acc_func(acc, max_acc);
		time = read_time();
		satillite = read_satillite();
		fix = read_fix();
		quality = read_quality();
		step_mode = step_mode_return();
		debounce_button();										// debounce buttons
		screen = read_button_screen(screen, fix);
		if (screen == 1){
			speed_set = set_speed(speed_set);					// set the speed to cruise at
		}
		//calculate_feedback();
		distance = read_distance();


		if (i >= 50){
			display(screen, buffed_speed, acc, max_acc, speed_set, satillite, encoder_1/40, time, distance, quality, UART_char_data_old, step_mode, error);
			//stepper_motor();
			i = 0;
		}
		i++;
	}
}




















