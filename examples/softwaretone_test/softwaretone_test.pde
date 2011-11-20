#include <SoftwareTone.h>
#include <TimerOne.h>

void setup() {
  Serial.begin(9600);
  
  SoftwareTone.init();
}

void loop() {
  for (int i=20; i<800; i+=10) {
    for (int pin=2; pin<=13; pin++) {
      SoftwareTone.setFreq(pin, i);
    }
    
    Serial.println(i);
    delay(300);
  }
}

