/*
  Analog Temperature
 */

#include <math.h>

const int sensorPin = A5;   // the pin that the thermistor is attached to

void setup() {
  Serial.begin(9600);
  Serial.println("Arduino Examples - Analog Temperature");
}

void loop() {
  // read the input on analog pin
  int readVal = analogRead(sensorPin);
  double temp =  Thermistor(readVal);

  // display tempature:
  Serial.print("value:"); Serial.print(readVal);
  Serial.print("\t Temperature for Device is: ");
  Serial.print(temp);
  Serial.println(" C.");

  delay(500); //just here to slow down the output so it is easier to read
}

float Thermistor(int RawADC) {
  float temp;
  int reading = analogRead(RawADC);     // (0~1023)
  float sensorV = reading*5.0/1024.0;   // (0~5)
  float sensorR = (( 5.0 * 10000.0 )/ sensorV ) - 10000.0;
  float kT = 1.0 / ((1.0 / (273.15 + 25.0)) + (1.0 / 4200.0) * log (sensorR / 10000.0));
  temp = kT-273.15;                     // Convert Kelvin to Ceicius
  //temp = (temp * 9.0) / 5.0 + 32.0;   // Convert Ceicius to Fahrenheit
  return temp;
}
