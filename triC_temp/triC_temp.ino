float temp, tempC, tempF;

void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL);
}

void loop() {
  temp = analogRead(A4);
  tempC = 1.074 * temp / 10;
  tempF = tempC * 1.8 + 32;

  Serial.println(tempC);
  Serial.println(tempF);
  delay(1000);
}
