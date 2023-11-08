void setup() {
  
  //DDR = TRISD
  DDRD = 0xFF;
  PORTD = 0;


}

void loop() {
  delay(50);
  PORTD++;
}
