 /*Parker Davis
 * 11/12/15
 * Robot will use the sonar to try and get out of an enclosed area
 * it will change direction if there is something within 5 inches
 * or it has the possibilty of being stuck. detects objects with button 
 * Touch sensor starts the program
 */
int echo = 9;             //orange wire on echo sonar, port 9
int trig = 8;             //brown wire on trig sonar, port 8
int button = 1;           //red wire on button, port 5
int touch = 5;            //green wire on touchsensor, port4
int leftforward = 2;      //yellow wire in in1. port 2
int leftbackward = 3;     //blue wire in in2. port 6
int rightforward = 6;     //purple wire in in3. port 3
int rightbackward = 7;    //green wire in in4. port 7
int distance = 0;         //distance away from object
int duration = 0;         //time takes to recieve echo
int stuckdirection = 0;   //alternates the direction it turns when stuck
int stuckbutton = 0;      //variable condition if button is touched
void setup() {
  pinMode(leftforward, OUTPUT);     //sets pin 2 (leftforward).
  pinMode(leftbackward, OUTPUT);    //sets pin 6 (leftbackward).
  pinMode(rightforward, OUTPUT);    //sets pin 3 (rightforward).
  pinMode(rightbackward, OUTPUT);   //sets pin 7 (rightbackward).
  pinMode(button, INPUT);           //sets pin 5 input, yellow button.
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  do  //doesnt run until button is pressed to give
  {   //user time to get out of arena
  } while (digitalRead(touch) == 0);
  delay(1000);  //1 second before motors move
}

void loop() {

  for (int stuck = 0; stuck < 451; stuck = stuck + 1)
  {//stuck being a variable that when triggered(runs long enough)
    //assumes the robot is stuck
    if (digitalRead(button) == 0)
    {
      stuckbutton = 1;//if button is touched it needs to move
    }

    delayMicroseconds(2);

    digitalWrite(trig, LOW); //turns trigger off
    delayMicroseconds(2);

    digitalWrite(trig, HIGH); //sends soundwave
    delayMicroseconds(10);

    digitalWrite(trig, LOW); //turns trigger off. soundwave Off

    duration = pulseIn(echo, HIGH); //how long it takes to get echo
    distance = duration / 148; //distance convertered CM to INCh

    if (distance <= 5 && distance > 0 || stuckbutton == 1) //within 5 inches of a wall
    {
      //goes backwards
      analogWrite(leftbackward, 175); //leftbackward to lowest speed.
      analogWrite(rightbackward, 175); //rightbackward to lowest speed.
      analogWrite(leftforward, 0); //leftforward to highest speed.
      analogWrite(rightforward, 0); //rightforward to highest speed.
      delay (250);//.5 seconds backwards
      //stops
      analogWrite(leftbackward, 0); //leftbackward to lowest speed.
      analogWrite(rightbackward, 0); //rightbackward to lowest speed.
      analogWrite(leftforward, 0); //leftforward to highest speed.
      analogWrite(rightforward, 0); //rightforward to highest speed.
      delay(750);
      //turns left
      analogWrite(leftbackward, 0); //leftbackward to lowest speed.
      analogWrite(leftforward, 255); //leftforward to highest speed.
      analogWrite(rightforward, 0); //right wheels stop forward
      analogWrite(rightbackward, 255); //rightbackward to highest speed.
      delay(300);//small turn to orient a different direction
      //stops
      analogWrite(leftbackward, 0); //leftbackward to lowest speed.
      analogWrite(rightbackward, 0); //rightbackward to lowest speed.
      analogWrite(leftforward, 0); //leftforward to highest speed.
      analogWrite(rightforward, 0); //rightforward to highest speed.
      delay(750);
      stuck = 0;
      stuckbutton = 0;
      }

    else if (stuck == 450)
    { //stuck meaning it has run unchanged for 450 loops, it could be "stuck"
      //goes backwards
     
      //alternates going right and left (won't get restuck) 
      if (stuckdirection == 0)
      {
        analogWrite(leftbackward, 175); //leftbackward to lowest speed.
        analogWrite(rightbackward, 175); //rightbackward to lowest speed.
        analogWrite(leftforward, 0); //leftforward to highest speed.
        analogWrite(rightforward, 0); //rightforward to highest speed.
        delay (250);//.25 seconds backwards
        //stops
        analogWrite(leftbackward, 0); //leftbackward to lowest speed.
        analogWrite(rightbackward, 0); //rightbackward to lowest speed.
        analogWrite(leftforward, 0); //leftforward to highest speed.
        analogWrite(rightforward, 0); //rightforward to highest speed.
        delay(750);
        //turns right
        analogWrite(leftbackward, 255); //leftbackward to lowest speed.
        analogWrite(leftforward, 0); //leftforward to highest speed.
        analogWrite(rightforward, 255); //right wheels stop forward
        analogWrite(rightbackward, 0); //rightbackward to highest speed.
        delay(300);//small turn to orient a different direction
        //stops
        analogWrite(leftbackward, 0); //leftbackward to lowest speed.
        analogWrite(rightbackward, 0); //rightbackward to lowest speed.
        analogWrite(leftforward, 0); //leftforward to highest speed.
        analogWrite(rightforward, 0); //rightforward to highest speed.
        delay(750);
        stuckdirection = 1; //alternates
        stuck = 0; //reset loop
      }
      else if (stuckdirection == 1)
      {
        analogWrite(leftbackward, 175); //leftbackward to lowest speed.
        analogWrite(rightbackward, 175); //rightbackward to lowest speed.
        analogWrite(leftforward, 0); //leftforward to highest speed.
        analogWrite(rightforward, 0); //rightforward to highest speed.
        delay (250);//.5 seconds backwards
        //stops
        analogWrite(leftbackward, 0); //leftbackward to lowest speed.
        analogWrite(rightbackward, 0); //rightbackward to lowest speed.
        analogWrite(leftforward, 0); //leftforward to highest speed.
        analogWrite(rightforward, 0); //rightforward to highest speed.
        delay(750);
        //turns left
        analogWrite(leftbackward, 0); //leftbackward to lowest speed.
        analogWrite(leftforward, 255); //leftforward to highest speed.
        analogWrite(rightforward, 0); //right wheels stop forward
        analogWrite(rightbackward, 255); //rightbackward to highest speed.
        delay(300);//small turn to orient a different direction
        //stops
        analogWrite(leftbackward, 0); //leftbackward to lowest speed.
        analogWrite(rightbackward, 0); //rightbackward to lowest speed.
        analogWrite(leftforward, 0); //leftforward to highest speed.
        analogWrite(rightforward, 0); //rightforward to highest speed.
        delay(750);
        stuckdirection = 0; //to alternate
        stuck = 0; //reset loop
      }
    }
    
    // moves forward
    analogWrite(leftbackward, 0); //leftbackward to lowest speed.
    analogWrite(rightbackward, 0); //rightbackward to lowest speed.
    analogWrite(leftforward, 175); //leftforward to a speed.
    analogWrite(rightforward, 175); //rightforward to a speed.
  }
}

