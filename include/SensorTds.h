#ifndef SensorTds_h
#define SensorTds_h

class SensorTds{        
    public:

        SensorTds(){
            pinMode(2, OUTPUT);
        }

        double getTds(){
            getInformacaoDoSensor();
            return this->tds;
        }

        double getTemperatura(){
            getInformacaoDoSensor();
            return this->temperatura;
        }

        private:
            double tds = 0;
            double temperatura = 0;
            unsigned long startTime;
            unsigned long timeout = 10000;

            // Este metodo faz a leitura dos bytes que o sensor envia
            // faz o tratamento os converte em char e depois em String
            // depois faz a divisão de valores entre temperatura e tds
            // e armazena os valores de temperatura e tds nas variaveis
            // privadas da classe
            void getInformacaoDoSensor(){
                Serial1.begin(300);
                digitalWrite(2, HIGH);
                String resultado = "";
                startTime = millis();
                while(true){
                    if(millis() - startTime >= timeout){
                        break;
                    }
                    if(Serial1.available() >= 8){
                        int value = Serial1.read();
                        if( value != -1){
                            if((value >= 48 and value <= 58) or value == 46){
                                char caractere = static_cast<char>(value);
                                resultado += caractere;
                            }else if (value == 10){
                                int doisPontos = resultado.indexOf(":");
                                if(doisPontos != -1){
                                    String temperatura = resultado.substring(0, doisPontos);
                                    String tds = resultado.substring(doisPontos+1);
                                    this->temperatura = temperatura.toFloat();
                                    this->tds = tds.toFloat();
                                }
                                digitalWrite(2, LOW);
                                while(Serial1.available() > 0){
                                    Serial1.read();
                                }
                                return;
                            }
                        }
                    }
                }
                this->temperatura = 0;
                this->tds = 0;
                digitalWrite(2, LOW);
            }
};

#endif