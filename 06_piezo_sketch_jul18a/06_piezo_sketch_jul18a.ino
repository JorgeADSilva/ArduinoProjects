int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;
//LED PIN (marked as L in the arduino)
const int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  //Callibrate for the first five seconds after program runs
  // the function millis allows us to know the time passed since the arduino started
  while(millis() < 5000){
    //record the maximum sensor value
    sensorValue = analogRead (A0);
    if(sensorHigh > sensorValue){
      sensorHigh = sensorValue;
    }
    //record the minimum sensor value
    if(sensorLow < sensorValue){
      sensorLow = sensorValue;
    }
  }
  //TURN THE LED OFF, SIGNALING THE END OF THE CALIBRATION PERIOD
  digitalWrite(ledPin, HIGH);
  
}

void loop() {
  
  digitalWrite(ledPin, HIGH);
  delay(25);
  //read the input from A0 and store it in a variable
  sensorValue = analogRead(A0);

  // map the sensor values to a wide range of pitches
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);

  // play the tone for 20 ms on pin 8
  tone(8, pitch, 20);
  
  digitalWrite(ledPin, LOW);

  delay(1005);
  
} // go back to the beginning of the loop
