#ifndef ESP_H
#define ESP_H

#define ESP_RX 2
#define ESP_TX 3

#include <SoftwareSerial.h>

enum class WiFiMode { Client = 1, AP = 2, Mixed = 3};

class ESP {
  private:
    void write(String data);
    bool waitAnswer(const char* expected);

  public:
    SoftwareSerial esp01s = SoftwareSerial(ESP_RX, ESP_TX);
    void init();
    bool connect(const char* ssid, const char* pwd);
    bool setMode(WiFiMode mode);
};

#endif ESP_H  
