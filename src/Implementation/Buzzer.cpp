#include <Arduino.h>
#include <Buzzer.h>

Buzzer::Buzzer(){
    pinMode(8, OUTPUT);
}

void Buzzer::apitar(int tempo){
    digitalWrite(8, HIGH);
    delay(tempo);
    digitalWrite(8, LOW);
}

void Buzzer::apitar(){
    digitalWrite(8, HIGH);
    delay(100);
    digitalWrite(8, LOW);
}