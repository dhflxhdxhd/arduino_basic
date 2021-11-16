int lightIn = A0;
void setup() {
  Serial.begin(9600);
}

void loop() {
   Serial.print("the light value is:");
   int lightValue = analogRead(lightIn);
   Serial.println(lightValue);
   onOff(lightValue);
   delay(3000);
}

void onOff(int lightValue){
  if(lightValue < 300)digitalWrite(LED,HIGH);
  else digitalWrite(LED,LOW);  
}
