
int motor  = 11;
int hbridge = 5;

void setup() {
  pinMode(motor, OUTPUT);
 // pinMode(hbridge, OUTPUT);

  analogWrite(motor, 250);
    digitalWrite(motor, 250);
 digitalWrite(motor, HIGH);
   analogWrite(motor, HIGH);

}

void loop() {


}
