#include "HardwareSerial.h"
#include "lcd-display.h"

void LCDDisplay::init() {
  pinMode(TURN_ON_BUTTON_PIN, INPUT_PULLUP);
  pinMode(SWITCH_TRANSISTOR_PIN, OUTPUT);
  digitalWrite(SWITCH_TRANSISTOR_PIN, LOW);

  Serial.println("LCD display was inited");
}

void LCDDisplay::listenButton() {
  if (digitalRead(TURN_ON_BUTTON_PIN) == LOW) {
    delay(200);

    this->turnedOn = !this->turnedOn;

    if (this->turnedOn) {
      this->turnOnDisplay();
    } else {
      this->turnOffDisplay();
    }
  }
}

void LCDDisplay::turnOnDisplay() {
  digitalWrite(SWITCH_TRANSISTOR_PIN, HIGH);

  this->lcd.init();    
  this->lcd.backlight(); 

  Serial.println("Display was turned on");

  this->print(this->lastData);
}

void LCDDisplay::turnOffDisplay() {
  digitalWrite(SWITCH_TRANSISTOR_PIN, LOW);

  Serial.println("Display was turned off");
}

bool LCDDisplay::isTurnedOn() {
  return this->turnedOn;
}

unsigned long LCDDisplay::getLastPrintTime() {
  return this->lastPrintTime;
}

void LCDDisplay::print(PrintData data) {
  if (!this->turnedOn) {
    this->lastData = data;

    return;
  }

  this->printTemperature(data.temperature);
  this->printHumidity(data.humidity);
  this->printGroundHumidity(data.groundHumidity);

  this->lastPrintTime = millis();
}

void LCDDisplay::printTemperature(int temperature) {
  this->lcd.setCursor(0, 0);
  this->lcd.print("t: ");

  this->lcd.setCursor(3, 0);
  this->lcd.print(temperature);
  this->lcd.print("C");
}

void LCDDisplay::printHumidity(int humidity) {
  this->lcd.setCursor(9, 0);
  this->lcd.print("h: ");
  this->lcd.setCursor(12, 0);
  this->lcd.print(humidity);
  this->lcd.print("%");
}

void LCDDisplay::printGroundHumidity(int groundHumidity) {
  this->lcd.setCursor(7, 1);
  this->lcd.print("gnd: ");
  this->lcd.setCursor(12, 1);
  this->lcd.print(groundHumidity);
  this->lcd.print("%");
}

PrintData::PrintData(int temperature, int humidity, int groundHumidity) {
  this->temperature = temperature;
  this->humidity = humidity;
  this->groundHumidity = groundHumidity;
}