const int  LED=13

void setup() {
  // put your setup code here, to run once:
  serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.aviable() > 0){
    char dato = Serial.read();
    if(dato=='1'){
      digitalWrite(LED,HIGH);
      Serial.print("encendido");
    }
    else if(dato=='0'){
      digitalWrite(LED,LOW);
      Serial.print("apagado");
    }
  }

}
