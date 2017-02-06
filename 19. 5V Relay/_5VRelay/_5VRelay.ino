/*
  5V Relay module
*/

const int relay = 3; // relay turns trigger signal - active high;

void setup() {
  pinMode(13, OUTPUT);      // Set Pin13 as output
  digitalWrite(13, HIGH);   // Set Pin13 High
  pinMode(relay, OUTPUT);  // Define port attribute is output;

  Serial.begin(9600);
  Serial.println("Arduino Examples - 5V Relay");
}

void loop() {
  Serial.println("relay switch is turned on");
  digitalWrite(relay, HIGH); // relay switch is turned on;
  delay(1000);

  Serial.println("relay switch is turned off");
  digitalWrite(relay, LOW);  // relay switch is turned off;
  delay(1000);
}
