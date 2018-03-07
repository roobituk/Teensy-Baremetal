/*
 ============================================================================
 Name        : main.c
 Author      : Kevin Webster
 Version     :
 Copyright   : 
 Description : Hello World in C
 ============================================================================
 */

#include "mk66f18.h"
#include <stdbool.h>
#include <stdlib.h>

// System clock in Hz
#define CLK_SYS_Hz			120000000

#define TEENSY_LED			(1 << 5)

#define LED_BLINK_FAST		50000				// 10Hz blink rate
#define LED_BLINK_SLOW		500000				// 1Hz blink rate

#define LED_BLINK_RATE		LED_BLINK_SLOW


// Just an LED counter
uint32_t ledCount = 0;

// Used in the delay routine
uint64_t delayCnt = 0;
bool doDelay = false;


// Wait for a specified number of microseconds
static void wait_us(uint16_t us) {

	delayCnt = us;
	doDelay = true;

	while (delayCnt > 0) {}

	doDelay = false;

}

// Wait for a specified number of milliseconds
static void wait_ms(uint16_t ms) {
	wait_us(ms * 1000);
}


int main(void) {

	// Configure the Teensy LED output
	PORTC->PCR[5] = PORT_PCR_MUX(1);
	PTC->PDDR |= (1 << 5);

	PTC->PCOR |= TEENSY_LED;

	for (;;) {
		// Main loop
	}

	return 0;
}

void systick_isr(void) {

	// THIS LOOP EXECUTES AT 1MHz
	// CODE IN HERE WILL EXECUTE EVERY 0.000001s

	// Used in the delay_xx functions
	if (doDelay)
		delayCnt--;

	if (ledCount == LED_BLINK_RATE) {
		PTC->PTOR |= TEENSY_LED;
		// Reset the LED counter
		ledCount = 0;
	}

	ledCount++;
}
