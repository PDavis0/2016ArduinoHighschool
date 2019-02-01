//parker davis
//variable loops


int lf = 2;
int lb = 3;
int rf = 6;
int rb = 7;
int button = 5;


void setup() {
  // put your setup code here, to run once:
pinMode(lf,OUTPUT);
pinMode(lb,OUTPUT);
pinMode(rf,OUTPUT);
pinMode(rb,OUTPUT);
pinMode(button,INPUT);

do{}while(digitalRead(button)==1);

}

void loop() {
  // put your main code here, to run repeatedly:
for(int x =0;x<4;x++)
{
  analogWrite(lf,255);
  analogWrite(rf,195);
  analogWrite(lb,0);
  analogWrite(rb,0);
  delay (3000);
  analogWrite(lf,0);
  analogWrite(rf,0);
  delay(1000);
}
do{}while(digitalRead(button)==1);
}

