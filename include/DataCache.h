#ifndef DataCache_H
#define DataCache_H
#include "DataCache.h"
#include <SensorDeTemperatura.h>
#include <SensorDePh.h>
#include <SensorTds.h>

class DataCache {
    public:
        int temp = 0;
        int humid = 0;
        int ec = 0;
        int tempi = 0;
        double ph = 0;

        void run();

    private:
        SensorDeTemperatura sensorTemp;
        SensorDePh sensorDePh;
        SensorTds sensorTds;
};

#endif