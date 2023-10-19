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
            double media = 0;

            for(int i = 0; i < 20; i++){
                media += this->sensorPH.read_ph_level();
            }
            media /= 20;

            return media;
        }

        void calibrar(double phDesejado) {
            double calibracao = -0.25;
            double ph = -1;
            double anteriorPh = -1;
            double escala = 0.05;

            while(ph > phDesejado){
                calibracao -= escala;
                sensorPH.recalibrate(calibracao);
                ph = 0;

                for(int i = 0; i < 20; i++){
                    ph += sensorPH.read_ph_level();
                }

                ph /= 20;
            }

            while(ph < phDesejado){
                calibracao += escala;
                sensorPH.recalibrate(calibracao);
                anteriorPh = ph;
                ph = 0;

                for(int i = 0; i < 20; i++){
                    ph += sensorPH.read_ph_level();
                }

                ph /= 20;
            }

            double deltA = phDesejado - anteriorPh;
            double deltB = ph - phDesejado;
            
            if(deltA < deltB){
                this->calibrate = calibracao;
            }else{
                this->calibrate = (calibracao - escala);
                this->sensorPH.recalibrate(this->calibrate);
            }
        }
};

#endif