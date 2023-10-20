#include <EEPROM.h>


#ifndef SensorDePh_h
#define SensorDePh_h
class DataSave{
    
    public:
        void salvar(int endereco, double valor) {
            byte* p = (byte*)(void*)&valor;
            for (unsigned int i = 0; i < sizeof(valor); i++) {
                EEPROM.write(endereco + i, *p);
                p++;
            }
        }

        double ler(int endereco) {
            double valorLido;
            byte* p = (byte*)(void*)&valorLido;
            for (int i = 0; i < sizeof(valorLido); i++) {
                *p = EEPROM.read(endereco + i);
                p++;
            }
            return valorLido;
        }
};

#endif