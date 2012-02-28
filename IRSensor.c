#include "IRSensor.h"

void initialize_IR_LEDs(){
	cli();

	TCCR0A = 0;

	/* Should have no prescaler, but default as off
	TCCR0A |= 1<<CS00; */

    DDRB |= 1<<PB7; // OC0A as output for IR LEDs
    TCCR0A |= 1<<WGM01 | 1<<COM0A0; // CTC mode and toggle OC0A on compare match

    OCR0A = IR_SENSITIVITY;

	sei();
}

void stop_IR_LEDs(){
	TCCR0A &= ~(1<<CS02|1<<CS01|1<<CS00); // Timer 0 off
}

void start_IR_LEDs(){
	TCNT0 = 0;
	TCCR0A |= 1<<CS00; // no presc
}

void initialize_IR_detectors(){
    DET_DDR &= ~(1<<DET_RIGHT|1<<DET_LEFT); // IR detectors as input    
}

static unsigned int raw_obstacle_right(){
	start_IR_LEDs();
	delay(1);
	stop_IR_LEDs();

    return bit_is_clear(DET_PIN, DET_RIGHT);
}

static unsigned int raw_obstacle_left(){
	start_IR_LEDs();
	delay(1);
	stop_IR_LEDs();
	
    return bit_is_clear(DET_PIN, DET_LEFT);
}

unsigned int obstacle_right(){
	unsigned int hits=0;
	for (unsigned int i=0; i<IR_SAMPLES; ++i){
		if (raw_obstacle_right()) hits++;
		delay(IR_INTERVAL);
	}
	return hits >= IR_THRESHOLD;
}

unsigned int obstacle_left(){
	unsigned int hits=0;
	for (unsigned int i=0; i<IR_SAMPLES; ++i){
		if (raw_obstacle_left()) hits++;
		delay(IR_INTERVAL);
	}
	return hits >= IR_THRESHOLD;
}
