//Parker Davis
//5-11-16
//temperature sensor

int val;
int tempPin = A4;

void setup()
{
Serial.begin(9600);
}
void loop()
{
val = analogRead(tempPin);
float mv = ( val/1024.0)*5000; 
float cel = mv/10;
float farh = (cel*9)/5 + 32;

Serial.print("TEMPRATURE = ");
Serial.print(cel);
Serial.print(" C\n");
delay(1000);

Serial.print("TEMPRATURE = ");
Serial.print(farh);
Serial.print(" F\n");
delay(1000);
}
