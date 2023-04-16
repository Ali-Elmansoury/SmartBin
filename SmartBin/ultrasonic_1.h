#ifndef _ULTRA_1_H_
#define _ULTRA_1_H_

#include<avr/io.h>
#include <avr/interrupt.h>
#include<string.h>
#include <stdlib.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include "timer.h"


#define   TRIGER1_DDR    DDRD
#define   ECHO1_DDR      DDRD
#define   TRIGER1_PORT   PORTD
#define   ECHO1_PULLUP   PORTD
#define   TRIGER1        1
#define   ECHO1          3

/*************************************************
 *  API functions
 *************************************************/

void ultrasonic1_init(void);
void enable_ex_interrupt1(void);
void ultrasonic1_triger(void);

#endif
