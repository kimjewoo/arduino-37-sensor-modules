/*
  Rotary Encoder
*/

int totalCount = 0;
int S = 2;    // SW: Switch
int pinA = 3; // DT
int pinB = 4; // CLK

void setup() {
  pinMode(S, INPUT);
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);

  digitalWrite(S, HIGH);

  Serial.begin(9600);
  Serial.println("Arduino Examples - Rotary Encoder");
}

int nowCnt = 0;

void loop() {
  if (LOW == digitalRead(S)) {
    Serial.println("Clear");
    delay(200);
    totalCount = 0;
  }
  else {
    //Serial.print(".");
  }

  nowCnt = getValue();

  if (nowCnt != 0) {
    totalCount += nowCnt;
    Serial.print("Total Count: ");
    Serial.println(totalCount);
  }
}

int oldA = LOW;
int oldB = LOW;

int getValue()
{
  int rValue = 0;
  int A = digitalRead(pinA);
  int B = digitalRead(pinB);

  if (A != oldA || B != oldB) {
    if (oldA == LOW && A == HIGH) {
      if (oldB == HIGH) rValue = 1;
      else rValue = -1;
    }
  }
  oldA = A;
  oldB = B;

  return rValue;
}
