//Parker Davis code for Parker, Joey, Jordan, CHRISSY
//12/14/15
//big robot test

int motorone = 5;
int motortwo = 6;
int led = 13;
void setup() {
  pinMode(motorone, OUTPUT); // set pin 5 drives motor
  pinMode(motortwo, OUTPUT); //set pin 4 drives motor
  pinMode(led,OUTPUT); //sets pin 13 to on
}

void loop() {
  //analogWrite(motorone, HIGH);
  //analogWrite(motortwo, HIGH);
  delay(3000);
  for (int k = 100; k <= 255; k = k + 5)
  {
    analogWrite(motorone, k);
    analogWrite(motortwo, k);
    delay(500);
  }
  analogWrite(motorone, 255);
  analogWrite(motortwo, 255);
  digitalWrite(led,HIGH);
  delay(900);
  digitalWrite(led, LOW);
  analogWrite(motorone, 0);
  analogWrite(motortwo, 0);
  delay(400);
}
