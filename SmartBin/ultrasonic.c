#include "ultrasonic.h"
#include "servo.h"

uint8_t sensor_working=0;
uint8_t rising_edge=0;
uint32_t timer_counter=0;
uint32_t distance;

void ultrasonic_init(void){

  TRIGER_DDR|=(1<<TRIGER);
  ECHO_DDR&=~(1<<ECHO);
  ECHO_PULLUP|=(1<<ECHO);
  enable_ex_interrupt0();
  timer0_init();
  return;
}

void enable_ex_interrupt0(void){

  MCUCR |= (1<<ISC00);		// Trigger INT0 on any logic change.
  GICR  |= (1<<INT0);			// Enable INT0 interrupts.

  return;
}

void ultrasonic_triger(void){
  if(!sensor_working){
    TRIGER_PORT|=(1<<TRIGER);
    _delay_us(15);
    TRIGER_PORT&=~(1<<TRIGER);
    sensor_working=1;
  }
}

ISR(INT0_vect){
  if(sensor_working==1){
    if(rising_edge==0){
      TCNT0=0x00;
      rising_edge=1;
      timer_counter=0;
    }
  else
  {
    distance=(timer_counter*256+TCNT0)/68;
	if (distance<5.0)
	{
		set_servo_angle(ANGLE_90);
		_delay_ms(1000);
		set_servo_angle(ANGLE_0);
		_delay_ms(1000);
		
	}
    timer_counter=0;
    rising_edge=0;
  }
}
}

ISR(TIMER0_OVF_vect){
    timer_counter++;
    if(timer_counter >730){
      TCNT0=0x00;
      sensor_working=0;
      rising_edge=0;
      timer_counter=0;
    }
}
