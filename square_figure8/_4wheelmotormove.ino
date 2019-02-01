//Parker Davis
//basic 4 motor move; 10/20/15

int x = 8225;//length time
int y = 9500;//width time
int turn = 955;//time for 90 degree turn
int button = 5;//red wire on button, port 5
int leftforward = 2; //yellow wire in in1. port 0
int leftbackward = 3; //blue wire in in2. port 1
int rightforward = 6; //purple wire in in3. port 2
int rightbackward = 7; //green wire in in4. port 3

void setup() {
  pinMode(leftforward,OUTPUT);//sets pin 0 (leftforward).
  pinMode(leftbackward,OUTPUT);//sets pin 1 (leftbackward).
  pinMode(rightforward,OUTPUT);//sets pin 2 (rightforward).
  pinMode(rightbackward,OUTPUT);//sets pin 3 (rightbackward).
  pinMode(button,INPUT);//sets pin 5 input, yellow button.
}

void loop() {
   
  do
  {
    
  }while(digitalRead(button)==1);

  delay(500);//1/2 a second before motors move

    
  //moves length of table
  analogWrite(leftbackward,0);//leftbackward to lowest speed.
  analogWrite(rightbackward,0);//rightbackward to lowest speed.
  analogWrite(leftforward,150);//leftforward to highest speed.
  analogWrite(rightforward,255);//rightforward to highest speed.
  delay(x+90);//keeps motors on for length of table

  //90 degree turn to the left
  analogWrite(rightforward,0);//right wheels stop forward
  analogWrite(rightbackward,255);//rightbackward to highest speed.
  delay(turn);//time needed to 90 

  //moves width of table
  analogWrite(leftbackward,0);//leftbackward to lowest speed.
  analogWrite(rightbackward,0);//rightbackward to lowest speed.
  analogWrite(leftforward,150);//leftforward to highest speed.
  analogWrite(rightforward,255);//rightforward to highest speed.
  delay(y);//keeps motors on for length of table

  //90 degree turn to the left
  analogWrite(rightforward,0);//right wheels stop forward
  analogWrite(rightbackward,255);//rightbackward to highest speed.
  delay(turn+100);//time needed to 90
  
  analogWrite(leftbackward,0);//leftbackward to lowest speed.
  analogWrite(rightbackward,0);//rightbackward to lowest speed.
  analogWrite(leftforward,150);//leftforward to highest speed.
  analogWrite(rightforward,255);//rightforward to highest speed.
  delay(x-50);//keeps motors on for length of table

  //90 degree turn to the left
  analogWrite(rightforward,0);//right wheels stop forward
  analogWrite(rightbackward,255);//rightbackward to highest speed.
  delay(turn+55);//time needed to 90
  
  //moves width of table
  analogWrite(leftbackward,0);//leftbackward to lowest speed.
  analogWrite(rightbackward,0);//rightbackward to lowest speed.
  analogWrite(leftforward,150);//leftforward to highest speed.
  analogWrite(rightforward,255);//rightforward to highest speed.
  delay(y);//keeps motors on for length of table

  
   /* THIS CODE WAS FOR FIGURE-8
   //90 degree turn to the right
  analogWrite(leftforward,0);//right wheels stop forward
  analogWrite(leftbackward,255);//rightbackward to highest speed.
  delay(turn-70);//time needed to 90
  
  analogWrite(leftbackward,0);//leftbackward to lowest speed.
  analogWrite(rightbackward,0);//rightbackward to lowest speed.
  analogWrite(leftforward,150);//leftforward to highest speed.
  analogWrite(rightforward,255);//rightforward to highest speed.
  delay(13500);//keeps motors on for length of table

  //90 degree turn to the right
  analogWrite(rightforward,0);//right wheels stop forward
  analogWrite(rightbackward,255);//rightbackward to highest speed.
  delay(turn-60);//time needed to 90//90 degree turn to the right
  
 analogWrite(leftbackward,0);//leftbackward to lowest speed.
  analogWrite(rightbackward,0);//rightbackward to lowest speed.
  analogWrite(leftforward,150);//leftforward to highest speed.
  analogWrite(rightforward,255);//rightforward to highest speed.
  delay(x+60);//keeps motors on for length of table

  analogWrite(rightforward,0);//right wheels stop forward
  analogWrite(rightbackward,255);//rightbackward to highest speed.
  delay(turn);//time needed to 90

  analogWrite(leftbackward,0);//leftbackward to lowest speed.
  analogWrite(rightbackward,0);//rightbackward to lowest speed.
  analogWrite(leftforward,150);//leftforward to highest speed.
  analogWrite(rightforward,255);//rightforward to highest speed.
  delay(14000);//keeps motors on for length of table

   //90 degree turn to the left
  analogWrite(rightforward,0);//right wheels stop forward
  analogWrite(rightbackward,255);//rightbackward to highest speed.
  delay(turn);//time needed to 90 

  analogWrite(leftbackward,0);//leftbackward to lowest speed.
  analogWrite(rightbackward,0);//rightbackward to lowest speed.
  analogWrite(leftforward,150);//leftforward to highest speed.
  analogWrite(rightforward,255);//rightforward to highest speed.
  delay(y);//keeps motors on for length of table

  //90 degree turn to the left
  analogWrite(leftforward,0);//right wheels stop forward
  analogWrite(leftbackward,255);//rightbackward to highest speed.
  delay(turn);//time needed to 90 

  analogWrite(leftbackward,0);//leftbackward to lowest speed.
  analogWrite(rightbackward,0);//rightbackward to lowest speed.
  analogWrite(leftforward,150);//leftforward to highest speed.
  analogWrite(rightforward,255);//rightforward to highest speed.
  delay(x);//keeps motors on for length of table
  
  //90 degree turn to the left
  analogWrite(leftforward,0);//right wheels stop forward
  analogWrite(leftbackward,255);//rightbackward to highest speed.
  delay(turn);//time needed to 90 
  */
}

