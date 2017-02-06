/*
  Vibration Switch - Spring - Edge Detection

  You need to know when the input changes from one state to another. This is
  called state change detection, or edge detection.
  See http://www.arduino.cc/en/Tutorial/ButtonStateChange

  This module has a 10K-ohm pull-up resistor to +5V. This configuration causes
  the input to read HIGH when the switch is open, and LOW when it is closed.

  * Note: because most Arduinos have a built-in LED attached to pin 13 on the
  board, the LED is optional.
*/

// this constant won't change:
const int sensorPin = 3;      // the pin that the sensor is attached to
const int ledPin = 13;        // the pin that the LED is attached to

// variables will change:
int sensorState = 0;          // current state of the sensor
int lastSensorState = 0;      // previous state of the sensor

void setup() {
  pinMode(sensorPin, INPUT);  // initialize the sensor pin as a input
  pinMode(ledPin, OUTPUT);    // initialize the LED as an output

  Serial.begin(9600);
  Serial.println("Arduino Examples - Vibration Switch - Edge Detection");
}

void loop() {
  // read the shock sensor state into a varialbe
  sensorState = digitalRead(sensorPin);

  // compare the sensorState to its previous state
  if (sensorState != lastSensorState) {

    // print out the value of the shock sensor
    Serial.print("value: ");  Serial.println(sensorState);

    // Keep in mind the pullup means the sensor's logic is inverted. It goes
    // HIGH when it's open, and LOW when it's close. Turn on LED when the
    // sensor detects a shock signal, and off when it's not:
    if (sensorState == LOW) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }

    // Delay a little bit to avoid bouncing
    delay(50);
  }

  // save the current state as the last state, for next time through the loop
  lastSensorState = sensorState;
}
