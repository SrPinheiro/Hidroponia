#include <Arduino.h>
#include <DataCache.h>

void DataCache::run(){
    this->temp = this->sensorTemp.getTemperatura();
    this->humid = this->sensorTemp.getHumidade();
    this->ph = this->sensorDePh.getPh();
    this->sensorTds.updateData();
    this->ec = this->sensorTds.getSimpleTds();
    this->tempi = this->sensorTds.getSimpleTemperatura();
}