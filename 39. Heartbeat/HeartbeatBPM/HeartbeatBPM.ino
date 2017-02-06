////////////////////////////////////////////////////////////////////////
/// Copyright (c)2015 Dan Truong
/// Permission is granted to use this software under the MIT
/// licence, with my name and copyright kept in source code
/// http://http://opensource.org/licenses/MIT
///
/// KY039 Arduino Heartrate Monitor V1.0 (April 02, 2015)
////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
/// @param[in] IRSensorPin Analog pin on which IR detector is connected
/// @param[in] delay (msec) delay between calls to this method. It is
///                  best to call it at least 5 times per beat, aka
///                  no slower than 150msec for 70bpm. An ideal value
///                  is 60ms or faster to handle up to 200 BPM.
///
/// @brief
/// True if heartbeat is detected on the sensor.
/// This code is trivial and just does a peak detection, instead of
/// trying to detect the heart's pulse waveform.
/// Note: I am fudging sensor data with the delay to make the integer
/// math after that uses constants, somewhat independant of the sleep
/// delay used in the main loop. Otherwise if maxValue decays too slow
/// or too fast, it causes glitches and false beat detection.
////////////////////////////////////////////////////////////////////////
//#define HBDEBUG(i) i
#define HBDEBUG(i)

bool heartbeatDetected(int IRSensorPin, int delay)
{
  static int maxValue = 0;
  static bool isPeak = false;
  int rawValue;
  bool result = false;
    
  rawValue = analogRead(IRSensorPin);
  // Separated because analogRead() may not return an int
  rawValue *= (1000/delay);
  HBDEBUG(Serial.print(isPeak); Serial.print("p, "));
  HBDEBUG(Serial.print(rawValue); Serial.print("r, "));
  HBDEBUG(Serial.print(maxValue); Serial.print("m, "));

  // If sensor shifts, then max is out of whack.
  // Just reset max to a new baseline.
  if (rawValue * 4L < maxValue) {
    maxValue = rawValue * 0.8;
    HBDEBUG(Serial.print("RESET, "));
  }
  
  // Detect new peak
  if (rawValue > maxValue - (1000/delay)) {
    // Only change peak if we find a higher one.
    if (rawValue > maxValue) {
      maxValue = rawValue;
    }
    // Only return true once per peak.
    if (isPeak == false) {
      result = true;
      Serial.print(result); Serial.print(",  *");
    }
    isPeak = true;
  } else if (rawValue < maxValue - (3000/delay)) {
    isPeak = false;
    // Decay max value to adjust to sensor shifting
    // Note that it may take a few seconds to re-detect
    // the signal when sensor is pushed on meatier part
    // of the finger. Another way would be to track how
    // long since last beat, and if over 1sec, reset
    // maxValue, or to use derivatives to remove DC bias.
    maxValue-=(1000/delay);
 }
  HBDEBUG(Serial.print("\n"));
  return result;
}

////////////////////////////////////////////////////////////////////////
// Arduino main code
////////////////////////////////////////////////////////////////////////
//int ledPin=13;
int analogPin=0;

void setup()
{
  // Built-in arduino board pin for the display LED
  //pinMode(ledPin,OUTPUT);
  
  // Init serial console
  Serial.begin(9600);
  Serial.println("Heartbeat detection sample code.");
}

const int delayMsec = 60; // 100msec per sample

// The main loop blips the LED and computes BPMs on serial port.
void loop()
{
  static int beatMsec = 0;
  int heartRateBPM = 0;
  
  if (heartbeatDetected(analogPin, delayMsec)) {
    heartRateBPM = 60000 / beatMsec;
    //digitalWrite(ledPin,1);

    // Print msec/beat and instantaneous heart rate in BPM
    Serial.print(beatMsec);
    Serial.print(", ");
    Serial.println(heartRateBPM);
    
    beatMsec = 0;
  } else {
    //digitalWrite(ledPin,0);
  }
  // Note: I assume the sleep delay is way longer than the
  // number of cycles used to run the code hence the error
  // is negligible for math.
  delay(delayMsec);
  beatMsec += delayMsec;
}
