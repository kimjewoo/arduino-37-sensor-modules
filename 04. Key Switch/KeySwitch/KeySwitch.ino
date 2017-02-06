/*
  Key Switch

  This module has a 10K-ohm pull-up resistor to +5V. This configuration causes
  the input to read HIGH when the switch is open, and LOW when it is closed.
  See http://www.arduino.cc/en/Tutorial/InputPullupSerial

  * Note: because most Arduinos have a built-in LED attached to pin 13 on the
  board, the LED is optional.
*/

// this constant won't change:
const int buttonPin = 3;      // the pin that the pushbutton is attached to
const int ledPin = 13 ;       // the pin that the LED is attached to

// Variables will change:
int buttonState = 0;          // current state of the shock

void setup() {
  pinMode(buttonPin, INPUT);  // initialize the pushbutton pin as a input
  pinMode(ledPin, OUTPUT);    // initialize the LED as an output

  Serial.begin(9600);
  Serial.println("Arduino Examples - Key Switch");
}

void loop() {
  // read the shock sensor state into a varialbe
  buttonState = digitalRead(buttonPin);
  // print out the value of the shock sensor
  Serial.print("value: ");  Serial.println(buttonState);

  // Keep in mind the pullup means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  if (buttonState == LOW) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(500); // just here to slow down the output so it is easier to read
}
