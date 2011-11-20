/*
  SoftwareTone.h - Library for generating square waves on any pin.
  Created by Greg Friedland, November 20, 2011.
  Released into the public domain.
*/

#ifndef SOFTWARETONE_H
#define SOFTWARETONE_H

#include <WProgram.h>

#define NUM_PINS 14

class SoftwareToneClass {
 public:
  SoftwareToneClass();
  void init();
  void enablePin(unsigned short pin); // set the frequency before calling this
  void disablePin(unsigned short pin);
  void setFreq(unsigned short pin, unsigned int f);

 private:
  static void callback();
  // ignores pins 1 or 0
  unsigned int topVals[NUM_PINS]; // what value to count up to
  boolean state[NUM_PINS];
  boolean enabled[NUM_PINS];
  unsigned int count[NUM_PINS];
};

extern SoftwareToneClass SoftwareTone;

#endif
