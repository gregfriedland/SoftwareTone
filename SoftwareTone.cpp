/*
  SoftwareTone.cpp - Library for generating square waves on any pin.
  Created by Greg Friedland, November 20, 2011.
  Released into the public domain.
*/

#include "SoftwareTone.h"
#include <TimerOne.h>

#define TIMER_PERIOD 50 // in us; this leaves at least 50% of the cpu available on a 16Mhz arduino

#define SET_BIT(pin) ((pin) <= 7 ? PORTD |= 1<<(pin) : PORTB |= 1<<((pin)-8))
#define CLEAR_BIT(pin) ((pin) <= 7 ? PORTD &= 0<<(pin) : PORTB &= 0<<((pin)-8))

SoftwareToneClass SoftwareTone; // singleton

SoftwareToneClass::SoftwareToneClass() {
}

void SoftwareToneClass::init() {
  Timer1.initialize(TIMER_PERIOD);
  Timer1.attachInterrupt(callback);

  for (unsigned short i=0; i<NUM_PINS; i++) {
    enabled[i] = false;
    topVals[i] = 2<<16-1;
    count[i] = 0;
  }
}  

// use a macro so we can unroll the loop
#define TOGGLE_PIN(pin) {					\
    if (SoftwareTone.enabled[pin]) {				\
      if (SoftwareTone.count[pin] >= SoftwareTone.topVals[pin]) {		\
	if (SoftwareTone.state[pin]) CLEAR_BIT(pin);		\
	else SET_BIT(pin);					\
	SoftwareTone.state[pin] = !SoftwareTone.state[pin];	\
	SoftwareTone.count[pin] = 0;				\
      }								\
      SoftwareTone.count[pin]++;				\
    }								\
  }

void SoftwareToneClass::callback() {
  TOGGLE_PIN(2);
  TOGGLE_PIN(3);
  TOGGLE_PIN(4);
  TOGGLE_PIN(5);
  TOGGLE_PIN(6);
  TOGGLE_PIN(7);
  TOGGLE_PIN(8);
  TOGGLE_PIN(9);
  TOGGLE_PIN(10);
  TOGGLE_PIN(11);
  TOGGLE_PIN(12);
  TOGGLE_PIN(13);  
}

void SoftwareToneClass::enablePin(unsigned short pin) {
  enabled[pin] = true;
  pinMode(pin, OUTPUT);
}

void SoftwareToneClass::disablePin(unsigned short pin) {
  enabled[pin] = false;
}

void SoftwareToneClass::setFreq(unsigned short pin, unsigned int f) {
  if (f != 0) {
    topVals[pin] = 1000000 / TIMER_PERIOD / 2 / f;
  } else {
    enabled[pin] = false;
  }
}
