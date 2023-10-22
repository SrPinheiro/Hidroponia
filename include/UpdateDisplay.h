#ifndef UpdateDisplay_h
#define UpdateDisplay_h

#include <DataCache.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

class UpdateDisplay {
    public:
        UpdateDisplay();
        void run(DataCache data);
        void teste();

    private:
        LiquidCrystal_I2C lcd;

};

#endif