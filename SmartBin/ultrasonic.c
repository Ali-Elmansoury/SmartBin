#include "ultrasonic.h"
#include "servo.h"

volatile uint8_t sensor_working=0;
volatile uint8_t rising_edge=0;
volatile uint32_t timer_counter=0;
volatile uint32_t distance;

volatile uint8_t sensor_working1=0;
volatile uint32_t distance1;


volatile uint8_t sensor1_working = 0; // flag to indicate if sensor 1 is working
volatile uint8_t sensor2_working = 0; // flag to indicate if sensor 2 is working

void ultrasonic_init(void){

  TRIGER_DDR|=(1<<TRIGER);
  ECHO_DDR&=~(1<<ECHO);
  ECHO_PULLUP|=(1<<ECHO);
  enable_ex_interrupts();
  timer0_init();
  
  TRIGER1_DDR|=(1<<TRIGER1);
  ECHO1_DDR&=~(1<<ECHO1);
  ECHO1_PULLUP|=(1<<ECHO1);
  return;
}

void enable_ex_interrupts(void){

  MCUCR |= (1<<ISC00)|(1<<ISC10);		// Trigger INT0,INT1 on any logic change.
  GICR  |= (1<<INT0)|(1<<INT1);			// Enable INT0,INT1 interrupts.

  return;
}

void ultrasonic_triger(void){
  if(!sensor_working){
    TRIGER_PORT|=(1<<TRIGER);
    _delay_us(15);
    TRIGER_PORT&=~(1<<TRIGER);
    sensor_working=1;
  }
  
  if(!sensor_working1){
	  TRIGER1_PORT|=(1<<TRIGER1);
	  _delay_us(15);
	  TRIGER1_PORT&=~(1<<TRIGER1);
	  sensor_working1=1;
  }
}

ISR(INT0_vect){
	if (sensor2_working == 0) { // check if sensor 2 is not in use
		sensor1_working = 1; // set flag to indicate that sensor 1 is in use
		if (rising_edge == 0){
			TCNT0 = 0x00;
			rising_edge = 1;
			timer_counter = 0;
			} else {
			distance = (timer_counter * 256 + TCNT0) / 68;
			if (distance < 20.0) {
				set_servo_angle(ANGLE_180);
				_delay_ms(5000);
				set_servo_angle(ANGLE_90);
				_delay_ms(1000);
			}
			timer_counter = 0;
			rising_edge = 0;
			sensor1_working = 0; // clear flag to indicate that sensor 1 is done
		}
	}
}


ISR(INT1_vect){
	if (sensor1_working == 0) { // check if sensor 1 is not in use
		sensor2_working = 1; // set flag to indicate that sensor 2 is in use
		if (rising_edge == 0){
			TCNT0 = 0x00;
			rising_edge = 1;
			timer_counter = 0;
			} else {
			distance1 = (timer_counter * 256 + TCNT0) / 68;
			if (distance1 < 20.0) {
				PORTC &= ~(1<<1);
				PORTA |= (1<<2);
				PORTA |= (1<<0);
				_delay_ms(1000);
				PORTA &= ~(1<<0);
				_delay_ms(1000);
			}
			timer_counter = 0;
			rising_edge= 0;
			sensor2_working = 0; // clear flag to indicate that sensor 2 is done
		}
	}
}

/*ISR(TIMER0_OVF_vect){
	timer_counter++;
	if(timer_counter >730){
		TCNT0=0x00;
		sensor_working=0;
		rising_edge=0;
		timer_counter=0;
	}
}*/




