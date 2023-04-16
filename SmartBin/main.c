#define F_CPU 1000000UL
#include "ultrasonic.h"
#include "ultrasonic_1.h"
#include "servo.h"

void main()
{
	DDRA |= (1<<0); //buzzer
	DDRD |= (1 << 4) | (1 << 5); // PWM Pins as Out
	ultrasonic_init();
	ultrasonic1_init();
	init_servo();
	sei();
	
	while(1)
	{
		ultrasonic_triger();
		_delay_ms(100);
		ultrasonic1_triger();
		_delay_ms(100);
	}
}


