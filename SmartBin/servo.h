#ifndef SERVO_H_
#define SERVO_H_

#define ANGLE_0 0
#define ANGLE_45 600
#define ANGLE_90 950
#define ANGLE_135 1425
#define ANGLE_180 1900

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000UL

void init_servo();
void set_servo_angle(int angle);

#endif /* SERVO_H_ */