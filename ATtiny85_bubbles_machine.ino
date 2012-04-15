// ATtiny85 bubbles machine (SeifenblasenMASCHINE)
//
// using an Arduino to program the ATtiny85
// should also work with an Arduino (pins should be changed)


#include <SoftwareServo.h> 

SoftwareServo servo;

// pin 0 - servo
// pin 1 - fan

void setup() 
{ 
  servo.attach(0);
  pinMode(1, OUTPUT);
  digitalWrite(1, LOW);
} 

void loop() 
{ 
  int val;
  int startVal = servo.read();
  for(val = startVal; val < 90; val++) {
    servo.write(val);
    delay(15);
    SoftwareServo::refresh();
  }
  
  delay(500);  
  digitalWrite(1, HIGH); // start fan
  delay(3000);
  digitalWrite(1, LOW); // stop fan
  delay(500);  

  for(val = 90; val >= 0; val--) {
    servo.write(val);
    delay(15);
    SoftwareServo::refresh();
  }
} 

