#define F_CPU 1000000UL
#include "ultrasonic.h"
#include "servo.h"

void main()
{
	DDRA |= (1 << 0) | (1 << 2); //buzzer, red led
	DDRD |= (1 << 4) | (1 << 5); // PWM Pins as Out
	DDRC |= (1 << 1) ; //1-23 Green
	ultrasonic_init();
	init_servo();
	sei();
	
	while(1)
	{
		ultrasonic_triger();
		PORTC |= (1 << 1);
		PORTA &= ~(1 << 2);
	}
}


