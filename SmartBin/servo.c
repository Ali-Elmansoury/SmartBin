#include "servo.h"

void init_servo()
{
	// Configure TIMER1
	TCCR1A |= (1 << COM1A1) | (1 << COM1B1) | (1 << WGM11); // NON Inverted PWM
	TCCR1B |= (1 << WGM13) | (1 << WGM12) | (0 << CS11) | (1 << CS10); // PRESCALER=8 MODE 14 (FAST PWM)

	ICR1 = 19999; // fPWM=50Hz (Period = 20ms Standard).
}

void set_servo_angle(int angle)
{
	OCR1A = angle ;
}

