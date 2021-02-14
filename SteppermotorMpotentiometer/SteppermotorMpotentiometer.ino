#include <Stepper.h>

const int stepsPerRevolution = 2048;
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);
float stepsPerDegree = 2048.0/360.0;
const int AnalogIN = A3;
int Pv = 0;
int potV = 0;

// the setup routine runs once when you press reset:
void setup() {
  myStepper.setSpeed(2);
  Serial.begin(9600);
  pinMode(AnalogIN, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  
  // Læser værdi fra potentiometer, og omdanner til værdi mellem 0 og 180, altså 0 grader og 180 grader.
  potV  = map(analogRead(AnalogIN), 0, 1023, 0, 180);
  
  if ( potV > Pv ) {
    Serial.println("Stepper motoren stepper 1 grad frem, hver gang potentiometeret øges med en værdi på 1");
     myStepper.step(stepsPerDegree);

  }
  if ( potV < Pv ) {
    Serial.println("Stepper motoren stepper 1 grad tilbage, hver gang potentiometeret reduceres med en værdi på 1");
    myStepper.step(-stepsPerDegree);
  }
  
  Pv = potV;
  
  Serial.println("Vinkel på steppermotor: " + String(potV));

}
