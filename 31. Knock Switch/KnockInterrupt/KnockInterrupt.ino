/*
  Knock Switch - Interrupt

  There are only two interrupt pins on the Arduino Uno, they are mapped to pins
  2 and 3. See https://www.arduino.cc/en/Reference/attachInterrupt

  * Note: because most Arduinos have a built-in LED attached to pin 13 on the
  board, the LED is optional.
*/

// this constant won't change:
const int sensorPin = 3;      // the pin that the sensor which is Interrupts.
const int ledPin = 13;        // the pin that the LED is attached to

// variables will change:
unsigned char state = 0;      // current state of the sensor

void setup() {
  pinMode(ledPin, OUTPUT);    // initialize the shock pin as a input
  pinMode(sensorPin, INPUT);  // initialize the LED as an output

  // trigger the blink function when the falling edge is detected
  attachInterrupt(digitalPinToInterrupt(sensorPin), blink, FALLING);

  Serial.begin(9600);
  Serial.println("Arduino Examples - Knock Switch - Interrupt");
}

void loop() {
  Serial.print("state: ");  Serial.println (state);

  if (state != 0) {
    state = 0;
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }

  delay(500); //just here to slow down the output so it is easier to read
}

//Interrupts function
void blink() {
    state++;
}
