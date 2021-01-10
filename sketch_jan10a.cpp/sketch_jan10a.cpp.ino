int motorLeftDirPin = 2;
int motorLeftOnPin = 3;

int motorRightDirPin = 4;
int motorRightOnPin = 5;

int motorSpeedPinLeft = 9;
int motorSpeedPinRight = 10;


void setup() {
  // put your setup code here, to run once:
  pinMode(motorLeftDirPin, OUTPUT);
  pinMode(motorLeftOnPin, OUTPUT);
  pinMode(motorRightDirPin, OUTPUT);
  pinMode(motorRightOnPin, OUTPUT);

  pinMode(motorSpeedPinLeft, OUTPUT);
  pinMode(motorSpeedPinRight, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:   

  //Controlling speed (0 = off and 255 = max speed):
  analogWrite(motorSpeedPinLeft, 250); //ENA pin
  analogWrite(motorSpeedPinRight, 250);

  //Controlling spin direction of motors:
  digitalWrite(motorLeftDirPin, HIGH);
  digitalWrite(motorLeftOnPin, LOW);

  digitalWrite(motorRightDirPin, HIGH);
  digitalWrite(motorRightOnPin, LOW);
  delay(1000);

  digitalWrite(motorLeftDirPin, LOW);
  digitalWrite(motorLeftOnPin, HIGH);

  digitalWrite(motorRightDirPin, LOW);
  digitalWrite(motorRightOnPin, HIGH);
  delay(1000);
}

void turn(int deg){
  // turn deg degrees, negative for left, positive for right
  
}

void drive(int deg){
  // drive deg degrees forward
  
}
