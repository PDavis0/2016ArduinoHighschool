//rotate 90, pause10s, rotate back
//by parker davis
//lestock robotics

#include <Servo.h>

Servo myservo;  //object to control servo, max of 8
int pos=0;
int led=13;

void setup() {
pinMode(led,OUTPUT);//ints the pin
myservo.attach(9);  //servo attatch to pin 9
myservo.write(90);//moves servo to 90
digitalWrite(led,HIGH);//turns on led for the delay
delay(10000);//pause 10 seconds
digitalWrite(led,LOW);//turns led off
myservo.write(0);//moves servo to 0

}

void loop() {
  // put your main code here, to run repeatedly:

}
