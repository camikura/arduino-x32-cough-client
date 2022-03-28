#include <Arduino.h>
#include <ArduinoSTL.h>

using namespace std;

#define PIN_B1 A1

#define CHATTERING_THRESHOLD 5

class Button;
typedef void (*handler)();

struct Button {
  int pin = PIN_B1;
  vector<int> counter = {0, 0, 0};

  Button();

  handler pressed_handler;
  handler released_handler;

  void scan();
};
