#ifndef DIOD_DISPLAY_H
#define DIOD_DISPLAY_H

#define RED_DIOD 6
#define YELLOW_DIOD 7
#define GREEN_DIOD 8

#include <arduino.h>

class DiodDisplay {
  public:
    void print(int humidity);
};

#endif DIOD_DISPLAY_H