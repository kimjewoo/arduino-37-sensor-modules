/*
  Heartbeat
*/

int sensorPin = 0;

double alpha = 0.75;
double change = 0.0;
double minval = 0.0;

void setup() {
    Serial.begin(9600);
    Serial.println("Arduino Examples - Heartbeat");
}

void loop() {
    static double oldValue = 0;
    static double oldChange = 0;

    int rawValue = analogRead(sensorPin);
    double value = alpha * oldValue + (1 - alpha) * rawValue;

    Serial.print("Raw Value:");
    Serial.print(rawValue);
    Serial.print(", Value:");
    Serial.println(value);
    oldValue = value;

    delay(500); //just here to slow down the output so it is easier to read
}
