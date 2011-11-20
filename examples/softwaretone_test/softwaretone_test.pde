#include <SoftwareTone.h>
#include <TimerOne.h>

void setup() {
  Serial.begin(9600);
  
  softwareTone.init();
  for (int pin=2; pin<=13; pin++) {
    softwareTone.enablePin(pin);
  }
}

void loop() {
  for (int i=20; i<800; i+=10) {
    for (int pin=2; pin<=13; pin++) {
      softwareTone.setFreq(pin, i);
    }
    
    Serial.println(i);
    delay(300);
  }
}

