/*
  Light Cup

  This module constist of a mercury tilt switch and a LED. The tilt switch is
  trigger to the LED in this module.
*/

const int pinLed = 5;     // the pin that the LED is attached to
const int pinInput = 4;   // the pin that the switch is attached to

int stateA = 0;
int brightness = 0;
int oldBrightness = 0;

void setup() {
 pinMode(pinLed, OUTPUT);   // initialize the sensor pin as a output
 pinMode(pinInput, INPUT);  // initialize the sensor pin as a input
 digitalWrite(pinInput, HIGH);

 Serial.begin(9600);
 Serial.println("Arduino Examples - Light Cup");
}

void loop() {
  stateA = digitalRead(pinInput);

  if (stateA == HIGH && brightness < 255)
    brightness++;
  if (stateA == LOW && brightness >0)
     brightness--;

  if (oldBrightness != brightness) {
    Serial.print("brightness:");
    Serial.println(brightness);
    analogWrite(pinLed, brightness);
  }

  oldBrightness = brightness;

  delay(100); //just here to slow down the output so it is easier to read
}
