const int LED=13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    char dato = Serial.read();
    if(dato=='1'){
      digitalWrite(LED, HIGH);
      Serial.println("Encendido");
    }
    else if(dato == '0'){
      digitalWrite(LED, LOW);
      Serial.println("Apagado");
    }
  }
}
