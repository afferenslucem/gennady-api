#include "diod-display.h"

void DiodDisplay::print(int humidity) {
  int level = humidity / 20;

  digitalWrite(RED_DIOD, LOW);
  digitalWrite(YELLOW_DIOD, LOW);
  digitalWrite(GREEN_DIOD, LOW);

  switch(level) {
    case 0:
      digitalWrite(RED_DIOD, HIGH);
      break;
    case 1:
      digitalWrite(RED_DIOD, HIGH);
      digitalWrite(YELLOW_DIOD, HIGH);
      break;
    case 2:
      digitalWrite(YELLOW_DIOD, HIGH);
      break;
    case 3:
      digitalWrite(YELLOW_DIOD, HIGH);
      digitalWrite(GREEN_DIOD, HIGH);
      break;
    case 4:
      digitalWrite(GREEN_DIOD, HIGH);
      break;
  }
}