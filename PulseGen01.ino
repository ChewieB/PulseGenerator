//Pulse Generator 01
// (c) Matt Baker 2019
// Phase 1
// A0 Pulse Width
// A1 Pulse gap spacing

// D13 Pulse O/P



void setup() {
  pinMode(13, OUTPUT);
  
}

void loop() 
{
  int pulseWidth = analogRead(A0);
  int pulseGap = analogRead(A1);
  
}
