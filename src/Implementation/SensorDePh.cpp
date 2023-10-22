#include <Arduino.h>
#include <SensorDePh.h>


SensorDePh::SensorDePh() : sensorPH(A0, A1){
    // nada aqui :)
}

double SensorDePh::getPh(){
    double media = 0;
    this ->sensorPH.recalibrate(calibrate);
    for(int i = 0; i < 20; i++){
        media += this->sensorPH.read_ph_level();
    }
    media /= 20;

    return media;
}

void SensorDePh::calibrar(double phDesejado){
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