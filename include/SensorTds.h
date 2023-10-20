#ifndef SensorDePh_h
#define SensorDePh_h

class SensorTds{        
    public:

        SensorTds(){
            pinMode(2, OUTPUT);
            Serial.begin(300);
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

            // Este metodo faz a leitura dos bytes que o sensor envia
            // faz o tratamento os converte em char e depois em String
            // depois faz a divisão de valores entre temperatura e tds
            // e armazena os valores de temperatura e tds nas variaveis
            // privadas da classe
            void getInformacaoDoSensor(){
                digitalWrite(2, HIGH);
                String resultado = "";
                while(true){
                    if(Serial.available() >= 8){
                        int value = Serial.read();
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
                                while(Serial.available() > 0){
                                    Serial.read();
                                }
                                break;
                            }
                        }
                    }
                }
            }
};

#endif