const int motorLeftPin1 = 2;
const int motorLeftPin2 = 3;

const int motorRightPin1 = 4;
const int motorRightPin2 = 5;

const int motorLeft[] = {motorLeftPin1, motorLeftPin2};
const int motorRight[] = {motorRightPin1, motorRightPin2};

const int motorSpeedPin = 6;

const int buttonPins[] = {8,9,10,11};

int buttonStates[] = {0,0,0,0};



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

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:   
  //Controlling speed (0 = off and 255 = max speed):
  analogWrite(motorSpeedPin, 75); //ENA pin

  for(int i = 0; i < 4; ++i){
    buttonStates[i] = digitalRead(buttonPins[i]);
    if (buttonStates[i] == HIGH) {
      Serial.print(i);
    }
  }
  
  //Controlling spin direction of motors:
  /*
  setDir(motorLeft, 2);

  setDir(motorRight, 2);
  delay(10);

  setDir(motorLeft, 1);

  setDir(motorRight, 1);
  delay(1000);
  */
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

void setDir(const int pins[], int dir){
  setDir(pins[0], pins[1], dir);
}
