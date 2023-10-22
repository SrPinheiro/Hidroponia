#ifndef SensorTds_h
#define SensorTds_h
#include <Arduino.h>
class SensorTds{        
    public:
        SensorTds();

        double getSimpleTds();
        double getSimpleTemperatura();
        double getTds();
        double getTemperatura();
        void updateData();

        private:
            double tds = 0;
            double temperatura = 0;
            unsigned long startTime;
            unsigned long timeout = 3000;
};

#endif