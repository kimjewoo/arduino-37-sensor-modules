/*
  Linear Hall

  * Note: because most Arduinos have a built-in LED attached to pin 13 on the
  board, the LED is optional.

  * Note: The polarity of the magnetic field is of influence to the switching
  action. The front side of the sensor needs the opposite polarity as the back
  of the sensor to switch on (front:S, back:N).
*/

// this constant won't change:
const int digitalPin = 3;    // the digital pin that the sensor is attached to
const int analogPin = A3;    // the analog pin that the sensor is attached to
const int ledPin = 13;       // the pin that the LED is attached to

// variables will change:
int sensorState;    // current digital state of the sensor
float sensorValue;  // current analoog value of the sensor

void setup() {
  pinMode(digitalPin, INPUT);   // initialize the sensor pin as a digital input
  pinMode(analogPin, INPUT);    // initialize the sensor pin as a analog input
  pinMode(ledPin, OUTPUT);      // initialize the LED as an output

  Serial.begin(9600);
  Serial.println("Arduino Examples - Linear Hall");
}

void loop() {
  // read the sensor analog value into a varialbe
  sensorValue = analogRead(analogPin);
  // read the sensor digital state into a varialbe
  sensorState = digitalRead(digitalPin);

  Serial.print("value");
  Serial.print("\t analog: ");  Serial.print(sensorValue);
  Serial.print("\t digital: ");  Serial.println(sensorState);

  // When the sensor detects a signal and reches a certain threshold
  if (sensorState == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(500); //just here to slow down the output so it is easier to read
}
