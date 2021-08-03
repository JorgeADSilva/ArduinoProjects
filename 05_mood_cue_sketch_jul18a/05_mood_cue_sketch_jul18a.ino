//include the servo library
#include <Servo.h>

Servo myServo;

int const potPin = A0;
int potVal;
int angle;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9); //attaches the servo on pin 9 to the servo object
  Serial.begin(9600); //open a serial connection to your computer
  myServo.write(1);
}

void loop() {
  
  delay(25);
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin); //read the value of the potentiometer
  //print out the value to the Serial Monitor;
  Serial.print("potVal: ");
  Serial.print(potVal);

  //scale the numbers from the pot
  angle = map( potVal, 0, 1023, 0, 179);

  Serial.print(" | angle: ");
  Serial.println(angle);

  myServo.write(angle);

  delay(25);
  
} // go back to the beginning of the loop
