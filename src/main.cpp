#include <Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "SensorDeTemperatura.h" 
#include "SensorDePh.h"
#include "SensorTds.h"

// Definindo as Classes
LiquidCrystal_I2C lcd(0x27,16,2);
SensorDeTemperatura sensorTemp;
SensorDePh sensorDePh;
SensorTds sensTds;

//Definindo as Variaveis
int temp = 0;
int humid = 0;
int ec = 0;
int tempi = 0;
double ph = 0;


void setup() {
    lcd.init();
    lcd.backlight();
    pinMode(2, OUTPUT);
}

void loop(){
        
}

void bomdaDagua(){
    if(digitalRead(2) == HIGH){
        digitalWrite(2, LOW);
    }else{
        digitalWrite(2, HIGH);
    }
}

void display(){
    temp = (int)sensorTemp.getTemperatura();
    humid = (int)sensorTemp.getHumidade();
    lcd.setCursor(0,0);
    lcd.print("Hum.: "+String(humid)+"%");
    lcd.setCursor(0,1);
    lcd.print("Temp.: "+String(temp)+"'C");
    delay(20000);

    ec = sensTds.getTds();
    tempi = sensTds.getTemperatura();
    ph = sensorDePh.getPh();

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("pH: " + String(ph) + " ec: " + String(ec) + " PPM");
    lcd.setCursor(0,1);
    lcd.print("Temp. Int.: " + String(tempi));
    delay(20000);
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Oláaaaaa");
    lcd.setCursor(0,1);
    lcd.print("aeaeae");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ABOAOAOAOA");
    delay(2000);
    lcd.clear();
}
