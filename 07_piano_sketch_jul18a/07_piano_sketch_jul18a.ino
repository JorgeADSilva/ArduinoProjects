int notes[] = {262, 294};
const int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);

}

void loop() {
  
  digitalWrite(ledPin, HIGH);
  delay(25);

  int keyVal = analogRead(A0);

  Serial.println(keyVal);
  if(keyVal >= 505 && keyVal <= 1500){
    tone(8, notes[1]); 
  } else{
 noTone(8);
 }
  
  digitalWrite(ledPin, LOW);
  
  
} // go back to the beginning of the loop
