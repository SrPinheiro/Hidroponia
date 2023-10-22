#include <Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "SensorDeTemperatura.h" 
#include "SensorDePh.h"
#include "SensorTds.h"

// LiquidCrystal_I2C lcd(0x27,16,2);

// SensorDeTemperatura sensorTemp;

// SensorDePh sensorDePh;

// SensorTds sensTds;

void setup()
{
//   Serial.begin(300);
//   lcd.init();                      
//   lcd.init();
//   lcd.backlight();
pinMode(2, OUTPUT);
}

void loop(){
    digitalWrite(2, HIGH);
    delay(3000);
    digitalWrite(2, LOW);
    delay(3000);
    // int temp = (int)sensorTemp.getTemperatura();
    // int humid = (int)sensorTemp.getHumidade();
    // lcd.setCursor(0,0);
    // lcd.print("Hum.: "+String(humid)+"%");
    // lcd.setCursor(0,1);
    // lcd.print("Temp.: "+String(temp)+"'C");
    // delay(20000);

    // int ec = sensTds.getTds();
    // int tempi = sensTds.getTemperatura();
    // double ph = sensorDePh.getPh();
    // lcd.clear();
    // lcd.setCursor(0,0);
    // lcd.print("pH: " + String(ph) + " ec: " + String(ec) + " PPM");
    // lcd.setCursor(0,1);
    // lcd.print("Temp. Int.: " + String(tempi));
    // delay(20000);
    // lcd.clear();

    // lcd.setCursor(0,0);
    // lcd.print("Oláaaaaa");
    // lcd.setCursor(0,1);
    // lcd.print("aeaeae");
    // delay(2000);
    // lcd.clear();
    // lcd.setCursor(0,0);
    // lcd.print("ABOAOAOAOA");
    // delay(2000);
    // lcd.clear();
}
