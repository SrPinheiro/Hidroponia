#ifndef SensorDePh_h
#define SensorDePh_h
#include <Arduino.h>

class SensorTds{
    public:
        double getTds(){
            try{
                String DadosRecebidos = getInformation();
                int tdsPpm = DadosRecebidos.indexOf(":");
                if (tdsPpm != -1) {
                    String temperaturaStr = DadosRecebidos.substring(0, tdsPpm);
                    String ppmStr = DadosRecebidos.substring(tdsPpm + 1);
                    
                    int ppm = ppmStr.toInt();
                    
                    return ppm;
                }
            }catch(...){
            }
            
            return 0;
        }

        double getTemperatura(){
            try{
                String DadosRecebidos = getInformation();
                int tdsPpm = DadosRecebidos.indexOf(":");
                if (tdsPpm != -1) {
                    String temperaturaStr = DadosRecebidos.substring(0, tdsPpm);
                    String ppmStr = DadosRecebidos.substring(tdsPpm + 1);
                    
                    float temperatura = temperaturaStr.toFloat();
                    
                    return temperatura;
                }
            }catch(...){
            }
            
            return 0;
        }

        String getInformation(){
            if (Serial.available() >= 8) {
                try{
                    byte bytesRecebidos[8];
                    for (int i = 0; i < 8; i++) {
                        bytesRecebidos[i] = Serial.read();
                    }
                    
                    // Converte os bytes em uma string
                    String DadosRecebidos = "";
                    for (int i = 0; i < 8; i++) {
                        DadosRecebidos += (char)bytesRecebidos[i];
                    }

                    return DadosRecebidos;
                }catch(...){
                }
            }
            return "0:0";
        }
};

#endif