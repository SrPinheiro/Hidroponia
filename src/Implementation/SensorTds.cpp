#include <Arduino.h>
#include <SensorTds.h>

SensorTds::SensorTds(){
    pinMode(2, OUTPUT);
    Serial1.begin(300);
}

double SensorTds::getSimpleTds(){
    return this->tds;
}

double SensorTds::getSimpleTemperatura(){
    return this->temperatura;
}

double SensorTds::getTds(){
    updateData();
    return this->tds;
}

double SensorTds::getTemperatura(){
    updateData();
    return this->temperatura;
}

void SensorTds::updateData(){
    digitalWrite(2, HIGH);
    String resultado = "";
    startTime = millis();
    while(true){
        if(millis() - startTime >= timeout){
            break;
        }

        if(Serial1.available() >= 8){
            int value = Serial1.read();
            if( value != -1){
                if((value >= 48 and value <= 58) or value == 46){
                    char caractere = static_cast<char>(value);
                    resultado += caractere;
                }else if (value == 10){
                    int doisPontos = resultado.indexOf(":");
                    if(doisPontos != -1){
                        String temperatura = resultado.substring(0, doisPontos);
                        String tds = resultado.substring(doisPontos+1);
                        this->temperatura = temperatura.toFloat();
                        this->tds = tds.toFloat();
                    }
                    digitalWrite(2, LOW);
                    while(Serial1.available() > 0){
                        Serial1.read();
                    }
                    return;
                }
            }
        }
    }
}