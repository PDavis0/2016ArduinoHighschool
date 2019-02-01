int led = 13;                  //led is preset to pin13
float distance = 0;            //distance the sonar reads
float duration = 0;            //time takes to recieve echo
int echo = 9;                  //orange wire on echo sonar, port 9
int trig = 8;                  //brown wire on trig sonar, port 8
int cm = 0;
int inch = 0;
int count = 0;                 //counts how many blinks

void setup() {
  pinMode(trig, OUTPUT);            //sets pin 11, output
  pinMode(echo, INPUT);             //sets pin 10, input
  pinMode(led, OUTPUT);             //pin 13 is output

  Serial.begin(9600);
}


void loop() {

  sonar();
  inchconversion();
  CMconversion();

  if (cm < 15)
  {
    count++;
    
    Serial.print("OBJECT DETECTED\n");
    Serial.print (count);
    Serial.print (" objects have been detected\n");
    digitalWrite(led, HIGH);

    Serial.print(distance);
    Serial.println(" meters");

    Serial.print(cm);
    Serial.println(" cm");

    Serial.print(inch);
    Serial.println(" inch\n\n");

    delay(500);
    digitalWrite(led,LOW);

  }
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
    distance = (duration / 58 / 100); //meters


  }
  void CMconversion()
  {
    cm = distance * 100; //m to cm
  }
  void inchconversion()
  {
    inch = (distance * 100) / 2.54; //m to inches
  }

