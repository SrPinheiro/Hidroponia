#include <BombaDagua.h>
#include <Arduino.h>

BombaDagua::BombaDagua(){
    pinMode(8, OUTPUT);
}

void BombaDagua::run(){
    if(digitalRead(8) == HIGH){
        digitalWrite(8, LOW);
    }else{
        digitalWrite(8, HIGH);
    }
}