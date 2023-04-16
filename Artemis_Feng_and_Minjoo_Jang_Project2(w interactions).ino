#include <Servo.h>
//servos
Servo house;
Servo treeMonster;
Servo leftDoor;
Servo rightDoor;

//setup button hangret (house --> trees swivel)
const int hangret = 2;
int buttonHGState;
int lastButtonHGState = 0;
bool HG = false;

//setup button monster (tree --> monster swivel)
const int monster = 4;
int buttonMonState;
int lastButtonMonState = 0;
bool Mon = false;

//setup button left candy (triggers left door servo)
const int candyLeft = 6;
int buttonLeftState;
int lastButtonLeftState = 0;
bool left = false;

const int candyRight = 7;
int buttonRightState;
int lastButtonRightState = 0;
bool right = false;

void setup() {
  Serial.begin(9600);
  house.attach(10);
  Serial.println(house.read());
  house.write(0);

  treeMonster.attach(11);
  treeMonster.write(0);

  rightDoor.attach(12);
  rightDoor.write(0);

  leftDoor.attach(13);
  leftDoor.write(0);
  pinMode(hangret, INPUT); // Set Button 1 pin as input with internal pullup resistor
  pinMode(monster, INPUT);
  pinMode(candyLeft, INPUT);



  //pinMode(candyRight, INPUT);
}

void loop() {

  buttonHGState = digitalRead(hangret);
  if (!HG == true && buttonHGState != lastButtonHGState) {
    if(buttonHGState == HIGH){
      Serial.println("AH! WE ARE IN THE FOREST... NO MORE HOUSE"); // Print message to serial monitor
      for(int i=house.read(); i<=180; i++){
        house.write(i);
        delay(15);
      }
    }
    HG = true;
  }

  buttonMonState = digitalRead(monster); //thinking of adding another monster (Scary Monkeys around trees)
  if(HG && !Mon == true && buttonMonState != lastButtonMonState){
    if(buttonMonState == HIGH){
      Serial.println("TREE MONSTER LURKS.");
      for(int i=0; i<=180; i++){
        treeMonster.write(i);
        delay(15);
      }
    }
    Mon = true;
  }

  buttonLeftState = digitalRead(lastButtonLeftState);
  buttonRightState = digitalRead(lastButtonRightState);
  if(Mon && HG){
    if(buttonLeftState != lastButtonLeftState){
      if(buttonLeftState == HIGH){
        Serial.println("LEFT CANDY INITIATED... LEFT DOOR UNLOCKED");
        for(int i=0; i<=90; i++){
          leftDoor.write(i);
          delay(15);
       }
      }
      left = true;
    }
    if(buttonRightState != lastButtonRightState){
      if(buttonRightState == HIGH){
        Serial.println("RIGHT CANDY INITIATED... RIGHT DOOR UNLOCKED");
        for(int i=0; i<=90; i++){
          rightDoor.write(i);
          delay(15);
       }
      }
      right = true;
    }
  }
  lastButtonHGState = buttonHGState;
  lastButtonMonState = buttonMonState;
  lastButtonLeftState = buttonLeftState;
  lastButtonRightState = buttonRightState;
  
  
}
