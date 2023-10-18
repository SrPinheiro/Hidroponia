#ifndef SensorDeTemperatura_h
#define SensorDeTemperatura_h

#include <DHT11.h>

class SensorDeTemperatura{
    private:
        DHT11 dht11;


    public:
        SensorDeTemperatura() : dht11(2) {
            //Construtor
        }
        
        double temperatura(){
            return this->dht11.readTemperature();
        }

        double humidade(){
            return this->dht11.readHumidity();
        }

};

#endif