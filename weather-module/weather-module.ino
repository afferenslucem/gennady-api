#include <arduino.h>
#include <DHT11.h>

#include "ground-sensor.h"
#include "diod-display.h"

#define DHT11PIN 10

GroundSensor groundSensor(A0);
DiodDisplay diods;
DHT11 dht11(DHT11PIN);

void setup() {
  Serial.begin(9600);
  Serial.println("Reading From the Sensor ...");

  delay(2000);  
}

void loop() {
  int groundHumidity = groundSensor.getValue();

  diods.print(groundHumidity);

  Serial.print("Ground humidity: ");
  Serial.print(groundHumidity);
  Serial.println(" %");

  printAirData();

  delay(5000);
}

void printAirData() {
    int temperature = 0;
    int humidity = 0;

    int result = dht11.readTemperatureHumidity(temperature, humidity);

    if (result == 0) {
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.println(" °C");
        Serial.print("Humidity: ");
        Serial.print(humidity);
        Serial.println(" %");
    } else {
        Serial.println(DHT11::getErrorString(result));
    }
}
