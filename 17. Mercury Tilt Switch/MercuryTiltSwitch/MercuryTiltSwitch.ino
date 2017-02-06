/*
  Mecury Tilt Switch Module

  This module has a pull-up resistor to +5V. This configuration causes the input
  to read HIGH when the switch is open, and LOW when it is closed.

  * Note: because most Arduinos have a built-in LED attached to pin 13 on the
  board, the LED is optional.
*/

// this constant won't change:
const int sensorPin = 3;  // the pin that the sensor is attached to
const int ledPin = 13;    // the pin that the LED is attached to

// variables will change:
int sensorState = 0;      // current state of the sensor

void setup() {
  pinMode(sensorPin, INPUT);   // initialize the sensor pin as a input
  pinMode(ledPin, OUTPUT);     // initialize the LED as an output

  Serial.begin(9600);
  Serial.println("Arduino Examples - Mercury Tilt Switch");
}

void loop() {
  // read the shock sensor state into a varialbe
  sensorState = digitalRead (sensorPin);
  Serial.print("value: ");  Serial.println(sensorState);

  // Keep in mind the pullup means the sensor's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's close. Turn on LED when the
  // sensor detects a tilt, and off when it's not:
  if (sensorState == LOW) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(500); //just here to slow down the output so it is easier to read
}
