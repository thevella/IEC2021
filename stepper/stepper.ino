#include <Stepper.h>
#define STEPS 2038
Stepper stepper(STEPS, 8, 10, 9, 11);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
stepper.setSpeed(15);
stepper.step(2038);
}
