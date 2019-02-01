//parker davis
//lestock final/science olympiad
//ONLY CHANGE DISTANCE FOR THE COMPETITION

//chris robot
int lf = 9;
int lb = 10;
int rf = 5;
int rb = 6;

int button = 8;


//THIS IS WHAT YOU CHANGE(UNITS IS METERS)
float distance = 9.6;//distance given by the compeition



int metertime = 1700;//time it takes to go a meter

void setup() {
  pinMode(lf, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rb, OUTPUT);
  pinMode(button, INPUT);

  do {} while (digitalRead(button) == 1);

  float runtime = metertime * distance; //formula for time it runs
  analogWrite(lf, 254);
  analogWrite(rf, 255);
  analogWrite(lb, 0);
  analogWrite(rb, 0);
  delay(runtime);
  analogWrite(lf, 0);
  analogWrite(rf, 0);

}

void loop() {

}

