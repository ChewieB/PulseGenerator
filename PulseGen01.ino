//Pulse Generator 01
// (c) Matt Baker 2019
// Phase 2
// A0 frequency 10 -100 Hz
// A1 Pulse Width 1 - 100 ms

// D13 Pulse O/P
// D12 Trigger O/P

#define ouputPin 13
#define triggerOutPin 12

void setup() {
  Serial.begin(9600);
  pinMode(ouputPin, OUTPUT);
  pinMode(triggerOutPin, OUTPUT);
}

void loop() 
{
  // read pots to get pulse paramaters
  int frequencyIn = analogRead(A0);
  int pulseWidthIn = analogRead(A1);

  // Pulse the Trigger output Hi Lo for 3 us
  digitalWrite(triggerOutPin, HIGH);
  delayMicroseconds(3);
  digitalWrite(triggerOutPin, LOW);
  
  // Set Pulse O/P Hi
  digitalWrite(ouputPin, HIGH);

  // Frequency calc
  float frequency = 10.0 + (float)frequencyIn / 10.24;
  
  // Pulse period calc
  float tTotal = 1.0 / frequency; // in seconds
    
  // Calculate pulse width 0-1023 1-11 ms
  float pulseWidth = (((float)pulseWidthIn/100.0) * 1000.0) + 1000.0;

  // Wait for the pulse width time
  delayMicroseconds(pulseWidth);

  // Calculate Off time
  float tOff = (tTotal * 1e6) - (pulseWidth);
  if (tOff > 0)
  {
    delayMicroseconds(tOff);
    // Set Pulse O/P lo
    digitalWrite(ouputPin, LOW);
  }
}
