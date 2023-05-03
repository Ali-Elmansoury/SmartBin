#ifndef _ULTRA_H_
#define _ULTRA_H_

#include<avr/io.h>
#include <avr/interrupt.h>
#include<string.h>
#include <stdlib.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include "timer.h"


#define   TRIGER_DDR    DDRA
#define   ECHO_DDR      DDRD
#define   TRIGER_PORT   PORTA
#define   ECHO_PULLUP   PORTD
#define   TRIGER        5
#define   ECHO          2

#define   TRIGER1_DDR    DDRA
#define   ECHO1_DDR      DDRD
#define   TRIGER1_PORT   PORTA
#define   ECHO1_PULLUP   PORTD
#define   TRIGER1        7
#define   ECHO1          3

/*************************************************
 *  API functions
 *************************************************/

void ultrasonic_init(void);
void enable_ex_interrupts(void);
void ultrasonic_triger(void);

#endif


