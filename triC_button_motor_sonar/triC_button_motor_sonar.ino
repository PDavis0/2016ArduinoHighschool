//Parker Davis
//3-8-16
/*  OBJECTIVE:
 *   The robot will run once the button is pressed
 *  run until object is detected 10-12 inches away
 *  robot will beep once object is detected
 *  robot will turn and continue
 */
int echo = 9;             //orange wire on echo sonar, port 9
int trig = 8;             //brown wire on trig sonar, port 8
int touch = 5;            //green wire on touchsensor, port4
int leftforward = 2;      //yellow wire in in1. port 2
int leftbackward = 3;     //blue wire in in2. port 6
int rightforward = 6;     //purple wire in in3. port 3
int rightbackward = 7;    //green wire in in4. port 7
float distance = 0;       //distance away from object
float duration = 0;       //time takes to recieve echo
int buzzer = 10;          //brown wire on buzzer, port 10

void setup() {
  pinMode(leftforward, OUTPUT);     //sets pin 2 (leftforward).
  pinMode(leftbackward, OUTPUT);    //sets pin 6 (leftbackward).
  pinMode(rightforward, OUTPUT);    //sets pin 3 (rightforward).
  pinMode(rightbackward, OUTPUT);   //sets pin 7 (rightbackward).
  pinMode(touch, INPUT);            //sets pin 5 input, yellow button.
  pinMode(trig, OUTPUT);            //sets pin 8 as an output
  pinMode(echo, INPUT);             //sets pin 9 as an input
  pinMode(buzzer, OUTPUT);          //sets pin 10 as an output
  Serial.begin(9600);
  //doesnt run until button is pressed
  do {} while (digitalRead(touch) == 0); //user time to get out of arena
  delay(1000);  //1 second before motors move
}

void loop() {
  sonar();                   //reads distance in front of robot
  Serial.print(distance);
  Serial.println(" inches"); //prints distance
  if (distance <= 11)        //checks distance
  {
    motorstop();             //object detected
    Serial.println("object detected\n");
    delay(500);
    tone(buzzer, 100);  //plays tone
    delay(500);
    noTone(buzzer);      //stops buzzer
    motorback();         //robot moves backwards
    motorleft();         //turns robot left
  }
  motorforward();        //robot forward
}

void motorstop() {
  //all motors stop
  analogWrite(leftbackward, 0); //leftbackward to lowest speed.
  analogWrite(rightbackward, 0); //rightbackward to lowest speed.
  analogWrite(leftforward, 0); //leftforward to lowest speed.
  analogWrite(rightforward, 0); //rightforward to lowest speed.
}

void motorforward() {
  //motors forwards
  analogWrite(leftbackward, 0); //leftbackward to lowest speed.
  analogWrite(rightbackward, 0); //rightbackward to lowest speed.
  analogWrite(leftforward, 175); //leftforward to highest speed.
  analogWrite(rightforward, 175); //rightforward to highest speed.
}

void motorleft() {
  //motors forwards
  analogWrite(leftbackward, 175); //leftbackward to highest speed.
  analogWrite(rightbackward, 0); //rightbackward to lowest speed.
  analogWrite(leftforward, 0); //leftforward to lowest speed.
  analogWrite(rightforward, 175); //rightforward to highest speed.
  delay (1000);//time is dependent on battery and accuracy
}

void motorback()
{
  analogWrite(leftbackward, 175);//leftbackward to highest speed.
  analogWrite(rightbackward, 175);//rightbackward to highest speed.
  analogWrite(leftforward, 0);//leftforward to lowest speed.
  analogWrite(rightforward, 0);//rightforward to lowest speed.
  delay (1000);
}

void sonar () {
  //sends and receives the ping then converts it it to cm
  delayMicroseconds(2);

  digitalWrite(trig, LOW); //turns trigger off
  delayMicroseconds(2);

  digitalWrite(trig, HIGH); //sends soundwave
  delayMicroseconds(10);

  digitalWrite(trig, LOW); //turns trigger off. soundwave Off

  duration = pulseIn(echo, HIGH); //how long it takes to get echo
  distance = duration / 58; //distance convertered CM
  distance = distance / 2.54; //distance converted to INCH
}
