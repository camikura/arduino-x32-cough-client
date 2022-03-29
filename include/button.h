#include <Arduino.h>
#include <ArduinoSTL.h>

using namespace std;

#define PIN_B1 A1

#define CHATTERING_THRESHOLD 5

struct Button;
typedef void (*handler)();

struct Button {
  int pin = PIN_B1;
  vector<int> counter = {0, 0, 0};

  handler pressed_handler;
  handler released_handler;

  Button();

  void scan();
};
