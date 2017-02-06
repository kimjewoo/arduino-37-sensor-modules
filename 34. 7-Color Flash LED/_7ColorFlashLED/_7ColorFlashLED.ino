/*
  7-Color FlashLED

  Turns on an LED on for about 40 seconds for automatic 7 color change,
  then off for one second, repeatedly.
*/

const int ledPin = 3;      // the pin that the LED is attached to

void setup() {
  pinMode(ledPin, OUTPUT);  // initialize the LED as an output

  Serial.begin(9600);
  Serial.println("Arduino Examples - 7-Color Flash LED");
}

void loop() {
  // turn the LED on (HIGH is the voltage level):
  Serial.println("LED on");
  digitalWrite(ledPin, HIGH);

  // wait for about 40 seconds for automatic 7 color change:
  Serial.println("wait for about 40 seconds");
  delay(40000);

  // turn the LED off by making the voltage LOW:
  Serial.println("LED off");
  digitalWrite(ledPin, LOW);

  // wait for a second:
  Serial.println("wait for a second");
  delay(1000);
}
