#ifndef SensorDePh_h
#define SensorDePh_h
#include <Arduino.h>
#include <ph4502c_sensor.h>


class SensorDePh{
    private:
        PH4502C_Sensor sensorPH;
        double calibrate = 9.20;

    public:
        SensorDePh() : sensorPH(A0, A1){

        }

        double getPh(){
            return this->sensorPH.read_ph_level();
        }

        void calibrar(double phDesejado) {
            double calibracao = 0;
            double ph = 0;
            double anteriorPh = 0;
            double escala = 0.25;

            while(true){
                sensorPH.recalibrate(calibracao);
                ph = sensorPH.read_ph_level();

                
                if(ph >= phDesejado){
                    // calcula o valor mais proximo do ph desejado e aplica a calibração desejada
                    double deltA = phDesejado - anteriorPh;
                    double deltB = ph - phDesejado;
                    
                    if(deltA < deltB){
                        this->calibrate = calibracao;
                    }else{
                        this->calibrate = (calibracao - escala);
                    }
                    break;

                }else{
                    anteriorPh = ph;
                    calibrate += escala;
                }
            }
        }
};

#endif