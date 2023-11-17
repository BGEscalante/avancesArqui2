void configurar()
{
     //Configurar ADCON
     ADCON0 = 0;
     ADCON1 = 0x0E;
     ADCON2 = 0x80;
     //Configurar interrupciones
     INTCON0 = 0xC0;
     PIR1 = 0;
     PIE1 = 0x40;
     IPR1 = 0x40;
     //configurar puertos
     TRISA = 1;
     TRISC = 0;
     TRISD = 0;
     //LIMPIAR PUERTOS
     PORTA = 0;
     PORTC = 0;
     PORTD = 0;
     //habilitar ADC
     ADON_bit = 1;
     GO_DONE_bit = 1;
}

void interrupt(){
     GO_DONE_bit =0;
     ADIF_bit =0;
     PORTD =  ADRESL;
     PORTC = ADRESH;
     GO_DONE_bit =1;
}

void main() {
       configurar();
       while();
}