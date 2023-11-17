void configurar() {
     T0CON = 0x03;
     TMR0L = 0xEE;
     TMR0H = 0x85;
     TRISD = 0;
     PORTD = 0;
     INTCON = 0xC0;
     INTCON2 = 0x04;
     T0IE bit = 1;
     TMR0on bit = 1;
}
 void interrupt (){
      TMR0ON bit
 }

void main() {

}