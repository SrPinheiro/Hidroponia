#include <BombaDagua.h>
#include <Arduino.h>

void BombaDagua::run(){
    if(digitalRead(8) == HIGH){
        digitalWrite(8, LOW);
    }else{
        digitalWrite(8, HIGH);
    }
}