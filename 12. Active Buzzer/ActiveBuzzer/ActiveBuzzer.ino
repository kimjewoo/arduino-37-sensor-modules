/*
  Active Buzzer
 */

const int buzzPin =  3;       // the pin that the buzzer is attached to

void setup() {
  pinMode(buzzPin, OUTPUT);   // initialize the buzzer as an output

  Serial.begin(9600);
  Serial.println("Arduino Examples - Active Puzzer");
}

// the loop function runs over and over again forever
void loop() {
  // turn on the buzzer:
  Serial.print("output: ");  Serial.println(HIGH);
  digitalWrite(buzzPin, HIGH);
  delay(1000);

  // turn off the buzzer:
  Serial.print("output: ");  Serial.println(LOW);
  digitalWrite(buzzPin, LOW);
  delay(1000);
}
