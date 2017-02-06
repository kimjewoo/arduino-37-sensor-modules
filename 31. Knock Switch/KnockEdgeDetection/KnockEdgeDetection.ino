/*
  Knock Switch - Edge Detection

  You need to know when the input changes from one state to another. This is
  called state change detection, or edge detection.
  See http://www.arduino.cc/en/Tutorial/ButtonStateChange

  This module has a 10K-ohm pull-up resistor to +5V. This configuration causes
  the input to read HIGH when the switch is open, and LOW when it is closed.

  * Note: because most Arduinos have a built-in LED attached to pin 13 on the
  board, the LED is optional.
*/

// this constant won't change:
const int shockPin = 3;      // the pin that the shock sensor is attached to
const int ledPin = 13;       // the pin that the LED is attached to

// variables will change:
int shockState = 0;          // current state of the shock
int lastShockState = 0;      // previous state of the shock

void setup() {
  pinMode(shockPin, INPUT);   // initialize the shock pin as a input
  pinMode(ledPin, OUTPUT);    // initialize the LED as an output

  // initialize serial communication at 9600 baud rate:
  Serial.begin(9600);
  Serial.println("Arduino Examples - Knock Switch - Edge Detection");
}

void loop() {
  // read the shock sensor state into a varialbe
  shockState = digitalRead(shockPin);

  // compare the shockState to its previous state
  if (shockState != lastShockState) {

    // print out the value of the shock sensor
    Serial.print("value: ");  Serial.println(shockState);

    // Keep in mind the pullup means the shock's logic is inverted. It goes
    // HIGH when it's open, and LOW when it's close. Turn on LED when the
    // sensor detects a shock, and off when it's not:
    if (shockState == LOW) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }

  // save the current state as the last state, for next time through the loop
  lastShockState = shockState;
}
