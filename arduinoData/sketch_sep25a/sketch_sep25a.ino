void setup() {
  // put your setup code here, to run once:
  pinMode(13,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13,HIGH);
  delay(500);
  digitalWrite(13,LOW);
  delay(1000);
}
