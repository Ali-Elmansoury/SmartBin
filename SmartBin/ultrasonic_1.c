#include "ultrasonic_1.h"

uint8_t sensor_working1=0;
uint8_t rising_edge1=0;
uint32_t timer_counter1=0;
uint32_t distance1;

void ultrasonic1_init(void){

  TRIGER1_DDR|=(1<<TRIGER1);
  ECHO1_DDR&=~(1<<ECHO1);
  ECHO1_PULLUP|=(1<<ECHO1);
  enable_ex_interrupt1();
  timer2_init();
  return;
}

void enable_ex_interrupt1(void){

  MCUCR |= (1<<ISC10);		// Trigger INT1 on any logic change.
  GICR  |= (1<<INT1);			// Enable INT1 interrupts.

  return;
}

void ultrasonic1_triger(void){
  if(!sensor_working1){
    TRIGER1_PORT|=(1<<TRIGER1);
    _delay_us(15);
    TRIGER1_PORT&=~(1<<TRIGER1);
    sensor_working1=1;
  }
}

ISR(INT1_vect){
  if(sensor_working1==1){
    if(rising_edge1==0){
      TCNT2=0x00;
      rising_edge1=1;
      timer_counter1=0;
    }
  else{
    distance1=(timer_counter1*256+TCNT2)/68;
	if (distance1<5.0)
	{
		PORTA |= (1<<0);
		_delay_ms(1000);
		PORTA &= ~(1<<0);
		_delay_ms(1000);
	}
    timer_counter1=0;
    rising_edge1=0;
  }
}}

ISR(TIMER2_OVF_vect){
    timer_counter1++;
    if(timer_counter1 >730){
      TCNT2=0x00;
      sensor_working1=0;
      rising_edge1=0;
      timer_counter1=0;
    }
}
