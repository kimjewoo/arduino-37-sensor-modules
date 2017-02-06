/*
  Laser Transmitter
*/

const int laserPin = 3;   // the pin that the laser is attached to

void setup() {
  pinMode(laserPin, OUTPUT);   // initialize the laser as an output

  Serial.begin(9600);
  Serial.println("Arduino Examples - Laser Transmitter");
}

void loop() {
  // turn on the laser head:
  Serial.print("output: ");  Serial.println(HIGH);
  digitalWrite(laserPin, HIGH);

  delay(1000); // delay one second

  // turn off the laser head:
  Serial.print("output: ");  Serial.println(LOW);
  digitalWrite(laserPin, LOW);

  delay(1000); // delay one second
}
