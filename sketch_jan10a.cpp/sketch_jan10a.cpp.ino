int motorLeftPin1 = 2;
int motorLeftPin2 = 3;

int motorRightPin1 = 4;
int motorRightPin2 = 5;

int motorLeft[] = {motorLeftPin1, motorLeftPin2};
int motorRight[] = {motorRightPin1, motorRightPin2};

define joyX A0
define joyY A1

int motorSpeedPin = 6;


void setup() {
  // put your setup code here, to run once:
  pinMode(motorLeftPin1, OUTPUT);
  pinMode(motorLeftPin2, OUTPUT);
  pinMode(motorRightPin1, OUTPUT);
  pinMode(motorRightPin2, OUTPUT);

  pinMode(motorSpeedPin, OUTPUT);

  pinMode(joyX, INPUT);
  pinMode(joyY, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:   

  //read joystick input
  xVal = analogRead(joyX);
  yVal = analogRead(joyY);
  
  //Controlling speed (0 = off and 255 = max speed):
  analogWrite(motorSpeedPin, 100); //ENA pin
  
  //Controlling spin direction of motors:
  while(xVal != 0 || yVal != 0){
  setDir(motorLeft, 2);

  setDir(motorRight, 2);
  delay(1000);

  setDir(motorLeft, 1);

  setDir(motorRight, 1);
  delay(1000);
  }
}

void setDir(int pin1, int pin2, int dir){
  // 0 = stop, 1 = forward, 2 = backwards
  if (dir == 0){
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
  } else if (dir == 1){
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
  } else if (dir == 2) {
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
  }
}

void setDir(int pins[], int dir){
  setDir(pins[0], pins[1], dir);
}

void turn(int deg){
  // turn deg degrees, negative for left, positive for right
  
}

void drive(int deg){
  // drive deg degrees forward
  
}
