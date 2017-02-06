/*
  2-Color LED (3mm)

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.
*/

// this constant won't change:
const int redpin = 11;    // the PWM pin the red LED is attached to
const int greenpin = 10;  // the PWM pin the green LED is attached to

// variables will change:
int val;

void setup() {
  // declare PWM pin to be an output:
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);

  Serial.begin(9600);
  Serial.println("Arduino Examples - 2-Color LED");
}

void loop() {
  for (val = 255; val > 0; val--) {
    analogWrite(greenpin, val);
    analogWrite(redpin, 255 - val);
    Serial.print("value: ");  Serial.println(val);
    // wait for 15 milliseconds to see the dimming effect
    delay(15);
  }
  for (val = 0; val < 255; val++) {
    analogWrite(greenpin, val);
    analogWrite(redpin, 255 - val);
    Serial.print("value: ");  Serial.println(val);
    // wait for 15 milliseconds to see the dimming effect
    delay(15);
  }
}
