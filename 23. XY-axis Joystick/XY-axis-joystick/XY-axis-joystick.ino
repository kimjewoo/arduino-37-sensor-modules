/*
  XY-axis Joystick Module

  This example demonstrates the use of pinMode(INPUT_PULLUP).

  Unlike pinMode(INPUT), there is no pull-down resistor necessary. An internal
  20K-ohm resistor is pulled to 5V. This configuration causes the input to
  read HIGH when the switch is open, and LOW when it is closed.
  See http://www.arduino.cc/en/Tutorial/InputPullupSerial
 */

int JoyStick_X = A0; // x
int JoyStick_Y = A1; // y
int JoyStick_Z = 3;  // key (button)

int x, y, z;

void setup() {
  pinMode(JoyStick_X, INPUT);
  pinMode(JoyStick_Y, INPUT);
  pinMode(JoyStick_Z, INPUT_PULLUP);

  Serial.begin(9600); // 9600 bps
  Serial.println("Arduino Examples - XY-axis Joystick");
}

void loop() {
  x = analogRead(JoyStick_X);
  y = analogRead(JoyStick_Y);
  z = digitalRead(JoyStick_Z);

  Serial.print("X:");
  Serial.print(x, DEC);
  Serial.print(", ");
  Serial.print("Y:");
  Serial.print(y, DEC);
  Serial.print(", ");
  Serial.print("KEY:");
  Serial.println(z, DEC);

  delay(500); //just here to slow down the output so it is easier to read
}
