#ifndef SensorDeTemperatura_h
#define SensorDeTemperatura_h

#include <DHT11.h>
#include <Arduino.h>

class SensorDeTemperatura{
    private:
        DHT11 dht11;


    public:
        SensorDeTemperatura() : dht11(4) {
            //Construtor
        }
        
        double getTemperatura(){
            return this->dht11.readTemperature();
        }

        double getHumidade(){
            return this->dht11.readHumidity();
        }

};

#endif