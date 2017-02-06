/*
  Photoresistor Module

  Demonstrates analog input by reading an analog sensor on analog pin 5 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead(). See http://www.arduino.cc/en/Tutorial/AnalogInput

  * Note: because most Arduinos have a built-in LED attached to pin 13 on the
  board, the LED is optional.
*/

// this constant won't change:
const int sensorPin = A5;   // select the input pin for the sensor
const int ledPin = 13;      // select the pin for the LED

// variables will change:
int sensorValue = 0;        // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
  Serial.println("Arduino Examples - Photoresistor");
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  Serial.print("value: ");  Serial.println(sensorValue, DEC);

  // turn the ledPin on
  digitalWrite(ledPin, HIGH);
  // stop the program for <sensorValue> milliseconds:
  delay(sensorValue);
  // turn the ledPin off:
  digitalWrite(ledPin, LOW);
  // stop the program for for <sensorValue> milliseconds:
  delay(sensorValue);
}
