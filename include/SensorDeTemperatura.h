#ifndef SensorDeTemperatura_h
#define SensorDeTemperatura_h

#include <DHT11.h>
#include <Arduino.h>

class SensorDeTemperatura{
    private:
        DHT11 dht11;

    public:
        SensorDeTemperatura();

        double getTemperatura();
        double getUmidade();
};

#endif