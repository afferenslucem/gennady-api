#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H

#define TURN_ON_BUTTON_PIN 9
#define SWITCH_TRANSISTOR_PIN 11

#include <arduino.h>
#include <LiquidCrystal_I2C.h>

class PrintData {
  public:
    int temperature;
    int humidity;
    int groundHumidity;

    PrintData(int temperature, int humidity, int groundHumidity);
};

class LCDDisplay {
  private: 
    LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
    bool turnedOn = false;
    unsigned long lastPrintTime = 0lu;

    PrintData lastData = PrintData(0, 0, 0);

    void turnOnDisplay();
    void turnOffDisplay();
    void printTemperature(int temperature);
    void printHumidity(int humidity);
    void printGroundHumidity(int groundHumidity);

  public:
    void init();
    void listenButton();
    void print(PrintData data);
    unsigned long getLastPrintTime();
    bool isTurnedOn();
};

#endif LCD_DISPLAY_H