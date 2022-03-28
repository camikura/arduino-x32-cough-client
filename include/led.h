#include <Arduino.h>

#define PIN_LED1 4

struct Led {
  Led();

  void on();
  void off();
};
