#ifndef Buzzer_h
#define Buzzer_h
#include <Arduino.h>

class Buzzer {
    public:
        Buzzer();

        void apitar(int tempo);
        void apitar();
};

#endif