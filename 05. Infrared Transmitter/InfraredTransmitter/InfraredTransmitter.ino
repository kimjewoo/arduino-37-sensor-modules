/*
   Infrared Transmitter

   LG TV power on/off, etc
*/
#include <IRremote.h>

IRsend irsend;

void setup() {
  Serial.begin(9600);
  Serial.println("Arduino Examples - Infrared Transmitter");
  Serial.println("Simulate LG TV Controller");

  Serial.println("Monitor Power ON (0x20DF10EF)");
  irsend.sendNEC(0x20DF10EF, 32); // Monitor power code

  Serial.println("delay 5 seconds");
  delay(5000);

  Serial.println("Select CH1 (0x20DF8877)");
  irsend.sendNEC(0x20DF10EF, 32); // CH 1

  Serial.println("delay 5 seconds");
  delay(5000);

  Serial.println("Monitor Power OFF (0x20DF10EF)");
  irsend.sendNEC(0x20DF10EF, 32); // Monitor power code
}

void loop () {
  // no need to repeat the processing.
}
