int lightIn = A0;
void setup() {
  Serial.begin(9600);
}

void loop() {
   Serial.print("the light value is:");
   int lightValue = analogRead(lightIn);
   delay(3000);
}
