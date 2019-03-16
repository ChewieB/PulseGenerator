//Pulse Generator 01
// (c) Matt Baker 2019
// Phase 1
// A0 Pulse Width
// A1 Pulse gap spacing

// D13 Pulse O/P

#define D13 13

void setup() {
  pinMode(13, OUTPUT);
  
}

void loop() 
{
  // read pots to get pulse paramaters
  int pulseWidth = analogRead(A0);
  int pulseGap = analogRead(A1);

  // Set Pulse O/P Hi
  digitalWrite(D13, HIGH);

  // Calculate pulse width 1024/4 gives a range of 0-255
  // 0 to 1/4 seconds can be checked by observation
  pulseWidth /= 4;

  // Calculate pulse gap this is going to be 3 times bigger for max values
  // No good reason just going with it. Later will go for pulse frequency and width
  pulseGap /= (3.0/4.0);

  // Wait for the pulse width time
  delay(pulseWidth);

  // Set Pulse O/P lo
  digitalWrite(D13, LOW);

  // Wait for the pulse gap time
  delay(pulseGap);
}
