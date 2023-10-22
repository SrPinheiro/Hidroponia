#include <UpdateDisplay.h>
#include <DataCache.h>
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

UpdateDisplay::UpdateDisplay(): lcd(0x27,16,2){
    
}

void UpdateDisplay::run(DataCache data){
    lcd.init();
    lcd.backlight();

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Hum: "+String(data.humid)+"%");
    lcd.setCursor(0,1);
    lcd.print("Temp: "+String(data.temp)+"'C");

    delay(5000);
    lcd.clear();
    
    lcd.setCursor(0,0);
    lcd.print("PH: " + String(data.ph));
    lcd.setCursor(0,1);
    lcd.print("Temp agua: " + String(data.tempi));

    delay(5000);
    lcd.clear();
    
    lcd.setCursor(0,0);
    lcd.print("TDS:");
    lcd.setCursor(0,1);
    lcd.print(String(data.ec) + " PPM");
}

void UpdateDisplay::teste(){
    lcd.init();
    lcd.backlight();
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Teste");
    lcd.setCursor(0,1);
    lcd.print("Teste2");

    delay(2000);
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Teste3");
    lcd.setCursor(0,1);
    lcd.print("Teste4");

    delay(2000);
}