#include <Arduino.h>
#include <Buzzer.h>

Buzzer::Buzzer(){
    pinMode(8, OUTPUT);
}

void Buzzer::apitar(int tempo){
    digitalWrite(10, HIGH);
    delay(tempo);
    digitalWrite(10, LOW);
}

void Buzzer::apitar(){
    digitalWrite(10, HIGH);
    delay(100);
    digitalWrite(10, LOW);
}