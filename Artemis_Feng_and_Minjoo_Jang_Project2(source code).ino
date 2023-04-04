#include <Servo.h>

Servo myservo;
const int buttonPin = 2;
const int ledPin = 13;
void setup() {
  myservo.attach(9);
  pinMode(butonPin, INPUT);
  pinMode(ledPin, INPUT);

}

void loop() {
  if(digitalRead(buttonPin)==HIGH){
    myservo.write(180);
  }
  else{
    myservo.write(0);
  }
  if(digitalRead(ledPin)==HIGH){
    digitalWrite(ledPin, HIGH);
  }
  else{
    digitalWrite(ledPin, LOW);
  }

}
