#ifndef SensorDePh_h
#define SensorDePh_h
#include <Arduino.h>
#include <ph4502c_sensor.h>

class SensorDePh{
    private:
        PH4502C_Sensor sensorPH;
        double calibrate = 8;
        int ponteiro = 50;
        

    public:
        SensorDePh();

        double getPh();
        void calibrar(double phDesejado);
};

#endif