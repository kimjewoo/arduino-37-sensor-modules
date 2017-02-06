/*
  SMD RGB LED

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.
*/

// this constant won't change:
const int redpin = 11;    // the PWM pin the red LED is attached to
const int bluepin = 10;   // the PWM pin the blue LED is attached to
const int greenpin = 9;   // the PWM pin the green LED is attached to

// variables will change:
int val;

void setup() {
  // declare PWM pin to be an output:
  pinMode(redpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(greenpin, OUTPUT);

  Serial.begin(9600);
  Serial.println("Arduino Examples - SMD RGB LED");
}

void loop() {
  for (val = 255; val > 0; val--) {
    analogWrite(redpin, val);
    analogWrite(bluepin, 255 - val);
    analogWrite(greenpin, 128 - val);
    Serial.print("RGB value: ");  Serial.println(val);
    // wait for 10 milliseconds to see the dimming effect
    delay(10);
  }
  for (val = 0; val < 255; val++) {
    analogWrite(redpin, val);
    analogWrite(bluepin, 255 - val);
    analogWrite(greenpin, 128 - val);
    Serial.print("RGB value: ");  Serial.println(val);
    // wait for 10 milliseconds to see the dimming effect
    delay(10);
  }
}
