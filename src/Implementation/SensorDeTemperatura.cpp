#include <Arduino.h>
#include <DHT11.h>
#include <SensorDeTemperatura.h>

SensorDeTemperatura::SensorDeTemperatura() : dht11(4) {
    //Construtor
}

double SensorDeTemperatura::getTemperatura(){
    return this->dht11.readTemperature();
}

double SensorDeTemperatura::getHumidade(){
    return this->dht11.readHumidity();
}