#ifndef AIR_SENSOR_H
#define AIR_SENSOR_H

#include <arduino.h>
#include <DHT11.h>

#define DHT11PIN 10

class AirMeassure {
  public:
    int humidity;
    int temperature;

    AirMeassure(int temperature, int humidity);
};

class AirSensor {
  private:
    DHT11 dht11 = DHT11(DHT11PIN);

  public:
    AirMeassure meassure();
};

#endif AIR_SENSOR_H  