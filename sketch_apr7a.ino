const int hangret = 2;  // Pin connected to Button 1
const int monster = 4;
const int candyLeft = 6;
const int candyRight = 7;
int buttonHG;
int buttonMon;
int buttonL;
int buttonR;

void setup() {
  Serial.begin(9600);
  pinMode(hangret, INPUT);  // Set Button 1 pin as input with internal pullup resistor
  pinMode(monster, INPUT);
  pinMode(candyLeft, INPUT);
  pinMode(candyRight, INPUT);
}

void loop() {
  buttonHG= digitalRead(hangret);
  buttonMon= digitalRead(monster);
  buttonL= digitalRead(candyLeft);
  buttonR= digitalRead(candyRight);
  if (buttonHG== HIGH) {  // If Button 1 is pressed
    Serial.println("hangret");  // Print message to serial monitor
  }
  if (buttonMon== HIGH) {  // If Button 1 is pressed
    Serial.println("monster");  // Print message to serial monitor
  }
  if (buttonL== HIGH) {  // If Button 1 is pressed
    Serial.println("L candy");  // Print message to serial monitor
  }
  if (buttonR== HIGH) {  // If Button 1 is pressed
    Serial.println("R candy");  // Print message to serial monitor
  }  
}
