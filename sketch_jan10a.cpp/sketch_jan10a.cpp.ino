#define joyX A0
#define joyY A1
const int joySw = 12;

const int motorLeftPin1 = 2;
const int motorLeftPin2 = 3;

const int motorRightPin1 = 4;
const int motorRightPin2 = 5;

const int motorLeft[] = {motorLeftPin1, motorLeftPin2};
const int motorRight[] = {motorRightPin1, motorRightPin2};

const int motorSpeedPin = 6;

const int buttonPins[] = {8,9,10,11};

int buttonStates[] = {0,0,0,0};

const int deadZone = 40;
int minSpeed = 100;

bool isDriving = false;

float xVal = 0;
float yVal = 0;
float vel = 0;



void setup() {
  // put your setup code here, to run once:
  pinMode(motorLeftPin1, OUTPUT);
  pinMode(motorLeftPin2, OUTPUT);
  pinMode(motorRightPin1, OUTPUT);
  pinMode(motorRightPin2, OUTPUT);

  pinMode(motorSpeedPin, OUTPUT);

  for (int i = 0; i < 4; ++i){
    pinMode(buttonPins[i], INPUT); 
  }

  pinMode(joyX, INPUT);
  pinMode(joyY, INPUT);
  pinMode(joySw, INPUT);

  Serial.begin(9600);
}

void loop() {

  for(int i = 0; i < 4; ++i){
    buttonStates[i] = digitalRead(buttonPins[i]);
    if (buttonStates[i] == HIGH) {
      Serial.print(i);
    }
  }
  
  setDir(motorLeft,0);
  setDir(motorRight,0);
  

  readInput();
  
  //Controlling spin direction of motors:
  while(isDriving){
    //steering left
    if(xVal < 512-deadZone){
      vel = abs(xVal-512)*0.02+minSpeed;
      setDir(motorLeft,2);
      setDir(motorRight,1);
    }
    //steering right
    if(xVal > 512+deadZone){
      vel = abs(xVal-512)*0.02+minSpeed;
      setDir(motorLeft,1);
      setDir(motorRight,2);
    }
    //drive forward
    if(yVal > 512+deadZone){
      vel = abs(yVal-512)*0.02+minSpeed;
      setDir(motorLeft,1);
      setDir(motorRight,1);
    }
    //drive backward
    if(yVal < 512-deadZone){
      vel = abs(yVal-512)*0.02+minSpeed;
      setDir(motorLeft,2);
      setDir(motorRight,2);
    }
    //Controlling speed (0 = off and 255 = max speed):
    
    //vel = abs(yVal-512)*0.02+75;
    analogWrite(motorSpeedPin, vel); //ENA pin
    Serial.println(vel);
    Serial.println(xVal);
    Serial.println(yVal);
    readInput();
  }

}

void setDir(const int pin1, const int pin2, int dir){
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

void readInput(){
  isDriving = 0;
  xVal = analogRead(joyX);
  yVal = analogRead(joyY);

  if ((xVal > 512-deadZone && xVal < 512+deadZone) && (yVal > 512-deadZone && yVal < 512+deadZone)){
    if (isDriving) {
      isDriving = false;
      setDir(motorLeft, 0);
      setDir(motorRight, 0);
    }
  } else {
    
    if (!isDriving){
      isDriving = true;
      Serial.print("here");
    }
  }
}

void setDir(const int pins[], int dir){
  setDir(pins[0], pins[1], dir);
}
