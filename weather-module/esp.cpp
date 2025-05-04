#include "arduino.h"
#include "esp.h"
#include "math.h"

#define PACKAGE_SIZE 2

void ESP::init() {
  this->esp01s.begin(115200);
  this->esp01s.setTimeout(100);
  
  delay(1000);
}

bool ESP::setMode(WiFiMode mode) {
    String data = "AT+CWMODE_DEF=";
    data += String((int) mode);

    this->write(data);

    while (!this->esp01s.available());
}

bool ESP::connect(const char* ssid, const char* pwd) {
  String data = "AT+CWJAP_CUR=\"";
  data += ssid;
  data += "\",\"";
  data += pwd;
  data += "\""; 

  this->write(data);

  while (!this->esp01s.available());

  return true;
}

void ESP::write(String data) {
  for (int i = 0; i < data.length(); i += PACKAGE_SIZE) {
    int start = i;
    int end = min(i + PACKAGE_SIZE, data.length());

    this->esp01s.print(data.substring(start, end));

    delay(10);
  }

  this->esp01s.println("");
}

bool ESP::waitAnswer(const char* expected) {
  while (!this->esp01s.available());

  String data = this->esp01s.readString();

  return data == expected;
}