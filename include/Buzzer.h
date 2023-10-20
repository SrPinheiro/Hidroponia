#ifndef Buzzer_h
#define Buzzer_h

class Buzzer {
    public:
        Buzzer(){
            pinMode(8, OUTPUT);
        }

        void apitar(int tempo){
            digitalWrite(8, HIGH);
            delay(tempo);
            digitalWrite(8, LOW);
        }

        void apitar(){
            digitalWrite(8, HIGH);
            delay(100);
            digitalWrite(8, LOW);
        }
};

#endif