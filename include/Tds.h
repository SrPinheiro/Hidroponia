#include <Arduino.h>
String inputString = "";
boolean stringComplete = false;

void setup() {
  Serial.begin(300);
  inputString.reserve(32); 
}

void loop() {
  while (Serial.available() > 0) {
    char inChar = (char)Serial.read();
    if (inChar == '\n') {
      stringComplete = true; 
    } else {
      inputString += inChar;
    }
  }

  if (stringComplete) {
    int colonIndex = inputString.indexOf(':');
    if (colonIndex > 0) {
      String temperatureStr = inputString.substring(0, colonIndex);
      String ppmStr = inputString.substring(colonIndex + 1);
      float temperature = temperatureStr.toFloat();
      int ppm = ppmStr.toInt();
      
      Serial.print("Temperatura: ");
      Serial.print(temperature);
      Serial.print(" PPM: ");
      Serial.println(ppm);
    }
    inputString = "";
    stringComplete = false;
  }
}
