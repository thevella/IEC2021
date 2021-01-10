int motorLeftPin1 = 2;
int motorLeftPin2 = 3;

int motorRightPin1 = 4;
int motorRightPin2 = 5;

int motorLeft[] = {motorLeftPin1, motorLeftPin2};
int motorRight[] = {motorRightPin1, motorRightPin2};

#define joyX A0
#define joyY A1
int joySw = 7;

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
  pinMode(joySw, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:   
  int isDriving;
  //read joystick input
  float xVal = analogRead(joyX);
  float yVal = analogRead(joyY);
  float vel;
  

  //check if controller is in deadzone
  if ((xVal > 512-20 && xVal < 512+20) && (yVal > 512-20 && yVal < 512+20)){
    isDriving = 0;
  }
  else{
    isDriving = 1;
  }
  
  //Controlling spin direction of motors:
  while(isDriving == 1){
    //steering left
    if(xVal < 512-20){
      setDir(motorLeft,2);
      setDir(motorRight,1);
    }
    //steering right
    if(xVal > 512+20){
      setDir(motorLeft,1);
      setDir(motorRight,2);
    }
    //drive forward
    if(yVal > 512+20){
      setDir(motorLeft,1);
      setDir(motorRight,1);
    }
    //drive backward
    if(yVal < 512-20){
      setDir(motorLeft,2);
      setDir(motorRight,2);
    }
    //Controlling speed (0 = off and 255 = max speed):
    
    vel = abs(yVal+512)*0.02+65;
    analogWrite(motorSpeedPin, vel); //ENA pin
    Serial.println(vel);
    Serial.println(xVal);
    Serial.println(yVal);

    if ((xVal > 512-20 && xVal < 512+20) && (yVal > 512-20 && yVal < 512+20)){
    isDriving = 0;
    delay(1000);
  }
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
