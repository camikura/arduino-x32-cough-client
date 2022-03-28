#include <button.h>

Button::Button() { pinMode(pin, INPUT_PULLUP); }

void Button::scan() {
  if (digitalRead(pin) == LOW) {
    counter[1] = 0;
    counter[0] += counter[0] <= CHATTERING_THRESHOLD;
  } else {
    counter[0] = 0;
    counter[1] += counter[1] <= CHATTERING_THRESHOLD;
  }

  if (counter[0] == CHATTERING_THRESHOLD) {
    if (counter[2] == 0) {
      pressed_handler();
      counter[2] = 1;
    }
  }
  if (counter[1] == CHATTERING_THRESHOLD) {
    if (counter[2] != 0) {
      released_handler();
      counter[2] = 0;
    }
  }
}
