
#include "lcd-display.h"
#include "air-sensor.h"
#include "ground-sensor.h"

LCDDisplay lcd;
AirSensor air;
GroundSensor ground;

#define MEASSURE_DELAY 30000lu

void setup() {
  Serial.begin(9600);

  lcd.init();

  Serial.println("Initialized");
}

void loop()
{
  lcd.listenButton();

  if (shouldMessure()) {
    Serial.println("meassuring");

    PrintData data = meassure();

    lcd.print(data);
  }
}

PrintData meassure() {
  AirMeassure airData = air.meassure();
  float gh = ground.getValue();

  return PrintData(airData.temperature, airData.humidity, gh);
}

bool shouldMessure() {
  static unsigned long lastMessure = -MEASSURE_DELAY;

  unsigned long now = millis();

  bool shouldUpdateForDefaultDelay = (now - lastMessure) > MEASSURE_DELAY;

  if (shouldUpdateForDefaultDelay) {
    lastMessure = now;

    return true;
  }

  return false;
}